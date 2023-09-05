
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
SubConditionElapsedTimeFromEvent::SubConditionElapsedTimeFromEvent(
    BHVR::NumericValue time, VIPRA::idx ev)
    : event(ev), requiredTime(std::move(time)), startTime(0) {}

inline constexpr bool inTimeStep(VIPRA::time_s currTime, VIPRA::time_s checkTime,
                                 VIPRA::delta_t dT) {
  const VIPRA::delta_t left = checkTime - dT;
  const VIPRA::delta_t right = checkTime + dT;
  return (currTime > left && currTime < right);
}

/**
 * @brief Returns true if the required simulated time has elapsed from the event starting.
 * 
 * @param dT : 
 * @return true 
 * @return false
 */
bool SubConditionElapsedTimeFromEvent::operator()(Simpack pack, VIPRA::idx pedIdx,
                                                  Target) {
  const auto& ev = pack.context.events[event];
  if (ev.isStarting()) {
    startTime = pack.context.elapsedTime;
  }

  float reqTime = requiredTime.value(pedIdx);
  float checkTime = startTime + reqTime;
  return inTimeStep(pack.context.elapsedTime, checkTime, pack.dT);
}
}  // namespace BHVR