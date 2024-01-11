
#include "conditions/subconditions/subcondition_exists.hpp"

namespace BHVR {
void SubConditionExists::operator()(Simpack pack, const VIPRA::idxVec& peds, std::vector<bool>& conditionMet,
                                    const std::vector<Target>& /*unused*/) const {
  for (auto selfidx : peds) {
    conditionMet[selfidx] = false;
    const auto& group = pack.get_groups().at(0);

    for (auto idx : pack.get_groups().at(0)) {
      if (_modifier.check(pack, selfidx, idx) &&
          _attributeCond.individual(pack, selfidx, {TargetType::PEDESTRIAN, idx})) {
        conditionMet[selfidx] = true;
        break;
      }
    }
  }
}
}  // namespace BHVR