
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
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__0) {
      setState(46);
      toplevel();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(52);
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

lispParser::DefstructContext* lispParser::ToplevelContext::defstruct() {
  return getRuleContext<lispParser::DefstructContext>(0);
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
    setState(57);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(54);
      defun();
      break;
    }

    case 2: {
      setState(55);
      define();
      break;
    }

    case 3: {
      setState(56);
      defstruct();
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
    setState(59);
    match(lispParser::T__0);
    setState(60);
    match(lispParser::T__1);
    setState(61);
    match(lispParser::IDENTIFIER);
    setState(62);
    match(lispParser::T__0);
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__5)
      | (1ULL << lispParser::POINTER_PREFIX)
      | (1ULL << lispParser::IDENTIFIER))) != 0)) {
      setState(63);
      typedParameter();
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(69);
    match(lispParser::T__2);
    setState(70);
    typeName();
    setState(74);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(71);
      expression();
      setState(76);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(77);
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
    setState(79);
    match(lispParser::T__0);
    setState(80);
    match(lispParser::T__3);
    setState(81);
    match(lispParser::IDENTIFIER);
    setState(82);
    expression();
    setState(83);
    match(lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefstructContext ------------------------------------------------------------------

lispParser::DefstructContext::DefstructContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lispParser::DefstructContext::IDENTIFIER() {
  return getToken(lispParser::IDENTIFIER, 0);
}

std::vector<lispParser::StructMemberContext *> lispParser::DefstructContext::structMember() {
  return getRuleContexts<lispParser::StructMemberContext>();
}

lispParser::StructMemberContext* lispParser::DefstructContext::structMember(size_t i) {
  return getRuleContext<lispParser::StructMemberContext>(i);
}


size_t lispParser::DefstructContext::getRuleIndex() const {
  return lispParser::RuleDefstruct;
}


antlrcpp::Any lispParser::DefstructContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitDefstruct(this);
  else
    return visitor->visitChildren(this);
}

lispParser::DefstructContext* lispParser::defstruct() {
  DefstructContext *_localctx = _tracker.createInstance<DefstructContext>(_ctx, getState());
  enterRule(_localctx, 8, lispParser::RuleDefstruct);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(lispParser::T__0);
    setState(86);
    match(lispParser::T__4);
    setState(87);
    match(lispParser::IDENTIFIER);
    setState(89); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(88);
      structMember();
      setState(91); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == lispParser::T__5);
    setState(93);
    match(lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructMemberContext ------------------------------------------------------------------

lispParser::StructMemberContext::StructMemberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lispParser::StructMemberContext::IDENTIFIER() {
  return getToken(lispParser::IDENTIFIER, 0);
}

lispParser::TypeNameContext* lispParser::StructMemberContext::typeName() {
  return getRuleContext<lispParser::TypeNameContext>(0);
}

lispParser::ExpressionContext* lispParser::StructMemberContext::expression() {
  return getRuleContext<lispParser::ExpressionContext>(0);
}


size_t lispParser::StructMemberContext::getRuleIndex() const {
  return lispParser::RuleStructMember;
}


antlrcpp::Any lispParser::StructMemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitStructMember(this);
  else
    return visitor->visitChildren(this);
}

lispParser::StructMemberContext* lispParser::structMember() {
  StructMemberContext *_localctx = _tracker.createInstance<StructMemberContext>(_ctx, getState());
  enterRule(_localctx, 10, lispParser::RuleStructMember);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(lispParser::T__5);
    setState(96);
    match(lispParser::IDENTIFIER);
    setState(97);
    typeName();
    setState(99);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(98);
      expression();
    }
    setState(101);
    match(lispParser::T__6);
   
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
  enterRule(_localctx, 12, lispParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(103);
      constant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(104);
      callable();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(105);
      lambda();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(106);
      let();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(107);
      cond();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(108);
      loop();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(109);
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

lispParser::SymbolReferenceContext* lispParser::ConstantContext::symbolReference() {
  return getRuleContext<lispParser::SymbolReferenceContext>(0);
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
  enterRule(_localctx, 14, lispParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(116);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lispParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(112);
        symbolReference();
        break;
      }

      case lispParser::FLOAT_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(113);
        match(lispParser::FLOAT_LITERAL);
        break;
      }

      case lispParser::INTEGER_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(114);
        match(lispParser::INTEGER_LITERAL);
        break;
      }

      case lispParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(115);
        match(lispParser::STRING_LITERAL);
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

//----------------- SymbolReferenceContext ------------------------------------------------------------------

lispParser::SymbolReferenceContext::SymbolReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> lispParser::SymbolReferenceContext::IDENTIFIER() {
  return getTokens(lispParser::IDENTIFIER);
}

tree::TerminalNode* lispParser::SymbolReferenceContext::IDENTIFIER(size_t i) {
  return getToken(lispParser::IDENTIFIER, i);
}


size_t lispParser::SymbolReferenceContext::getRuleIndex() const {
  return lispParser::RuleSymbolReference;
}


antlrcpp::Any lispParser::SymbolReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lispVisitor*>(visitor))
    return parserVisitor->visitSymbolReference(this);
  else
    return visitor->visitChildren(this);
}

