
// Generated from .\lisp.g by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "lispParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by lispParser.
 */
class  lispVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by lispParser.
   */
    virtual antlrcpp::Any visitProgram(lispParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitToplevel(lispParser::ToplevelContext *context) = 0;

    virtual antlrcpp::Any visitDefun(lispParser::DefunContext *context) = 0;

    virtual antlrcpp::Any visitDefine(lispParser::DefineContext *context) = 0;

    virtual antlrcpp::Any visitDefstruct(lispParser::DefstructContext *context) = 0;

    virtual antlrcpp::Any visitStructMember(lispParser::StructMemberContext *context) = 0;

    virtual antlrcpp::Any visitExpression(lispParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant(lispParser::ConstantContext *context) = 0;

    virtual antlrcpp::Any visitSymbolReference(lispParser::SymbolReferenceContext *context) = 0;

    virtual antlrcpp::Any visitCallable(lispParser::CallableContext *context) = 0;

    virtual antlrcpp::Any visitParameter(lispParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitLambda(lispParser::LambdaContext *context) = 0;

    virtual antlrcpp::Any visitTypedParameter(lispParser::TypedParameterContext *context) = 0;

    virtual antlrcpp::Any visitLet(lispParser::LetContext *context) = 0;

    virtual antlrcpp::Any visitTypedValueBinding(lispParser::TypedValueBindingContext *context) = 0;

    virtual antlrcpp::Any visitTypeName(lispParser::TypeNameContext *context) = 0;

    virtual antlrcpp::Any visitCond(lispParser::CondContext *context) = 0;

    virtual antlrcpp::Any visitCondCondition(lispParser::CondConditionContext *context) = 0;

    virtual antlrcpp::Any visitCondValue(lispParser::CondValueContext *context) = 0;

    virtual antlrcpp::Any visitLoop(lispParser::LoopContext *context) = 0;

    virtual antlrcpp::Any visitLoopBindingExpression(lispParser::LoopBindingExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBinary(lispParser::BinaryContext *context) = 0;

    virtual antlrcpp::Any visitBinaryOperator(lispParser::BinaryOperatorContext *context) = 0;


};

