
#include "conditions/subconditions/subcondition_elapsed_time.hpp"

namespace {
inline constexpr auto in_time_step(VIPRA::time_s currTime, VIPRA::time_s checkTime, VIPRA::delta_t deltaT)
    -> bool {
  const VIPRA::delta_t left = checkTime - deltaT;
  const VIPRA::delta_t right = checkTime + deltaT;
  return (currTime > left && currTime < right);
}
}  // namespace

namespace BHVR {
void SubConditionElapsedTimeFromEvent::operator()(Simpack pack, const VIPRA::idxVec& peds,
                                                  std::vector<bool>& conditionMet,
                                                  const std::vector<Target>& /*unused*/) {
  for (auto idx : peds) {
    const auto& event = pack.get_context().events[_event];
    if (event.is_starting()) {
      _startTime = pack.get_context().elapsedTime;
    }

    float reqTime = _requiredTime.value(idx);
    float checkTime = _startTime + reqTime;
    conditionMet[idx] = in_time_step(pack.get_context().elapsedTime, checkTime, pack.dT);
  }
}
}  // namespace BHVR