lispParser::SymbolReferenceContext* lispParser::symbolReference() {
  SymbolReferenceContext *_localctx = _tracker.createInstance<SymbolReferenceContext>(_ctx, getState());
  enterRule(_localctx, 16, lispParser::RuleSymbolReference);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(lispParser::IDENTIFIER);
    setState(123);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__7) {
      setState(119);
      match(lispParser::T__7);
      setState(120);
      match(lispParser::IDENTIFIER);
      setState(125);
      _errHandler->sync(this);
      _la = _input->LA(1);
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
  enterRule(_localctx, 18, lispParser::RuleCallable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    match(lispParser::T__0);
    setState(127);
    expression();
    setState(131);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(128);
      parameter();
      setState(133);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(134);
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
  enterRule(_localctx, 20, lispParser::RuleParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
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
  enterRule(_localctx, 22, lispParser::RuleLambda);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    match(lispParser::T__0);
    setState(139);
    match(lispParser::T__8);
    setState(140);
    match(lispParser::T__0);
    setState(144);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__5)
      | (1ULL << lispParser::POINTER_PREFIX)
      | (1ULL << lispParser::IDENTIFIER))) != 0)) {
      setState(141);
      typedParameter();
      setState(146);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(147);
    match(lispParser::T__2);
    setState(148);
    typeName();
    setState(152);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(149);
      expression();
      setState(154);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(155);
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
  enterRule(_localctx, 24, lispParser::RuleTypedParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(163);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lispParser::T__5: {
        enterOuterAlt(_localctx, 1);
        setState(157);
        match(lispParser::T__5);
        setState(158);
        match(lispParser::IDENTIFIER);
        setState(159);
        typeName();
        setState(160);
        match(lispParser::T__6);
        break;
      }

      case lispParser::POINTER_PREFIX:
      case lispParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(162);
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
  enterRule(_localctx, 26, lispParser::RuleLet);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(lispParser::T__0);
    setState(166);
    match(lispParser::T__9);
    setState(167);
    match(lispParser::T__0);
    setState(171);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__5) {
      setState(168);
      typedValueBinding();
      setState(173);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(174);
    match(lispParser::T__2);
    setState(178);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(175);
      expression();
      setState(180);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(181);
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
  enterRule(_localctx, 28, lispParser::RuleTypedValueBinding);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(lispParser::T__5);
    setState(184);
    match(lispParser::IDENTIFIER);
    setState(186);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(185);
      typeName();
      break;
    }

    }
    setState(188);
    expression();
    setState(189);
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
  enterRule(_localctx, 30, lispParser::RuleTypeName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lispParser::POINTER_PREFIX) {
      setState(191);
      match(lispParser::POINTER_PREFIX);
    }
    setState(194);
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
  enterRule(_localctx, 32, lispParser::RuleCond);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    match(lispParser::T__0);
    setState(197);
    match(lispParser::T__10);
    setState(201);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__5) {
      setState(198);
      condValue();
      setState(203);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(204);
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
  enterRule(_localctx, 34, lispParser::RuleCondCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
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
  enterRule(_localctx, 36, lispParser::RuleCondValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(226);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(208);
      match(lispParser::T__5);
      setState(209);
      condCondition();
      setState(211); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(210);
        expression();
        setState(213); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << lispParser::T__0)
        | (1ULL << lispParser::IDENTIFIER)
        | (1ULL << lispParser::FLOAT_LITERAL)
        | (1ULL << lispParser::INTEGER_LITERAL)
        | (1ULL << lispParser::STRING_LITERAL))) != 0));
      setState(215);
      match(lispParser::T__6);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(217);
      match(lispParser::T__5);
      setState(218);
      match(lispParser::T__11);
      setState(220); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(219);
        expression();
        setState(222); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << lispParser::T__0)
        | (1ULL << lispParser::IDENTIFIER)
        | (1ULL << lispParser::FLOAT_LITERAL)
        | (1ULL << lispParser::INTEGER_LITERAL)
        | (1ULL << lispParser::STRING_LITERAL))) != 0));
      setState(224);
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
  enterRule(_localctx, 38, lispParser::RuleLoop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    match(lispParser::T__0);
    setState(229);
    match(lispParser::T__12);
    setState(230);
    match(lispParser::T__0);
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lispParser::T__5) {
      setState(231);
      loopBindingExpression();
      setState(236);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(237);
    match(lispParser::T__2);
    setState(238);
    match(lispParser::T__13);
    setState(242);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__0)
      | (1ULL << lispParser::IDENTIFIER)
      | (1ULL << lispParser::FLOAT_LITERAL)
      | (1ULL << lispParser::INTEGER_LITERAL)
      | (1ULL << lispParser::STRING_LITERAL))) != 0)) {
      setState(239);
      expression();
      setState(244);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(245);
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
  enterRule(_localctx, 40, lispParser::RuleLoopBindingExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    match(lispParser::T__5);
    setState(248);
    match(lispParser::IDENTIFIER);
    setState(250);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(249);
      typeName();
      break;
    }

    }
    setState(252);
    expression();
    setState(253);
    expression();
    setState(254);
    expression();
    setState(255);
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
  enterRule(_localctx, 42, lispParser::RuleBinary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(lispParser::T__0);
    setState(258);
    binaryOperator();
    setState(259);
    expression();
    setState(260);
    expression();
    setState(261);
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
  enterRule(_localctx, 44, lispParser::RuleBinaryOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lispParser::T__14)
      | (1ULL << lispParser::T__15)
      | (1ULL << lispParser::T__16)
      | (1ULL << lispParser::T__17)
      | (1ULL << lispParser::T__18)
      | (1ULL << lispParser::T__19)
      | (1ULL << lispParser::T__20)
      | (1ULL << lispParser::T__21)
      | (1ULL << lispParser::T__22)
      | (1ULL << lispParser::T__23))) != 0))) {
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
  "program", "toplevel", "defun", "define", "defstruct", "structMember", 
  "expression", "constant", "symbolReference", "callable", "parameter", 
  "lambda", "typedParameter", "let", "typedValueBinding", "typeName", "cond", 
  "condCondition", "condValue", "loop", "loopBindingExpression", "binary", 
  "binaryOperator"
};

