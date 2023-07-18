#ifndef VIPRA_BEHAVIORS_TARGET_NEAREST_SELECTOR_HPP
#define VIPRA_BEHAVIORS_TARGET_NEAREST_SELECTOR_HPP

#include <limits>

#include <definitions/pedestrian_types.hpp>
#include <definitions/sim_pack.hpp>
#include <definitions/type_definitions.hpp>
#include <targets/target.hpp>

namespace BHVR {
struct TargetNearest {
  typeUID type;

  inline Target operator()(Simpack pack, Target self) const {
    VIPRA::idx groupIdx = GroupsContainer::index(type);

    const auto&      coords = pack.pedSet.getCoordinates();
    const VIPRA::f3d currCoords = coords.at(self.targetIdx);

    VIPRA::dist shortest = std::numeric_limits<VIPRA::dist>::max();
    VIPRA::idx  nearest = VIPRA::idx_INVALID;
    for (VIPRA::idx pedIdx : pack.groups.at(groupIdx)) {
      if (pedIdx == self.targetIdx) continue;
      if (pack.goals.isPedestianGoalMet(pedIdx)) continue;
      if (pack.obsSet.rayHit(currCoords, coords.at(pedIdx)) != -1) continue;

      VIPRA::dist curr = currCoords.distanceTo(coords.at(pedIdx));
      if (curr < shortest) {
        shortest = curr;
        nearest = pedIdx;
      }
    }

    if (nearest == VIPRA::idx_INVALID) {
      return Target{TargetType::INVALID, 0};
    }

    return Target{TargetType::PEDESTRIAN, nearest};
  }
};
}  // namespace BHVR

#endif