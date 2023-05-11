#ifndef VIPRA_SUB_CONDITION_HPP
#define VIPRA_SUB_CONDITION_HPP

#include <functional>

#include <definitions/behavior_context.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

namespace Behaviors {

using SubCondition = std::function<
    bool(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx, VIPRA::delta_t)>;

}  // namespace Behaviors

#endif