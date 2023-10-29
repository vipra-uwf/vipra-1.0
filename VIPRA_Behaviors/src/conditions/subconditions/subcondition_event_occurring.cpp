

#include <conditions/subconditions/subcondition_event_occurring.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {

SubConditionEventOccurring::SubConditionEventOccurring(VIPRA::idx event) : _event(event) {}

/**
 * @brief Returns true if the event is occurring
 * 
 * @return true
 * @return false
 */
auto SubConditionEventOccurring::operator()(Simpack pack, VIPRA::idx /*unused*/, Target /*unused*/) const
    -> bool {
  return pack.get_context().events[_event].is_occurring();
}
}  // namespace BHVR