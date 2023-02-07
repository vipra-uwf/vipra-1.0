
// Generated from Behavior.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  BehaviorParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, ID = 26, 
    STATE = 27, ACTION = 28, ATTRIBUTE = 29, PARAMETER = 30, NUMBER = 31, 
    COMMENT = 32, LINE_COMMENT = 33, WS = 34, AN = 35, AND = 36, OR = 37, 
    ANDOR = 38, COMMA = 39, COLON = 40, THE = 41, GIVEN = 42, SET = 43, 
    PARAMETERS = 44, FASTERorSLOWER = 45, Direction = 46
  };

  enum {
    RuleProgram = 0, RuleStatement = 1, RuleTransition_Environment = 2, 
    RuleTransition_Pedestrian = 3, RuleCondition = 4, RuleSub_condition = 5, 
    RuleCondition_Existance = 6, RuleCondition_State = 7, RuleCondition_Others_State = 8, 
    RuleCondition_Time_Elapsed = 9, RuleState_Check = 10, RuleState_Set = 11, 
    RuleObject = 12, RulePed_Selector = 13, RuleSelector_Percent = 14, RuleSelector_Exactly_N_Random = 15, 
    RuleSelector_Everyone = 16, RuleAction = 17, RuleConditional_action = 18, 
    RuleUn_conditional_action = 19, RuleSub_action = 20, RuleAction_atom = 21, 
    RuleAction_Stop = 22, RuleAction_atom_Percent_Walk_Speed = 23, RuleDeclaration = 24, 
    RuleDecl_Ped = 25, RuleDecl_Ped_State = 26, RuleDecl_Env_State = 27, 
    RuleDecl_Parameters = 28
  };

  BehaviorParser(antlr4::TokenStream *input);
  ~BehaviorParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class StatementContext;
  class Transition_EnvironmentContext;
  class Transition_PedestrianContext;
  class ConditionContext;
  class Sub_conditionContext;
  class Condition_ExistanceContext;
  class Condition_StateContext;
  class Condition_Others_StateContext;
  class Condition_Time_ElapsedContext;
  class State_CheckContext;
  class State_SetContext;
  class ObjectContext;
  class Ped_SelectorContext;
  class Selector_PercentContext;
  class Selector_Exactly_N_RandomContext;
  class Selector_EveryoneContext;
  class ActionContext;
  class Conditional_actionContext;
  class Un_conditional_actionContext;
  class Sub_actionContext;
  class Action_atomContext;
  class Action_StopContext;
  class Action_atom_Percent_Walk_SpeedContext;
  class DeclarationContext;
  class Decl_PedContext;
  class Decl_Ped_StateContext;
  class Decl_Env_StateContext;
  class Decl_ParametersContext; 

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
    DeclarationContext *declaration();
    Ped_SelectorContext *ped_Selector();
    ActionContext *action();
    Transition_EnvironmentContext *transition_Environment();
    Transition_PedestrianContext *transition_Pedestrian();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  Transition_EnvironmentContext : public antlr4::ParserRuleContext {
  public:
    Transition_EnvironmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    State_SetContext *state_Set();
    ConditionContext *condition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Transition_EnvironmentContext* transition_Environment();

  class  Transition_PedestrianContext : public antlr4::ParserRuleContext {
  public:
    Transition_PedestrianContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *ID();
    State_SetContext *state_Set();
    ConditionContext *condition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Transition_PedestrianContext* transition_Pedestrian();

  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sub_conditionContext *sub_condition();
    antlr4::tree::TerminalNode *ANDOR();
    ConditionContext *condition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionContext* condition();

  class  Sub_conditionContext : public antlr4::ParserRuleContext {
  public:
    Sub_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Condition_StateContext *condition_State();
    Condition_Time_ElapsedContext *condition_Time_Elapsed();
    Condition_ExistanceContext *condition_Existance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sub_conditionContext* sub_condition();

  class  Condition_ExistanceContext : public antlr4::ParserRuleContext {
  public:
    Condition_ExistanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GIVEN();
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Direction();
    Condition_Others_StateContext *condition_Others_State();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_ExistanceContext* condition_Existance();

  class  Condition_StateContext : public antlr4::ParserRuleContext {
  public:
    Condition_StateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GIVEN();
    ObjectContext *object();
    State_CheckContext *state_Check();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_StateContext* condition_State();

  class  Condition_Others_StateContext : public antlr4::ParserRuleContext {
  public:
    Condition_Others_StateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    State_CheckContext *state_Check();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_Others_StateContext* condition_Others_State();

  class  Condition_Time_ElapsedContext : public antlr4::ParserRuleContext {
  public:
    Condition_Time_ElapsedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_Time_ElapsedContext* condition_Time_Elapsed();

  class  State_CheckContext : public antlr4::ParserRuleContext {
  public:
    State_CheckContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STATE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  State_CheckContext* state_Check();

  class  State_SetContext : public antlr4::ParserRuleContext {
  public:
    State_SetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STATE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  State_SetContext* state_Set();

  class  ObjectContext : public antlr4::ParserRuleContext {
  public:
    ObjectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjectContext* object();

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
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_PercentContext* selector_Percent();

  class  Selector_Exactly_N_RandomContext : public antlr4::ParserRuleContext {
  public:
    Selector_Exactly_N_RandomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_Exactly_N_RandomContext* selector_Exactly_N_Random();

  class  Selector_EveryoneContext : public antlr4::ParserRuleContext {
  public:
    Selector_EveryoneContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_EveryoneContext* selector_Everyone();

  class  ActionContext : public antlr4::ParserRuleContext {
  public:
    ActionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Conditional_actionContext *conditional_action();
    Un_conditional_actionContext *un_conditional_action();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActionContext* action();

  class  Conditional_actionContext : public antlr4::ParserRuleContext {
  public:
    Conditional_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *ID();
    Sub_actionContext *sub_action();
    ConditionContext *condition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Conditional_actionContext* conditional_action();

  class  Un_conditional_actionContext : public antlr4::ParserRuleContext {
  public:
    Un_conditional_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *ID();
    Sub_actionContext *sub_action();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Un_conditional_actionContext* un_conditional_action();

  class  Sub_actionContext : public antlr4::ParserRuleContext {
  public:
    Sub_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Action_atomContext *> action_atom();
    Action_atomContext* action_atom(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sub_actionContext* sub_action();

  class  Action_atomContext : public antlr4::ParserRuleContext {
  public:
    Action_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACTION();
    State_SetContext *state_Set();
    Action_StopContext *action_Stop();
    Action_atom_Percent_Walk_SpeedContext *action_atom_Percent_Walk_Speed();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_atomContext* action_atom();

  class  Action_StopContext : public antlr4::ParserRuleContext {
  public:
    Action_StopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_StopContext* action_Stop();

  class  Action_atom_Percent_Walk_SpeedContext : public antlr4::ParserRuleContext {
  public:
    Action_atom_Percent_Walk_SpeedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *FASTERorSLOWER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_atom_Percent_Walk_SpeedContext* action_atom_Percent_Walk_Speed();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Decl_PedContext *decl_Ped();
    Decl_Ped_StateContext *decl_Ped_State();
    Decl_Env_StateContext *decl_Env_State();
    Decl_ParametersContext *decl_Parameters();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  Decl_PedContext : public antlr4::ParserRuleContext {
  public:
    Decl_PedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_PedContext* decl_Ped();

  class  Decl_Ped_StateContext : public antlr4::ParserRuleContext {
  public:
    Decl_Ped_StateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_Ped_StateContext* decl_Ped_State();

  class  Decl_Env_StateContext : public antlr4::ParserRuleContext {
  public:
    Decl_Env_StateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_Env_StateContext* decl_Env_State();

  class  Decl_ParametersContext : public antlr4::ParserRuleContext {
  public:
    Decl_ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PARAMETERS();
    std::vector<antlr4::tree::TerminalNode *> PARAMETER();
    antlr4::tree::TerminalNode* PARAMETER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_ParametersContext* decl_Parameters();


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

