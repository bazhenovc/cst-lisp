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

#include "ast.hh"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>

#include <llvm/ADT/StringRef.h>

#undef _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(pop)

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <typeindex>

#ifdef _WIN32
#pragma comment(lib, "kernel32.lib")
extern "C" bool IsDebuggerPresent();
#endif

static llvm::StringRef ToLLVM(std::string_view sv)
{
    return llvm::StringRef(sv.data(), sv.size());
}

namespace AST
{
    //-----------------------------------------------------------------------------------------------------------------
    // BaseExpression
    BaseExpression::BaseExpression(SourceParseContext context)
     : ParseContext(context)
    {}

    BaseExpression::~BaseExpression() {}

    void BaseExpression::Assert(bool condition, std::string_view message)
    {
        if (!condition) {
            std::cerr << message << " at line " << ParseContext.LineNumber + 1 << std::endl
                      << ParseContext.Source << std::endl;
#ifdef _WIN32
            if (IsDebuggerPresent()) {
                __debugbreak();
            }
#endif
            exit(-1);
        }
    }

    llvm::Type* BaseExpression::ResolveType(ExpressionType type, const GeneratedScope &scope)
    {
        auto itr = scope.Types.find(type.TypeName);
        Assert(itr != scope.Types.end(), "Unknown type");

        llvm::Type* baseType = (*itr).second;
        if (type.IsPointer) {
            baseType = baseType->getPointerTo();
        }
        return baseType;
    }

    llvm::Value* BaseExpression::PerformSafeTypeCast(llvm::Value *value, llvm::Type *desiredType)
    {
        llvm::Type* valueType = value->getType();
        if (valueType != desiredType) {
            if (desiredType->isStructTy()) {
                Assert(false, "Cannot implicitly cast a struct");
            }

            if (llvm::Constant::classof(value)) {
                if (desiredType->isIntegerTy()) {
                    Assert(valueType->isIntegerTy(),
                           "Cannot implicitly convert non-integer type to integer, please use a manual cast");

                    llvm::APInt apValue = static_cast<llvm::ConstantInt*>(value)->getValue();
                    // TODO: Check overflow
                    return llvm::ConstantInt::get(desiredType, apValue.getLimitedValue());
                } else if (desiredType->isFloatingPointTy()) {
                    if (valueType->isIntegerTy()) {
                        llvm::APInt apValue = static_cast<llvm::ConstantInt*>(value)->getValue();
                        // TODO: Check overflow
                        return llvm::ConstantFP::get(desiredType, double(apValue.getLimitedValue()));
                    } else if (valueType->isFloatingPointTy()) {
                        llvm::APFloat apValue = static_cast<llvm::ConstantFP*>(value)->getValueAPF();
                        // TODO: Check overflow
                        return llvm::ConstantFP::get(desiredType, apValue.convertToDouble());
                    }
                }
            }

            //if (valueType->isPointerTy() && desiredType->isPointerTy()) {
            //    return value;
            //}

            Assert(false, "Cannot perform implicit type conversion");
        }
        return value;
    }

    void BaseExpression::DebugPrint(int indent)
    {
        std::cerr << std::setfill(' ') << std::setw(indent)
                  << indent << "::" << typeid(*this).name() << "::" << ParseContext.Source << std::endl;
    }

    //-----------------------------------------------------------------------------------------------------------------
    // BinaryOperator
    BinaryOperatorExpression::BinaryOperatorExpression(SourceParseContext parseContext,
                                                       BaseExpressionPtr&& lhs, BaseExpressionPtr&& rhs)
        : BaseExpression(parseContext),
          Operator(parseContext.Source), LHS(std::move(lhs)), RHS(std::move(rhs))
    {}

