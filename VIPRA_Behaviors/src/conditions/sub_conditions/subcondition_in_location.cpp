#include "conditions/subconditions/subcondition_in_location.hpp"

namespace BHVR {

void SubConditionInLocation::operator()(Simpack pack, const VIPRA::idxVec& peds,
                                        std::vector<bool>&         conditionMet,
                                        const std::vector<Target>& targets) const {
  for (auto idx : peds) {
    const auto& coords = pack.get_pedset().getPedCoords(targets[idx].targetIdx);
    conditionMet[idx] = pack.get_context().locations[_location].contains(coords);
  }
}

}  // namespace BHVR