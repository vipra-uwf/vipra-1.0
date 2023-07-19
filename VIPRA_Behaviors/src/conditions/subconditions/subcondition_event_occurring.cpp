

#include <conditions/subconditions/subcondition_event_occurring.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {
/**
   * @brief Constructor, adds start and end listeners to the provided event
   * 
   * @param event : 
   */
SubConditionEventOccurring::SubConditionEventOccurring(VIPRA::idx ev) : event(ev) {}

/**
 * @brief Returns true if the event is occurring
 * 
 * @return true
 * @return false
 */
bool SubConditionEventOccurring::operator()(Simpack pack, VIPRA::idx, Target) const {
  return pack.context.events[event].isOccurring();
}
}  // namespace BHVR