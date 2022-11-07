
// Generated from Behaviors.g4 by ANTLR 4.7.2


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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(54);
      statement();
      setState(57); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BehaviorsParser::T__0)
      | (1ULL << BehaviorsParser::T__5)
      | (1ULL << BehaviorsParser::T__7)
      | (1ULL << BehaviorsParser::T__16)
      | (1ULL << BehaviorsParser::T__17)
      | (1ULL << BehaviorsParser::T__18)
      | (1ULL << BehaviorsParser::T__19)
      | (1ULL << BehaviorsParser::T__21)
      | (1ULL << BehaviorsParser::T__22)
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(69);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(59);
      consideration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(60);
      stateSelector();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(61);
      stateDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(62);
      initialStateDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(63);
      environmentStateDeclaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(64);
      environmentInitialStateDeclaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(65);
      environmentTransition();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(66);
      stateTransitionElapsedTime();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(67);
      stateTransitionEnvironmentState();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(68);
      stateAction();
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(BehaviorsParser::T__0);
    setState(72);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(73);
    match(BehaviorsParser::ID);
    setState(74);
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

BehaviorsParser::ExactlyNRandomSelectorContext* BehaviorsParser::StateSelectorContext::exactlyNRandomSelector() {
  return getRuleContext<BehaviorsParser::ExactlyNRandomSelectorContext>(0);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(80);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorsParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(76);
        idRatioSelector();
        break;
      }

      case BehaviorsParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(77);
        exactlyNRandomSelector();
        break;
      }

      case BehaviorsParser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(78);
        randomIdRatioSelector();
        break;
      }

      case BehaviorsParser::T__16: {
        enterOuterAlt(_localctx, 4);
        setState(79);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(BehaviorsParser::NUMBER);
    setState(83);
    match(BehaviorsParser::T__4);
    setState(84);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(85);
    match(BehaviorsParser::ID);
    setState(86);
    match(BehaviorsParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExactlyNRandomSelectorContext ------------------------------------------------------------------

BehaviorsParser::ExactlyNRandomSelectorContext::ExactlyNRandomSelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::ExactlyNRandomSelectorContext::NUMBER() {
  return getToken(BehaviorsParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorsParser::ExactlyNRandomSelectorContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}


size_t BehaviorsParser::ExactlyNRandomSelectorContext::getRuleIndex() const {
  return BehaviorsParser::RuleExactlyNRandomSelector;
}

antlrcpp::Any BehaviorsParser::ExactlyNRandomSelectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitExactlyNRandomSelector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::ExactlyNRandomSelectorContext* BehaviorsParser::exactlyNRandomSelector() {
  ExactlyNRandomSelectorContext *_localctx = _tracker.createInstance<ExactlyNRandomSelectorContext>(_ctx, getState());
  enterRule(_localctx, 10, BehaviorsParser::RuleExactlyNRandomSelector);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(BehaviorsParser::T__5);
    setState(89);
    match(BehaviorsParser::NUMBER);
    setState(90);
    match(BehaviorsParser::T__6);
    setState(91);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(92);
    match(BehaviorsParser::ID);
    setState(93);
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
  enterRule(_localctx, 12, BehaviorsParser::RuleRandomIdRatioStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(BehaviorsParser::T__7);
    setState(96);
    match(BehaviorsParser::NUMBER);
    setState(97);
    match(BehaviorsParser::T__8);
    setState(98);
    match(BehaviorsParser::NUMBER);
    setState(99);
    match(BehaviorsParser::T__9);
    setState(100);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(101);
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
  enterRule(_localctx, 14, BehaviorsParser::RuleRandomIdRatioSelector);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(111);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<RandomIdRatioSelectorContext *>(_tracker.createInstance<BehaviorsParser::NoGroupRandomIdSelectorContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(103);
      randomIdRatioStatement();
      setState(104);
      match(BehaviorsParser::T__3);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<RandomIdRatioSelectorContext *>(_tracker.createInstance<BehaviorsParser::GroupingRandomIdSelectorContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(106);
      randomIdRatioStatement();
      setState(107);
      match(BehaviorsParser::T__10);
      setState(108);
      match(BehaviorsParser::ID);
      setState(109);
      match(BehaviorsParser::T__3);
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
  enterRule(_localctx, 16, BehaviorsParser::RuleConditionElapsedTime);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(BehaviorsParser::T__11);
    setState(114);
    match(BehaviorsParser::NUMBER);
    setState(115);
    match(BehaviorsParser::T__12);
   
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
  enterRule(_localctx, 18, BehaviorsParser::RuleConditionEnvironmentState);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__13

    || _la == BehaviorsParser::T__14)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(118);
    match(BehaviorsParser::T__15);
    setState(119);
    match(BehaviorsParser::ID);
    setState(120);
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
  enterRule(_localctx, 20, BehaviorsParser::RuleEveryoneSelector);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(BehaviorsParser::T__16);
    setState(123);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__1

    || _la == BehaviorsParser::T__2)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(124);
    match(BehaviorsParser::ID);
    setState(125);
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
  enterRule(_localctx, 22, BehaviorsParser::RuleEnvironmentStateDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(BehaviorsParser::T__17);
    setState(128);
    match(BehaviorsParser::ID);
    setState(129);
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
  enterRule(_localctx, 24, BehaviorsParser::RuleEnvironmentInitialStateDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(BehaviorsParser::T__18);
    setState(132);
    match(BehaviorsParser::ID);
    setState(133);
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
  enterRule(_localctx, 26, BehaviorsParser::RuleEnvironmentTransition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(BehaviorsParser::T__19);
    setState(136);
    match(BehaviorsParser::ID);
    setState(137);
    match(BehaviorsParser::T__20);
    setState(138);
    match(BehaviorsParser::ID);
    setState(139);
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
  enterRule(_localctx, 28, BehaviorsParser::RuleStateDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__21

    || _la == BehaviorsParser::T__22)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(142);
    match(BehaviorsParser::ID);
    setState(143);
    match(BehaviorsParser::T__23);
    setState(144);
    match(BehaviorsParser::ID);
    setState(145);
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
  enterRule(_localctx, 30, BehaviorsParser::RuleInitialStateDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__21

    || _la == BehaviorsParser::T__22)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(148);
    match(BehaviorsParser::ID);
    setState(149);
    match(BehaviorsParser::T__24);
    setState(150);
    match(BehaviorsParser::ID);
    setState(151);
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
  enterRule(_localctx, 32, BehaviorsParser::RulePedestrianSelected);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__21

    || _la == BehaviorsParser::T__22)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(154);
    match(BehaviorsParser::ID);
    setState(155);
    match(BehaviorsParser::T__25);
    setState(156);
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
  enterRule(_localctx, 34, BehaviorsParser::RuleStateTransitionElapsedTime);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    pedestrianSelected();
    setState(159);
    match(BehaviorsParser::T__20);
    setState(160);
    match(BehaviorsParser::ID);
    setState(161);
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
  enterRule(_localctx, 36, BehaviorsParser::RuleStateTransitionEnvironmentState);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    pedestrianSelected();
    setState(164);
    match(BehaviorsParser::T__20);
    setState(165);
    match(BehaviorsParser::ID);
    setState(166);
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
  enterRule(_localctx, 38, BehaviorsParser::RuleFasterOrSlower);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
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
  enterRule(_localctx, 40, BehaviorsParser::RuleTowardOrAwayFrom);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
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
  enterRule(_localctx, 42, BehaviorsParser::RuleTarget);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    _la = _input->LA(1);
    if (!(_la == BehaviorsParser::T__30

    || _la == BehaviorsParser::T__31)) {
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
  enterRule(_localctx, 44, BehaviorsParser::RuleStoppedBehavior);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(BehaviorsParser::T__32);
   
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
  enterRule(_localctx, 46, BehaviorsParser::RuleWalkSpeedBehavior);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(BehaviorsParser::T__33);
    setState(177);
    match(BehaviorsParser::NUMBER);
    setState(178);
    match(BehaviorsParser::T__34);
    setState(179);
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
  enterRule(_localctx, 48, BehaviorsParser::RuleWalkSpeedWithTargetBehavior);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(BehaviorsParser::T__33);
    setState(182);
    match(BehaviorsParser::NUMBER);
    setState(183);
    match(BehaviorsParser::T__34);
    setState(184);
    fasterOrSlower();
    setState(185);
    match(BehaviorsParser::T__35);
    setState(186);
    towardOrAwayFrom();
    setState(187);
    match(BehaviorsParser::T__35);
    setState(188);
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
  enterRule(_localctx, 50, BehaviorsParser::RuleNormalBehavior);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(BehaviorsParser::T__36);
   
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
  enterRule(_localctx, 52, BehaviorsParser::RuleStateAction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(208);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StateActionContext *>(_tracker.createInstance<BehaviorsParser::StateActionStoppedContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(192);
      pedestrianSelected();
      setState(193);
      stoppedBehavior();
      setState(194);
      match(BehaviorsParser::T__3);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StateActionContext *>(_tracker.createInstance<BehaviorsParser::StateActionWalkSpeedContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(196);
      pedestrianSelected();
      setState(197);
      walkSpeedBehavior();
      setState(198);
      match(BehaviorsParser::T__3);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StateActionContext *>(_tracker.createInstance<BehaviorsParser::StateActionWalkSpeedWithTargetContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(200);
      pedestrianSelected();
      setState(201);
      walkSpeedWithTargetBehavior();
      setState(202);
      match(BehaviorsParser::T__3);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StateActionContext *>(_tracker.createInstance<BehaviorsParser::StateActionNormalContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(204);
      pedestrianSelected();
      setState(205);
      normalBehavior();
      setState(206);
      match(BehaviorsParser::T__3);
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

// Static vars and initialization.
std::vector<dfa::DFA> BehaviorsParser::_decisionToDFA;
atn::PredictionContextCache BehaviorsParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN BehaviorsParser::_atn;
std::vector<uint16_t> BehaviorsParser::_serializedATN;

std::vector<std::string> BehaviorsParser::_ruleNames = {
  "program", "statement", "consideration", "stateSelector", "idRatioSelector", 
  "exactlyNRandomSelector", "randomIdRatioStatement", "randomIdRatioSelector", 
  "conditionElapsedTime", "conditionEnvironmentState", "everyoneSelector", 
  "environmentStateDeclaration", "environmentInitialStateDeclaration", "environmentTransition", 
  "stateDeclaration", "initialStateDeclaration", "pedestrianSelected", "stateTransitionElapsedTime", 
  "stateTransitionEnvironmentState", "fasterOrSlower", "towardOrAwayFrom", 
  "target", "stoppedBehavior", "walkSpeedBehavior", "walkSpeedWithTargetBehavior", 
  "normalBehavior", "stateAction"
};

std::vector<std::string> BehaviorsParser::_literalNames = {
  "", "'Consider '", "'a '", "'an '", "'.'", "'% of the population are '", 
  "'Exactly '", "' random pedestrian is '", "'A random '", "' out of every '", 
  "' pedestrians is '", "', forming a '", "' after '", "' seconds.'", "' if'", 
  "' when'", "' the environment is '", "'Everyone is '", "'The environment can be '", 
  "'The environment is initially '", "'The environment that is '", "' will be '", 
  "'A '", "'An '", "' can be '", "' is initially '", "' who is '", "'faster'", 
  "'slower'", "'toward'", "'away from'", "'their group'", "'their goal'", 
  "' is STOPPED'", "' will walk '", "'% '", "' '", "' will behave normally'"
};

std::vector<std::string> BehaviorsParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "ID", "NUMBER", "COMMENT", "LINE_COMMENT", "WHITESPACE"
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

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2c, 0xd5, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 
    0x1c, 0x9, 0x1c, 0x3, 0x2, 0x6, 0x2, 0x3a, 0xa, 0x2, 0xd, 0x2, 0xe, 
    0x2, 0x3b, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x48, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x53, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x72, 0xa, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0xd3, 0xa, 0x1c, 0x3, 0x1c, 0x2, 
    0x2, 0x1d, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
    0x30, 0x32, 0x34, 0x36, 0x2, 0x8, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 0x10, 
    0x11, 0x3, 0x2, 0x18, 0x19, 0x3, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x1f, 0x20, 
    0x3, 0x2, 0x21, 0x22, 0x2, 0xca, 0x2, 0x39, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x6, 0x49, 0x3, 0x2, 0x2, 0x2, 0x8, 0x52, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x54, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x61, 0x3, 0x2, 0x2, 0x2, 0x10, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x73, 0x3, 0x2, 0x2, 0x2, 0x14, 0x77, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x18, 0x81, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x89, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x95, 0x3, 0x2, 0x2, 0x2, 0x22, 0x9b, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x26, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xac, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xae, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xb0, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0xb2, 0x3, 0x2, 0x2, 0x2, 0x32, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0xc0, 0x3, 0x2, 0x2, 0x2, 0x36, 0xd2, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3a, 
    0x5, 0x4, 0x3, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x3, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x48, 0x5, 0x6, 0x4, 
    0x2, 0x3e, 0x48, 0x5, 0x8, 0x5, 0x2, 0x3f, 0x48, 0x5, 0x1e, 0x10, 0x2, 
    0x40, 0x48, 0x5, 0x20, 0x11, 0x2, 0x41, 0x48, 0x5, 0x18, 0xd, 0x2, 0x42, 
    0x48, 0x5, 0x1a, 0xe, 0x2, 0x43, 0x48, 0x5, 0x1c, 0xf, 0x2, 0x44, 0x48, 
    0x5, 0x24, 0x13, 0x2, 0x45, 0x48, 0x5, 0x26, 0x14, 0x2, 0x46, 0x48, 
    0x5, 0x36, 0x1c, 0x2, 0x47, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x47, 0x3e, 0x3, 
    0x2, 0x2, 0x2, 0x47, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x47, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x41, 0x3, 0x2, 0x2, 0x2, 0x47, 0x42, 0x3, 0x2, 0x2, 
    0x2, 0x47, 0x43, 0x3, 0x2, 0x2, 0x2, 0x47, 0x44, 0x3, 0x2, 0x2, 0x2, 
    0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x3, 0x2, 0x2, 0x4a, 0x4b, 
    0x9, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x28, 0x2, 0x2, 0x4c, 0x4d, 0x7, 
    0x6, 0x2, 0x2, 0x4d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x53, 0x5, 0xa, 
    0x6, 0x2, 0x4f, 0x53, 0x5, 0xc, 0x7, 0x2, 0x50, 0x53, 0x5, 0x10, 0x9, 
    0x2, 0x51, 0x53, 0x5, 0x16, 0xc, 0x2, 0x52, 0x4e, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 0x9, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 
    0x7, 0x29, 0x2, 0x2, 0x55, 0x56, 0x7, 0x7, 0x2, 0x2, 0x56, 0x57, 0x9, 
    0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 0x28, 0x2, 0x2, 0x58, 0x59, 0x7, 0x6, 
    0x2, 0x2, 0x59, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x8, 0x2, 
    0x2, 0x5b, 0x5c, 0x7, 0x29, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x9, 0x2, 0x2, 
    0x5d, 0x5e, 0x9, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x28, 0x2, 0x2, 0x5f, 
    0x60, 0x7, 0x6, 0x2, 0x2, 0x60, 0xd, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 
    0x7, 0xa, 0x2, 0x2, 0x62, 0x63, 0x7, 0x29, 0x2, 0x2, 0x63, 0x64, 0x7, 
    0xb, 0x2, 0x2, 0x64, 0x65, 0x7, 0x29, 0x2, 0x2, 0x65, 0x66, 0x7, 0xc, 
    0x2, 0x2, 0x66, 0x67, 0x9, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x28, 0x2, 
    0x2, 0x68, 0xf, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x5, 0xe, 0x8, 0x2, 
    0x6a, 0x6b, 0x7, 0x6, 0x2, 0x2, 0x6b, 0x72, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x6d, 0x5, 0xe, 0x8, 0x2, 0x6d, 0x6e, 0x7, 0xd, 0x2, 0x2, 0x6e, 0x6f, 
    0x7, 0x28, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x6, 0x2, 0x2, 0x70, 0x72, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x69, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x11, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0xe, 0x2, 
    0x2, 0x74, 0x75, 0x7, 0x29, 0x2, 0x2, 0x75, 0x76, 0x7, 0xf, 0x2, 0x2, 
    0x76, 0x13, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x9, 0x3, 0x2, 0x2, 0x78, 
    0x79, 0x7, 0x12, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x28, 0x2, 0x2, 0x7a, 0x7b, 
    0x7, 0x6, 0x2, 0x2, 0x7b, 0x15, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 
    0x13, 0x2, 0x2, 0x7d, 0x7e, 0x9, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x28, 
    0x2, 0x2, 0x7f, 0x80, 0x7, 0x6, 0x2, 0x2, 0x80, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x82, 0x7, 0x14, 0x2, 0x2, 0x82, 0x83, 0x7, 0x28, 0x2, 0x2, 
    0x83, 0x84, 0x7, 0x6, 0x2, 0x2, 0x84, 0x19, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x86, 0x7, 0x15, 0x2, 0x2, 0x86, 0x87, 0x7, 0x28, 0x2, 0x2, 0x87, 0x88, 
    0x7, 0x6, 0x2, 0x2, 0x88, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x7, 
    0x16, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x28, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x17, 
    0x2, 0x2, 0x8c, 0x8d, 0x7, 0x28, 0x2, 0x2, 0x8d, 0x8e, 0x5, 0x12, 0xa, 
    0x2, 0x8e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x9, 0x4, 0x2, 0x2, 
    0x90, 0x91, 0x7, 0x28, 0x2, 0x2, 0x91, 0x92, 0x7, 0x1a, 0x2, 0x2, 0x92, 
    0x93, 0x7, 0x28, 0x2, 0x2, 0x93, 0x94, 0x7, 0x6, 0x2, 0x2, 0x94, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x9, 0x4, 0x2, 0x2, 0x96, 0x97, 0x7, 
    0x28, 0x2, 0x2, 0x97, 0x98, 0x7, 0x1b, 0x2, 0x2, 0x98, 0x99, 0x7, 0x28, 
    0x2, 0x2, 0x99, 0x9a, 0x7, 0x6, 0x2, 0x2, 0x9a, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x9b, 0x9c, 0x9, 0x4, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x28, 0x2, 0x2, 
    0x9d, 0x9e, 0x7, 0x1c, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x28, 0x2, 0x2, 0x9f, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0x22, 0x12, 0x2, 0xa1, 0xa2, 
    0x7, 0x17, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x28, 0x2, 0x2, 0xa3, 0xa4, 0x5, 
    0x12, 0xa, 0x2, 0xa4, 0x25, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x22, 
    0x12, 0x2, 0xa6, 0xa7, 0x7, 0x17, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x28, 0x2, 
    0x2, 0xa8, 0xa9, 0x5, 0x14, 0xb, 0x2, 0xa9, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0xab, 0x9, 0x5, 0x2, 0x2, 0xab, 0x29, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xad, 0x9, 0x6, 0x2, 0x2, 0xad, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 
    0x9, 0x7, 0x2, 0x2, 0xaf, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 
    0x23, 0x2, 0x2, 0xb1, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x24, 
    0x2, 0x2, 0xb3, 0xb4, 0x7, 0x29, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x25, 0x2, 
    0x2, 0xb5, 0xb6, 0x5, 0x28, 0x15, 0x2, 0xb6, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0xb7, 0xb8, 0x7, 0x24, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x29, 0x2, 0x2, 0xb9, 
    0xba, 0x7, 0x25, 0x2, 0x2, 0xba, 0xbb, 0x5, 0x28, 0x15, 0x2, 0xbb, 0xbc, 
    0x7, 0x26, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x2a, 0x16, 0x2, 0xbd, 0xbe, 0x7, 
    0x26, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x2c, 0x17, 0x2, 0xbf, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0xc1, 0x7, 0x27, 0x2, 0x2, 0xc1, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0xc2, 0xc3, 0x5, 0x22, 0x12, 0x2, 0xc3, 0xc4, 0x5, 0x2e, 0x18, 
    0x2, 0xc4, 0xc5, 0x7, 0x6, 0x2, 0x2, 0xc5, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0xc6, 0xc7, 0x5, 0x22, 0x12, 0x2, 0xc7, 0xc8, 0x5, 0x30, 0x19, 0x2, 
    0xc8, 0xc9, 0x7, 0x6, 0x2, 0x2, 0xc9, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xca, 
    0xcb, 0x5, 0x22, 0x12, 0x2, 0xcb, 0xcc, 0x5, 0x32, 0x1a, 0x2, 0xcc, 
    0xcd, 0x7, 0x6, 0x2, 0x2, 0xcd, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 
    0x5, 0x22, 0x12, 0x2, 0xcf, 0xd0, 0x5, 0x34, 0x1b, 0x2, 0xd0, 0xd1, 
    0x7, 0x6, 0x2, 0x2, 0xd1, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xd2, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xca, 0x3, 0x2, 
    0x2, 0x2, 0xd2, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd3, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x7, 0x3b, 0x47, 0x52, 0x71, 0xd2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

BehaviorsParser::Initializer BehaviorsParser::_init;
