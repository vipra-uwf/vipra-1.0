#include "state_condition.hpp"

StateCondition::StateCondition(SimulationContext *simulationContext, int desiredState)
    : Condition(simulationContext)
{
    this->desiredState = desiredState;
}

bool StateCondition::evaluate(int pedestrianIndex, const PedestrianSet& pedestrianSet)
{
    int pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);

    int currentState = this->getSimulationContext()->states.at(pedestrianId);
    
    return  currentState == this->desiredState;
}
