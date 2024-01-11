
#include "conditions/subconditions/subcondition_leave.hpp"

namespace BHVR {

void SubConditionLeave::operator()(Simpack pack, const VIPRA::idxVec& peds, std::vector<bool>& conditionMet,
                                   const std::vector<Target>& targets) {
  for (auto idx : peds) {
    if (_left.size() < pack.get_pedset().getNumPedestrians())
      _left.resize(pack.get_pedset().getNumPedestrians());

    if (_left[targets[idx].targetIdx]) {
      conditionMet[idx] = false;
    }

    Location& loc = pack.get_context().locations[_location];
    bool      leave = !loc.contains(pack.get_state().coords[targets[idx].targetIdx]) &&
                 loc.contains(pack.get_pedset().getPedCoords(targets[idx].targetIdx));

    if (leave) {
      _left[targets[idx].targetIdx] = true;
    }

    conditionMet[idx] = leave;
  }
}

}  // namespace BHVR
