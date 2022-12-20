#include "condition.hpp"

Condition::Condition(SimulationContext* simContext) {
  this->simulationContext = simContext;
}

SimulationContext*
Condition::getSimulationContext() {
  return this->simulationContext;
}