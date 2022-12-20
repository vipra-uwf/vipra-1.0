#include "action.hpp"

#include <utility>

Action::Action(SimulationContext* simContext, std::string name) : actionName(std::move(name)) {
  this->simulationContext = simContext;
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
Action::actionApplied(VIPRA::idx pedestrianIndex) {
  return false;
}

void
Action::initialize(const PedestrianSet& pedestrianSet) {}
