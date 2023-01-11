#include "pedestrian_transition.hpp"

PedestrianTransition::PedestrianTransition(SimulationContext* simContext,
                                           Condition*         cond,
                                           VIPRA::stateUID    nextState)
  : Transition(simContext, cond, nextState) {}

bool
PedestrianTransition::evaluateTransition(const ObstacleSet&   obsSet,
                                         const PedestrianSet& pedSet,
                                         const Goals&         goals,
                                         VIPRA::idx           pedestrianIndex) {
  if (this->condition->evaluate(obsSet, pedSet, goals, pedestrianIndex)) {
    this->simulationContext->states.at(pedestrianIndex) = newState;
    this->simulationContext->transitionPointSeconds.at(pedestrianIndex) = this->simulationContext->elapsedSeconds;
    return true;
  }

  return false;
}
