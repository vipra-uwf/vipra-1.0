

#include <attributes/attributes.hpp>
#include <conditions/subconditions/subcondition_attribute.hpp>

namespace BHVR {
SubConditionAttribute::SubConditionAttribute(Attribute type, CAttributeValue val)
    : type(type), value(val) {}

bool SubConditionAttribute::operator()(Simpack pack, VIPRA::idx, Target target) const {
  auto attr = AttributeHandling::getValue(target, type, pack);
  return AttributeHandling::equal(attr, value);
}
}  // namespace BHVR