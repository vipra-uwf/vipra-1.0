
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
    setState(53); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(52);
      statement();
      setState(55); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BehaviorsParser::T__0)
      | (1ULL << BehaviorsParser::T__5)
      | (1ULL << BehaviorsParser::T__14)
      | (1ULL << BehaviorsParser::T__15)
      | (1ULL << BehaviorsParser::T__16)
      | (1ULL << BehaviorsParser::T__17)
      | (1ULL << BehaviorsParser::T__19)
      | (1ULL << BehaviorsParser::T__20)
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

BehaviorsParser::InitialStateDeclarationContext* BehaviorsParser::StatementContext::initialStateDeclaration() {
  return getRuleContext<BehaviorsParser::InitialStateDeclarationContext>(0);
}

BehaviorsParser::EnvironmentStateDeclarationContext* BehaviorsParser::StatementContext::environmentStateDeclaration() {
  return getRuleContext<BehaviorsParser::EnvironmentStateDeclarationContext>(0);
}

BehaviorsParser::EnvironmentInitialStateDeclarationContext* BehaviorsParser::StatementContext::environmentInitialStateDeclaration() {
  return getRuleContext<BehaviorsParser::EnvironmentInitialStateDeclarationContext>(0);
}

BehaviorsParser::EnvironmentTransitionContext* BehaviorsParser::StatementContext::environmentTransition() {
  return getRuleContext<BehaviorsParser::EnvironmentTransitionContext>(0);
}

BehaviorsParser::StateTransitionElapsedTimeContext* BehaviorsParser::StatementContext::stateTransitionElapsedTime() {
  return getRuleContext<BehaviorsParser::StateTransitionElapsedTimeContext>(0);
}

