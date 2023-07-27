#ifndef VIPRA_SUBCONDITION_ATTRIBUTE_HPP
#define VIPRA_SUBCONDITION_ATTRIBUTE_HPP

#include <attributes/attributes.hpp>
#include <conditions/sub_condition.hpp>

namespace BHVR {
/**
 * @brief SubCondition for target attribute to equal a value
 * 
 */
class SubConditionAttribute {
 public:
  explicit SubConditionAttribute(Attribute, CAttributeValue);

  bool operator()(Simpack, VIPRA::idx, Target) const;

 private:
  Attribute       type;
  CAttributeValue value;

 public:
  ~SubConditionAttribute() = default;
  SubConditionAttribute() = delete;
  SubConditionAttribute(const SubConditionAttribute&) = default;
  SubConditionAttribute& operator=(const SubConditionAttribute&) = default;
  SubConditionAttribute(SubConditionAttribute&&) noexcept = default;
  SubConditionAttribute& operator=(SubConditionAttribute&&) noexcept = default;
};
}  // namespace BHVR

#endif