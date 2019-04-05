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

#include <string_view>
#include <vector>
#include <unordered_map>
#include <memory>

namespace llvm
{
    class LLVMContext;
    class Value;
    class Type;
    class BasicBlock;
    class Module;

    class ConstantFolder;
    class IRBuilderDefaultInserter;
    template <typename T /*= ConstantFolder*/,
              typename Inserter /*= IRBuilderDefaultInserter*/>
    class IRBuilder;
}

namespace AST
{
    struct BaseExpression;
    typedef std::unique_ptr<BaseExpression> BaseExpressionPtr;

    struct GeneratedScope
    {
        std::unordered_map<std::string_view, llvm::Value*> Bindings;
        std::unordered_map<std::string_view, llvm::Type*> Types;
        llvm::BasicBlock* RootBlock = nullptr;
    };

    struct SourceParseContext
    {
        std::string_view    Source;
        size_t              LineNumber = 0;
    };

    typedef llvm::IRBuilder<llvm::ConstantFolder, llvm::IRBuilderDefaultInserter> IRBuilder;
    struct CodeGenContext
    {
        GeneratedScope&             Scope;
        IRBuilder*                  Builder = nullptr;
        llvm::Module*               Module = nullptr;
        llvm::LLVMContext*          Context = nullptr;
    };

    struct ExpressionType
    {
        std::string_view TypeName;
        bool IsPointer;
    };

    // Expressions

    struct ExpressionScope
    {
        std::vector<std::pair<std::string_view, BaseExpressionPtr>> Bindings;
    };

    struct BaseExpression
    {
        SourceParseContext  ParseContext;

        BaseExpression(SourceParseContext context);

        virtual ~BaseExpression();
        virtual llvm::Value* Generate(CodeGenContext& cc) = 0;

        void Assert(bool condition, std::string_view message);

        llvm::Type* ResolveType(ExpressionType type, const GeneratedScope& scope);
        llvm::Value* GenerateSafeTypeCast(llvm::Value* value, llvm::Type* desiredType);

        // Debug printing
        virtual void DebugPrint(int indent);
    };

    struct BinaryOperatorExpression : public BaseExpression
    {
        std::string_view    Operator;
        BaseExpressionPtr   LHS;
        BaseExpressionPtr   RHS;

        BinaryOperatorExpression(SourceParseContext parseContext,
                                 BaseExpressionPtr&& lhs, BaseExpressionPtr&& rhs);

        virtual llvm::Value* Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct LambdaExpression : public BaseExpression
    {
        struct LambdaSignature
        {
            std::vector<std::string_view> ArgNames;
            std::vector<ExpressionType> ArgTypes;
            ExpressionType ReturnType;
        };

        LambdaSignature                 Signature;
        std::vector<BaseExpressionPtr>  Body;

        LambdaExpression(SourceParseContext context, LambdaSignature&& signature,
                         std::vector<BaseExpressionPtr>&& body);

        virtual llvm::Value* Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct CondExpression : public BaseExpression
    {
        struct ConditionAndValue
        {
            BaseExpressionPtr Condition;
            std::vector<BaseExpressionPtr> Values;
        };

        std::vector<ConditionAndValue> Body;

        CondExpression(SourceParseContext context, std::vector<ConditionAndValue>&& body);

        virtual llvm::Value* Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct FunctionCallExpression : public BaseExpression
    {
        BaseExpressionPtr               FunctionExpr;
        std::vector<BaseExpressionPtr>  FunctionArguments;
        //ExpressionScope                 Scope;

        FunctionCallExpression(SourceParseContext parseContext,
                BaseExpressionPtr&& functionExpr, std::vector<BaseExpressionPtr>&& arguments);

        virtual llvm::Value* Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct LetExpression : public BaseExpression
    {
        std::unordered_map<std::string_view, BaseExpressionPtr> Bindings;
        std::vector<BaseExpressionPtr> Body;

        LetExpression(SourceParseContext parseContext,
                      std::unordered_map<std::string_view, BaseExpressionPtr>&& bindings,
                      std::vector<BaseExpressionPtr>&& body);

        virtual llvm::Value* Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct LiteralExpression : public BaseExpression
    {
        enum LiteralType
        {
            Invalid = 0,
            Integer,
            Float,
            Boolean,
            String
        };

        LiteralType         Type = Invalid;
        std::string_view    RawValue;

        LiteralExpression(SourceParseContext parseContext, LiteralType type);

        virtual llvm::Value* Generate(CodeGenContext &cc) override;
    };

    struct ValueExpression : public BaseExpression
    {
        std::string_view Value;

        ValueExpression(SourceParseContext parseContext);

        virtual llvm::Value* Generate(CodeGenContext &cc) override;
    };

    struct TypeCastExpression : public BaseExpression
    {
        AST::BaseExpressionPtr  OriginalExpression;
        ExpressionType          DesiredType;

        TypeCastExpression(SourceParseContext parseContext,
                           BaseExpressionPtr&& originalExpression,
                           ExpressionType desiredType);

        virtual llvm::Value* Generate(CodeGenContext &cc) override;
    };
}
