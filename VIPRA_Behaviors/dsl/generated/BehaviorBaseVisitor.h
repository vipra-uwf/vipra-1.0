
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

  virtual antlrcpp::Any visitConsideration(BehaviorParser::ConsiderationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(BehaviorParser::StatementContext *ctx) override {
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


};

