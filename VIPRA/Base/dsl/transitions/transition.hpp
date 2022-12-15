#ifndef VIPRA_TRANSITION_HPP
#define VIPRA_TRANSITION_HPP

#include "../conditions/condition.hpp"
#include "../simulation_context.hpp"

/**
 * A transition pairs a condition with a new state. If the condition evaluates
 * to true, the state is changed to the new value.
 */
class Transition {
 public:
  Transition(SimulationContext* simulationContext, Condition* condition, int newState);

 protected:
  SimulationContext* simulationContext;
  Condition*         condition;
  int                newState;
};

#endif  //VIPRA_TRANSITION_HPP
