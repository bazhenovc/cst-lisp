/** MIT License

    Copyright (c) 2019 Kyrylo Bazhenov

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#include "parser.hh"

#include <iostream>

#ifdef _WIN32
#pragma comment(lib, "kernel32.lib")
extern "C" bool IsDebuggerPresent();
#endif

//---------------------------------------------------------------------------------------------------------------------
// Lexer
Lexer::Lexer(std::string_view sourceCode) : SourceCode(sourceCode) {}

bool Lexer::EndOfFile(const LexerState& state) const { return state.CurrentCharIndex == SourceCode.size(); }

char Lexer::NextChar(LexerState& state) const
{
    char c = SourceCode[state.CurrentCharIndex];
    state.CurrentCharIndex++;
    return c;
}

void Lexer::PrevChar(LexerState& state) const
{
    state.CurrentCharIndex--;
}

std::string_view Lexer::GetSource(const LexerState& state, size_t lastCharIndex) const
{
    return SourceCode.substr(lastCharIndex, state.CurrentCharIndex - lastCharIndex);
}

bool Lexer::IsAllowedInIdentifier(char c)
{
    //return c == '+' || c == '-' || c == '*' || c == '_';
    return c == '_' || c == '-';
}

Token Lexer::NextToken(LexerState& state) const
{
    if (EndOfFile(state)) { return InvalidToken; }

    char c = NextChar(state);

    // Skip all skippable stuff
    while (c == '\n' || c == ';' || isspace(c) && !EndOfFile(state)) {
        // newline
        if (c == '\n') {
            c = NextChar(state);
            state.CurrentLine++;
            continue;
        }

        // skip comments (line comments only)
        if (c == ';') {
            while (c != '\n') { c = NextChar(state); }

            // Advance newline
            c = NextChar(state);
            state.CurrentLine++;
            continue;
        }

        // skip whitespaces
        if (isspace(c) && !EndOfFile(state)) {
            c = NextChar(state);
            continue;
        }
    }

    size_t lastCharIndex = state.CurrentCharIndex - 1;

    // something that looks like an identifier
    if (isalpha(c) && !EndOfFile(state)) {
        while ((isalnum(c) || IsAllowedInIdentifier(c)) && !EndOfFile(state)) {
            c = NextChar(state);
        }

        PrevChar(state);
        std::string_view identifier = GetSource(state, lastCharIndex);

        if (identifier.empty())                 { return { TokenType::Invalid,      identifier }; }
        else if (identifier == "lambda")        { return { TokenType::LambdaKW,     identifier }; }
        else if (identifier == "let")           { return { TokenType::LetKW,        identifier }; }
        else if (identifier == "defun")         { return { TokenType::DefunKW,      identifier }; }
        else if (identifier == "define")        { return { TokenType::DefineKW,     identifier }; }
        else if (identifier == "if")            { return { TokenType::IfKW,         identifier }; }
        //else if (identifier == "module")        { return { TokenType::ModuleKW,     identifier }; }
        //else if (identifier == "struct")        { return { TokenType::StructKW,     identifier }; }
        //else if (identifier == "function")      { return { TokenType::FunctionKW,   identifier }; }
        //else if (identifier == "return")        { return { TokenType::ReturnKW,     identifier }; }
        else                                    { return { TokenType::Identifier,   identifier }; }
    }

    // Something that looks like a number
    if (isdigit(c) || c == '-' || c == '+') {

        // Parse negative number
        if (c == '-' || c == '+') {
            c = NextChar(state);
            if (!isdigit(c)) {
                PrevChar(state);
                return { TokenType::Symbol, GetSource(state, lastCharIndex) };
            }
        }

        TokenType literalType = TokenType::IntegerLiteral;
        while (isdigit(c) || c == '.' && !EndOfFile(state)) {
            if (c == '.') {
                literalType = TokenType::FloatLiteral;
            }
            c = NextChar(state);
        }

        PrevChar(state);
        std::string_view number = GetSource(state, lastCharIndex);

        if (number.empty())     { return { TokenType::Invalid,  number }; }
        else                    { return { literalType,         number }; }
    }

    // Something that looks like a string
    if (c == '\"') {
        // We don't want to include initial quote symbol
        lastCharIndex++;
        c = NextChar(state);

        while (c != '\"' && !EndOfFile(state)) {
            c = NextChar(state);
        }

        PrevChar(state);
        std::string_view string = GetSource(state, lastCharIndex);

        // HACK: Eat remaining quote
        NextChar(state);

        if (string.empty())     { return { TokenType::Invalid,          string }; }
        else                    { return { TokenType::StringLiteral,    string }; }
    }

    // something that looks like a symbol, return it as-is
    if (        c == '+' || c == '-' || c == '*' || c == '/'
                ||      c == '(' || c == ')' || c == '<' || c == '>'
                ||      c == '^' || c == '|' || c == '&' || c == '!'
                ||      c == '=' || c == ':' || c == ';'
                ||      c == '[' || c == ']') {
        return { TokenType::Symbol, GetSource(state, lastCharIndex) };
    }

    // invalid token, probably EOF
    return { TokenType::Invalid, GetSource(state, lastCharIndex) };
}

//---------------------------------------------------------------------------------------------------------------------
// Parser
Token Parser::NextToken()
{
    return lexer.NextToken(lexerState);
}

Token Parser::PeekToken() const
{
    LexerState tempState = lexerState;
    return lexer.NextToken(tempState);
}

void Parser::Assert(bool condition, std::string_view message)
{
    if (!condition) {
        std::cerr << message << " at line " << lexerState.CurrentLine + 1 << std::endl;
#ifdef _WIN32
        if (IsDebuggerPresent()) {
            __debugbreak();
        }
#endif
        exit(-1);
    }
}

AST::ExpressionType Parser::ParseType(const Token& token)
{
    if (token.IsSymbol("&")) {
        AST::ExpressionType type = ParseType(NextToken());
        type.IsPointer = true;
        return type;
    }
    Assert(token.Type == TokenType::Identifier, "Unexpected token");
    AST::ExpressionType type;
    type.TypeName = token.Value;
    type.IsPointer = false;
    return type;
}

AST::SourceParseContext Parser::GetParseContext(const Token& token)
{
    return {
        token.Value, lexerState.CurrentLine
    };
}

AST::BaseExpressionPtr Parser::ParseLet(AST::FormExpression::FormScope& parentScope)
{
    Token braceToken = NextToken();
    Assert(braceToken.IsSymbol("("), "Unexpected token, '(' is expected");

    // Parse binding list
    std::unordered_map<std::string_view, AST::BaseExpressionPtr> bindings;// = parentScope.Bindings;
    while (Token bindingToken = NextToken()) {
        if (bindingToken.IsSymbol(")")) {
            break;
        }
        Assert(bindingToken.IsSymbol("["), "Unexpected token, '[' is expected");

        Token bindingName = NextToken();
        Assert(bindingName.IsIdentifier(), "Identifier expected as a binding name");

        auto itr = bindings.find(bindingName.Value);
        Assert(itr == bindings.end(), "Conflicting local binding name");

        AST::BaseExpressionPtr value = ParseFormOrValue(NextToken(), parentScope);
        bindings.insert(itr, { bindingName.Value, std::move(value) });

        Token lastToken = NextToken();
        Assert(lastToken.IsSymbol("]"), "Unexpected token, ']' is expected");
    }

    // Parse expression
    std::vector<AST::BaseExpressionPtr> body;
    body.emplace_back(std::move(ParseFormOrValue(NextToken(), parentScope)));
    while (Token bodyToken = PeekToken()) {
        if (bodyToken.IsSymbol(")")) {
            break;
        }
        body.emplace_back(ParseFormOrValue(NextToken(), parentScope));
    }

    return std::make_unique<AST::LetExpression>(GetParseContext(braceToken), std::move(bindings), std::move(body));
}

AST::BaseExpressionPtr Parser::ParseFormOrValue(const Token& nextToken, AST::FormExpression::FormScope& parentScope)
{
    return nextToken.IsSymbol("(") ?
                ParseGenericForm(nextToken, parentScope) : ParseSingleValue(nextToken, parentScope);
}

AST::LambdaExpression::LambdaSignature Parser::ParseLambdaSignature()
{
    Token token = NextToken();
    Assert(token.IsSymbol("("), "Unexpected token");

    std::vector<std::string_view> functionArgNames;
    std::vector<AST::ExpressionType> functionArgTypes;

    while (Token argToken = NextToken()) {
        if (argToken.IsSymbol(")")) {
            break;
        }

        if (argToken.IsSymbol("[")) {
            Token argName = NextToken();
            Assert(argName.IsIdentifier(), "Identifier expected for function argument name");
            functionArgNames.push_back(argName.Value);
            functionArgTypes.push_back(ParseType(NextToken()));

            Token lastToken = NextToken();
            Assert(lastToken.IsSymbol("]"), "Unexpected token when parsing function signature, ']' expected");
        } else {
            functionArgNames.push_back(std::string_view());
            functionArgTypes.push_back(ParseType(argToken));
        }
    }

    AST::ExpressionType returnType = ParseType(NextToken());
    return {
        std::move(functionArgNames), std::move(functionArgTypes),
                returnType
    };
}

AST::BaseExpressionPtr Parser::ParseLambda(const Token& lambdaToken, AST::FormExpression::FormScope& parentScope)
{
    auto lambdaDecl = std::make_unique<AST::LambdaExpression>(
                GetParseContext(lambdaToken), ParseLambdaSignature());

    bool hasFunctionBody = true;
    if (PeekToken().IsSymbol(")")) {
        hasFunctionBody = false;
    }

    // Parse body
    if (hasFunctionBody) {
        AST::BaseExpressionPtr value = ParseFormOrValue(NextToken(), parentScope);
        value->Parent = lambdaDecl.get();
        lambdaDecl->Body.emplace_back(std::move(value));

        while (Token bodyToken = PeekToken()) {
            if (bodyToken.IsSymbol(")")) {
                break;
            }
            value = ParseFormOrValue(NextToken(), parentScope);
            value->Parent = lambdaDecl.get();
            lambdaDecl->Body.emplace_back(std::move(value));
        }
    }

    return lambdaDecl;
}

AST::BaseExpressionPtr Parser::ParseIf(const Token& value, AST::FormExpression::FormScope& parentScope)
{
    auto condition = ParseFormOrValue(NextToken(), parentScope);
    auto trueExpression = ParseFormOrValue(NextToken(), parentScope);
    auto falseExpression = ParseFormOrValue(NextToken(), parentScope);

    return std::make_unique<AST::IfExpression>(GetParseContext(value), std::move(condition),
                                               std::move(trueExpression), std::move(falseExpression));
}

AST::BaseExpressionPtr Parser::ParseDefun(const Token& lambdaName, AST::FormExpression::FormScope& parentScope)
{
    auto lambdaDecl = ParseLambda(lambdaName, parentScope);
    return lambdaDecl;
}

AST::BaseExpressionPtr Parser::ParseSingleValue(const Token& value, AST::FormExpression::FormScope& parentScope)
{
    switch (value.Type) {
        case TokenType::Identifier: {
            return std::make_unique<AST::ValueExpression>(GetParseContext(value));
        } break;

        case TokenType::LambdaKW: {
            return ParseLambda(value, parentScope);
        } break;

        case TokenType::IntegerLiteral: {
            return std::make_unique<AST::LiteralExpression>(
                        GetParseContext(value), AST::LiteralExpression::Integer);
        } break;

        case TokenType::FloatLiteral: {
            return std::make_unique<AST::LiteralExpression>(
                        GetParseContext(value), AST::LiteralExpression::Float);
        } break;

        case TokenType::StringLiteral: {
            return std::make_unique<AST::LiteralExpression>(
                        GetParseContext(value), AST::LiteralExpression::String);
        } break;

        case TokenType::IfKW: {
            return ParseIf(value, parentScope);
        }

        case TokenType::Symbol: {
            if (value.Value == "+" || value.Value == "-" || value.Value == "*" || value.Value == "/" ||
                value.Value == ">" || value.Value == "<" || value.Value == "=" || value.Value == "~") { // TODO: Not-equals symbol
                AST::BaseExpressionPtr lhs;
                AST::BaseExpressionPtr rhs;

                Token lhsToken = NextToken();
                if (lhsToken.IsSymbol("(")) {
                    lhs = ParseGenericForm(lhsToken, parentScope);
                } else {
                    lhs = ParseSingleValue(lhsToken, parentScope);
                }

                Token rhsToken = NextToken();
                if (rhsToken.IsSymbol("(")) {
                    rhs = ParseGenericForm(rhsToken, parentScope);
                } else {
                    rhs = ParseSingleValue(rhsToken, parentScope);
                }

                // Make sure there's a closing token
                Assert(PeekToken().IsSymbol(")"), "Binary operator expects exactly 2 arguments");

                // Binary arithmetic
                return std::make_unique<AST::BinaryOperatorExpression>(
                            GetParseContext(value), std::move(lhs), std::move(rhs));
            }
            else { Assert(false, "Unexpected symbol"); }
        } break;

        case TokenType::LetKW: {
            return ParseLet(parentScope);
        } break;

        default: {
            Assert(false, "Unexpected token");
            return nullptr;
        }
    }
    return nullptr;
}

AST::BaseExpressionPtr Parser::ParseGenericForm(const Token& token, AST::FormExpression::FormScope& parentScope)
{
    Assert(token.IsSymbol("("), "Unexpected token, start of the form expected");

    AST::FormExpression::FormScope scope;// = parentScope;
    std::vector<AST::BaseExpressionPtr> body;
    while (Token nextToken = NextToken())
    {
        if (nextToken.IsSymbol(")")) {
            break;
        }

        if (false) {
        } else if (nextToken.Type == TokenType::DefineKW) {
            Token symbolName = NextToken();
            Assert(symbolName.IsIdentifier(), "Identifier expected");
            //Assert(parentScope.Bindings.find(symbolName.Value) == parentScope.Bindings.end(),
            //       "Conflicting declaration");

            auto symbolValue = ParseFormOrValue(NextToken(), parentScope);
            symbolValue->ParseContext = GetParseContext(symbolName);
            parentScope.Bindings.emplace_back(std::make_pair(symbolName.Value, std::move(symbolValue)));

            Assert(NextToken().IsSymbol(")"), "Unexpected token at the end of declaration");
            break;
        } else if (nextToken.Type == TokenType::DefunKW) {
            Token lambdaName = NextToken();
            Assert(lambdaName.IsIdentifier(), "Identifier expected");
            //Assert(parentScope.Bindings.find(lambdaName.Value) == parentScope.Bindings.end(),
            //       "Conflicting declaration");

            auto lambda = ParseDefun(lambdaName, parentScope);
            parentScope.Bindings.emplace_back(std::make_pair(lambdaName.Value, std::move(lambda)));

            Assert(NextToken().IsSymbol(")"), "Unexpected token at the end of function definition");
            break;
        } else if (nextToken.IsSymbol("(")) {
            body.emplace_back(ParseGenericForm(nextToken, scope));
        } else {
            body.emplace_back(ParseSingleValue(nextToken, scope));
        }
    }

    //Assert(!body.empty(), "Empty form");
    return std::make_unique<AST::FormExpression>(GetParseContext(token), std::move(body), std::move(scope));
}

AST::BaseExpressionPtr Parser::ParseToplevelForm(const Token& token, AST::FormExpression::FormScope& parentScope)
{
    // Validate toplevel forms
    Token nextToken = PeekToken();
    Assert(nextToken && (nextToken.Type == TokenType::DefunKW || nextToken.Type == TokenType::DefineKW),
           "Invalid toplevel form");

    // Parse
    return ParseGenericForm(token, parentScope);
}
