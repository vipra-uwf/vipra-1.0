//
// Created by joe on 12/5/21.
//

#include "environment_transition.hpp"

EnvironmentTransition::EnvironmentTransition(SimulationContext *simulationContext, Condition *condition, int newState)
        : Transition(simulationContext, condition, newState)
{

}

bool EnvironmentTransition::evaluateTransition()
{
    bool transitioned = false;
    if (this->condition->evaluate(0))
    {
        this->simulationContext->environmentState = newState;
        this->simulationContext->environmentTransitionPointSeconds = this->simulationContext->elapsedSeconds;
        transitioned = true;
    }

    return transitioned;
}
