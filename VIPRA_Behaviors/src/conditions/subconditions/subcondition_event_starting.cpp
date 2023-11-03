

#include <conditions/subconditions/subcondition_event_starting.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {
SubConditionEventStarting::SubConditionEventStarting(VIPRA::idx event) : _event(event) {}

/**
 * @brief Returns true if the event is starting
 * 
 * @return true
 * @return false
 */
auto SubConditionEventStarting::operator()(Simpack pack, VIPRA::idx /*unused*/, Target /*unused*/) const
    -> bool {
  return pack.get_context().events[_event].is_starting();
}
}  // namespace BHVR