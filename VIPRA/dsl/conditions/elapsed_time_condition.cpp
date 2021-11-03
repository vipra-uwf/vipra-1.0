#include "elapsed_time_condition.hpp"

ElapsedTimeCondition::ElapsedTimeCondition(SimulationContext *simulationContext, FLOATING_NUMBER desiredElapsedTime)
    : Condition(simulationContext)
{
    this->desiredElapsedTime = desiredElapsedTime;
}

bool ElapsedTimeCondition::evaluate(int pedestrianIndex)
{
    int pedestrianId = this->getSimulationContext()->pedestrianSet->getIds()->at(pedestrianIndex);
    FLOATING_NUMBER lastTransitionMs = 
        this->getSimulationContext()->elapsedSeconds - 
        this->getSimulationContext()->transitionPointSeconds.at(pedestrianId);

    return lastTransitionMs > this->desiredElapsedTime;
}