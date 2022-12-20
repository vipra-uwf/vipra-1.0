//
// Created by joe on 12/1/21.
//

#include "environment_state_condition.hpp"

EnvironmentStateCondition::EnvironmentStateCondition(SimulationContext* simContext, VIPRA::stateUID state)
  : Condition(simContext), desiredState(state) {}

bool
EnvironmentStateCondition::evaluate(const ObstacleSet&   obsSet,
                                    const PedestrianSet& pedestrianSet,
                                    const Goals&         goals,
                                    VIPRA::idx           pedestrianIndex) {
  return getSimulationContext()->environmentState == desiredState;
}
