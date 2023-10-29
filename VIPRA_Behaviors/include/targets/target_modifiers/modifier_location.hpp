#ifndef VIPRA_BEHAVIORS_MODIFIER_LOCATION_HPP
#define VIPRA_BEHAVIORS_MODIFIER_LOCATION_HPP

#include <utility>

#include "definitions/sim_pack.hpp"
#include "values/numeric_value.hpp"

#include "util/class_types.hpp"

namespace BHVR {
/**
  * @brief Target modifier for distance to target
  * 
  */
class ModifierDistance {
  NON_DEFAULT_CONSTRUCTIBLE(ModifierDistance)
  COPYABLE(ModifierDistance)
  MOVABLE(ModifierDistance)

 public:
  explicit ModifierDistance(VIPRA::idx location) : _location(location) {}

  /**
   * @brief Returns if target is within the location
   * 
   * @param pack : simulation pack
   * @param targetIdx : target to check
   * @param selfIdx : pedsetrian looking for target
   * @return true : if within distance
   * @return false : if NOT within distance
   */
  auto operator()(Simpack pack, VIPRA::idx targetIdx, VIPRA::idx selfIdx) const -> bool {
    // TODO:
  }

 private:
  VIPRA::idx _location;
};
}  // namespace BHVR

#endif