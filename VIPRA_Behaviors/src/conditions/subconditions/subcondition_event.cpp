

#include <conditions/subconditions/subcondition_event.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {
SubConditionEventOccurred::SubConditionEventOccurred(VIPRA::idx event) : _event(event) {}

/**
 * @brief Returns true if the event has occurred
 * 
 * @return true 
 * @return false 
 */
auto SubConditionEventOccurred::operator()(Simpack pack, VIPRA::idx /*unused*/, Target /*unused*/) const
    -> bool {
  return pack.get_context().events[_event].has_occurred();
}
}  // namespace BHVR