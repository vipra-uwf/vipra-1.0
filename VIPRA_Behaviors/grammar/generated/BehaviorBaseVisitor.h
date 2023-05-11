
// Generated from Behavior.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "BehaviorVisitor.h"


/**
 * This class provides an empty implementation of BehaviorVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  BehaviorBaseVisitor : public BehaviorVisitor {
public:

  virtual antlrcpp::Any visitProgram(BehaviorParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(BehaviorParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent(BehaviorParser::EventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_Single(BehaviorParser::Event_SingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_Lasting(BehaviorParser::Event_LastingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition(BehaviorParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConnector(BehaviorParser::ConnectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOr_Connector(BehaviorParser::Or_ConnectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnd_Connector(BehaviorParser::And_ConnectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSub_condition(BehaviorParser::Sub_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition_Time_Elapsed_From_Event(BehaviorParser::Condition_Time_Elapsed_From_EventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition_Event_Occurred(BehaviorParser::Condition_Event_OccurredContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition_Event_Occurring(BehaviorParser::Condition_Event_OccurringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition_Event_One_Time(BehaviorParser::Condition_Event_One_TimeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDirection(BehaviorParser::DirectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDir(BehaviorParser::DirContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDirection_of(BehaviorParser::Direction_ofContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInfront(BehaviorParser::InfrontContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBehind(BehaviorParser::BehindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAround(BehaviorParser::AroundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObject(BehaviorParser::ObjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPed_Selector(BehaviorParser::Ped_SelectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelector_Cond(BehaviorParser::Selector_CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelector(BehaviorParser::SelectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelector_Percent(BehaviorParser::Selector_PercentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelector_Exactly_N_Random(BehaviorParser::Selector_Exactly_N_RandomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelector_Everyone(BehaviorParser::Selector_EveryoneContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitId_list(BehaviorParser::Id_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction(BehaviorParser::ActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional_action(BehaviorParser::Conditional_actionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUn_conditional_action(BehaviorParser::Un_conditional_actionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSub_action(BehaviorParser::Sub_actionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction_atom(BehaviorParser::Action_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction_Stop(BehaviorParser::Action_StopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction_atom_Percent_Walk_Speed(BehaviorParser::Action_atom_Percent_Walk_SpeedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction_Push(BehaviorParser::Action_PushContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction_Be(BehaviorParser::Action_BeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(BehaviorParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl_Ped(BehaviorParser::Decl_PedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext *ctx) override {
    return visitChildren(ctx);
  }


};

