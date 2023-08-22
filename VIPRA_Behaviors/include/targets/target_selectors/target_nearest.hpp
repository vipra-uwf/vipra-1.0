#ifndef VIPRA_BEHAVIORS_TARGET_NEAREST_SELECTOR_HPP
#define VIPRA_BEHAVIORS_TARGET_NEAREST_SELECTOR_HPP

#include <limits>

#include <definitions/pedestrian_types.hpp>
#include <definitions/sim_pack.hpp>
#include <targets/target.hpp>
#include "definitions/type_definitions.hpp"
#include "targets/target_modifier.hpp"

namespace BHVR {
/**
  * @brief Selects the nearest pedestrian with any of the given types
  * 
  */
struct TargetNearest {
  Ptype                         type;
  bool                          allPeds;
  std::optional<TargetModifier> modifier;

  /**
   * @brief Returns the nearest pedestrian that has any of the target types
   * 
   * @param pack : simulation pack
   * @param self : pedestrain calling the function
   * @return Target 
   */
  inline Target operator()(Simpack pack, Target self) const {
    if (allPeds) {
      auto curr = nearestInGroup(pack, self.targetIdx, pack.groups.getGroup(0));
      if (curr.second == VIPRA::idx_INVALID) return Target{TargetType::INVALID, 0};
      return {TargetType::PEDESTRIAN, curr.second};
    }

    VIPRA::dist shortest = std::numeric_limits<VIPRA::dist>::max();
    VIPRA::idx  nearest = VIPRA::idx_INVALID;

    type.forEachType([&](typeUID type) {
      VIPRA::idx groupIdx = GroupsContainer::index(type);
      auto curr = nearestInGroup(pack, self.targetIdx, pack.groups.getGroup(groupIdx));
      if (curr.first < shortest) {
        shortest = curr.first;
        nearest = curr.second;
      }
    });

    if (nearest == VIPRA::idx_INVALID) {
      return Target{TargetType::INVALID, 0};
    }

    return Target{TargetType::PEDESTRIAN, nearest};
  }

 private:
  /**
   * @brief Returns the nearest pedestrian and the distance to them in a given group
   * 
   * @param pack : simulation pack
   * @param self : pedestrian looking for target
   * @param idxs : vector of pedestrian indexes in group
   * @return std::pair<VIPRA::dist, VIPRA::idx> : nearest distance and nearest pedestrian index
   */
  [[nodiscard]] inline std::pair<VIPRA::dist, VIPRA::idx> nearestInGroup(
      Simpack pack, VIPRA::idx self, const VIPRA::idxVec& idxs) const {
    VIPRA::dist shortest = std::numeric_limits<VIPRA::dist>::max();
    VIPRA::idx  nearest = VIPRA::idx_INVALID;

    const auto&      coords = pack.pedSet.getCoordinates();
    const VIPRA::f3d currCoords = coords.at(self);

    for (VIPRA::idx pedIdx : idxs) {
      if (pedIdx == self) continue;
      if (pack.goals.isPedestianGoalMet(pedIdx)) continue;

      if (modifier) {
        if (!modifier->check(pack, pedIdx, self)) continue;
      }

      if (pack.obsSet.rayHit(currCoords, coords.at(pedIdx)) != -1) continue;

      VIPRA::dist curr = currCoords.distanceTo(coords.at(pedIdx));
      if (curr < shortest) {
        shortest = curr;
        nearest = pedIdx;
      }
    }
    return {shortest, nearest};
  }
};
}  // namespace BHVR

#endif