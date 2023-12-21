#ifndef VIPRA_BEHAVIORS_DISEMBARK_BEHAVIOR_HPP
#define VIPRA_BEHAVIORS_DISEMBARK_BEHAVIOR_HPP

#include "behavior/human_behavior.hpp"
#include "builder/behavior_builder.hpp"
#include "configuration/config.hpp"
#include "definitions/state.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

namespace BHVR::TEST {
void disembark_behavior(VIPRA::PedestrianSet&, VIPRA::Goals&, VIPRA::State&);
}  // namespace BHVR::TEST

#endif