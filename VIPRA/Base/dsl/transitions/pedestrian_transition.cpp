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
  // TODO: get index from id
  // VIPRA::uid pedestrianId = pedSet.getIds().at(pedestrianIndex);

  // bool transitioned = false;
  // if (this->condition->evaluate(obsSet, pedSet, goals, pedestrianIndex)) {
  //   this->simulationContext->states.at(pedestrianId) = newState;
  //   this->simulationContext->transitionPointSeconds.at(pedestrianId) =
  //       this->simulationContext->elapsedSeconds;
  //   transitioned = true;
  // }

  // return transitioned;
  return false;
}
