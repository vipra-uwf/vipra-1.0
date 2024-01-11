
#include "conditions/subconditions/subcondition_event_starting.hpp"

namespace BHVR {
void SubConditionEventStarting::operator()(Simpack            pack, const VIPRA::idxVec& /*unused*/,
                                           std::vector<bool>& conditionMet,
                                           const std::vector<Target>& /*unused*/) const {
  std::fill(conditionMet.begin(), conditionMet.end(), pack.get_context().events[_event].is_starting());
}

}  // namespace BHVR