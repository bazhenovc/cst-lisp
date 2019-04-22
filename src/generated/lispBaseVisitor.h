
// Generated from .\lisp.g by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "lispVisitor.h"


/**
 * This class provides an empty implementation of lispVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  lispBaseVisitor : public lispVisitor {
public:

  virtual antlrcpp::Any visitProgram(lispParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToplevel(lispParser::ToplevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefun(lispParser::DefunContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefine(lispParser::DefineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefstruct(lispParser::DefstructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructMember(lispParser::StructMemberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(lispParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant(lispParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbolReference(lispParser::SymbolReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallable(lispParser::CallableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter(lispParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLambda(lispParser::LambdaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypedParameter(lispParser::TypedParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLet(lispParser::LetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypedValueBinding(lispParser::TypedValueBindingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeName(lispParser::TypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond(lispParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondCondition(lispParser::CondConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondValue(lispParser::CondValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop(lispParser::LoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopBindingExpression(lispParser::LoopBindingExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary(lispParser::BinaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryOperator(lispParser::BinaryOperatorContext *ctx) override {
    return visitChildren(ctx);
  }


};

