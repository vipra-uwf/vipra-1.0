#ifndef VIPRA_SUBCONDITION_EXISTS_HPP
#define VIPRA_SUBCONDITION_EXISTS_HPP

#include <optional>

#include "attributes/attributes.hpp"
#include "conditions/sub_condition.hpp"
#include "conditions/subconditions/subcondition_attribute.hpp"
#include "targets/target_modifier.hpp"
#include "util/class_types.hpp"

namespace BHVR {
/**
 * @brief SubCondition for target attribute to equal a value
 * 
 */
class SubConditionExists {
  NON_DEFAULT_CONSTRUCTIBLE(SubConditionExists)
  COPYABLE(SubConditionExists)
  MOVEABLE(SubConditionExists)

 public:
  explicit SubConditionExists(TargetModifier, SubConditionAttribute);

  [[nodiscard]] auto operator()(Simpack, VIPRA::idx, Target) const -> bool;

 private:
  TargetModifier        _modifier;
  SubConditionAttribute _attributeCond;
};
}  // namespace BHVR

#endif