
// Generated from Behaviors.g4 by ANTLR 4.9.3


#include "BehaviorsVisitor.h"

#include "BehaviorsParser.h"


using namespace antlrcpp;
using namespace antlr4;

BehaviorsParser::BehaviorsParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

BehaviorsParser::~BehaviorsParser() {
  delete _interpreter;
}

std::string BehaviorsParser::getGrammarFileName() const {
  return "Behaviors.g4";
}

const std::vector<std::string>& BehaviorsParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& BehaviorsParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

BehaviorsParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BehaviorsParser::StatementContext *> BehaviorsParser::ProgramContext::statement() {
  return getRuleContexts<BehaviorsParser::StatementContext>();
}

BehaviorsParser::StatementContext* BehaviorsParser::ProgramContext::statement(size_t i) {
  return getRuleContext<BehaviorsParser::StatementContext>(i);
}


size_t BehaviorsParser::ProgramContext::getRuleIndex() const {
  return BehaviorsParser::RuleProgram;
}


antlrcpp::Any BehaviorsParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::ProgramContext* BehaviorsParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, BehaviorsParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(40);
      statement();
      setState(43); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BehaviorsParser::T__0)
      | (1ULL << BehaviorsParser::T__5)
      | (1ULL << BehaviorsParser::T__9)
      | (1ULL << BehaviorsParser::T__10)
      | (1ULL << BehaviorsParser::T__11)
      | (1ULL << BehaviorsParser::T__12)
      | (1ULL << BehaviorsParser::NUMBER))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

BehaviorsParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorsParser::ConsiderationContext* BehaviorsParser::StatementContext::consideration() {
  return getRuleContext<BehaviorsParser::ConsiderationContext>(0);
}

BehaviorsParser::StateSelectorContext* BehaviorsParser::StatementContext::stateSelector() {
  return getRuleContext<BehaviorsParser::StateSelectorContext>(0);
}

BehaviorsParser::StateDeclarationContext* BehaviorsParser::StatementContext::stateDeclaration() {
  return getRuleContext<BehaviorsParser::StateDeclarationContext>(0);
}

BehaviorsParser::EnvironmentStateDeclarationContext* BehaviorsParser::StatementContext::environmentStateDeclaration() {
  return getRuleContext<BehaviorsParser::EnvironmentStateDeclarationContext>(0);
}

BehaviorsParser::StateTransitionContext* BehaviorsParser::StatementContext::stateTransition() {
  return getRuleContext<BehaviorsParser::StateTransitionContext>(0);
}

BehaviorsParser::StateActionContext* BehaviorsParser::StatementContext::stateAction() {
  return getRuleContext<BehaviorsParser::StateActionContext>(0);
}


size_t BehaviorsParser::StatementContext::getRuleIndex() const {
  return BehaviorsParser::RuleStatement;
}


antlrcpp::Any BehaviorsParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::StatementContext* BehaviorsParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, BehaviorsParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(51);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(45);
      consideration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(46);
      stateSelector();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(47);
      stateDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(48);
      environmentStateDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(49);
      stateTransition();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(50);
      stateAction();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConsiderationContext ------------------------------------------------------------------

BehaviorsParser::ConsiderationContext::ConsiderationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::ConsiderationContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}


size_t BehaviorsParser::ConsiderationContext::getRuleIndex() const {
  return BehaviorsParser::RuleConsideration;
}


