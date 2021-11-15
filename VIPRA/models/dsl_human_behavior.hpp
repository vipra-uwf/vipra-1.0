#ifndef DSL_HUMAN_BEHAVIOR_HPP
#define DSL_HUMAN_BEHAVIOR_HPP

#include "human_behavior.hpp"
#include "../dsl/generated/BehaviorsBaseVisitor.h"

class DslHumanBehavior : public HumanBehavior, public BehaviorsBaseVisitor
{
    public:
        DslHumanBehavior();
        virtual ~DslHumanBehavior() = default;

        antlrcpp::Any visitStateSelector(BehaviorsParser::StateSelectorContext *ctx);
        antlrcpp::Any visitStateDeclaration(BehaviorsParser::StateDeclarationContext *ctx);
        antlrcpp::Any visitStateTransition(BehaviorsParser::StateTransitionContext *ctx);
        antlrcpp::Any visitStateAction(BehaviorsParser::StateActionContext *ctx);
        antlrcpp::Any visitConsideration(BehaviorsParser::ConsiderationContext *ctx);
};

#endif