#ifndef VIPRA_BEHAVIORS_ATOM_SET_HPP
#define VIPRA_BEHAVIORS_ATOM_SET_HPP

#include "targets/attributes.hpp"
#include "targets/target.hpp"

namespace BHVR {
struct AtomSet {
  Attribute       attribute;
  cAttributeValue value;
  bool            targetSelf;

  inline void operator()(Simpack pack, Target self, Target target, VIPRA::State& state) const {
    if (targetSelf) {
      AttributeHandling::setValue(self, attribute, pack, state, value);
      return;
    }

    // if (target.targetIdx == 64) {
    //   spdlog::warn("Ped {} in fight with Ped {}", self.targetIdx, target.targetIdx);
    // }
    AttributeHandling::setValue(target, attribute, pack, state, value);
  }
};
}  // namespace BHVR

#endif