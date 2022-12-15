#include "action.hpp"

#include <utility>

Action::Action(SimulationContext* simulationContext, std::string actionName)
  : actionName(std::move(actionName)) {
  this->simulationContext = simulationContext;
}

SimulationContext*
Action::getSimulationContext() {
  return this->simulationContext;
}

const std::string&
Action::getActionName() const {
  return actionName;
}

bool
Action::actionApplied(int pedestrianIndex) {
  return false;
}

void
Action::initialize(const PedestrianSet& pedestrianSet) {}
