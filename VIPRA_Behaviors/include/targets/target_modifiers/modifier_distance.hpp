#ifndef VIPRA_BEHAVIORS_MODIFIER_DISTANCE_HPP
#define VIPRA_BEHAVIORS_MODIFIER_DISTANCE_HPP

#include <utility>

#include "definitions/sim_pack.hpp"
#include "values/numeric_value.hpp"

namespace BHVR {
/**
  * @brief Target modifier for distance to target
  * 
  */
class ModifierDistance {
 public:
  explicit ModifierDistance(NumericValue value) : dist(std::move(value)) {}

  /**
   * @brief Returns if target is within distance
   * 
   * @param pack : simulation pack
   * @param targetIdx : target to check
   * @param selfIdx : pedsetrian looking for target
   * @return true : if within distance
   * @return false : if NOT within distance
   */
  bool operator()(Simpack pack, VIPRA::idx targetIdx, VIPRA::idx selfIdx) const {
    return pack.pedSet.getPedCoords(selfIdx).distanceTo(
               pack.pedSet.getPedCoords(targetIdx)) <= dist.value(selfIdx);
  }

 private:
  NumericValue dist;

 public:
  ~ModifierDistance() = default;
  ModifierDistance() = delete;
  ModifierDistance(const ModifierDistance&) = default;
  ModifierDistance& operator=(const ModifierDistance&) = default;
  ModifierDistance(ModifierDistance&&) noexcept = default;
  ModifierDistance& operator=(ModifierDistance&&) noexcept = default;
};
}  // namespace BHVR

#endif