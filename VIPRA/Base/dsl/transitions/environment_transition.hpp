#ifndef VIPRA_ENVIRONMENT_TRANSITION_HPP
#define VIPRA_ENVIRONMENT_TRANSITION_HPP

#include "goals/goals.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"
#include "transition.hpp"

class EnvironmentTransition : public Transition {
 public:
  EnvironmentTransition(SimulationContext* simulationContext, Condition* condition, VIPRA::stateUID newState);
  bool evaluateTransition(const ObstacleSet&, const PedestrianSet&, const Goals&, VIPRA::idx pedestrianIndex);
};

#endif  //VIPRA_ENVIRONMENT_TRANSITION_HPP
