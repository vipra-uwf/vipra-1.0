

#include <conditions/subconditions/subcondition_event.hpp>

namespace Behaviors {
/**
   * @brief Constructor, adds start handler to the provided event
   * 
   * @param event : 
   */
SubCondition_Event_Occurred::SubCondition_Event_Occurred(Event* event) : occurred(false) {
  event->onStart([&]() { occurred = true; });
}

/**
 * @brief Returns true if the event has started
 * 
 * @return true 
 * @return false 
 */
bool
SubCondition_Event_Occurred::operator()(const PedestrianSet&,
                                        const ObstacleSet&,
                                        const Goals&,
                                        const BehaviorContext&,
                                        VIPRA::idx,
                                        VIPRA::delta_t) {
  return occurred;
}
}  // namespace Behaviors