#ifndef SIMULATION_CONTEXT_HPP
#define SIMULATION_CONTEXT_HPP

/**
 * Holder object for states vector. Used for actions, conditions, and selectors in the DSL.
 */
struct SimulationContext {
  std::vector<int> states;
  int              environmentState;

  // The timestamps for each person that transitions. This is used in the DSL state machine to define when a
  // person first entered the previous state, in case the rule is time-dependent (e.g., 30 minute nap).
  std::vector<float> transitionPointSeconds;
  float              environmentTransitionPointSeconds;

  // A store of the elapsed time for use in computations. This is updated in the behavior's update method.
  float elapsedSeconds;
};

#endif