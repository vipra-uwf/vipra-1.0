#ifndef VIPRA_BEHAVIORS_ATOM_SET_HPP
#define VIPRA_BEHAVIORS_ATOM_SET_HPP

#include <attributes/attributes.hpp>
#include "targets/target.hpp"

namespace BHVR {
struct AtomSet {
  Attribute       attribute;
  CAttributeValue value;
  bool            targetSelf;

  inline void operator()(Simpack pack, Self self, Target target) const {
    if (targetSelf) {
      AttributeHandling::set_value(self.target, attribute, pack, pack.state, value);
      return;
    }

    AttributeHandling::set_value(target, attribute, pack, pack.state, value);
  }
};
}  // namespace BHVR

#endif