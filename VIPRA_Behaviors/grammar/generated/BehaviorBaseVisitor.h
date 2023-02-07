
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

  virtual antlrcpp::Any visitTransition_Environment(BehaviorParser::Transition_EnvironmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTransition_Pedestrian(BehaviorParser::Transition_PedestrianContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition(BehaviorParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSub_condition(BehaviorParser::Sub_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition_Existance(BehaviorParser::Condition_ExistanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition_State(BehaviorParser::Condition_StateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition_Others_State(BehaviorParser::Condition_Others_StateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition_Time_Elapsed(BehaviorParser::Condition_Time_ElapsedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitState_Check(BehaviorParser::State_CheckContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitState_Set(BehaviorParser::State_SetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObject(BehaviorParser::ObjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPed_Selector(BehaviorParser::Ped_SelectorContext *ctx) override {
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

  virtual antlrcpp::Any visitDecl_Parameters(BehaviorParser::Decl_ParametersContext *ctx) override {
    return visitChildren(ctx);
  }


};

