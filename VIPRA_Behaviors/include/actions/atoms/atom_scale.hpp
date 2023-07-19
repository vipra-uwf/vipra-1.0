#ifndef VIPRA_BEHAVIORS_ATOM_SCALE_HPP
#define VIPRA_BEHAVIORS_ATOM_SCALE_HPP

#include <attributes/attributes.hpp>
#include <targets/target.hpp>

namespace BHVR {
struct AtomScale {
  Attribute       attribute;
  CAttributeValue value;
  bool            targetSelf;

  inline void operator()(Simpack pack, Target self, Target target,
                         VIPRA::State& state) const {
    if (targetSelf) {
      AttributeHandling::scaleValue(self, attribute, pack, state, value);
      return;
    }

    AttributeHandling::scaleValue(target, attribute, pack, state, value);
  }
};
}  // namespace BHVR

#endif