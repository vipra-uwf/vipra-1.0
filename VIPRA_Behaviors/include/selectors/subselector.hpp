#ifndef VIPRA_BEHAVIORS_SUB_SELECTOR_HPP
#define VIPRA_BEHAVIORS_SUB_SELECTOR_HPP

#include <functional>

#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

#include <definitions/behavior_context.hpp>
#include <definitions/pedestrian_types.hpp>

namespace Behaviors {
using SelectorFunc = std::function<std::vector<
    VIPRA::idx>(seed, const std::vector<VIPRA::idx>&, const PedestrianSet&, const ObstacleSet&, const Goals&)>;

struct SubSelector {
  typeUID      group;
  pType        type;
  SelectorFunc select;
};
}  // namespace Behaviors

#endif