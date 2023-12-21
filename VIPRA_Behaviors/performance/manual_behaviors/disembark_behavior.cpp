/*

Types:
  Passenger
.

Location:
  Name: Plane_Front
  Dimensions:
    Center: {24, 1.7}
    Lengths: {3, 10}
    Rotation: 0
.

Selector:
  Type: Passenger
  Select: Everyone
.

Action (Passenger):
  Condition:
    Goal is @Plane_Front
    and
    Exists: Passenger in front, within 2m whose Goal is not @Plane_Front
    
  Response: set velocity to {0}
.
*/

#include "disembark_behavior.hpp"
#include "definitions/type_definitions.hpp"

namespace BHVR::TEST {

constexpr auto FRONT_CENTER = VIPRA::f3d{24, 1.7};
constexpr auto FRONT_LENGTHS = VIPRA::f3d{3, 10};
constexpr auto PLANE_FRONT = Location(FRONT_CENTER, FRONT_LENGTHS);

[[nodiscard]] auto ped_in_direction_of_goal(VIPRA::pcoord pedCoords, VIPRA::goal goal, VIPRA::pcoord other)
    -> bool {
  VIPRA::f3d pedDirection = goal - pedCoords;
  VIPRA::f3d secondDirection = other - pedCoords;

  const float dotProduct = (pedDirection.x * secondDirection.x) + (pedDirection.y * secondDirection.y) +
                           (pedDirection.z * secondDirection.z);

  return dotProduct > 0;
}

[[nodiscard]] inline auto check_exists(VIPRA::idx pedIdx, VIPRA::PedestrianSet& pedSet, VIPRA::Goals& goals)
    -> bool {
  for (VIPRA::idx idx = 0; idx < pedSet.getNumPedestrians(); ++idx) {
    if (idx == pedIdx) continue;

    if (goals.isPedestianGoalMet(idx)) continue;

    if (PLANE_FRONT.contains(goals.getCurrentGoal(idx))) continue;

    if (!ped_in_direction_of_goal(pedSet.getPedCoords(pedIdx), goals.getCurrentGoal(pedIdx),
                                  pedSet.getPedCoords(idx)))
      continue;

    if (pedSet.getPedCoords(idx).distanceTo(pedSet.getPedCoords(pedIdx)) > 2) continue;

    return true;
  }

  return false;
}

void disembark_behavior(VIPRA::PedestrianSet& pedSet, VIPRA::Goals& goals, VIPRA::State& state) {
  for (VIPRA::idx idx = 0; idx < pedSet.getNumPedestrians(); ++idx) {
    if (goals.isPedestianGoalMet(idx)) continue;
    if (!PLANE_FRONT.contains(goals.getCurrentGoal(idx))) continue;

    if (check_exists(idx, pedSet, goals)) {
      state.velocities[idx] = VIPRA::veloc{0};
      state.coords[idx] = pedSet.getPedCoords(idx);
    }
  }
}
}  // namespace BHVR::TEST