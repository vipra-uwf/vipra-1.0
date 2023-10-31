#ifndef VIPRA_SUBCONDITION_ATTRIBUTE_HPP
#define VIPRA_SUBCONDITION_ATTRIBUTE_HPP

#include "attributes/attributes.hpp"
#include "conditions/sub_condition.hpp"
#include "util/class_types.hpp"

namespace BHVR {
/**
 * @brief SubCondition for target attribute to equal a value
 * 
 */
class SubConditionAttribute {
  NON_DEFAULT_CONSTRUCTIBLE(SubConditionAttribute)
  COPYABLE(SubConditionAttribute)
  MOVEABLE(SubConditionAttribute)

 public:
  explicit SubConditionAttribute(Attribute, CAttributeValue, bool);

  [[nodiscard]] auto operator()(Simpack, VIPRA::idx, Target) const -> bool;

 private:
  Attribute       _type;
  CAttributeValue _value;
  bool            _not;
};
}  // namespace BHVR

#endif