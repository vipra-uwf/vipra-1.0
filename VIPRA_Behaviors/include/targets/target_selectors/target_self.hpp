#ifndef VIPRA_BEHAVIORS_SELF_SELECTOR_HPP
#define VIPRA_BEHAVIORS_SELF_SELECTOR_HPP

#include <definitions/sim_pack.hpp>
#include <targets/target.hpp>

namespace BHVR {

/**
 * @brief Returns the target that calls this
 * 
 */
struct TargetSelf {
  inline auto operator()(Simpack /*unused*/, Self self) -> Target { return self.target; }
};
}  // namespace BHVR

#endif