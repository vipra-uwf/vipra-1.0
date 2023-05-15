#ifndef SIMULATION_CONTEXT_HPP
#define SIMULATION_CONTEXT_HPP

#include <vector>

#include <definitions/dsl_types.hpp>
#include <definitions/pedestrian_types.hpp>
#include <definitions/type_definitions.hpp>


namespace BHVR {
struct BehaviorContext {
  VIPRA::delta_t              elapsedTime = 0;
  BHVR::stateUID              environmentState = 0;
  std::vector<BHVR::stateUID> pedStates;
  std::vector<BHVR::typeUID>  types;
};
}  // namespace BHVR

#endif