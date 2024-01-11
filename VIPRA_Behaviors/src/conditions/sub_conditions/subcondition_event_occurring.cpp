
#include "conditions/subconditions/subcondition_event_occurring.hpp"

namespace BHVR {

void SubConditionEventOccurring::operator()(Simpack            pack, const VIPRA::idxVec& /*unused*/,
                                            std::vector<bool>& conditionMet,
                                            const std::vector<Target>& /*unused*/) const {
  std::fill(conditionMet.begin(), conditionMet.end(), pack.get_context().events[_event].is_occurring());
}
}  // namespace BHVR