//
// Created by joe on 12/5/21.
//

#include "environment_elapsed_time_condition.hpp"

EnvironmentElapsedTimeCondition::EnvironmentElapsedTimeCondition(SimulationContext* simContext,
                                                                 float              elapsedTime)
  : ElapsedTimeCondition(simContext, elapsedTime) {}

bool
EnvironmentElapsedTimeCondition::evaluate(const ObstacleSet&   obsSet,
                                          const PedestrianSet& pedestrianSet,
                                          const Goals&         goals,
                                          VIPRA::idx           pedestrianIndex) {
  float lastTransitionMs = this->getSimulationContext()->elapsedSeconds -
                           this->getSimulationContext()->environmentTransitionPointSeconds;

  return lastTransitionMs > this->desiredElapsedTime;
}
