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

#pragma once

#pragma warning(push)
#pragma warning(disable:4146)
#pragma warning(disable:4141)
#pragma warning(disable:4244)
#pragma warning(disable:4267)
#pragma warning(disable:4291)
#pragma warning(disable:4624)
#pragma warning(disable:4996)
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

#include "generated/lispVisitor.h"
#include "generated/lispParser.h"
#include "generated/lispLexer.h"

#include <fstream>
#include <iostream>
#include <stack>
#include <string_view>

class ModuleBuilder : public lispVisitor
{
public:

    struct CodeGenResult
    {
        std::unique_ptr<llvm::Module>       Module;
        std::unique_ptr<llvm::IRBuilder<>>  Builder;
    };

    // TODO: Implement a proper scope stack
    AST::ExpressionScope RootScope;

    CodeGenResult ParseAndGenerate(std::string_view inFile, llvm::LLVMContext* LLVMContext,
                                   lispParser::ProgramContext *context);

    virtual antlrcpp::Any visitProgram(lispParser::ProgramContext *context) override;

    virtual antlrcpp::Any visitToplevel(lispParser::ToplevelContext *context) override;

    virtual antlrcpp::Any visitDefun(lispParser::DefunContext *context) override;

    virtual antlrcpp::Any visitDefine(lispParser::DefineContext *context) override;

    virtual antlrcpp::Any visitDefstruct(lispParser::DefstructContext *context) override;

    virtual antlrcpp::Any visitStructMember(lispParser::StructMemberContext *context) override;

    virtual antlrcpp::Any visitExpression(lispParser::ExpressionContext *context) override;

    virtual antlrcpp::Any visitConstant(lispParser::ConstantContext *context) override;

    virtual antlrcpp::Any visitSymbolReference(lispParser::SymbolReferenceContext *context) override;

    virtual antlrcpp::Any visitCallable(lispParser::CallableContext *context) override;

    virtual antlrcpp::Any visitParameter(lispParser::ParameterContext *context) override;

    virtual antlrcpp::Any visitLambda(lispParser::LambdaContext *context) override;

    virtual antlrcpp::Any visitTypedParameter(lispParser::TypedParameterContext *context) override;

    virtual antlrcpp::Any visitLet(lispParser::LetContext *context) override;

    virtual antlrcpp::Any visitTypedValueBinding(lispParser::TypedValueBindingContext *context) override;

    virtual antlrcpp::Any visitTypeName(lispParser::TypeNameContext *context) override;

    virtual antlrcpp::Any visitCond(lispParser::CondContext *context) override;

    virtual antlrcpp::Any visitCondCondition(lispParser::CondConditionContext *context) override;

    virtual antlrcpp::Any visitCondValue(lispParser::CondValueContext *context) override;

    virtual antlrcpp::Any visitLoop(lispParser::LoopContext *context) override;

    virtual antlrcpp::Any visitLoopBindingExpression(lispParser::LoopBindingExpressionContext *context) override;

    virtual antlrcpp::Any visitBinary(lispParser::BinaryContext *context) override;

    virtual antlrcpp::Any visitBinaryOperator(lispParser::BinaryOperatorContext *context) override;

private:

    std::list<std::string> mCopiedStrings; // TODO: Refactor this

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
