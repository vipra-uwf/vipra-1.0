
#include "conditions/subconditions/subcondition_event.hpp"

namespace BHVR {

void SubConditionEventOccurred::operator()(Simpack            pack, const VIPRA::idxVec& /*unused*/,
                                           std::vector<bool>& conditionMet,
                                           const std::vector<Target>& /*unused*/) const {
  std::fill(conditionMet.begin(), conditionMet.end(), pack.get_context().events[_event].has_occurred());
}
}  // namespace BHVR