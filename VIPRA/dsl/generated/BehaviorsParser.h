
// Generated from Behaviors.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  BehaviorsParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, ID = 35, NUMBER = 36, COMMENT = 37, LINE_COMMENT = 38, 
    WHITESPACE = 39
  };

  enum {
    RuleProgram = 0, RuleStatement = 1, RuleConsideration = 2, RuleStateSelector = 3, 
    RuleIdRatioSelector = 4, RuleRandomIdRatioStatement = 5, RuleRandomIdRatioSelector = 6, 
    RuleEveryoneSelector = 7, RuleEnvironmentStateDeclaration = 8, RuleStateDeclaration = 9, 
    RulePedestrianSelected = 10, RuleStateCondition = 11, RuleStateTransition = 12, 
    RuleFasterOrSlower = 13, RuleTowardOrAwayFrom = 14, RuleTarget = 15, 
    RuleStoppedBehavior = 16, RuleWalkSpeedBehavior = 17, RuleNormalBehavior = 18, 
    RuleStateAction = 19
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
  class RandomIdRatioStatementContext;
  class RandomIdRatioSelectorContext;
  class EveryoneSelectorContext;
  class EnvironmentStateDeclarationContext;
  class StateDeclarationContext;
  class PedestrianSelectedContext;
  class StateConditionContext;
  class StateTransitionContext;
  class FasterOrSlowerContext;
  class TowardOrAwayFromContext;
  class TargetContext;
  class StoppedBehaviorContext;
  class WalkSpeedBehaviorContext;
  class NormalBehaviorContext;
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
    EnvironmentStateDeclarationContext *environmentStateDeclaration();
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
    EveryoneSelectorContext *everyoneSelector();


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

  class  RandomIdRatioStatementContext : public antlr4::ParserRuleContext {
  public:
    RandomIdRatioStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RandomIdRatioStatementContext* randomIdRatioStatement();

  class  RandomIdRatioSelectorContext : public antlr4::ParserRuleContext {
  public:
    RandomIdRatioSelectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RandomIdRatioSelectorContext() = default;
    void copyFrom(RandomIdRatioSelectorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NoGroupRandomIdSelectorContext : public RandomIdRatioSelectorContext {
  public:
    NoGroupRandomIdSelectorContext(RandomIdRatioSelectorContext *ctx);

    RandomIdRatioStatementContext *randomIdRatioStatement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GroupingRandomIdSelectorContext : public RandomIdRatioSelectorContext {
  public:
    GroupingRandomIdSelectorContext(RandomIdRatioSelectorContext *ctx);

    RandomIdRatioStatementContext *randomIdRatioStatement();
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RandomIdRatioSelectorContext* randomIdRatioSelector();

  class  EveryoneSelectorContext : public antlr4::ParserRuleContext {
  public:
    EveryoneSelectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EveryoneSelectorContext* everyoneSelector();

  class  EnvironmentStateDeclarationContext : public antlr4::ParserRuleContext {
  public:
    EnvironmentStateDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnvironmentStateDeclarationContext* environmentStateDeclaration();

  class  StateDeclarationContext : public antlr4::ParserRuleContext {
  public:
    StateDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StateDeclarationContext* stateDeclaration();

  class  PedestrianSelectedContext : public antlr4::ParserRuleContext {
  public:
    PedestrianSelectedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PedestrianSelectedContext* pedestrianSelected();

  class  StateConditionContext : public antlr4::ParserRuleContext {
  public:
    StateConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StateConditionContext* stateCondition();

  class  StateTransitionContext : public antlr4::ParserRuleContext {
  public:
    StateTransitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PedestrianSelectedContext *pedestrianSelected();
    antlr4::tree::TerminalNode *ID();
    StateConditionContext *stateCondition();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StateTransitionContext* stateTransition();

  class  FasterOrSlowerContext : public antlr4::ParserRuleContext {
  public:
    FasterOrSlowerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FasterOrSlowerContext* fasterOrSlower();

  class  TowardOrAwayFromContext : public antlr4::ParserRuleContext {
  public:
    TowardOrAwayFromContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TowardOrAwayFromContext* towardOrAwayFrom();

  class  TargetContext : public antlr4::ParserRuleContext {
  public:
    TargetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TargetContext* target();

  class  StoppedBehaviorContext : public antlr4::ParserRuleContext {
  public:
    StoppedBehaviorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StoppedBehaviorContext* stoppedBehavior();

  class  WalkSpeedBehaviorContext : public antlr4::ParserRuleContext {
  public:
    WalkSpeedBehaviorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    FasterOrSlowerContext *fasterOrSlower();
    TowardOrAwayFromContext *towardOrAwayFrom();
    TargetContext *target();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WalkSpeedBehaviorContext* walkSpeedBehavior();

  class  NormalBehaviorContext : public antlr4::ParserRuleContext {
  public:
    NormalBehaviorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NormalBehaviorContext* normalBehavior();

  class  StateActionContext : public antlr4::ParserRuleContext {
  public:
    StateActionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StateActionContext() = default;
    void copyFrom(StateActionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StateActionStoppedContext : public StateActionContext {
  public:
    StateActionStoppedContext(StateActionContext *ctx);

    PedestrianSelectedContext *pedestrianSelected();
    StoppedBehaviorContext *stoppedBehavior();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StateActionNormalContext : public StateActionContext {
  public:
    StateActionNormalContext(StateActionContext *ctx);

    PedestrianSelectedContext *pedestrianSelected();
    NormalBehaviorContext *normalBehavior();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StateActionWalkSpeedContext : public StateActionContext {
  public:
    StateActionWalkSpeedContext(StateActionContext *ctx);

    PedestrianSelectedContext *pedestrianSelected();
    WalkSpeedBehaviorContext *walkSpeedBehavior();

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

