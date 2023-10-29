#ifndef VIPRA_BEHAVIORS_ATOM_SCALE_HPP
#define VIPRA_BEHAVIORS_ATOM_SCALE_HPP

#include <attributes/attributes.hpp>
#include <targets/target.hpp>

namespace BHVR {
struct AtomScale {
  Attribute       attribute;
  CAttributeValue value;
  bool            targetSelf;

  inline void operator()(Simpack pack, Self self, Target target) const {
    if (targetSelf) {
      AttributeHandling::scale_value(self.target, attribute, pack, pack.state, value);
      return;
    }

    AttributeHandling::scale_value(target, attribute, pack, pack.state, value);
  }
};
}  // namespace BHVR

#endif