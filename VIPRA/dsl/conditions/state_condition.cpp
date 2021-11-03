#include "state_condition.hpp"

StateCondition::StateCondition(SimulationContext *simulationContext, int desiredState)
    : Condition(simulationContext)
{
    this->desiredState = desiredState;
}

bool StateCondition::evaluate(int pedestrianIndex)
{
    int pedestrianId = this
        ->getSimulationContext()
        ->pedestrianSet
        ->getIds()
        ->at(pedestrianIndex);

    return this
        ->getSimulationContext()
        ->states
        ->at(pedestrianId) == this->desiredState;
}
