
#pragma once

#include <string_view>

#include "ast.hh"

enum class TokenType
{
    Invalid = 0,
    Symbol,
    Identifier,
    IntegerLiteral,
    FloatLiteral,
    StringLiteral,
    BooleanLiteral,

    // keywords
    LambdaKW,

    // will-be-macros
    DefunKW,
    DefineKW,
    LetKW,
    //ModuleKW,
    //StructKW,
    //FunctionKW,
    //ReturnKW
};

struct Token
{
    TokenType           Type;
    std::string_view    Value;

    operator bool() const { return Type != TokenType::Invalid; }

    inline bool IsSymbol() const { return Type == TokenType::Symbol; }
    inline bool IsSymbol(std::string_view symbol) const { return IsSymbol() && Value == symbol; }
    inline bool IsIdentifier() const { return Type == TokenType::Identifier; }
};

struct LexerState
{
    size_t      CurrentCharIndex = 0;
    size_t      CurrentLine = 0;
};

struct Lexer
{
    const Token InvalidToken = { TokenType::Invalid, std::string_view() };

    std::string_view  SourceCode;

    Lexer(std::string_view sourceCode);

    bool EndOfFile(const LexerState& state) const;

    char NextChar(LexerState& state) const;
    void PrevChar(LexerState& state) const;

    std::string_view GetSource(const LexerState& state, size_t lastCharIndex) const;
    static bool IsAllowedInIdentifier(char c);

    Token NextToken(LexerState& state) const;
};

//---------------------------------------------------------------------------------------------------------------------
// Parser

struct Parser
{
    const Lexer& lexer;
    LexerState lexerState;

    Token NextToken();

    Token PeekToken() const;

    void Assert(bool condition, std::string_view message);

    AST::ExpressionType ParseType(const Token& token);

    AST::SourceParseContext GetParseContext(const Token& token);

    AST::BaseExpressionPtr ParseLet(AST::FormExpression::FormScope& parentScope);

    AST::BaseExpressionPtr ParseFormOrValue(const Token& nextToken, AST::FormExpression::FormScope& parentScope);

    AST::LambdaExpression::LambdaSignature ParseLambdaSignature();

    AST::BaseExpressionPtr ParseLambda(const Token& lambdaToken, AST::FormExpression::FormScope& parentScope);
    AST::BaseExpressionPtr ParseDefun(const Token& lambdaName, AST::FormExpression::FormScope& parentScope);

    AST::BaseExpressionPtr ParseSingleValue(const Token& value, AST::FormExpression::FormScope& parentScope);

    AST::BaseExpressionPtr ParseGenericForm(const Token& token, AST::FormExpression::FormScope& parentScope);
    AST::BaseExpressionPtr ParseToplevelForm(const Token& token, AST::FormExpression::FormScope& parentScope);
};
