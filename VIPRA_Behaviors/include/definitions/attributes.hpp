#ifndef VIPRA_BEHAVIORS_ATTRIBUTES_HPP
#define VIPRA_BEHAVIORS_ATTRIBUTES_HPP

#include <definitions/behavior_context.hpp>

#include <pedestrian_set/pedestrian_set.hpp>

#include <definitions/dimensions.hpp>
#include <definitions/type_definitions.hpp>

namespace Behaviors {
enum class PedAttribute {
  SPEED,
  END_GOAL,
  STATE,
};

float      getPed_speed(VIPRA::idx, const PedestrianSet&);
VIPRA::f3d getPed_endgoal(VIPRA::idx, const PedestrianSet&);
stateUID   getPed_state(VIPRA::idx, const BehaviorContext&);

}  // namespace Behaviors

#endif