
// Generated from Behavior.g4 by ANTLR 4.7.2


#include "BehaviorVisitor.h"

#include "BehaviorParser.h"


using namespace antlrcpp;
using namespace antlr4;

BehaviorParser::BehaviorParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

BehaviorParser::~BehaviorParser() {
  delete _interpreter;
}

std::string BehaviorParser::getGrammarFileName() const {
  return "Behavior.g4";
}

const std::vector<std::string>& BehaviorParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& BehaviorParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

BehaviorParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BehaviorParser::StatementContext *> BehaviorParser::ProgramContext::statement() {
  return getRuleContexts<BehaviorParser::StatementContext>();
}

BehaviorParser::StatementContext* BehaviorParser::ProgramContext::statement(size_t i) {
  return getRuleContext<BehaviorParser::StatementContext>(i);
}


size_t BehaviorParser::ProgramContext::getRuleIndex() const {
  return BehaviorParser::RuleProgram;
}

antlrcpp::Any BehaviorParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::ProgramContext* BehaviorParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, BehaviorParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(44);
      statement();
      setState(47); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BehaviorParser::T__2)
      | (1ULL << BehaviorParser::T__5)
      | (1ULL << BehaviorParser::T__11)
      | (1ULL << BehaviorParser::T__17)
      | (1ULL << BehaviorParser::T__18)
      | (1ULL << BehaviorParser::T__19)
      | (1ULL << BehaviorParser::A)
      | (1ULL << BehaviorParser::NUMBER))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

BehaviorParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::DeclarationContext* BehaviorParser::StatementContext::declaration() {
  return getRuleContext<BehaviorParser::DeclarationContext>(0);
}

BehaviorParser::Ped_SelectorContext* BehaviorParser::StatementContext::ped_Selector() {
  return getRuleContext<BehaviorParser::Ped_SelectorContext>(0);
}

BehaviorParser::ActionContext* BehaviorParser::StatementContext::action() {
  return getRuleContext<BehaviorParser::ActionContext>(0);
}


size_t BehaviorParser::StatementContext::getRuleIndex() const {
  return BehaviorParser::RuleStatement;
}

antlrcpp::Any BehaviorParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::StatementContext* BehaviorParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, BehaviorParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(52);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::T__17:
      case BehaviorParser::T__18:
      case BehaviorParser::T__19: {
        enterOuterAlt(_localctx, 1);
        setState(49);
        declaration();
        break;
      }

      case BehaviorParser::T__2:
      case BehaviorParser::T__5:
      case BehaviorParser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(50);
        ped_Selector();
        break;
      }

      case BehaviorParser::T__11:
      case BehaviorParser::A: {
        enterOuterAlt(_localctx, 3);
        setState(51);
        action();
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

//----------------- Ped_SelectorContext ------------------------------------------------------------------

BehaviorParser::Ped_SelectorContext::Ped_SelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Selector_PercentContext* BehaviorParser::Ped_SelectorContext::selector_Percent() {
  return getRuleContext<BehaviorParser::Selector_PercentContext>(0);
}

BehaviorParser::Selector_Exactly_N_RandomContext* BehaviorParser::Ped_SelectorContext::selector_Exactly_N_Random() {
  return getRuleContext<BehaviorParser::Selector_Exactly_N_RandomContext>(0);
}

BehaviorParser::Selector_EveryoneContext* BehaviorParser::Ped_SelectorContext::selector_Everyone() {
  return getRuleContext<BehaviorParser::Selector_EveryoneContext>(0);
}


size_t BehaviorParser::Ped_SelectorContext::getRuleIndex() const {
  return BehaviorParser::RulePed_Selector;
}

antlrcpp::Any BehaviorParser::Ped_SelectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitPed_Selector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Ped_SelectorContext* BehaviorParser::ped_Selector() {
  Ped_SelectorContext *_localctx = _tracker.createInstance<Ped_SelectorContext>(_ctx, getState());
  enterRule(_localctx, 4, BehaviorParser::RulePed_Selector);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(57);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(54);
        selector_Percent();
        break;
      }

      case BehaviorParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(55);
        selector_Exactly_N_Random();
        break;
      }

      case BehaviorParser::T__5: {
        enterOuterAlt(_localctx, 3);
        setState(56);
        selector_Everyone();
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

//----------------- Selector_PercentContext ------------------------------------------------------------------

BehaviorParser::Selector_PercentContext::Selector_PercentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorParser::Selector_PercentContext::NUMBER() {
  return getTokens(BehaviorParser::NUMBER);
}

tree::TerminalNode* BehaviorParser::Selector_PercentContext::NUMBER(size_t i) {
  return getToken(BehaviorParser::NUMBER, i);
}

tree::TerminalNode* BehaviorParser::Selector_PercentContext::A() {
  return getToken(BehaviorParser::A, 0);
}

tree::TerminalNode* BehaviorParser::Selector_PercentContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Selector_PercentContext::END() {
  return getToken(BehaviorParser::END, 0);
}


size_t BehaviorParser::Selector_PercentContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_Percent;
}

