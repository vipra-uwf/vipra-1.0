//
// Created by joe on 12/5/21.
//

#include "environment_elapsed_time_condition.hpp"


EnvironmentElapsedTimeCondition::EnvironmentElapsedTimeCondition(SimulationContext *simulationContext,
                                                                 FLOATING_NUMBER desiredElapsedTime)
        : ElapsedTimeCondition(simulationContext, desiredElapsedTime)
{
}

bool EnvironmentElapsedTimeCondition::evaluate(int pedestrianIndex)
{
    FLOATING_NUMBER lastTransitionMs =
            this->getSimulationContext()->elapsedSeconds -
            this->getSimulationContext()->environmentTransitionPointSeconds;

    return lastTransitionMs > this->desiredElapsedTime;
}
