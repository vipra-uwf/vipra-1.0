
// Generated from Behavior.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "BehaviorVisitor.h"


/**
 * This class provides an empty implementation of BehaviorVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  BehaviorBaseVisitor : public BehaviorVisitor {
public:

  virtual std::any visitProgram(BehaviorParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(BehaviorParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEvent(BehaviorParser::EventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEvent_Single(BehaviorParser::Event_SingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEvent_Lasting(BehaviorParser::Event_LastingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondition(BehaviorParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConnector(BehaviorParser::ConnectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOr_Connector(BehaviorParser::Or_ConnectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnd_Connector(BehaviorParser::And_ConnectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSub_condition(BehaviorParser::Sub_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondition_Time_Elapsed_From_Event(BehaviorParser::Condition_Time_Elapsed_From_EventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondition_Event_Occurred(BehaviorParser::Condition_Event_OccurredContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondition_Event_Occurring(BehaviorParser::Condition_Event_OccurringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_numeric(BehaviorParser::Value_numericContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_number(BehaviorParser::Value_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_float(BehaviorParser::Value_floatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_range(BehaviorParser::Value_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_random(BehaviorParser::Value_randomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRandom_number(BehaviorParser::Random_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRandom_float(BehaviorParser::Random_floatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloat_range(BehaviorParser::Float_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber_range(BehaviorParser::Number_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDirection(BehaviorParser::DirectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDir(BehaviorParser::DirContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDirection_of(BehaviorParser::Direction_ofContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInfront(BehaviorParser::InfrontContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBehind(BehaviorParser::BehindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAround(BehaviorParser::AroundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObject(BehaviorParser::ObjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDuration(BehaviorParser::DurationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPed_Selector(BehaviorParser::Ped_SelectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelector(BehaviorParser::SelectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelector_Percent(BehaviorParser::Selector_PercentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelector_Exactly_N_Random(BehaviorParser::Selector_Exactly_N_RandomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelector_Everyone(BehaviorParser::Selector_EveryoneContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitId_list(BehaviorParser::Id_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAction(BehaviorParser::ActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConditional_action(BehaviorParser::Conditional_actionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUn_conditional_action(BehaviorParser::Un_conditional_actionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSub_action(BehaviorParser::Sub_actionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAction_atom(BehaviorParser::Action_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAction_Stop(BehaviorParser::Action_StopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAction_atom_Percent_Walk_Speed(BehaviorParser::Action_atom_Percent_Walk_SpeedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAction_Be(BehaviorParser::Action_BeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(BehaviorParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl_Loc(BehaviorParser::Decl_LocContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl_Loc_Area_Circle(BehaviorParser::Decl_Loc_Area_CircleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl_Loc_Area_Rect(BehaviorParser::Decl_Loc_Area_RectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl_Loc_Point(BehaviorParser::Decl_Loc_PointContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl_Ped(BehaviorParser::Decl_PedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPoint(BehaviorParser::PointContext *ctx) override {
    return visitChildren(ctx);
  }


};

