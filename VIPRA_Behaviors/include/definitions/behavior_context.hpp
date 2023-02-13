#ifndef SIMULATION_CONTEXT_HPP
#define SIMULATION_CONTEXT_HPP

#include <vector>

#include "definitions/type_definitions.hpp"
#include "dsl_types.hpp"

struct BehaviorContext {
  VIPRA::delta_t               elapsedTime;
  VIPRA::stateUID              environmentState = 0;
  std::vector<VIPRA::stateUID> pedStates;
};

#endif