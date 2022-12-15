#ifndef PEDESTRIAN_TRANSITION_HPP
#define PEDESTRIAN_TRANSITION_HPP

#include "../conditions/condition.hpp"
#include "../simulation_context.hpp"
#include "goals/goals.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"
#include "transition.hpp"

/**
 * A transition pairs a condition with a new state. If the condition evaluates
 * to true, the state is changed to the new value.
 */
class PedestrianTransition : public Transition {
 public:
  PedestrianTransition(SimulationContext* simulationContext, Condition* condition, int newState);
  bool evaluateTransition(const ObstacleSet&, const PedestrianSet&, const Goals&, int pedestrianIndex);
};

#endif