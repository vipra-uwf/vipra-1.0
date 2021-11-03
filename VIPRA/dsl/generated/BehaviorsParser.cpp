
// Generated from Behaviors.g4 by ANTLR 4.9.2


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
    setState(13); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(12);
      statement();
      setState(15); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == BehaviorsParser::T__0

    || _la == BehaviorsParser::T__2);
   
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

BehaviorsParser::CountContext* BehaviorsParser::StatementContext::count() {
  return getRuleContext<BehaviorsParser::CountContext>(0);
}

BehaviorsParser::DescriptionContext* BehaviorsParser::StatementContext::description() {
  return getRuleContext<BehaviorsParser::DescriptionContext>(0);
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
    enterOuterAlt(_localctx, 1);
    setState(17);
    consideration();
    setState(18);
    count();
    setState(19);
    description();
   
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

tree::TerminalNode* BehaviorsParser::ConsiderationContext::PERSON_TYPE() {
  return getToken(BehaviorsParser::PERSON_TYPE, 0);
}

tree::TerminalNode* BehaviorsParser::ConsiderationContext::NEWLINE() {
  return getToken(BehaviorsParser::NEWLINE, 0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(29);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorsParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(21);
        match(BehaviorsParser::T__0);
        setState(22);
        match(BehaviorsParser::PERSON_TYPE);
        setState(23);
        match(BehaviorsParser::T__1);
        setState(24);
        match(BehaviorsParser::NEWLINE);
        break;
      }

      case BehaviorsParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(25);
        match(BehaviorsParser::T__2);
        setState(26);
        match(BehaviorsParser::PERSON_TYPE);
        setState(27);
        match(BehaviorsParser::T__1);
        setState(28);
        match(BehaviorsParser::NEWLINE);
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

//----------------- CountContext ------------------------------------------------------------------

BehaviorsParser::CountContext::CountContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::CountContext::NUMBER() {
  return getToken(BehaviorsParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorsParser::CountContext::PERSON_TYPE() {
  return getToken(BehaviorsParser::PERSON_TYPE, 0);
}

tree::TerminalNode* BehaviorsParser::CountContext::NEWLINE() {
  return getToken(BehaviorsParser::NEWLINE, 0);
}


size_t BehaviorsParser::CountContext::getRuleIndex() const {
  return BehaviorsParser::RuleCount;
}


antlrcpp::Any BehaviorsParser::CountContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitCount(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::CountContext* BehaviorsParser::count() {
  CountContext *_localctx = _tracker.createInstance<CountContext>(_ctx, getState());
  enterRule(_localctx, 6, BehaviorsParser::RuleCount);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(41);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(31);
      match(BehaviorsParser::NUMBER);
      setState(32);
      match(BehaviorsParser::T__3);
      setState(33);
      match(BehaviorsParser::PERSON_TYPE);
      setState(34);
      match(BehaviorsParser::T__1);
      setState(35);
      match(BehaviorsParser::NEWLINE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(36);
      match(BehaviorsParser::NUMBER);
      setState(37);
      match(BehaviorsParser::T__4);
      setState(38);
      match(BehaviorsParser::PERSON_TYPE);
      setState(39);
      match(BehaviorsParser::T__1);
      setState(40);
      match(BehaviorsParser::NEWLINE);
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

//----------------- DescriptionContext ------------------------------------------------------------------

BehaviorsParser::DescriptionContext::DescriptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::DescriptionContext::PERSON_TYPE() {
  return getToken(BehaviorsParser::PERSON_TYPE, 0);
}


size_t BehaviorsParser::DescriptionContext::getRuleIndex() const {
  return BehaviorsParser::RuleDescription;
}


antlrcpp::Any BehaviorsParser::DescriptionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitDescription(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::DescriptionContext* BehaviorsParser::description() {
  DescriptionContext *_localctx = _tracker.createInstance<DescriptionContext>(_ctx, getState());
  enterRule(_localctx, 8, BehaviorsParser::RuleDescription);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    match(BehaviorsParser::T__5);
    setState(44);
    match(BehaviorsParser::PERSON_TYPE);
    setState(45);
    match(BehaviorsParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StateContext ------------------------------------------------------------------

BehaviorsParser::StateContext::StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorsParser::StateContext::getRuleIndex() const {
  return BehaviorsParser::RuleState;
}

void BehaviorsParser::StateContext::copyFrom(StateContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AwakeContext ------------------------------------------------------------------

BehaviorsParser::AwakeContext::AwakeContext(StateContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BehaviorsParser::AwakeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitAwake(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SleepingContext ------------------------------------------------------------------

BehaviorsParser::SleepingContext::SleepingContext(StateContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BehaviorsParser::SleepingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitSleeping(this);
  else
    return visitor->visitChildren(this);
}
BehaviorsParser::StateContext* BehaviorsParser::state() {
  StateContext *_localctx = _tracker.createInstance<StateContext>(_ctx, getState());
  enterRule(_localctx, 10, BehaviorsParser::RuleState);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorsParser::T__7: {
        _localctx = dynamic_cast<StateContext *>(_tracker.createInstance<BehaviorsParser::AwakeContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(47);
        match(BehaviorsParser::T__7);
        break;
      }

      case BehaviorsParser::T__8: {
        _localctx = dynamic_cast<StateContext *>(_tracker.createInstance<BehaviorsParser::SleepingContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(48);
        match(BehaviorsParser::T__8);
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

// Static vars and initialization.
std::vector<dfa::DFA> BehaviorsParser::_decisionToDFA;
atn::PredictionContextCache BehaviorsParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN BehaviorsParser::_atn;
std::vector<uint16_t> BehaviorsParser::_serializedATN;

std::vector<std::string> BehaviorsParser::_ruleNames = {
  "program", "statement", "consideration", "count", "description", "state"
};

std::vector<std::string> BehaviorsParser::_literalNames = {
  "", "'Consider a '", "'.'", "'Consider an '", "'% of the population are a '", 
  "'% of the population are an '", "'A '", "' pauses movement randomly for 1 minute.'", 
  "'AWAKE'", "'SLEEPING'", "", "", "", "' '"
};

std::vector<std::string> BehaviorsParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "PERSON_TYPE", "NUMBER", "NEWLINE", 
  "WHITESPACE"
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
       0x3, 0xf, 0x36, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x3, 0x2, 0x6, 0x2, 0x10, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x11, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
       0x20, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x2c, 
       0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
       0x7, 0x5, 0x7, 0x34, 0xa, 0x7, 0x3, 0x7, 0x2, 0x2, 0x8, 0x2, 0x4, 
       0x6, 0x8, 0xa, 0xc, 0x2, 0x2, 0x2, 0x33, 0x2, 0xf, 0x3, 0x2, 0x2, 
       0x2, 0x4, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1f, 0x3, 0x2, 0x2, 0x2, 
       0x8, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xc, 
       0x33, 0x3, 0x2, 0x2, 0x2, 0xe, 0x10, 0x5, 0x4, 0x3, 0x2, 0xf, 0xe, 
       0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x3, 0x2, 0x2, 0x2, 0x11, 0xf, 0x3, 
       0x2, 0x2, 0x2, 0x11, 0x12, 0x3, 0x2, 0x2, 0x2, 0x12, 0x3, 0x3, 0x2, 
       0x2, 0x2, 0x13, 0x14, 0x5, 0x6, 0x4, 0x2, 0x14, 0x15, 0x5, 0x8, 0x5, 
       0x2, 0x15, 0x16, 0x5, 0xa, 0x6, 0x2, 0x16, 0x5, 0x3, 0x2, 0x2, 0x2, 
       0x17, 0x18, 0x7, 0x3, 0x2, 0x2, 0x18, 0x19, 0x7, 0xc, 0x2, 0x2, 0x19, 
       0x1a, 0x7, 0x4, 0x2, 0x2, 0x1a, 0x20, 0x7, 0xe, 0x2, 0x2, 0x1b, 0x1c, 
       0x7, 0x5, 0x2, 0x2, 0x1c, 0x1d, 0x7, 0xc, 0x2, 0x2, 0x1d, 0x1e, 0x7, 
       0x4, 0x2, 0x2, 0x1e, 0x20, 0x7, 0xe, 0x2, 0x2, 0x1f, 0x17, 0x3, 0x2, 
       0x2, 0x2, 0x1f, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x20, 0x7, 0x3, 0x2, 0x2, 
       0x2, 0x21, 0x22, 0x7, 0xd, 0x2, 0x2, 0x22, 0x23, 0x7, 0x6, 0x2, 0x2, 
       0x23, 0x24, 0x7, 0xc, 0x2, 0x2, 0x24, 0x25, 0x7, 0x4, 0x2, 0x2, 0x25, 
       0x2c, 0x7, 0xe, 0x2, 0x2, 0x26, 0x27, 0x7, 0xd, 0x2, 0x2, 0x27, 0x28, 
       0x7, 0x7, 0x2, 0x2, 0x28, 0x29, 0x7, 0xc, 0x2, 0x2, 0x29, 0x2a, 0x7, 
       0x4, 0x2, 0x2, 0x2a, 0x2c, 0x7, 0xe, 0x2, 0x2, 0x2b, 0x21, 0x3, 0x2, 
       0x2, 0x2, 0x2b, 0x26, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x9, 0x3, 0x2, 0x2, 
       0x2, 0x2d, 0x2e, 0x7, 0x8, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0xc, 0x2, 0x2, 
       0x2f, 0x30, 0x7, 0x9, 0x2, 0x2, 0x30, 0xb, 0x3, 0x2, 0x2, 0x2, 0x31, 
       0x34, 0x7, 0xa, 0x2, 0x2, 0x32, 0x34, 0x7, 0xb, 0x2, 0x2, 0x33, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0xd, 0x3, 
       0x2, 0x2, 0x2, 0x6, 0x11, 0x1f, 0x2b, 0x33, 
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
