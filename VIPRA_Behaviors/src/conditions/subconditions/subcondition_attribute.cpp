

#include <conditions/subconditions/subcondition_attribute.hpp>
#include "targets/attributes.hpp"

namespace BHVR {
SubConditionAttribute::SubConditionAttribute(Attribute type, cAttributeValue val) : value(val) {}

bool SubConditionAttribute::operator()(Simpack pack, VIPRA::idx pedIdx, Target target) const {
  return AttributeHandling::getValue(target, type, pack) == value;
}
}  // namespace BHVR