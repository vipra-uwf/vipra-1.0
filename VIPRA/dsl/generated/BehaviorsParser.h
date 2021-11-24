
// Generated from Behaviors.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  BehaviorsParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, ID = 17, NUMBER = 18, COMMENT = 19, LINE_COMMENT = 20, 
    WHITESPACE = 21
  };

  enum {
    RuleProgram = 0, RuleStatement = 1, RuleConsideration = 2, RuleStateSelector = 3, 
    RuleIdRatioSelector = 4, RuleRandomIdRatioSelector = 5, RuleStateDeclaration = 6, 
    RuleStateTransition = 7, RuleStateAction = 8
  };

  explicit BehaviorsParser(antlr4::TokenStream *input);
  ~BehaviorsParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class StatementContext;
  class ConsiderationContext;
  class StateSelectorContext;
  class IdRatioSelectorContext;
  class RandomIdRatioSelectorContext;
  class StateDeclarationContext;
  class StateTransitionContext;
  class StateActionContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConsiderationContext *consideration();
    StateSelectorContext *stateSelector();
    StateDeclarationContext *stateDeclaration();
    StateTransitionContext *stateTransition();
    StateActionContext *stateAction();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  ConsiderationContext : public antlr4::ParserRuleContext {
  public:
    ConsiderationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConsiderationContext* consideration();

  class  StateSelectorContext : public antlr4::ParserRuleContext {
  public:
    StateSelectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdRatioSelectorContext *idRatioSelector();
    RandomIdRatioSelectorContext *randomIdRatioSelector();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StateSelectorContext* stateSelector();

  class  IdRatioSelectorContext : public antlr4::ParserRuleContext {
  public:
    IdRatioSelectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdRatioSelectorContext* idRatioSelector();

  class  RandomIdRatioSelectorContext : public antlr4::ParserRuleContext {
  public:
    RandomIdRatioSelectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RandomIdRatioSelectorContext* randomIdRatioSelector();

  class  StateDeclarationContext : public antlr4::ParserRuleContext {
  public:
    StateDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StateDeclarationContext* stateDeclaration();

  class  StateTransitionContext : public antlr4::ParserRuleContext {
  public:
    StateTransitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *NUMBER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StateTransitionContext* stateTransition();

  class  StateActionContext : public antlr4::ParserRuleContext {
  public:
    StateActionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StateActionContext* stateAction();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

