
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
    setState(15); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(14);
      statement();
      setState(17); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BehaviorsParser::T__0)
      | (1ULL << BehaviorsParser::T__2)
      | (1ULL << BehaviorsParser::T__5)
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
    setState(24);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(19);
      consideration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(20);
      stateSelector();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(21);
      stateDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(22);
      stateTransition();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(23);
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
    setState(34);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorsParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(26);
        match(BehaviorsParser::T__0);
        setState(27);
        match(BehaviorsParser::ID);
        setState(28);
        match(BehaviorsParser::T__1);
        setState(29);
        match(BehaviorsParser::NEWLINE);
        break;
      }

      case BehaviorsParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(30);
        match(BehaviorsParser::T__2);
        setState(31);
        match(BehaviorsParser::ID);
        setState(32);
        match(BehaviorsParser::T__1);
        setState(33);
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

//----------------- StateSelectorContext ------------------------------------------------------------------

BehaviorsParser::StateSelectorContext::StateSelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorsParser::StateSelectorContext::NUMBER() {
  return getToken(BehaviorsParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorsParser::StateSelectorContext::ID() {
  return getToken(BehaviorsParser::ID, 0);
}

tree::TerminalNode* BehaviorsParser::StateSelectorContext::NEWLINE() {
  return getToken(BehaviorsParser::NEWLINE, 0);
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
    setState(46);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(36);
      match(BehaviorsParser::NUMBER);
      setState(37);
      match(BehaviorsParser::T__3);
      setState(38);
      match(BehaviorsParser::ID);
      setState(39);
      match(BehaviorsParser::T__1);
      setState(40);
      match(BehaviorsParser::NEWLINE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(41);
      match(BehaviorsParser::NUMBER);
      setState(42);
      match(BehaviorsParser::T__4);
      setState(43);
      match(BehaviorsParser::ID);
      setState(44);
      match(BehaviorsParser::T__1);
      setState(45);
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

tree::TerminalNode* BehaviorsParser::StateDeclarationContext::NEWLINE() {
  return getToken(BehaviorsParser::NEWLINE, 0);
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
  enterRule(_localctx, 8, BehaviorsParser::RuleStateDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(BehaviorsParser::T__5);
    setState(49);
    match(BehaviorsParser::ID);
    setState(50);
    match(BehaviorsParser::T__6);
    setState(51);
    match(BehaviorsParser::ID);
    setState(52);
    match(BehaviorsParser::T__1);
    setState(53);
    match(BehaviorsParser::NEWLINE);
   
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

std::vector<tree::TerminalNode *> BehaviorsParser::StateTransitionContext::ID() {
  return getTokens(BehaviorsParser::ID);
}

tree::TerminalNode* BehaviorsParser::StateTransitionContext::ID(size_t i) {
  return getToken(BehaviorsParser::ID, i);
}

tree::TerminalNode* BehaviorsParser::StateTransitionContext::NUMBER() {
  return getToken(BehaviorsParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorsParser::StateTransitionContext::NEWLINE() {
  return getToken(BehaviorsParser::NEWLINE, 0);
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
  enterRule(_localctx, 10, BehaviorsParser::RuleStateTransition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    match(BehaviorsParser::T__5);
    setState(56);
    match(BehaviorsParser::ID);
    setState(57);
    match(BehaviorsParser::T__7);
    setState(58);
    match(BehaviorsParser::ID);
    setState(59);
    match(BehaviorsParser::T__8);
    setState(60);
    match(BehaviorsParser::ID);
    setState(61);
    match(BehaviorsParser::T__9);
    setState(62);
    match(BehaviorsParser::NUMBER);
    setState(63);
    match(BehaviorsParser::T__10);
    setState(64);
    match(BehaviorsParser::NEWLINE);
   
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

std::vector<tree::TerminalNode *> BehaviorsParser::StateActionContext::ID() {
  return getTokens(BehaviorsParser::ID);
}

tree::TerminalNode* BehaviorsParser::StateActionContext::ID(size_t i) {
  return getToken(BehaviorsParser::ID, i);
}

tree::TerminalNode* BehaviorsParser::StateActionContext::NEWLINE() {
  return getToken(BehaviorsParser::NEWLINE, 0);
}


size_t BehaviorsParser::StateActionContext::getRuleIndex() const {
  return BehaviorsParser::RuleStateAction;
}


antlrcpp::Any BehaviorsParser::StateActionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorsVisitor*>(visitor))
    return parserVisitor->visitStateAction(this);
  else
    return visitor->visitChildren(this);
}

BehaviorsParser::StateActionContext* BehaviorsParser::stateAction() {
  StateActionContext *_localctx = _tracker.createInstance<StateActionContext>(_ctx, getState());
  enterRule(_localctx, 12, BehaviorsParser::RuleStateAction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(BehaviorsParser::T__5);
    setState(67);
    match(BehaviorsParser::ID);
    setState(68);
    match(BehaviorsParser::T__7);
    setState(69);
    match(BehaviorsParser::ID);
    setState(70);
    match(BehaviorsParser::T__11);
    setState(71);
    match(BehaviorsParser::ID);
    setState(72);
    match(BehaviorsParser::T__1);
    setState(73);
    match(BehaviorsParser::NEWLINE);
   
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
  "program", "statement", "consideration", "stateSelector", "stateDeclaration", 
  "stateTransition", "stateAction"
};

std::vector<std::string> BehaviorsParser::_literalNames = {
  "", "'Consider a '", "'.'", "'Consider an '", "'% of the population are a '", 
  "'% of the population are an '", "'A '", "' can be '", "' who is '", "' will be '", 
  "' after '", "' seconds.'", "' is '", "", "", "", "' '"
};

std::vector<std::string> BehaviorsParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", "NUMBER", "NEWLINE", 
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
       0x3, 0x12, 0x4e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x3, 0x2, 0x6, 0x2, 0x12, 0xa, 0x2, 0xd, 
       0x2, 0xe, 0x2, 0x13, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x5, 0x3, 0x1b, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x25, 0xa, 
       0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x31, 0xa, 0x5, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x2, 0x2, 0x9, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
       0xe, 0x2, 0x2, 0x2, 0x4d, 0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1a, 
       0x3, 0x2, 0x2, 0x2, 0x6, 0x24, 0x3, 0x2, 0x2, 0x2, 0x8, 0x30, 0x3, 
       0x2, 0x2, 0x2, 0xa, 0x32, 0x3, 0x2, 0x2, 0x2, 0xc, 0x39, 0x3, 0x2, 
       0x2, 0x2, 0xe, 0x44, 0x3, 0x2, 0x2, 0x2, 0x10, 0x12, 0x5, 0x4, 0x3, 
       0x2, 0x11, 0x10, 0x3, 0x2, 0x2, 0x2, 0x12, 0x13, 0x3, 0x2, 0x2, 0x2, 
       0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 0x3, 0x2, 0x2, 0x2, 0x14, 
       0x3, 0x3, 0x2, 0x2, 0x2, 0x15, 0x1b, 0x5, 0x6, 0x4, 0x2, 0x16, 0x1b, 
       0x5, 0x8, 0x5, 0x2, 0x17, 0x1b, 0x5, 0xa, 0x6, 0x2, 0x18, 0x1b, 0x5, 
       0xc, 0x7, 0x2, 0x19, 0x1b, 0x5, 0xe, 0x8, 0x2, 0x1a, 0x15, 0x3, 0x2, 
       0x2, 0x2, 0x1a, 0x16, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x17, 0x3, 0x2, 0x2, 
       0x2, 0x1a, 0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 
       0x1b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x7, 0x3, 0x2, 0x2, 0x1d, 
       0x1e, 0x7, 0xf, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0x4, 0x2, 0x2, 0x1f, 0x25, 
       0x7, 0x11, 0x2, 0x2, 0x20, 0x21, 0x7, 0x5, 0x2, 0x2, 0x21, 0x22, 
       0x7, 0xf, 0x2, 0x2, 0x22, 0x23, 0x7, 0x4, 0x2, 0x2, 0x23, 0x25, 0x7, 
       0x11, 0x2, 0x2, 0x24, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x24, 0x20, 0x3, 
       0x2, 0x2, 0x2, 0x25, 0x7, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x7, 0x10, 
       0x2, 0x2, 0x27, 0x28, 0x7, 0x6, 0x2, 0x2, 0x28, 0x29, 0x7, 0xf, 0x2, 
       0x2, 0x29, 0x2a, 0x7, 0x4, 0x2, 0x2, 0x2a, 0x31, 0x7, 0x11, 0x2, 
       0x2, 0x2b, 0x2c, 0x7, 0x10, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x7, 0x2, 
       0x2, 0x2d, 0x2e, 0x7, 0xf, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x4, 0x2, 0x2, 
       0x2f, 0x31, 0x7, 0x11, 0x2, 0x2, 0x30, 0x26, 0x3, 0x2, 0x2, 0x2, 
       0x30, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x31, 0x9, 0x3, 0x2, 0x2, 0x2, 0x32, 
       0x33, 0x7, 0x8, 0x2, 0x2, 0x33, 0x34, 0x7, 0xf, 0x2, 0x2, 0x34, 0x35, 
       0x7, 0x9, 0x2, 0x2, 0x35, 0x36, 0x7, 0xf, 0x2, 0x2, 0x36, 0x37, 0x7, 
       0x4, 0x2, 0x2, 0x37, 0x38, 0x7, 0x11, 0x2, 0x2, 0x38, 0xb, 0x3, 0x2, 
       0x2, 0x2, 0x39, 0x3a, 0x7, 0x8, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0xf, 0x2, 
       0x2, 0x3b, 0x3c, 0x7, 0xa, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0xf, 0x2, 0x2, 
       0x3d, 0x3e, 0x7, 0xb, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0xf, 0x2, 0x2, 0x3f, 
       0x40, 0x7, 0xc, 0x2, 0x2, 0x40, 0x41, 0x7, 0x10, 0x2, 0x2, 0x41, 
       0x42, 0x7, 0xd, 0x2, 0x2, 0x42, 0x43, 0x7, 0x11, 0x2, 0x2, 0x43, 
       0xd, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x8, 0x2, 0x2, 0x45, 0x46, 
       0x7, 0xf, 0x2, 0x2, 0x46, 0x47, 0x7, 0xa, 0x2, 0x2, 0x47, 0x48, 0x7, 
       0xf, 0x2, 0x2, 0x48, 0x49, 0x7, 0xe, 0x2, 0x2, 0x49, 0x4a, 0x7, 0xf, 
       0x2, 0x2, 0x4a, 0x4b, 0x7, 0x4, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x11, 
       0x2, 0x2, 0x4c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6, 0x13, 0x1a, 0x24, 0x30, 
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
