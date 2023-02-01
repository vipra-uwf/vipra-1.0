
// Generated from Behavior.g4 by ANTLR 4.7.2

#pragma once

#include "antlr4-runtime.h"

class BehaviorParser : public antlr4::Parser {
 public:
  enum {
    T__0 = 1,
    T__1 = 2,
    T__2 = 3,
    T__3 = 4,
    T__4 = 5,
    T__5 = 6,
    T__6 = 7,
    T__7 = 8,
    T__8 = 9,
    T__9 = 10,
    T__10 = 11,
    T__11 = 12,
    T__12 = 13,
    T__13 = 14,
    T__14 = 15,
    T__15 = 16,
    T__16 = 17,
    T__17 = 18,
    T__18 = 19,
    T__19 = 20,
    A = 21,
    AndOr = 22,
    END = 23,
    ID = 24,
    STATE = 25,
    NUMBER = 26,
    PERCENT = 27,
    COMMENT = 28,
    LINE_COMMENT = 29,
    WS = 30,
    Direction = 31
  };

  enum {
    RuleProgram = 0,
    RuleStatement = 1,
    RulePed_Selector = 2,
    RuleSelector_Percent = 3,
    RuleSelector_Exactly_N_Random = 4,
    RuleSelector_Everyone = 5,
    RuleCondition = 6,
    RuleSub_condition = 7,
    RuleCondition_Existance = 8,
    RuleCondition_State = 9,
    RuleCondition_Others_State = 10,
    RuleCondition_Env_State = 11,
    RuleAction = 12,
    RuleConditional_action = 13,
    RuleNon_conditional_action = 14,
    RuleSub_action = 15,
    RuleAction_atom = 16,
    RuleAction_Stop = 17,
    RuleDeclaration = 18,
    RuleDecl_Ped = 19,
    RuleDecl_Ped_State = 20,
    RuleDecl_Env_State = 21
  };

  BehaviorParser(antlr4::TokenStream* input);
  ~BehaviorParser();

  virtual std::string                     getGrammarFileName() const override;
  virtual const antlr4::atn::ATN&         getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override {
    return _tokenNames;
  };  // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary&        getVocabulary() const override;

  class ProgramContext;
  class StatementContext;
  class Ped_SelectorContext;
  class Selector_PercentContext;
  class Selector_Exactly_N_RandomContext;
  class Selector_EveryoneContext;
  class ConditionContext;
  class Sub_conditionContext;
  class Condition_ExistanceContext;
  class Condition_StateContext;
  class Condition_Others_StateContext;
  class Condition_Env_StateContext;
  class ActionContext;
  class Conditional_actionContext;
  class Non_conditional_actionContext;
  class Sub_actionContext;
  class Action_atomContext;
  class Action_StopContext;
  class DeclarationContext;
  class Decl_PedContext;
  class Decl_Ped_StateContext;
  class Decl_Env_StateContext;

  class ProgramContext : public antlr4::ParserRuleContext {
   public:
    ProgramContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t                 getRuleIndex() const override;
    std::vector<StatementContext*> statement();
    StatementContext*              statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  ProgramContext* program();

  class StatementContext : public antlr4::ParserRuleContext {
   public:
    StatementContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t       getRuleIndex() const override;
    DeclarationContext*  declaration();
    Ped_SelectorContext* ped_Selector();
    ActionContext*       action();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  StatementContext* statement();

  class Ped_SelectorContext : public antlr4::ParserRuleContext {
   public:
    Ped_SelectorContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t                    getRuleIndex() const override;
    Selector_PercentContext*          selector_Percent();
    Selector_Exactly_N_RandomContext* selector_Exactly_N_Random();
    Selector_EveryoneContext*         selector_Everyone();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Ped_SelectorContext* ped_Selector();

  class Selector_PercentContext : public antlr4::ParserRuleContext {
   public:
    Selector_PercentContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t                           getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode*> NUMBER();
    antlr4::tree::TerminalNode*              NUMBER(size_t i);
    antlr4::tree::TerminalNode*              A();
    antlr4::tree::TerminalNode*              ID();
    antlr4::tree::TerminalNode*              END();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Selector_PercentContext* selector_Percent();

  class Selector_Exactly_N_RandomContext : public antlr4::ParserRuleContext {
   public:
    Selector_Exactly_N_RandomContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t              getRuleIndex() const override;
    antlr4::tree::TerminalNode* NUMBER();
    antlr4::tree::TerminalNode* A();
    antlr4::tree::TerminalNode* ID();
    antlr4::tree::TerminalNode* END();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Selector_Exactly_N_RandomContext* selector_Exactly_N_Random();

  class Selector_EveryoneContext : public antlr4::ParserRuleContext {
   public:
    Selector_EveryoneContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t              getRuleIndex() const override;
    antlr4::tree::TerminalNode* A();
    antlr4::tree::TerminalNode* ID();
    antlr4::tree::TerminalNode* END();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Selector_EveryoneContext* selector_Everyone();