antlrcpp::Any BehaviorsParser::ConsiderationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitConsideration(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::ConsiderationContext* BehaviorsParser::consideration() {
  ConsiderationContext *_localctx = _tracker.createInstance<ConsiderationContext>(_ctx, getState());
  enterRule(_localctx, 4, BehaviorsParser::RuleConsideration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(BehaviorsParser::T__0);
    setState(54);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(55);
    match(BehaviorsParser::ID);
    setState(56);
    match(BehaviorsParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateSelectorContext ------------------------------------------------------------------

BehaviorsParser::StateSelectorContext::StateSelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorsParser::IdRatioSelectorContext* BehaviorsParser::StateSelectorContext::idRatioSelector() {
  return getRuleContext<BehaviorsParser::IdRatioSelectorContext>(0);
}

BehaviorsParser::RandomIdRatioSelectorContext* BehaviorsParser::StateSelectorContext::randomIdRatioSelector() {
  return getRuleContext<BehaviorsParser::RandomIdRatioSelectorContext>(0);
}

BehaviorsParser::EveryoneSelectorContext* BehaviorsParser::StateSelectorContext::everyoneSelector() {
  return getRuleContext<BehaviorsParser::EveryoneSelectorContext>(0);
}


size_t BehaviorsParser::StateSelectorContext::getRuleIndex() const {
  return BehaviorsParser::RuleStateSelector;
}


antlrcpp::Any BehaviorsParser::StateSelectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStateSelector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::StateSelectorContext* BehaviorsParser::stateSelector() {
  StateSelectorContext *_localctx = _tracker.createInstance<StateSelectorContext>(_ctx, getState());
  enterRule(_localctx, 6, BehaviorsParser::RuleStateSelector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorsParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(58);
        idRatioSelector();
        break;
      }

      case BehaviorsParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(59);
        randomIdRatioSelector();
        break;
      }

      case BehaviorsParser::T__9: {
        enterOuterAlt(_localctx, 3);
        setState(60);
        everyoneSelector();
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

//----------------- IdRatioSelectorContext ------------------------------------------------------------------

BehaviorsParser::IdRatioSelectorContext::IdRatioSelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::IdRatioSelectorContext::NUMBER() {
  return getToken(BehaviorsParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorsParser::IdRatioSelectorContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}


size_t BehaviorsParser::IdRatioSelectorContext::getRuleIndex() const {
  return BehaviorsParser::RuleIdRatioSelector;
}


antlrcpp::Any BehaviorsParser::IdRatioSelectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitIdRatioSelector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::IdRatioSelectorContext* BehaviorsParser::idRatioSelector() {
  IdRatioSelectorContext *_localctx = _tracker.createInstance<IdRatioSelectorContext>(_ctx, getState());
  enterRule(_localctx, 8, BehaviorsParser::RuleIdRatioSelector);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(BehaviorsParser::NUMBER);
    setState(64);
    match(BehaviorsParser::T__4);
    setState(65);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(66);
    match(BehaviorsParser::ID);
    setState(67);
    match(BehaviorsParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RandomIdRatioStatementContext ------------------------------------------------------------------

BehaviorsParser::RandomIdRatioStatementContext::RandomIdRatioStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorsParser::RandomIdRatioStatementContext::NUMBER() {
  return getTokens(BehaviorsParser::NUMBER);
}

tree::TerminalNode* BehaviorsParser::RandomIdRatioStatementContext::NUMBER(size_t i) {
  return getToken(BehaviorsParser::NUMBER, i);
}

tree::TerminalNode* BehaviorsParser::RandomIdRatioStatementContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}


size_t BehaviorsParser::RandomIdRatioStatementContext::getRuleIndex() const {
  return BehaviorsParser::RuleRandomIdRatioStatement;
}


antlrcpp::Any BehaviorsParser::RandomIdRatioStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitRandomIdRatioStatement(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::RandomIdRatioStatementContext* BehaviorsParser::randomIdRatioStatement() {
  RandomIdRatioStatementContext *_localctx = _tracker.createInstance<RandomIdRatioStatementContext>(_ctx, getState());
  enterRule(_localctx, 10, BehaviorsParser::RuleRandomIdRatioStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    match(BehaviorsParser::T__5);
    setState(70);
    match(BehaviorsParser::NUMBER);
    setState(71);
    match(BehaviorsParser::T__6);
    setState(72);
    match(BehaviorsParser::NUMBER);
    setState(73);
    match(BehaviorsParser::T__7);
    setState(74);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(75);
    match(BehaviorsParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RandomIdRatioSelectorContext ------------------------------------------------------------------

BehaviorsParser::RandomIdRatioSelectorContext::RandomIdRatioSelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorsParser::RandomIdRatioSelectorContext::getRuleIndex() const {
  return BehaviorsParser::RuleRandomIdRatioSelector;
}

void BehaviorsParser::RandomIdRatioSelectorContext::copyFrom(RandomIdRatioSelectorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NoGroupRandomIdSelectorContext ------------------------------------------------------------------

BehaviorsParser::RandomIdRatioStatementContext* BehaviorsParser::NoGroupRandomIdSelectorContext::randomIdRatioStatement() {
  return getRuleContext<BehaviorsParser::RandomIdRatioStatementContext>(0);
}

BehaviorsParser::NoGroupRandomIdSelectorContext::NoGroupRandomIdSelectorContext(RandomIdRatioSelectorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BehaviorsParser::NoGroupRandomIdSelectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitNoGroupRandomIdSelector(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GroupingRandomIdSelectorContext ------------------------------------------------------------------

BehaviorsParser::RandomIdRatioStatementContext* BehaviorsParser::GroupingRandomIdSelectorContext::randomIdRatioStatement() {
  return getRuleContext<BehaviorsParser::RandomIdRatioStatementContext>(0);
}

tree::TerminalNode* BehaviorsParser::GroupingRandomIdSelectorContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}

BehaviorsParser::GroupingRandomIdSelectorContext::GroupingRandomIdSelectorContext(RandomIdRatioSelectorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BehaviorsParser::GroupingRandomIdSelectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitGroupingRandomIdSelector(this);
  else
    return visitor->visitChildren(this);
}
BehaviorsParser::RandomIdRatioSelectorContext* BehaviorsParser::randomIdRatioSelector() {
  RandomIdRatioSelectorContext *_localctx = _tracker.createInstance<RandomIdRatioSelectorContext>(_ctx, getState());
  enterRule(_localctx, 12, BehaviorsParser::RuleRandomIdRatioSelector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(85);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<BehaviorsParser::NoGroupRandomIdSelectorContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(77);
      randomIdRatioStatement();
      setState(78);
      match(BehaviorsParser::T__3);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<BehaviorsParser::GroupingRandomIdSelectorContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(80);
      randomIdRatioStatement();
      setState(81);
      match(BehaviorsParser::T__8);
      setState(82);
      match(BehaviorsParser::ID);
      setState(83);
      match(BehaviorsParser::T__3);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EveryoneSelectorContext ------------------------------------------------------------------

BehaviorsParser::EveryoneSelectorContext::EveryoneSelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::EveryoneSelectorContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}


size_t BehaviorsParser::EveryoneSelectorContext::getRuleIndex() const {
  return BehaviorsParser::RuleEveryoneSelector;
}


antlrcpp::Any BehaviorsParser::EveryoneSelectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitEveryoneSelector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::EveryoneSelectorContext* BehaviorsParser::everyoneSelector() {
  EveryoneSelectorContext *_localctx = _tracker.createInstance<EveryoneSelectorContext>(_ctx, getState());
  enterRule(_localctx, 14, BehaviorsParser::RuleEveryoneSelector);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(BehaviorsParser::T__9);
    setState(88);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(89);
    match(BehaviorsParser::ID);
    setState(90);
    match(BehaviorsParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnvironmentStateDeclarationContext ------------------------------------------------------------------

BehaviorsParser::EnvironmentStateDeclarationContext::EnvironmentStateDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::EnvironmentStateDeclarationContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}


size_t BehaviorsParser::EnvironmentStateDeclarationContext::getRuleIndex() const {
  return BehaviorsParser::RuleEnvironmentStateDeclaration;
}


antlrcpp::Any BehaviorsParser::EnvironmentStateDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitEnvironmentStateDeclaration(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::EnvironmentStateDeclarationContext* BehaviorsParser::environmentStateDeclaration() {
  EnvironmentStateDeclarationContext *_localctx = _tracker.createInstance<EnvironmentStateDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 16, BehaviorsParser::RuleEnvironmentStateDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(BehaviorsParser::T__10);
    setState(93);
    match(BehaviorsParser::ID);
    setState(94);
    match(BehaviorsParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateDeclarationContext ------------------------------------------------------------------

BehaviorsParser::StateDeclarationContext::StateDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorsParser::StateDeclarationContext::ID() {
  return getTokens(BehaviorsParser::ID);
}

tree::TerminalNode* BehaviorsParser::StateDeclarationContext::ID(size_t i) {
  return getToken(BehaviorsParser::ID, i);
}


size_t BehaviorsParser::StateDeclarationContext::getRuleIndex() const {
  return BehaviorsParser::RuleStateDeclaration;
}


antlrcpp::Any BehaviorsParser::StateDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStateDeclaration(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::StateDeclarationContext* BehaviorsParser::stateDeclaration() {
  StateDeclarationContext *_localctx = _tracker.createInstance<StateDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 18, BehaviorsParser::RuleStateDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__11

    || _la == BehaviorsParser::T__12)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(97);
    match(BehaviorsParser::ID);
    setState(98);
    match(BehaviorsParser::T__13);
    setState(99);
    match(BehaviorsParser::ID);
    setState(100);
    match(BehaviorsParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PedestrianSelectedContext ------------------------------------------------------------------

BehaviorsParser::PedestrianSelectedContext::PedestrianSelectedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorsParser::PedestrianSelectedContext::ID() {
  return getTokens(BehaviorsParser::ID);
}

tree::TerminalNode* BehaviorsParser::PedestrianSelectedContext::ID(size_t i) {
  return getToken(BehaviorsParser::ID, i);
}


size_t BehaviorsParser::PedestrianSelectedContext::getRuleIndex() const {
  return BehaviorsParser::RulePedestrianSelected;
}


antlrcpp::Any BehaviorsParser::PedestrianSelectedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitPedestrianSelected(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::PedestrianSelectedContext* BehaviorsParser::pedestrianSelected() {
  PedestrianSelectedContext *_localctx = _tracker.createInstance<PedestrianSelectedContext>(_ctx, getState());
  enterRule(_localctx, 20, BehaviorsParser::RulePedestrianSelected);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__11

    || _la == BehaviorsParser::T__12)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(103);
    match(BehaviorsParser::ID);
    setState(104);
    match(BehaviorsParser::T__14);
    setState(105);
    match(BehaviorsParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateConditionContext ------------------------------------------------------------------

BehaviorsParser::StateConditionContext::StateConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::StateConditionContext::NUMBER() {
  return getToken(BehaviorsParser::NUMBER, 0);
}


size_t BehaviorsParser::StateConditionContext::getRuleIndex() const {
  return BehaviorsParser::RuleStateCondition;
}


antlrcpp::Any BehaviorsParser::StateConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStateCondition(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::StateConditionContext* BehaviorsParser::stateCondition() {
  StateConditionContext *_localctx = _tracker.createInstance<StateConditionContext>(_ctx, getState());
  enterRule(_localctx, 22, BehaviorsParser::RuleStateCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(BehaviorsParser::T__15);
    setState(108);
    match(BehaviorsParser::NUMBER);
    setState(109);
    match(BehaviorsParser::T__16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateTransitionContext ------------------------------------------------------------------

BehaviorsParser::StateTransitionContext::StateTransitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorsParser::PedestrianSelectedContext* BehaviorsParser::StateTransitionContext::pedestrianSelected() {
  return getRuleContext<BehaviorsParser::PedestrianSelectedContext>(0);
}

tree::TerminalNode* BehaviorsParser::StateTransitionContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}

BehaviorsParser::StateConditionContext* BehaviorsParser::StateTransitionContext::stateCondition() {
  return getRuleContext<BehaviorsParser::StateConditionContext>(0);
}


size_t BehaviorsParser::StateTransitionContext::getRuleIndex() const {
  return BehaviorsParser::RuleStateTransition;
}


antlrcpp::Any BehaviorsParser::StateTransitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStateTransition(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::StateTransitionContext* BehaviorsParser::stateTransition() {
  StateTransitionContext *_localctx = _tracker.createInstance<StateTransitionContext>(_ctx, getState());
  enterRule(_localctx, 24, BehaviorsParser::RuleStateTransition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    pedestrianSelected();
    setState(112);
    match(BehaviorsParser::T__17);
    setState(113);
    match(BehaviorsParser::ID);
    setState(114);
    stateCondition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FasterOrSlowerContext ------------------------------------------------------------------

BehaviorsParser::FasterOrSlowerContext::FasterOrSlowerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorsParser::FasterOrSlowerContext::getRuleIndex() const {
  return BehaviorsParser::RuleFasterOrSlower;
}


antlrcpp::Any BehaviorsParser::FasterOrSlowerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitFasterOrSlower(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::FasterOrSlowerContext* BehaviorsParser::fasterOrSlower() {
  FasterOrSlowerContext *_localctx = _tracker.createInstance<FasterOrSlowerContext>(_ctx, getState());
  enterRule(_localctx, 26, BehaviorsParser::RuleFasterOrSlower);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__18

    || _la == BehaviorsParser::T__19)) {
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

//----------------- TowardOrAwayFromContext ------------------------------------------------------------------

BehaviorsParser::TowardOrAwayFromContext::TowardOrAwayFromContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorsParser::TowardOrAwayFromContext::getRuleIndex() const {
  return BehaviorsParser::RuleTowardOrAwayFrom;
}


antlrcpp::Any BehaviorsParser::TowardOrAwayFromContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitTowardOrAwayFrom(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::TowardOrAwayFromContext* BehaviorsParser::towardOrAwayFrom() {
  TowardOrAwayFromContext *_localctx = _tracker.createInstance<TowardOrAwayFromContext>(_ctx, getState());
  enterRule(_localctx, 28, BehaviorsParser::RuleTowardOrAwayFrom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__20

    || _la == BehaviorsParser::T__21)) {
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

//----------------- TargetContext ------------------------------------------------------------------

BehaviorsParser::TargetContext::TargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorsParser::TargetContext::getRuleIndex() const {
  return BehaviorsParser::RuleTarget;
}


antlrcpp::Any BehaviorsParser::TargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitTarget(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::TargetContext* BehaviorsParser::target() {
  TargetContext *_localctx = _tracker.createInstance<TargetContext>(_ctx, getState());
  enterRule(_localctx, 30, BehaviorsParser::RuleTarget);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__22

    || _la == BehaviorsParser::T__23)) {
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

//----------------- StoppedBehaviorContext ------------------------------------------------------------------

BehaviorsParser::StoppedBehaviorContext::StoppedBehaviorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorsParser::StoppedBehaviorContext::getRuleIndex() const {
  return BehaviorsParser::RuleStoppedBehavior;
}


antlrcpp::Any BehaviorsParser::StoppedBehaviorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStoppedBehavior(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::StoppedBehaviorContext* BehaviorsParser::stoppedBehavior() {
  StoppedBehaviorContext *_localctx = _tracker.createInstance<StoppedBehaviorContext>(_ctx, getState());
  enterRule(_localctx, 32, BehaviorsParser::RuleStoppedBehavior);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(BehaviorsParser::T__24);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WalkSpeedBehaviorContext ------------------------------------------------------------------

BehaviorsParser::WalkSpeedBehaviorContext::WalkSpeedBehaviorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::WalkSpeedBehaviorContext::NUMBER() {
  return getToken(BehaviorsParser::NUMBER, 0);
}

BehaviorsParser::FasterOrSlowerContext* BehaviorsParser::WalkSpeedBehaviorContext::fasterOrSlower() {
  return getRuleContext<BehaviorsParser::FasterOrSlowerContext>(0);
}

BehaviorsParser::TowardOrAwayFromContext* BehaviorsParser::WalkSpeedBehaviorContext::towardOrAwayFrom() {
  return getRuleContext<BehaviorsParser::TowardOrAwayFromContext>(0);
}

BehaviorsParser::TargetContext* BehaviorsParser::WalkSpeedBehaviorContext::target() {
  return getRuleContext<BehaviorsParser::TargetContext>(0);
}


size_t BehaviorsParser::WalkSpeedBehaviorContext::getRuleIndex() const {
  return BehaviorsParser::RuleWalkSpeedBehavior;
}


antlrcpp::Any BehaviorsParser::WalkSpeedBehaviorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitWalkSpeedBehavior(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::WalkSpeedBehaviorContext* BehaviorsParser::walkSpeedBehavior() {
  WalkSpeedBehaviorContext *_localctx = _tracker.createInstance<WalkSpeedBehaviorContext>(_ctx, getState());
  enterRule(_localctx, 34, BehaviorsParser::RuleWalkSpeedBehavior);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(BehaviorsParser::T__25);
    setState(125);
    match(BehaviorsParser::NUMBER);
    setState(126);
    match(BehaviorsParser::T__26);
    setState(127);
    fasterOrSlower();
    setState(128);
    match(BehaviorsParser::T__27);
    setState(129);
    towardOrAwayFrom();
    setState(130);
    match(BehaviorsParser::T__27);
    setState(131);
    target();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NormalBehaviorContext ------------------------------------------------------------------

BehaviorsParser::NormalBehaviorContext::NormalBehaviorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorsParser::NormalBehaviorContext::getRuleIndex() const {
  return BehaviorsParser::RuleNormalBehavior;
}


antlrcpp::Any BehaviorsParser::NormalBehaviorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitNormalBehavior(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::NormalBehaviorContext* BehaviorsParser::normalBehavior() {
  NormalBehaviorContext *_localctx = _tracker.createInstance<NormalBehaviorContext>(_ctx, getState());
  enterRule(_localctx, 36, BehaviorsParser::RuleNormalBehavior);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(BehaviorsParser::T__28);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateActionContext ------------------------------------------------------------------

BehaviorsParser::StateActionContext::StateActionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorsParser::StateActionContext::getRuleIndex() const {
  return BehaviorsParser::RuleStateAction;
}

void BehaviorsParser::StateActionContext::copyFrom(StateActionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StateActionStoppedContext ------------------------------------------------------------------

BehaviorsParser::PedestrianSelectedContext* BehaviorsParser::StateActionStoppedContext::pedestrianSelected() {
  return getRuleContext<BehaviorsParser::PedestrianSelectedContext>(0);
}

BehaviorsParser::StoppedBehaviorContext* BehaviorsParser::StateActionStoppedContext::stoppedBehavior() {
  return getRuleContext<BehaviorsParser::StoppedBehaviorContext>(0);
}

BehaviorsParser::StateActionStoppedContext::StateActionStoppedContext(StateActionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BehaviorsParser::StateActionStoppedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStateActionStopped(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StateActionNormalContext ------------------------------------------------------------------

BehaviorsParser::PedestrianSelectedContext* BehaviorsParser::StateActionNormalContext::pedestrianSelected() {
  return getRuleContext<BehaviorsParser::PedestrianSelectedContext>(0);
}

BehaviorsParser::NormalBehaviorContext* BehaviorsParser::StateActionNormalContext::normalBehavior() {
  return getRuleContext<BehaviorsParser::NormalBehaviorContext>(0);
}

BehaviorsParser::StateActionNormalContext::StateActionNormalContext(StateActionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BehaviorsParser::StateActionNormalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStateActionNormal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StateActionWalkSpeedContext ------------------------------------------------------------------

BehaviorsParser::PedestrianSelectedContext* BehaviorsParser::StateActionWalkSpeedContext::pedestrianSelected() {
  return getRuleContext<BehaviorsParser::PedestrianSelectedContext>(0);
}

BehaviorsParser::WalkSpeedBehaviorContext* BehaviorsParser::StateActionWalkSpeedContext::walkSpeedBehavior() {
  return getRuleContext<BehaviorsParser::WalkSpeedBehaviorContext>(0);
}

BehaviorsParser::StateActionWalkSpeedContext::StateActionWalkSpeedContext(StateActionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BehaviorsParser::StateActionWalkSpeedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStateActionWalkSpeed(this);
  else
    return visitor->visitChildren(this);
}
BehaviorsParser::StateActionContext* BehaviorsParser::stateAction() {
  StateActionContext *_localctx = _tracker.createInstance<StateActionContext>(_ctx, getState());
  enterRule(_localctx, 38, BehaviorsParser::RuleStateAction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(147);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<BehaviorsParser::StateActionStoppedContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(135);
      pedestrianSelected();
      setState(136);
      stoppedBehavior();
      setState(137);
      match(BehaviorsParser::T__3);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<BehaviorsParser::StateActionWalkSpeedContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(139);
      pedestrianSelected();
      setState(140);
      walkSpeedBehavior();
      setState(141);
      match(BehaviorsParser::T__3);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<BehaviorsParser::StateActionNormalContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(143);
      pedestrianSelected();
      setState(144);
      normalBehavior();
      setState(145);
      match(BehaviorsParser::T__3);
      break;
    }

    default:
      break;
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
std::vector<dfa::DFA> BehaviorsParser::_decisionToDFA;
atn::PredictionContextCache BehaviorsParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN BehaviorsParser::_atn;
std::vector<uint16_t> BehaviorsParser::_serializedATN;

std::vector<std::string> BehaviorsParser::_ruleNames = {
  "program", "statement", "consideration", "stateSelector", "idRatioSelector", 
  "randomIdRatioStatement", "randomIdRatioSelector", "everyoneSelector", 
  "environmentStateDeclaration", "stateDeclaration", "pedestrianSelected", 
  "stateCondition", "stateTransition", "fasterOrSlower", "towardOrAwayFrom", 
  "target", "stoppedBehavior", "walkSpeedBehavior", "normalBehavior", "stateAction"
};

std::vector<std::string> BehaviorsParser::_literalNames = {
  "", "'Consider '", "'a '", "'an '", "'.'", "'% of the population are '", 
  "'A random '", "' out of every '", "' pedestrians is '", "', forming a '", 
  "'Everyone is '", "'The environment can be '", "'A '", "'An '", "' can be '", 
  "' who is '", "' after '", "' seconds.'", "' will be '", "'faster'", "'slower'", 
  "'toward'", "'away from'", "'their group'", "'their goal'", "' is STOPPED'", 
  "' will walk '", "'% '", "' '", "' will behave normally'"
};

std::vector<std::string> BehaviorsParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "ID", "NUMBER", "COMMENT", 
  "LINE_COMMENT", "WHITESPACE"
};

dfa::Vocabulary BehaviorsParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> BehaviorsParser::_tokenNames;

BehaviorsParser::Initializer::Initializer() {
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x24, 0x98, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x3, 0x2, 0x6, 0x2, 0x2c, 0xa, 0x2, 
       0xd, 0x2, 0xe, 0x2, 0x2d, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x36, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
       0x5, 0x40, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x58, 0xa, 
       0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
       0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x96, 0xa, 
       0x15, 0x3, 0x15, 0x2, 0x2, 0x16, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
       0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
       0x26, 0x28, 0x2, 0x7, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 0xe, 0xf, 0x3, 
       0x2, 0x15, 0x16, 0x3, 0x2, 0x17, 0x18, 0x3, 0x2, 0x19, 0x1a, 0x2, 
       0x8e, 0x2, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x35, 0x3, 0x2, 0x2, 0x2, 
       0x6, 0x37, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3f, 0x3, 0x2, 0x2, 0x2, 0xa, 
       0x41, 0x3, 0x2, 0x2, 0x2, 0xc, 0x47, 0x3, 0x2, 0x2, 0x2, 0xe, 0x57, 
       0x3, 0x2, 0x2, 0x2, 0x10, 0x59, 0x3, 0x2, 0x2, 0x2, 0x12, 0x5e, 0x3, 
       0x2, 0x2, 0x2, 0x14, 0x62, 0x3, 0x2, 0x2, 0x2, 0x16, 0x68, 0x3, 0x2, 
       0x2, 0x2, 0x18, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x71, 0x3, 0x2, 0x2, 
       0x2, 0x1c, 0x76, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x78, 0x3, 0x2, 0x2, 0x2, 
       0x20, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x22, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x24, 
       0x7e, 0x3, 0x2, 0x2, 0x2, 0x26, 0x87, 0x3, 0x2, 0x2, 0x2, 0x28, 0x95, 
       0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x5, 0x4, 0x3, 0x2, 0x2b, 0x2a, 0x3, 
       0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 
       0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x3, 0x3, 0x2, 0x2, 
       0x2, 0x2f, 0x36, 0x5, 0x6, 0x4, 0x2, 0x30, 0x36, 0x5, 0x8, 0x5, 0x2, 
       0x31, 0x36, 0x5, 0x14, 0xb, 0x2, 0x32, 0x36, 0x5, 0x12, 0xa, 0x2, 
       0x33, 0x36, 0x5, 0x1a, 0xe, 0x2, 0x34, 0x36, 0x5, 0x28, 0x15, 0x2, 
       0x35, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x35, 0x30, 0x3, 0x2, 0x2, 0x2, 0x35, 
       0x31, 0x3, 0x2, 0x2, 0x2, 0x35, 0x32, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 
       0x3, 0x2, 0x2, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x5, 0x3, 
       0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0x3, 0x2, 0x2, 0x38, 0x39, 0x9, 0x2, 
       0x2, 0x2, 0x39, 0x3a, 0x7, 0x20, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x6, 
       0x2, 0x2, 0x3b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x40, 0x5, 0xa, 0x6, 
       0x2, 0x3d, 0x40, 0x5, 0xe, 0x8, 0x2, 0x3e, 0x40, 0x5, 0x10, 0x9, 
       0x2, 0x3f, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 
       0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x9, 0x3, 0x2, 0x2, 0x2, 0x41, 
       0x42, 0x7, 0x21, 0x2, 0x2, 0x42, 0x43, 0x7, 0x7, 0x2, 0x2, 0x43, 
       0x44, 0x9, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x20, 0x2, 0x2, 0x45, 
       0x46, 0x7, 0x6, 0x2, 0x2, 0x46, 0xb, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 
       0x7, 0x8, 0x2, 0x2, 0x48, 0x49, 0x7, 0x21, 0x2, 0x2, 0x49, 0x4a, 
       0x7, 0x9, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x21, 0x2, 0x2, 0x4b, 0x4c, 
       0x7, 0xa, 0x2, 0x2, 0x4c, 0x4d, 0x9, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 
       0x20, 0x2, 0x2, 0x4e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x5, 0xc, 
       0x7, 0x2, 0x50, 0x51, 0x7, 0x6, 0x2, 0x2, 0x51, 0x58, 0x3, 0x2, 0x2, 
       0x2, 0x52, 0x53, 0x5, 0xc, 0x7, 0x2, 0x53, 0x54, 0x7, 0xb, 0x2, 0x2, 
       0x54, 0x55, 0x7, 0x20, 0x2, 0x2, 0x55, 0x56, 0x7, 0x6, 0x2, 0x2, 
       0x56, 0x58, 0x3, 0x2, 0x2, 0x2, 0x57, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x57, 
       0x52, 0x3, 0x2, 0x2, 0x2, 0x58, 0xf, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 
       0x7, 0xc, 0x2, 0x2, 0x5a, 0x5b, 0x9, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x7, 
       0x20, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x6, 0x2, 0x2, 0x5d, 0x11, 0x3, 
       0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0xd, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x20, 
       0x2, 0x2, 0x60, 0x61, 0x7, 0x6, 0x2, 0x2, 0x61, 0x13, 0x3, 0x2, 0x2, 
       0x2, 0x62, 0x63, 0x9, 0x3, 0x2, 0x2, 0x63, 0x64, 0x7, 0x20, 0x2, 
       0x2, 0x64, 0x65, 0x7, 0x10, 0x2, 0x2, 0x65, 0x66, 0x7, 0x20, 0x2, 
       0x2, 0x66, 0x67, 0x7, 0x6, 0x2, 0x2, 0x67, 0x15, 0x3, 0x2, 0x2, 0x2, 
       0x68, 0x69, 0x9, 0x3, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x20, 0x2, 0x2, 
       0x6a, 0x6b, 0x7, 0x11, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x20, 0x2, 0x2, 
       0x6c, 0x17, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x12, 0x2, 0x2, 
       0x6e, 0x6f, 0x7, 0x21, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x13, 0x2, 0x2, 
       0x70, 0x19, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x5, 0x16, 0xc, 0x2, 
       0x72, 0x73, 0x7, 0x14, 0x2, 0x2, 0x73, 0x74, 0x7, 0x20, 0x2, 0x2, 
       0x74, 0x75, 0x5, 0x18, 0xd, 0x2, 0x75, 0x1b, 0x3, 0x2, 0x2, 0x2, 
       0x76, 0x77, 0x9, 0x4, 0x2, 0x2, 0x77, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x78, 
       0x79, 0x9, 0x5, 0x2, 0x2, 0x79, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 
       0x9, 0x6, 0x2, 0x2, 0x7b, 0x21, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 
       0x1b, 0x2, 0x2, 0x7d, 0x23, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 
       0x1c, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x21, 0x2, 0x2, 0x80, 0x81, 0x7, 
       0x1d, 0x2, 0x2, 0x81, 0x82, 0x5, 0x1c, 0xf, 0x2, 0x82, 0x83, 0x7, 
       0x1e, 0x2, 0x2, 0x83, 0x84, 0x5, 0x1e, 0x10, 0x2, 0x84, 0x85, 0x7, 
       0x1e, 0x2, 0x2, 0x85, 0x86, 0x5, 0x20, 0x11, 0x2, 0x86, 0x25, 0x3, 
       0x2, 0x2, 0x2, 0x87, 0x88, 0x7, 0x1f, 0x2, 0x2, 0x88, 0x27, 0x3, 
       0x2, 0x2, 0x2, 0x89, 0x8a, 0x5, 0x16, 0xc, 0x2, 0x8a, 0x8b, 0x5, 
       0x22, 0x12, 0x2, 0x8b, 0x8c, 0x7, 0x6, 0x2, 0x2, 0x8c, 0x96, 0x3, 
       0x2, 0x2, 0x2, 0x8d, 0x8e, 0x5, 0x16, 0xc, 0x2, 0x8e, 0x8f, 0x5, 
       0x24, 0x13, 0x2, 0x8f, 0x90, 0x7, 0x6, 0x2, 0x2, 0x90, 0x96, 0x3, 
       0x2, 0x2, 0x2, 0x91, 0x92, 0x5, 0x16, 0xc, 0x2, 0x92, 0x93, 0x5, 
       0x26, 0x14, 0x2, 0x93, 0x94, 0x7, 0x6, 0x2, 0x2, 0x94, 0x96, 0x3, 
       0x2, 0x2, 0x2, 0x95, 0x89, 0x3, 0x2, 0x2, 0x2, 0x95, 0x8d, 0x3, 0x2, 
       0x2, 0x2, 0x95, 0x91, 0x3, 0x2, 0x2, 0x2, 0x96, 0x29, 0x3, 0x2, 0x2, 
       0x2, 0x7, 0x2d, 0x35, 0x3f, 0x57, 0x95, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

BehaviorsParser::Initializer BehaviorsParser::_init;
