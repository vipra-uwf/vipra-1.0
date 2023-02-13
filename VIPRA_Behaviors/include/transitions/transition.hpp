#ifndef VIPRA_TRANSITION_HPP
#define VIPRA_TRANSITION_HPP

#include <memory>

#include "../conditions/condition.hpp"

#include "../definitions/behavior_context.hpp"

/**
 * A transition pairs a condition with a new state. If the condition evaluates
 * to true, the state is changed to the new value.
 */
class Transition {
 public:
  Transition(VIPRA::stateUID);

  void addCondition(Condition&&);
  void evaluate(const PedestrianSet&, const ObstacleSet&, const Goals&, BehaviorContext&, VIPRA::idx, VIPRA::delta_t);

 protected:
  VIPRA::stateUID newState;
  Condition       condition;
};

#endif  //VIPRA_TRANSITION_HPP
