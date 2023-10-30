#ifndef VIPRA_SUBCONDITION_LOCATION_HPP
#define VIPRA_SUBCONDITION_LOCATION_HPP

#include "attributes/attributes.hpp"
#include "conditions/sub_condition.hpp"
#include "util/class_types.hpp"

namespace BHVR {
/**
 * @brief SubCondition for target being in a location
 * 
 */
class SubConditionInLocation {
  NON_DEFAULT_CONSTRUCTIBLE(SubConditionInLocation)
  COPYABLE(SubConditionInLocation)
  MOVEABLE(SubConditionInLocation)

 public:
  explicit SubConditionInLocation(VIPRA::idx);

  [[nodiscard]] auto operator()(Simpack, VIPRA::idx, Target) const -> bool;

 private:
  VIPRA::idx _location;
};
}  // namespace BHVR

#endif