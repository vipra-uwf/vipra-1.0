
// Generated from Behaviors.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "BehaviorsParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by BehaviorsParser.
 */
class  BehaviorsVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by BehaviorsParser.
   */
    virtual antlrcpp::Any visitProgram(BehaviorsParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitStatement(BehaviorsParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitConsideration(BehaviorsParser::ConsiderationContext *context) = 0;

    virtual antlrcpp::Any visitStateSelector(BehaviorsParser::StateSelectorContext *context) = 0;

    virtual antlrcpp::Any visitIdRatioSelector(BehaviorsParser::IdRatioSelectorContext *context) = 0;

    virtual antlrcpp::Any visitRandomIdRatioStatement(BehaviorsParser::RandomIdRatioStatementContext *context) = 0;

    virtual antlrcpp::Any visitNoGroupRandomIdSelector(BehaviorsParser::NoGroupRandomIdSelectorContext *context) = 0;

    virtual antlrcpp::Any visitGroupingRandomIdSelector(BehaviorsParser::GroupingRandomIdSelectorContext *context) = 0;

    virtual antlrcpp::Any visitEveryoneSelector(BehaviorsParser::EveryoneSelectorContext *context) = 0;

    virtual antlrcpp::Any visitEnvironmentStateDeclaration(BehaviorsParser::EnvironmentStateDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitStateDeclaration(BehaviorsParser::StateDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitInitialStateDeclaration(BehaviorsParser::InitialStateDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitPedestrianSelected(BehaviorsParser::PedestrianSelectedContext *context) = 0;

    virtual antlrcpp::Any visitStateCondition(BehaviorsParser::StateConditionContext *context) = 0;

    virtual antlrcpp::Any visitStateTransition(BehaviorsParser::StateTransitionContext *context) = 0;

    virtual antlrcpp::Any visitFasterOrSlower(BehaviorsParser::FasterOrSlowerContext *context) = 0;

    virtual antlrcpp::Any visitTowardOrAwayFrom(BehaviorsParser::TowardOrAwayFromContext *context) = 0;

    virtual antlrcpp::Any visitTarget(BehaviorsParser::TargetContext *context) = 0;

    virtual antlrcpp::Any visitStoppedBehavior(BehaviorsParser::StoppedBehaviorContext *context) = 0;

    virtual antlrcpp::Any visitWalkSpeedBehavior(BehaviorsParser::WalkSpeedBehaviorContext *context) = 0;

    virtual antlrcpp::Any visitNormalBehavior(BehaviorsParser::NormalBehaviorContext *context) = 0;

    virtual antlrcpp::Any visitStateActionStopped(BehaviorsParser::StateActionStoppedContext *context) = 0;

    virtual antlrcpp::Any visitStateActionWalkSpeed(BehaviorsParser::StateActionWalkSpeedContext *context) = 0;

    virtual antlrcpp::Any visitStateActionNormal(BehaviorsParser::StateActionNormalContext *context) = 0;


};

