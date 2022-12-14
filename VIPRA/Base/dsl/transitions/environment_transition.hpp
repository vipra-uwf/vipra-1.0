#ifndef VIPRA_ENVIRONMENT_TRANSITION_HPP
#define VIPRA_ENVIRONMENT_TRANSITION_HPP

#include "pedestrianset/pedestrian_set.hpp"
#include "transition.hpp"

class EnvironmentTransition : public Transition {
 public:
  EnvironmentTransition(SimulationContext* simulationContext, Condition* condition, int newState);
  bool evaluateTransition(const PedestrianSet&);
};

#endif  //VIPRA_ENVIRONMENT_TRANSITION_HPP
