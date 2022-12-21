#include "state_condition.hpp"

StateCondition::StateCondition(SimulationContext* simContext, VIPRA::stateUID desiredStateId) : Condition(simContext) {
  this->desiredState = desiredStateId;
}

bool
StateCondition::evaluate(const ObstacleSet&   obsSet,
                         const PedestrianSet& pedestrianSet,
                         const Goals&         goals,
                         VIPRA::idx           pedestrianIndex) {
  // TODO: get index from id
  VIPRA::uid pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);

  VIPRA::stateUID currentState = this->getSimulationContext()->states.at(pedestrianId);

  return currentState == this->desiredState;
  return false;
}
