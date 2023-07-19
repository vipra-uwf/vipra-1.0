

#include <attributes/attributes.hpp>
#include <conditions/subconditions/subcondition_attribute.hpp>

// TODO (rolland) NEXT this
namespace BHVR {
SubConditionAttribute::SubConditionAttribute(Attribute type, CAttributeValue val)
    : type(type), value(val) {}

bool SubConditionAttribute::operator()(Simpack pack, VIPRA::idx pedIdx,
                                       Target target) const {
  return AttributeHandling::getValue(target, type, pack) == value;
}
}  // namespace BHVR