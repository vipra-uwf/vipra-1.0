#include "conditions/subconditions/subcondition_spatial.hpp"

namespace BHVR {

void SubConditionSpatial::operator()(Simpack pack, const VIPRA::idxVec& peds, std::vector<bool>& conditionMet,
                                     const std::vector<Target>& targets) const {
  for (auto idx : peds) {
    const auto& coords = pack.get_pedset().getCoordinates();
    conditionMet[idx] = coords[idx].distanceTo(coords[targets[idx].targetIdx]) <= _within.value(idx);
  }
}
}  // namespace BHVR
