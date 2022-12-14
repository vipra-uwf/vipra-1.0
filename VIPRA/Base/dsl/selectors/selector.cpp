#include "selector.hpp"

Selector::Selector(SimulationContext* simulationContext) {
  this->simulationContext = simulationContext;
}

SimulationContext*
Selector::getSimulationContext() {
  return this->simulationContext;
}

void
Selector::initialize(const ObstacleSet& obsSet, const PedestrianSet& pedSet, const Goals& goals) {}
