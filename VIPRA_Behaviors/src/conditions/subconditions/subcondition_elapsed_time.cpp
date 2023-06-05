
#include <spdlog/spdlog.h>

#include <conditions/subconditions/subcondition_elapsed_time.hpp>

namespace BHVR {

/**
 * @brief Constructor, adds start event listener to provided event
 * 
 * @param time : 
 * @param event : 
 */
SubConditionElapsedTimeFromEvent::SubConditionElapsedTimeFromEvent(VIPRA::time_s time, VIPRA::idx ev)
    : latch(time), event(ev) {}

/**
 * @brief Returns true if the required simulated time has elapsed from the event starting.
 * 
 * @param dT : 
 * @return true 
 * @return false
 */
bool SubConditionElapsedTimeFromEvent::operator()(const PedestrianSet&, const ObstacleSet&, const Goals&,
                                                  const BehaviorContext& context, VIPRA::idx, VIPRA::delta_t) {
  const VIPRA::time_s currTime = context.elapsedTime;
  if (latch.check(currTime)) {
    return true;
  }

  const auto& ev = context.events[event];
  if (ev.isStarting()) {
    latch.latch(currTime);
    return true;
  }

  return false;
}
}  // namespace BHVR