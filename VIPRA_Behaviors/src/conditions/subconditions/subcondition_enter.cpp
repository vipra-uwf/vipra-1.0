
#include <limits>

#include "conditions/subconditions/subcondition_enter.hpp"
#include "locations/location.hpp"

namespace BHVR {
SubConditionEnter::SubConditionEnter(VIPRA::idx locIdx) : _location(locIdx) {}

auto SubConditionEnter::operator()(Simpack pack, VIPRA::idx self, Target /*unused*/) -> bool {
  if (_entered.size() < pack.get_pedset().getNumPedestrians())
    _entered.resize(pack.get_pedset().getNumPedestrians());

  if (_entered[self]) {
    return false;
  }

  Location& loc = pack.get_context().locations[_location];
  bool      enter =
      loc.is_inside(pack.get_state().coords[self]) && !loc.is_inside(pack.get_pedset().getPedCoords(self));

  if (enter) {
    _entered[self] = true;
  }

  return enter;
}
}  // namespace BHVR