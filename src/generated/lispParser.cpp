
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
    setState(43);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__0) {
      setState(40);
      toplevel();
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(46);
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
    setState(50);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(48);
      defun();
      break;
    }

    case 2: {
      setState(49);
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
    setState(52);
    match(lispParser::T__0);
    setState(53);
    match(lispParser::T__1);
    setState(54);
    match(lispParser::IDENTIFIER);
    setState(55);
    match(lispParser::T__0);
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__5)
      | (1ULL << lispParser::POINTER_PREFIX)
      | (1ULL << lispParser::IDENTIFIER))) != 0)) {
      setState(56);
      typedParameter();
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(62);
    match(lispParser::T__2);
    setState(63);
    typeName();
    setState(67);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(64);
      expression();
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(70);
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
    setState(72);
    match(lispParser::T__0);
    setState(73);
    match(lispParser::T__3);
    setState(74);
    match(lispParser::IDENTIFIER);
    setState(75);
    expression();
    setState(76);
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

lispParser::CallableContext* lispParser::ExpressionContext::callable() {
  return getRuleContext<lispParser::CallableContext>(0);
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

lispParser::LoopContext* lispParser::ExpressionContext::loop() {
  return getRuleContext<lispParser::LoopContext>(0);
}

lispParser::BinaryContext* lispParser::ExpressionContext::binary() {
  return getRuleContext<lispParser::BinaryContext>(0);
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
    setState(85);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(78);
      constant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(79);
      callable();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(80);
      lambda();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(81);
      let();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(82);
      cond();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(83);
      loop();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(84);
      binary();
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
    setState(87);
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
    setState(89);
    match(lispParser::T__0);
    setState(90);
    expression();
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(91);
      parameter();
      setState(96);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(97);
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
    setState(99);
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
    setState(101);
    match(lispParser::T__0);
    setState(102);
    match(lispParser::T__4);
    setState(103);
    match(lispParser::T__0);
    setState(107);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__5)
      | (1ULL << lispParser::POINTER_PREFIX)
      | (1ULL << lispParser::IDENTIFIER))) != 0)) {
      setState(104);
      typedParameter();
      setState(109);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(110);
    match(lispParser::T__2);
    setState(111);
    typeName();
    setState(115);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(112);
      expression();
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(118);
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
    setState(126);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lispParser::T__5: {
        enterOuterAlt(_localctx, 1);
        setState(120);
        match(lispParser::T__5);
        setState(121);
        match(lispParser::IDENTIFIER);
        setState(122);
        typeName();
        setState(123);
        match(lispParser::T__6);
        break;
      }

      case lispParser::POINTER_PREFIX:
      case lispParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(125);
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
    setState(128);
    match(lispParser::T__0);
    setState(129);
    match(lispParser::T__7);
    setState(130);
    match(lispParser::T__0);
    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__5) {
      setState(131);
      typedValueBinding();
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(137);
    match(lispParser::T__2);
    setState(141);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(138);
      expression();
      setState(143);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(144);
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
    setState(146);
    match(lispParser::T__5);
    setState(147);
    match(lispParser::IDENTIFIER);
    setState(148);
    expression();
    setState(150);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lispParser::POINTER_PREFIX

    || _la == lispParser::IDENTIFIER) {
      setState(149);
      typeName();
    }
    setState(152);
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
    setState(155);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lispParser::POINTER_PREFIX) {
      setState(154);
      match(lispParser::POINTER_PREFIX);
    }
    setState(157);
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
    setState(159);
    match(lispParser::T__0);
    setState(160);
    match(lispParser::T__8);
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__5) {
      setState(161);
      condValue();
      setState(166);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(167);
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
    setState(169);
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
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(171);
      match(lispParser::T__5);
      setState(172);
      condCondition();
      setState(174); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(173);
        expression();
        setState(176); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << lispParser::T__0)
        | (1ULL << lispParser::IDENTIFIER)
        | (1ULL << lispParser::FLOAT_LITERAL)
        | (1ULL << lispParser::INTEGER_LITERAL)
        | (1ULL << lispParser::STRING_LITERAL))) != 0));
      setState(178);
      match(lispParser::T__6);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(180);
      match(lispParser::T__5);
      setState(181);
      match(lispParser::T__9);
      setState(183); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(182);
        expression();
        setState(185); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << lispParser::T__0)
        | (1ULL << lispParser::IDENTIFIER)
        | (1ULL << lispParser::FLOAT_LITERAL)
        | (1ULL << lispParser::INTEGER_LITERAL)
        | (1ULL << lispParser::STRING_LITERAL))) != 0));
      setState(187);
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

//----------------- LoopContext ------------------------------------------------------------------

lispParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lispParser::LoopBindingExpressionContext *> lispParser::LoopContext::loopBindingExpression() {
  return getRuleContexts<lispParser::LoopBindingExpressionContext>();
}

lispParser::LoopBindingExpressionContext* lispParser::LoopContext::loopBindingExpression(size_t i) {
  return getRuleContext<lispParser::LoopBindingExpressionContext>(i);
}

std::vector<lispParser::ExpressionContext *> lispParser::LoopContext::expression() {
  return getRuleContexts<lispParser::ExpressionContext>();
}

lispParser::ExpressionContext* lispParser::LoopContext::expression(size_t i) {
  return getRuleContext<lispParser::ExpressionContext>(i);
}


size_t lispParser::LoopContext::getRuleIndex() const {
  return lispParser::RuleLoop;
}


antlrcpp::Any lispParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitLoop(this);
  else
    return visitor->visitChildren(this);
}

lispParser::LoopContext* lispParser::loop() {
  LoopContext *_localctx = _tracker.createInstance<LoopContext>(_ctx, getState());
  enterRule(_localctx, 32, lispParser::RuleLoop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(lispParser::T__0);
    setState(192);
    match(lispParser::T__10);
    setState(193);
    match(lispParser::T__0);
    setState(197);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__5) {
      setState(194);
      loopBindingExpression();
      setState(199);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(200);
    match(lispParser::T__2);
    setState(201);
    match(lispParser::T__11);
    setState(205);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(202);
      expression();
      setState(207);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(208);
    match(lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopBindingExpressionContext ------------------------------------------------------------------

lispParser::LoopBindingExpressionContext::LoopBindingExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lispParser::LoopBindingExpressionContext::IDENTIFIER() {
  return getToken(lispParser::IDENTIFIER, 0);
}

std::vector<lispParser::ExpressionContext *> lispParser::LoopBindingExpressionContext::expression() {
  return getRuleContexts<lispParser::ExpressionContext>();
}

lispParser::ExpressionContext* lispParser::LoopBindingExpressionContext::expression(size_t i) {
  return getRuleContext<lispParser::ExpressionContext>(i);
}

lispParser::TypeNameContext* lispParser::LoopBindingExpressionContext::typeName() {
  return getRuleContext<lispParser::TypeNameContext>(0);
}


size_t lispParser::LoopBindingExpressionContext::getRuleIndex() const {
  return lispParser::RuleLoopBindingExpression;
}


antlrcpp::Any lispParser::LoopBindingExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitLoopBindingExpression(this);
  else
    return visitor->visitChildren(this);
}

lispParser::LoopBindingExpressionContext* lispParser::loopBindingExpression() {
  LoopBindingExpressionContext *_localctx = _tracker.createInstance<LoopBindingExpressionContext>(_ctx, getState());
  enterRule(_localctx, 34, lispParser::RuleLoopBindingExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(lispParser::T__5);
    setState(211);
    match(lispParser::IDENTIFIER);
    setState(212);
    expression();
    setState(213);
    typeName();
    setState(214);
    expression();
    setState(215);
    expression();
    setState(216);
    match(lispParser::T__6);
   
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
  enterRule(_localctx, 36, lispParser::RuleBinary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(lispParser::T__0);
    setState(219);
    binaryOperator();
    setState(220);
    expression();
    setState(221);
    expression();
    setState(222);
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
  enterRule(_localctx, 38, lispParser::RuleBinaryOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__12)
      | (1ULL << lispParser::T__13)
      | (1ULL << lispParser::T__14)
      | (1ULL << lispParser::T__15)
      | (1ULL << lispParser::T__16)
      | (1ULL << lispParser::T__17)
      | (1ULL << lispParser::T__18)
      | (1ULL << lispParser::T__19)
      | (1ULL << lispParser::T__20)
      | (1ULL << lispParser::T__21))) != 0))) {
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
  "cond", "condCondition", "condValue", "loop", "loopBindingExpression", 
  "binary", "binaryOperator"
};

std::vector<std::string> lispParser::_literalNames = {
  "", "'('", "'defun'", "')'", "'define'", "'lambda'", "'['", "']'", "'let'", 
  "'cond'", "'else'", "'loop'", "'do'", "'+'", "'-'", "'*'", "'/'", "'='", 
  "'>'", "'<'", "'~='", "'>='", "'<='", "", "'&'"
};

