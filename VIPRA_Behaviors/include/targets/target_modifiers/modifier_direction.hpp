#ifndef VIPRA_BEHAVIORS_MODIFIER_DIRECTION_HPP
#define VIPRA_BEHAVIORS_MODIFIER_DIRECTION_HPP

#include "definitions/sim_pack.hpp"
#include "values/direction.hpp"
#include "values/numeric_value.hpp"

namespace BHVR {
/**
 * @brief Target Modifier for direction to target
 * 
 */
class ModifierDirection {
 public:
  explicit ModifierDirection(Direction direction) : dir(direction) {}

  /**
   * @brief Returns true if the target is in the desired direction
   * 
   * @param pack : simulation pack
   * @param targetIdx : target to check
   * @param selfIdx : pedestrain looking for target
   * @return true : if in direction
   * @return false : if not in direction
   */
  bool operator()(Simpack pack, VIPRA::idx targetIdx, VIPRA::idx selfIdx) const {
    const auto& goalCoord = pack.goals.getCurrentGoal(selfIdx);
    const auto& selfCoord = pack.pedSet.getPedCoords(selfIdx);
    const auto& targetCoord = pack.pedSet.getPedCoords(targetIdx);

    auto forward = goalCoord - selfCoord;
    auto dif = targetCoord - selfCoord;

    if (dir == Direction::FRONT) {
      return forward.dot(dif) > 0;
    }

    return forward.dot(dif) <= 0;
  }

 private:
  Direction dir;

 public:
  ~ModifierDirection() = default;
  ModifierDirection() = delete;
  ModifierDirection(const ModifierDirection&) = default;
  ModifierDirection& operator=(const ModifierDirection&) = default;
  ModifierDirection(ModifierDirection&&) noexcept = default;
  ModifierDirection& operator=(ModifierDirection&&) noexcept = default;
};
}  // namespace BHVR

#endif