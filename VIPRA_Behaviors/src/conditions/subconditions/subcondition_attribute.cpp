

#include <attributes/attributes.hpp>
#include <conditions/subconditions/subcondition_attribute.hpp>

namespace BHVR {
SubConditionAttribute::SubConditionAttribute(Attribute type, CAttributeValue val, bool negative)
    : _type(type), _value(val), _not(negative) {}

/**
 * @brief Returns true if the targets attribute equals the value, or does not equal the value if the subcondition is negative.
 * 
 */
auto SubConditionAttribute::operator()(Simpack pack, VIPRA::idx /*unused*/, Target target) const -> bool {
  auto attr = AttributeHandling::get_value(target, _type, pack);

  if (_not) {
    return AttributeHandling::is_not_equal(attr, _value, pack);
  }

  return AttributeHandling::is_equal(attr, _value, pack);
}
}  // namespace BHVR