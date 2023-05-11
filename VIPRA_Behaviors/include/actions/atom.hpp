#ifndef VIPRA_ACTION_ATOM_HPP
#define VIPRA_ACTION_ATOM_HPP

#include <functional>

#include <definitions/behavior_context.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

namespace Behaviors {

using Atom = std::function<
    void(PedestrianSet&, ObstacleSet&, Goals&, BehaviorContext&, VIPRA::idx, VIPRA::delta_t, std::shared_ptr<VIPRA::State>)>;

}  // namespace Behaviors

#endif