std::vector<std::string> lispParser::_literalNames = {
  "", "'('", "'defun'", "')'", "'define'", "'defstruct'", "'['", "']'", 
  "'.'", "'lambda'", "'let'", "'cond'", "'else'", "'loop'", "'do'", "'+'", 
  "'-'", "'*'", "'/'", "'='", "'>'", "'<'", "'~='", "'>='", "'<='", "", 
  "'&'"
};

std::vector<std::string> lispParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "WHITESPACE", "POINTER_PREFIX", "IDENTIFIER", 
  "FLOAT_LITERAL", "INTEGER_LITERAL", "STRING_LITERAL", "LINE_COMMENT"
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
    0x3, 0x21, 0x10c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x3, 0x2, 0x7, 0x2, 0x32, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x35, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x3c, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x43, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x46, 0xb, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0x4b, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x4e, 0xb, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x5c, 
    0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x5d, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x66, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x71, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x77, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x7c, 0xa, 
    0xa, 0xc, 0xa, 0xe, 0xa, 0x7f, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0x84, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x87, 0xb, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x7, 0xd, 0x91, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x94, 0xb, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x99, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x9c, 
    0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xa6, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x7, 0xf, 0xac, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xaf, 0xb, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xb3, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 
    0xb6, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x5, 0x10, 0xbd, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 
    0x5, 0x11, 0xc3, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x7, 0x12, 0xca, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xcd, 0xb, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x6, 0x14, 0xd6, 0xa, 0x14, 0xd, 0x14, 0xe, 0x14, 0xd7, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x6, 0x14, 0xdf, 0xa, 
    0x14, 0xd, 0x14, 0xe, 0x14, 0xe0, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xe5, 
    0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xeb, 
    0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xee, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x7, 0x15, 0xf3, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xf6, 0xb, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 
    0xfd, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x2, 0x2, 0x19, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x2, 0x3, 0x3, 0x2, 0x11, 0x1a, 
    0x2, 0x114, 0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x8, 0x51, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x57, 0x3, 0x2, 0x2, 0x2, 0xc, 0x61, 0x3, 0x2, 0x2, 0x2, 0xe, 0x70, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x76, 0x3, 0x2, 0x2, 0x2, 0x12, 0x78, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x80, 0x3, 0x2, 0x2, 0x2, 0x16, 0x8a, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xb9, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x22, 0xc6, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0x26, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x28, 0xe6, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x103, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x109, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 0x5, 0x4, 
    0x3, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x37, 0x7, 0x2, 0x2, 0x3, 0x37, 0x3, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3c, 
    0x5, 0x6, 0x4, 0x2, 0x39, 0x3c, 0x5, 0x8, 0x5, 0x2, 0x3a, 0x3c, 0x5, 
    0xa, 0x6, 0x2, 0x3b, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x3e, 0x7, 0x3, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x4, 0x2, 0x2, 
    0x3f, 0x40, 0x7, 0x1d, 0x2, 0x2, 0x40, 0x44, 0x7, 0x3, 0x2, 0x2, 0x41, 
    0x43, 0x5, 0x1a, 0xe, 0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x46, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x47, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x48, 0x7, 0x5, 0x2, 0x2, 0x48, 0x4c, 0x5, 0x20, 0x11, 
    0x2, 0x49, 0x4b, 0x5, 0xe, 0x8, 0x2, 0x4a, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x5, 0x2, 0x2, 0x50, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x3, 0x2, 0x2, 0x52, 0x53, 0x7, 0x6, 
    0x2, 0x2, 0x53, 0x54, 0x7, 0x1d, 0x2, 0x2, 0x54, 0x55, 0x5, 0xe, 0x8, 
    0x2, 0x55, 0x56, 0x7, 0x5, 0x2, 0x2, 0x56, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x58, 0x7, 0x3, 0x2, 0x2, 0x58, 0x59, 0x7, 0x7, 0x2, 0x2, 0x59, 
    0x5b, 0x7, 0x1d, 0x2, 0x2, 0x5a, 0x5c, 0x5, 0xc, 0x7, 0x2, 0x5b, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x5f, 0x60, 0x7, 0x5, 0x2, 0x2, 0x60, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x7, 0x8, 0x2, 0x2, 0x62, 0x63, 0x7, 0x1d, 0x2, 0x2, 
    0x63, 0x65, 0x5, 0x20, 0x11, 0x2, 0x64, 0x66, 0x5, 0xe, 0x8, 0x2, 0x65, 
    0x64, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x9, 0x2, 0x2, 0x68, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x71, 0x5, 0x10, 0x9, 0x2, 0x6a, 0x71, 0x5, 0x14, 
    0xb, 0x2, 0x6b, 0x71, 0x5, 0x18, 0xd, 0x2, 0x6c, 0x71, 0x5, 0x1c, 0xf, 
    0x2, 0x6d, 0x71, 0x5, 0x22, 0x12, 0x2, 0x6e, 0x71, 0x5, 0x28, 0x15, 
    0x2, 0x6f, 0x71, 0x5, 0x2c, 0x17, 0x2, 0x70, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x77, 0x5, 0x12, 0xa, 0x2, 0x73, 0x77, 0x7, 0x1e, 
    0x2, 0x2, 0x74, 0x77, 0x7, 0x1f, 0x2, 0x2, 0x75, 0x77, 0x7, 0x20, 0x2, 
    0x2, 0x76, 0x72, 0x3, 0x2, 0x2, 0x2, 0x76, 0x73, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x76, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7d, 0x7, 0x1d, 0x2, 0x2, 0x79, 0x7a, 
    0x7, 0xa, 0x2, 0x2, 0x7a, 0x7c, 0x7, 0x1d, 0x2, 0x2, 0x7b, 0x79, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x7, 0x3, 0x2, 0x2, 
    0x81, 0x85, 0x5, 0xe, 0x8, 0x2, 0x82, 0x84, 0x5, 0x16, 0xc, 0x2, 0x83, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 0x87, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 
    0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 0x2, 0x2, 0x86, 0x88, 0x3, 
    0x2, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x5, 
    0x2, 0x2, 0x89, 0x15, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x5, 0xe, 0x8, 
    0x2, 0x8b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x3, 0x2, 0x2, 
    0x8d, 0x8e, 0x7, 0xb, 0x2, 0x2, 0x8e, 0x92, 0x7, 0x3, 0x2, 0x2, 0x8f, 
    0x91, 0x5, 0x1a, 0xe, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x94, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 
    0x2, 0x2, 0x2, 0x93, 0x95, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 
    0x2, 0x2, 0x95, 0x96, 0x7, 0x5, 0x2, 0x2, 0x96, 0x9a, 0x5, 0x20, 0x11, 
    0x2, 0x97, 0x99, 0x5, 0xe, 0x8, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x99, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 
    0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9a, 
    0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x5, 0x2, 0x2, 0x9e, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x8, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x1d, 
    0x2, 0x2, 0xa1, 0xa2, 0x5, 0x20, 0x11, 0x2, 0xa2, 0xa3, 0x7, 0x9, 0x2, 
    0x2, 0xa3, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa6, 0x5, 0x20, 0x11, 0x2, 
    0xa5, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x3, 0x2, 0x2, 0xa8, 0xa9, 
    0x7, 0xc, 0x2, 0x2, 0xa9, 0xad, 0x7, 0x3, 0x2, 0x2, 0xaa, 0xac, 0x5, 
    0x1e, 0x10, 0x2, 0xab, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0xae, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0xb4, 0x7, 0x5, 0x2, 0x2, 0xb1, 0xb3, 0x5, 0xe, 0x8, 0x2, 0xb2, 
    0xb1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb2, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x5, 
    0x2, 0x2, 0xb8, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x8, 0x2, 
    0x2, 0xba, 0xbc, 0x7, 0x1d, 0x2, 0x2, 0xbb, 0xbd, 0x5, 0x20, 0x11, 0x2, 
    0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0xe, 0x8, 0x2, 0xbf, 0xc0, 
    0x7, 0x9, 0x2, 0x2, 0xc0, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc3, 0x7, 
    0x1c, 0x2, 0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x1d, 0x2, 
    0x2, 0xc5, 0x21, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x3, 0x2, 0x2, 
    0xc7, 0xcb, 0x7, 0xd, 0x2, 0x2, 0xc8, 0xca, 0x5, 0x26, 0x14, 0x2, 0xc9, 
    0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 
    0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x5, 
    0x2, 0x2, 0xcf, 0x23, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x5, 0xe, 0x8, 
    0x2, 0xd1, 0x25, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x8, 0x2, 0x2, 
    0xd3, 0xd5, 0x5, 0x24, 0x13, 0x2, 0xd4, 0xd6, 0x5, 0xe, 0x8, 0x2, 0xd5, 
    0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 
    0x2, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x9, 0x2, 0x2, 0xda, 0xe5, 0x3, 0x2, 
    0x2, 0x2, 0xdb, 0xdc, 0x7, 0x8, 0x2, 0x2, 0xdc, 0xde, 0x7, 0xe, 0x2, 
    0x2, 0xdd, 0xdf, 0x5, 0xe, 0x8, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 
    0x7, 0x9, 0x2, 0x2, 0xe3, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xd2, 0x3, 
    0x2, 0x2, 0x2, 0xe4, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xe5, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xe7, 0x7, 0x3, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0xf, 0x2, 
    0x2, 0xe8, 0xec, 0x7, 0x3, 0x2, 0x2, 0xe9, 0xeb, 0x5, 0x2a, 0x16, 0x2, 
    0xea, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 0x2, 0x2, 0xec, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x7, 
    0x5, 0x2, 0x2, 0xf0, 0xf4, 0x7, 0x10, 0x2, 0x2, 0xf1, 0xf3, 0x5, 0xe, 
    0x8, 0x2, 0xf2, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf6, 0x3, 0x2, 0x2, 
    0x2, 0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 
    0xf5, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf7, 
    0xf8, 0x7, 0x5, 0x2, 0x2, 0xf8, 0x29, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 
    0x7, 0x8, 0x2, 0x2, 0xfa, 0xfc, 0x7, 0x1d, 0x2, 0x2, 0xfb, 0xfd, 0x5, 
    0x20, 0x11, 0x2, 0xfc, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x3, 0x2, 
    0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x5, 0xe, 0x8, 
    0x2, 0xff, 0x100, 0x5, 0xe, 0x8, 0x2, 0x100, 0x101, 0x5, 0xe, 0x8, 0x2, 
    0x101, 0x102, 0x7, 0x9, 0x2, 0x2, 0x102, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x103, 
    0x104, 0x7, 0x3, 0x2, 0x2, 0x104, 0x105, 0x5, 0x2e, 0x18, 0x2, 0x105, 
    0x106, 0x5, 0xe, 0x8, 0x2, 0x106, 0x107, 0x5, 0xe, 0x8, 0x2, 0x107, 
    0x108, 0x7, 0x5, 0x2, 0x2, 0x108, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 
    0x9, 0x2, 0x2, 0x2, 0x10a, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x33, 0x3b, 
    0x44, 0x4c, 0x5d, 0x65, 0x70, 0x76, 0x7d, 0x85, 0x92, 0x9a, 0xa5, 0xad, 
    0xb4, 0xbc, 0xc2, 0xcb, 0xd7, 0xe0, 0xe4, 0xec, 0xf4, 0xfc, 
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
