#include "pedestrian_transition.hpp"

PedestrianTransition::PedestrianTransition(SimulationContext* simulationContext,
                                           Condition*         condition,
                                           int                newState)
  : Transition(simulationContext, condition, newState) {}

bool
PedestrianTransition::evaluateTransition(const ObstacleSet&   obsSet,
                                         const PedestrianSet& pedSet,
                                         const Goals&         goals,
                                         int                  pedestrianIndex) {
  int pedestrianId = pedSet.getIds().at(pedestrianIndex);

  bool transitioned = false;
  if (this->condition->evaluate(obsSet, pedSet, goals, pedestrianIndex)) {
    this->simulationContext->states.at(pedestrianId) = newState;
    this->simulationContext->transitionPointSeconds.at(pedestrianId) =
        this->simulationContext->elapsedSeconds;
    transitioned = true;
  }

  return transitioned;
}