std::vector<std::string> lispParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "WHITESPACE", "POINTER_PREFIX", "IDENTIFIER", "FLOAT_LITERAL", 
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
    0x3, 0x1f, 0xe5, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x3, 0x2, 0x7, 0x2, 0x2c, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x2f, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x35, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x3c, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x3f, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x7, 0x4, 0x44, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x47, 0xb, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x58, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x7, 0x8, 0x5f, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x62, 0xb, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x7, 0xa, 0x6c, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x6f, 0xb, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x74, 0xa, 0xa, 0xc, 0xa, 0xe, 
    0xa, 0x77, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x81, 0xa, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x87, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 
    0x8a, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x8e, 0xa, 0xc, 0xc, 0xc, 
    0xe, 0xc, 0x91, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x5, 0xd, 0x99, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
    0x5, 0xe, 0x9e, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x7, 0xf, 0xa5, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xa8, 0xb, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x6, 0x11, 0xb1, 0xa, 0x11, 0xd, 0x11, 0xe, 0x11, 0xb2, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x6, 0x11, 0xba, 0xa, 0x11, 0xd, 
    0x11, 0xe, 0x11, 0xbb, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xc0, 0xa, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xc6, 0xa, 0x12, 
    0xc, 0x12, 0xe, 0x12, 0xc9, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x7, 0x12, 0xce, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xd1, 0xb, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x2, 0x2, 
    0x16, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2, 0x4, 0x3, 0x2, 
    0x1b, 0x1e, 0x3, 0x2, 0xf, 0x18, 0x2, 0xe8, 0x2, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x34, 0x3, 0x2, 0x2, 0x2, 0x6, 0x36, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x4a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x57, 0x3, 0x2, 0x2, 0x2, 0xc, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x10, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x67, 0x3, 0x2, 0x2, 0x2, 0x14, 0x80, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x82, 0x3, 0x2, 0x2, 0x2, 0x18, 0x94, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xab, 0x3, 0x2, 0x2, 0x2, 0x20, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xc1, 0x3, 0x2, 0x2, 0x2, 0x24, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x26, 0xdc, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0xe2, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x5, 
    0x4, 0x3, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x31, 0x7, 0x2, 0x2, 0x3, 0x31, 0x3, 0x3, 0x2, 0x2, 0x2, 0x32, 
    0x35, 0x5, 0x6, 0x4, 0x2, 0x33, 0x35, 0x5, 0x8, 0x5, 0x2, 0x34, 0x32, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 0x3, 0x2, 0x2, 0x37, 0x38, 0x7, 0x4, 
    0x2, 0x2, 0x38, 0x39, 0x7, 0x1b, 0x2, 0x2, 0x39, 0x3d, 0x7, 0x3, 0x2, 
    0x2, 0x3a, 0x3c, 0x5, 0x14, 0xb, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x7, 0x5, 0x2, 0x2, 0x41, 0x45, 0x5, 
    0x1a, 0xe, 0x2, 0x42, 0x44, 0x5, 0xa, 0x6, 0x2, 0x43, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x47, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0x5, 0x2, 0x2, 0x49, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x3, 0x2, 0x2, 0x4b, 0x4c, 
    0x7, 0x6, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x1b, 0x2, 0x2, 0x4d, 0x4e, 0x5, 
    0xa, 0x6, 0x2, 0x4e, 0x4f, 0x7, 0x5, 0x2, 0x2, 0x4f, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x50, 0x58, 0x5, 0xc, 0x7, 0x2, 0x51, 0x58, 0x5, 0xe, 0x8, 
    0x2, 0x52, 0x58, 0x5, 0x12, 0xa, 0x2, 0x53, 0x58, 0x5, 0x16, 0xc, 0x2, 
    0x54, 0x58, 0x5, 0x1c, 0xf, 0x2, 0x55, 0x58, 0x5, 0x22, 0x12, 0x2, 0x56, 
    0x58, 0x5, 0x26, 0x14, 0x2, 0x57, 0x50, 0x3, 0x2, 0x2, 0x2, 0x57, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x52, 0x3, 0x2, 0x2, 0x2, 0x57, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x57, 0x54, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x59, 0x5a, 0x9, 0x2, 0x2, 0x2, 0x5a, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x5c, 0x7, 0x3, 0x2, 0x2, 0x5c, 0x60, 0x5, 0xa, 0x6, 0x2, 0x5d, 
    0x5f, 0x5, 0x10, 0x9, 0x2, 0x5e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x61, 0x63, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 
    0x2, 0x2, 0x63, 0x64, 0x7, 0x5, 0x2, 0x2, 0x64, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x65, 0x66, 0x5, 0xa, 0x6, 0x2, 0x66, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x67, 0x68, 0x7, 0x3, 0x2, 0x2, 0x68, 0x69, 0x7, 0x7, 0x2, 0x2, 0x69, 
    0x6d, 0x7, 0x3, 0x2, 0x2, 0x6a, 0x6c, 0x5, 0x14, 0xb, 0x2, 0x6b, 0x6a, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6b, 0x3, 
    0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0x5, 0x2, 
    0x2, 0x71, 0x75, 0x5, 0x1a, 0xe, 0x2, 0x72, 0x74, 0x5, 0xa, 0x6, 0x2, 
    0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x77, 0x3, 0x2, 0x2, 0x2, 0x75, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x78, 
    0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 
    0x5, 0x2, 0x2, 0x79, 0x13, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x8, 
    0x2, 0x2, 0x7b, 0x7c, 0x7, 0x1b, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x1a, 0xe, 
    0x2, 0x7d, 0x7e, 0x7, 0x9, 0x2, 0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x7f, 0x81, 0x5, 0x1a, 0xe, 0x2, 0x80, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x15, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 
    0x7, 0x3, 0x2, 0x2, 0x83, 0x84, 0x7, 0xa, 0x2, 0x2, 0x84, 0x88, 0x7, 
    0x3, 0x2, 0x2, 0x85, 0x87, 0x5, 0x18, 0xd, 0x2, 0x86, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x87, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 
    0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8f, 0x7, 0x5, 0x2, 0x2, 0x8c, 
    0x8e, 0x5, 0xa, 0x6, 0x2, 0x8d, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x92, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x93, 0x7, 0x5, 0x2, 0x2, 0x93, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x95, 0x7, 0x8, 0x2, 0x2, 0x95, 0x96, 0x7, 0x1b, 0x2, 0x2, 
    0x96, 0x98, 0x5, 0xa, 0x6, 0x2, 0x97, 0x99, 0x5, 0x1a, 0xe, 0x2, 0x98, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 
    0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x9, 0x2, 0x2, 0x9b, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x9e, 0x7, 0x1a, 0x2, 0x2, 0x9d, 0x9c, 0x3, 0x2, 
    0x2, 0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 
    0x2, 0x9f, 0xa0, 0x7, 0x1b, 0x2, 0x2, 0xa0, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0xa1, 0xa2, 0x7, 0x3, 0x2, 0x2, 0xa2, 0xa6, 0x7, 0xb, 0x2, 0x2, 0xa3, 
    0xa5, 0x5, 0x20, 0x11, 0x2, 0xa4, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa8, 
    0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0xa9, 0xaa, 0x7, 0x5, 0x2, 0x2, 0xaa, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0xab, 0xac, 0x5, 0xa, 0x6, 0x2, 0xac, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0xad, 0xae, 0x7, 0x8, 0x2, 0x2, 0xae, 0xb0, 0x5, 0x1e, 0x10, 0x2, 0xaf, 
    0xb1, 0x5, 0xa, 0x6, 0x2, 0xb0, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x9, 
    0x2, 0x2, 0xb5, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x8, 0x2, 
    0x2, 0xb7, 0xb9, 0x7, 0xc, 0x2, 0x2, 0xb8, 0xba, 0x5, 0xa, 0x6, 0x2, 
    0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xb9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0x9, 0x2, 0x2, 0xbe, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0x21, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x3, 0x2, 
    0x2, 0xc2, 0xc3, 0x7, 0xd, 0x2, 0x2, 0xc3, 0xc7, 0x7, 0x3, 0x2, 0x2, 
    0xc4, 0xc6, 0x5, 0x24, 0x13, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xc9, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 
    0x3, 0x2, 0x2, 0x2, 0xc8, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x5, 0x2, 0x2, 0xcb, 0xcf, 0x7, 0xe, 
    0x2, 0x2, 0xcc, 0xce, 0x5, 0xa, 0x6, 0x2, 0xcd, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd1, 
    0xcf, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x5, 0x2, 0x2, 0xd3, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x8, 0x2, 0x2, 0xd5, 0xd6, 0x7, 
    0x1b, 0x2, 0x2, 0xd6, 0xd7, 0x5, 0xa, 0x6, 0x2, 0xd7, 0xd8, 0x5, 0x1a, 
    0xe, 0x2, 0xd8, 0xd9, 0x5, 0xa, 0x6, 0x2, 0xd9, 0xda, 0x5, 0xa, 0x6, 
    0x2, 0xda, 0xdb, 0x7, 0x9, 0x2, 0x2, 0xdb, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xdd, 0x7, 0x3, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x28, 0x15, 0x2, 0xde, 
    0xdf, 0x5, 0xa, 0x6, 0x2, 0xdf, 0xe0, 0x5, 0xa, 0x6, 0x2, 0xe0, 0xe1, 
    0x7, 0x5, 0x2, 0x2, 0xe1, 0x27, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x9, 
    0x3, 0x2, 0x2, 0xe3, 0x29, 0x3, 0x2, 0x2, 0x2, 0x15, 0x2d, 0x34, 0x3d, 
    0x45, 0x57, 0x60, 0x6d, 0x75, 0x80, 0x88, 0x8f, 0x98, 0x9d, 0xa6, 0xb2, 
    0xbb, 0xbf, 0xc7, 0xcf, 
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
