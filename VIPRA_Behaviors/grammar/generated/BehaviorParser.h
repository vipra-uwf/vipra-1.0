
// Generated from Behavior.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  BehaviorParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    COMMENT = 8, LINE_COMMENT = 9, WS = 10, COMMA = 11, COLON = 12, STATE_VAL = 13, 
    EVNT = 14, AN = 15, AT = 16, ADD = 17, AND = 18, ARE = 19, AFTER = 20, 
    ALWAYS = 21, AROUND = 22, ACTION = 23, BEHIND = 24, CONSIDER = 25, DECIMAL = 26, 
    DIRECTION = 27, DURATION = 28, END = 29, ENDS = 30, ENVIRONMENT = 31, 
    EVENT = 32, EXACTLY = 33, EVERY = 34, EVERYONE = 35, ENDING = 36, FOR = 37, 
    FROM = 38, FRONT = 39, FASTER = 40, GIVEN = 41, GOAL = 42, GROUP = 43, 
    HAS = 44, IN = 45, INTEGER = 46, IS = 47, IF = 48, LENGTH = 49, LOCATION = 50, 
    MAX = 51, METERS = 52, NAME = 53, NEAREST = 54, NORMAL = 55, NONE = 56, 
    OBSTACLE = 57, OCCUR = 58, OCCURRED = 59, OCCURRING = 60, OF = 61, ON = 62, 
    OR = 63, PEDESTRIAN = 64, PEDESTRIANS = 65, POSSIBLE = 66, POSITION = 67, 
    RADIUS = 68, RANDOM = 69, REQUIRED = 70, RESPONSE = 71, SCALE = 72, 
    SELF = 73, SELECT = 74, SELECTOR = 75, SET = 76, SECOND = 77, SECONDS = 78, 
    STATUS = 79, STARTING = 80, SLOWER = 81, STATES = 82, START = 83, STATE = 84, 
    STARTS = 85, SPEED = 86, SUBTRACT = 87, STIMULUS = 88, TARGET = 89, 
    TO = 90, THE = 91, THAT = 92, THEN = 93, THEIR = 94, THERES = 95, TYPES = 96, 
    TYPE = 97, UNCONDITIONALLY = 98, VALUE = 99, VELOCITY = 100, WHEN = 101, 
    WHILE = 102, WIDTH = 103, WILL = 104, WITH = 105, WITHIN = 106, ID = 107, 
    NUMBER = 108, FLOAT = 109
  };

  enum {
    RuleProgram = 0, RuleStatement = 1, RuleEvent = 2, RuleEvent_attribute = 3, 
    RuleEvent_name = 4, RuleEvent_start = 5, RuleEvent_end = 6, RuleCondition = 7, 
    RuleConnector = 8, RuleOr_Connector = 9, RuleAnd_Connector = 10, RuleSub_condition = 11, 
    RuleCondition_Time_Elapsed_From_Event = 12, RuleCondition_Event_Occurred = 13, 
    RuleCondition_Event_Occurring = 14, RuleCondition_Event_Starting = 15, 
    RuleCondition_Event_Ending = 16, RuleCondition_Spatial = 17, RuleCondition_Attribute = 18, 
    RuleValue_numeric = 19, RuleValue_number = 20, RuleValue_float = 21, 
    RuleValue_range = 22, RuleValue_random = 23, RuleRandom_number = 24, 
    RuleRandom_float = 25, RuleFloat_range = 26, RuleNumber_range = 27, 
    RuleValue_coord = 28, RuleDuration = 29, RuleAttribute = 30, RuleAttr_value = 31, 
    RulePed_Selector = 32, RuleSelector_attribute = 33, RuleSelector_type = 34, 
    RuleSelector_selector = 35, RuleSelector_from = 36, RuleSelector_required = 37, 
    RuleSelector = 38, RuleSelector_Percent = 39, RuleSelector_Exactly_N_Random = 40, 
    RuleSelector_Everyone = 41, RuleGroup = 42, RuleId_list = 43, RuleAction = 44, 
    RuleAction_attribute = 45, RuleAction_stimulus = 46, RuleNone = 47, 
    RuleAction_response = 48, RuleAction_duration = 49, RuleAction_target = 50, 
    RuleSub_action = 51, RuleAction_atom = 52, RuleSet_atom = 53, RuleScale_atom = 54, 
    RuleTarget = 55, RuleSelf = 56, RuleOther = 57, RuleNearest_type = 58, 
    RuleModifier = 59, RuleDistance = 60, RuleDirection = 61, RuleFront = 62, 
    RuleBehind = 63, RuleDeclaration = 64, RuleDecl_Loc = 65, RuleDecl_Ped_State = 66, 
    RuleDecl_Env_State = 67, RuleDecl_Loc_Area_Circle = 68, RuleDecl_Loc_Area_Rect = 69, 
    RuleDecl_Loc_Point = 70, RuleDecl_Ped = 71
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
  class Event_attributeContext;
  class Event_nameContext;
  class Event_startContext;
  class Event_endContext;
  class ConditionContext;
  class ConnectorContext;
  class Or_ConnectorContext;
  class And_ConnectorContext;
  class Sub_conditionContext;
  class Condition_Time_Elapsed_From_EventContext;
  class Condition_Event_OccurredContext;
  class Condition_Event_OccurringContext;
  class Condition_Event_StartingContext;
  class Condition_Event_EndingContext;
  class Condition_SpatialContext;
  class Condition_AttributeContext;
  class Value_numericContext;
  class Value_numberContext;
  class Value_floatContext;
  class Value_rangeContext;
  class Value_randomContext;
  class Random_numberContext;
  class Random_floatContext;
  class Float_rangeContext;
  class Number_rangeContext;
  class Value_coordContext;
  class DurationContext;
  class AttributeContext;
  class Attr_valueContext;
  class Ped_SelectorContext;
  class Selector_attributeContext;
  class Selector_typeContext;
  class Selector_selectorContext;
  class Selector_fromContext;
  class Selector_requiredContext;
  class SelectorContext;
  class Selector_PercentContext;
  class Selector_Exactly_N_RandomContext;
  class Selector_EveryoneContext;
  class GroupContext;
  class Id_listContext;
  class ActionContext;
  class Action_attributeContext;
  class Action_stimulusContext;
  class NoneContext;
  class Action_responseContext;
  class Action_durationContext;
  class Action_targetContext;
  class Sub_actionContext;
  class Action_atomContext;
  class Set_atomContext;
  class Scale_atomContext;
  class TargetContext;
  class SelfContext;
  class OtherContext;
  class Nearest_typeContext;
  class ModifierContext;
  class DistanceContext;
  class DirectionContext;
  class FrontContext;
  class BehindContext;
  class DeclarationContext;
  class Decl_LocContext;
  class Decl_Ped_StateContext;
  class Decl_Env_StateContext;
  class Decl_Loc_Area_CircleContext;
  class Decl_Loc_Area_RectContext;
  class Decl_Loc_PointContext;
  class Decl_PedContext; 

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
    antlr4::tree::TerminalNode *EVENT();
    antlr4::tree::TerminalNode *COLON();
    std::vector<Event_attributeContext *> event_attribute();
    Event_attributeContext* event_attribute(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EventContext* event();

  class  Event_attributeContext : public antlr4::ParserRuleContext {
  public:
    Event_attributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Event_nameContext *event_name();
    Event_startContext *event_start();
    Event_endContext *event_end();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Event_attributeContext* event_attribute();

  class  Event_nameContext : public antlr4::ParserRuleContext {
  public:
    Event_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Event_nameContext* event_name();

  class  Event_startContext : public antlr4::ParserRuleContext {
  public:
    Event_startContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *START();
    antlr4::tree::TerminalNode *COLON();
    ConditionContext *condition();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Event_startContext* event_start();

  class  Event_endContext : public antlr4::ParserRuleContext {
  public:
    Event_endContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *COLON();
    ConditionContext *condition();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Event_endContext* event_end();

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
    Condition_Event_StartingContext *condition_Event_Starting();
    Condition_Event_EndingContext *condition_Event_Ending();
    Condition_SpatialContext *condition_Spatial();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sub_conditionContext* sub_condition();

  class  Condition_Time_Elapsed_From_EventContext : public antlr4::ParserRuleContext {
  public:
    Condition_Time_Elapsed_From_EventContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_numericContext *value_numeric();
    antlr4::tree::TerminalNode *SECONDS();
    antlr4::tree::TerminalNode *AFTER();
    antlr4::tree::TerminalNode *EVNT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_Time_Elapsed_From_EventContext* condition_Time_Elapsed_From_Event();

  class  Condition_Event_OccurredContext : public antlr4::ParserRuleContext {
  public:
    Condition_Event_OccurredContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EVNT();
    antlr4::tree::TerminalNode *HAS();
    antlr4::tree::TerminalNode *OCCURRED();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_Event_OccurredContext* condition_Event_Occurred();

  class  Condition_Event_OccurringContext : public antlr4::ParserRuleContext {
  public:
    Condition_Event_OccurringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EVNT();
    antlr4::tree::TerminalNode *OCCURRING();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_Event_OccurringContext* condition_Event_Occurring();

  class  Condition_Event_StartingContext : public antlr4::ParserRuleContext {
  public:
    Condition_Event_StartingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EVNT();
    antlr4::tree::TerminalNode *STARTING();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_Event_StartingContext* condition_Event_Starting();

  class  Condition_Event_EndingContext : public antlr4::ParserRuleContext {
  public:
    Condition_Event_EndingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EVNT();
    antlr4::tree::TerminalNode *ENDING();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_Event_EndingContext* condition_Event_Ending();

  class  Condition_SpatialContext : public antlr4::ParserRuleContext {
  public:
    Condition_SpatialContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TARGET();
    antlr4::tree::TerminalNode *WITHIN();
    Value_numericContext *value_numeric();
    antlr4::tree::TerminalNode *METERS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_SpatialContext* condition_Spatial();

  class  Condition_AttributeContext : public antlr4::ParserRuleContext {
  public:
    Condition_AttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeContext *attribute();
    antlr4::tree::TerminalNode *IS();
    Attr_valueContext *attr_value();
    antlr4::tree::TerminalNode *TARGET();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_AttributeContext* condition_Attribute();

  class  Value_numericContext : public antlr4::ParserRuleContext {
  public:
    Value_numericContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_numberContext *value_number();
    Value_floatContext *value_float();
    Value_rangeContext *value_range();
    Value_randomContext *value_random();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_numericContext* value_numeric();

  class  Value_numberContext : public antlr4::ParserRuleContext {
  public:
    Value_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_numberContext* value_number();

  class  Value_floatContext : public antlr4::ParserRuleContext {
  public:
    Value_floatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOAT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_floatContext* value_float();

  class  Value_rangeContext : public antlr4::ParserRuleContext {
  public:
    Value_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Float_rangeContext *float_range();
    Number_rangeContext *number_range();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_rangeContext* value_range();

  class  Value_randomContext : public antlr4::ParserRuleContext {
  public:
    Value_randomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Random_floatContext *random_float();
    Random_numberContext *random_number();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_randomContext* value_random();

  class  Random_numberContext : public antlr4::ParserRuleContext {
  public:
    Random_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RANDOM();
    Number_rangeContext *number_range();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Random_numberContext* random_number();

  class  Random_floatContext : public antlr4::ParserRuleContext {
  public:
    Random_floatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RANDOM();
    Float_rangeContext *float_range();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Random_floatContext* random_float();

  class  Float_rangeContext : public antlr4::ParserRuleContext {
  public:
    Float_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> FLOAT();
    antlr4::tree::TerminalNode* FLOAT(size_t i);
    antlr4::tree::TerminalNode *TO();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Float_rangeContext* float_range();

  class  Number_rangeContext : public antlr4::ParserRuleContext {
  public:
    Number_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    antlr4::tree::TerminalNode *TO();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Number_rangeContext* number_range();

  class  Value_coordContext : public antlr4::ParserRuleContext {
  public:
    Value_coordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Value_numericContext *> value_numeric();
    Value_numericContext* value_numeric(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_coordContext* value_coord();

  class  DurationContext : public antlr4::ParserRuleContext {
  public:
    DurationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_numericContext *value_numeric();
    antlr4::tree::TerminalNode *SECONDS();
    antlr4::tree::TerminalNode *SECOND();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DurationContext* duration();

  class  AttributeContext : public antlr4::ParserRuleContext {
  public:
    AttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POSITION();
    antlr4::tree::TerminalNode *VELOCITY();
    antlr4::tree::TerminalNode *GOAL();
    antlr4::tree::TerminalNode *STATE();
    antlr4::tree::TerminalNode *LOCATION();
    antlr4::tree::TerminalNode *STATUS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttributeContext* attribute();

  class  Attr_valueContext : public antlr4::ParserRuleContext {
  public:
    Attr_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_numericContext *value_numeric();
    Value_coordContext *value_coord();
    antlr4::tree::TerminalNode *STATE_VAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attr_valueContext* attr_value();

  class  Ped_SelectorContext : public antlr4::ParserRuleContext {
  public:
    Ped_SelectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECTOR();
    antlr4::tree::TerminalNode *COLON();
    std::vector<Selector_attributeContext *> selector_attribute();
    Selector_attributeContext* selector_attribute(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ped_SelectorContext* ped_Selector();

  class  Selector_attributeContext : public antlr4::ParserRuleContext {
  public:
    Selector_attributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Selector_typeContext *selector_type();
    Selector_selectorContext *selector_selector();
    Selector_fromContext *selector_from();
    Selector_requiredContext *selector_required();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_attributeContext* selector_attribute();

  class  Selector_typeContext : public antlr4::ParserRuleContext {
  public:
    Selector_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *COLON();
    Id_listContext *id_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_typeContext* selector_type();

  class  Selector_selectorContext : public antlr4::ParserRuleContext {
  public:
    Selector_selectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECT();
    antlr4::tree::TerminalNode *COLON();
    SelectorContext *selector();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_selectorContext* selector_selector();

  class  Selector_fromContext : public antlr4::ParserRuleContext {
  public:
    Selector_fromContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *COLON();
    GroupContext *group();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_fromContext* selector_from();

  class  Selector_requiredContext : public antlr4::ParserRuleContext {
  public:
    Selector_requiredContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REQUIRED();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_requiredContext* selector_required();

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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selector_PercentContext* selector_Percent();

  class  Selector_Exactly_N_RandomContext : public antlr4::ParserRuleContext {
  public:
    Selector_Exactly_N_RandomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_numberContext *value_number();


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

  class  GroupContext : public antlr4::ParserRuleContext {
  public:
    GroupContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *PEDESTRIAN();
    antlr4::tree::TerminalNode *PEDESTRIANS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GroupContext* group();

  class  Id_listContext : public antlr4::ParserRuleContext {
  public:
    Id_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PEDESTRIAN();
    antlr4::tree::TerminalNode* PEDESTRIAN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Id_listContext* id_list();

  class  ActionContext : public antlr4::ParserRuleContext {
  public:
    ActionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACTION();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COLON();
    std::vector<Action_attributeContext *> action_attribute();
    Action_attributeContext* action_attribute(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActionContext* action();

  class  Action_attributeContext : public antlr4::ParserRuleContext {
  public:
    Action_attributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Action_responseContext *action_response();
    Action_stimulusContext *action_stimulus();
    Action_durationContext *action_duration();
    Action_targetContext *action_target();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_attributeContext* action_attribute();

  class  Action_stimulusContext : public antlr4::ParserRuleContext {
  public:
    Action_stimulusContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NoneContext *none();
    antlr4::tree::TerminalNode *STIMULUS();
    antlr4::tree::TerminalNode *COLON();
    ConditionContext *condition();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_stimulusContext* action_stimulus();

  class  NoneContext : public antlr4::ParserRuleContext {
  public:
    NoneContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STIMULUS();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *NONE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NoneContext* none();

  class  Action_responseContext : public antlr4::ParserRuleContext {
  public:
    Action_responseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESPONSE();
    antlr4::tree::TerminalNode *COLON();
    Sub_actionContext *sub_action();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_responseContext* action_response();

  class  Action_durationContext : public antlr4::ParserRuleContext {
  public:
    Action_durationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DURATION();
    antlr4::tree::TerminalNode *COLON();
    DurationContext *duration();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_durationContext* action_duration();

  class  Action_targetContext : public antlr4::ParserRuleContext {
  public:
    Action_targetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TARGET();
    antlr4::tree::TerminalNode *COLON();
    TargetContext *target();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_targetContext* action_target();

  class  Sub_actionContext : public antlr4::ParserRuleContext {
  public:
    Sub_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Action_atomContext *> action_atom();
    Action_atomContext* action_atom(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sub_actionContext* sub_action();

  class  Action_atomContext : public antlr4::ParserRuleContext {
  public:
    Action_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Set_atomContext *set_atom();
    Scale_atomContext *scale_atom();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_atomContext* action_atom();

  class  Set_atomContext : public antlr4::ParserRuleContext {
  public:
    Set_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    AttributeContext *attribute();
    antlr4::tree::TerminalNode *TO();
    Attr_valueContext *attr_value();
    antlr4::tree::TerminalNode *TARGET();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Set_atomContext* set_atom();

  class  Scale_atomContext : public antlr4::ParserRuleContext {
  public:
    Scale_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCALE();
    AttributeContext *attribute();
    Attr_valueContext *attr_value();
    antlr4::tree::TerminalNode *TARGET();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Scale_atomContext* scale_atom();

  class  TargetContext : public antlr4::ParserRuleContext {
  public:
    TargetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SelfContext *self();
    OtherContext *other();
    std::vector<ModifierContext *> modifier();
    ModifierContext* modifier(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TargetContext* target();

  class  SelfContext : public antlr4::ParserRuleContext {
  public:
    SelfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelfContext* self();

  class  OtherContext : public antlr4::ParserRuleContext {
  public:
    OtherContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Nearest_typeContext *nearest_type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OtherContext* other();

  class  Nearest_typeContext : public antlr4::ParserRuleContext {
  public:
    Nearest_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEAREST();
    Id_listContext *id_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Nearest_typeContext* nearest_type();

  class  ModifierContext : public antlr4::ParserRuleContext {
  public:
    ModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DirectionContext *direction();
    DistanceContext *distance();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModifierContext* modifier();

  class  DistanceContext : public antlr4::ParserRuleContext {
  public:
    DistanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITHIN();
    Value_numericContext *value_numeric();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DistanceContext* distance();

  class  DirectionContext : public antlr4::ParserRuleContext {
  public:
    DirectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FrontContext *front();
    BehindContext *behind();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DirectionContext* direction();

  class  FrontContext : public antlr4::ParserRuleContext {
  public:
    FrontContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *FRONT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FrontContext* front();

  class  BehindContext : public antlr4::ParserRuleContext {
  public:
    BehindContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEHIND();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BehindContext* behind();

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
    antlr4::tree::TerminalNode *PEDESTRIAN();
    antlr4::tree::TerminalNode *STATES();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> STATE_VAL();
    antlr4::tree::TerminalNode* STATE_VAL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_Ped_StateContext* decl_Ped_State();

  class  Decl_Env_StateContext : public antlr4::ParserRuleContext {
  public:
    Decl_Env_StateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENVIRONMENT();
    antlr4::tree::TerminalNode *STATES();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> STATE_VAL();
    antlr4::tree::TerminalNode* STATE_VAL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


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
    Value_coordContext *value_coord();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *RADIUS();
    antlr4::tree::TerminalNode *OF();
    Value_numericContext *value_numeric();


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
    Value_coordContext *value_coord();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *LENGTH();
    std::vector<antlr4::tree::TerminalNode *> OF();
    antlr4::tree::TerminalNode* OF(size_t i);
    std::vector<Value_numericContext *> value_numeric();
    Value_numericContext* value_numeric(size_t i);
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
    Value_coordContext *value_coord();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_Loc_PointContext* decl_Loc_Point();

  class  Decl_PedContext : public antlr4::ParserRuleContext {
  public:
    Decl_PedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPES();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Decl_PedContext* decl_Ped();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};
