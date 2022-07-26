//
// Created by joe on 12/1/21.
//

#include "environment_state_condition.hpp"


EnvironmentStateCondition::EnvironmentStateCondition(SimulationContext *simulationContext, int state)
    : Condition(simulationContext), desiredState(state)
{

}

bool EnvironmentStateCondition::evaluate(int pedestrianIndex)
{
    return getSimulationContext()->environmentState == desiredState;
}
