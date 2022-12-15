#include "state_condition.hpp"

StateCondition::StateCondition(SimulationContext* simulationContext, int desiredState)
  : Condition(simulationContext) {
  this->desiredState = desiredState;
}

bool
StateCondition::evaluate(const ObstacleSet&   obsSet,
                         const PedestrianSet& pedestrianSet,
                         const Goals&         goals,
                         int                  pedestrianIndex) {
  int pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);

  int currentState = this->getSimulationContext()->states.at(pedestrianId);

  return currentState == this->desiredState;
}
