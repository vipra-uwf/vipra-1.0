#ifndef VIPRA_SUBCONDITION_SPATIAL_HPP
#define VIPRA_SUBCONDITION_SPATIAL_HPP

#include "conditions/sub_condition.hpp"
#include "util/class_types.hpp"
#include "values/numeric_value.hpp"

namespace BHVR {
class SubConditionSpatial {
  NON_DEFAULT_CONSTRUCTIBLE(SubConditionSpatial)
  COPYABLE(SubConditionSpatial)
  MOVEABLE(SubConditionSpatial)
 public:
  explicit SubConditionSpatial(NumericValue);

  [[nodiscard]] auto operator()(Simpack, VIPRA::idx, Target) const -> bool;

 private:
  NumericValue _within;
};
}  // namespace BHVR

#endif