

#include <conditions/subconditions/subcondition_event_starting.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {
SubConditionEventStarting::SubConditionEventStarting(VIPRA::idx ev) : event(ev) {}

/**
 * @brief Returns true if the event is occurring
 * 
 * @return true
 * @return false
 */
bool SubConditionEventStarting::operator()(Simpack pack, VIPRA::idx, Target) const {
  return pack.context.events[event].isStarting();
}
}  // namespace BHVR