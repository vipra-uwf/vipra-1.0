#include "pedestrian_transition.hpp"

PedestrianTransition::PedestrianTransition(SimulationContext* simulationContext,
                                           Condition*         condition,
                                           int                newState)
  : Transition(simulationContext, condition, newState) {}

bool
PedestrianTransition::evaluateTransition(const PedestrianSet& pedSet, int pedestrianIndex) {
  int pedestrianId = pedSet.getIds().at(pedestrianIndex);

  bool transitioned = false;
  if (this->condition->evaluate(pedestrianIndex, pedSet)) {
    this->simulationContext->states.at(pedestrianId) = newState;
    this->simulationContext->transitionPointSeconds.at(pedestrianId) =
        this->simulationContext->elapsedSeconds;
    transitioned = true;
  }

  return transitioned;
}
