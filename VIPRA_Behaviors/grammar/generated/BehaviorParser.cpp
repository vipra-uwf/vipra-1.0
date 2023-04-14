
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
    setState(81); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(80);
      statement();
      setState(83); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 22) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 22)) & ((1ULL << (BehaviorParser::AN - 22))
      | (1ULL << (BehaviorParser::CONSIDER - 22))
      | (1ULL << (BehaviorParser::EXACTLY - 22))
      | (1ULL << (BehaviorParser::EVERYONE - 22))
      | (1ULL << (BehaviorParser::POSSIBLE - 22))
      | (1ULL << (BehaviorParser::THE - 22))
      | (1ULL << (BehaviorParser::NUMBER - 22)))) != 0));
   
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
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(85);
      event();
      setState(86);
      match(BehaviorParser::T__0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(88);
      declaration();
      setState(89);
      match(BehaviorParser::T__0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(91);
      ped_Selector();
      setState(92);
      match(BehaviorParser::T__0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(94);
      action();
      setState(95);
      match(BehaviorParser::T__0);
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
    setState(101);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(99);
      event_Single();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(100);
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

tree::TerminalNode* BehaviorParser::Event_SingleContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::WILL() {
  return getToken(BehaviorParser::WILL, 0);
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::OCCUR() {
  return getToken(BehaviorParser::OCCUR, 0);
}

BehaviorParser::ConditionContext* BehaviorParser::Event_SingleContext::condition() {
  return getRuleContext<BehaviorParser::ConditionContext>(0);
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::THE() {
  return getToken(BehaviorParser::THE, 0);
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::AN

    || _la == BehaviorParser::THE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(104);
    match(BehaviorParser::EVNT);
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(105);
      match(BehaviorParser::EVENT);
    }
    setState(108);
    match(BehaviorParser::WILL);
    setState(109);
    match(BehaviorParser::OCCUR);
    setState(110);
    condition();
   
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

tree::TerminalNode* BehaviorParser::Event_LastingContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::WILL() {
  return getToken(BehaviorParser::WILL, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::OCCUR() {
  return getToken(BehaviorParser::OCCUR, 0);
}

std::vector<BehaviorParser::ConditionContext *> BehaviorParser::Event_LastingContext::condition() {
  return getRuleContexts<BehaviorParser::ConditionContext>();
}

BehaviorParser::ConditionContext* BehaviorParser::Event_LastingContext::condition(size_t i) {
  return getRuleContext<BehaviorParser::ConditionContext>(i);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::AND() {
  return getToken(BehaviorParser::AND, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::END() {
  return getToken(BehaviorParser::END, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::THE() {
  return getToken(BehaviorParser::THE, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::AN

    || _la == BehaviorParser::THE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(113);
    match(BehaviorParser::EVNT);
    setState(115);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(114);
      match(BehaviorParser::EVENT);
    }
    setState(117);
    match(BehaviorParser::WILL);
    setState(118);
    match(BehaviorParser::OCCUR);
    setState(119);
    condition();
    setState(120);
    match(BehaviorParser::AND);
    setState(121);
    match(BehaviorParser::END);
    setState(122);
    condition();
   
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

BehaviorParser::Sub_conditionContext* BehaviorParser::ConditionContext::sub_condition() {
  return getRuleContext<BehaviorParser::Sub_conditionContext>(0);
}

std::vector<BehaviorParser::ConnectorContext *> BehaviorParser::ConditionContext::connector() {
  return getRuleContexts<BehaviorParser::ConnectorContext>();
}

BehaviorParser::ConnectorContext* BehaviorParser::ConditionContext::connector(size_t i) {
  return getRuleContext<BehaviorParser::ConnectorContext>(i);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(124);
    sub_condition();
    setState(128);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(125);
        connector(); 
      }
      setState(130);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConnectorContext ------------------------------------------------------------------

BehaviorParser::ConnectorContext::ConnectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Or_ConnectorContext* BehaviorParser::ConnectorContext::or_Connector() {
  return getRuleContext<BehaviorParser::Or_ConnectorContext>(0);
}

BehaviorParser::And_ConnectorContext* BehaviorParser::ConnectorContext::and_Connector() {
  return getRuleContext<BehaviorParser::And_ConnectorContext>(0);
}


size_t BehaviorParser::ConnectorContext::getRuleIndex() const {
  return BehaviorParser::RuleConnector;
}

antlrcpp::Any BehaviorParser::ConnectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitConnector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::ConnectorContext* BehaviorParser::connector() {
  ConnectorContext *_localctx = _tracker.createInstance<ConnectorContext>(_ctx, getState());
  enterRule(_localctx, 12, BehaviorParser::RuleConnector);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::OR: {
        enterOuterAlt(_localctx, 1);
        setState(131);
        or_Connector();
        break;
      }

      case BehaviorParser::AND: {
        enterOuterAlt(_localctx, 2);
        setState(132);
        and_Connector();
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

//----------------- Or_ConnectorContext ------------------------------------------------------------------

BehaviorParser::Or_ConnectorContext::Or_ConnectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Or_ConnectorContext::OR() {
  return getToken(BehaviorParser::OR, 0);
}

BehaviorParser::Sub_conditionContext* BehaviorParser::Or_ConnectorContext::sub_condition() {
  return getRuleContext<BehaviorParser::Sub_conditionContext>(0);
}


size_t BehaviorParser::Or_ConnectorContext::getRuleIndex() const {
  return BehaviorParser::RuleOr_Connector;
}

antlrcpp::Any BehaviorParser::Or_ConnectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitOr_Connector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Or_ConnectorContext* BehaviorParser::or_Connector() {
  Or_ConnectorContext *_localctx = _tracker.createInstance<Or_ConnectorContext>(_ctx, getState());
  enterRule(_localctx, 14, BehaviorParser::RuleOr_Connector);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(BehaviorParser::OR);
    setState(136);
    sub_condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- And_ConnectorContext ------------------------------------------------------------------

BehaviorParser::And_ConnectorContext::And_ConnectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::And_ConnectorContext::AND() {
  return getToken(BehaviorParser::AND, 0);
}

BehaviorParser::Sub_conditionContext* BehaviorParser::And_ConnectorContext::sub_condition() {
  return getRuleContext<BehaviorParser::Sub_conditionContext>(0);
}


size_t BehaviorParser::And_ConnectorContext::getRuleIndex() const {
  return BehaviorParser::RuleAnd_Connector;
}

antlrcpp::Any BehaviorParser::And_ConnectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAnd_Connector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::And_ConnectorContext* BehaviorParser::and_Connector() {
  And_ConnectorContext *_localctx = _tracker.createInstance<And_ConnectorContext>(_ctx, getState());
  enterRule(_localctx, 16, BehaviorParser::RuleAnd_Connector);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    match(BehaviorParser::AND);
    setState(139);
    sub_condition();
   
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

BehaviorParser::Condition_Time_Elapsed_From_EventContext* BehaviorParser::Sub_conditionContext::condition_Time_Elapsed_From_Event() {
  return getRuleContext<BehaviorParser::Condition_Time_Elapsed_From_EventContext>(0);
}

BehaviorParser::Condition_Event_OccurredContext* BehaviorParser::Sub_conditionContext::condition_Event_Occurred() {
  return getRuleContext<BehaviorParser::Condition_Event_OccurredContext>(0);
}

BehaviorParser::Condition_Event_OccurringContext* BehaviorParser::Sub_conditionContext::condition_Event_Occurring() {
  return getRuleContext<BehaviorParser::Condition_Event_OccurringContext>(0);
}

BehaviorParser::Condition_Event_One_TimeContext* BehaviorParser::Sub_conditionContext::condition_Event_One_Time() {
  return getRuleContext<BehaviorParser::Condition_Event_One_TimeContext>(0);
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
  enterRule(_localctx, 18, BehaviorParser::RuleSub_condition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(145);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::AFTER: {
        enterOuterAlt(_localctx, 1);
        setState(141);
        condition_Time_Elapsed_From_Event();
        break;
      }

      case BehaviorParser::GIVEN: {
        enterOuterAlt(_localctx, 2);
        setState(142);
        condition_Event_Occurred();
        break;
      }

      case BehaviorParser::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(143);
        condition_Event_Occurring();
        break;
      }

      case BehaviorParser::WHEN: {
        enterOuterAlt(_localctx, 4);
        setState(144);
        condition_Event_One_Time();
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

//----------------- Condition_Time_Elapsed_From_EventContext ------------------------------------------------------------------

BehaviorParser::Condition_Time_Elapsed_From_EventContext::Condition_Time_Elapsed_From_EventContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::AFTER() {
  return getToken(BehaviorParser::AFTER, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::NUMBER() {
  return getToken(BehaviorParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::SECONDS() {
  return getToken(BehaviorParser::SECONDS, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::FROM() {
  return getToken(BehaviorParser::FROM, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::THE() {
  return getToken(BehaviorParser::THE, 0);
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
  enterRule(_localctx, 20, BehaviorParser::RuleCondition_Time_Elapsed_From_Event);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(BehaviorParser::AFTER);
    setState(148);
    match(BehaviorParser::NUMBER);
    setState(149);
    match(BehaviorParser::SECONDS);
    setState(150);
    match(BehaviorParser::FROM);
    setState(152);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THE) {
      setState(151);
      _la = _input->LA(1);
      if (!(_la == BehaviorParser::AN

      || _la == BehaviorParser::THE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(154);
    match(BehaviorParser::EVNT);
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(155);
      match(BehaviorParser::EVENT);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Event_OccurredContext ------------------------------------------------------------------

BehaviorParser::Condition_Event_OccurredContext::Condition_Event_OccurredContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::GIVEN() {
  return getToken(BehaviorParser::GIVEN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::HAS() {
  return getToken(BehaviorParser::HAS, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::OCCURRED() {
  return getToken(BehaviorParser::OCCURRED, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::THE() {
  return getToken(BehaviorParser::THE, 0);
}


size_t BehaviorParser::Condition_Event_OccurredContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Event_Occurred;
}

antlrcpp::Any BehaviorParser::Condition_Event_OccurredContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Event_Occurred(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Event_OccurredContext* BehaviorParser::condition_Event_Occurred() {
  Condition_Event_OccurredContext *_localctx = _tracker.createInstance<Condition_Event_OccurredContext>(_ctx, getState());
  enterRule(_localctx, 22, BehaviorParser::RuleCondition_Event_Occurred);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    match(BehaviorParser::GIVEN);
    setState(160);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THE) {
      setState(159);
      _la = _input->LA(1);
      if (!(_la == BehaviorParser::AN

      || _la == BehaviorParser::THE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(162);
    match(BehaviorParser::EVNT);
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(163);
      match(BehaviorParser::EVENT);
    }
    setState(166);
    match(BehaviorParser::HAS);
    setState(167);
    match(BehaviorParser::OCCURRED);
   
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

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::IS() {
  return getToken(BehaviorParser::IS, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::OCCURRING() {
  return getToken(BehaviorParser::OCCURRING, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::THEN() {
  return getToken(BehaviorParser::THEN, 0);
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
  enterRule(_localctx, 24, BehaviorParser::RuleCondition_Event_Occurring);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    match(BehaviorParser::WHILE);
    setState(171);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THEN) {
      setState(170);
      _la = _input->LA(1);
      if (!(_la == BehaviorParser::AN

      || _la == BehaviorParser::THEN)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(173);
    match(BehaviorParser::EVNT);
    setState(175);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(174);
      match(BehaviorParser::EVENT);
    }
    setState(177);
    match(BehaviorParser::IS);
    setState(178);
    match(BehaviorParser::OCCURRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Event_One_TimeContext ------------------------------------------------------------------

BehaviorParser::Condition_Event_One_TimeContext::Condition_Event_One_TimeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::WHEN() {
  return getToken(BehaviorParser::WHEN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::ENDS() {
  return getToken(BehaviorParser::ENDS, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::STARTS() {
  return getToken(BehaviorParser::STARTS, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::THEN() {
  return getToken(BehaviorParser::THEN, 0);
}


size_t BehaviorParser::Condition_Event_One_TimeContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Event_One_Time;
}

antlrcpp::Any BehaviorParser::Condition_Event_One_TimeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Event_One_Time(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Event_One_TimeContext* BehaviorParser::condition_Event_One_Time() {
  Condition_Event_One_TimeContext *_localctx = _tracker.createInstance<Condition_Event_One_TimeContext>(_ctx, getState());
  enterRule(_localctx, 26, BehaviorParser::RuleCondition_Event_One_Time);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(BehaviorParser::WHEN);
    setState(182);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THEN) {
      setState(181);
      _la = _input->LA(1);
      if (!(_la == BehaviorParser::AN

      || _la == BehaviorParser::THEN)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(184);
    match(BehaviorParser::EVNT);
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(185);
      match(BehaviorParser::EVENT);
    }
    setState(188);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::ENDS

    || _la == BehaviorParser::STARTS)) {
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

//----------------- DirectionContext ------------------------------------------------------------------

BehaviorParser::DirectionContext::DirectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::DirContext* BehaviorParser::DirectionContext::dir() {
  return getRuleContext<BehaviorParser::DirContext>(0);
}

tree::TerminalNode* BehaviorParser::DirectionContext::WITHIN() {
  return getToken(BehaviorParser::WITHIN, 0);
}

tree::TerminalNode* BehaviorParser::DirectionContext::NUMBER() {
  return getToken(BehaviorParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorParser::DirectionContext::METERS() {
  return getToken(BehaviorParser::METERS, 0);
}


size_t BehaviorParser::DirectionContext::getRuleIndex() const {
  return BehaviorParser::RuleDirection;
}

antlrcpp::Any BehaviorParser::DirectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDirection(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::DirectionContext* BehaviorParser::direction() {
  DirectionContext *_localctx = _tracker.createInstance<DirectionContext>(_ctx, getState());
  enterRule(_localctx, 28, BehaviorParser::RuleDirection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    dir();
    setState(191);
    match(BehaviorParser::WITHIN);
    setState(192);
    match(BehaviorParser::NUMBER);
    setState(193);
    match(BehaviorParser::METERS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirContext ------------------------------------------------------------------

BehaviorParser::DirContext::DirContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Direction_ofContext* BehaviorParser::DirContext::direction_of() {
  return getRuleContext<BehaviorParser::Direction_ofContext>(0);
}

BehaviorParser::InfrontContext* BehaviorParser::DirContext::infront() {
  return getRuleContext<BehaviorParser::InfrontContext>(0);
}

BehaviorParser::BehindContext* BehaviorParser::DirContext::behind() {
  return getRuleContext<BehaviorParser::BehindContext>(0);
}

BehaviorParser::AroundContext* BehaviorParser::DirContext::around() {
  return getRuleContext<BehaviorParser::AroundContext>(0);
}


size_t BehaviorParser::DirContext::getRuleIndex() const {
  return BehaviorParser::RuleDir;
}

antlrcpp::Any BehaviorParser::DirContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDir(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::DirContext* BehaviorParser::dir() {
  DirContext *_localctx = _tracker.createInstance<DirContext>(_ctx, getState());
  enterRule(_localctx, 30, BehaviorParser::RuleDir);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(199);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(195);
      direction_of();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(196);
      infront();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(197);
      behind();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(198);
      around();
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

//----------------- Direction_ofContext ------------------------------------------------------------------

BehaviorParser::Direction_ofContext::Direction_ofContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Direction_ofContext::IN() {
  return getToken(BehaviorParser::IN, 0);
}

tree::TerminalNode* BehaviorParser::Direction_ofContext::DIRECTION() {
  return getToken(BehaviorParser::DIRECTION, 0);
}

tree::TerminalNode* BehaviorParser::Direction_ofContext::OF() {
  return getToken(BehaviorParser::OF, 0);
}

tree::TerminalNode* BehaviorParser::Direction_ofContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}


size_t BehaviorParser::Direction_ofContext::getRuleIndex() const {
  return BehaviorParser::RuleDirection_of;
}

antlrcpp::Any BehaviorParser::Direction_ofContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDirection_of(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Direction_ofContext* BehaviorParser::direction_of() {
  Direction_ofContext *_localctx = _tracker.createInstance<Direction_ofContext>(_ctx, getState());
  enterRule(_localctx, 32, BehaviorParser::RuleDirection_of);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(BehaviorParser::IN);
    setState(202);
    match(BehaviorParser::DIRECTION);
    setState(203);
    match(BehaviorParser::OF);
    setState(204);
    match(BehaviorParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InfrontContext ------------------------------------------------------------------

BehaviorParser::InfrontContext::InfrontContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::InfrontContext::IN() {
  return getToken(BehaviorParser::IN, 0);
}

tree::TerminalNode* BehaviorParser::InfrontContext::FRONT() {
  return getToken(BehaviorParser::FRONT, 0);
}


size_t BehaviorParser::InfrontContext::getRuleIndex() const {
  return BehaviorParser::RuleInfront;
}

antlrcpp::Any BehaviorParser::InfrontContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitInfront(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::InfrontContext* BehaviorParser::infront() {
  InfrontContext *_localctx = _tracker.createInstance<InfrontContext>(_ctx, getState());
  enterRule(_localctx, 34, BehaviorParser::RuleInfront);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    match(BehaviorParser::IN);
    setState(207);
    match(BehaviorParser::FRONT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BehindContext ------------------------------------------------------------------

BehaviorParser::BehindContext::BehindContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::BehindContext::BEHIND() {
  return getToken(BehaviorParser::BEHIND, 0);
}


size_t BehaviorParser::BehindContext::getRuleIndex() const {
  return BehaviorParser::RuleBehind;
}

antlrcpp::Any BehaviorParser::BehindContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitBehind(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::BehindContext* BehaviorParser::behind() {
  BehindContext *_localctx = _tracker.createInstance<BehindContext>(_ctx, getState());
  enterRule(_localctx, 36, BehaviorParser::RuleBehind);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(BehaviorParser::BEHIND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AroundContext ------------------------------------------------------------------

BehaviorParser::AroundContext::AroundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::AroundContext::AROUND() {
  return getToken(BehaviorParser::AROUND, 0);
}


size_t BehaviorParser::AroundContext::getRuleIndex() const {
  return BehaviorParser::RuleAround;
}

antlrcpp::Any BehaviorParser::AroundContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAround(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::AroundContext* BehaviorParser::around() {
  AroundContext *_localctx = _tracker.createInstance<AroundContext>(_ctx, getState());
  enterRule(_localctx, 38, BehaviorParser::RuleAround);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    match(BehaviorParser::AROUND);
   
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

tree::TerminalNode* BehaviorParser::ObjectContext::PEDESTRIAN() {
  return getToken(BehaviorParser::PEDESTRIAN, 0);
}

tree::TerminalNode* BehaviorParser::ObjectContext::OBSTACLE() {
  return getToken(BehaviorParser::OBSTACLE, 0);
}

tree::TerminalNode* BehaviorParser::ObjectContext::OBJECT() {
  return getToken(BehaviorParser::OBJECT, 0);
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
  enterRule(_localctx, 40, BehaviorParser::RuleObject);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(218);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(213);
      match(BehaviorParser::T__1);
      setState(214);
      match(BehaviorParser::PEDESTRIAN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(215);
      match(BehaviorParser::T__1);
      setState(216);
      match(BehaviorParser::OBSTACLE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(217);
      match(BehaviorParser::OBJECT);
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

//----------------- Ped_SelectorContext ------------------------------------------------------------------

BehaviorParser::Ped_SelectorContext::Ped_SelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::SelectorContext* BehaviorParser::Ped_SelectorContext::selector() {
  return getRuleContext<BehaviorParser::SelectorContext>(0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

BehaviorParser::Id_listContext* BehaviorParser::Ped_SelectorContext::id_list() {
  return getRuleContext<BehaviorParser::Id_listContext>(0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::PEDESTRIAN() {
  return getToken(BehaviorParser::PEDESTRIAN, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::PEDESTRIANS() {
  return getToken(BehaviorParser::PEDESTRIANS, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::ARE() {
  return getToken(BehaviorParser::ARE, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::IS() {
  return getToken(BehaviorParser::IS, 0);
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
  enterRule(_localctx, 42, BehaviorParser::RulePed_Selector);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(227);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::EXACTLY:
      case BehaviorParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(220);
        selector();
        setState(221);
        _la = _input->LA(1);
        if (!(((((_la - 50) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 50)) & ((1ULL << (BehaviorParser::PEDESTRIAN - 50))
          | (1ULL << (BehaviorParser::PEDESTRIANS - 50))
          | (1ULL << (BehaviorParser::ID - 50)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(222);
        _la = _input->LA(1);
        if (!(_la == BehaviorParser::ARE

        || _la == BehaviorParser::IS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(223);
        match(BehaviorParser::AN);
        setState(224);
        id_list();
        break;
      }

      case BehaviorParser::EVERYONE: {
        enterOuterAlt(_localctx, 2);
        setState(226);
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

//----------------- SelectorContext ------------------------------------------------------------------

BehaviorParser::SelectorContext::SelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Selector_PercentContext* BehaviorParser::SelectorContext::selector_Percent() {
  return getRuleContext<BehaviorParser::Selector_PercentContext>(0);
}

BehaviorParser::Selector_Exactly_N_RandomContext* BehaviorParser::SelectorContext::selector_Exactly_N_Random() {
  return getRuleContext<BehaviorParser::Selector_Exactly_N_RandomContext>(0);
}


size_t BehaviorParser::SelectorContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector;
}

antlrcpp::Any BehaviorParser::SelectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::SelectorContext* BehaviorParser::selector() {
  SelectorContext *_localctx = _tracker.createInstance<SelectorContext>(_ctx, getState());
  enterRule(_localctx, 44, BehaviorParser::RuleSelector);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(231);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(229);
        selector_Percent();
        break;
      }

      case BehaviorParser::EXACTLY: {
        enterOuterAlt(_localctx, 2);
        setState(230);
        selector_Exactly_N_Random();
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

tree::TerminalNode* BehaviorParser::Selector_PercentContext::OF() {
  return getToken(BehaviorParser::OF, 0);
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
  enterRule(_localctx, 46, BehaviorParser::RuleSelector_Percent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    match(BehaviorParser::NUMBER);
    setState(234);
    match(BehaviorParser::T__2);
    setState(235);
    match(BehaviorParser::OF);
   
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

tree::TerminalNode* BehaviorParser::Selector_Exactly_N_RandomContext::EXACTLY() {
  return getToken(BehaviorParser::EXACTLY, 0);
}

tree::TerminalNode* BehaviorParser::Selector_Exactly_N_RandomContext::NUMBER() {
  return getToken(BehaviorParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorParser::Selector_Exactly_N_RandomContext::OF() {
  return getToken(BehaviorParser::OF, 0);
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
  enterRule(_localctx, 48, BehaviorParser::RuleSelector_Exactly_N_Random);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    match(BehaviorParser::EXACTLY);
    setState(238);
    match(BehaviorParser::NUMBER);
    setState(239);
    match(BehaviorParser::OF);
   
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

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::EVERYONE() {
  return getToken(BehaviorParser::EVERYONE, 0);
}

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::IS() {
  return getToken(BehaviorParser::IS, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Selector_EveryoneContext::AN() {
  return getTokens(BehaviorParser::AN);
}

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::AN(size_t i) {
  return getToken(BehaviorParser::AN, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Selector_EveryoneContext::ID() {
  return getTokens(BehaviorParser::ID);
}

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::ID(size_t i) {
  return getToken(BehaviorParser::ID, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Selector_EveryoneContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Selector_EveryoneContext::AND() {
  return getTokens(BehaviorParser::AND);
}

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::AND(size_t i) {
  return getToken(BehaviorParser::AND, i);
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
  enterRule(_localctx, 50, BehaviorParser::RuleSelector_Everyone);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    match(BehaviorParser::EVERYONE);
    setState(242);
    match(BehaviorParser::IS);
    setState(243);
    match(BehaviorParser::AN);

    setState(244);
    match(BehaviorParser::ID);
    setState(257);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 12) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 12)) & ((1ULL << (BehaviorParser::COMMA - 12))
      | (1ULL << (BehaviorParser::AND - 12))
      | (1ULL << (BehaviorParser::AN - 12))
      | (1ULL << (BehaviorParser::ID - 12)))) != 0)) {
      setState(246);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(245);
        match(BehaviorParser::COMMA);
      }
      setState(249);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(248);
        match(BehaviorParser::AND);
      }
      setState(252);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(251);
        match(BehaviorParser::AN);
      }
      setState(254);
      match(BehaviorParser::ID);
      setState(259);
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

//----------------- Id_listContext ------------------------------------------------------------------

BehaviorParser::Id_listContext::Id_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorParser::Id_listContext::ID() {
  return getTokens(BehaviorParser::ID);
}

tree::TerminalNode* BehaviorParser::Id_listContext::ID(size_t i) {
  return getToken(BehaviorParser::ID, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Id_listContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Id_listContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Id_listContext::AND() {
  return getTokens(BehaviorParser::AND);
}

tree::TerminalNode* BehaviorParser::Id_listContext::AND(size_t i) {
  return getToken(BehaviorParser::AND, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Id_listContext::AN() {
  return getTokens(BehaviorParser::AN);
}

tree::TerminalNode* BehaviorParser::Id_listContext::AN(size_t i) {
  return getToken(BehaviorParser::AN, i);
}


size_t BehaviorParser::Id_listContext::getRuleIndex() const {
  return BehaviorParser::RuleId_list;
}

antlrcpp::Any BehaviorParser::Id_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitId_list(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Id_listContext* BehaviorParser::id_list() {
  Id_listContext *_localctx = _tracker.createInstance<Id_listContext>(_ctx, getState());
  enterRule(_localctx, 52, BehaviorParser::RuleId_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(BehaviorParser::ID);
    setState(273);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 12) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 12)) & ((1ULL << (BehaviorParser::COMMA - 12))
      | (1ULL << (BehaviorParser::AND - 12))
      | (1ULL << (BehaviorParser::AN - 12))
      | (1ULL << (BehaviorParser::ID - 12)))) != 0)) {
      setState(262);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(261);
        match(BehaviorParser::COMMA);
      }
      setState(265);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(264);
        match(BehaviorParser::AND);
      }
      setState(268);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(267);
        match(BehaviorParser::AN);
      }
      setState(270);
      match(BehaviorParser::ID);
      setState(275);
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
  enterRule(_localctx, 54, BehaviorParser::RuleAction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(278);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(276);
      conditional_action();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(277);
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

tree::TerminalNode* BehaviorParser::Conditional_actionContext::WILL() {
  return getToken(BehaviorParser::WILL, 0);
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
  enterRule(_localctx, 56, BehaviorParser::RuleConditional_action);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    match(BehaviorParser::AN);
    setState(281);
    match(BehaviorParser::ID);
    setState(282);
    match(BehaviorParser::WILL);
    setState(283);
    sub_action();
    setState(284);
    condition();
   
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

tree::TerminalNode* BehaviorParser::Un_conditional_actionContext::WILL() {
  return getToken(BehaviorParser::WILL, 0);
}

tree::TerminalNode* BehaviorParser::Un_conditional_actionContext::ALWAYS() {
  return getToken(BehaviorParser::ALWAYS, 0);
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
  enterRule(_localctx, 58, BehaviorParser::RuleUn_conditional_action);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    match(BehaviorParser::AN);
    setState(287);
    match(BehaviorParser::ID);
    setState(288);
    match(BehaviorParser::WILL);
    setState(289);
    match(BehaviorParser::ALWAYS);
    setState(290);
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

std::vector<BehaviorParser::Action_atomContext *> BehaviorParser::Sub_actionContext::action_atom() {
  return getRuleContexts<BehaviorParser::Action_atomContext>();
}

BehaviorParser::Action_atomContext* BehaviorParser::Sub_actionContext::action_atom(size_t i) {
  return getRuleContext<BehaviorParser::Action_atomContext>(i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Sub_actionContext::THEN() {
  return getTokens(BehaviorParser::THEN);
}

tree::TerminalNode* BehaviorParser::Sub_actionContext::THEN(size_t i) {
  return getToken(BehaviorParser::THEN, i);
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
  enterRule(_localctx, 60, BehaviorParser::RuleSub_action);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    action_atom();
    setState(297);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::THEN) {
      setState(293);
      match(BehaviorParser::THEN);
      setState(294);
      action_atom();
      setState(299);
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

BehaviorParser::Action_StopContext* BehaviorParser::Action_atomContext::action_Stop() {
  return getRuleContext<BehaviorParser::Action_StopContext>(0);
}

BehaviorParser::Action_BeContext* BehaviorParser::Action_atomContext::action_Be() {
  return getRuleContext<BehaviorParser::Action_BeContext>(0);
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
  enterRule(_localctx, 62, BehaviorParser::RuleAction_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(304);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::ACTION: {
        enterOuterAlt(_localctx, 1);
        setState(300);
        match(BehaviorParser::ACTION);
        break;
      }

      case BehaviorParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(301);
        action_Stop();
        break;
      }

      case BehaviorParser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(302);
        action_Be();
        break;
      }

      case BehaviorParser::T__4: {
        enterOuterAlt(_localctx, 4);
        setState(303);
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
  enterRule(_localctx, 64, BehaviorParser::RuleAction_Stop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(BehaviorParser::T__3);
   
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

tree::TerminalNode* BehaviorParser::Action_atom_Percent_Walk_SpeedContext::FLOAT() {
  return getToken(BehaviorParser::FLOAT, 0);
}

tree::TerminalNode* BehaviorParser::Action_atom_Percent_Walk_SpeedContext::THEIR() {
  return getToken(BehaviorParser::THEIR, 0);
}

tree::TerminalNode* BehaviorParser::Action_atom_Percent_Walk_SpeedContext::NORMAL() {
  return getToken(BehaviorParser::NORMAL, 0);
}

tree::TerminalNode* BehaviorParser::Action_atom_Percent_Walk_SpeedContext::SPEED() {
  return getToken(BehaviorParser::SPEED, 0);
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
  enterRule(_localctx, 66, BehaviorParser::RuleAction_atom_Percent_Walk_Speed);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    match(BehaviorParser::T__4);
    setState(309);
    match(BehaviorParser::FLOAT);
    setState(310);
    match(BehaviorParser::T__5);
    setState(311);
    match(BehaviorParser::THEIR);
    setState(312);
    match(BehaviorParser::NORMAL);
    setState(313);
    match(BehaviorParser::SPEED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_PushContext ------------------------------------------------------------------

BehaviorParser::Action_PushContext::Action_PushContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Action_PushContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}


size_t BehaviorParser::Action_PushContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_Push;
}

antlrcpp::Any BehaviorParser::Action_PushContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_Push(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_PushContext* BehaviorParser::action_Push() {
  Action_PushContext *_localctx = _tracker.createInstance<Action_PushContext>(_ctx, getState());
  enterRule(_localctx, 68, BehaviorParser::RuleAction_Push);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    match(BehaviorParser::T__6);
    setState(316);
    match(BehaviorParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_BeContext ------------------------------------------------------------------

BehaviorParser::Action_BeContext::Action_BeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Action_BeContext::STATE() {
  return getToken(BehaviorParser::STATE, 0);
}


size_t BehaviorParser::Action_BeContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_Be;
}

antlrcpp::Any BehaviorParser::Action_BeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_Be(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_BeContext* BehaviorParser::action_Be() {
  Action_BeContext *_localctx = _tracker.createInstance<Action_BeContext>(_ctx, getState());
  enterRule(_localctx, 70, BehaviorParser::RuleAction_Be);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    match(BehaviorParser::T__7);
    setState(319);
    match(BehaviorParser::STATE);
   
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
  enterRule(_localctx, 72, BehaviorParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(324);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(321);
      decl_Ped();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(322);
      decl_Ped_State();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(323);
      decl_Env_State();
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

//----------------- Decl_PedContext ------------------------------------------------------------------

BehaviorParser::Decl_PedContext::Decl_PedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::CONSIDER() {
  return getToken(BehaviorParser::CONSIDER, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_PedContext::AN() {
  return getTokens(BehaviorParser::AN);
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::AN(size_t i) {
  return getToken(BehaviorParser::AN, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_PedContext::ID() {
  return getTokens(BehaviorParser::ID);
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::ID(size_t i) {
  return getToken(BehaviorParser::ID, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_PedContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_PedContext::AND() {
  return getTokens(BehaviorParser::AND);
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::AND(size_t i) {
  return getToken(BehaviorParser::AND, i);
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
  enterRule(_localctx, 74, BehaviorParser::RuleDecl_Ped);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(326);
    match(BehaviorParser::CONSIDER);
    setState(327);
    match(BehaviorParser::AN);

    setState(328);
    match(BehaviorParser::ID);
    setState(341);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 12) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 12)) & ((1ULL << (BehaviorParser::COMMA - 12))
      | (1ULL << (BehaviorParser::AND - 12))
      | (1ULL << (BehaviorParser::AN - 12))
      | (1ULL << (BehaviorParser::ID - 12)))) != 0)) {
      setState(330);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(329);
        match(BehaviorParser::COMMA);
      }
      setState(333);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(332);
        match(BehaviorParser::AND);
      }
      setState(336);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(335);
        match(BehaviorParser::AN);
      }
      setState(338);
      match(BehaviorParser::ID);
      setState(343);
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

//----------------- Decl_Ped_StateContext ------------------------------------------------------------------

BehaviorParser::Decl_Ped_StateContext::Decl_Ped_StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::POSSIBLE() {
  return getToken(BehaviorParser::POSSIBLE, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::PEDESTRIAN() {
  return getToken(BehaviorParser::PEDESTRIAN, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::STATES() {
  return getToken(BehaviorParser::STATES, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::ARE() {
  return getToken(BehaviorParser::ARE, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Ped_StateContext::STATE() {
  return getTokens(BehaviorParser::STATE);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::STATE(size_t i) {
  return getToken(BehaviorParser::STATE, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Ped_StateContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Ped_StateContext::AND() {
  return getTokens(BehaviorParser::AND);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::AND(size_t i) {
  return getToken(BehaviorParser::AND, i);
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
  enterRule(_localctx, 76, BehaviorParser::RuleDecl_Ped_State);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    match(BehaviorParser::POSSIBLE);
    setState(345);
    match(BehaviorParser::PEDESTRIAN);
    setState(346);
    match(BehaviorParser::STATES);
    setState(347);
    match(BehaviorParser::ARE);

    setState(348);
    match(BehaviorParser::STATE);
    setState(358);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BehaviorParser::COMMA)
      | (1ULL << BehaviorParser::STATE)
      | (1ULL << BehaviorParser::AND))) != 0)) {
      setState(350);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(349);
        match(BehaviorParser::COMMA);
      }
      setState(353);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(352);
        match(BehaviorParser::AND);
      }
      setState(355);
      match(BehaviorParser::STATE);
      setState(360);
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

//----------------- Decl_Env_StateContext ------------------------------------------------------------------

BehaviorParser::Decl_Env_StateContext::Decl_Env_StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::POSSIBLE() {
  return getToken(BehaviorParser::POSSIBLE, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::ENVIRONMENT() {
  return getToken(BehaviorParser::ENVIRONMENT, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::STATES() {
  return getToken(BehaviorParser::STATES, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::ARE() {
  return getToken(BehaviorParser::ARE, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Env_StateContext::STATE() {
  return getTokens(BehaviorParser::STATE);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::STATE(size_t i) {
  return getToken(BehaviorParser::STATE, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Env_StateContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Env_StateContext::AND() {
  return getTokens(BehaviorParser::AND);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::AND(size_t i) {
  return getToken(BehaviorParser::AND, i);
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
  enterRule(_localctx, 78, BehaviorParser::RuleDecl_Env_State);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    match(BehaviorParser::POSSIBLE);
    setState(362);
    match(BehaviorParser::ENVIRONMENT);
    setState(363);
    match(BehaviorParser::STATES);
    setState(364);
    match(BehaviorParser::ARE);

    setState(365);
    match(BehaviorParser::STATE);
    setState(375);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BehaviorParser::COMMA)
      | (1ULL << BehaviorParser::STATE)
      | (1ULL << BehaviorParser::AND))) != 0)) {
      setState(367);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(366);
        match(BehaviorParser::COMMA);
      }
      setState(370);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(369);
        match(BehaviorParser::AND);
      }
      setState(372);
      match(BehaviorParser::STATE);
      setState(377);
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

// Static vars and initialization.
std::vector<dfa::DFA> BehaviorParser::_decisionToDFA;
atn::PredictionContextCache BehaviorParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN BehaviorParser::_atn;
std::vector<uint16_t> BehaviorParser::_serializedATN;

std::vector<std::string> BehaviorParser::_ruleNames = {
  "program", "statement", "event", "event_Single", "event_Lasting", "condition", 
  "connector", "or_Connector", "and_Connector", "sub_condition", "condition_Time_Elapsed_From_Event", 
  "condition_Event_Occurred", "condition_Event_Occurring", "condition_Event_One_Time", 
  "direction", "dir", "direction_of", "infront", "behind", "around", "object", 
  "ped_Selector", "selector", "selector_Percent", "selector_Exactly_N_Random", 
  "selector_Everyone", "id_list", "action", "conditional_action", "un_conditional_action", 
  "sub_action", "action_atom", "action_Stop", "action_atom_Percent_Walk_Speed", 
  "action_Push", "action_Be", "declaration", "decl_Ped", "decl_Ped_State", 
  "decl_Env_State"
};

std::vector<std::string> BehaviorParser::_literalNames = {
  "", "'.'", "'+'", "'%'", "'@stop'", "'@walk'", "'x'", "'@push'", "'@be set to'", 
  "", "", "", "','", "':'"
};

std::vector<std::string> BehaviorParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "COMMENT", "LINE_COMMENT", "WS", "COMMA", 
  "COLON", "STATE", "ACTION", "PARAMETER", "EVNT", "OBJECT", "AFTER", "AND", 
  "ALWAYS", "AN", "ARE", "AROUND", "BEHIND", "CONSIDER", "DIRECTION", "END", 
  "ENDS", "ENVIRONMENT", "EVENT", "EXACTLY", "EVERY", "EVERYONE", "FASTER", 
  "FROM", "FRONT", "GIVEN", "HAS", "IN", "IS", "METERS", "NORMAL", "OBSTACLE", 
  "OCCUR", "OCCURRED", "OCCURRING", "OF", "OR", "PEDESTRIAN", "PEDESTRIANS", 
  "POSSIBLE", "RANDOM", "SECONDS", "SLOWER", "STATES", "STARTS", "SPEED", 
  "THE", "THEN", "THEIR", "TYPES", "WHEN", "WHILE", "WILL", "WITHIN", "ID", 
  "NUMBER", "FLOAT"
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
    0x3, 0x47, 0x17d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x3, 0x2, 0x6, 0x2, 0x54, 0xa, 0x2, 0xd, 0x2, 
    0xe, 0x2, 0x55, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x64, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x68, 0xa, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x6d, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x76, 0xa, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x81, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 
    0x84, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x88, 0xa, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x94, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x9b, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0x9f, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xa3, 0xa, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xa7, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xae, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x5, 0xe, 0xb2, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0xb9, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xbd, 0xa, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xca, 
    0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xdd, 
    0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x5, 0x17, 0xe6, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x5, 
    0x18, 0xea, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0xf9, 0xa, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 
    0xfc, 0xa, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0xff, 0xa, 0x1b, 0x3, 0x1b, 0x7, 
    0x1b, 0x102, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x105, 0xb, 0x1b, 0x3, 
    0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x109, 0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 
    0x10c, 0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x10f, 0xa, 0x1c, 0x3, 0x1c, 
    0x7, 0x1c, 0x112, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x115, 0xb, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x119, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x7, 0x20, 0x12a, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x12d, 0xb, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x133, 0xa, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x147, 
    0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x14d, 
    0xa, 0x27, 0x3, 0x27, 0x5, 0x27, 0x150, 0xa, 0x27, 0x3, 0x27, 0x5, 0x27, 
    0x153, 0xa, 0x27, 0x3, 0x27, 0x7, 0x27, 0x156, 0xa, 0x27, 0xc, 0x27, 
    0xe, 0x27, 0x159, 0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x161, 0xa, 0x28, 0x3, 0x28, 0x5, 0x28, 
    0x164, 0xa, 0x28, 0x3, 0x28, 0x7, 0x28, 0x167, 0xa, 0x28, 0xc, 0x28, 
    0xe, 0x28, 0x16a, 0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x172, 0xa, 0x29, 0x3, 0x29, 0x5, 0x29, 
    0x175, 0xa, 0x29, 0x3, 0x29, 0x7, 0x29, 0x178, 0xa, 0x29, 0xc, 0x29, 
    0xe, 0x29, 0x17b, 0xb, 0x29, 0x3, 0x29, 0x2, 0x2, 0x2a, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
    0x50, 0x2, 0x7, 0x4, 0x2, 0x18, 0x18, 0x3d, 0x3d, 0x4, 0x2, 0x18, 0x18, 
    0x3e, 0x3e, 0x4, 0x2, 0x1f, 0x1f, 0x3b, 0x3b, 0x4, 0x2, 0x34, 0x35, 
    0x45, 0x45, 0x4, 0x2, 0x19, 0x19, 0x2b, 0x2b, 0x2, 0x188, 0x2, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x63, 0x3, 0x2, 0x2, 0x2, 0x6, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x69, 0x3, 0x2, 0x2, 0x2, 0xa, 0x72, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x7e, 0x3, 0x2, 0x2, 0x2, 0xe, 0x87, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x12, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x14, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x95, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa0, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0xab, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x20, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x24, 0xd0, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x28, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xe9, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x32, 0xef, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x36, 0x106, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x118, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x120, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x126, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x132, 0x3, 0x2, 0x2, 0x2, 0x42, 0x134, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x136, 0x3, 0x2, 0x2, 0x2, 0x46, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x48, 0x140, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x146, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x148, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x50, 0x16b, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x54, 0x5, 0x4, 0x3, 0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x3, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x58, 0x5, 0x6, 0x4, 0x2, 0x58, 0x59, 0x7, 0x3, 0x2, 0x2, 0x59, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0x4a, 0x26, 0x2, 0x5b, 0x5c, 0x7, 
    0x3, 0x2, 0x2, 0x5c, 0x64, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x5, 0x2c, 
    0x17, 0x2, 0x5e, 0x5f, 0x7, 0x3, 0x2, 0x2, 0x5f, 0x64, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x61, 0x5, 0x38, 0x1d, 0x2, 0x61, 0x62, 0x7, 0x3, 0x2, 0x2, 
    0x62, 0x64, 0x3, 0x2, 0x2, 0x2, 0x63, 0x57, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x5a, 0x3, 0x2, 0x2, 0x2, 0x63, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x63, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x5, 0x3, 0x2, 0x2, 0x2, 0x65, 0x68, 0x5, 
    0x8, 0x5, 0x2, 0x66, 0x68, 0x5, 0xa, 0x6, 0x2, 0x67, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x6a, 0x9, 0x2, 0x2, 0x2, 0x6a, 0x6c, 0x7, 0x13, 0x2, 0x2, 
    0x6b, 0x6d, 0x7, 0x21, 0x2, 0x2, 0x6c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 
    0x7, 0x43, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x2f, 0x2, 0x2, 0x70, 0x71, 0x5, 
    0xc, 0x7, 0x2, 0x71, 0x9, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x9, 0x2, 
    0x2, 0x2, 0x73, 0x75, 0x7, 0x13, 0x2, 0x2, 0x74, 0x76, 0x7, 0x21, 0x2, 
    0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0x43, 0x2, 0x2, 0x78, 
    0x79, 0x7, 0x2f, 0x2, 0x2, 0x79, 0x7a, 0x5, 0xc, 0x7, 0x2, 0x7a, 0x7b, 
    0x7, 0x16, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x1e, 0x2, 0x2, 0x7c, 0x7d, 0x5, 
    0xc, 0x7, 0x2, 0x7d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x82, 0x5, 0x14, 
    0xb, 0x2, 0x7f, 0x81, 0x5, 0xe, 0x8, 0x2, 0x80, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x84, 0x3, 0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0xd, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0x85, 0x88, 0x5, 0x10, 0x9, 0x2, 0x86, 0x88, 
    0x5, 0x12, 0xa, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x86, 0x3, 
    0x2, 0x2, 0x2, 0x88, 0xf, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x33, 
    0x2, 0x2, 0x8a, 0x8b, 0x5, 0x14, 0xb, 0x2, 0x8b, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x8d, 0x7, 0x16, 0x2, 0x2, 0x8d, 0x8e, 0x5, 0x14, 0xb, 0x2, 
    0x8e, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x94, 0x5, 0x16, 0xc, 0x2, 0x90, 
    0x94, 0x5, 0x18, 0xd, 0x2, 0x91, 0x94, 0x5, 0x1a, 0xe, 0x2, 0x92, 0x94, 
    0x5, 0x1c, 0xf, 0x2, 0x93, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x93, 0x90, 0x3, 
    0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x92, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x15, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x7, 0x15, 0x2, 
    0x2, 0x96, 0x97, 0x7, 0x46, 0x2, 0x2, 0x97, 0x98, 0x7, 0x38, 0x2, 0x2, 
    0x98, 0x9a, 0x7, 0x26, 0x2, 0x2, 0x99, 0x9b, 0x9, 0x2, 0x2, 0x2, 0x9a, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 
    0x3, 0x2, 0x2, 0x2, 0x9c, 0x9e, 0x7, 0x13, 0x2, 0x2, 0x9d, 0x9f, 0x7, 
    0x21, 0x2, 0x2, 0x9e, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0x9f, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa2, 0x7, 0x28, 0x2, 
    0x2, 0xa1, 0xa3, 0x9, 0x2, 0x2, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xa6, 0x7, 0x13, 0x2, 0x2, 0xa5, 0xa7, 0x7, 0x21, 0x2, 0x2, 0xa6, 0xa5, 
    0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x3, 
    0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x29, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x30, 
    0x2, 0x2, 0xaa, 0x19, 0x3, 0x2, 0x2, 0x2, 0xab, 0xad, 0x7, 0x42, 0x2, 
    0x2, 0xac, 0xae, 0x9, 0x3, 0x2, 0x2, 0xad, 0xac, 0x3, 0x2, 0x2, 0x2, 
    0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb1, 0x7, 0x13, 0x2, 0x2, 0xb0, 0xb2, 0x7, 0x21, 0x2, 0x2, 0xb1, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x2b, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x31, 
    0x2, 0x2, 0xb5, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb8, 0x7, 0x41, 0x2, 
    0x2, 0xb7, 0xb9, 0x9, 0x3, 0x2, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 
    0xbc, 0x7, 0x13, 0x2, 0x2, 0xbb, 0xbd, 0x7, 0x21, 0x2, 0x2, 0xbc, 0xbb, 
    0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x3, 
    0x2, 0x2, 0x2, 0xbe, 0xbf, 0x9, 0x4, 0x2, 0x2, 0xbf, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0xc1, 0x5, 0x20, 0x11, 0x2, 0xc1, 0xc2, 0x7, 0x44, 0x2, 
    0x2, 0xc2, 0xc3, 0x7, 0x46, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x2c, 0x2, 0x2, 
    0xc4, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xca, 0x5, 0x22, 0x12, 0x2, 0xc6, 
    0xca, 0x5, 0x24, 0x13, 0x2, 0xc7, 0xca, 0x5, 0x26, 0x14, 0x2, 0xc8, 
    0xca, 0x5, 0x28, 0x15, 0x2, 0xc9, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc8, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0x21, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x2a, 
    0x2, 0x2, 0xcc, 0xcd, 0x7, 0x1d, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x32, 0x2, 
    0x2, 0xce, 0xcf, 0x7, 0x45, 0x2, 0x2, 0xcf, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0xd0, 0xd1, 0x7, 0x2a, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x27, 0x2, 0x2, 0xd2, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x1b, 0x2, 0x2, 0xd4, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x1a, 0x2, 0x2, 0xd6, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x4, 0x2, 0x2, 0xd8, 0xdd, 0x7, 0x34, 
    0x2, 0x2, 0xd9, 0xda, 0x7, 0x4, 0x2, 0x2, 0xda, 0xdd, 0x7, 0x2e, 0x2, 
    0x2, 0xdb, 0xdd, 0x7, 0x14, 0x2, 0x2, 0xdc, 0xd7, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x5, 0x2e, 0x18, 0x2, 0xdf, 0xe0, 
    0x9, 0x5, 0x2, 0x2, 0xe0, 0xe1, 0x9, 0x6, 0x2, 0x2, 0xe1, 0xe2, 0x7, 
    0x18, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x36, 0x1c, 0x2, 0xe3, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xe6, 0x5, 0x34, 0x1b, 0x2, 0xe5, 0xde, 0x3, 0x2, 0x2, 
    0x2, 0xe5, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xe7, 0xea, 0x5, 0x30, 0x19, 0x2, 0xe8, 0xea, 0x5, 0x32, 0x1a, 0x2, 
    0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xea, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x46, 0x2, 0x2, 0xec, 0xed, 
    0x7, 0x5, 0x2, 0x2, 0xed, 0xee, 0x7, 0x32, 0x2, 0x2, 0xee, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x22, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x46, 
    0x2, 0x2, 0xf1, 0xf2, 0x7, 0x32, 0x2, 0x2, 0xf2, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0xf3, 0xf4, 0x7, 0x24, 0x2, 0x2, 0xf4, 0xf5, 0x7, 0x2b, 0x2, 0x2, 
    0xf5, 0xf6, 0x7, 0x18, 0x2, 0x2, 0xf6, 0x103, 0x7, 0x45, 0x2, 0x2, 0xf7, 
    0xf9, 0x7, 0xe, 0x2, 0x2, 0xf8, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 
    0x3, 0x2, 0x2, 0x2, 0xf9, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfc, 0x7, 
    0x16, 0x2, 0x2, 0xfb, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 
    0x2, 0x2, 0xfc, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xff, 0x7, 0x18, 0x2, 
    0x2, 0xfe, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 
    0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 0x100, 0x102, 0x7, 0x45, 0x2, 0x2, 
    0x101, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x102, 0x105, 0x3, 0x2, 0x2, 0x2, 0x103, 
    0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 0x104, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x105, 0x103, 0x3, 0x2, 0x2, 0x2, 0x106, 0x113, 
    0x7, 0x45, 0x2, 0x2, 0x107, 0x109, 0x7, 0xe, 0x2, 0x2, 0x108, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10b, 
    0x3, 0x2, 0x2, 0x2, 0x10a, 0x10c, 0x7, 0x16, 0x2, 0x2, 0x10b, 0x10a, 
    0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10e, 
    0x3, 0x2, 0x2, 0x2, 0x10d, 0x10f, 0x7, 0x18, 0x2, 0x2, 0x10e, 0x10d, 
    0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0x112, 0x7, 0x45, 0x2, 0x2, 0x111, 0x108, 
    0x3, 0x2, 0x2, 0x2, 0x112, 0x115, 0x3, 0x2, 0x2, 0x2, 0x113, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 0x2, 0x116, 0x119, 0x5, 
    0x3a, 0x1e, 0x2, 0x117, 0x119, 0x5, 0x3c, 0x1f, 0x2, 0x118, 0x116, 0x3, 
    0x2, 0x2, 0x2, 0x118, 0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x11a, 0x11b, 0x7, 0x18, 0x2, 0x2, 0x11b, 0x11c, 0x7, 0x45, 
    0x2, 0x2, 0x11c, 0x11d, 0x7, 0x43, 0x2, 0x2, 0x11d, 0x11e, 0x5, 0x3e, 
    0x20, 0x2, 0x11e, 0x11f, 0x5, 0xc, 0x7, 0x2, 0x11f, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x120, 0x121, 0x7, 0x18, 0x2, 0x2, 0x121, 0x122, 0x7, 0x45, 
    0x2, 0x2, 0x122, 0x123, 0x7, 0x43, 0x2, 0x2, 0x123, 0x124, 0x7, 0x17, 
    0x2, 0x2, 0x124, 0x125, 0x5, 0x3e, 0x20, 0x2, 0x125, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x126, 0x12b, 0x5, 0x40, 0x21, 0x2, 0x127, 0x128, 0x7, 0x3e, 
    0x2, 0x2, 0x128, 0x12a, 0x5, 0x40, 0x21, 0x2, 0x129, 0x127, 0x3, 0x2, 
    0x2, 0x2, 0x12a, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 
    0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x133, 0x7, 0x11, 0x2, 
    0x2, 0x12f, 0x133, 0x5, 0x42, 0x22, 0x2, 0x130, 0x133, 0x5, 0x48, 0x25, 
    0x2, 0x131, 0x133, 0x5, 0x44, 0x23, 0x2, 0x132, 0x12e, 0x3, 0x2, 0x2, 
    0x2, 0x132, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x132, 0x130, 0x3, 0x2, 0x2, 
    0x2, 0x132, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x134, 0x135, 0x7, 0x6, 0x2, 0x2, 0x135, 0x43, 0x3, 0x2, 0x2, 0x2, 0x136, 
    0x137, 0x7, 0x7, 0x2, 0x2, 0x137, 0x138, 0x7, 0x47, 0x2, 0x2, 0x138, 
    0x139, 0x7, 0x8, 0x2, 0x2, 0x139, 0x13a, 0x7, 0x3f, 0x2, 0x2, 0x13a, 
    0x13b, 0x7, 0x2d, 0x2, 0x2, 0x13b, 0x13c, 0x7, 0x3c, 0x2, 0x2, 0x13c, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x9, 0x2, 0x2, 0x13e, 0x13f, 
    0x7, 0x45, 0x2, 0x2, 0x13f, 0x47, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 
    0x7, 0xa, 0x2, 0x2, 0x141, 0x142, 0x7, 0x10, 0x2, 0x2, 0x142, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x143, 0x147, 0x5, 0x4c, 0x27, 0x2, 0x144, 0x147, 
    0x5, 0x4e, 0x28, 0x2, 0x145, 0x147, 0x5, 0x50, 0x29, 0x2, 0x146, 0x143, 
    0x3, 0x2, 0x2, 0x2, 0x146, 0x144, 0x3, 0x2, 0x2, 0x2, 0x146, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x147, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x7, 
    0x1c, 0x2, 0x2, 0x149, 0x14a, 0x7, 0x18, 0x2, 0x2, 0x14a, 0x157, 0x7, 
    0x45, 0x2, 0x2, 0x14b, 0x14d, 0x7, 0xe, 0x2, 0x2, 0x14c, 0x14b, 0x3, 
    0x2, 0x2, 0x2, 0x14c, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14f, 0x3, 
    0x2, 0x2, 0x2, 0x14e, 0x150, 0x7, 0x16, 0x2, 0x2, 0x14f, 0x14e, 0x3, 
    0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 0x152, 0x3, 
    0x2, 0x2, 0x2, 0x151, 0x153, 0x7, 0x18, 0x2, 0x2, 0x152, 0x151, 0x3, 
    0x2, 0x2, 0x2, 0x152, 0x153, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 
    0x2, 0x2, 0x2, 0x154, 0x156, 0x7, 0x45, 0x2, 0x2, 0x155, 0x14c, 0x3, 
    0x2, 0x2, 0x2, 0x156, 0x159, 0x3, 0x2, 0x2, 0x2, 0x157, 0x155, 0x3, 
    0x2, 0x2, 0x2, 0x157, 0x158, 0x3, 0x2, 0x2, 0x2, 0x158, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 0x7, 0x36, 
    0x2, 0x2, 0x15b, 0x15c, 0x7, 0x34, 0x2, 0x2, 0x15c, 0x15d, 0x7, 0x3a, 
    0x2, 0x2, 0x15d, 0x15e, 0x7, 0x19, 0x2, 0x2, 0x15e, 0x168, 0x7, 0x10, 
    0x2, 0x2, 0x15f, 0x161, 0x7, 0xe, 0x2, 0x2, 0x160, 0x15f, 0x3, 0x2, 
    0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 0x163, 0x3, 0x2, 
    0x2, 0x2, 0x162, 0x164, 0x7, 0x16, 0x2, 0x2, 0x163, 0x162, 0x3, 0x2, 
    0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 
    0x2, 0x2, 0x165, 0x167, 0x7, 0x10, 0x2, 0x2, 0x166, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x167, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x168, 0x166, 0x3, 0x2, 
    0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x16a, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x7, 0x36, 0x2, 
    0x2, 0x16c, 0x16d, 0x7, 0x20, 0x2, 0x2, 0x16d, 0x16e, 0x7, 0x3a, 0x2, 
    0x2, 0x16e, 0x16f, 0x7, 0x19, 0x2, 0x2, 0x16f, 0x179, 0x7, 0x10, 0x2, 
    0x2, 0x170, 0x172, 0x7, 0xe, 0x2, 0x2, 0x171, 0x170, 0x3, 0x2, 0x2, 
    0x2, 0x171, 0x172, 0x3, 0x2, 0x2, 0x2, 0x172, 0x174, 0x3, 0x2, 0x2, 
    0x2, 0x173, 0x175, 0x7, 0x16, 0x2, 0x2, 0x174, 0x173, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x3, 0x2, 0x2, 
    0x2, 0x176, 0x178, 0x7, 0x10, 0x2, 0x2, 0x177, 0x171, 0x3, 0x2, 0x2, 
    0x2, 0x178, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x179, 0x177, 0x3, 0x2, 0x2, 
    0x2, 0x179, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x17b, 0x179, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x55, 0x63, 0x67, 0x6c, 0x75, 
    0x82, 0x87, 0x93, 0x9a, 0x9e, 0xa2, 0xa6, 0xad, 0xb1, 0xb8, 0xbc, 0xc9, 
    0xdc, 0xe5, 0xe9, 0xf8, 0xfb, 0xfe, 0x103, 0x108, 0x10b, 0x10e, 0x113, 
    0x118, 0x12b, 0x132, 0x146, 0x14c, 0x14f, 0x152, 0x157, 0x160, 0x163, 
    0x168, 0x171, 0x174, 0x179, 
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
