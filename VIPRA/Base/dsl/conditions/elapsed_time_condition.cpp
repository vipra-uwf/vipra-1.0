#include "elapsed_time_condition.hpp"
#include <iostream>

ElapsedTimeCondition::ElapsedTimeCondition(SimulationContext *simulationContext, FLOATING_NUMBER desiredElapsedTime)
    : Condition(simulationContext)
{
    this->desiredElapsedTime = desiredElapsedTime;
}

bool ElapsedTimeCondition::evaluate(int pedestrianIndex, const PedestrianSet& pedestrianSet)
{
    int pedestrianId = pedestrianSet->getIds().at(pedestrianIndex);
    FLOATING_NUMBER lastTransitionMs = 
        this->getSimulationContext()->elapsedSeconds - 
        this->getSimulationContext()->transitionPointSeconds.at(pedestrianId);
    
    // std::cout << "last transition ms of pedestrian(" << pedestrianId << ") is " << lastTransitionMs << ". Desired is " << this->desiredElapsedTime << std::endl;

    return lastTransitionMs > this->desiredElapsedTime;
}