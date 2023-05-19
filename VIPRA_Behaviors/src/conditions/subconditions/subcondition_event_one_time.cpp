

#include <conditions/subconditions/subcondition_event_one_time.hpp>

namespace BHVR {
/**
   * @brief Constructor, adds start and end listeners to the provided event
   * 
   * @param event : 
   */
SubConditionEventOneTime::SubConditionEventOneTime(bool onstart, VIPRA::idx ev)
    : onStart(onstart), hasReturned(false), event(ev) {}

/**
 * @brief Returns true once when the event has either started or ended
 * 
 * @return true 
 * @return false 
 */
bool SubConditionEventOneTime::operator()(const PedestrianSet&, const ObstacleSet&, const Goals&,
                                          const BehaviorContext& context, VIPRA::idx, VIPRA::delta_t) {
  if (onStart) {
    if (context.events[event].hasStarted() && !hasReturned) {
      hasReturned = true;
      return true;
    }
  } else {
    if (context.events[event].hasEnded() && !hasReturned) {
      hasReturned = true;
      return true;
    }
  }

  return false;
}
}  // namespace BHVR