#ifndef VIPRA_BEHAVIORS_SIM_PACK_HPP
#define VIPRA_BEHAVIORS_SIM_PACK_HPP

#include <definitions/behavior_context.hpp>
#include <definitions/state.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>
#include <selectors/pedestrian_groups.hpp>
#include "definitions/type_definitions.hpp"

namespace BHVR {
/**
  * @brief Holds references to commonly used parameters for simpler passing
  * 
  */
struct Simpack {
  // NOLINTBEGIN (rolland) this is only used to pass references around : ignores (cppcoreguidelines-avoid-const-or-ref-data-members)
  const VIPRA::PedestrianSet& pedSet;
  const VIPRA::ObstacleSet&   obsSet;
  VIPRA::Goals&               goals;
  VIPRA::State&               state;
  BehaviorContext&            context;
  const GroupsContainer&      groups;
  VIPRA::delta_t              dT;
  // NOLINTEND
};
}  // namespace BHVR

#endif