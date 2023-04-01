
#include <conditions/subconditions/subcondition_elapsed_time.hpp>

namespace Behaviors {

/**
 * @brief Constructor, adds start event listener to provided event
 * 
 * @param time : 
 * @param event : 
 */
SubCondition_Elapsed_Time_From_Event::SubCondition_Elapsed_Time_From_Event(VIPRA::delta_t time, Event* event)
  : elapsedTime(0), requiredTime(time) {
  event->onStart([&](float) { started = true; });
}

/**
 * @brief Returns true if the required simulated time has elapsed from the event starting.
 * 
 * @param dT : 
 * @return true 
 * @return false 
 */
bool
SubCondition_Elapsed_Time_From_Event::operator()(const PedestrianSet&,
                                                 const ObstacleSet&,
                                                 const Goals&,
                                                 const BehaviorContext&,
                                                 VIPRA::idx,
                                                 VIPRA::delta_t dT) {
  if (started) {
    elapsedTime += dT;
    if (elapsedTime >= requiredTime) {
      started = false;
      elapsedTime = 0;
      return true;
    }
  }
  return false;
}
}  // namespace Behaviors