
// Generated from .\lisp.g by ANTLR 4.7.2


#include "lispVisitor.h"

#include "lispParser.h"


using namespace antlrcpp;
using namespace antlr4;

lispParser::lispParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

lispParser::~lispParser() {
  delete _interpreter;
}

std::string lispParser::getGrammarFileName() const {
  return "lisp.g";
}

const std::vector<std::string>& lispParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& lispParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

lispParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lispParser::ProgramContext::EOF() {
  return getToken(lispParser::EOF, 0);
}

std::vector<lispParser::ToplevelContext *> lispParser::ProgramContext::toplevel() {
  return getRuleContexts<lispParser::ToplevelContext>();
}

lispParser::ToplevelContext* lispParser::ProgramContext::toplevel(size_t i) {
  return getRuleContext<lispParser::ToplevelContext>(i);
}


size_t lispParser::ProgramContext::getRuleIndex() const {
  return lispParser::RuleProgram;
}


antlrcpp::Any lispParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

lispParser::ProgramContext* lispParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, lispParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(39);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__0) {
      setState(36);
      toplevel();
      setState(41);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(42);
    match(lispParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ToplevelContext ------------------------------------------------------------------

lispParser::ToplevelContext::ToplevelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lispParser::DefunContext* lispParser::ToplevelContext::defun() {
  return getRuleContext<lispParser::DefunContext>(0);
}

lispParser::DefineContext* lispParser::ToplevelContext::define() {
  return getRuleContext<lispParser::DefineContext>(0);
}


size_t lispParser::ToplevelContext::getRuleIndex() const {
  return lispParser::RuleToplevel;
}


antlrcpp::Any lispParser::ToplevelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitToplevel(this);
  else
    return visitor->visitChildren(this);
}

lispParser::ToplevelContext* lispParser::toplevel() {
  ToplevelContext *_localctx = _tracker.createInstance<ToplevelContext>(_ctx, getState());
  enterRule(_localctx, 2, lispParser::RuleToplevel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(44);
      defun();
      break;
    }

    case 2: {
      setState(45);
      define();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefunContext ------------------------------------------------------------------

lispParser::DefunContext::DefunContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lispParser::DefunContext::IDENTIFIER() {
  return getToken(lispParser::IDENTIFIER, 0);
}

lispParser::TypeNameContext* lispParser::DefunContext::typeName() {
  return getRuleContext<lispParser::TypeNameContext>(0);
}

std::vector<lispParser::TypedParameterContext *> lispParser::DefunContext::typedParameter() {
  return getRuleContexts<lispParser::TypedParameterContext>();
}

lispParser::TypedParameterContext* lispParser::DefunContext::typedParameter(size_t i) {
  return getRuleContext<lispParser::TypedParameterContext>(i);
}

std::vector<lispParser::ExpressionContext *> lispParser::DefunContext::expression() {
  return getRuleContexts<lispParser::ExpressionContext>();
}

lispParser::ExpressionContext* lispParser::DefunContext::expression(size_t i) {
  return getRuleContext<lispParser::ExpressionContext>(i);
}


size_t lispParser::DefunContext::getRuleIndex() const {
  return lispParser::RuleDefun;
}


antlrcpp::Any lispParser::DefunContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitDefun(this);
  else
    return visitor->visitChildren(this);
}

lispParser::DefunContext* lispParser::defun() {
  DefunContext *_localctx = _tracker.createInstance<DefunContext>(_ctx, getState());
  enterRule(_localctx, 4, lispParser::RuleDefun);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(lispParser::T__0);
    setState(49);
    match(lispParser::T__1);
    setState(50);
    match(lispParser::IDENTIFIER);
    setState(51);
    match(lispParser::T__0);
    setState(55);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__5)
      | (1ULL << lispParser::POINTER_PREFIX)
      | (1ULL << lispParser::IDENTIFIER))) != 0)) {
      setState(52);
      typedParameter();
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(58);
    match(lispParser::T__2);
    setState(59);
    typeName();
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(60);
      expression();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
    match(lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefineContext ------------------------------------------------------------------

lispParser::DefineContext::DefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lispParser::DefineContext::IDENTIFIER() {
  return getToken(lispParser::IDENTIFIER, 0);
}

lispParser::ExpressionContext* lispParser::DefineContext::expression() {
  return getRuleContext<lispParser::ExpressionContext>(0);
}


size_t lispParser::DefineContext::getRuleIndex() const {
  return lispParser::RuleDefine;
}


antlrcpp::Any lispParser::DefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitDefine(this);
  else
    return visitor->visitChildren(this);
}

lispParser::DefineContext* lispParser::define() {
  DefineContext *_localctx = _tracker.createInstance<DefineContext>(_ctx, getState());
  enterRule(_localctx, 6, lispParser::RuleDefine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(lispParser::T__0);
    setState(69);
    match(lispParser::T__3);
    setState(70);
    match(lispParser::IDENTIFIER);
    setState(71);
    expression();
    setState(72);
    match(lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

lispParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lispParser::ConstantContext* lispParser::ExpressionContext::constant() {
  return getRuleContext<lispParser::ConstantContext>(0);
}

lispParser::LambdaContext* lispParser::ExpressionContext::lambda() {
  return getRuleContext<lispParser::LambdaContext>(0);
}

lispParser::LetContext* lispParser::ExpressionContext::let() {
  return getRuleContext<lispParser::LetContext>(0);
}

lispParser::CondContext* lispParser::ExpressionContext::cond() {
  return getRuleContext<lispParser::CondContext>(0);
}

lispParser::BinaryContext* lispParser::ExpressionContext::binary() {
  return getRuleContext<lispParser::BinaryContext>(0);
}

lispParser::CallableContext* lispParser::ExpressionContext::callable() {
  return getRuleContext<lispParser::CallableContext>(0);
}


size_t lispParser::ExpressionContext::getRuleIndex() const {
  return lispParser::RuleExpression;
}


antlrcpp::Any lispParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

lispParser::ExpressionContext* lispParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 8, lispParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(80);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(74);
      constant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(75);
      lambda();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(76);
      let();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(77);
      cond();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(78);
      binary();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(79);
      callable();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

lispParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lispParser::ConstantContext::IDENTIFIER() {
  return getToken(lispParser::IDENTIFIER, 0);
}

tree::TerminalNode* lispParser::ConstantContext::FLOAT_LITERAL() {
  return getToken(lispParser::FLOAT_LITERAL, 0);
}

tree::TerminalNode* lispParser::ConstantContext::INTEGER_LITERAL() {
  return getToken(lispParser::INTEGER_LITERAL, 0);
}

tree::TerminalNode* lispParser::ConstantContext::STRING_LITERAL() {
  return getToken(lispParser::STRING_LITERAL, 0);
}


size_t lispParser::ConstantContext::getRuleIndex() const {
  return lispParser::RuleConstant;
}


antlrcpp::Any lispParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

lispParser::ConstantContext* lispParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 10, lispParser::RuleConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallableContext ------------------------------------------------------------------

lispParser::CallableContext::CallableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lispParser::ExpressionContext* lispParser::CallableContext::expression() {
  return getRuleContext<lispParser::ExpressionContext>(0);
}

std::vector<lispParser::ParameterContext *> lispParser::CallableContext::parameter() {
  return getRuleContexts<lispParser::ParameterContext>();
}

lispParser::ParameterContext* lispParser::CallableContext::parameter(size_t i) {
  return getRuleContext<lispParser::ParameterContext>(i);
}


size_t lispParser::CallableContext::getRuleIndex() const {
  return lispParser::RuleCallable;
}


antlrcpp::Any lispParser::CallableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitCallable(this);
  else
    return visitor->visitChildren(this);
}

lispParser::CallableContext* lispParser::callable() {
  CallableContext *_localctx = _tracker.createInstance<CallableContext>(_ctx, getState());
  enterRule(_localctx, 12, lispParser::RuleCallable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(lispParser::T__0);
    setState(85);
    expression();
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(86);
      parameter();
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(92);
    match(lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

lispParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lispParser::ExpressionContext* lispParser::ParameterContext::expression() {
  return getRuleContext<lispParser::ExpressionContext>(0);
}


size_t lispParser::ParameterContext::getRuleIndex() const {
  return lispParser::RuleParameter;
}


antlrcpp::Any lispParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

lispParser::ParameterContext* lispParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 14, lispParser::RuleParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaContext ------------------------------------------------------------------

lispParser::LambdaContext::LambdaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lispParser::TypeNameContext* lispParser::LambdaContext::typeName() {
  return getRuleContext<lispParser::TypeNameContext>(0);
}

std::vector<lispParser::TypedParameterContext *> lispParser::LambdaContext::typedParameter() {
  return getRuleContexts<lispParser::TypedParameterContext>();
}

lispParser::TypedParameterContext* lispParser::LambdaContext::typedParameter(size_t i) {
  return getRuleContext<lispParser::TypedParameterContext>(i);
}

std::vector<lispParser::ExpressionContext *> lispParser::LambdaContext::expression() {
  return getRuleContexts<lispParser::ExpressionContext>();
}

lispParser::ExpressionContext* lispParser::LambdaContext::expression(size_t i) {
  return getRuleContext<lispParser::ExpressionContext>(i);
}


size_t lispParser::LambdaContext::getRuleIndex() const {
  return lispParser::RuleLambda;
}


antlrcpp::Any lispParser::LambdaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitLambda(this);
  else
    return visitor->visitChildren(this);
}

lispParser::LambdaContext* lispParser::lambda() {
  LambdaContext *_localctx = _tracker.createInstance<LambdaContext>(_ctx, getState());
  enterRule(_localctx, 16, lispParser::RuleLambda);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(lispParser::T__0);
    setState(97);
    match(lispParser::T__4);
    setState(98);
    match(lispParser::T__0);
    setState(102);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__5)
      | (1ULL << lispParser::POINTER_PREFIX)
      | (1ULL << lispParser::IDENTIFIER))) != 0)) {
      setState(99);
      typedParameter();
      setState(104);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(105);
    match(lispParser::T__2);
    setState(106);
    typeName();
    setState(110);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(107);
      expression();
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(113);
    match(lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypedParameterContext ------------------------------------------------------------------

lispParser::TypedParameterContext::TypedParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lispParser::TypedParameterContext::IDENTIFIER() {
  return getToken(lispParser::IDENTIFIER, 0);
}

lispParser::TypeNameContext* lispParser::TypedParameterContext::typeName() {
  return getRuleContext<lispParser::TypeNameContext>(0);
}


size_t lispParser::TypedParameterContext::getRuleIndex() const {
  return lispParser::RuleTypedParameter;
}


antlrcpp::Any lispParser::TypedParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitTypedParameter(this);
  else
    return visitor->visitChildren(this);
}

lispParser::TypedParameterContext* lispParser::typedParameter() {
  TypedParameterContext *_localctx = _tracker.createInstance<TypedParameterContext>(_ctx, getState());
  enterRule(_localctx, 18, lispParser::RuleTypedParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(121);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lispParser::T__5: {
        enterOuterAlt(_localctx, 1);
        setState(115);
        match(lispParser::T__5);
        setState(116);
        match(lispParser::IDENTIFIER);
        setState(117);
        typeName();
        setState(118);
        match(lispParser::T__6);
        break;
      }

      case lispParser::POINTER_PREFIX:
      case lispParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(120);
        typeName();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LetContext ------------------------------------------------------------------

lispParser::LetContext::LetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lispParser::TypedValueBindingContext *> lispParser::LetContext::typedValueBinding() {
  return getRuleContexts<lispParser::TypedValueBindingContext>();
}

lispParser::TypedValueBindingContext* lispParser::LetContext::typedValueBinding(size_t i) {
  return getRuleContext<lispParser::TypedValueBindingContext>(i);
}

std::vector<lispParser::ExpressionContext *> lispParser::LetContext::expression() {
  return getRuleContexts<lispParser::ExpressionContext>();
}

lispParser::ExpressionContext* lispParser::LetContext::expression(size_t i) {
  return getRuleContext<lispParser::ExpressionContext>(i);
}


size_t lispParser::LetContext::getRuleIndex() const {
  return lispParser::RuleLet;
}


antlrcpp::Any lispParser::LetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitLet(this);
  else
    return visitor->visitChildren(this);
}

lispParser::LetContext* lispParser::let() {
  LetContext *_localctx = _tracker.createInstance<LetContext>(_ctx, getState());
  enterRule(_localctx, 20, lispParser::RuleLet);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(lispParser::T__0);
    setState(124);
    match(lispParser::T__7);
    setState(125);
    match(lispParser::T__0);
    setState(129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__5) {
      setState(126);
      typedValueBinding();
      setState(131);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(132);
    match(lispParser::T__2);
    setState(136);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(133);
      expression();
      setState(138);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(139);
    match(lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypedValueBindingContext ------------------------------------------------------------------

lispParser::TypedValueBindingContext::TypedValueBindingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lispParser::TypedValueBindingContext::IDENTIFIER() {
  return getToken(lispParser::IDENTIFIER, 0);
}

lispParser::ExpressionContext* lispParser::TypedValueBindingContext::expression() {
  return getRuleContext<lispParser::ExpressionContext>(0);
}

lispParser::TypeNameContext* lispParser::TypedValueBindingContext::typeName() {
  return getRuleContext<lispParser::TypeNameContext>(0);
}


size_t lispParser::TypedValueBindingContext::getRuleIndex() const {
  return lispParser::RuleTypedValueBinding;
}


antlrcpp::Any lispParser::TypedValueBindingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitTypedValueBinding(this);
  else
    return visitor->visitChildren(this);
}

lispParser::TypedValueBindingContext* lispParser::typedValueBinding() {
  TypedValueBindingContext *_localctx = _tracker.createInstance<TypedValueBindingContext>(_ctx, getState());
  enterRule(_localctx, 22, lispParser::RuleTypedValueBinding);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(lispParser::T__5);
    setState(142);
    match(lispParser::IDENTIFIER);
    setState(143);
    expression();
    setState(145);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lispParser::POINTER_PREFIX

    || _la == lispParser::IDENTIFIER) {
      setState(144);
      typeName();
    }
    setState(147);
    match(lispParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

lispParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lispParser::TypeNameContext::IDENTIFIER() {
  return getToken(lispParser::IDENTIFIER, 0);
}

tree::TerminalNode* lispParser::TypeNameContext::POINTER_PREFIX() {
  return getToken(lispParser::POINTER_PREFIX, 0);
}


size_t lispParser::TypeNameContext::getRuleIndex() const {
  return lispParser::RuleTypeName;
}


antlrcpp::Any lispParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

lispParser::TypeNameContext* lispParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 24, lispParser::RuleTypeName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lispParser::POINTER_PREFIX) {
      setState(149);
      match(lispParser::POINTER_PREFIX);
    }
    setState(152);
    match(lispParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

lispParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lispParser::CondValueContext *> lispParser::CondContext::condValue() {
  return getRuleContexts<lispParser::CondValueContext>();
}

lispParser::CondValueContext* lispParser::CondContext::condValue(size_t i) {
  return getRuleContext<lispParser::CondValueContext>(i);
}


size_t lispParser::CondContext::getRuleIndex() const {
  return lispParser::RuleCond;
}


antlrcpp::Any lispParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

lispParser::CondContext* lispParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 26, lispParser::RuleCond);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    match(lispParser::T__0);
    setState(155);
    match(lispParser::T__8);
    setState(159);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__5) {
      setState(156);
      condValue();
      setState(161);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(162);
    match(lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondConditionContext ------------------------------------------------------------------

lispParser::CondConditionContext::CondConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lispParser::ExpressionContext* lispParser::CondConditionContext::expression() {
  return getRuleContext<lispParser::ExpressionContext>(0);
}


size_t lispParser::CondConditionContext::getRuleIndex() const {
  return lispParser::RuleCondCondition;
}


antlrcpp::Any lispParser::CondConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitCondCondition(this);
  else
    return visitor->visitChildren(this);
}

lispParser::CondConditionContext* lispParser::condCondition() {
  CondConditionContext *_localctx = _tracker.createInstance<CondConditionContext>(_ctx, getState());
  enterRule(_localctx, 28, lispParser::RuleCondCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondValueContext ------------------------------------------------------------------

lispParser::CondValueContext::CondValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lispParser::CondConditionContext* lispParser::CondValueContext::condCondition() {
  return getRuleContext<lispParser::CondConditionContext>(0);
}

std::vector<lispParser::ExpressionContext *> lispParser::CondValueContext::expression() {
  return getRuleContexts<lispParser::ExpressionContext>();
}

lispParser::ExpressionContext* lispParser::CondValueContext::expression(size_t i) {
  return getRuleContext<lispParser::ExpressionContext>(i);
}


size_t lispParser::CondValueContext::getRuleIndex() const {
  return lispParser::RuleCondValue;
}


antlrcpp::Any lispParser::CondValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitCondValue(this);
  else
    return visitor->visitChildren(this);
}

lispParser::CondValueContext* lispParser::condValue() {
  CondValueContext *_localctx = _tracker.createInstance<CondValueContext>(_ctx, getState());
  enterRule(_localctx, 30, lispParser::RuleCondValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(185);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(166);
      match(lispParser::T__5);
      setState(167);
      condCondition();
      setState(171);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << lispParser::T__0)
        | (1ULL << lispParser::IDENTIFIER)
        | (1ULL << lispParser::FLOAT_LITERAL)
        | (1ULL << lispParser::INTEGER_LITERAL)
        | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
        setState(168);
        expression();
        setState(173);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(174);
      match(lispParser::T__6);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(176);
      match(lispParser::T__5);
      setState(177);
      match(lispParser::T__9);
      setState(181);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << lispParser::T__0)
        | (1ULL << lispParser::IDENTIFIER)
        | (1ULL << lispParser::FLOAT_LITERAL)
        | (1ULL << lispParser::INTEGER_LITERAL)
        | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
        setState(178);
        expression();
        setState(183);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(184);
      match(lispParser::T__6);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryContext ------------------------------------------------------------------

lispParser::BinaryContext::BinaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lispParser::BinaryOperatorContext* lispParser::BinaryContext::binaryOperator() {
  return getRuleContext<lispParser::BinaryOperatorContext>(0);
}

std::vector<lispParser::ExpressionContext *> lispParser::BinaryContext::expression() {
  return getRuleContexts<lispParser::ExpressionContext>();
}

lispParser::ExpressionContext* lispParser::BinaryContext::expression(size_t i) {
  return getRuleContext<lispParser::ExpressionContext>(i);
}


size_t lispParser::BinaryContext::getRuleIndex() const {
  return lispParser::RuleBinary;
}


antlrcpp::Any lispParser::BinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitBinary(this);
  else
    return visitor->visitChildren(this);
}

lispParser::BinaryContext* lispParser::binary() {
  BinaryContext *_localctx = _tracker.createInstance<BinaryContext>(_ctx, getState());
  enterRule(_localctx, 32, lispParser::RuleBinary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    match(lispParser::T__0);
    setState(188);
    binaryOperator();
    setState(189);
    expression();
    setState(190);
    expression();
    setState(191);
    match(lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryOperatorContext ------------------------------------------------------------------

lispParser::BinaryOperatorContext::BinaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t lispParser::BinaryOperatorContext::getRuleIndex() const {
  return lispParser::RuleBinaryOperator;
}


antlrcpp::Any lispParser::BinaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitBinaryOperator(this);
  else
    return visitor->visitChildren(this);
}

lispParser::BinaryOperatorContext* lispParser::binaryOperator() {
  BinaryOperatorContext *_localctx = _tracker.createInstance<BinaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 34, lispParser::RuleBinaryOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__10)
      | (1ULL << lispParser::T__11)
      | (1ULL << lispParser::T__12)
      | (1ULL << lispParser::T__13)
      | (1ULL << lispParser::T__14)
      | (1ULL << lispParser::T__15)
      | (1ULL << lispParser::T__16)
      | (1ULL << lispParser::T__17)
      | (1ULL << lispParser::T__18)
      | (1ULL << lispParser::T__19))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> lispParser::_decisionToDFA;
atn::PredictionContextCache lispParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN lispParser::_atn;
std::vector<uint16_t> lispParser::_serializedATN;

std::vector<std::string> lispParser::_ruleNames = {
  "program", "toplevel", "defun", "define", "expression", "constant", "callable", 
  "parameter", "lambda", "typedParameter", "let", "typedValueBinding", "typeName", 
  "cond", "condCondition", "condValue", "binary", "binaryOperator"
};

std::vector<std::string> lispParser::_literalNames = {
  "", "'('", "'defun'", "')'", "'define'", "'lambda'", "'['", "']'", "'let'", 
  "'cond'", "'else'", "'+'", "'-'", "'*'", "'/'", "'='", "'>'", "'<'", "'~='", 
  "'>='", "'<='", "", "'&'"
};

std::vector<std::string> lispParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "WHITESPACE", "POINTER_PREFIX", "IDENTIFIER", "FLOAT_LITERAL", 
  "INTEGER_LITERAL", "STRING_LITERAL", "LINE_COMMENT"
};

dfa::Vocabulary lispParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> lispParser::_tokenNames;

lispParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1d, 0xc6, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x3, 0x2, 0x7, 0x2, 0x28, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x2b, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x31, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x7, 0x4, 0x38, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x3b, 0xb, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x40, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0x43, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x53, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x5a, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 
    0x5d, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x67, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 
    0x6a, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x6f, 0xa, 0xa, 
    0xc, 0xa, 0xe, 0xa, 0x72, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x7c, 0xa, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x82, 0xa, 0xc, 0xc, 
    0xc, 0xe, 0xc, 0x85, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x89, 0xa, 
    0xc, 0xc, 0xc, 0xe, 0xc, 0x8c, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x94, 0xa, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xe, 0x5, 0xe, 0x99, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xa0, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xa3, 
    0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x7, 0x11, 0xac, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xaf, 
    0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 
    0x11, 0xb6, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xb9, 0xb, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0xbc, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x2, 0x2, 0x14, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x2, 0x4, 0x3, 0x2, 0x19, 0x1c, 0x3, 0x2, 
    0xd, 0x16, 0x2, 0xc8, 0x2, 0x29, 0x3, 0x2, 0x2, 0x2, 0x4, 0x30, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x32, 0x3, 0x2, 0x2, 0x2, 0x8, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x52, 0x3, 0x2, 0x2, 0x2, 0xc, 0x54, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x10, 0x60, 0x3, 0x2, 0x2, 0x2, 0x12, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xa6, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x22, 0xbd, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x26, 0x28, 0x5, 0x4, 0x3, 0x2, 0x27, 
    0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x3, 
    0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x2, 
    0x2, 0x3, 0x2d, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x31, 0x5, 0x6, 0x4, 
    0x2, 0x2f, 0x31, 0x5, 0x8, 0x5, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x5, 0x3, 0x2, 0x2, 0x2, 0x32, 
    0x33, 0x7, 0x3, 0x2, 0x2, 0x33, 0x34, 0x7, 0x4, 0x2, 0x2, 0x34, 0x35, 
    0x7, 0x19, 0x2, 0x2, 0x35, 0x39, 0x7, 0x3, 0x2, 0x2, 0x36, 0x38, 0x5, 
    0x14, 0xb, 0x2, 0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x3d, 0x7, 0x5, 0x2, 0x2, 0x3d, 0x41, 0x5, 0x1a, 0xe, 0x2, 0x3e, 
    0x40, 0x5, 0xa, 0x6, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0x42, 0x44, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x45, 0x7, 0x5, 0x2, 0x2, 0x45, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x47, 0x7, 0x3, 0x2, 0x2, 0x47, 0x48, 0x7, 0x6, 0x2, 0x2, 
    0x48, 0x49, 0x7, 0x19, 0x2, 0x2, 0x49, 0x4a, 0x5, 0xa, 0x6, 0x2, 0x4a, 
    0x4b, 0x7, 0x5, 0x2, 0x2, 0x4b, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x53, 
    0x5, 0xc, 0x7, 0x2, 0x4d, 0x53, 0x5, 0x12, 0xa, 0x2, 0x4e, 0x53, 0x5, 
    0x16, 0xc, 0x2, 0x4f, 0x53, 0x5, 0x1c, 0xf, 0x2, 0x50, 0x53, 0x5, 0x22, 
    0x12, 0x2, 0x51, 0x53, 0x5, 0xe, 0x8, 0x2, 0x52, 0x4c, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x52, 0x4e, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 0xb, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 
    0x9, 0x2, 0x2, 0x2, 0x55, 0xd, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 
    0x3, 0x2, 0x2, 0x57, 0x5b, 0x5, 0xa, 0x6, 0x2, 0x58, 0x5a, 0x5, 0x10, 
    0x9, 0x2, 0x59, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x5f, 0x7, 0x5, 0x2, 0x2, 0x5f, 0xf, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 
    0x5, 0xa, 0x6, 0x2, 0x61, 0x11, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 
    0x3, 0x2, 0x2, 0x63, 0x64, 0x7, 0x7, 0x2, 0x2, 0x64, 0x68, 0x7, 0x3, 
    0x2, 0x2, 0x65, 0x67, 0x5, 0x14, 0xb, 0x2, 0x66, 0x65, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 
    0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6a, 
    0x68, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x5, 0x2, 0x2, 0x6c, 0x70, 
    0x5, 0x1a, 0xe, 0x2, 0x6d, 0x6f, 0x5, 0xa, 0x6, 0x2, 0x6e, 0x6d, 0x3, 
    0x2, 0x2, 0x2, 0x6f, 0x72, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x73, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0x5, 0x2, 0x2, 
    0x74, 0x13, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 0x8, 0x2, 0x2, 0x76, 
    0x77, 0x7, 0x19, 0x2, 0x2, 0x77, 0x78, 0x5, 0x1a, 0xe, 0x2, 0x78, 0x79, 
    0x7, 0x9, 0x2, 0x2, 0x79, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7c, 0x5, 
    0x1a, 0xe, 0x2, 0x7b, 0x75, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7a, 0x3, 0x2, 
    0x2, 0x2, 0x7c, 0x15, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x3, 0x2, 
    0x2, 0x7e, 0x7f, 0x7, 0xa, 0x2, 0x2, 0x7f, 0x83, 0x7, 0x3, 0x2, 0x2, 
    0x80, 0x82, 0x5, 0x18, 0xd, 0x2, 0x81, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x86, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x8a, 0x7, 0x5, 0x2, 0x2, 0x87, 0x89, 0x5, 0xa, 
    0x6, 0x2, 0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8c, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x8b, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8d, 
    0x8e, 0x7, 0x5, 0x2, 0x2, 0x8e, 0x17, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 
    0x7, 0x8, 0x2, 0x2, 0x90, 0x91, 0x7, 0x19, 0x2, 0x2, 0x91, 0x93, 0x5, 
    0xa, 0x6, 0x2, 0x92, 0x94, 0x5, 0x1a, 0xe, 0x2, 0x93, 0x92, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x95, 0x96, 0x7, 0x9, 0x2, 0x2, 0x96, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x99, 0x7, 0x18, 0x2, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 
    0x7, 0x19, 0x2, 0x2, 0x9b, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x7, 
    0x3, 0x2, 0x2, 0x9d, 0xa1, 0x7, 0xb, 0x2, 0x2, 0x9e, 0xa0, 0x5, 0x20, 
    0x11, 0x2, 0x9f, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xa5, 0x7, 0x5, 0x2, 0x2, 0xa5, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 
    0x5, 0xa, 0x6, 0x2, 0xa7, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 
    0x8, 0x2, 0x2, 0xa9, 0xad, 0x5, 0x1e, 0x10, 0x2, 0xaa, 0xac, 0x5, 0xa, 
    0x6, 0x2, 0xab, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaf, 0x3, 0x2, 0x2, 
    0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb0, 
    0xb1, 0x7, 0x9, 0x2, 0x2, 0xb1, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 
    0x7, 0x8, 0x2, 0x2, 0xb3, 0xb7, 0x7, 0xc, 0x2, 0x2, 0xb4, 0xb6, 0x5, 
    0xa, 0x6, 0x2, 0xb5, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xba, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0xba, 0xbc, 0x7, 0x9, 0x2, 0x2, 0xbb, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xb2, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x21, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 
    0x7, 0x3, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x24, 0x13, 0x2, 0xbf, 0xc0, 0x5, 
    0xa, 0x6, 0x2, 0xc0, 0xc1, 0x5, 0xa, 0x6, 0x2, 0xc1, 0xc2, 0x7, 0x5, 
    0x2, 0x2, 0xc2, 0x23, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x9, 0x3, 0x2, 
    0x2, 0xc4, 0x25, 0x3, 0x2, 0x2, 0x2, 0x13, 0x29, 0x30, 0x39, 0x41, 0x52, 
    0x5b, 0x68, 0x70, 0x7b, 0x83, 0x8a, 0x93, 0x98, 0xa1, 0xad, 0xb7, 0xbb, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

lispParser::Initializer lispParser::_init;
