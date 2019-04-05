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

#pragma warning(push)
#pragma warning(disable:4146)
#pragma warning(disable:4141)
#pragma warning(disable:4244)
#pragma warning(disable:4267)
#pragma warning(disable:4291)
#pragma warning(disable:4624)
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS  1

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/BasicBlock.h>

#include <llvm/ADT/StringRef.h>

#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Bitcode/BitcodeWriter.h>

#undef _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(pop)

#include "ast.hh"

#include <fstream>
#include <iostream>
#include <stack>

#include "generated/lispVisitor.h"
#include "generated/lispParser.h"
#include "generated/lispLexer.h"

llvm::StringRef ToLLVM(std::string_view sv)
{
    return llvm::StringRef(sv.data(), sv.size());
}

class ModuleBuilder : public lispVisitor
{
public:

    // TODO: Implement a proper scope stack
    AST::ExpressionScope RootScope;

    void ParseAndGenerate(std::string_view inFile, std::string_view outFile,
                          lispParser::ProgramContext *context)
    {
        std::unique_ptr<llvm::LLVMContext>  LLVMContext;
        std::unique_ptr<llvm::Module>       Module;
        std::unique_ptr<llvm::IRBuilder<>>  Builder;

        LLVMContext = std::make_unique<llvm::LLVMContext>();
        Module = std::make_unique<llvm::Module>(ToLLVM(inFile), *LLVMContext.get());
        Builder = std::make_unique<llvm::IRBuilder<>>(*LLVMContext.get());

        AST::GeneratedScope rootScope;
        rootScope.Types.insert(std::make_pair("void", llvm::Type::getVoidTy(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("boolean", llvm::Type::getInt1Ty(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("f16", llvm::Type::getHalfTy(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("f32", llvm::Type::getFloatTy(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("f64", llvm::Type::getDoubleTy(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("f128", llvm::Type::getFP128Ty(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("i8", llvm::Type::getInt8Ty(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("i16", llvm::Type::getInt16Ty(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("i32", llvm::Type::getInt32Ty(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("i64", llvm::Type::getInt64Ty(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("i128", llvm::Type::getInt128Ty(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("u8", llvm::Type::getInt8Ty(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("u16", llvm::Type::getInt16Ty(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("u32", llvm::Type::getInt32Ty(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("u64", llvm::Type::getInt64Ty(*LLVMContext.get())));
        rootScope.Types.insert(std::make_pair("u128", llvm::Type::getInt128Ty(*LLVMContext.get())));
        rootScope.RootBlock = llvm::BasicBlock::Create(*LLVMContext.get(), "__module_main");

        std::vector<AST::BaseExpressionPtr> programBody = std::move(
                    visitProgram(context).as<std::vector<AST::BaseExpressionPtr>>());

        // Debug print body
        for (auto& expr: programBody) {
            expr->DebugPrint(0);
        }
        std::cerr.flush();

        // Generate code
        AST::CodeGenContext codeGenContext = {
            rootScope,
            Builder.get(),
            Module.get(),
            LLVMContext.get(),
        };

        // Generate root scope
        for (auto& scopeItem: RootScope.Bindings) {
            assert(rootScope.Bindings.find(scopeItem.first) == rootScope.Bindings.end()
                   && "Conflicting binding name in global scope");

            scopeItem.second->DebugPrint(0);

            llvm::Value* value = scopeItem.second->Generate(codeGenContext);
            rootScope.Bindings.insert(rootScope.Bindings.end(), std::make_pair(scopeItem.first, value));
        }

        // Generate program body
        for (auto& expr: programBody) {
            expr->Generate(codeGenContext);
        }

        // Debug print bitcode
        Module->print(llvm::errs(), nullptr);
        llvm::errs().flush();

        // Write bitcode to file
        std::error_code errorCode;
        llvm::raw_fd_ostream outStream(ToLLVM(outFile), errorCode, llvm::sys::fs::F_None);
        if (!errorCode) {
            llvm::WriteBitcodeToFile(*Module.get(), outStream);
            outStream.flush();
        } else {
            std::cerr << "Failed to write bitcode:" << errorCode << std::endl;
        }

        programBody.clear();
        Builder.reset();
        Module.reset();
        LLVMContext.reset();
    }

    virtual antlrcpp::Any visitProgram(lispParser::ProgramContext *context) override
    {
        std::vector<AST::BaseExpressionPtr> programBody;

        for (lispParser::ToplevelContext* toplevel: context->toplevel()) {
            auto expr = std::move(visitToplevel(toplevel).as<AST::BaseExpressionPtr>());
            if (expr) {
                programBody.emplace_back(std::move(expr));
            }
        }

        return programBody;
    }

    virtual antlrcpp::Any visitToplevel(lispParser::ToplevelContext *context) override
    {
        AST::BaseExpressionPtr toplevelExpression;

        lispParser::DefunContext* defunContext = context->defun();
        lispParser::DefineContext* defineContext = context->define();
        if (defunContext != nullptr) {
            //toplevelExpression = std::move(visitDefun(defunContext).as<AST::BaseExpressionPtr>());
            visitDefun(defunContext);
        } else if (defineContext != nullptr) {
            //toplevelExpression = std::move(visitDefine(defineContext).as<AST::BaseExpressionPtr>());
            visitDefine(defineContext);
        } else {
            assert(false && "Internal parser error");
        }

        return toplevelExpression;
    }

    virtual antlrcpp::Any visitDefun(lispParser::DefunContext *context) override
    {
        AST::SourceParseContext parseContext = { CopyString(context->IDENTIFIER()), context->getStart()->getLine() };

        AST::ExpressionType functionReturnType = visitTypeName(context->typeName()).as<AST::ExpressionType>();

        std::vector<std::string_view> functionArgNames;
        std::vector<AST::ExpressionType> functionArgTypes;

        for (lispParser::TypedParameterContext* typedParam: context->typedParameter()) {
            functionArgNames.emplace_back(CopyString(typedParam->IDENTIFIER()));
            functionArgTypes.emplace_back(visitTypeName(typedParam->typeName()).as<AST::ExpressionType>());
        }

        AST::LambdaExpression::LambdaSignature signature = {
            std::move(functionArgNames), std::move(functionArgTypes),
            functionReturnType
        };

        std::vector<AST::BaseExpressionPtr> functionBody;
        for (lispParser::ExpressionContext* expr: context->expression()) {
            functionBody.emplace_back(std::move(visitExpression(expr).as<AST::BaseExpressionPtr>()));
        }

        AST::BaseExpressionPtr functionDecl = std::make_unique<AST::LambdaExpression>(
            parseContext, std::move(signature), std::move(functionBody));

        // Add global binding
        RootScope.Bindings.emplace_back(std::make_pair(parseContext.Source, std::move(functionDecl)));
        return AST::BaseExpressionPtr();
    }

    virtual antlrcpp::Any visitDefine(lispParser::DefineContext *context) override
    {
        std::string_view symbolName = CopyString(context->IDENTIFIER());
        AST::BaseExpressionPtr symbolValue = std::move(visitExpression(context->expression()).as<AST::BaseExpressionPtr>());

        RootScope.Bindings.emplace_back(std::make_pair(symbolName, std::move(symbolValue)));
        return AST::BaseExpressionPtr();
    }

    virtual antlrcpp::Any visitExpression(lispParser::ExpressionContext *context) override
    {
        lispParser::ConstantContext* constant = context->constant();
        lispParser::LambdaContext* lambda = context->lambda();
        lispParser::LetContext* let = context->let();
        lispParser::CondContext* cond = context->cond();
        lispParser::BinaryContext* binary = context->binary();
        lispParser::CallableContext* callable = context->callable();

        if (constant != nullptr) {
            return visitConstant(constant);
        } else if (lambda != nullptr) {
            return visitLambda(lambda);
        } else if (let != nullptr) {
            return visitLet(let);
        } else if (cond != nullptr) {
            return visitCond(cond);
        } else if (binary != nullptr) {
            return visitBinary(binary);
        } else {
            assert(callable != nullptr && "Internal parser error: expected <CALLABLE>, got null");
            return visitCallable(callable);
        }

        assert(false && "Internal parser error, unreachable code reached");
        return nullptr;
    }

    virtual antlrcpp::Any visitConstant(lispParser::ConstantContext *context) override
    {
        auto identifier = context->IDENTIFIER();
        auto floatLiteral = context->FLOAT_LITERAL();
        auto integerLiteral = context->INTEGER_LITERAL();
        auto stringLiteral = context->STRING_LITERAL();

        AST::BaseExpressionPtr expr;
        if (identifier != nullptr) {
            AST::SourceParseContext parseContext = { CopyString(identifier), context->getStart()->getLine() };
            expr = std::make_unique<AST::ValueExpression>(parseContext);
        } else if (floatLiteral != nullptr) {
            AST::SourceParseContext parseContext = { CopyString(floatLiteral), context->getStart()->getLine() };
            expr = std::make_unique<AST::LiteralExpression>(parseContext, AST::LiteralExpression::Float);
        } else if (integerLiteral != nullptr) {
            AST::SourceParseContext parseContext = { CopyString(integerLiteral), context->getStart()->getLine() };
            expr = std::make_unique<AST::LiteralExpression>(parseContext, AST::LiteralExpression::Integer);
        } else if (stringLiteral != nullptr) {
            std::string_view literalString = CopyString(stringLiteral);

            // Remove quotes
            if (!literalString.empty()) {
                assert(literalString[0] == '\"' && literalString[literalString.size() - 1] == '\"');
                assert(literalString.size() >= 2);
                literalString.remove_prefix(1);
                literalString.remove_suffix(1);
            }

            AST::SourceParseContext parseContext = { literalString, context->getStart()->getLine() };
            expr = std::make_unique<AST::LiteralExpression>(parseContext, AST::LiteralExpression::String);
        }
        return expr;
    }

    virtual antlrcpp::Any visitCallable(lispParser::CallableContext *context) override
    {
        AST::SourceParseContext parseContext = {
            CopyString(context->expression()->getStart()),
            context->expression()->getStart()->getLine()
        };

        AST::BaseExpressionPtr functionExpr = std::move(visitExpression(context->expression()).as<AST::BaseExpressionPtr>());
        std::vector<AST::BaseExpressionPtr> functionParameters;
        for (lispParser::ParameterContext* parameter: context->parameter()) {
            functionParameters.emplace_back(std::move(visitParameter(parameter).as<AST::BaseExpressionPtr>()));
        }

        AST::BaseExpressionPtr functionCall = std::make_unique<AST::FunctionCallExpression>(
                    parseContext, std::move(functionExpr), std::move(functionParameters));
        return functionCall;
    }

    virtual antlrcpp::Any visitParameter(lispParser::ParameterContext *context) override
    {
        return visitExpression(context->expression());
    }

    virtual antlrcpp::Any visitLambda(lispParser::LambdaContext *context) override
    {
        AST::SourceParseContext parseContext = { "lambda", context->getStart()->getLine() };

        // TODO: Remove copy-paste
        AST::ExpressionType functionReturnType = visitTypeName(context->typeName()).as<AST::ExpressionType>();

        std::vector<std::string_view> functionArgNames;
        std::vector<AST::ExpressionType> functionArgTypes;

        for (lispParser::TypedParameterContext* typedParam: context->typedParameter()) {
            functionArgNames.emplace_back(CopyString(typedParam->IDENTIFIER()));
            functionArgTypes.emplace_back(visitTypeName(typedParam->typeName()).as<AST::ExpressionType>());
        }

        AST::LambdaExpression::LambdaSignature signature = {
            std::move(functionArgNames), std::move(functionArgTypes),
            functionReturnType
        };

        std::vector<AST::BaseExpressionPtr> functionBody;
        for (lispParser::ExpressionContext* expr: context->expression()) {
            functionBody.emplace_back(std::move(visitExpression(expr).as<AST::BaseExpressionPtr>()));
        }

        AST::BaseExpressionPtr functionDecl = std::make_unique<AST::LambdaExpression>(
            parseContext, std::move(signature), std::move(functionBody));

        return functionDecl;
    }

    virtual antlrcpp::Any visitTypedParameter(lispParser::TypedParameterContext *context) override
    {
        assert(false && "Should not be called directly"); // TODO: Refactor this
        return nullptr;
    }

    virtual antlrcpp::Any visitLet(lispParser::LetContext *context) override
    {
        AST::SourceParseContext parseContext = { CopyString(context->getStart()), context->getStart()->getLine() };

        std::unordered_map<std::string_view, AST::BaseExpressionPtr> letBindings;
        for (lispParser::TypedValueBindingContext* bindingContext: context->typedValueBinding()) {
            std::string_view bindingName = CopyString(bindingContext->IDENTIFIER());
            assert(letBindings.find(bindingName) == letBindings.end() && "Conflicting binding");

            AST::BaseExpressionPtr bindingExpr = std::move(visitTypedValueBinding(bindingContext).as<AST::BaseExpressionPtr>());
            letBindings.insert(letBindings.end(), std::make_pair(bindingName, std::move(bindingExpr)));
        }

        std::vector<AST::BaseExpressionPtr> letBody;
        for (lispParser::ExpressionContext* expr: context->expression()) {
            letBody.emplace_back(std::move(visitExpression(expr).as<AST::BaseExpressionPtr>()));
        }

        AST::BaseExpressionPtr letExpr = std::make_unique<AST::LetExpression>(
                    parseContext, std::move(letBindings), std::move(letBody));
        return letExpr;
    }

    virtual antlrcpp::Any visitTypedValueBinding(lispParser::TypedValueBindingContext *context) override
    {
        lispParser::TypeNameContext* typeName = context->typeName();

        AST::BaseExpressionPtr bindingExpr = std::move(visitExpression(context->expression()).as<AST::BaseExpressionPtr>());
        if (typeName != nullptr) {
            AST::ExpressionType bindingType = visitTypeName(typeName).as<AST::ExpressionType>();

            AST::SourceParseContext parseContext = { CopyString(typeName->getStart()), typeName->getStart()->getLine() };
            bindingExpr = std::make_unique<AST::TypeCastExpression>(parseContext, std::move(bindingExpr), bindingType);
        }

        return bindingExpr;
    }

    virtual antlrcpp::Any visitTypeName(lispParser::TypeNameContext *context) override
    {
        AST::ExpressionType exprType;
        exprType.TypeName = CopyString(context->IDENTIFIER());
        exprType.IsPointer = context->POINTER_PREFIX() != nullptr;
        return exprType;
    }

    virtual antlrcpp::Any visitCond(lispParser::CondContext *context) override
    {
        AST::SourceParseContext parseContext = { CopyString(context->getStart()), context->getStart()->getLine() };

        std::vector<AST::CondExpression::ConditionAndValue> condBody;

        for (lispParser::CondValueContext* condValue: context->condValue()) {
            AST::CondExpression::ConditionAndValue parsedValue;

            lispParser::CondConditionContext* condCondition = condValue->condCondition();

            if (condCondition != nullptr) {
                parsedValue.Condition = std::move(visitCondCondition(condCondition).as<AST::BaseExpressionPtr>());
            }

            for (lispParser::ExpressionContext* condExpr: condValue->expression()) {
                parsedValue.Values.emplace_back(std::move(visitExpression(condExpr).as<AST::BaseExpressionPtr>()));
            }

            condBody.emplace_back(std::move(parsedValue));
        }

        AST::BaseExpressionPtr condExpr = std::make_unique<AST::CondExpression>(
                    parseContext, std::move(condBody));
        return condExpr;
    }

    virtual antlrcpp::Any visitCondCondition(lispParser::CondConditionContext *context) override
    {
        return visitExpression(context->expression());
    }

    virtual antlrcpp::Any visitCondValue(lispParser::CondValueContext *context) override
    {
        assert(false && "Should not be called directly"); // TODO: Refactor this
        return nullptr;
    }

    virtual antlrcpp::Any visitBinary(lispParser::BinaryContext *context) override
    {
        AST::SourceParseContext parseContext = { CopyString(context->binaryOperator()->getStart()),
                                                 context->binaryOperator()->getStart()->getLine() };

        auto lhs = std::move(visitExpression(context->expression(0)).as<AST::BaseExpressionPtr>());
        auto rhs = std::move(visitExpression(context->expression(1)).as<AST::BaseExpressionPtr>());

        AST::BaseExpressionPtr binaryOperatorExpr = std::make_unique<AST::BinaryOperatorExpression>(
                    parseContext, std::move(lhs), std::move(rhs));
        return binaryOperatorExpr;
    }

    virtual antlrcpp::Any visitBinaryOperator(lispParser::BinaryOperatorContext *context) override
    {
        assert(false && "Should not be called directly");
        return nullptr;
    }

private:

    std::list<std::string> mCopiedStrings;

    template <typename T>
    std::string_view CopyString(T* antlrObject)
    {
        if (antlrObject != nullptr) {
            mCopiedStrings.emplace_back(antlrObject->getText());
            return mCopiedStrings.back();
        }
        return std::string_view();
    }
};

int main(int argc, char** argv)
{
    if (argc < 3) {
        std::cerr << "Usage: chisel <input file> <output file>" << std::endl;
        return -1;
    }

    std::ifstream inStream(argv[1], std::ios::in);
    if (!inStream.good()) {
        std::cerr << "Failed to open input file:" << argv[1] << std::endl;
        return -1;
    }

    if (inStream.good()) {

        antlr4::ANTLRInputStream inputStream(inStream);
        lispLexer lexer(&inputStream);
        antlr4::CommonTokenStream tokenStream(&lexer);
        lispParser parser(&tokenStream);

        lispParser::ProgramContext* context = parser.program();

        ModuleBuilder builder;

        builder.ParseAndGenerate(argv[1], argv[2], context);
    }

    return 0;
}
