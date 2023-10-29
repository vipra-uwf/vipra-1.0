

#include <conditions/subconditions/subcondition_event_ending.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {

SubConditionEventEnding::SubConditionEventEnding(VIPRA::idx event) : _event(event) {}

/**
 * @brief Returns true if the event is occurring
 * 
 * @return true
 * @return false
 */
auto SubConditionEventEnding::operator()(Simpack pack, VIPRA::idx /*unused*/, Target /*unused*/) const
    -> bool {
  return pack.get_context().events[_event].is_ending();
}
}  // namespace BHVR