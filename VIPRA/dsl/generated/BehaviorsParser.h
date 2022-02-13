
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
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, ID = 38, 
    NUMBER = 39, COMMENT = 40, LINE_COMMENT = 41, WHITESPACE = 42
  };

  enum {
    RuleProgram = 0, RuleStatement = 1, RuleConsideration = 2, RuleStateSelector = 3, 
    RuleIdRatioSelector = 4, RuleExactlyNRandomSelector = 5, RuleRandomIdRatioStatement = 6, 
    RuleRandomIdRatioSelector = 7, RuleConditionElapsedTime = 8, RuleConditionEnvironmentState = 9, 
    RuleEveryoneSelector = 10, RuleEnvironmentStateDeclaration = 11, RuleEnvironmentInitialStateDeclaration = 12, 
    RuleEnvironmentTransition = 13, RuleStateDeclaration = 14, RuleInitialStateDeclaration = 15, 
    RulePedestrianSelected = 16, RuleStateTransitionElapsedTime = 17, RuleStateTransitionEnvironmentState = 18, 
    RuleFasterOrSlower = 19, RuleTowardOrAwayFrom = 20, RuleTarget = 21, 
    RuleStoppedBehavior = 22, RuleWalkSpeedBehavior = 23, RuleWalkSpeedWithTargetBehavior = 24, 
    RuleNormalBehavior = 25, RuleStateAction = 26
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
  class ExactlyNRandomSelectorContext;
  class RandomIdRatioStatementContext;
  class RandomIdRatioSelectorContext;
  class ConditionElapsedTimeContext;
  class ConditionEnvironmentStateContext;
  class EveryoneSelectorContext;
  class EnvironmentStateDeclarationContext;
  class EnvironmentInitialStateDeclarationContext;
  class EnvironmentTransitionContext;
  class StateDeclarationContext;
  class InitialStateDeclarationContext;
  class PedestrianSelectedContext;
  class StateTransitionElapsedTimeContext;
  class StateTransitionEnvironmentStateContext;
  class FasterOrSlowerContext;
  class TowardOrAwayFromContext;
  class TargetContext;
  class StoppedBehaviorContext;
  class WalkSpeedBehaviorContext;
  class WalkSpeedWithTargetBehaviorContext;
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
    InitialStateDeclarationContext *initialStateDeclaration();
    EnvironmentStateDeclarationContext *environmentStateDeclaration();
    EnvironmentInitialStateDeclarationContext *environmentInitialStateDeclaration();
    EnvironmentTransitionContext *environmentTransition();
    StateTransitionElapsedTimeContext *stateTransitionElapsedTime();
    StateTransitionEnvironmentStateContext *stateTransitionEnvironmentState();
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
    ExactlyNRandomSelectorContext *exactlyNRandomSelector();
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

  class  ExactlyNRandomSelectorContext : public antlr4::ParserRuleContext {
  public:
    ExactlyNRandomSelectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExactlyNRandomSelectorContext* exactlyNRandomSelector();

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

  class  ConditionElapsedTimeContext : public antlr4::ParserRuleContext {
  public:
    ConditionElapsedTimeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionElapsedTimeContext* conditionElapsedTime();

  class  ConditionEnvironmentStateContext : public antlr4::ParserRuleContext {
  public:
    ConditionEnvironmentStateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionEnvironmentStateContext* conditionEnvironmentState();

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

  class  EnvironmentInitialStateDeclarationContext : public antlr4::ParserRuleContext {
  public:
    EnvironmentInitialStateDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnvironmentInitialStateDeclarationContext* environmentInitialStateDeclaration();

  class  EnvironmentTransitionContext : public antlr4::ParserRuleContext {
  public:
    EnvironmentTransitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    ConditionElapsedTimeContext *conditionElapsedTime();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnvironmentTransitionContext* environmentTransition();

  class  StateDeclarationContext : public antlr4::ParserRuleContext {
  public:
    StateDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StateDeclarationContext* stateDeclaration();

  class  InitialStateDeclarationContext : public antlr4::ParserRuleContext {
  public:
    InitialStateDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitialStateDeclarationContext* initialStateDeclaration();

  class  PedestrianSelectedContext : public antlr4::ParserRuleContext {
  public:
    PedestrianSelectedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PedestrianSelectedContext* pedestrianSelected();

  class  StateTransitionElapsedTimeContext : public antlr4::ParserRuleContext {
  public:
    StateTransitionElapsedTimeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PedestrianSelectedContext *pedestrianSelected();
    antlr4::tree::TerminalNode *ID();
    ConditionElapsedTimeContext *conditionElapsedTime();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StateTransitionElapsedTimeContext* stateTransitionElapsedTime();

  class  StateTransitionEnvironmentStateContext : public antlr4::ParserRuleContext {
  public:
    StateTransitionEnvironmentStateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PedestrianSelectedContext *pedestrianSelected();
    antlr4::tree::TerminalNode *ID();
    ConditionEnvironmentStateContext *conditionEnvironmentState();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StateTransitionEnvironmentStateContext* stateTransitionEnvironmentState();

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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WalkSpeedBehaviorContext* walkSpeedBehavior();

  class  WalkSpeedWithTargetBehaviorContext : public antlr4::ParserRuleContext {
  public:
    WalkSpeedWithTargetBehaviorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    FasterOrSlowerContext *fasterOrSlower();
    TowardOrAwayFromContext *towardOrAwayFrom();
    TargetContext *target();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WalkSpeedWithTargetBehaviorContext* walkSpeedWithTargetBehavior();

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

  class  StateActionWalkSpeedWithTargetContext : public StateActionContext {
  public:
    StateActionWalkSpeedWithTargetContext(StateActionContext *ctx);

    PedestrianSelectedContext *pedestrianSelected();
    WalkSpeedWithTargetBehaviorContext *walkSpeedWithTargetBehavior();

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

