#ifndef VIPRA_BEHAVIORS_TARGET_SELECTOR_HPP
#define VIPRA_BEHAVIORS_TARGET_SELECTOR_HPP

#include "definitions/sim_pack.hpp"
#include "target.hpp"
#include "targets/target_selectors/target_self.hpp"

namespace BHVR {

/**
 * @brief Used to grab a target for either conditions or actions
 * 
 */
class TargetSelector {
 public:
  TargetSelector() : select(TargetSelf()) {}
  explicit TargetSelector(TargetFunc&& func) : select(func) {}
  Target getTarget(Simpack pack, Target self) { return select(pack, self); }

 private:
  TargetFunc select;
};
}  // namespace BHVR

#endif