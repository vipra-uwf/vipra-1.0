//
// Created by joe on 12/5/21.
//

#include "environment_transition.hpp"

EnvironmentTransition::EnvironmentTransition(SimulationContext* simContext,
                                             Condition*         cond,
                                             VIPRA::stateUID    nextState)
  : Transition(simContext, cond, nextState) {}

bool
EnvironmentTransition::evaluateTransition(const ObstacleSet&          obsSet,
                                          const PedestrianSet&        pedSet,
                                          const Goals&                goals,
                                          [[maybe_unused]] VIPRA::idx pedestrianIndex) {
  if (this->condition->evaluate(obsSet, pedSet, goals, 0)) {
    this->simulationContext->environmentState = newState;
    this->simulationContext->environmentTransitionPointSeconds = this->simulationContext->elapsedSeconds;
    return true;
  }

  return false;
}
