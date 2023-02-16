#ifndef SIMULATION_CONTEXT_HPP
#define SIMULATION_CONTEXT_HPP

#include <vector>

#include "definitions/type_definitions.hpp"
#include "dsl_types.hpp"

namespace Behaviors {
struct BehaviorContext {
  VIPRA::delta_t                   elapsedTime;
  Behaviors::stateUID              environmentState = 0;
  std::vector<Behaviors::stateUID> pedStates;
};
}  // namespace Behaviors

#endif