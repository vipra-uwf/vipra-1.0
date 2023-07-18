#ifndef VIPRA_BEHAVIORS_SELF_SELECTOR_HPP
#define VIPRA_BEHAVIORS_SELF_SELECTOR_HPP

#include <definitions/sim_pack.hpp>
#include <targets/target.hpp>

namespace BHVR {
struct TargetSelf {
  inline Target operator()(Simpack, Target self) { return self; }
};
}  // namespace BHVR

#endif