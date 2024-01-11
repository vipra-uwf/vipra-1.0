#ifndef VIPRA_START_EVENT_HPP
#define VIPRA_START_EVENT_HPP

#include "definitions/behavior_context.hpp"
#include "definitions/sim_pack.hpp"
#include "events/event.hpp"
#include "targets/target.hpp"

namespace BHVR {
class SubConditionStart {
  DEFAULT_CONSTRUCTIBLE(SubConditionStart)
  COPYABLE(SubConditionStart)
  MOVEABLE(SubConditionStart)

 public:
  void operator()(Simpack /*unused*/, const VIPRA::idxVec& /*unused*/, std::vector<bool>& conditionMet,
                  const std::vector<Target>& /*unused*/) const {
    std::fill(conditionMet.begin(), conditionMet.end(), true);
  }
};
}  // namespace BHVR

#endif