  class ConditionContext : public antlr4::ParserRuleContext {
   public:
    ConditionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t                           getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode*> WS();
    antlr4::tree::TerminalNode*              WS(size_t i);
    Sub_conditionContext*                    sub_condition();
    antlr4::tree::TerminalNode*              AndOr();
    ConditionContext*                        condition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  ConditionContext* condition();

  class Sub_conditionContext : public antlr4::ParserRuleContext {
   public:
    Sub_conditionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t              getRuleIndex() const override;
    Condition_StateContext*     condition_State();
    Condition_ExistanceContext* condition_Existance();
    Condition_Env_StateContext* condition_Env_State();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Sub_conditionContext* sub_condition();

  class Condition_ExistanceContext : public antlr4::ParserRuleContext {
   public:
    Condition_ExistanceContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t                 getRuleIndex() const override;
    antlr4::tree::TerminalNode*    A();
    antlr4::tree::TerminalNode*    ID();
    antlr4::tree::TerminalNode*    Direction();
    Condition_Others_StateContext* condition_Others_State();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Condition_ExistanceContext* condition_Existance();

  class Condition_StateContext : public antlr4::ParserRuleContext {
   public:
    Condition_StateContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t              getRuleIndex() const override;
    antlr4::tree::TerminalNode* ID();
    antlr4::tree::TerminalNode* STATE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Condition_StateContext* condition_State();

  class Condition_Others_StateContext : public antlr4::ParserRuleContext {
   public:
    Condition_Others_StateContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t              getRuleIndex() const override;
    antlr4::tree::TerminalNode* STATE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Condition_Others_StateContext* condition_Others_State();

  class Condition_Env_StateContext : public antlr4::ParserRuleContext {
   public:
    Condition_Env_StateContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t              getRuleIndex() const override;
    antlr4::tree::TerminalNode* STATE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Condition_Env_StateContext* condition_Env_State();

  class ActionContext : public antlr4::ParserRuleContext {
   public:
    ActionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t                 getRuleIndex() const override;
    Conditional_actionContext*     conditional_action();
    Non_conditional_actionContext* non_conditional_action();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  ActionContext* action();

  class Conditional_actionContext : public antlr4::ParserRuleContext {
   public:
    Conditional_actionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t                           getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode*> WS();
    antlr4::tree::TerminalNode*              WS(size_t i);
    ConditionContext*                        condition();
    antlr4::tree::TerminalNode*              A();
    antlr4::tree::TerminalNode*              ID();
    Sub_actionContext*                       sub_action();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Conditional_actionContext* conditional_action();

  class Non_conditional_actionContext : public antlr4::ParserRuleContext {
   public:
    Non_conditional_actionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t              getRuleIndex() const override;
    antlr4::tree::TerminalNode* A();
    antlr4::tree::TerminalNode* ID();
    antlr4::tree::TerminalNode* WS();
    Sub_actionContext*          sub_action();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Non_conditional_actionContext* non_conditional_action();

  class Sub_actionContext : public antlr4::ParserRuleContext {
   public:
    Sub_actionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t      getRuleIndex() const override;
    Action_atomContext* action_atom();
    Sub_actionContext*  sub_action();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Sub_actionContext* sub_action();

  class Action_atomContext : public antlr4::ParserRuleContext {
   public:
    Action_atomContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t      getRuleIndex() const override;
    Action_StopContext* action_Stop();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Action_atomContext* action_atom();

  class Action_StopContext : public antlr4::ParserRuleContext {
   public:
    Action_StopContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Action_StopContext* action_Stop();

  class DeclarationContext : public antlr4::ParserRuleContext {
   public:
    DeclarationContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t         getRuleIndex() const override;
    Decl_PedContext*       decl_Ped();
    Decl_Ped_StateContext* decl_Ped_State();
    Decl_Env_StateContext* decl_Env_State();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  DeclarationContext* declaration();

  class Decl_PedContext : public antlr4::ParserRuleContext {
   public:
    Decl_PedContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t              getRuleIndex() const override;
    antlr4::tree::TerminalNode* A();
    antlr4::tree::TerminalNode* ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Decl_PedContext* decl_Ped();

  class Decl_Ped_StateContext : public antlr4::ParserRuleContext {
   public:
    Decl_Ped_StateContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t                           getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode*> ID();
    antlr4::tree::TerminalNode*              ID(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Decl_Ped_StateContext* decl_Ped_State();

  class Decl_Env_StateContext : public antlr4::ParserRuleContext {
   public:
    Decl_Env_StateContext(antlr4::ParserRuleContext* parent, size_t invokingState);
    virtual size_t                           getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode*> ID();
    antlr4::tree::TerminalNode*              ID(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
  };

  Decl_Env_StateContext* decl_Env_State();

 private:
  static std::vector<antlr4::dfa::DFA>       _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string>            _ruleNames;
  static std::vector<std::string>            _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary  _vocabulary;
  static antlr4::atn::ATN         _atn;
  static std::vector<uint16_t>    _serializedATN;

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};
