#include "dsl_human_behavior.hpp"
#include "../dsl/generated/BehaviorsLexer.h"
#include "../dsl/generated/BehaviorsParser.h"
#include "../dsl/selectors/id_ratio_selector.hpp"
#include "../dsl/actions/stop_movement_action.hpp"
#include "../dsl/conditions/and_condition.hpp"
#include "../dsl/conditions/state_condition.hpp"
#include "../dsl/conditions/elapsed_time_condition.hpp"
#include <iostream>
#include <fstream>

int findState(std::vector<std::string> states, std::string stateName)
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

DslHumanBehavior::DslHumanBehavior()
    : HumanBehavior()
{
    // Read in the hard-coded file
    std::ifstream dslFile("random_sleep.behavior");
    std::string line;

    antlr4::ANTLRInputStream input(dslFile);
    BehaviorsLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    BehaviorsParser parser(&tokens);

    BehaviorsParser::ProgramContext *tree = parser.program();

    this->visitProgram(tree);
}

antlrcpp::Any DslHumanBehavior::visitConsideration(BehaviorsParser::ConsiderationContext *ctx)
{
    std::cout << "Considering " << ctx->ID()->getText() << " type of person" << std::endl;
    return BehaviorsBaseVisitor::visitConsideration(ctx);
}

antlrcpp::Any DslHumanBehavior::visitStateSelector(BehaviorsParser::StateSelectorContext *ctx)
{
    float percent = std::atof(ctx->NUMBER()->getText().c_str());
    this->addSelector(new IdRatioSelector(this->getSimulationContext(), percent / 100.0));
    std::cout << "Added selector for " << percent << " percent of the population" << std::endl;
    return 0;
}

antlrcpp::Any DslHumanBehavior::visitStateDeclaration(BehaviorsParser::StateDeclarationContext *ctx)
{
    std::string state = ctx->ID(1)->getText();
    this->addStateDefinition(state);

    std::cout << "Added state definition for " << state << std::endl;
    return 0;
}

antlrcpp::Any DslHumanBehavior::visitStateTransition(BehaviorsParser::StateTransitionContext *ctx)
{
    std::string fromStateName = ctx->ID(1)->getText();
    int fromState = findState(this->getStateDefinitions(), fromStateName);
    std::string toStateName = ctx->ID(2)->getText();
    int toState = findState(this->getStateDefinitions(), toStateName);

    float seconds = std::atof(ctx->NUMBER()->getText().c_str());

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

    std::cout << "Added transition from " << fromStateName << " to " << toStateName << " after " << seconds << " seconds" << std::endl;

    return 0;
}

antlrcpp::Any DslHumanBehavior::visitStateAction(BehaviorsParser::StateActionContext *ctx)
{
    std::string stateName = ctx->ID(1)->getText();
    int state = findState(this->getStateDefinitions(), stateName);

    std::string stateAction = ctx->ID(2)->getText();
    // only STOPPED Supported for now
    if (stateAction == "STOPPED")
    {
        this->addStateAction(state, new StopMovementAction(this->getSimulationContext()));
        std::cout << "Added stopped action for state " << stateName << std::endl;
    }

    return 0;
}
