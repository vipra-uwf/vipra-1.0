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
  DEFAULT_CONSTRUCTIBLE(TargetSelector)
  COPYABLE(TargetSelector)
  MOVEABLE(TargetSelector)

 public:
  explicit TargetSelector(TargetFunc&& func) : _select(func) {}
  auto get_target(Simpack pack, Self self) -> Target { return _select(pack, self); }

 private:
  TargetFunc _select{TargetSelf{}};
};
}  // namespace BHVR

#endif