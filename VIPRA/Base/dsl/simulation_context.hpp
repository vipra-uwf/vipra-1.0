#ifndef SIMULATION_CONTEXT_HPP
#define SIMULATION_CONTEXT_HPP

#include <unordered_map>
#include <vector>

#include "definitions/type_definitions.hpp"
#include "dsl/definitions/dsl_types.hpp"

/**
 * Holder object for states vector. Used for actions, conditions, and selectors in the DSL.
 */
struct SimulationContext {
  std::unordered_map<VIPRA::idx, VIPRA::stateUID> states;
  VIPRA::stateUID                                 environmentState;

  // The timestamps for each person that transitions. This is used in the DSL state machine to define when a
  // person first entered the previous state, in case the rule is time-dependent (e.g., 30 minute nap).
  std::unordered_map<VIPRA::idx, float> transitionPointSeconds;
  float                                 environmentTransitionPointSeconds;

  // A store of the elapsed time for use in computations. This is updated in the behavior's update method.
  float elapsedSeconds;
};

#endif