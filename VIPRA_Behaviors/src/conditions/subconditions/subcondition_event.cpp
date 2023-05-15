

#include <conditions/subconditions/subcondition_event.hpp>

namespace BHVR {
/**
   * @brief Constructor, adds start handler to the provided event
   * 
   * @param event : 
   */
SubConditionEventOccurred::SubConditionEventOccurred(Event* ev) : event(ev) {}

/**
 * @brief Returns true if the event has occurred
 * 
 * @return true 
 * @return false 
 */
bool SubConditionEventOccurred::operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&,
                                           VIPRA::idx, VIPRA::delta_t) const {
  return event->hasOccurred();
}
}  // namespace BHVR