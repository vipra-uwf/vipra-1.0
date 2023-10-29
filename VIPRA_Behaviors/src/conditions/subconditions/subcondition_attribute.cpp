

#include <attributes/attributes.hpp>
#include <conditions/subconditions/subcondition_attribute.hpp>

namespace BHVR {
SubConditionAttribute::SubConditionAttribute(Attribute type, CAttributeValue val)
    : _type(type), _value(val) {}

auto SubConditionAttribute::operator()(Simpack pack, VIPRA::idx /*unused*/, Target target) const -> bool {
  auto attr = AttributeHandling::get_value(target, _type, pack);
  return AttributeHandling::equal(attr, _value);
}
}  // namespace BHVR