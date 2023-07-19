#ifndef VIPRA_SUBCONDITION_SPATIAL_HPP
#define VIPRA_SUBCONDITION_SPATIAL_HPP

#include <conditions/sub_condition.hpp>
#include <values/numeric_value.hpp>

namespace BHVR {
class SubConditionSpatial {
 public:
  explicit SubConditionSpatial(NumericValue);

  bool operator()(Simpack, VIPRA::idx, Target) const;

 private:
  NumericValue within;

 public:
  ~SubConditionSpatial() = default;
  SubConditionSpatial() = delete;
  SubConditionSpatial(const SubConditionSpatial&) = default;
  SubConditionSpatial& operator=(const SubConditionSpatial&) = default;
  SubConditionSpatial(SubConditionSpatial&&) noexcept = default;
  SubConditionSpatial& operator=(SubConditionSpatial&&) noexcept = default;
};
}  // namespace BHVR

#endif