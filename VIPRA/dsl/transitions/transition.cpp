#include "transition.hpp"

Transition::Transition(SimulationContext *simulationContext, Condition *condition, int newState)
{
    this->simulationContext = simulationContext;
    this->condition = condition;
    this->newState = newState;
}

bool Transition::evaluateTransition(int pedestrianIndex)
{
    int pedestrianId = this->simulationContext->pedestrianSet->getIds()->at(pedestrianIndex);

    bool transitioned = false;
    if (this->condition->evaluate(pedestrianIndex))
    {
        this->simulationContext->states->at(pedestrianId) = newState;
        this->simulationContext->transitionPointSeconds.at(pedestrianId) = this->simulationContext->elapsedSeconds;
        transitioned = true;
    }

    return transitioned;
}
