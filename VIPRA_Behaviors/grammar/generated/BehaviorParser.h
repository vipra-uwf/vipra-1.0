
// Generated from Behavior.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  BehaviorParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, COMMENT = 11, LINE_COMMENT = 12, WS = 13, 
    COMMA = 14, COLON = 15, STATE = 16, ACTION = 17, EVNT = 18, OBJECT = 19, 
    AN = 20, AT = 21, AND = 22, ARE = 23, AFTER = 24, ALWAYS = 25, AROUND = 26, 
    BEHIND = 27, CONSIDER = 28, DECIMAL = 29, DIRECTION = 30, END = 31, 
    ENDS = 32, ENVIRONMENT = 33, EVENT = 34, EXACTLY = 35, EVERY = 36, EVERYONE = 37, 
    FOR = 38, FROM = 39, FRONT = 40, FASTER = 41, GIVEN = 42, HAS = 43, 
    IN = 44, INTEGER = 45, IS = 46, LENGTH = 47, LOCATION = 48, METERS = 49, 
    NORMAL = 50, OBSTACLE = 51, OCCUR = 52, OCCURRED = 53, OCCURRING = 54, 
    OF = 55, OR = 56, PEDESTRIAN = 57, PEDESTRIANS = 58, POSSIBLE = 59, 
    RADIUS = 60, RANDOM = 61, REQUIRED = 62, SECOND = 63, SECONDS = 64, 
    SLOWER = 65, STATES = 66, STARTS = 67, SPEED = 68, TO = 69, THE = 70, 
    THAT = 71, THEN = 72, THEIR = 73, THERES = 74, TYPES = 75, VALUE = 76, 
    WHEN = 77, WHILE = 78, WIDTH = 79, WILL = 80, WITH = 81, WITHIN = 82, 
    ID = 83, NUMBER = 84, FLOAT = 85
  };

  enum {
    RuleProgram = 0, RuleStatement = 1, RuleEvent = 2, RuleEvent_Single = 3, 
    RuleEvent_Lasting = 4, RuleEvent_Individual = 5, RuleCondition = 6, 
    RuleConnector = 7, RuleOr_Connector = 8, RuleAnd_Connector = 9, RuleSub_condition = 10, 
    RuleCondition_Time_Elapsed_From_Event = 11, RuleCondition_Event_Occurred = 12, 
    RuleCondition_Event_Occurring = 13, RuleValue_number = 14, RuleNumber_random = 15, 
    RuleRandom_number = 16, RuleRandom_float = 17, RuleDirection = 18, RuleDir = 19, 
    RuleDirection_of = 20, RuleInfront = 21, RuleBehind = 22, RuleAround = 23, 
    RuleObject = 24, RuleDuration = 25, RulePed_Selector = 26, RuleSelector = 27, 
    RuleSelector_Percent = 28, RuleSelector_Exactly_N_Random = 29, RuleSelector_Everyone = 30, 
    RuleId_list = 31, RuleAction = 32, RuleConditional_action = 33, RuleUn_conditional_action = 34, 
    RuleSub_action = 35, RuleAction_atom = 36, RuleAction_Stop = 37, RuleAction_atom_Percent_Walk_Speed = 38, 
    RuleAction_Be = 39, RuleDeclaration = 40, RuleDecl_Loc = 41, RuleDecl_Ped_State = 42, 
    RuleDecl_Env_State = 43, RuleDecl_Loc_Area_Circle = 44, RuleDecl_Loc_Area_Rect = 45, 
    RuleDecl_Loc_Point = 46, RuleDecl_Ped = 47, RulePoint = 48
  };

  explicit BehaviorParser(antlr4::TokenStream *input);

  BehaviorParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~BehaviorParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class StatementContext;
  class EventContext;
  class Event_SingleContext;
  class Event_LastingContext;
  class Event_IndividualContext;
  class ConditionContext;
  class ConnectorContext;
  class Or_ConnectorContext;
  class And_ConnectorContext;
  class Sub_conditionContext;
  class Condition_Time_Elapsed_From_EventContext;
  class Condition_Event_OccurredContext;
  class Condition_Event_OccurringContext;
  class Value_numberContext;
  class Number_randomContext;
  class Random_numberContext;
  class Random_floatContext;
  class DirectionContext;
  class DirContext;
  class Direction_ofContext;
  class InfrontContext;
  class BehindContext;
  class AroundContext;
  class ObjectContext;
  class DurationContext;
  class Ped_SelectorContext;
  class SelectorContext;
  class Selector_PercentContext;
  class Selector_Exactly_N_RandomContext;
  class Selector_EveryoneContext;
  class Id_listContext;
  class ActionContext;
  class Conditional_actionContext;
  class Un_conditional_actionContext;
  class Sub_actionContext;
  class Action_atomContext;
  class Action_StopContext;
  class Action_atom_Percent_Walk_SpeedContext;
  class Action_BeContext;
  class DeclarationContext;
  class Decl_LocContext;
  class Decl_Ped_StateContext;
  class Decl_Env_StateContext;
  class Decl_Loc_Area_CircleContext;
  class Decl_Loc_Area_RectContext;
  class Decl_Loc_PointContext;
  class Decl_PedContext;
  class PointContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Decl_PedContext *decl_Ped();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EventContext *event();
    DeclarationContext *declaration();
    Ped_SelectorContext *ped_Selector();
    ActionContext *action();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  EventContext : public antlr4::ParserRuleContext {
  public:
    EventContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Event_SingleContext *event_Single();
    Event_LastingContext *event_Lasting();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EventContext* event();

  class  Event_SingleContext : public antlr4::ParserRuleContext {
  public:
    Event_SingleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EVNT();
    antlr4::tree::TerminalNode *WILL();
    antlr4::tree::TerminalNode *OCCUR();
    ConditionContext *condition();
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *THE();
    antlr4::tree::TerminalNode *EVENT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Event_SingleContext* event_Single();

  class  Event_LastingContext : public antlr4::ParserRuleContext {
  public:
    Event_LastingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EVNT();
    antlr4::tree::TerminalNode *WILL();
    antlr4::tree::TerminalNode *OCCUR();
    std::vector<ConditionContext *> condition();
    ConditionContext* condition(size_t i);
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *THE();
    antlr4::tree::TerminalNode *EVENT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Event_LastingContext* event_Lasting();

  class  Event_IndividualContext : public antlr4::ParserRuleContext {
  public:
    Event_IndividualContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *WILL();
    antlr4::tree::TerminalNode *EVNT();
    ConditionContext *condition();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Event_IndividualContext* event_Individual();

  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sub_conditionContext *sub_condition();
    std::vector<ConnectorContext *> connector();
    ConnectorContext* connector(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionContext* condition();

  class  ConnectorContext : public antlr4::ParserRuleContext {
  public:
    ConnectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Or_ConnectorContext *or_Connector();
    And_ConnectorContext *and_Connector();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConnectorContext* connector();

  class  Or_ConnectorContext : public antlr4::ParserRuleContext {
  public:
    Or_ConnectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();
    Sub_conditionContext *sub_condition();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Or_ConnectorContext* or_Connector();

  class  And_ConnectorContext : public antlr4::ParserRuleContext {
  public:
    And_ConnectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();
    Sub_conditionContext *sub_condition();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  And_ConnectorContext* and_Connector();

  class  Sub_conditionContext : public antlr4::ParserRuleContext {
  public:
    Sub_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Condition_Time_Elapsed_From_EventContext *condition_Time_Elapsed_From_Event();
    Condition_Event_OccurredContext *condition_Event_Occurred();
    Condition_Event_OccurringContext *condition_Event_Occurring();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sub_conditionContext* sub_condition();

  class  Condition_Time_Elapsed_From_EventContext : public antlr4::ParserRuleContext {
  public:
    Condition_Time_Elapsed_From_EventContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AFTER();
    DurationContext *duration();
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *EVNT();
    antlr4::tree::TerminalNode *EVENT();
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *THE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_Time_Elapsed_From_EventContext* condition_Time_Elapsed_From_Event();

  class  Condition_Event_OccurredContext : public antlr4::ParserRuleContext {
  public:
    Condition_Event_OccurredContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GIVEN();
    antlr4::tree::TerminalNode *EVNT();
    antlr4::tree::TerminalNode *HAS();
    antlr4::tree::TerminalNode *OCCURRED();
    antlr4::tree::TerminalNode *EVENT();
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *THE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_Event_OccurredContext* condition_Event_Occurred();

  class  Condition_Event_OccurringContext : public antlr4::ParserRuleContext {
  public:
    Condition_Event_OccurringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *EVNT();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *OCCURRING();
    antlr4::tree::TerminalNode *EVENT();
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *THE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_Event_OccurringContext* condition_Event_Occurring();

  class  Value_numberContext : public antlr4::ParserRuleContext {
  public:
    Value_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Number_randomContext *number_random();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *FLOAT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_numberContext* value_number();

  class  Number_randomContext : public antlr4::ParserRuleContext {
  public:
    Number_randomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Random_floatContext *random_float();
    Random_numberContext *random_number();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Number_randomContext* number_random();

  class  Random_numberContext : public antlr4::ParserRuleContext {
  public:
    Random_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *RANDOM();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    antlr4::tree::TerminalNode *TO();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Random_numberContext* random_number();

  class  Random_floatContext : public antlr4::ParserRuleContext {
  public:
    Random_floatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *RANDOM();
    std::vector<antlr4::tree::TerminalNode *> FLOAT();
    antlr4::tree::TerminalNode* FLOAT(size_t i);
    antlr4::tree::TerminalNode *TO();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Random_floatContext* random_float();

  class  DirectionContext : public antlr4::ParserRuleContext {
  public:
    DirectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DirContext *dir();
    antlr4::tree::TerminalNode *WITHIN();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *METERS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DirectionContext* direction();

  class  DirContext : public antlr4::ParserRuleContext {
  public:
    DirContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Direction_ofContext *direction_of();
    InfrontContext *infront();
    BehindContext *behind();
    AroundContext *around();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DirContext* dir();

  class  Direction_ofContext : public antlr4::ParserRuleContext {
  public:
    Direction_ofContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *DIRECTION();
    antlr4::tree::TerminalNode *OF();
    antlr4::tree::TerminalNode *ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Direction_ofContext* direction_of();

  class  InfrontContext : public antlr4::ParserRuleContext {
  public:
    InfrontContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *FRONT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InfrontContext* infront();

  class  BehindContext : public antlr4::ParserRuleContext {
  public:
    BehindContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEHIND();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BehindContext* behind();

  class  AroundContext : public antlr4::ParserRuleContext {
  public:
    AroundContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AROUND();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AroundContext* around();

  class  ObjectContext : public antlr4::ParserRuleContext {
  public:
    ObjectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PEDESTRIAN();
    antlr4::tree::TerminalNode *OBSTACLE();
    antlr4::tree::TerminalNode *OBJECT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjectContext* object();

  class  DurationContext : public antlr4::ParserRuleContext {
  public:
    DurationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    Value_numberContext *value_number();
    antlr4::tree::TerminalNode *SECONDS();
    antlr4::tree::TerminalNode *SECOND();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DurationContext* duration();

  class  Ped_SelectorContext : public antlr4::ParserRuleContext {
  public:
    Ped_SelectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SelectorContext *selector();
    Id_listContext *id_list();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *PEDESTRIAN();
    antlr4::tree::TerminalNode *PEDESTRIANS();
    antlr4::tree::TerminalNode *ARE();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *REQUIRED();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *AN();
    Selector_EveryoneContext *selector_Everyone();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ped_SelectorContext* ped_Selector();

  class  SelectorContext : public antlr4::ParserRuleContext {
  public:
    SelectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Selector_PercentContext *selector_Percent();
    Selector_Exactly_N_RandomContext *selector_Exactly_N_Random();
    Selector_EveryoneContext *selector_Everyone();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectorContext* selector();

  class  Selector_PercentContext : public antlr4::ParserRuleContext {
  public:
    Selector_PercentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_numberContext *value_number();
    antlr4::tree::TerminalNode *OF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_PercentContext* selector_Percent();

  class  Selector_Exactly_N_RandomContext : public antlr4::ParserRuleContext {
  public:
    Selector_Exactly_N_RandomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXACTLY();
    Value_numberContext *value_number();
    antlr4::tree::TerminalNode *OF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_Exactly_N_RandomContext* selector_Exactly_N_Random();

  class  Selector_EveryoneContext : public antlr4::ParserRuleContext {
  public:
    Selector_EveryoneContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EVERYONE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_EveryoneContext* selector_Everyone();

  class  Id_listContext : public antlr4::ParserRuleContext {
  public:
    Id_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AN();
    antlr4::tree::TerminalNode* AN(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Id_listContext* id_list();

  class  ActionContext : public antlr4::ParserRuleContext {
  public:
    ActionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Conditional_actionContext *conditional_action();
    Un_conditional_actionContext *un_conditional_action();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActionContext* action();

  class  Conditional_actionContext : public antlr4::ParserRuleContext {
  public:
    Conditional_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *WILL();
    Sub_actionContext *sub_action();
    ConditionContext *condition();
    DurationContext *duration();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Conditional_actionContext* conditional_action();

  class  Un_conditional_actionContext : public antlr4::ParserRuleContext {
  public:
    Un_conditional_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *WILL();
    antlr4::tree::TerminalNode *ALWAYS();
    Sub_actionContext *sub_action();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Un_conditional_actionContext* un_conditional_action();

  class  Sub_actionContext : public antlr4::ParserRuleContext {
  public:
    Sub_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Action_atomContext *> action_atom();
    Action_atomContext* action_atom(size_t i);
    std::vector<antlr4::tree::TerminalNode *> THEN();
    antlr4::tree::TerminalNode* THEN(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sub_actionContext* sub_action();

  class  Action_atomContext : public antlr4::ParserRuleContext {
  public:
    Action_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACTION();
    Action_StopContext *action_Stop();
    Action_BeContext *action_Be();
    Action_atom_Percent_Walk_SpeedContext *action_atom_Percent_Walk_Speed();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_atomContext* action_atom();

  class  Action_StopContext : public antlr4::ParserRuleContext {
  public:
    Action_StopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_StopContext* action_Stop();

  class  Action_atom_Percent_Walk_SpeedContext : public antlr4::ParserRuleContext {
  public:
    Action_atom_Percent_Walk_SpeedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_numberContext *value_number();
    antlr4::tree::TerminalNode *THEIR();
    antlr4::tree::TerminalNode *NORMAL();
    antlr4::tree::TerminalNode *SPEED();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_atom_Percent_Walk_SpeedContext* action_atom_Percent_Walk_Speed();

  class  Action_BeContext : public antlr4::ParserRuleContext {
  public:
    Action_BeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STATE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_BeContext* action_Be();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Decl_LocContext *decl_Loc();
    Decl_Ped_StateContext *decl_Ped_State();
    Decl_Env_StateContext *decl_Env_State();
    Decl_PedContext *decl_Ped();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  Decl_LocContext : public antlr4::ParserRuleContext {
  public:
    Decl_LocContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Decl_Loc_Area_CircleContext *decl_Loc_Area_Circle();
    Decl_Loc_PointContext *decl_Loc_Point();
    Decl_Loc_Area_RectContext *decl_Loc_Area_Rect();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_LocContext* decl_Loc();

  class  Decl_Ped_StateContext : public antlr4::ParserRuleContext {
  public:
    Decl_Ped_StateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POSSIBLE();
    antlr4::tree::TerminalNode *PEDESTRIAN();
    antlr4::tree::TerminalNode *STATES();
    antlr4::tree::TerminalNode *ARE();
    std::vector<antlr4::tree::TerminalNode *> STATE();
    antlr4::tree::TerminalNode* STATE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_Ped_StateContext* decl_Ped_State();

  class  Decl_Env_StateContext : public antlr4::ParserRuleContext {
  public:
    Decl_Env_StateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POSSIBLE();
    antlr4::tree::TerminalNode *ENVIRONMENT();
    antlr4::tree::TerminalNode *STATES();
    antlr4::tree::TerminalNode *ARE();
    std::vector<antlr4::tree::TerminalNode *> STATE();
    antlr4::tree::TerminalNode* STATE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_Env_StateContext* decl_Env_State();

  class  Decl_Loc_Area_CircleContext : public antlr4::ParserRuleContext {
  public:
    Decl_Loc_Area_CircleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONSIDER();
    std::vector<antlr4::tree::TerminalNode *> AN();
    antlr4::tree::TerminalNode* AN(size_t i);
    antlr4::tree::TerminalNode *LOCATION();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *AT();
    PointContext *point();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *RADIUS();
    antlr4::tree::TerminalNode *OF();
    Value_numberContext *value_number();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_Loc_Area_CircleContext* decl_Loc_Area_Circle();

  class  Decl_Loc_Area_RectContext : public antlr4::ParserRuleContext {
  public:
    Decl_Loc_Area_RectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONSIDER();
    std::vector<antlr4::tree::TerminalNode *> AN();
    antlr4::tree::TerminalNode* AN(size_t i);
    antlr4::tree::TerminalNode *LOCATION();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *AT();
    PointContext *point();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *LENGTH();
    std::vector<antlr4::tree::TerminalNode *> OF();
    antlr4::tree::TerminalNode* OF(size_t i);
    std::vector<Value_numberContext *> value_number();
    Value_numberContext* value_number(size_t i);
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *WIDTH();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_Loc_Area_RectContext* decl_Loc_Area_Rect();

  class  Decl_Loc_PointContext : public antlr4::ParserRuleContext {
  public:
    Decl_Loc_PointContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONSIDER();
    antlr4::tree::TerminalNode *AN();
    antlr4::tree::TerminalNode *LOCATION();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *AT();
    PointContext *point();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_Loc_PointContext* decl_Loc_Point();

  class  Decl_PedContext : public antlr4::ParserRuleContext {
  public:
    Decl_PedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONSIDER();
    std::vector<antlr4::tree::TerminalNode *> AN();
    antlr4::tree::TerminalNode* AN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_PedContext* decl_Ped();

  class  PointContext : public antlr4::ParserRuleContext {
  public:
    PointContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Value_numberContext *> value_number();
    Value_numberContext* value_number(size_t i);
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PointContext* point();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

