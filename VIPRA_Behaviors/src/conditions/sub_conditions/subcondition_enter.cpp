
#include "conditions/subconditions/subcondition_enter.hpp"

namespace BHVR {

void SubConditionEnter::operator()(Simpack pack, const VIPRA::idxVec& peds, std::vector<bool>& met,
                                   const std::vector<Target>& targets) {
  if (_entered.size() < pack.get_pedset().getNumPedestrians())
    _entered.resize(pack.get_pedset().getNumPedestrians());

  for (auto idx : peds) {
    if (_entered[targets[idx].targetIdx]) {
      met[idx] = false;
    }

    Location& loc = pack.get_context().locations[_location];
    bool      enter = loc.contains(pack.get_state().coords[targets[idx].targetIdx]) &&
                 !loc.contains(pack.get_pedset().getPedCoords(targets[idx].targetIdx));

    if (enter) {
      _entered[targets[idx].targetIdx] = true;
    }

    met[idx] = enter;
  }
}

}  // namespace BHVR
