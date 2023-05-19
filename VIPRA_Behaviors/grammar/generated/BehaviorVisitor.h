
// Generated from Behavior.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "BehaviorParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by BehaviorParser.
 */
class  BehaviorVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by BehaviorParser.
   */
    virtual std::any visitProgram(BehaviorParser::ProgramContext *context) = 0;

    virtual std::any visitStatement(BehaviorParser::StatementContext *context) = 0;

    virtual std::any visitEvent(BehaviorParser::EventContext *context) = 0;

    virtual std::any visitEvent_Single(BehaviorParser::Event_SingleContext *context) = 0;

    virtual std::any visitEvent_Lasting(BehaviorParser::Event_LastingContext *context) = 0;

    virtual std::any visitCondition(BehaviorParser::ConditionContext *context) = 0;

    virtual std::any visitConnector(BehaviorParser::ConnectorContext *context) = 0;

    virtual std::any visitOr_Connector(BehaviorParser::Or_ConnectorContext *context) = 0;

    virtual std::any visitAnd_Connector(BehaviorParser::And_ConnectorContext *context) = 0;

    virtual std::any visitSub_condition(BehaviorParser::Sub_conditionContext *context) = 0;

    virtual std::any visitCondition_Time_Elapsed_From_Event(BehaviorParser::Condition_Time_Elapsed_From_EventContext *context) = 0;

    virtual std::any visitCondition_Event_Occurred(BehaviorParser::Condition_Event_OccurredContext *context) = 0;

    virtual std::any visitCondition_Event_Occurring(BehaviorParser::Condition_Event_OccurringContext *context) = 0;

    virtual std::any visitCondition_Event_One_Time(BehaviorParser::Condition_Event_One_TimeContext *context) = 0;

    virtual std::any visitValue_number(BehaviorParser::Value_numberContext *context) = 0;

    virtual std::any visitNumber_random(BehaviorParser::Number_randomContext *context) = 0;

    virtual std::any visitRandom_number(BehaviorParser::Random_numberContext *context) = 0;

    virtual std::any visitRandom_float(BehaviorParser::Random_floatContext *context) = 0;

    virtual std::any visitDirection(BehaviorParser::DirectionContext *context) = 0;

    virtual std::any visitDir(BehaviorParser::DirContext *context) = 0;

    virtual std::any visitDirection_of(BehaviorParser::Direction_ofContext *context) = 0;

    virtual std::any visitInfront(BehaviorParser::InfrontContext *context) = 0;

    virtual std::any visitBehind(BehaviorParser::BehindContext *context) = 0;

    virtual std::any visitAround(BehaviorParser::AroundContext *context) = 0;

    virtual std::any visitObject(BehaviorParser::ObjectContext *context) = 0;

    virtual std::any visitPed_Selector(BehaviorParser::Ped_SelectorContext *context) = 0;

    virtual std::any visitSelector(BehaviorParser::SelectorContext *context) = 0;

    virtual std::any visitSelector_Percent(BehaviorParser::Selector_PercentContext *context) = 0;

    virtual std::any visitSelector_Exactly_N_Random(BehaviorParser::Selector_Exactly_N_RandomContext *context) = 0;

    virtual std::any visitSelector_Everyone(BehaviorParser::Selector_EveryoneContext *context) = 0;

    virtual std::any visitSelector_Area(BehaviorParser::Selector_AreaContext *context) = 0;

    virtual std::any visitId_list(BehaviorParser::Id_listContext *context) = 0;

    virtual std::any visitAction(BehaviorParser::ActionContext *context) = 0;

    virtual std::any visitConditional_action(BehaviorParser::Conditional_actionContext *context) = 0;

    virtual std::any visitUn_conditional_action(BehaviorParser::Un_conditional_actionContext *context) = 0;

    virtual std::any visitSub_action(BehaviorParser::Sub_actionContext *context) = 0;

    virtual std::any visitAction_atom(BehaviorParser::Action_atomContext *context) = 0;

    virtual std::any visitAction_Stop(BehaviorParser::Action_StopContext *context) = 0;

    virtual std::any visitAction_atom_Percent_Walk_Speed(BehaviorParser::Action_atom_Percent_Walk_SpeedContext *context) = 0;

    virtual std::any visitAction_Push(BehaviorParser::Action_PushContext *context) = 0;

    virtual std::any visitAction_Be(BehaviorParser::Action_BeContext *context) = 0;

    virtual std::any visitDeclaration(BehaviorParser::DeclarationContext *context) = 0;

    virtual std::any visitDecl_Ped(BehaviorParser::Decl_PedContext *context) = 0;

    virtual std::any visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext *context) = 0;

    virtual std::any visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext *context) = 0;


};

