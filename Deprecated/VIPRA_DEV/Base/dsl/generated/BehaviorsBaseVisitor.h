
// Generated from Behaviors.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "BehaviorsVisitor.h"


/**
 * This class provides an empty implementation of BehaviorsVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  BehaviorsBaseVisitor : public BehaviorsVisitor {
public:

  virtual antlrcpp::Any visitProgram(BehaviorsParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(BehaviorsParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConsideration(BehaviorsParser::ConsiderationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStateSelector(BehaviorsParser::StateSelectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdRatioSelector(BehaviorsParser::IdRatioSelectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExactlyNRandomSelector(BehaviorsParser::ExactlyNRandomSelectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRandomIdRatioStatement(BehaviorsParser::RandomIdRatioStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNoGroupRandomIdSelector(BehaviorsParser::NoGroupRandomIdSelectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroupingRandomIdSelector(BehaviorsParser::GroupingRandomIdSelectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditionElapsedTime(BehaviorsParser::ConditionElapsedTimeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditionEnvironmentState(BehaviorsParser::ConditionEnvironmentStateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEveryoneSelector(BehaviorsParser::EveryoneSelectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnvironmentStateDeclaration(BehaviorsParser::EnvironmentStateDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnvironmentInitialStateDeclaration(BehaviorsParser::EnvironmentInitialStateDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnvironmentTransition(BehaviorsParser::EnvironmentTransitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStateDeclaration(BehaviorsParser::StateDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitialStateDeclaration(BehaviorsParser::InitialStateDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPedestrianSelected(BehaviorsParser::PedestrianSelectedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStateTransitionElapsedTime(BehaviorsParser::StateTransitionElapsedTimeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStateTransitionEnvironmentState(BehaviorsParser::StateTransitionEnvironmentStateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFasterOrSlower(BehaviorsParser::FasterOrSlowerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTowardOrAwayFrom(BehaviorsParser::TowardOrAwayFromContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTarget(BehaviorsParser::TargetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStoppedBehavior(BehaviorsParser::StoppedBehaviorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWalkSpeedBehavior(BehaviorsParser::WalkSpeedBehaviorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWalkSpeedWithTargetBehavior(BehaviorsParser::WalkSpeedWithTargetBehaviorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNormalBehavior(BehaviorsParser::NormalBehaviorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStateActionStopped(BehaviorsParser::StateActionStoppedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStateActionWalkSpeed(BehaviorsParser::StateActionWalkSpeedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStateActionWalkSpeedWithTarget(BehaviorsParser::StateActionWalkSpeedWithTargetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStateActionNormal(BehaviorsParser::StateActionNormalContext *ctx) override {
    return visitChildren(ctx);
  }


};

