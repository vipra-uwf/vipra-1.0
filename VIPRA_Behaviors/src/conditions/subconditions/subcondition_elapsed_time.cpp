
#include <spdlog/spdlog.h>

#include <conditions/subconditions/subcondition_elapsed_time.hpp>

namespace BHVR {

/**
 * @brief Constructor, adds start event listener to provided event
 * 
 * @param time : 
 * @param event : 
 */
SubConditionElapsedTimeFromEvent::SubConditionElapsedTimeFromEvent(VIPRA::delta_t time, VIPRA::idx ev)
    : requiredTime(time), event(ev) {}

/**
 * @brief Returns true if the required simulated time has elapsed from the event starting.
 * 
 * @param dT : 
 * @return true 
 * @return false
 */
bool SubConditionElapsedTimeFromEvent::operator()(const PedestrianSet&, const ObstacleSet&, const Goals&,
                                                  const BehaviorContext& context, VIPRA::idx, VIPRA::delta_t) const {
  const auto& ev = context.events[event];
  if (ev.hasOccurred()) {
    return ev.timeSinceLastStart(context) >= requiredTime;
  }

  return false;
}
}  // namespace BHVR