
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

    struct BaseExpression
    {
        SourceParseContext  ParseContext;
        BaseExpression*     Parent = nullptr;
        BaseExpression*     SourceExpression = nullptr;

        BaseExpression(SourceParseContext context);

        virtual ~BaseExpression();
        virtual llvm::Value* Generate(CodeGenContext& cc) = 0;

        void Assert(bool condition, std::string_view message);

        llvm::Type* ResolveType(ExpressionType type, const GeneratedScope& scope);
        llvm::Value* PerformSafeTypeCast(llvm::Value* value, llvm::Type* desiredType);

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

        LambdaExpression(SourceParseContext context, LambdaSignature&& signature);

        virtual llvm::Value* Generate(CodeGenContext& cc) override;
        virtual void DebugPrint(int indent) override;
    };

    struct FormExpression : public BaseExpression
    {
        struct FormScope
        {
            std::vector<std::pair<std::string_view, BaseExpressionPtr>> Bindings;
        };

        std::vector<BaseExpressionPtr>  Body;
        FormScope                       Scope;

        FormExpression(SourceParseContext parseContext,
                       std::vector<BaseExpressionPtr>&& arguments,
                       FormScope&& scope);

        bool IsDeclaredInThisForm(BaseExpression* expression) const;

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

        llvm::Value* Generate(CodeGenContext &cc) override;
    };
}
