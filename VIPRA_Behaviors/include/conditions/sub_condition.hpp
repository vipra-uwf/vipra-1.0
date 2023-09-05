#ifndef VIPRA_SUB_CONDITION_HPP
#define VIPRA_SUB_CONDITION_HPP

#include <functional>

#include <definitions/behavior_context.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>
#include <targets/target.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {
using SubCondition = std::function<bool(Simpack, VIPRA::idx, Target)>;
}  // namespace BHVR

#endif