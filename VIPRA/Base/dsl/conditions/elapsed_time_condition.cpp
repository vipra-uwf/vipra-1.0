#include "elapsed_time_condition.hpp"
#include <iostream>

ElapsedTimeCondition::ElapsedTimeCondition(SimulationContext* simContext, float elapsedTime)
  : Condition(simContext) {
  this->desiredElapsedTime = elapsedTime;
}

bool
ElapsedTimeCondition::evaluate(const ObstacleSet&   obsSet,
                               const PedestrianSet& pedestrianSet,
                               const Goals&         goals,
                               VIPRA::idx           pedestrianIndex) {
  // TODO: get index from id
  // VIPRA::uid pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);
  // float      lastTransitionMs = this->getSimulationContext()->elapsedSeconds -
  //                          this->getSimulationContext()->transitionPointSeconds.at(pedestrianId);

  // // std::cout << "last transition ms of pedestrian(" << pedestrianId << ") is " << lastTransitionMs << ". Desired is " << this->desiredElapsedTime << std::endl;

  // return lastTransitionMs > this->desiredElapsedTime;
  return false;
}