    llvm::Value* BinaryOperatorExpression::Generate(CodeGenContext &cc)
    {
        llvm::Value* lhs = LHS->Generate(cc);
        llvm::Value* rhs = RHS->Generate(cc);

        if (llvm::Constant::classof(lhs) && !llvm::Constant::classof(rhs)) {
            lhs = PerformSafeTypeCast(lhs, rhs->getType());
        } else if (!llvm::Constant::classof(lhs) && llvm::Constant::classof(rhs)) {
            rhs = PerformSafeTypeCast(rhs, lhs->getType());
        } else {
            rhs = PerformSafeTypeCast(rhs, lhs->getType());
        }

        if (false) {}

        // Arithmetic operators
        else if (Operator == "+") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
            } else if (lhs->getType()->isIntegerTy()) {
                return cc.Builder->CreateAdd(lhs, rhs);
            } else if (lhs->getType()->isFloatingPointTy()) {
                return cc.Builder->CreateFAdd(lhs, rhs);
            }
        } else if (Operator == "-") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
            } else if (lhs->getType()->isIntegerTy()) {
                return cc.Builder->CreateSub(lhs, rhs);
            } else if (lhs->getType()->isFloatingPointTy()) {
                return cc.Builder->CreateFSub(lhs, rhs);
            }
        } else if (Operator == "*") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
            } else if (lhs->getType()->isIntegerTy()) {
                return cc.Builder->CreateMul(lhs, rhs);
            } else if (lhs->getType()->isFloatingPointTy()) {
                return cc.Builder->CreateFMul(lhs, rhs);
            }
        } else if (Operator == "/") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
            } else if (lhs->getType()->isIntegerTy()) {
                return cc.Builder->CreateSDiv(lhs, rhs); // TODO: signed/unsigned division
            } else if (lhs->getType()->isFloatingPointTy()) {
                return cc.Builder->CreateFDiv(lhs, rhs);
            }
        }

        Assert(false, "Unexpected binary operator");
        return nullptr;
    }

    void BinaryOperatorExpression::DebugPrint(int indent)
    {
        BaseExpression::DebugPrint(indent);
        LHS->DebugPrint(indent + 1);
        RHS->DebugPrint(indent + 1);
    }

    //-----------------------------------------------------------------------------------------------------------------
    // FunctionDecl
    LambdaExpression::LambdaExpression(SourceParseContext context, LambdaSignature &&signature)
        : BaseExpression(context)
    {
        Signature = std::move(signature);
        SourceExpression = this;
    }

    llvm::Value* LambdaExpression::Generate(CodeGenContext &cc)
    {
        llvm::Function::LinkageTypes linkage = llvm::Function::ExternalLinkage;

        // Resolve return and argument types
        llvm::Type* returnType = ResolveType(Signature.ReturnType, cc.Scope);
        std::vector<llvm::Type*> argTypes;
        for (auto& type: Signature.ArgTypes) {
            argTypes.emplace_back(ResolveType(type, cc.Scope));
        }

        // Create function
        llvm::FunctionType* functionType = llvm::FunctionType::get(returnType, argTypes, false);
        llvm::Function* functionValue = llvm::Function::Create(functionType, linkage,
                                                               ToLLVM(ParseContext.Source), cc.Module);

        // Create body
        if (!Body.empty()) {
            GeneratedScope functionScope = cc.Scope;

            // Generate function body
            llvm::BasicBlock* block = llvm::BasicBlock::Create(*cc.Context, "__funcbody", functionValue);
            cc.Builder->SetInsertPoint(block);
            functionScope.RootBlock = block;

            // Load parameters
            if (!Signature.ArgNames.empty()) {
                //llvm::BasicBlock* paramsBlock = llvm::BasicBlock::Create(LLVMContext, "load_params", functionValue);
                //Builder.SetInsertPoint(paramsBlock);

                for (size_t i = 0; i < Signature.ArgNames.size(); ++i) {
                    if (!Signature.ArgNames[i].empty()) {
                        Assert(functionScope.Bindings.find(Signature.ArgNames[i]) == functionScope.Bindings.end(),
                               "Conflicting binding name in function scope");
                        //llvm::Value* allocation = Builder.CreateAlloca(functionSignature.ArgTypes[i]);
                        //Builder.CreateStore(functionValue->arg_begin() + i, allocation);
                        //functionScope.Bindings.insert(std::make_pair(functionSignature.ArgNames[i], allocation));
                        functionScope.Bindings.insert(std::make_pair(Signature.ArgNames[i], functionValue->arg_begin() + i));
                    }
                }
            }

            CodeGenContext localContext = {
                std::move(functionScope),
                cc.Builder, cc.Module, cc.Context
            };

            llvm::Value* value = nullptr;
            for (auto& body: Body) {
                value = body->Generate(localContext);
            }

            // Cast to return type
            if (value != nullptr) {
                value = PerformSafeTypeCast(value, returnType);
            }

            Assert((value == nullptr) || (value != nullptr && value->getType() == returnType),
                   "Function return type does not match expression type");

            if (value == nullptr || value->getType()->isVoidTy()) {
                cc.Builder->CreateRetVoid();
            } else {
                cc.Builder->CreateRet(value); // TODO: return statements
            }

            // Restore root block
            cc.Builder->SetInsertPoint(cc.Scope.RootBlock);

            //functionValue->setVisibility(llvm::Function::HiddenVisibility);
        } else {
            functionValue->setDLLStorageClass(llvm::Function::DLLImportStorageClass);
            functionValue->setVisibility(llvm::Function::DefaultVisibility);
        }

        return functionValue;
    }

    void LambdaExpression::DebugPrint(int indent)
    {
        BaseExpression::DebugPrint(indent);
        for (auto& body: Body) {
            body->DebugPrint(indent + 1);
        }
    }

    //-----------------------------------------------------------------------------------------------------------------
    // If
    IfExpression::IfExpression(SourceParseContext context, BaseExpressionPtr &&conditionExpression,
                               BaseExpressionPtr &&thenExpression, BaseExpressionPtr &&elseExpression)
        : BaseExpression(context)
    {
        ConditionExpression = std::move(conditionExpression);
        TrueExpression = std::move(thenExpression);
        ElseExpression = std::move(elseExpression);
    }

    llvm::Value* IfExpression::Generate(CodeGenContext &cc)
    {
        llvm::Value* conditionValue = ConditionExpression->Generate(cc);
        llvm::Value* thenValue = nullptr;
        llvm::Value* elseValue = nullptr;

        Assert(conditionValue->getType()->isIntegerTy(), "Boolean or integer expected");
        llvm::IntegerType* intType = static_cast<llvm::IntegerType*>(conditionValue->getType());
        conditionValue = cc.Builder->CreateICmpEQ(conditionValue,
                                                  llvm::ConstantInt::get(intType,
                                                                         llvm::APInt(intType->getBitWidth(), 1, false)));

        // Blocks
        llvm::BasicBlock* thenBlock = llvm::BasicBlock::Create(*cc.Context, "if", cc.Builder->GetInsertBlock()->getParent());
        llvm::BasicBlock* elseBlock = llvm::BasicBlock::Create(*cc.Context, "else", cc.Builder->GetInsertBlock()->getParent());
        llvm::BasicBlock* mergeBlock = llvm::BasicBlock::Create(*cc.Context, "next", cc.Builder->GetInsertBlock()->getParent());

        cc.Builder->CreateCondBr(conditionValue, thenBlock, elseBlock);

        // Emit true block
        if (TrueExpression) {
            GeneratedScope localScope = cc.Scope;
            localScope.RootBlock = thenBlock;
            cc.Builder->SetInsertPoint(thenBlock);

            CodeGenContext localContext = {
                localScope,
                cc.Builder, cc.Module, cc.Context,
            };

            thenValue = TrueExpression->Generate(localContext);
            cc.Builder->CreateBr(mergeBlock);
        }


        // Emit false block
        {
            if (ElseExpression) {
                GeneratedScope localScope = cc.Scope;
                localScope.RootBlock = elseBlock;
                cc.Builder->SetInsertPoint(elseBlock);

                CodeGenContext localContext = {
                    localScope,
                    cc.Builder, cc.Module, cc.Context,
                };

                elseValue = ElseExpression->Generate(localContext);
                elseValue = PerformSafeTypeCast(elseValue, thenValue->getType());
            }
            cc.Builder->SetInsertPoint(elseBlock);
            cc.Builder->CreateBr(mergeBlock);
        }

        // This is probably the only place that modifies the insert point and does not restore it back
        cc.Builder->SetInsertPoint(mergeBlock);
        cc.Scope.RootBlock = mergeBlock;

        llvm::PHINode* phi = cc.Builder->CreatePHI(thenValue->getType(), elseValue ? 2 : 1);
        phi->addIncoming(thenValue, thenBlock);
        if (elseValue != nullptr) {
            phi->addIncoming(elseValue, elseBlock);
        }

        return phi;
    }

    void IfExpression::DebugPrint(int indent)
    {
        BaseExpression::DebugPrint(indent);
        if (TrueExpression) {
            TrueExpression->DebugPrint(indent + 1);
        }
        if (ElseExpression) {
            ElseExpression->DebugPrint(indent + 1);
        }
    }

    //-----------------------------------------------------------------------------------------------------------------
    // Form
    FormExpression::FormExpression(SourceParseContext parseContext,
                                   std::vector<BaseExpressionPtr> &&arguments, FormScope&& scope)
        : BaseExpression(parseContext)
    {
        Body = std::move(arguments);
        Scope = std::move(scope);
        for (auto& argument: Body) {
            argument->Parent = this;
        }
    }

    bool FormExpression::IsDeclaredInThisForm(BaseExpression *expression) const
    {
        // TODO: refactor this
        return expression->SourceExpression ? (Body[0]->SourceExpression == this || Body[0]->SourceExpression->Parent == this) : false;
    }

    llvm::Value* FormExpression::Generate(CodeGenContext &cc)
    {
        // Generate scope
        GeneratedScope generatedScope = cc.Scope;
        for (const auto& expr: Scope.Bindings) {
            Assert(generatedScope.Bindings.find(expr.first) == generatedScope.Bindings.end(),
                   "Conflicting binding name in form scope");

            CodeGenContext localContext = {
                generatedScope,
                cc.Builder, cc.Module, cc.Context
            };
            generatedScope.Bindings.insert(std::make_pair(expr.first, expr.second->Generate(localContext)));
        }

        CodeGenContext localContext = {
            std::move(generatedScope),
            cc.Builder, cc.Module, cc.Context
        };

        // Generate body
        if (!Body.empty()) {
            llvm::Value* value = Body[0]->Generate(localContext);

            if (value != nullptr) {
                llvm::Type* valueType = value->getType();
                bool isFunction = valueType->isPointerTy() && valueType->getPointerElementType()->isFunctionTy();
                if (isFunction && !IsDeclaredInThisForm(Body[0].get())) {
                    llvm::Function* functionValue = static_cast<llvm::Function*>(value);
                    Assert((Body.size() - 1) == functionValue->arg_size(), "Unexpected amount of function arguments");

                    std::vector<llvm::Value*> arguments;
                    for (size_t i = 1; i < Body.size(); ++i) {
                        llvm::Type* expectedType = (functionValue->arg_begin() + (i - 1))->getType();
                        llvm::Value* argumentValue = PerformSafeTypeCast(Body[i]->Generate(localContext), expectedType);
                        arguments.emplace_back(argumentValue);
                    }

                    return cc.Builder->CreateCall(functionValue, arguments);
                }

                Assert(Body.size() == 1, "Form has extra arguments which will be ignored");
                return value;
            }
        }

        //Assert(!Scope.Bindings.empty(), "Empty form");
        return nullptr;
    }

    void FormExpression::DebugPrint(int indent)
    {
        BaseExpression::DebugPrint(indent);
        for (auto& expr: Scope.Bindings) {
            expr.second->DebugPrint(indent + 1);
        }
        for (auto& body: Body) {
            body->DebugPrint(indent + 1);
        }
    }

    //-----------------------------------------------------------------------------------------------------------------
    // Let
    LetExpression::LetExpression(SourceParseContext parseContext,
                                 std::unordered_map<std::string_view, BaseExpressionPtr> &&bindings,
                                 std::vector<BaseExpressionPtr> &&body)
        : BaseExpression(parseContext)
    {
        Bindings = std::move(bindings);
        Body = std::move(body);
    }

    llvm::Value* LetExpression::Generate(CodeGenContext &cc)
    {
        // Generate bindings
        GeneratedScope localScope = cc.Scope;
        for (auto& binding : Bindings) {
            std::string_view bindingName = binding.first;

            auto itr = localScope.Bindings.find(bindingName);
            Assert(itr == localScope.Bindings.end(), "Conflicting binding name");

            llvm::Value* bindingValue = binding.second->Generate(cc);
            //if (!llvm::Constant::classof(bindingValue)) {
            //    llvm::Value* allocation = cc.Builder->CreateAlloca(bindingValue->getType());
            //    cc.Builder->CreateStore(bindingValue, allocation);
            //    bindingValue = allocation;
            //}

            localScope.Bindings.insert(itr, { bindingName, bindingValue });
        }

        // Generate body
        CodeGenContext localContext = {
            std::move(localScope),
            cc.Builder, cc.Module, cc.Context
        };

        llvm::Value* value = nullptr;
        for (auto& body: Body) {
            value = body->Generate(localContext);
        }

        return value;
    }

    void LetExpression::DebugPrint(int indent)
    {
        BaseExpression::DebugPrint(indent);
        for (auto& expr: Bindings) {
            expr.second->DebugPrint(indent + 1);
        }
        for (auto& body: Body) {
            body->DebugPrint(indent + 1);
        }
    }

    //-----------------------------------------------------------------------------------------------------------------
    // Literal
    // TODO: Refactor strings
    static llvm::Value* MakeStringLiteral(llvm::Module *module, llvm::LLVMContext &context, std::string_view value)
    {
        llvm::ArrayType* type = llvm::ArrayType::get(llvm::Type::getInt8Ty(context), value.size() + 1);
        llvm::Constant* constant = llvm::ConstantDataArray::getString(context, ToLLVM(value), true);
        llvm::GlobalValue* variable = new llvm::GlobalVariable(*module, type,
                                                               true, llvm::GlobalValue::InternalLinkage,
                                                               constant, "__str_literal");

        return variable;
     }

    LiteralExpression::LiteralExpression(SourceParseContext parseContext,
                                         LiteralType type)
        : BaseExpression(parseContext)
    {
        Type = type;
        RawValue = parseContext.Source;
    }

    llvm::Value* LiteralExpression::Generate(CodeGenContext& cc)
    {
        llvm::Value* value = nullptr;

        switch (Type) {
            case Integer: {
                llvm::IntegerType* type = llvm::Type::getInt128Ty(*cc.Context);
                value = llvm::ConstantInt::get(type, ToLLVM(RawValue), 10);
            } break;

            case Float: {
                llvm::Type* type = llvm::Type::getDoubleTy(*cc.Context);
                value = llvm::ConstantFP::get(type, ToLLVM(RawValue));
            } break;

            case String: {
                value = MakeStringLiteral(cc.Module, *cc.Context, RawValue);

                // TODO: refactor strings and arrays
                llvm::Value* indices[] = {
                    llvm::ConstantInt::get(llvm::Type::getInt64Ty(*cc.Context), 0),
                    llvm::ConstantInt::get(llvm::Type::getInt64Ty(*cc.Context), 0),
                };
                value = cc.Builder->CreateGEP(value->getType()->getContainedType(0),
                                              value, indices);
            } break;

            default: {
                Assert(false, "Unsupported literal type");
            } break;
        }

        return value;
    }

    //-----------------------------------------------------------------------------------------------------------------
    // Value
    ValueExpression::ValueExpression(SourceParseContext parseContext)
        : BaseExpression(parseContext)
    {
        Value = parseContext.Source;
    }

    llvm::Value* ValueExpression::Generate(CodeGenContext &cc)
    {
        // TODO: refactor scopes
        auto itr = cc.Scope.Bindings.find(Value);
        Assert(itr != cc.Scope.Bindings.end(), "Unknown identifier");

        llvm::Value* value = (*itr).second;
        //if (llvm::AllocaInst::classof(value)) {
        //    return cc.Builder->CreateLoad(value);
        //}

        // TODO: refactor strings and arrays
        if (value->getType()->isPointerTy() && value->getType()->getContainedType(0)->isArrayTy()) {
            llvm::Value* indices[] = {
                llvm::ConstantInt::get(llvm::Type::getInt64Ty(*cc.Context), 0),
                llvm::ConstantInt::get(llvm::Type::getInt64Ty(*cc.Context), 0),
            };
            return cc.Builder->CreateGEP(value->getType()->getContainedType(0),
                                         value, indices);
        }

        return value;
    }
}
