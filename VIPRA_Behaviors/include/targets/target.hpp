#ifndef VIPRA_BEHAVIORS_TARGET_HPP
#define VIPRA_BEHAVIORS_TARGET_HPP

#include <functional>

#include <definitions/behavior_context.hpp>
#include <definitions/sim_pack.hpp>
#include <definitions/type_definitions.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>
#include <random/random.hpp>

namespace BHVR {
enum class TargetType {
  PEDESTRIAN,
  EVENT,
  INVALID,
};

struct Target {
  TargetType type;
  VIPRA::idx targetIdx;
};

using TargetFunc = std::function<Target(Simpack, Target)>;

}  // namespace BHVR

#endif