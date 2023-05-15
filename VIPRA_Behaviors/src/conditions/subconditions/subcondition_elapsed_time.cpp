
#include <spdlog/spdlog.h>

#include <conditions/subconditions/subcondition_elapsed_time.hpp>

namespace BHVR {

/**
 * @brief Constructor, adds start event listener to provided event
 * 
 * @param time : 
 * @param event : 
 */
SubConditionElapsedTimeFromEvent::SubConditionElapsedTimeFromEvent(VIPRA::delta_t time, Event* ev)
    : requiredTime(time), hasReturned(false), event(ev) {}

/**
 * @brief Returns true if the required simulated time has elapsed from the event starting.
 * 
 * @param dT : 
 * @return true 
 * @return false
 */
bool SubConditionElapsedTimeFromEvent::operator()(const PedestrianSet&, const ObstacleSet&, const Goals&,
                                                  const BehaviorContext& context, VIPRA::idx, VIPRA::delta_t) {

  if (hasReturned) {
    return false;
  }

  bool ret = (event->timeSinceLastStart(context) >= requiredTime);
  if (ret) {
    hasReturned = true;
    ret = false;
  }

  return ret;
}
}  // namespace BHVR