//
// Created by joe on 12/5/21.
//

#include "environment_elapsed_time_condition.hpp"

EnvironmentElapsedTimeCondition::EnvironmentElapsedTimeCondition(SimulationContext* simulationContext,
                                                                 float              desiredElapsedTime)
  : ElapsedTimeCondition(simulationContext, desiredElapsedTime) {}

bool
EnvironmentElapsedTimeCondition::evaluate(const ObstacleSet&   obsSet,
                                          const PedestrianSet& pedestrianSet,
                                          const Goals&         goals,
                                          int                  pedestrianIndex) {
  float lastTransitionMs = this->getSimulationContext()->elapsedSeconds -
                           this->getSimulationContext()->environmentTransitionPointSeconds;

  return lastTransitionMs > this->desiredElapsedTime;
}