BehaviorsParser::StateTransitionEnvironmentStateContext* BehaviorsParser::StatementContext::stateTransitionEnvironmentState() {
  return getRuleContext<BehaviorsParser::StateTransitionEnvironmentStateContext>(0);
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
    setState(67);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(57);
      consideration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(58);
      stateSelector();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(59);
      stateDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(60);
      initialStateDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(61);
      environmentStateDeclaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(62);
      environmentInitialStateDeclaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(63);
      environmentTransition();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(64);
      stateTransitionElapsedTime();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(65);
      stateTransitionEnvironmentState();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(66);
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
    setState(69);
    match(BehaviorsParser::T__0);
    setState(70);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(71);
    match(BehaviorsParser::ID);
    setState(72);
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
    setState(77);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorsParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(74);
        idRatioSelector();
        break;
      }

      case BehaviorsParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(75);
        randomIdRatioSelector();
        break;
      }

      case BehaviorsParser::T__14: {
        enterOuterAlt(_localctx, 3);
        setState(76);
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
    setState(79);
    match(BehaviorsParser::NUMBER);
    setState(80);
    match(BehaviorsParser::T__4);
    setState(81);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(82);
    match(BehaviorsParser::ID);
    setState(83);
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
    setState(85);
    match(BehaviorsParser::T__5);
    setState(86);
    match(BehaviorsParser::NUMBER);
    setState(87);
    match(BehaviorsParser::T__6);
    setState(88);
    match(BehaviorsParser::NUMBER);
    setState(89);
    match(BehaviorsParser::T__7);
    setState(90);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(91);
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
    setState(101);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<BehaviorsParser::NoGroupRandomIdSelectorContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(93);
      randomIdRatioStatement();
      setState(94);
      match(BehaviorsParser::T__3);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<BehaviorsParser::GroupingRandomIdSelectorContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(96);
      randomIdRatioStatement();
      setState(97);
      match(BehaviorsParser::T__8);
      setState(98);
      match(BehaviorsParser::ID);
      setState(99);
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

//----------------- ConditionElapsedTimeContext ------------------------------------------------------------------

BehaviorsParser::ConditionElapsedTimeContext::ConditionElapsedTimeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::ConditionElapsedTimeContext::NUMBER() {
  return getToken(BehaviorsParser::NUMBER, 0);
}


size_t BehaviorsParser::ConditionElapsedTimeContext::getRuleIndex() const {
  return BehaviorsParser::RuleConditionElapsedTime;
}


antlrcpp::Any BehaviorsParser::ConditionElapsedTimeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitConditionElapsedTime(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::ConditionElapsedTimeContext* BehaviorsParser::conditionElapsedTime() {
  ConditionElapsedTimeContext *_localctx = _tracker.createInstance<ConditionElapsedTimeContext>(_ctx, getState());
  enterRule(_localctx, 14, BehaviorsParser::RuleConditionElapsedTime);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(BehaviorsParser::T__9);
    setState(104);
    match(BehaviorsParser::NUMBER);
    setState(105);
    match(BehaviorsParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionEnvironmentStateContext ------------------------------------------------------------------

BehaviorsParser::ConditionEnvironmentStateContext::ConditionEnvironmentStateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::ConditionEnvironmentStateContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}


size_t BehaviorsParser::ConditionEnvironmentStateContext::getRuleIndex() const {
  return BehaviorsParser::RuleConditionEnvironmentState;
}


antlrcpp::Any BehaviorsParser::ConditionEnvironmentStateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitConditionEnvironmentState(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::ConditionEnvironmentStateContext* BehaviorsParser::conditionEnvironmentState() {
  ConditionEnvironmentStateContext *_localctx = _tracker.createInstance<ConditionEnvironmentStateContext>(_ctx, getState());
  enterRule(_localctx, 16, BehaviorsParser::RuleConditionEnvironmentState);
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
    setState(107);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__11

    || _la == BehaviorsParser::T__12)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(108);
    match(BehaviorsParser::T__13);
    setState(109);
    match(BehaviorsParser::ID);
    setState(110);
    match(BehaviorsParser::T__3);
   
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
  enterRule(_localctx, 18, BehaviorsParser::RuleEveryoneSelector);
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
    setState(112);
    match(BehaviorsParser::T__14);
    setState(113);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(114);
    match(BehaviorsParser::ID);
    setState(115);
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
  enterRule(_localctx, 20, BehaviorsParser::RuleEnvironmentStateDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(BehaviorsParser::T__15);
    setState(118);
    match(BehaviorsParser::ID);
    setState(119);
    match(BehaviorsParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnvironmentInitialStateDeclarationContext ------------------------------------------------------------------

BehaviorsParser::EnvironmentInitialStateDeclarationContext::EnvironmentInitialStateDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::EnvironmentInitialStateDeclarationContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}


size_t BehaviorsParser::EnvironmentInitialStateDeclarationContext::getRuleIndex() const {
  return BehaviorsParser::RuleEnvironmentInitialStateDeclaration;
}


antlrcpp::Any BehaviorsParser::EnvironmentInitialStateDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitEnvironmentInitialStateDeclaration(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::EnvironmentInitialStateDeclarationContext* BehaviorsParser::environmentInitialStateDeclaration() {
  EnvironmentInitialStateDeclarationContext *_localctx = _tracker.createInstance<EnvironmentInitialStateDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 22, BehaviorsParser::RuleEnvironmentInitialStateDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(BehaviorsParser::T__16);
    setState(122);
    match(BehaviorsParser::ID);
    setState(123);
    match(BehaviorsParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnvironmentTransitionContext ------------------------------------------------------------------

BehaviorsParser::EnvironmentTransitionContext::EnvironmentTransitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorsParser::EnvironmentTransitionContext::ID() {
  return getTokens(BehaviorsParser::ID);
}

tree::TerminalNode* BehaviorsParser::EnvironmentTransitionContext::ID(size_t i) {
  return getToken(BehaviorsParser::ID, i);
}

BehaviorsParser::ConditionElapsedTimeContext* BehaviorsParser::EnvironmentTransitionContext::conditionElapsedTime() {
  return getRuleContext<BehaviorsParser::ConditionElapsedTimeContext>(0);
}


size_t BehaviorsParser::EnvironmentTransitionContext::getRuleIndex() const {
  return BehaviorsParser::RuleEnvironmentTransition;
}


antlrcpp::Any BehaviorsParser::EnvironmentTransitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitEnvironmentTransition(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::EnvironmentTransitionContext* BehaviorsParser::environmentTransition() {
  EnvironmentTransitionContext *_localctx = _tracker.createInstance<EnvironmentTransitionContext>(_ctx, getState());
  enterRule(_localctx, 24, BehaviorsParser::RuleEnvironmentTransition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    match(BehaviorsParser::T__17);
    setState(126);
    match(BehaviorsParser::ID);
    setState(127);
    match(BehaviorsParser::T__18);
    setState(128);
    match(BehaviorsParser::ID);
    setState(129);
    conditionElapsedTime();
   
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
  enterRule(_localctx, 26, BehaviorsParser::RuleStateDeclaration);
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
    setState(131);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__19

    || _la == BehaviorsParser::T__20)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(132);
    match(BehaviorsParser::ID);
    setState(133);
    match(BehaviorsParser::T__21);
    setState(134);
    match(BehaviorsParser::ID);
    setState(135);
    match(BehaviorsParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitialStateDeclarationContext ------------------------------------------------------------------

BehaviorsParser::InitialStateDeclarationContext::InitialStateDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorsParser::InitialStateDeclarationContext::ID() {
  return getTokens(BehaviorsParser::ID);
}

tree::TerminalNode* BehaviorsParser::InitialStateDeclarationContext::ID(size_t i) {
  return getToken(BehaviorsParser::ID, i);
}


size_t BehaviorsParser::InitialStateDeclarationContext::getRuleIndex() const {
  return BehaviorsParser::RuleInitialStateDeclaration;
}


antlrcpp::Any BehaviorsParser::InitialStateDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitInitialStateDeclaration(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::InitialStateDeclarationContext* BehaviorsParser::initialStateDeclaration() {
  InitialStateDeclarationContext *_localctx = _tracker.createInstance<InitialStateDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 28, BehaviorsParser::RuleInitialStateDeclaration);
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
    setState(137);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__19

    || _la == BehaviorsParser::T__20)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(138);
    match(BehaviorsParser::ID);
    setState(139);
    match(BehaviorsParser::T__22);
    setState(140);
    match(BehaviorsParser::ID);
    setState(141);
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
  enterRule(_localctx, 30, BehaviorsParser::RulePedestrianSelected);
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
    setState(143);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__19

    || _la == BehaviorsParser::T__20)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(144);
    match(BehaviorsParser::ID);
    setState(145);
    match(BehaviorsParser::T__23);
    setState(146);
    match(BehaviorsParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateTransitionElapsedTimeContext ------------------------------------------------------------------

BehaviorsParser::StateTransitionElapsedTimeContext::StateTransitionElapsedTimeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorsParser::PedestrianSelectedContext* BehaviorsParser::StateTransitionElapsedTimeContext::pedestrianSelected() {
  return getRuleContext<BehaviorsParser::PedestrianSelectedContext>(0);
}

tree::TerminalNode* BehaviorsParser::StateTransitionElapsedTimeContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}

BehaviorsParser::ConditionElapsedTimeContext* BehaviorsParser::StateTransitionElapsedTimeContext::conditionElapsedTime() {
  return getRuleContext<BehaviorsParser::ConditionElapsedTimeContext>(0);
}


size_t BehaviorsParser::StateTransitionElapsedTimeContext::getRuleIndex() const {
  return BehaviorsParser::RuleStateTransitionElapsedTime;
}


antlrcpp::Any BehaviorsParser::StateTransitionElapsedTimeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStateTransitionElapsedTime(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::StateTransitionElapsedTimeContext* BehaviorsParser::stateTransitionElapsedTime() {
  StateTransitionElapsedTimeContext *_localctx = _tracker.createInstance<StateTransitionElapsedTimeContext>(_ctx, getState());
  enterRule(_localctx, 32, BehaviorsParser::RuleStateTransitionElapsedTime);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    pedestrianSelected();
    setState(149);
    match(BehaviorsParser::T__18);
    setState(150);
    match(BehaviorsParser::ID);
    setState(151);
    conditionElapsedTime();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateTransitionEnvironmentStateContext ------------------------------------------------------------------

BehaviorsParser::StateTransitionEnvironmentStateContext::StateTransitionEnvironmentStateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorsParser::PedestrianSelectedContext* BehaviorsParser::StateTransitionEnvironmentStateContext::pedestrianSelected() {
  return getRuleContext<BehaviorsParser::PedestrianSelectedContext>(0);
}

tree::TerminalNode* BehaviorsParser::StateTransitionEnvironmentStateContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}

BehaviorsParser::ConditionEnvironmentStateContext* BehaviorsParser::StateTransitionEnvironmentStateContext::conditionEnvironmentState() {
  return getRuleContext<BehaviorsParser::ConditionEnvironmentStateContext>(0);
}


size_t BehaviorsParser::StateTransitionEnvironmentStateContext::getRuleIndex() const {
  return BehaviorsParser::RuleStateTransitionEnvironmentState;
}


antlrcpp::Any BehaviorsParser::StateTransitionEnvironmentStateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStateTransitionEnvironmentState(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::StateTransitionEnvironmentStateContext* BehaviorsParser::stateTransitionEnvironmentState() {
  StateTransitionEnvironmentStateContext *_localctx = _tracker.createInstance<StateTransitionEnvironmentStateContext>(_ctx, getState());
  enterRule(_localctx, 34, BehaviorsParser::RuleStateTransitionEnvironmentState);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    pedestrianSelected();
    setState(154);
    match(BehaviorsParser::T__18);
    setState(155);
    match(BehaviorsParser::ID);
    setState(156);
    conditionEnvironmentState();
   
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
  enterRule(_localctx, 36, BehaviorsParser::RuleFasterOrSlower);
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
    setState(158);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__24

    || _la == BehaviorsParser::T__25)) {
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
  enterRule(_localctx, 38, BehaviorsParser::RuleTowardOrAwayFrom);
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
    setState(160);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__26

    || _la == BehaviorsParser::T__27)) {
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
  enterRule(_localctx, 40, BehaviorsParser::RuleTarget);
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
    setState(162);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__28

    || _la == BehaviorsParser::T__29)) {
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
  enterRule(_localctx, 42, BehaviorsParser::RuleStoppedBehavior);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    match(BehaviorsParser::T__30);
   
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
  enterRule(_localctx, 44, BehaviorsParser::RuleWalkSpeedBehavior);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(BehaviorsParser::T__31);
    setState(167);
    match(BehaviorsParser::NUMBER);
    setState(168);
    match(BehaviorsParser::T__32);
    setState(169);
    fasterOrSlower();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WalkSpeedWithTargetBehaviorContext ------------------------------------------------------------------

BehaviorsParser::WalkSpeedWithTargetBehaviorContext::WalkSpeedWithTargetBehaviorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::WalkSpeedWithTargetBehaviorContext::NUMBER() {
  return getToken(BehaviorsParser::NUMBER, 0);
}

BehaviorsParser::FasterOrSlowerContext* BehaviorsParser::WalkSpeedWithTargetBehaviorContext::fasterOrSlower() {
  return getRuleContext<BehaviorsParser::FasterOrSlowerContext>(0);
}

BehaviorsParser::TowardOrAwayFromContext* BehaviorsParser::WalkSpeedWithTargetBehaviorContext::towardOrAwayFrom() {
  return getRuleContext<BehaviorsParser::TowardOrAwayFromContext>(0);
}

BehaviorsParser::TargetContext* BehaviorsParser::WalkSpeedWithTargetBehaviorContext::target() {
  return getRuleContext<BehaviorsParser::TargetContext>(0);
}


size_t BehaviorsParser::WalkSpeedWithTargetBehaviorContext::getRuleIndex() const {
  return BehaviorsParser::RuleWalkSpeedWithTargetBehavior;
}


antlrcpp::Any BehaviorsParser::WalkSpeedWithTargetBehaviorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitWalkSpeedWithTargetBehavior(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::WalkSpeedWithTargetBehaviorContext* BehaviorsParser::walkSpeedWithTargetBehavior() {
  WalkSpeedWithTargetBehaviorContext *_localctx = _tracker.createInstance<WalkSpeedWithTargetBehaviorContext>(_ctx, getState());
  enterRule(_localctx, 46, BehaviorsParser::RuleWalkSpeedWithTargetBehavior);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(BehaviorsParser::T__31);
    setState(172);
    match(BehaviorsParser::NUMBER);
    setState(173);
    match(BehaviorsParser::T__32);
    setState(174);
    fasterOrSlower();
    setState(175);
    match(BehaviorsParser::T__33);
    setState(176);
    towardOrAwayFrom();
    setState(177);
    match(BehaviorsParser::T__33);
    setState(178);
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
  enterRule(_localctx, 48, BehaviorsParser::RuleNormalBehavior);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(BehaviorsParser::T__34);
   
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
//----------------- StateActionWalkSpeedWithTargetContext ------------------------------------------------------------------

BehaviorsParser::PedestrianSelectedContext* BehaviorsParser::StateActionWalkSpeedWithTargetContext::pedestrianSelected() {
  return getRuleContext<BehaviorsParser::PedestrianSelectedContext>(0);
}

BehaviorsParser::WalkSpeedWithTargetBehaviorContext* BehaviorsParser::StateActionWalkSpeedWithTargetContext::walkSpeedWithTargetBehavior() {
  return getRuleContext<BehaviorsParser::WalkSpeedWithTargetBehaviorContext>(0);
}

BehaviorsParser::StateActionWalkSpeedWithTargetContext::StateActionWalkSpeedWithTargetContext(StateActionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BehaviorsParser::StateActionWalkSpeedWithTargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStateActionWalkSpeedWithTarget(this);
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
  enterRule(_localctx, 50, BehaviorsParser::RuleStateAction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(198);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<BehaviorsParser::StateActionStoppedContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(182);
      pedestrianSelected();
      setState(183);
      stoppedBehavior();
      setState(184);
      match(BehaviorsParser::T__3);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<BehaviorsParser::StateActionWalkSpeedContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(186);
      pedestrianSelected();
      setState(187);
      walkSpeedBehavior();
      setState(188);
      match(BehaviorsParser::T__3);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<BehaviorsParser::StateActionWalkSpeedWithTargetContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(190);
      pedestrianSelected();
      setState(191);
      walkSpeedWithTargetBehavior();
      setState(192);
      match(BehaviorsParser::T__3);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<BehaviorsParser::StateActionNormalContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(194);
      pedestrianSelected();
      setState(195);
      normalBehavior();
      setState(196);
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
  "randomIdRatioStatement", "randomIdRatioSelector", "conditionElapsedTime", 
  "conditionEnvironmentState", "everyoneSelector", "environmentStateDeclaration", 
  "environmentInitialStateDeclaration", "environmentTransition", "stateDeclaration", 
  "initialStateDeclaration", "pedestrianSelected", "stateTransitionElapsedTime", 
  "stateTransitionEnvironmentState", "fasterOrSlower", "towardOrAwayFrom", 
  "target", "stoppedBehavior", "walkSpeedBehavior", "walkSpeedWithTargetBehavior", 
  "normalBehavior", "stateAction"
};

std::vector<std::string> BehaviorsParser::_literalNames = {
  "", "'Consider '", "'a '", "'an '", "'.'", "'% of the population are '", 
  "'A random '", "' out of every '", "' pedestrians is '", "', forming a '", 
  "' after '", "' seconds.'", "' if'", "' when'", "' the environment is '", 
  "'Everyone is '", "'The environment can be '", "'The environment is initially '", 
  "'The environment that is '", "' will be '", "'A '", "'An '", "' can be '", 
  "' is initially '", "' who is '", "'faster'", "'slower'", "'toward'", 
  "'away from'", "'their group'", "'their goal'", "' is STOPPED'", "' will walk '", 
  "'% '", "' '", "' will behave normally'"
};

std::vector<std::string> BehaviorsParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "ID", "NUMBER", "COMMENT", "LINE_COMMENT", "WHITESPACE"
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
       0x3, 0x2a, 0xcb, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x3, 0x2, 0x6, 0x2, 0x38, 0xa, 0x2, 
       0xd, 0x2, 0xe, 0x2, 0x39, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
       0x3, 0x46, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x50, 0xa, 0x5, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x68, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
       0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x5, 0x1b, 0xc9, 0xa, 0x1b, 0x3, 0x1b, 0x2, 0x2, 0x1c, 0x2, 
       0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
       0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
       0x32, 0x34, 0x2, 0x8, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 0xe, 0xf, 0x3, 
       0x2, 0x16, 0x17, 0x3, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x1d, 0x1e, 0x3, 
       0x2, 0x1f, 0x20, 0x2, 0xc0, 0x2, 0x37, 0x3, 0x2, 0x2, 0x2, 0x4, 0x45, 
       0x3, 0x2, 0x2, 0x2, 0x6, 0x47, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4f, 0x3, 
       0x2, 0x2, 0x2, 0xa, 0x51, 0x3, 0x2, 0x2, 0x2, 0xc, 0x57, 0x3, 0x2, 
       0x2, 0x2, 0xe, 0x67, 0x3, 0x2, 0x2, 0x2, 0x10, 0x69, 0x3, 0x2, 0x2, 
       0x2, 0x12, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x14, 0x72, 0x3, 0x2, 0x2, 0x2, 
       0x16, 0x77, 0x3, 0x2, 0x2, 0x2, 0x18, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x1a, 
       0x7f, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x85, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x8b, 
       0x3, 0x2, 0x2, 0x2, 0x20, 0x91, 0x3, 0x2, 0x2, 0x2, 0x22, 0x96, 0x3, 
       0x2, 0x2, 0x2, 0x24, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x26, 0xa0, 0x3, 0x2, 
       0x2, 0x2, 0x28, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xa4, 0x3, 0x2, 0x2, 
       0x2, 0x2c, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xa8, 0x3, 0x2, 0x2, 0x2, 
       0x30, 0xad, 0x3, 0x2, 0x2, 0x2, 0x32, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x34, 
       0xc8, 0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x5, 0x4, 0x3, 0x2, 0x37, 0x36, 
       0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 
       0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3, 0x3, 0x2, 
       0x2, 0x2, 0x3b, 0x46, 0x5, 0x6, 0x4, 0x2, 0x3c, 0x46, 0x5, 0x8, 0x5, 
       0x2, 0x3d, 0x46, 0x5, 0x1c, 0xf, 0x2, 0x3e, 0x46, 0x5, 0x1e, 0x10, 
       0x2, 0x3f, 0x46, 0x5, 0x16, 0xc, 0x2, 0x40, 0x46, 0x5, 0x18, 0xd, 
       0x2, 0x41, 0x46, 0x5, 0x1a, 0xe, 0x2, 0x42, 0x46, 0x5, 0x22, 0x12, 
       0x2, 0x43, 0x46, 0x5, 0x24, 0x13, 0x2, 0x44, 0x46, 0x5, 0x34, 0x1b, 
       0x2, 0x45, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x45, 0x3c, 0x3, 0x2, 0x2, 0x2, 
       0x45, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x45, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x45, 
       0x3f, 0x3, 0x2, 0x2, 0x2, 0x45, 0x40, 0x3, 0x2, 0x2, 0x2, 0x45, 0x41, 
       0x3, 0x2, 0x2, 0x2, 0x45, 0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 
       0x2, 0x2, 0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x5, 0x3, 0x2, 
       0x2, 0x2, 0x47, 0x48, 0x7, 0x3, 0x2, 0x2, 0x48, 0x49, 0x9, 0x2, 0x2, 
       0x2, 0x49, 0x4a, 0x7, 0x26, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x6, 0x2, 
       0x2, 0x4b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x50, 0x5, 0xa, 0x6, 0x2, 
       0x4d, 0x50, 0x5, 0xe, 0x8, 0x2, 0x4e, 0x50, 0x5, 0x14, 0xb, 0x2, 
       0x4f, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 
       0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x9, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 
       0x7, 0x27, 0x2, 0x2, 0x52, 0x53, 0x7, 0x7, 0x2, 0x2, 0x53, 0x54, 
       0x9, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 0x26, 0x2, 0x2, 0x55, 0x56, 
       0x7, 0x6, 0x2, 0x2, 0x56, 0xb, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 
       0x8, 0x2, 0x2, 0x58, 0x59, 0x7, 0x27, 0x2, 0x2, 0x59, 0x5a, 0x7, 
       0x9, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x27, 0x2, 0x2, 0x5b, 0x5c, 0x7, 
       0xa, 0x2, 0x2, 0x5c, 0x5d, 0x9, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x26, 
       0x2, 0x2, 0x5e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x5, 0xc, 0x7, 
       0x2, 0x60, 0x61, 0x7, 0x6, 0x2, 0x2, 0x61, 0x68, 0x3, 0x2, 0x2, 0x2, 
       0x62, 0x63, 0x5, 0xc, 0x7, 0x2, 0x63, 0x64, 0x7, 0xb, 0x2, 0x2, 0x64, 
       0x65, 0x7, 0x26, 0x2, 0x2, 0x65, 0x66, 0x7, 0x6, 0x2, 0x2, 0x66, 
       0x68, 0x3, 0x2, 0x2, 0x2, 0x67, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x67, 0x62, 
       0x3, 0x2, 0x2, 0x2, 0x68, 0xf, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 
       0xc, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x27, 0x2, 0x2, 0x6b, 0x6c, 0x7, 
       0xd, 0x2, 0x2, 0x6c, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x9, 0x3, 
       0x2, 0x2, 0x6e, 0x6f, 0x7, 0x10, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x26, 
       0x2, 0x2, 0x70, 0x71, 0x7, 0x6, 0x2, 0x2, 0x71, 0x13, 0x3, 0x2, 0x2, 
       0x2, 0x72, 0x73, 0x7, 0x11, 0x2, 0x2, 0x73, 0x74, 0x9, 0x2, 0x2, 
       0x2, 0x74, 0x75, 0x7, 0x26, 0x2, 0x2, 0x75, 0x76, 0x7, 0x6, 0x2, 
       0x2, 0x76, 0x15, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0x12, 0x2, 
       0x2, 0x78, 0x79, 0x7, 0x26, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x6, 0x2, 
       0x2, 0x7a, 0x17, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x13, 0x2, 
       0x2, 0x7c, 0x7d, 0x7, 0x26, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x6, 0x2, 
       0x2, 0x7e, 0x19, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x14, 0x2, 
       0x2, 0x80, 0x81, 0x7, 0x26, 0x2, 0x2, 0x81, 0x82, 0x7, 0x15, 0x2, 
       0x2, 0x82, 0x83, 0x7, 0x26, 0x2, 0x2, 0x83, 0x84, 0x5, 0x10, 0x9, 
       0x2, 0x84, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x9, 0x4, 0x2, 0x2, 
       0x86, 0x87, 0x7, 0x26, 0x2, 0x2, 0x87, 0x88, 0x7, 0x18, 0x2, 0x2, 
       0x88, 0x89, 0x7, 0x26, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x6, 0x2, 0x2, 
       0x8a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x9, 0x4, 0x2, 0x2, 0x8c, 
       0x8d, 0x7, 0x26, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x19, 0x2, 0x2, 0x8e, 
       0x8f, 0x7, 0x26, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x6, 0x2, 0x2, 0x90, 
       0x1f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x9, 0x4, 0x2, 0x2, 0x92, 0x93, 
       0x7, 0x26, 0x2, 0x2, 0x93, 0x94, 0x7, 0x1a, 0x2, 0x2, 0x94, 0x95, 
       0x7, 0x26, 0x2, 0x2, 0x95, 0x21, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 
       0x5, 0x20, 0x11, 0x2, 0x97, 0x98, 0x7, 0x15, 0x2, 0x2, 0x98, 0x99, 
       0x7, 0x26, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x10, 0x9, 0x2, 0x9a, 0x23, 
       0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x5, 0x20, 0x11, 0x2, 0x9c, 0x9d, 
       0x7, 0x15, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x26, 0x2, 0x2, 0x9e, 0x9f, 
       0x5, 0x12, 0xa, 0x2, 0x9f, 0x25, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 
       0x9, 0x5, 0x2, 0x2, 0xa1, 0x27, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x9, 
       0x6, 0x2, 0x2, 0xa3, 0x29, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x9, 0x7, 
       0x2, 0x2, 0xa5, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x21, 
       0x2, 0x2, 0xa7, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x22, 
       0x2, 0x2, 0xa9, 0xaa, 0x7, 0x27, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x23, 
       0x2, 0x2, 0xab, 0xac, 0x5, 0x26, 0x14, 0x2, 0xac, 0x2f, 0x3, 0x2, 
       0x2, 0x2, 0xad, 0xae, 0x7, 0x22, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x27, 
       0x2, 0x2, 0xaf, 0xb0, 0x7, 0x23, 0x2, 0x2, 0xb0, 0xb1, 0x5, 0x26, 
       0x14, 0x2, 0xb1, 0xb2, 0x7, 0x24, 0x2, 0x2, 0xb2, 0xb3, 0x5, 0x28, 
       0x15, 0x2, 0xb3, 0xb4, 0x7, 0x24, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x2a, 
       0x16, 0x2, 0xb5, 0x31, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x25, 
       0x2, 0x2, 0xb7, 0x33, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x5, 0x20, 
       0x11, 0x2, 0xb9, 0xba, 0x5, 0x2c, 0x17, 0x2, 0xba, 0xbb, 0x7, 0x6, 
       0x2, 0x2, 0xbb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x20, 
       0x11, 0x2, 0xbd, 0xbe, 0x5, 0x2e, 0x18, 0x2, 0xbe, 0xbf, 0x7, 0x6, 
       0x2, 0x2, 0xbf, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x5, 0x20, 
       0x11, 0x2, 0xc1, 0xc2, 0x5, 0x30, 0x19, 0x2, 0xc2, 0xc3, 0x7, 0x6, 
       0x2, 0x2, 0xc3, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x20, 
       0x11, 0x2, 0xc5, 0xc6, 0x5, 0x32, 0x1a, 0x2, 0xc6, 0xc7, 0x7, 0x6, 
       0x2, 0x2, 0xc7, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xb8, 0x3, 0x2, 0x2, 
       0x2, 0xc8, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc0, 0x3, 0x2, 0x2, 0x2, 
       0xc8, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc9, 0x35, 0x3, 0x2, 0x2, 0x2, 0x7, 
       0x39, 0x45, 0x4f, 0x67, 0xc8, 
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