antlrcpp::Any BehaviorParser::Selector_PercentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_Percent(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_PercentContext* BehaviorParser::selector_Percent() {
  Selector_PercentContext *_localctx = _tracker.createInstance<Selector_PercentContext>(_ctx, getState());
  enterRule(_localctx, 6, BehaviorParser::RuleSelector_Percent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(BehaviorParser::NUMBER);
    setState(60);
    match(BehaviorParser::T__0);
    setState(61);
    match(BehaviorParser::NUMBER);
    setState(62);
    match(BehaviorParser::T__1);
    setState(63);
    match(BehaviorParser::A);
    setState(64);
    match(BehaviorParser::ID);
    setState(65);
    match(BehaviorParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selector_Exactly_N_RandomContext ------------------------------------------------------------------

BehaviorParser::Selector_Exactly_N_RandomContext::Selector_Exactly_N_RandomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Selector_Exactly_N_RandomContext::NUMBER() {
  return getToken(BehaviorParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorParser::Selector_Exactly_N_RandomContext::A() {
  return getToken(BehaviorParser::A, 0);
}

tree::TerminalNode* BehaviorParser::Selector_Exactly_N_RandomContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Selector_Exactly_N_RandomContext::END() {
  return getToken(BehaviorParser::END, 0);
}


size_t BehaviorParser::Selector_Exactly_N_RandomContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_Exactly_N_Random;
}

antlrcpp::Any BehaviorParser::Selector_Exactly_N_RandomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_Exactly_N_Random(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_Exactly_N_RandomContext* BehaviorParser::selector_Exactly_N_Random() {
  Selector_Exactly_N_RandomContext *_localctx = _tracker.createInstance<Selector_Exactly_N_RandomContext>(_ctx, getState());
  enterRule(_localctx, 8, BehaviorParser::RuleSelector_Exactly_N_Random);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(67);
      match(BehaviorParser::T__2);
      setState(68);
      match(BehaviorParser::NUMBER);
      setState(69);
      match(BehaviorParser::T__3);
      setState(70);
      match(BehaviorParser::A);
      setState(71);
      match(BehaviorParser::ID);
      setState(72);
      match(BehaviorParser::END);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(73);
      match(BehaviorParser::T__2);
      setState(74);
      match(BehaviorParser::NUMBER);
      setState(75);
      match(BehaviorParser::T__4);
      setState(76);
      match(BehaviorParser::A);
      setState(77);
      match(BehaviorParser::ID);
      setState(78);
      match(BehaviorParser::END);
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

//----------------- Selector_EveryoneContext ------------------------------------------------------------------

BehaviorParser::Selector_EveryoneContext::Selector_EveryoneContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::A() {
  return getToken(BehaviorParser::A, 0);
}

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::END() {
  return getToken(BehaviorParser::END, 0);
}


size_t BehaviorParser::Selector_EveryoneContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_Everyone;
}

antlrcpp::Any BehaviorParser::Selector_EveryoneContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_Everyone(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_EveryoneContext* BehaviorParser::selector_Everyone() {
  Selector_EveryoneContext *_localctx = _tracker.createInstance<Selector_EveryoneContext>(_ctx, getState());
  enterRule(_localctx, 10, BehaviorParser::RuleSelector_Everyone);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    match(BehaviorParser::T__5);
    setState(82);
    match(BehaviorParser::A);
    setState(83);
    match(BehaviorParser::ID);
    setState(84);
    match(BehaviorParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

BehaviorParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorParser::ConditionContext::WS() {
  return getTokens(BehaviorParser::WS);
}

tree::TerminalNode* BehaviorParser::ConditionContext::WS(size_t i) {
  return getToken(BehaviorParser::WS, i);
}

BehaviorParser::Sub_conditionContext* BehaviorParser::ConditionContext::sub_condition() {
  return getRuleContext<BehaviorParser::Sub_conditionContext>(0);
}

tree::TerminalNode* BehaviorParser::ConditionContext::AndOr() {
  return getToken(BehaviorParser::AndOr, 0);
}

BehaviorParser::ConditionContext* BehaviorParser::ConditionContext::condition() {
  return getRuleContext<BehaviorParser::ConditionContext>(0);
}


size_t BehaviorParser::ConditionContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition;
}

antlrcpp::Any BehaviorParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::ConditionContext* BehaviorParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 12, BehaviorParser::RuleCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(95);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(86);
      match(BehaviorParser::WS);
      setState(87);
      sub_condition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(88);
      match(BehaviorParser::WS);
      setState(89);
      sub_condition();
      setState(90);
      match(BehaviorParser::WS);
      setState(91);
      match(BehaviorParser::AndOr);
      setState(92);
      match(BehaviorParser::WS);
      setState(93);
      condition();
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

//----------------- Sub_conditionContext ------------------------------------------------------------------

BehaviorParser::Sub_conditionContext::Sub_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Condition_StateContext* BehaviorParser::Sub_conditionContext::condition_State() {
  return getRuleContext<BehaviorParser::Condition_StateContext>(0);
}

BehaviorParser::Condition_ExistanceContext* BehaviorParser::Sub_conditionContext::condition_Existance() {
  return getRuleContext<BehaviorParser::Condition_ExistanceContext>(0);
}

BehaviorParser::Condition_Env_StateContext* BehaviorParser::Sub_conditionContext::condition_Env_State() {
  return getRuleContext<BehaviorParser::Condition_Env_StateContext>(0);
}


size_t BehaviorParser::Sub_conditionContext::getRuleIndex() const {
  return BehaviorParser::RuleSub_condition;
}

antlrcpp::Any BehaviorParser::Sub_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSub_condition(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Sub_conditionContext* BehaviorParser::sub_condition() {
  Sub_conditionContext *_localctx = _tracker.createInstance<Sub_conditionContext>(_ctx, getState());
  enterRule(_localctx, 14, BehaviorParser::RuleSub_condition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(100);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(97);
        condition_State();
        break;
      }

      case BehaviorParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(98);
        condition_Existance();
        break;
      }

      case BehaviorParser::T__10: {
        enterOuterAlt(_localctx, 3);
        setState(99);
        condition_Env_State();
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

//----------------- Condition_ExistanceContext ------------------------------------------------------------------

BehaviorParser::Condition_ExistanceContext::Condition_ExistanceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_ExistanceContext::A() {
  return getToken(BehaviorParser::A, 0);
}

tree::TerminalNode* BehaviorParser::Condition_ExistanceContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Condition_ExistanceContext::Direction() {
  return getToken(BehaviorParser::Direction, 0);
}

BehaviorParser::Condition_Others_StateContext* BehaviorParser::Condition_ExistanceContext::condition_Others_State() {
  return getRuleContext<BehaviorParser::Condition_Others_StateContext>(0);
}


size_t BehaviorParser::Condition_ExistanceContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Existance;
}

antlrcpp::Any BehaviorParser::Condition_ExistanceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Existance(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_ExistanceContext* BehaviorParser::condition_Existance() {
  Condition_ExistanceContext *_localctx = _tracker.createInstance<Condition_ExistanceContext>(_ctx, getState());
  enterRule(_localctx, 16, BehaviorParser::RuleCondition_Existance);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(111);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(102);
      match(BehaviorParser::T__6);
      setState(103);
      match(BehaviorParser::A);
      setState(104);
      match(BehaviorParser::ID);
      setState(105);
      match(BehaviorParser::Direction);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(106);
      match(BehaviorParser::T__6);
      setState(107);
      match(BehaviorParser::A);
      setState(108);
      match(BehaviorParser::ID);
      setState(109);
      match(BehaviorParser::Direction);
      setState(110);
      condition_Others_State();
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

//----------------- Condition_StateContext ------------------------------------------------------------------

BehaviorParser::Condition_StateContext::Condition_StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_StateContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Condition_StateContext::STATE() {
  return getToken(BehaviorParser::STATE, 0);
}


size_t BehaviorParser::Condition_StateContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_State;
}

antlrcpp::Any BehaviorParser::Condition_StateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_State(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_StateContext* BehaviorParser::condition_State() {
  Condition_StateContext *_localctx = _tracker.createInstance<Condition_StateContext>(_ctx, getState());
  enterRule(_localctx, 18, BehaviorParser::RuleCondition_State);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(BehaviorParser::T__7);
    setState(114);
    match(BehaviorParser::ID);
    setState(115);
    match(BehaviorParser::T__8);
    setState(116);
    match(BehaviorParser::STATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Others_StateContext ------------------------------------------------------------------

BehaviorParser::Condition_Others_StateContext::Condition_Others_StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Others_StateContext::STATE() {
  return getToken(BehaviorParser::STATE, 0);
}


size_t BehaviorParser::Condition_Others_StateContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Others_State;
}

antlrcpp::Any BehaviorParser::Condition_Others_StateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Others_State(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Others_StateContext* BehaviorParser::condition_Others_State() {
  Condition_Others_StateContext *_localctx = _tracker.createInstance<Condition_Others_StateContext>(_ctx, getState());
  enterRule(_localctx, 20, BehaviorParser::RuleCondition_Others_State);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(BehaviorParser::T__9);
    setState(119);
    match(BehaviorParser::STATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Env_StateContext ------------------------------------------------------------------

BehaviorParser::Condition_Env_StateContext::Condition_Env_StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Env_StateContext::STATE() {
  return getToken(BehaviorParser::STATE, 0);
}


size_t BehaviorParser::Condition_Env_StateContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Env_State;
}

antlrcpp::Any BehaviorParser::Condition_Env_StateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Env_State(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Env_StateContext* BehaviorParser::condition_Env_State() {
  Condition_Env_StateContext *_localctx = _tracker.createInstance<Condition_Env_StateContext>(_ctx, getState());
  enterRule(_localctx, 22, BehaviorParser::RuleCondition_Env_State);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(BehaviorParser::T__10);
    setState(122);
    match(BehaviorParser::STATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActionContext ------------------------------------------------------------------

BehaviorParser::ActionContext::ActionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Conditional_actionContext* BehaviorParser::ActionContext::conditional_action() {
  return getRuleContext<BehaviorParser::Conditional_actionContext>(0);
}

BehaviorParser::Non_conditional_actionContext* BehaviorParser::ActionContext::non_conditional_action() {
  return getRuleContext<BehaviorParser::Non_conditional_actionContext>(0);
}


size_t BehaviorParser::ActionContext::getRuleIndex() const {
  return BehaviorParser::RuleAction;
}

antlrcpp::Any BehaviorParser::ActionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::ActionContext* BehaviorParser::action() {
  ActionContext *_localctx = _tracker.createInstance<ActionContext>(_ctx, getState());
  enterRule(_localctx, 24, BehaviorParser::RuleAction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::T__11: {
        enterOuterAlt(_localctx, 1);
        setState(124);
        conditional_action();
        break;
      }

      case BehaviorParser::A: {
        enterOuterAlt(_localctx, 2);
        setState(125);
        non_conditional_action();
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

//----------------- Conditional_actionContext ------------------------------------------------------------------

BehaviorParser::Conditional_actionContext::Conditional_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorParser::Conditional_actionContext::WS() {
  return getTokens(BehaviorParser::WS);
}

tree::TerminalNode* BehaviorParser::Conditional_actionContext::WS(size_t i) {
  return getToken(BehaviorParser::WS, i);
}

BehaviorParser::ConditionContext* BehaviorParser::Conditional_actionContext::condition() {
  return getRuleContext<BehaviorParser::ConditionContext>(0);
}

tree::TerminalNode* BehaviorParser::Conditional_actionContext::A() {
  return getToken(BehaviorParser::A, 0);
}

tree::TerminalNode* BehaviorParser::Conditional_actionContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

BehaviorParser::Sub_actionContext* BehaviorParser::Conditional_actionContext::sub_action() {
  return getRuleContext<BehaviorParser::Sub_actionContext>(0);
}


size_t BehaviorParser::Conditional_actionContext::getRuleIndex() const {
  return BehaviorParser::RuleConditional_action;
}

antlrcpp::Any BehaviorParser::Conditional_actionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitConditional_action(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Conditional_actionContext* BehaviorParser::conditional_action() {
  Conditional_actionContext *_localctx = _tracker.createInstance<Conditional_actionContext>(_ctx, getState());
  enterRule(_localctx, 26, BehaviorParser::RuleConditional_action);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    match(BehaviorParser::T__11);
    setState(129);
    match(BehaviorParser::WS);
    setState(130);
    condition();
    setState(131);
    match(BehaviorParser::WS);
    setState(132);
    match(BehaviorParser::A);
    setState(133);
    match(BehaviorParser::ID);
    setState(134);
    match(BehaviorParser::T__12);
    setState(135);
    match(BehaviorParser::WS);
    setState(136);
    sub_action();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Non_conditional_actionContext ------------------------------------------------------------------

BehaviorParser::Non_conditional_actionContext::Non_conditional_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Non_conditional_actionContext::A() {
  return getToken(BehaviorParser::A, 0);
}

tree::TerminalNode* BehaviorParser::Non_conditional_actionContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Non_conditional_actionContext::WS() {
  return getToken(BehaviorParser::WS, 0);
}

BehaviorParser::Sub_actionContext* BehaviorParser::Non_conditional_actionContext::sub_action() {
  return getRuleContext<BehaviorParser::Sub_actionContext>(0);
}


size_t BehaviorParser::Non_conditional_actionContext::getRuleIndex() const {
  return BehaviorParser::RuleNon_conditional_action;
}

antlrcpp::Any BehaviorParser::Non_conditional_actionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitNon_conditional_action(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Non_conditional_actionContext* BehaviorParser::non_conditional_action() {
  Non_conditional_actionContext *_localctx = _tracker.createInstance<Non_conditional_actionContext>(_ctx, getState());
  enterRule(_localctx, 28, BehaviorParser::RuleNon_conditional_action);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    match(BehaviorParser::A);
    setState(139);
    match(BehaviorParser::ID);
    setState(140);
    match(BehaviorParser::T__13);
    setState(141);
    match(BehaviorParser::WS);
    setState(142);
    sub_action();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sub_actionContext ------------------------------------------------------------------

BehaviorParser::Sub_actionContext::Sub_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Action_atomContext* BehaviorParser::Sub_actionContext::action_atom() {
  return getRuleContext<BehaviorParser::Action_atomContext>(0);
}

BehaviorParser::Sub_actionContext* BehaviorParser::Sub_actionContext::sub_action() {
  return getRuleContext<BehaviorParser::Sub_actionContext>(0);
}


size_t BehaviorParser::Sub_actionContext::getRuleIndex() const {
  return BehaviorParser::RuleSub_action;
}

antlrcpp::Any BehaviorParser::Sub_actionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSub_action(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Sub_actionContext* BehaviorParser::sub_action() {
  Sub_actionContext *_localctx = _tracker.createInstance<Sub_actionContext>(_ctx, getState());
  enterRule(_localctx, 30, BehaviorParser::RuleSub_action);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(144);
      action_atom();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(145);
      action_atom();
      setState(146);
      match(BehaviorParser::T__14);
      setState(147);
      sub_action();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(149);
      action_atom();
      setState(150);
      match(BehaviorParser::T__15);
      setState(151);
      sub_action();
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

//----------------- Action_atomContext ------------------------------------------------------------------

BehaviorParser::Action_atomContext::Action_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Action_StopContext* BehaviorParser::Action_atomContext::action_Stop() {
  return getRuleContext<BehaviorParser::Action_StopContext>(0);
}


size_t BehaviorParser::Action_atomContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_atom;
}

antlrcpp::Any BehaviorParser::Action_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_atom(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_atomContext* BehaviorParser::action_atom() {
  Action_atomContext *_localctx = _tracker.createInstance<Action_atomContext>(_ctx, getState());
  enterRule(_localctx, 32, BehaviorParser::RuleAction_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    action_Stop();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_StopContext ------------------------------------------------------------------

BehaviorParser::Action_StopContext::Action_StopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorParser::Action_StopContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_Stop;
}

antlrcpp::Any BehaviorParser::Action_StopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_Stop(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_StopContext* BehaviorParser::action_Stop() {
  Action_StopContext *_localctx = _tracker.createInstance<Action_StopContext>(_ctx, getState());
  enterRule(_localctx, 34, BehaviorParser::RuleAction_Stop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(BehaviorParser::T__16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

BehaviorParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Decl_PedContext* BehaviorParser::DeclarationContext::decl_Ped() {
  return getRuleContext<BehaviorParser::Decl_PedContext>(0);
}

BehaviorParser::Decl_Ped_StateContext* BehaviorParser::DeclarationContext::decl_Ped_State() {
  return getRuleContext<BehaviorParser::Decl_Ped_StateContext>(0);
}

BehaviorParser::Decl_Env_StateContext* BehaviorParser::DeclarationContext::decl_Env_State() {
  return getRuleContext<BehaviorParser::Decl_Env_StateContext>(0);
}


size_t BehaviorParser::DeclarationContext::getRuleIndex() const {
  return BehaviorParser::RuleDeclaration;
}

antlrcpp::Any BehaviorParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::DeclarationContext* BehaviorParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 36, BehaviorParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::T__17: {
        enterOuterAlt(_localctx, 1);
        setState(159);
        decl_Ped();
        break;
      }

      case BehaviorParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(160);
        decl_Ped_State();
        break;
      }

      case BehaviorParser::T__19: {
        enterOuterAlt(_localctx, 3);
        setState(161);
        decl_Env_State();
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

//----------------- Decl_PedContext ------------------------------------------------------------------

BehaviorParser::Decl_PedContext::Decl_PedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::A() {
  return getToken(BehaviorParser::A, 0);
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}


size_t BehaviorParser::Decl_PedContext::getRuleIndex() const {
  return BehaviorParser::RuleDecl_Ped;
}

antlrcpp::Any BehaviorParser::Decl_PedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDecl_Ped(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Decl_PedContext* BehaviorParser::decl_Ped() {
  Decl_PedContext *_localctx = _tracker.createInstance<Decl_PedContext>(_ctx, getState());
  enterRule(_localctx, 38, BehaviorParser::RuleDecl_Ped);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    match(BehaviorParser::T__17);
    setState(165);
    match(BehaviorParser::A);
    setState(166);
    match(BehaviorParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decl_Ped_StateContext ------------------------------------------------------------------

BehaviorParser::Decl_Ped_StateContext::Decl_Ped_StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Ped_StateContext::ID() {
  return getTokens(BehaviorParser::ID);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::ID(size_t i) {
  return getToken(BehaviorParser::ID, i);
}


size_t BehaviorParser::Decl_Ped_StateContext::getRuleIndex() const {
  return BehaviorParser::RuleDecl_Ped_State;
}

antlrcpp::Any BehaviorParser::Decl_Ped_StateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDecl_Ped_State(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Decl_Ped_StateContext* BehaviorParser::decl_Ped_State() {
  Decl_Ped_StateContext *_localctx = _tracker.createInstance<Decl_Ped_StateContext>(_ctx, getState());
  enterRule(_localctx, 40, BehaviorParser::RuleDecl_Ped_State);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    match(BehaviorParser::T__18);
    setState(170); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(169);
      match(BehaviorParser::ID);
      setState(172); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == BehaviorParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decl_Env_StateContext ------------------------------------------------------------------

BehaviorParser::Decl_Env_StateContext::Decl_Env_StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Env_StateContext::ID() {
  return getTokens(BehaviorParser::ID);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::ID(size_t i) {
  return getToken(BehaviorParser::ID, i);
}


size_t BehaviorParser::Decl_Env_StateContext::getRuleIndex() const {
  return BehaviorParser::RuleDecl_Env_State;
}

antlrcpp::Any BehaviorParser::Decl_Env_StateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDecl_Env_State(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Decl_Env_StateContext* BehaviorParser::decl_Env_State() {
  Decl_Env_StateContext *_localctx = _tracker.createInstance<Decl_Env_StateContext>(_ctx, getState());
  enterRule(_localctx, 42, BehaviorParser::RuleDecl_Env_State);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(BehaviorParser::T__19);
    setState(176); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(175);
      match(BehaviorParser::ID);
      setState(178); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == BehaviorParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> BehaviorParser::_decisionToDFA;
atn::PredictionContextCache BehaviorParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN BehaviorParser::_atn;
std::vector<uint16_t> BehaviorParser::_serializedATN;

std::vector<std::string> BehaviorParser::_ruleNames = {
  "program", "statement", "ped_Selector", "selector_Percent", "selector_Exactly_N_Random", 
  "selector_Everyone", "condition", "sub_condition", "condition_Existance", 
  "condition_State", "condition_Others_State", "condition_Env_State", "action", 
  "conditional_action", "non_conditional_action", "sub_action", "action_atom", 
  "action_Stop", "declaration", "decl_Ped", "decl_Ped_State", "decl_Env_State"
};

std::vector<std::string> BehaviorParser::_literalNames = {
  "", "' out of '", "' Pedestrians is '", "'Exactly '", "' random pedestrians are '", 
  "' random pedestrian is '", "'Everyone is '", "' There is '", "' The '", 
  "' is '", "' That is '", "' The Environment is '", "'Given'", "' will '", 
  "' will always '", "', '", "' and '", "'STOP'", "'Consider '", "'Possible Pedestrian States Are: '", 
  "'Possible Environment States Are: '", "", "", "'.'"
};

std::vector<std::string> BehaviorParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "A", "AndOr", "END", "ID", "STATE", "NUMBER", "PERCENT", "COMMENT", 
  "LINE_COMMENT", "WS", "Direction"
};

dfa::Vocabulary BehaviorParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> BehaviorParser::_tokenNames;

BehaviorParser::Initializer::Initializer() {
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
    0x3, 0x21, 0xb7, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x6, 0x2, 
    0x30, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x31, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x37, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3c, 
    0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x52, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x62, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0x67, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x72, 
    0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x5, 0xe, 0x81, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x5, 0x11, 0x9c, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xa5, 0xa, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x6, 0x16, 
    0xad, 0xa, 0x16, 0xd, 0x16, 0xe, 0x16, 0xae, 0x3, 0x17, 0x3, 0x17, 0x6, 
    0x17, 0xb3, 0xa, 0x17, 0xd, 0x17, 0xe, 0x17, 0xb4, 0x3, 0x17, 0x2, 0x2, 
    0x18, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2, 0x2, 
    0x2, 0xb1, 0x2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x36, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0xc, 0x53, 0x3, 0x2, 0x2, 0x2, 0xe, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x66, 0x3, 0x2, 0x2, 0x2, 0x12, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x73, 0x3, 0x2, 0x2, 0x2, 0x16, 0x78, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x80, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x82, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x8c, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x22, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0x26, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x28, 0xa6, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xb0, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x4, 0x3, 0x2, 0x2f, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x33, 0x37, 0x5, 0x26, 0x14, 0x2, 0x34, 0x37, 0x5, 0x6, 0x4, 0x2, 0x35, 
    0x37, 0x5, 0x1a, 0xe, 0x2, 0x36, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x34, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x3c, 0x5, 0x8, 0x5, 0x2, 0x39, 0x3c, 0x5, 0xa, 
    0x6, 0x2, 0x3a, 0x3c, 0x5, 0xc, 0x7, 0x2, 0x3b, 0x38, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x1c, 0x2, 0x2, 0x3e, 
    0x3f, 0x7, 0x3, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x1c, 0x2, 0x2, 0x40, 0x41, 
    0x7, 0x4, 0x2, 0x2, 0x41, 0x42, 0x7, 0x17, 0x2, 0x2, 0x42, 0x43, 0x7, 
    0x1a, 0x2, 0x2, 0x43, 0x44, 0x7, 0x19, 0x2, 0x2, 0x44, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x45, 0x46, 0x7, 0x5, 0x2, 0x2, 0x46, 0x47, 0x7, 0x1c, 0x2, 
    0x2, 0x47, 0x48, 0x7, 0x6, 0x2, 0x2, 0x48, 0x49, 0x7, 0x17, 0x2, 0x2, 
    0x49, 0x4a, 0x7, 0x1a, 0x2, 0x2, 0x4a, 0x52, 0x7, 0x19, 0x2, 0x2, 0x4b, 
    0x4c, 0x7, 0x5, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x1c, 0x2, 0x2, 0x4d, 0x4e, 
    0x7, 0x7, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x17, 0x2, 0x2, 0x4f, 0x50, 0x7, 
    0x1a, 0x2, 0x2, 0x50, 0x52, 0x7, 0x19, 0x2, 0x2, 0x51, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x51, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x52, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x54, 0x7, 0x8, 0x2, 0x2, 0x54, 0x55, 0x7, 0x17, 0x2, 0x2, 
    0x55, 0x56, 0x7, 0x1a, 0x2, 0x2, 0x56, 0x57, 0x7, 0x19, 0x2, 0x2, 0x57, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 0x20, 0x2, 0x2, 0x59, 0x62, 
    0x5, 0x10, 0x9, 0x2, 0x5a, 0x5b, 0x7, 0x20, 0x2, 0x2, 0x5b, 0x5c, 0x5, 
    0x10, 0x9, 0x2, 0x5c, 0x5d, 0x7, 0x20, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x18, 
    0x2, 0x2, 0x5e, 0x5f, 0x7, 0x20, 0x2, 0x2, 0x5f, 0x60, 0x5, 0xe, 0x8, 
    0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 0x61, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x61, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x62, 0xf, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x67, 0x5, 0x14, 0xb, 0x2, 0x64, 0x67, 0x5, 0x12, 0xa, 0x2, 0x65, 0x67, 
    0x5, 0x18, 0xd, 0x2, 0x66, 0x63, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x69, 0x7, 0x9, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x17, 0x2, 
    0x2, 0x6a, 0x6b, 0x7, 0x1a, 0x2, 0x2, 0x6b, 0x72, 0x7, 0x21, 0x2, 0x2, 
    0x6c, 0x6d, 0x7, 0x9, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x17, 0x2, 0x2, 0x6e, 
    0x6f, 0x7, 0x1a, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x21, 0x2, 0x2, 0x70, 0x72, 
    0x5, 0x16, 0xc, 0x2, 0x71, 0x68, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6c, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x13, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0xa, 
    0x2, 0x2, 0x74, 0x75, 0x7, 0x1a, 0x2, 0x2, 0x75, 0x76, 0x7, 0xb, 0x2, 
    0x2, 0x76, 0x77, 0x7, 0x1b, 0x2, 0x2, 0x77, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x79, 0x7, 0xc, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x1b, 0x2, 0x2, 0x7a, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0xd, 0x2, 0x2, 0x7c, 0x7d, 
    0x7, 0x1b, 0x2, 0x2, 0x7d, 0x19, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x81, 0x5, 
    0x1c, 0xf, 0x2, 0x7f, 0x81, 0x5, 0x1e, 0x10, 0x2, 0x80, 0x7e, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x83, 0x7, 0xe, 0x2, 0x2, 0x83, 0x84, 0x7, 0x20, 0x2, 0x2, 
    0x84, 0x85, 0x5, 0xe, 0x8, 0x2, 0x85, 0x86, 0x7, 0x20, 0x2, 0x2, 0x86, 
    0x87, 0x7, 0x17, 0x2, 0x2, 0x87, 0x88, 0x7, 0x1a, 0x2, 0x2, 0x88, 0x89, 
    0x7, 0xf, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x20, 0x2, 0x2, 0x8a, 0x8b, 0x5, 
    0x20, 0x11, 0x2, 0x8b, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x17, 
    0x2, 0x2, 0x8d, 0x8e, 0x7, 0x1a, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x10, 0x2, 
    0x2, 0x8f, 0x90, 0x7, 0x20, 0x2, 0x2, 0x90, 0x91, 0x5, 0x20, 0x11, 0x2, 
    0x91, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x92, 0x9c, 0x5, 0x22, 0x12, 0x2, 0x93, 
    0x94, 0x5, 0x22, 0x12, 0x2, 0x94, 0x95, 0x7, 0x11, 0x2, 0x2, 0x95, 0x96, 
    0x5, 0x20, 0x11, 0x2, 0x96, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x5, 
    0x22, 0x12, 0x2, 0x98, 0x99, 0x7, 0x12, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x20, 
    0x11, 0x2, 0x9a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x9b, 0x93, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x9c, 0x21, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x24, 0x13, 0x2, 0x9e, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x13, 0x2, 0x2, 0xa0, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0xa1, 0xa5, 0x5, 0x28, 0x15, 0x2, 0xa2, 0xa5, 0x5, 
    0x2a, 0x16, 0x2, 0xa3, 0xa5, 0x5, 0x2c, 0x17, 0x2, 0xa4, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0xa5, 0x27, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x14, 0x2, 
    0x2, 0xa7, 0xa8, 0x7, 0x17, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x1a, 0x2, 0x2, 
    0xa9, 0x29, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xac, 0x7, 0x15, 0x2, 0x2, 0xab, 
    0xad, 0x7, 0x1a, 0x2, 0x2, 0xac, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0xaf, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb2, 0x7, 0x16, 
    0x2, 0x2, 0xb1, 0xb3, 0x7, 0x1a, 0x2, 0x2, 0xb2, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 
    0xb4, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb5, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x31, 0x36, 0x3b, 0x51, 0x61, 0x66, 0x71, 0x80, 0x9b, 0xa4, 0xae, 0xb4, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

BehaviorParser::Initializer BehaviorParser::_init;
