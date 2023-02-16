
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
    setState(67); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(66);
      statement();
      setState(69); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BehaviorParser::T__16)
      | (1ULL << BehaviorParser::T__18)
      | (1ULL << BehaviorParser::T__21)
      | (1ULL << BehaviorParser::T__28)
      | (1ULL << BehaviorParser::T__29)
      | (1ULL << BehaviorParser::T__30)
      | (1ULL << BehaviorParser::AN)
      | (1ULL << BehaviorParser::PARAMETERS))) != 0));
   
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

BehaviorParser::EventContext* BehaviorParser::StatementContext::event() {
  return getRuleContext<BehaviorParser::EventContext>(0);
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
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(71);
      event();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(72);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(73);
      ped_Selector();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(74);
      action();
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

//----------------- EventContext ------------------------------------------------------------------

BehaviorParser::EventContext::EventContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Event_SingleContext* BehaviorParser::EventContext::event_Single() {
  return getRuleContext<BehaviorParser::Event_SingleContext>(0);
}

BehaviorParser::Event_LastingContext* BehaviorParser::EventContext::event_Lasting() {
  return getRuleContext<BehaviorParser::Event_LastingContext>(0);
}


size_t BehaviorParser::EventContext::getRuleIndex() const {
  return BehaviorParser::RuleEvent;
}

antlrcpp::Any BehaviorParser::EventContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEvent(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::EventContext* BehaviorParser::event() {
  EventContext *_localctx = _tracker.createInstance<EventContext>(_ctx, getState());
  enterRule(_localctx, 4, BehaviorParser::RuleEvent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(77);
      event_Single();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(78);
      event_Lasting();
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

//----------------- Event_SingleContext ------------------------------------------------------------------

BehaviorParser::Event_SingleContext::Event_SingleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

BehaviorParser::ConditionContext* BehaviorParser::Event_SingleContext::condition() {
  return getRuleContext<BehaviorParser::ConditionContext>(0);
}


size_t BehaviorParser::Event_SingleContext::getRuleIndex() const {
  return BehaviorParser::RuleEvent_Single;
}

antlrcpp::Any BehaviorParser::Event_SingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEvent_Single(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Event_SingleContext* BehaviorParser::event_Single() {
  Event_SingleContext *_localctx = _tracker.createInstance<Event_SingleContext>(_ctx, getState());
  enterRule(_localctx, 6, BehaviorParser::RuleEvent_Single);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    match(BehaviorParser::AN);
    setState(82);
    match(BehaviorParser::EVENT);
    setState(83);
    match(BehaviorParser::T__0);
    setState(84);
    condition();
    setState(85);
    match(BehaviorParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Event_LastingContext ------------------------------------------------------------------

BehaviorParser::Event_LastingContext::Event_LastingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

std::vector<BehaviorParser::ConditionContext *> BehaviorParser::Event_LastingContext::condition() {
  return getRuleContexts<BehaviorParser::ConditionContext>();
}

BehaviorParser::ConditionContext* BehaviorParser::Event_LastingContext::condition(size_t i) {
  return getRuleContext<BehaviorParser::ConditionContext>(i);
}


size_t BehaviorParser::Event_LastingContext::getRuleIndex() const {
  return BehaviorParser::RuleEvent_Lasting;
}

antlrcpp::Any BehaviorParser::Event_LastingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEvent_Lasting(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Event_LastingContext* BehaviorParser::event_Lasting() {
  Event_LastingContext *_localctx = _tracker.createInstance<Event_LastingContext>(_ctx, getState());
  enterRule(_localctx, 8, BehaviorParser::RuleEvent_Lasting);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(BehaviorParser::AN);
    setState(88);
    match(BehaviorParser::EVENT);
    setState(89);
    match(BehaviorParser::T__0);
    setState(90);
    condition();
    setState(91);
    match(BehaviorParser::T__2);
    setState(92);
    condition();
    setState(93);
    match(BehaviorParser::T__1);
   
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

std::vector<BehaviorParser::Sub_conditionContext *> BehaviorParser::ConditionContext::sub_condition() {
  return getRuleContexts<BehaviorParser::Sub_conditionContext>();
}

BehaviorParser::Sub_conditionContext* BehaviorParser::ConditionContext::sub_condition(size_t i) {
  return getRuleContext<BehaviorParser::Sub_conditionContext>(i);
}

std::vector<tree::TerminalNode *> BehaviorParser::ConditionContext::ANDOR() {
  return getTokens(BehaviorParser::ANDOR);
}

tree::TerminalNode* BehaviorParser::ConditionContext::ANDOR(size_t i) {
  return getToken(BehaviorParser::ANDOR, i);
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
  enterRule(_localctx, 10, BehaviorParser::RuleCondition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    sub_condition();
    setState(100);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::ANDOR) {
      setState(96);
      match(BehaviorParser::ANDOR);
      setState(97);
      sub_condition();
      setState(102);
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

//----------------- Sub_conditionContext ------------------------------------------------------------------

BehaviorParser::Sub_conditionContext::Sub_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Condition_StateContext* BehaviorParser::Sub_conditionContext::condition_State() {
  return getRuleContext<BehaviorParser::Condition_StateContext>(0);
}

BehaviorParser::Condition_Time_Elapsed_From_EventContext* BehaviorParser::Sub_conditionContext::condition_Time_Elapsed_From_Event() {
  return getRuleContext<BehaviorParser::Condition_Time_Elapsed_From_EventContext>(0);
}

BehaviorParser::Condition_ExistanceContext* BehaviorParser::Sub_conditionContext::condition_Existance() {
  return getRuleContext<BehaviorParser::Condition_ExistanceContext>(0);
}

BehaviorParser::Condition_EventContext* BehaviorParser::Sub_conditionContext::condition_Event() {
  return getRuleContext<BehaviorParser::Condition_EventContext>(0);
}

BehaviorParser::Condition_Event_OccurringContext* BehaviorParser::Sub_conditionContext::condition_Event_Occurring() {
  return getRuleContext<BehaviorParser::Condition_Event_OccurringContext>(0);
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
  enterRule(_localctx, 12, BehaviorParser::RuleSub_condition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(103);
      condition_State();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(104);
      condition_Time_Elapsed_From_Event();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(105);
      condition_Existance();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(106);
      condition_Event();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(107);
      condition_Event_Occurring();
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

//----------------- Condition_ExistanceContext ------------------------------------------------------------------

BehaviorParser::Condition_ExistanceContext::Condition_ExistanceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_ExistanceContext::GIVEN() {
  return getToken(BehaviorParser::GIVEN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_ExistanceContext::AN() {
  return getToken(BehaviorParser::AN, 0);
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
  enterRule(_localctx, 14, BehaviorParser::RuleCondition_Existance);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(121);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(110);
      match(BehaviorParser::GIVEN);
      setState(111);
      match(BehaviorParser::T__3);
      setState(112);
      match(BehaviorParser::AN);
      setState(113);
      match(BehaviorParser::ID);
      setState(114);
      match(BehaviorParser::Direction);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(115);
      match(BehaviorParser::GIVEN);
      setState(116);
      match(BehaviorParser::T__3);
      setState(117);
      match(BehaviorParser::AN);
      setState(118);
      match(BehaviorParser::ID);
      setState(119);
      match(BehaviorParser::Direction);
      setState(120);
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

tree::TerminalNode* BehaviorParser::Condition_StateContext::GIVEN() {
  return getToken(BehaviorParser::GIVEN, 0);
}

BehaviorParser::ObjectContext* BehaviorParser::Condition_StateContext::object() {
  return getRuleContext<BehaviorParser::ObjectContext>(0);
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
  enterRule(_localctx, 16, BehaviorParser::RuleCondition_State);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(BehaviorParser::GIVEN);
    setState(124);
    object();
    setState(125);
    match(BehaviorParser::T__4);
    setState(126);
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
  enterRule(_localctx, 18, BehaviorParser::RuleCondition_Others_State);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    match(BehaviorParser::T__5);
    setState(129);
    match(BehaviorParser::STATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Met_GoalContext ------------------------------------------------------------------

BehaviorParser::Condition_Met_GoalContext::Condition_Met_GoalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorParser::Condition_Met_GoalContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Met_Goal;
}

antlrcpp::Any BehaviorParser::Condition_Met_GoalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Met_Goal(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Met_GoalContext* BehaviorParser::condition_Met_Goal() {
  Condition_Met_GoalContext *_localctx = _tracker.createInstance<Condition_Met_GoalContext>(_ctx, getState());
  enterRule(_localctx, 20, BehaviorParser::RuleCondition_Met_Goal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(BehaviorParser::T__6);
    setState(133);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::T__7) {
      setState(132);
      match(BehaviorParser::T__7);
    }
    setState(135);
    match(BehaviorParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Time_Elapsed_From_EventContext ------------------------------------------------------------------

BehaviorParser::Condition_Time_Elapsed_From_EventContext::Condition_Time_Elapsed_From_EventContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::NUMBER() {
  return getToken(BehaviorParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}


size_t BehaviorParser::Condition_Time_Elapsed_From_EventContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Time_Elapsed_From_Event;
}

antlrcpp::Any BehaviorParser::Condition_Time_Elapsed_From_EventContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Time_Elapsed_From_Event(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Time_Elapsed_From_EventContext* BehaviorParser::condition_Time_Elapsed_From_Event() {
  Condition_Time_Elapsed_From_EventContext *_localctx = _tracker.createInstance<Condition_Time_Elapsed_From_EventContext>(_ctx, getState());
  enterRule(_localctx, 22, BehaviorParser::RuleCondition_Time_Elapsed_From_Event);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(BehaviorParser::T__9);
    setState(138);
    match(BehaviorParser::NUMBER);
    setState(139);
    match(BehaviorParser::T__10);
    setState(140);
    match(BehaviorParser::EVENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_EventContext ------------------------------------------------------------------

BehaviorParser::Condition_EventContext::Condition_EventContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_EventContext::GIVEN() {
  return getToken(BehaviorParser::GIVEN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_EventContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_EventContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}


size_t BehaviorParser::Condition_EventContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Event;
}

antlrcpp::Any BehaviorParser::Condition_EventContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Event(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_EventContext* BehaviorParser::condition_Event() {
  Condition_EventContext *_localctx = _tracker.createInstance<Condition_EventContext>(_ctx, getState());
  enterRule(_localctx, 24, BehaviorParser::RuleCondition_Event);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    match(BehaviorParser::GIVEN);
    setState(144);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN) {
      setState(143);
      match(BehaviorParser::AN);
    }
    setState(146);
    match(BehaviorParser::EVENT);
    setState(147);
    match(BehaviorParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Event_OccurringContext ------------------------------------------------------------------

BehaviorParser::Condition_Event_OccurringContext::Condition_Event_OccurringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::WHILE() {
  return getToken(BehaviorParser::WHILE, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}


size_t BehaviorParser::Condition_Event_OccurringContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Event_Occurring;
}

antlrcpp::Any BehaviorParser::Condition_Event_OccurringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Event_Occurring(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Event_OccurringContext* BehaviorParser::condition_Event_Occurring() {
  Condition_Event_OccurringContext *_localctx = _tracker.createInstance<Condition_Event_OccurringContext>(_ctx, getState());
  enterRule(_localctx, 26, BehaviorParser::RuleCondition_Event_Occurring);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(BehaviorParser::WHILE);
    setState(151);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN) {
      setState(150);
      match(BehaviorParser::AN);
    }
    setState(153);
    match(BehaviorParser::EVENT);
    setState(154);
    match(BehaviorParser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- State_CheckContext ------------------------------------------------------------------

BehaviorParser::State_CheckContext::State_CheckContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::State_CheckContext::STATE() {
  return getToken(BehaviorParser::STATE, 0);
}


size_t BehaviorParser::State_CheckContext::getRuleIndex() const {
  return BehaviorParser::RuleState_Check;
}

antlrcpp::Any BehaviorParser::State_CheckContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitState_Check(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::State_CheckContext* BehaviorParser::state_Check() {
  State_CheckContext *_localctx = _tracker.createInstance<State_CheckContext>(_ctx, getState());
  enterRule(_localctx, 28, BehaviorParser::RuleState_Check);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(BehaviorParser::T__4);
    setState(157);
    match(BehaviorParser::STATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- State_SetContext ------------------------------------------------------------------

BehaviorParser::State_SetContext::State_SetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::State_SetContext::STATE() {
  return getToken(BehaviorParser::STATE, 0);
}


size_t BehaviorParser::State_SetContext::getRuleIndex() const {
  return BehaviorParser::RuleState_Set;
}

antlrcpp::Any BehaviorParser::State_SetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitState_Set(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::State_SetContext* BehaviorParser::state_Set() {
  State_SetContext *_localctx = _tracker.createInstance<State_SetContext>(_ctx, getState());
  enterRule(_localctx, 30, BehaviorParser::RuleState_Set);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(BehaviorParser::T__13);
    setState(160);
    match(BehaviorParser::STATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

BehaviorParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorParser::ObjectContext::getRuleIndex() const {
  return BehaviorParser::RuleObject;
}

antlrcpp::Any BehaviorParser::ObjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitObject(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::ObjectContext* BehaviorParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 32, BehaviorParser::RuleObject);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::T__14

    || _la == BehaviorParser::T__15)) {
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
  enterRule(_localctx, 34, BehaviorParser::RulePed_Selector);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(167);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::T__16: {
        enterOuterAlt(_localctx, 1);
        setState(164);
        selector_Percent();
        break;
      }

      case BehaviorParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(165);
        selector_Exactly_N_Random();
        break;
      }

      case BehaviorParser::T__21: {
        enterOuterAlt(_localctx, 3);
        setState(166);
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

tree::TerminalNode* BehaviorParser::Selector_PercentContext::NUMBER() {
  return getToken(BehaviorParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorParser::Selector_PercentContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Selector_PercentContext::ID() {
  return getToken(BehaviorParser::ID, 0);
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
  enterRule(_localctx, 36, BehaviorParser::RuleSelector_Percent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    match(BehaviorParser::T__16);
    setState(170);
    match(BehaviorParser::NUMBER);
    setState(171);
    match(BehaviorParser::T__17);
    setState(172);
    match(BehaviorParser::AN);
    setState(173);
    match(BehaviorParser::ID);
    setState(174);
    match(BehaviorParser::T__1);
   
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

tree::TerminalNode* BehaviorParser::Selector_Exactly_N_RandomContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Selector_Exactly_N_RandomContext::ID() {
  return getToken(BehaviorParser::ID, 0);
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
  enterRule(_localctx, 38, BehaviorParser::RuleSelector_Exactly_N_Random);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(BehaviorParser::T__18);
    setState(177);
    match(BehaviorParser::NUMBER);
    setState(178);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::T__19

    || _la == BehaviorParser::T__20)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(179);
    match(BehaviorParser::AN);
    setState(180);
    match(BehaviorParser::ID);
    setState(181);
    match(BehaviorParser::T__1);
   
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

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::ID() {
  return getToken(BehaviorParser::ID, 0);
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
  enterRule(_localctx, 40, BehaviorParser::RuleSelector_Everyone);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(BehaviorParser::T__21);
    setState(184);
    match(BehaviorParser::AN);
    setState(185);
    match(BehaviorParser::ID);
    setState(186);
    match(BehaviorParser::T__1);
   
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

BehaviorParser::Un_conditional_actionContext* BehaviorParser::ActionContext::un_conditional_action() {
  return getRuleContext<BehaviorParser::Un_conditional_actionContext>(0);
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
  enterRule(_localctx, 42, BehaviorParser::RuleAction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(190);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(188);
      conditional_action();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(189);
      un_conditional_action();
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

//----------------- Conditional_actionContext ------------------------------------------------------------------

BehaviorParser::Conditional_actionContext::Conditional_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Conditional_actionContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Conditional_actionContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

BehaviorParser::Sub_actionContext* BehaviorParser::Conditional_actionContext::sub_action() {
  return getRuleContext<BehaviorParser::Sub_actionContext>(0);
}

BehaviorParser::ConditionContext* BehaviorParser::Conditional_actionContext::condition() {
  return getRuleContext<BehaviorParser::ConditionContext>(0);
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
  enterRule(_localctx, 44, BehaviorParser::RuleConditional_action);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(BehaviorParser::AN);
    setState(193);
    match(BehaviorParser::ID);
    setState(194);
    match(BehaviorParser::T__22);
    setState(195);
    sub_action();
    setState(196);
    condition();
    setState(197);
    match(BehaviorParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Un_conditional_actionContext ------------------------------------------------------------------

BehaviorParser::Un_conditional_actionContext::Un_conditional_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Un_conditional_actionContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Un_conditional_actionContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

BehaviorParser::Sub_actionContext* BehaviorParser::Un_conditional_actionContext::sub_action() {
  return getRuleContext<BehaviorParser::Sub_actionContext>(0);
}


size_t BehaviorParser::Un_conditional_actionContext::getRuleIndex() const {
  return BehaviorParser::RuleUn_conditional_action;
}

antlrcpp::Any BehaviorParser::Un_conditional_actionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitUn_conditional_action(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Un_conditional_actionContext* BehaviorParser::un_conditional_action() {
  Un_conditional_actionContext *_localctx = _tracker.createInstance<Un_conditional_actionContext>(_ctx, getState());
  enterRule(_localctx, 46, BehaviorParser::RuleUn_conditional_action);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(BehaviorParser::AN);
    setState(200);
    match(BehaviorParser::ID);
    setState(201);
    match(BehaviorParser::T__23);
    setState(202);
    sub_action();
    setState(203);
    match(BehaviorParser::T__1);
   
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

std::vector<BehaviorParser::Action_atomContext *> BehaviorParser::Sub_actionContext::action_atom() {
  return getRuleContexts<BehaviorParser::Action_atomContext>();
}

BehaviorParser::Action_atomContext* BehaviorParser::Sub_actionContext::action_atom(size_t i) {
  return getRuleContext<BehaviorParser::Action_atomContext>(i);
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
  enterRule(_localctx, 48, BehaviorParser::RuleSub_action);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    action_atom();
    setState(210);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::T__24) {
      setState(206);
      match(BehaviorParser::T__24);
      setState(207);
      action_atom();
      setState(212);
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

//----------------- Action_atomContext ------------------------------------------------------------------

BehaviorParser::Action_atomContext::Action_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Action_atomContext::ACTION() {
  return getToken(BehaviorParser::ACTION, 0);
}

BehaviorParser::State_SetContext* BehaviorParser::Action_atomContext::state_Set() {
  return getRuleContext<BehaviorParser::State_SetContext>(0);
}

BehaviorParser::Action_StopContext* BehaviorParser::Action_atomContext::action_Stop() {
  return getRuleContext<BehaviorParser::Action_StopContext>(0);
}

BehaviorParser::Action_atom_Percent_Walk_SpeedContext* BehaviorParser::Action_atomContext::action_atom_Percent_Walk_Speed() {
  return getRuleContext<BehaviorParser::Action_atom_Percent_Walk_SpeedContext>(0);
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
  enterRule(_localctx, 50, BehaviorParser::RuleAction_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(217);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::ACTION: {
        enterOuterAlt(_localctx, 1);
        setState(213);
        match(BehaviorParser::ACTION);
        break;
      }

      case BehaviorParser::T__13: {
        enterOuterAlt(_localctx, 2);
        setState(214);
        state_Set();
        break;
      }

      case BehaviorParser::T__25: {
        enterOuterAlt(_localctx, 3);
        setState(215);
        action_Stop();
        break;
      }

      case BehaviorParser::T__26: {
        enterOuterAlt(_localctx, 4);
        setState(216);
        action_atom_Percent_Walk_Speed();
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
  enterRule(_localctx, 52, BehaviorParser::RuleAction_Stop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    match(BehaviorParser::T__25);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_atom_Percent_Walk_SpeedContext ------------------------------------------------------------------

BehaviorParser::Action_atom_Percent_Walk_SpeedContext::Action_atom_Percent_Walk_SpeedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Action_atom_Percent_Walk_SpeedContext::NUMBER() {
  return getToken(BehaviorParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorParser::Action_atom_Percent_Walk_SpeedContext::FASTERorSLOWER() {
  return getToken(BehaviorParser::FASTERorSLOWER, 0);
}


size_t BehaviorParser::Action_atom_Percent_Walk_SpeedContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_atom_Percent_Walk_Speed;
}

antlrcpp::Any BehaviorParser::Action_atom_Percent_Walk_SpeedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_atom_Percent_Walk_Speed(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_atom_Percent_Walk_SpeedContext* BehaviorParser::action_atom_Percent_Walk_Speed() {
  Action_atom_Percent_Walk_SpeedContext *_localctx = _tracker.createInstance<Action_atom_Percent_Walk_SpeedContext>(_ctx, getState());
  enterRule(_localctx, 54, BehaviorParser::RuleAction_atom_Percent_Walk_Speed);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(BehaviorParser::T__26);
    setState(222);
    match(BehaviorParser::NUMBER);
    setState(223);
    match(BehaviorParser::T__27);
    setState(224);
    match(BehaviorParser::FASTERorSLOWER);
   
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

BehaviorParser::Decl_ParametersContext* BehaviorParser::DeclarationContext::decl_Parameters() {
  return getRuleContext<BehaviorParser::Decl_ParametersContext>(0);
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
  enterRule(_localctx, 56, BehaviorParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(230);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::T__28: {
        enterOuterAlt(_localctx, 1);
        setState(226);
        decl_Ped();
        break;
      }

      case BehaviorParser::T__29: {
        enterOuterAlt(_localctx, 2);
        setState(227);
        decl_Ped_State();
        break;
      }

      case BehaviorParser::T__30: {
        enterOuterAlt(_localctx, 3);
        setState(228);
        decl_Env_State();
        break;
      }

      case BehaviorParser::PARAMETERS: {
        enterOuterAlt(_localctx, 4);
        setState(229);
        decl_Parameters();
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

tree::TerminalNode* BehaviorParser::Decl_PedContext::AN() {
  return getToken(BehaviorParser::AN, 0);
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
  enterRule(_localctx, 58, BehaviorParser::RuleDecl_Ped);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(BehaviorParser::T__28);
    setState(233);
    match(BehaviorParser::AN);
    setState(234);
    match(BehaviorParser::ID);
    setState(235);
    match(BehaviorParser::T__1);
   
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

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Ped_StateContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
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
  enterRule(_localctx, 60, BehaviorParser::RuleDecl_Ped_State);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    match(BehaviorParser::T__29);

    setState(238);
    match(BehaviorParser::ID);
    setState(243);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::COMMA) {
      setState(239);
      match(BehaviorParser::COMMA);
      setState(240);
      match(BehaviorParser::ID);
      setState(245);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(246);
    match(BehaviorParser::T__1);
   
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

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Env_StateContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
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
  enterRule(_localctx, 62, BehaviorParser::RuleDecl_Env_State);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(BehaviorParser::T__30);

    setState(249);
    match(BehaviorParser::ID);
    setState(254);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::COMMA) {
      setState(250);
      match(BehaviorParser::COMMA);
      setState(251);
      match(BehaviorParser::ID);
      setState(256);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(257);
    match(BehaviorParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decl_ParametersContext ------------------------------------------------------------------

BehaviorParser::Decl_ParametersContext::Decl_ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Decl_ParametersContext::PARAMETERS() {
  return getToken(BehaviorParser::PARAMETERS, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_ParametersContext::PARAMETER() {
  return getTokens(BehaviorParser::PARAMETER);
}

tree::TerminalNode* BehaviorParser::Decl_ParametersContext::PARAMETER(size_t i) {
  return getToken(BehaviorParser::PARAMETER, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_ParametersContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Decl_ParametersContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
}


size_t BehaviorParser::Decl_ParametersContext::getRuleIndex() const {
  return BehaviorParser::RuleDecl_Parameters;
}

antlrcpp::Any BehaviorParser::Decl_ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDecl_Parameters(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Decl_ParametersContext* BehaviorParser::decl_Parameters() {
  Decl_ParametersContext *_localctx = _tracker.createInstance<Decl_ParametersContext>(_ctx, getState());
  enterRule(_localctx, 64, BehaviorParser::RuleDecl_Parameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(BehaviorParser::PARAMETERS);

    setState(260);
    match(BehaviorParser::PARAMETER);
    setState(265);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::COMMA) {
      setState(261);
      match(BehaviorParser::COMMA);
      setState(262);
      match(BehaviorParser::PARAMETER);
      setState(267);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(268);
    match(BehaviorParser::T__1);
   
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
  "program", "statement", "event", "event_Single", "event_Lasting", "condition", 
  "sub_condition", "condition_Existance", "condition_State", "condition_Others_State", 
  "condition_Met_Goal", "condition_Time_Elapsed_From_Event", "condition_Event", 
  "condition_Event_Occurring", "state_Check", "state_Set", "object", "ped_Selector", 
  "selector_Percent", "selector_Exactly_N_Random", "selector_Everyone", 
  "action", "conditional_action", "un_conditional_action", "sub_action", 
  "action_atom", "action_Stop", "action_atom_Percent_Walk_Speed", "declaration", 
  "decl_Ped", "decl_Ped_State", "decl_Env_State", "decl_Parameters"
};

std::vector<std::string> BehaviorParser::_literalNames = {
  "", "'event will occur'", "'.'", "'and end'", "'There is'", "'is'", "'That is'", 
  "'That has '", "'not '", "'met any goal'", "'after'", "'seconds from'", 
  "'event has occurred'", "'event is occurring'", "'be'", "'The Environment'", 
  "'Pedestrian'", "'A Random'", "'% of Pedestrians are'", "'Exactly'", "'random pedestrians are'", 
  "'random pedestrian is'", "'Everyone is'", "'will'", "'will always'", 
  "'then'", "'@stop'", "'@walk'", "'%'", "'Consider'", "'Possible Pedestrian States Are:'", 
  "'Possible Environment States Are:'", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "','", "':'"
};

std::vector<std::string> BehaviorParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", "STATE", 
  "ACTION", "ATTRIBUTE", "PARAMETER", "EVENT", "NUMBER", "COMMENT", "LINE_COMMENT", 
  "WS", "AN", "AND", "OR", "ANDOR", "COMMA", "COLON", "THE", "GIVEN", "SET", 
  "WHILE", "PARAMETERS", "FASTERorSLOWER", "Direction"
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
    0x3, 0x38, 0x111, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x3, 0x2, 0x6, 0x2, 0x46, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x47, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x4e, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x52, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0x65, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x68, 0xb, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x6f, 0xa, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x7c, 0xa, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x88, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 
    0xe, 0x93, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x5, 0xf, 0x9a, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xaa, 0xa, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 
    0x17, 0x5, 0x17, 0xc1, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 
    0x1a, 0xd3, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0xd6, 0xb, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0xdc, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0xe9, 0xa, 0x1e, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0xf4, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 
    0xf7, 0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x7, 0x21, 0xff, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x102, 
    0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x7, 0x22, 0x10a, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x10d, 0xb, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x2, 0x2, 0x23, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x2, 0x4, 0x3, 0x2, 0x11, 0x12, 
    0x3, 0x2, 0x16, 0x17, 0x2, 0x10a, 0x2, 0x45, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x6, 0x51, 0x3, 0x2, 0x2, 0x2, 0x8, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x59, 0x3, 0x2, 0x2, 0x2, 0xc, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x14, 0x82, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x85, 0x3, 0x2, 0x2, 0x2, 0x18, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x97, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x22, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x26, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xb2, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x32, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0xdb, 0x3, 0x2, 0x2, 0x2, 0x36, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x38, 0xdf, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x3c, 0xea, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0xef, 0x3, 0x2, 0x2, 0x2, 0x40, 0xfa, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x105, 0x3, 0x2, 0x2, 0x2, 0x44, 0x46, 0x5, 0x4, 0x3, 
    0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4e, 0x5, 0x6, 0x4, 0x2, 0x4a, 0x4e, 
    0x5, 0x3a, 0x1e, 0x2, 0x4b, 0x4e, 0x5, 0x24, 0x13, 0x2, 0x4c, 0x4e, 
    0x5, 0x2c, 0x17, 0x2, 0x4d, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x52, 0x5, 0x8, 0x5, 
    0x2, 0x50, 0x52, 0x5, 0xa, 0x6, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x7, 0x3, 0x2, 0x2, 0x2, 0x53, 
    0x54, 0x7, 0x2c, 0x2, 0x2, 0x54, 0x55, 0x7, 0x27, 0x2, 0x2, 0x55, 0x56, 
    0x7, 0x3, 0x2, 0x2, 0x56, 0x57, 0x5, 0xc, 0x7, 0x2, 0x57, 0x58, 0x7, 
    0x4, 0x2, 0x2, 0x58, 0x9, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x2c, 
    0x2, 0x2, 0x5a, 0x5b, 0x7, 0x27, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x3, 0x2, 
    0x2, 0x5c, 0x5d, 0x5, 0xc, 0x7, 0x2, 0x5d, 0x5e, 0x7, 0x5, 0x2, 0x2, 
    0x5e, 0x5f, 0x5, 0xc, 0x7, 0x2, 0x5f, 0x60, 0x7, 0x4, 0x2, 0x2, 0x60, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x61, 0x66, 0x5, 0xe, 0x8, 0x2, 0x62, 0x63, 
    0x7, 0x2f, 0x2, 0x2, 0x63, 0x65, 0x5, 0xe, 0x8, 0x2, 0x64, 0x62, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x68, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6f, 0x5, 0x12, 0xa, 0x2, 
    0x6a, 0x6f, 0x5, 0x18, 0xd, 0x2, 0x6b, 0x6f, 0x5, 0x10, 0x9, 0x2, 0x6c, 
    0x6f, 0x5, 0x1a, 0xe, 0x2, 0x6d, 0x6f, 0x5, 0x1c, 0xf, 0x2, 0x6e, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6b, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x6f, 0xf, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0x33, 0x2, 
    0x2, 0x71, 0x72, 0x7, 0x6, 0x2, 0x2, 0x72, 0x73, 0x7, 0x2c, 0x2, 0x2, 
    0x73, 0x74, 0x7, 0x22, 0x2, 0x2, 0x74, 0x7c, 0x7, 0x38, 0x2, 0x2, 0x75, 
    0x76, 0x7, 0x33, 0x2, 0x2, 0x76, 0x77, 0x7, 0x6, 0x2, 0x2, 0x77, 0x78, 
    0x7, 0x2c, 0x2, 0x2, 0x78, 0x79, 0x7, 0x22, 0x2, 0x2, 0x79, 0x7a, 0x7, 
    0x38, 0x2, 0x2, 0x7a, 0x7c, 0x5, 0x14, 0xb, 0x2, 0x7b, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0x7b, 0x75, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x7d, 0x7e, 0x7, 0x33, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0x22, 0x12, 0x2, 
    0x7f, 0x80, 0x7, 0x7, 0x2, 0x2, 0x80, 0x81, 0x7, 0x23, 0x2, 0x2, 0x81, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 0x8, 0x2, 0x2, 0x83, 0x84, 
    0x7, 0x23, 0x2, 0x2, 0x84, 0x15, 0x3, 0x2, 0x2, 0x2, 0x85, 0x87, 0x7, 
    0x9, 0x2, 0x2, 0x86, 0x88, 0x7, 0xa, 0x2, 0x2, 0x87, 0x86, 0x3, 0x2, 
    0x2, 0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 
    0x2, 0x89, 0x8a, 0x7, 0xb, 0x2, 0x2, 0x8a, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x8b, 0x8c, 0x7, 0xc, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x28, 0x2, 0x2, 0x8d, 
    0x8e, 0x7, 0xd, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x27, 0x2, 0x2, 0x8f, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x92, 0x7, 0x33, 0x2, 0x2, 0x91, 0x93, 0x7, 
    0x2c, 0x2, 0x2, 0x92, 0x91, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x7, 0x27, 0x2, 
    0x2, 0x95, 0x96, 0x7, 0xe, 0x2, 0x2, 0x96, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x99, 0x7, 0x35, 0x2, 0x2, 0x98, 0x9a, 0x7, 0x2c, 0x2, 0x2, 0x99, 
    0x98, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x27, 0x2, 0x2, 0x9c, 0x9d, 0x7, 
    0xf, 0x2, 0x2, 0x9d, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x7, 
    0x2, 0x2, 0x9f, 0xa0, 0x7, 0x23, 0x2, 0x2, 0xa0, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0xa2, 0x7, 0x10, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x23, 0x2, 0x2, 
    0xa3, 0x21, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x9, 0x2, 0x2, 0x2, 0xa5, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xaa, 0x5, 0x26, 0x14, 0x2, 0xa7, 0xaa, 
    0x5, 0x28, 0x15, 0x2, 0xa8, 0xaa, 0x5, 0x2a, 0x16, 0x2, 0xa9, 0xa6, 
    0x3, 0x2, 0x2, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa8, 0x3, 
    0x2, 0x2, 0x2, 0xaa, 0x25, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x7, 0x13, 
    0x2, 0x2, 0xac, 0xad, 0x7, 0x28, 0x2, 0x2, 0xad, 0xae, 0x7, 0x14, 0x2, 
    0x2, 0xae, 0xaf, 0x7, 0x2c, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x22, 0x2, 0x2, 
    0xb0, 0xb1, 0x7, 0x4, 0x2, 0x2, 0xb1, 0x27, 0x3, 0x2, 0x2, 0x2, 0xb2, 
    0xb3, 0x7, 0x15, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x28, 0x2, 0x2, 0xb4, 0xb5, 
    0x9, 0x3, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x2c, 0x2, 0x2, 0xb6, 0xb7, 0x7, 
    0x22, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x4, 0x2, 0x2, 0xb8, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xba, 0x7, 0x18, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x2c, 0x2, 
    0x2, 0xbb, 0xbc, 0x7, 0x22, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x4, 0x2, 0x2, 
    0xbd, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc1, 0x5, 0x2e, 0x18, 0x2, 0xbf, 
    0xc1, 0x5, 0x30, 0x19, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x7, 
    0x2c, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x22, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x19, 
    0x2, 0x2, 0xc5, 0xc6, 0x5, 0x32, 0x1a, 0x2, 0xc6, 0xc7, 0x5, 0xc, 0x7, 
    0x2, 0xc7, 0xc8, 0x7, 0x4, 0x2, 0x2, 0xc8, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0xc9, 0xca, 0x7, 0x2c, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x22, 0x2, 0x2, 0xcb, 
    0xcc, 0x7, 0x1a, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x32, 0x1a, 0x2, 0xcd, 0xce, 
    0x7, 0x4, 0x2, 0x2, 0xce, 0x31, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd4, 0x5, 
    0x34, 0x1b, 0x2, 0xd0, 0xd1, 0x7, 0x1b, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0x34, 
    0x1b, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd6, 0x3, 0x2, 0x2, 
    0x2, 0xd4, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0xd5, 0x33, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd7, 
    0xdc, 0x7, 0x24, 0x2, 0x2, 0xd8, 0xdc, 0x5, 0x20, 0x11, 0x2, 0xd9, 0xdc, 
    0x5, 0x36, 0x1c, 0x2, 0xda, 0xdc, 0x5, 0x38, 0x1d, 0x2, 0xdb, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 
    0x2, 0x2, 0x2, 0xdb, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0xdd, 0xde, 0x7, 0x1c, 0x2, 0x2, 0xde, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0xdf, 0xe0, 0x7, 0x1d, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x28, 0x2, 0x2, 
    0xe1, 0xe2, 0x7, 0x1e, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x37, 0x2, 0x2, 0xe3, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe9, 0x5, 0x3c, 0x1f, 0x2, 0xe5, 0xe9, 
    0x5, 0x3e, 0x20, 0x2, 0xe6, 0xe9, 0x5, 0x40, 0x21, 0x2, 0xe7, 0xe9, 
    0x5, 0x42, 0x22, 0x2, 0xe8, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe5, 0x3, 
    0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe7, 0x3, 0x2, 
    0x2, 0x2, 0xe9, 0x3b, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x1f, 0x2, 
    0x2, 0xeb, 0xec, 0x7, 0x2c, 0x2, 0x2, 0xec, 0xed, 0x7, 0x22, 0x2, 0x2, 
    0xed, 0xee, 0x7, 0x4, 0x2, 0x2, 0xee, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xef, 
    0xf0, 0x7, 0x20, 0x2, 0x2, 0xf0, 0xf5, 0x7, 0x22, 0x2, 0x2, 0xf1, 0xf2, 
    0x7, 0x30, 0x2, 0x2, 0xf2, 0xf4, 0x7, 0x22, 0x2, 0x2, 0xf3, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xf4, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 
    0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x4, 0x2, 0x2, 
    0xf9, 0x3f, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x21, 0x2, 0x2, 0xfb, 
    0x100, 0x7, 0x22, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x30, 0x2, 0x2, 0xfd, 0xff, 
    0x7, 0x22, 0x2, 0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xff, 0x102, 0x3, 
    0x2, 0x2, 0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x3, 0x2, 
    0x2, 0x2, 0x101, 0x103, 0x3, 0x2, 0x2, 0x2, 0x102, 0x100, 0x3, 0x2, 
    0x2, 0x2, 0x103, 0x104, 0x7, 0x4, 0x2, 0x2, 0x104, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x105, 0x106, 0x7, 0x36, 0x2, 0x2, 0x106, 0x10b, 0x7, 0x26, 0x2, 
    0x2, 0x107, 0x108, 0x7, 0x30, 0x2, 0x2, 0x108, 0x10a, 0x7, 0x26, 0x2, 
    0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10d, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 
    0x2, 0x10e, 0x10f, 0x7, 0x4, 0x2, 0x2, 0x10f, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x13, 0x47, 0x4d, 0x51, 0x66, 0x6e, 0x7b, 0x87, 0x92, 0x99, 0xa9, 0xc0, 
    0xd4, 0xdb, 0xe8, 0xf5, 0x100, 0x10b, 
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
