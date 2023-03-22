

#include <conditions/subconditions/subcondition_event_occurring.hpp>

namespace Behaviors {
/**
   * @brief Constructor, adds start and end listeners to the provided event
   * 
   * @param event : 
   */
SubCondition_Event_Occurring::SubCondition_Event_Occurring(Event* event) : occurring(false) {
  event->onStart([this]() { this->occurring = true; });
  event->onEnd([this]() { this->occurring = false; });
}

/**
 * @brief Returns true if the event is occurring
 * 
 * @return true 
 * @return false 
 */
bool
SubCondition_Event_Occurring::operator()(const PedestrianSet&,
                                         const ObstacleSet&,
                                         const Goals&,
                                         const BehaviorContext&,
                                         VIPRA::idx,
                                         VIPRA::delta_t) {
  return occurring;
}
}  // namespace Behaviors