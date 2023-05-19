

#include <conditions/subconditions/subcondition_event.hpp>

namespace BHVR {
/**
   * @brief Constructor, adds start handler to the provided event
   * 
   * @param event : 
   */
SubConditionEventOccurred::SubConditionEventOccurred(VIPRA::idx ev) : event(ev) {}

/**
 * @brief Returns true if the event has occurred
 * 
 * @return true 
 * @return false 
 */
bool SubConditionEventOccurred::operator()(const PedestrianSet&, const ObstacleSet&, const Goals&,
                                           const BehaviorContext& context, VIPRA::idx, VIPRA::delta_t) const {
  return context.events[event].hasOccurred();
}
}  // namespace BHVR