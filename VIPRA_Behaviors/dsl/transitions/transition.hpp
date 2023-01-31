#ifndef VIPRA_TRANSITION_HPP
#define VIPRA_TRANSITION_HPP

#include <memory>

#include "conditions/condition.hpp"

#include "../definitions/behavior_context.hpp"

/**
 * A transition pairs a condition with a new state. If the condition evaluates
 * to true, the state is changed to the new value.
 */
class Transition {
 public:
  Transition(VIPRA::stateUID newState);
  virtual bool evaluate() = 0;

 protected:
  VIPRA::stateUID newState;
};

#endif  //VIPRA_TRANSITION_HPP
