#ifndef SIMULATION_CONTEXT_HPP
#define SIMULATION_CONTEXT_HPP

#include <vector>

#include "definitions/type_definitions.hpp"
#include "dsl_types.hpp"

struct BehaviorContext {
  VIPRA::stateUID              environmentState;
  VIPRA::delta_t               elapsedTime;
  std::vector<VIPRA::stateUID> pedStates;
};

#endif