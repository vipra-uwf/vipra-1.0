
#include <spdlog/spdlog.h>

#include <conditions/subconditions/subcondition_elapsed_time.hpp>
#include <utility>
#include "definitions/sim_pack.hpp"
#include "util/bool_latch.hpp"
#include "values/numeric_value.hpp"

namespace BHVR {

/**
 * @brief Constructor, adds start event listener to provided event
 * 
 * @param time : 
 * @param event : 
 */
SubConditionElapsedTimeFromEvent::SubConditionElapsedTimeFromEvent(BHVR::NumericValue time, VIPRA::idx event)
    : _event(event), _requiredTime(std::move(time)) {}

inline constexpr auto in_time_step(VIPRA::time_s currTime, VIPRA::time_s checkTime, VIPRA::delta_t deltaT)
    -> bool {
  const VIPRA::delta_t left = checkTime - deltaT;
  const VIPRA::delta_t right = checkTime + deltaT;
  return (currTime > left && currTime < right);
}

/**
 * @brief Returns true if the required simulated time has elapsed from the event starting.
 * 
 * @param deltaT : 
 * @return true 
 * @return false
 */
auto SubConditionElapsedTimeFromEvent::operator()(Simpack pack, VIPRA::idx pedIdx, Target) -> bool {
  const auto& event = pack.get_context().events[_event];
  if (event.is_starting()) {
    _startTime = pack.get_context().elapsedTime;
  }

  float reqTime = _requiredTime.value(pedIdx);
  float checkTime = _startTime + reqTime;
  return in_time_step(pack.get_context().elapsedTime, checkTime, pack.dT);
}
}  // namespace BHVR