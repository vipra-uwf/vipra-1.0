#include "condition.hpp"

Condition::Condition(SimulationContext* simulationContext) {
  this->simulationContext = simulationContext;
}

SimulationContext*
Condition::getSimulationContext() {
  return this->simulationContext;
}