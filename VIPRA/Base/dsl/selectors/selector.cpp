#include "selector.hpp"

Selector::Selector(SimulationContext* simContext) {
  this->simulationContext = simContext;
}

SimulationContext*
Selector::getSimulationContext() {
  return this->simulationContext;
}

void
Selector::initialize(const ObstacleSet& obsSet, const PedestrianSet& pedSet, const Goals& goals) {}
