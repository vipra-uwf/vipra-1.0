#ifndef VIPRA_SUB_CONDITION_HPP
#define VIPRA_SUB_CONDITION_HPP

#include <functional>

#include <definitions/behavior_context.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

namespace BHVR {
/**
  * @brief Subconditions are composed in Conditions to create more complex conditions
  * 
  */
using SubCondition =
    std::function<bool(const PedestrianSet&, const ObstacleSet&, const Goals&,
                       const BehaviorContext&, VIPRA::idx, VIPRA::delta_t)>;
}  // namespace BHVR

#endif