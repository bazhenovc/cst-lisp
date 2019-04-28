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

#include "module_builder.hh"

static llvm::StringRef ToLLVM(std::string_view sv)
{
    return llvm::StringRef(sv.data(), sv.size());
}

ModuleBuilder::CodeGenResult ModuleBuilder::ParseAndGenerate(std::string_view inFile,
                                                             llvm::LLVMContext* LLVMContext,
                                                             lispParser::ProgramContext* context)
{
    std::unique_ptr<llvm::Module>       Module;
    std::unique_ptr<llvm::IRBuilder<>>  Builder;

    Module = std::make_unique<llvm::Module>(ToLLVM(inFile), *LLVMContext);
    Builder = std::make_unique<llvm::IRBuilder<>>(*LLVMContext);

    AST::GeneratedScope rootScope;
    rootScope.Types.insert(std::make_pair("void", llvm::Type::getVoidTy(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("boolean", llvm::Type::getInt1Ty(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("f16", llvm::Type::getHalfTy(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("f32", llvm::Type::getFloatTy(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("f64", llvm::Type::getDoubleTy(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("f128", llvm::Type::getFP128Ty(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("i8", llvm::Type::getInt8Ty(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("i16", llvm::Type::getInt16Ty(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("i32", llvm::Type::getInt32Ty(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("i64", llvm::Type::getInt64Ty(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("i128", llvm::Type::getInt128Ty(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("u8", llvm::Type::getInt8Ty(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("u16", llvm::Type::getInt16Ty(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("u32", llvm::Type::getInt32Ty(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("u64", llvm::Type::getInt64Ty(*LLVMContext)));
    rootScope.Types.insert(std::make_pair("u128", llvm::Type::getInt128Ty(*LLVMContext)));
    rootScope.RootBlock = llvm::BasicBlock::Create(*LLVMContext, "__module_main");

    std::vector<AST::BaseExpressionPtr> programBody = std::move(visitProgram(context).as<std::vector<AST::BaseExpressionPtr>>());

    // Debug print body
    //for (auto& expr: programBody) {
    //    expr->DebugPrint(0);
    //}
    //std::cerr.flush();

    // Generate code
    AST::CodeGenContext codeGenContext = {
        rootScope,
        Builder.get(),
        Module.get(),
        LLVMContext,
    };

    // Generate root scope
    for (auto& scopeItem: RootScope.Types) {
        scopeItem.second->Generate(codeGenContext);
    }

    for (auto& scopeItem: RootScope.Bindings) {
        assert(rootScope.Bindings.find(scopeItem.first) == rootScope.Bindings.end()
               && "Conflicting binding name in global scope");

        //scopeItem.second->DebugPrint(0);

        llvm::Value* value = scopeItem.second->Generate(codeGenContext);
        rootScope.Bindings.insert(rootScope.Bindings.end(), std::make_pair(scopeItem.first, value));
    }

    // Generate program body
    for (auto& expr: programBody) {
        expr->Generate(codeGenContext);
    }

    // Debug print bitcode
    //Module->print(llvm::errs(), nullptr);
    //llvm::errs().flush();

    // Write bitcode to file
    //std::error_code errorCode;
    //llvm::raw_fd_ostream outStream(ToLLVM(outFile), errorCode, llvm::sys::fs::F_None);
    //if (!errorCode) {
    //    llvm::WriteBitcodeToFile(*Module.get(), outStream);
    //    outStream.flush();
    //} else {
    //    std::cerr << "Failed to write bitcode:" << errorCode << std::endl;
    //}

    programBody.clear();

    return {
        std::move(Module),
        std::move(Builder)
    };
    //Builder.reset();
    //Module.reset();
    //LLVMContext.reset();
}

antlrcpp::Any ModuleBuilder::visitProgram(lispParser::ProgramContext* context)
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

antlrcpp::Any ModuleBuilder::visitToplevel(lispParser::ToplevelContext* context)
{
    AST::BaseExpressionPtr toplevelExpression;

    lispParser::DefunContext* defunContext = context->defun();
    lispParser::DefineContext* defineContext = context->define();
    lispParser::DefstructContext* defstructContext = context->defstruct();
    if (defunContext != nullptr) {
        visitDefun(defunContext);
    } else if (defineContext != nullptr) {
        visitDefine(defineContext);
    } else if (defstructContext != nullptr) {
        visitDefstruct(defstructContext);
    } else {
        assert(false && "Internal parser error");
    }

    return toplevelExpression;
}

antlrcpp::Any ModuleBuilder::visitDefun(lispParser::DefunContext* context)
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

antlrcpp::Any ModuleBuilder::visitDefine(lispParser::DefineContext* context)
{
    std::string_view symbolName = CopyString(context->IDENTIFIER());
    AST::BaseExpressionPtr symbolValue = std::move(visitExpression(context->expression()).as<AST::BaseExpressionPtr>());

    RootScope.Bindings.emplace_back(std::make_pair(symbolName, std::move(symbolValue)));
    return AST::BaseExpressionPtr();
}

antlrcpp::Any ModuleBuilder::visitDefstruct(lispParser::DefstructContext* context)
{
    std::vector<AST::StructExpression::Member> members;
    for (lispParser::StructMemberContext* memberContext: context->structMember()) {
        members.emplace_back(std::move(visitStructMember(memberContext).as<AST::StructExpression::Member>()));
    }
    AST::SourceParseContext parseContext = { CopyString(context->IDENTIFIER()), context->getStart()->getLine() };
    AST::BaseExpressionPtr structExpr = std::make_unique<AST::StructExpression>(parseContext, std::move(members));

    // Add global binding
    RootScope.Types.emplace_back(std::make_pair(parseContext.Source, std::move(structExpr)));
    return AST::BaseExpressionPtr();
}

antlrcpp::Any ModuleBuilder::visitStructMember(lispParser::StructMemberContext* context)
{
    AST::StructExpression::Member structMember = {
        CopyString(context->IDENTIFIER()),
        visitTypeName(context->typeName()),
        (context->expression() != nullptr) ?
        std::move(visitExpression(context->expression()).as<AST::BaseExpressionPtr>()) : nullptr
    };
    return structMember;
}

antlrcpp::Any ModuleBuilder::visitExpression(lispParser::ExpressionContext* context)
{
    lispParser::ConstantContext* constant = context->constant();
    lispParser::CallableContext* callable = context->callable();
    lispParser::LambdaContext* lambda = context->lambda();
    lispParser::LetContext* let = context->let();
    lispParser::CondContext* cond = context->cond();
    lispParser::LoopContext* loop = context->loop();
    lispParser::BinaryContext* binary = context->binary();


    if (constant != nullptr) {
        return visitConstant(constant);
    } else if (callable != nullptr) {
        return visitCallable(callable);
    } else if (lambda != nullptr) {
        return visitLambda(lambda);
    } else if (let != nullptr) {
        return visitLet(let);
    } else if (cond != nullptr) {
        return visitCond(cond);
    } else if (loop != nullptr) {
        return visitLoop(loop);
    } else if (binary != nullptr) {
        return visitBinary(binary);
    }

    assert(false && "Internal parser error, unreachable code reached");
    return nullptr;
}

antlrcpp::Any ModuleBuilder::visitConstant(lispParser::ConstantContext* context)
{
    auto symbol = context->symbolReference();
    auto floatLiteral = context->FLOAT_LITERAL();
    auto integerLiteral = context->INTEGER_LITERAL();
    auto stringLiteral = context->STRING_LITERAL();

    AST::BaseExpressionPtr expr;
    if (symbol != nullptr) {
        AST::SourceParseContext parseContext = { CopyString(symbol), context->getStart()->getLine() };
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

antlrcpp::Any ModuleBuilder::visitSymbolReference(lispParser::SymbolReferenceContext* context)
{
    assert(false && "Should not be called directly"); // TODO: Refactor this
    return nullptr;
}

antlrcpp::Any ModuleBuilder::visitCallable(lispParser::CallableContext* context)
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

antlrcpp::Any ModuleBuilder::visitParameter(lispParser::ParameterContext* context)
{
    return visitExpression(context->expression());
}

antlrcpp::Any ModuleBuilder::visitLambda(lispParser::LambdaContext* context)
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

antlrcpp::Any ModuleBuilder::visitTypedParameter(lispParser::TypedParameterContext* context)
{
    assert(false && "Should not be called directly"); // TODO: Refactor this
    return nullptr;
}

antlrcpp::Any ModuleBuilder::visitLet(lispParser::LetContext* context)
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

antlrcpp::Any ModuleBuilder::visitTypedValueBinding(lispParser::TypedValueBindingContext* context)
{
    lispParser::TypeNameContext* typeName = context->typeName();

    AST::BaseExpressionPtr bindingExpr = std::move(visitExpression(context->expression()).as<AST::BaseExpressionPtr>());
    if (typeName != nullptr) {
        AST::ExpressionType bindingType = visitTypeName(typeName).as<AST::ExpressionType>();

        AST::SourceParseContext parseContext = { CopyString(typeName->getStart()), typeName->getStart()->getLine() };
        bindingExpr = std::make_unique<AST::TypeCastExpression>(parseContext, bindingType, std::move(bindingExpr));
    }

    return bindingExpr;
}

antlrcpp::Any ModuleBuilder::visitTypeName(lispParser::TypeNameContext* context)
{
    AST::ExpressionType exprType;
    exprType.TypeName = CopyString(context->IDENTIFIER());
    exprType.IsPointer = context->POINTER_PREFIX() != nullptr;
    return exprType;
}

antlrcpp::Any ModuleBuilder::visitCond(lispParser::CondContext* context)
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

antlrcpp::Any ModuleBuilder::visitCondCondition(lispParser::CondConditionContext* context)
{
    return visitExpression(context->expression());
}

antlrcpp::Any ModuleBuilder::visitCondValue(lispParser::CondValueContext* context)
{
    assert(false && "Should not be called directly"); // TODO: Refactor this
    return nullptr;
}

antlrcpp::Any ModuleBuilder::visitLoop(lispParser::LoopContext* context)
{
    std::vector<AST::LoopExpression::BindingExpression> bindings;
    for (lispParser::LoopBindingExpressionContext* bindingContext: context->loopBindingExpression()) {
        AST::LoopExpression::BindingExpression bindingExpr = std::move(visitLoopBindingExpression(bindingContext).as<AST::LoopExpression::BindingExpression>());
        //assert(std::find_if(bindings.begin(), bindings.end(), [bindingExpr->Name](AST::LoopExpression::BindingExpression& val) {
        //    return val.Name == bindingExpr->Name;
        //}) == bindings.end() && "Conflicting binding");

        bindings.emplace_back(std::move(bindingExpr));
    }

    std::vector<AST::BaseExpressionPtr> loopBody;
    for (lispParser::ExpressionContext* bodyContext: context->expression()) {
        loopBody.emplace_back(std::move(visitExpression(bodyContext).as<AST::BaseExpressionPtr>()));
    }

    AST::SourceParseContext parseContext = { CopyString(context->getStart()),
                                             context->getStart()->getLine() };
    AST::BaseExpressionPtr loop = std::make_unique<AST::LoopExpression>(parseContext,
                                                                        std::move(bindings), std::move(loopBody));
    return loop;
}

antlrcpp::Any ModuleBuilder::visitLoopBindingExpression(lispParser::LoopBindingExpressionContext* context)
{
    AST::LoopExpression::BindingExpression bindingExpression = {
        CopyString(context->IDENTIFIER()),                                               // name
        visitTypeName(context->typeName()).as<AST::ExpressionType>(),                    // desired type
        std::move(visitExpression(context->expression(0)).as<AST::BaseExpressionPtr>()), // initial value
        std::move(visitExpression(context->expression(1)).as<AST::BaseExpressionPtr>()), // exit condition
        std::move(visitExpression(context->expression(2)).as<AST::BaseExpressionPtr>())  // body
    };
    return bindingExpression;
}

antlrcpp::Any ModuleBuilder::visitBinary(lispParser::BinaryContext* context)
{
    AST::SourceParseContext parseContext = { CopyString(context->binaryOperator()->getStart()),
                                             context->binaryOperator()->getStart()->getLine() };

    auto lhs = std::move(visitExpression(context->expression(0)).as<AST::BaseExpressionPtr>());
    auto rhs = std::move(visitExpression(context->expression(1)).as<AST::BaseExpressionPtr>());

    AST::BaseExpressionPtr binaryOperatorExpr = std::make_unique<AST::BinaryOperatorExpression>(
                parseContext, std::move(lhs), std::move(rhs));
    return binaryOperatorExpr;
}

antlrcpp::Any ModuleBuilder::visitBinaryOperator(lispParser::BinaryOperatorContext* context)
{
    assert(false && "Should not be called directly");
    return nullptr;
}
