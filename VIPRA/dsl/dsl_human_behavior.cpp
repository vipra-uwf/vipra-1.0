#include "dsl_human_behavior.hpp"
#include "generated/BehaviorsLexer.h"
#include "generated/BehaviorsParser.h"
#include "selectors/everyone_selector.hpp"
#include "selectors/id_ratio_selector.hpp"
#include "selectors/id_random_selector.hpp"
#include "actions/stop_movement_action.hpp"
#include "conditions/and_condition.hpp"
#include "conditions/state_condition.hpp"
#include "conditions/elapsed_time_condition.hpp"
#include <iostream>
#include <fstream>
#include <antlr4-runtime/support/Any.h>

int findState(std::vector<std::string> states, const std::string& stateName)
{
    for (int i = 0; i < states.size(); ++i)
    {
        if (states.at(i) == stateName)
        {
            return i;
        }
    }

    return -1;
}

DslHumanBehavior::DslHumanBehavior(const std::string &fileName, unsigned int seed)
    : HumanBehavior(), seed(seed)
{
    std::ifstream dslFile(fileName);
    std::string line;

    antlr4::ANTLRInputStream input(dslFile);
    BehaviorsLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    BehaviorsParser parser(&tokens);

    BehaviorsParser::ProgramContext *tree = parser.program();

    this->visitProgram(tree);
}

DslHumanBehavior::DslHumanBehavior(const std::string& fileName)
        : DslHumanBehavior(fileName, time(nullptr))
{
}

antlrcpp::Any DslHumanBehavior::visitConsideration(BehaviorsParser::ConsiderationContext *ctx)
{
    this->behavior = ctx->ID()->getText();
    std::cout << "Considering " << this->behavior << " type of person" << std::endl;
    return BehaviorsBaseVisitor::visitConsideration(ctx);
}

antlrcpp::Any DslHumanBehavior::visitIdRatioSelector(BehaviorsParser::IdRatioSelectorContext *ctx)
{
    float percent = std::atof(ctx->NUMBER()->getText().c_str());
    this->addSelector(new IdRatioSelector(this->getSimulationContext(), percent / 100.0));
    std::cout << behavior << ": Added selector for " << percent
              << " percent of the population" << std::endl;
    return BehaviorsBaseVisitor::visitIdRatioSelector(ctx);
}


antlrcpp::Any DslHumanBehavior::visitStateDeclaration(BehaviorsParser::StateDeclarationContext *ctx)
{
    std::string state = ctx->ID(1)->getText();
    this->addStateDefinition(state);

    std::cout << behavior << ": Added state definition for " << state << std::endl;
    return 0;
}

antlrcpp::Any DslHumanBehavior::visitStateTransition(BehaviorsParser::StateTransitionContext *ctx)
{
    std::string fromStateName = ctx->pedestrianSelected()->ID(1)->getText();
    int fromState = findState(this->getStateDefinitions(), fromStateName);
    std::string toStateName = ctx->ID()->getText();
    int toState = findState(this->getStateDefinitions(), toStateName);

    float seconds = std::atof(ctx->stateCondition()->NUMBER()->getText().c_str());

    SimulationContext *simulationContext = this->getSimulationContext();
    this->addTransition
    (
        new Transition
        (
                simulationContext,
                new AndCondition
                        (
                                simulationContext,
                                new StateCondition(simulationContext, fromState),
                                new ElapsedTimeCondition(simulationContext, seconds)
                        ),
                toState
        )
    );

    std::cout << behavior << ": Added transition from "
              << fromStateName << " to " << toStateName
              << " after " << seconds << " seconds" << std::endl;

    return 0;
}

antlrcpp::Any DslHumanBehavior::visitStateActionStopped(BehaviorsParser::StateActionStoppedContext *ctx)
{
    std::string stateName = ctx->pedestrianSelected()->ID(1)->getText();
    int state = findState(this->getStateDefinitions(), stateName);
    this->addStateAction(state, new StopMovementAction(this->getSimulationContext()));
    std::cout << behavior << ": Added stopped action for state " << stateName << std::endl;

    return BehaviorsBaseVisitor::visitStateActionStopped(ctx);
}

antlrcpp::Any DslHumanBehavior::visitNoGroupRandomIdSelector(BehaviorsParser::NoGroupRandomIdSelectorContext *ctx)
{
    float numerator = std::atof(ctx->randomIdRatioStatement()->NUMBER(0)->getText().c_str());
    float denominator = std::atof(ctx->randomIdRatioStatement()->NUMBER(1)->getText().c_str());
    this->addSelector(new IdRandomSelector(
            this->getSimulationContext(),
            numerator / denominator,
            seed));
    std::cout << behavior << ": Added selector for a random " << numerator
              << " out of " << denominator
              << " pedestrians with a seed of " << seed << std::endl;

    return BehaviorsBaseVisitor::visitNoGroupRandomIdSelector(ctx);
}

antlrcpp::Any DslHumanBehavior::visitEveryoneSelector(BehaviorsParser::EveryoneSelectorContext *ctx)
{
    this->addSelector(new EveryoneSelector(this->getSimulationContext()));
    std::cout << behavior << ": Added selector for everyone. " << std::endl;

    return BehaviorsBaseVisitor::visitEveryoneSelector(ctx);
}

antlrcpp::Any DslHumanBehavior::visitInitialStateDeclaration(BehaviorsParser::InitialStateDeclarationContext *ctx)
{
    std::string stateName = ctx->ID(1)->getText();
    int stateValue = findState(this->getStateDefinitions(), stateName);
    this->setInitialState(stateValue);
    std::cout << behavior << ": Set initial state to " << stateName << std::endl;
    return BehaviorsBaseVisitor::visitInitialStateDeclaration(ctx);
}
