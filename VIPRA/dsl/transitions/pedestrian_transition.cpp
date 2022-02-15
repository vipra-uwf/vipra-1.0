#include "pedestrian_transition.hpp"

PedestrianTransition::PedestrianTransition(SimulationContext *simulationContext, Condition *condition, int newState)
    : Transition(simulationContext, condition, newState)
{
}

bool PedestrianTransition::evaluateTransition(int pedestrianIndex)
{
    int pedestrianId = this->simulationContext->pedestrianSet->getIds()->at(pedestrianIndex);

    bool transitioned = false;
    if (this->condition->evaluate(pedestrianIndex))
    {
        this->simulationContext->states.at(pedestrianId) = newState;
        this->simulationContext->transitionPointSeconds.at(pedestrianId) = this->simulationContext->elapsedSeconds;
        transitioned = true;
    }

    return transitioned;
}
