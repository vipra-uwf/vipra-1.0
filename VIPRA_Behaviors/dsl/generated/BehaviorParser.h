
// Generated from Behavior.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  BehaviorParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, A = 12, END = 13, ID = 14, 
    STATE = 15, NUMBER = 16, PERCENT = 17, COMMENT = 18, LINE_COMMENT = 19, 
    WS = 20, Direction = 21
  };

  enum {
    RuleProgram = 0, RuleConsideration = 1, RuleStatement = 2, RulePed_Selector = 3, 
    RuleSelector_Percent = 4, RuleSelector_Exactly_N_Random = 5, RuleSelector_Everyone = 6, 
    RuleCondition = 7, RuleSub_condition = 8, RuleCondition_Existance = 9, 
    RuleCondition_State = 10
  };

  BehaviorParser(antlr4::TokenStream *input);
  ~BehaviorParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class ConsiderationContext;
  class StatementContext;
  class Ped_SelectorContext;
  class Selector_PercentContext;
  class Selector_Exactly_N_RandomContext;
  class Selector_EveryoneContext;
  class ConditionContext;
  class Sub_conditionContext;
  class Condition_ExistanceContext;
  class Condition_StateContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConsiderationContext *consideration();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ConsiderationContext : public antlr4::ParserRuleContext {
  public:
    ConsiderationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *A();
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConsiderationContext* consideration();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ped_SelectorContext *ped_Selector();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  Ped_SelectorContext : public antlr4::ParserRuleContext {
  public:
    Ped_SelectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Selector_PercentContext *selector_Percent();
    Selector_Exactly_N_RandomContext *selector_Exactly_N_Random();
    Selector_EveryoneContext *selector_Everyone();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ped_SelectorContext* ped_Selector();

  class  Selector_PercentContext : public antlr4::ParserRuleContext {
  public:
    Selector_PercentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    antlr4::tree::TerminalNode *A();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *END();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_PercentContext* selector_Percent();

  class  Selector_Exactly_N_RandomContext : public antlr4::ParserRuleContext {
  public:
    Selector_Exactly_N_RandomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *A();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *END();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_Exactly_N_RandomContext* selector_Exactly_N_Random();

  class  Selector_EveryoneContext : public antlr4::ParserRuleContext {
  public:
    Selector_EveryoneContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *A();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *END();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_EveryoneContext* selector_Everyone();

  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    Sub_conditionContext *sub_condition();
    ConditionContext *condition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionContext* condition();

  class  Sub_conditionContext : public antlr4::ParserRuleContext {
  public:
    Sub_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Condition_ExistanceContext *condition_Existance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sub_conditionContext* sub_condition();

  class  Condition_ExistanceContext : public antlr4::ParserRuleContext {
  public:
    Condition_ExistanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *A();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Direction();
    Condition_StateContext *condition_State();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_ExistanceContext* condition_Existance();

  class  Condition_StateContext : public antlr4::ParserRuleContext {
  public:
    Condition_StateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STATE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_StateContext* condition_State();


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

