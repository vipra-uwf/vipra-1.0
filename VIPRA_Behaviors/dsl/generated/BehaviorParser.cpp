
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

BehaviorParser::ConsiderationContext* BehaviorParser::ProgramContext::consideration() {
  return getRuleContext<BehaviorParser::ConsiderationContext>(0);
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
    setState(22);
    consideration();
    setState(24); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(23);
      statement();
      setState(26); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BehaviorParser::T__3)
      | (1ULL << BehaviorParser::T__6)
      | (1ULL << BehaviorParser::NUMBER))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConsiderationContext ------------------------------------------------------------------

BehaviorParser::ConsiderationContext::ConsiderationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::ConsiderationContext::A() {
  return getToken(BehaviorParser::A, 0);
}

tree::TerminalNode* BehaviorParser::ConsiderationContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}


size_t BehaviorParser::ConsiderationContext::getRuleIndex() const {
  return BehaviorParser::RuleConsideration;
}

antlrcpp::Any BehaviorParser::ConsiderationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitConsideration(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::ConsiderationContext* BehaviorParser::consideration() {
  ConsiderationContext *_localctx = _tracker.createInstance<ConsiderationContext>(_ctx, getState());
  enterRule(_localctx, 2, BehaviorParser::RuleConsideration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    match(BehaviorParser::T__0);
    setState(29);
    match(BehaviorParser::A);
    setState(30);
    match(BehaviorParser::ID);
   
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

BehaviorParser::Ped_SelectorContext* BehaviorParser::StatementContext::ped_Selector() {
  return getRuleContext<BehaviorParser::Ped_SelectorContext>(0);
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
  enterRule(_localctx, 4, BehaviorParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32);
    ped_Selector();
   
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
  enterRule(_localctx, 6, BehaviorParser::RulePed_Selector);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(37);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(34);
        selector_Percent();
        break;
      }

      case BehaviorParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(35);
        selector_Exactly_N_Random();
        break;
      }

      case BehaviorParser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(36);
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
  enterRule(_localctx, 8, BehaviorParser::RuleSelector_Percent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(39);
    match(BehaviorParser::NUMBER);
    setState(40);
    match(BehaviorParser::T__1);
    setState(41);
    match(BehaviorParser::NUMBER);
    setState(42);
    match(BehaviorParser::T__2);
    setState(43);
    match(BehaviorParser::A);
    setState(44);
    match(BehaviorParser::ID);
    setState(45);
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
  enterRule(_localctx, 10, BehaviorParser::RuleSelector_Exactly_N_Random);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(59);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(47);
      match(BehaviorParser::T__3);
      setState(48);
      match(BehaviorParser::NUMBER);
      setState(49);
      match(BehaviorParser::T__4);
      setState(50);
      match(BehaviorParser::A);
      setState(51);
      match(BehaviorParser::ID);
      setState(52);
      match(BehaviorParser::END);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(53);
      match(BehaviorParser::T__3);
      setState(54);
      match(BehaviorParser::NUMBER);
      setState(55);
      match(BehaviorParser::T__5);
      setState(56);
      match(BehaviorParser::A);
      setState(57);
      match(BehaviorParser::ID);
      setState(58);
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
  enterRule(_localctx, 12, BehaviorParser::RuleSelector_Everyone);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(BehaviorParser::T__6);
    setState(62);
    match(BehaviorParser::A);
    setState(63);
    match(BehaviorParser::ID);
    setState(64);
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
  enterRule(_localctx, 14, BehaviorParser::RuleCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(80);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(66);
      match(BehaviorParser::WS);
      setState(67);
      sub_condition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(68);
      match(BehaviorParser::WS);
      setState(69);
      sub_condition();
      setState(70);
      match(BehaviorParser::WS);
      setState(71);
      match(BehaviorParser::T__7);
      setState(72);
      condition();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(74);
      match(BehaviorParser::WS);
      setState(75);
      sub_condition();
      setState(76);
      match(BehaviorParser::WS);
      setState(77);
      match(BehaviorParser::T__8);
      setState(78);
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

BehaviorParser::Condition_ExistanceContext* BehaviorParser::Sub_conditionContext::condition_Existance() {
  return getRuleContext<BehaviorParser::Condition_ExistanceContext>(0);
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
  enterRule(_localctx, 16, BehaviorParser::RuleSub_condition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    condition_Existance();
   
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

BehaviorParser::Condition_StateContext* BehaviorParser::Condition_ExistanceContext::condition_State() {
  return getRuleContext<BehaviorParser::Condition_StateContext>(0);
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
  enterRule(_localctx, 18, BehaviorParser::RuleCondition_Existance);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(84);
      match(BehaviorParser::T__9);
      setState(85);
      match(BehaviorParser::A);
      setState(86);
      match(BehaviorParser::ID);
      setState(87);
      match(BehaviorParser::Direction);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(88);
      match(BehaviorParser::T__9);
      setState(89);
      match(BehaviorParser::A);
      setState(90);
      match(BehaviorParser::ID);
      setState(91);
      match(BehaviorParser::Direction);
      setState(92);
      condition_State();
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
  enterRule(_localctx, 20, BehaviorParser::RuleCondition_State);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(BehaviorParser::T__10);
    setState(96);
    match(BehaviorParser::STATE);
   
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
  "program", "consideration", "statement", "ped_Selector", "selector_Percent", 
  "selector_Exactly_N_Random", "selector_Everyone", "condition", "sub_condition", 
  "condition_Existance", "condition_State"
};

std::vector<std::string> BehaviorParser::_literalNames = {
  "", "'Consider '", "' out of '", "' Pedestrians is '", "'Exactly '", "' random pedestrians are '", 
  "' random pedestrian is '", "'Everyone is '", "'AND'", "'OR'", "' There is '", 
  "' That is '", "", "'.'"
};

std::vector<std::string> BehaviorParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "A", "END", "ID", "STATE", 
  "NUMBER", "PERCENT", "COMMENT", "LINE_COMMENT", "WS", "Direction"
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
    0x3, 0x17, 0x65, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x1b, 0xa, 0x2, 
    0xd, 0x2, 0xe, 0x2, 0x1c, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x28, 0xa, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0x3e, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x53, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0x60, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x2, 0x2, 0xd, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x2, 0x2, 
    0x2, 0x60, 0x2, 0x18, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1e, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x22, 0x3, 0x2, 0x2, 0x2, 0x8, 0x27, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x52, 0x3, 0x2, 0x2, 0x2, 0x12, 0x54, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x16, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x1a, 0x5, 0x4, 0x3, 0x2, 0x19, 0x1b, 0x5, 0x6, 0x4, 
    0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x1c, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1d, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0x3, 0x2, 0x2, 0x1f, 0x20, 
    0x7, 0xe, 0x2, 0x2, 0x20, 0x21, 0x7, 0x10, 0x2, 0x2, 0x21, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x22, 0x23, 0x5, 0x8, 0x5, 0x2, 0x23, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x24, 0x28, 0x5, 0xa, 0x6, 0x2, 0x25, 0x28, 0x5, 0xc, 0x7, 
    0x2, 0x26, 0x28, 0x5, 0xe, 0x8, 0x2, 0x27, 0x24, 0x3, 0x2, 0x2, 0x2, 
    0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x12, 0x2, 0x2, 0x2a, 0x2b, 
    0x7, 0x4, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x12, 0x2, 0x2, 0x2c, 0x2d, 0x7, 
    0x5, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0xe, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x10, 
    0x2, 0x2, 0x2f, 0x30, 0x7, 0xf, 0x2, 0x2, 0x30, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x32, 0x7, 0x6, 0x2, 0x2, 0x32, 0x33, 0x7, 0x12, 0x2, 0x2, 
    0x33, 0x34, 0x7, 0x7, 0x2, 0x2, 0x34, 0x35, 0x7, 0xe, 0x2, 0x2, 0x35, 
    0x36, 0x7, 0x10, 0x2, 0x2, 0x36, 0x3e, 0x7, 0xf, 0x2, 0x2, 0x37, 0x38, 
    0x7, 0x6, 0x2, 0x2, 0x38, 0x39, 0x7, 0x12, 0x2, 0x2, 0x39, 0x3a, 0x7, 
    0x8, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0xe, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x10, 
    0x2, 0x2, 0x3c, 0x3e, 0x7, 0xf, 0x2, 0x2, 0x3d, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3e, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x3f, 0x40, 0x7, 0x9, 0x2, 0x2, 0x40, 0x41, 0x7, 0xe, 0x2, 0x2, 0x41, 
    0x42, 0x7, 0x10, 0x2, 0x2, 0x42, 0x43, 0x7, 0xf, 0x2, 0x2, 0x43, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x16, 0x2, 0x2, 0x45, 0x53, 0x5, 
    0x12, 0xa, 0x2, 0x46, 0x47, 0x7, 0x16, 0x2, 0x2, 0x47, 0x48, 0x5, 0x12, 
    0xa, 0x2, 0x48, 0x49, 0x7, 0x16, 0x2, 0x2, 0x49, 0x4a, 0x7, 0xa, 0x2, 
    0x2, 0x4a, 0x4b, 0x5, 0x10, 0x9, 0x2, 0x4b, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4d, 0x7, 0x16, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0x12, 0xa, 0x2, 0x4e, 
    0x4f, 0x7, 0x16, 0x2, 0x2, 0x4f, 0x50, 0x7, 0xb, 0x2, 0x2, 0x50, 0x51, 
    0x5, 0x10, 0x9, 0x2, 0x51, 0x53, 0x3, 0x2, 0x2, 0x2, 0x52, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x46, 0x3, 0x2, 0x2, 0x2, 0x52, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0x11, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x5, 0x14, 0xb, 
    0x2, 0x55, 0x13, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0xc, 0x2, 0x2, 
    0x57, 0x58, 0x7, 0xe, 0x2, 0x2, 0x58, 0x59, 0x7, 0x10, 0x2, 0x2, 0x59, 
    0x60, 0x7, 0x17, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0xc, 0x2, 0x2, 0x5b, 0x5c, 
    0x7, 0xe, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x10, 0x2, 0x2, 0x5d, 0x5e, 0x7, 
    0x17, 0x2, 0x2, 0x5e, 0x60, 0x5, 0x16, 0xc, 0x2, 0x5f, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x5f, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x60, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x7, 0xd, 0x2, 0x2, 0x62, 0x63, 0x7, 0x11, 0x2, 0x2, 
    0x63, 0x17, 0x3, 0x2, 0x2, 0x2, 0x7, 0x1c, 0x27, 0x3d, 0x52, 0x5f, 
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
