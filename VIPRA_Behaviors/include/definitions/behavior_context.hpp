#ifndef SIMULATION_CONTEXT_HPP
#define SIMULATION_CONTEXT_HPP

#include <vector>
#include <memory>

#include <definitions/dsl_types.hpp>
#include <definitions/pedestrian_types.hpp>
#include <definitions/type_definitions.hpp>

namespace BHVR {
class Event;
class Location;
struct BehaviorContext {
  VIPRA::delta_t              elapsedTime = 0;
  BHVR::stateUID              environmentState = 0;
  std::vector<BHVR::stateUID> pedStates;
  std::vector<BHVR::typeUID>  types;
  std::vector<BHVR::Event>    events;
  std::vector<BHVR::Location> locations;
};
}  // namespace BHVR

#endif