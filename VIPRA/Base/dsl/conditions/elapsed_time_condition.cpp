#include "elapsed_time_condition.hpp"
#include <iostream>

ElapsedTimeCondition::ElapsedTimeCondition(SimulationContext* simulationContext, float desiredElapsedTime)
  : Condition(simulationContext) {
  this->desiredElapsedTime = desiredElapsedTime;
}

bool
ElapsedTimeCondition::evaluate(const ObstacleSet&   obsSet,
                               const PedestrianSet& pedestrianSet,
                               const Goals&         goals,
                               int                  pedestrianIndex) {
  int   pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);
  float lastTransitionMs = this->getSimulationContext()->elapsedSeconds -
                           this->getSimulationContext()->transitionPointSeconds.at(pedestrianId);

  // std::cout << "last transition ms of pedestrian(" << pedestrianId << ") is " << lastTransitionMs << ". Desired is " << this->desiredElapsedTime << std::endl;

  return lastTransitionMs > this->desiredElapsedTime;
}