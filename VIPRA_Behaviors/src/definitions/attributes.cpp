

#include <definitions/attributes.hpp>

#include <goals/goals.hpp>

namespace Behaviors {

float
getPed_speed(VIPRA::idx index, const PedestrianSet& pedSet) {
  return pedSet.getPedVelocity(index).magnitude();
}

VIPRA::f3d
getPed_endgoal(VIPRA::idx index, const Goals& goals) {
  return goals.getEndGoal(index);
}

stateUID
getPed_state(VIPRA::idx index, const BehaviorContext& context) {
  return context.pedStates.at(index);
}
}  // namespace Behaviors
