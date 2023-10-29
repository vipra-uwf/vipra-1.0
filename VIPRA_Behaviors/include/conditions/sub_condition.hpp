#ifndef VIPRA_SUB_CONDITION_HPP
#define VIPRA_SUB_CONDITION_HPP

#include <functional>

#include "definitions/behavior_context.hpp"
#include "definitions/sim_pack.hpp"
#include "goals/goals.hpp"
#include "targets/target.hpp"

namespace BHVR {
using SubCondition = std::function<bool(Simpack, VIPRA::idx, Target)>;
}  // namespace BHVR

#endif