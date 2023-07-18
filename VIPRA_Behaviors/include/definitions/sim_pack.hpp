#ifndef VIPRA_BEHAVIORS_SIM_PACK_HPP
#define VIPRA_BEHAVIORS_SIM_PACK_HPP

#include <definitions/behavior_context.hpp>
#include <definitions/type_definitions.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>
#include "selectors/pedestrian_groups.hpp"

namespace BHVR {
struct Simpack {
  // NOLINTBEGIN (rolland) this is only used to pass references around : ignores (cppcoreguidelines-avoid-const-or-ref-data-members)
  const PedestrianSet&   pedSet;
  const ObstacleSet&     obsSet;
  const Goals&           goals;
  BehaviorContext&       context;
  const GroupsContainer& groups;
  VIPRA::delta_t         dT;
  // NOLINTEND
};
}  // namespace BHVR

#endif