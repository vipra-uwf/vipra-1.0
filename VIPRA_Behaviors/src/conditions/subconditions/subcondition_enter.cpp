
#include <limits>
#include <output/output.hpp>

#include "conditions/subconditions/subcondition_enter.hpp"
#include "locations/location.hpp"

namespace BHVR {
SubConditionEnter::SubConditionEnter(VIPRA::idx locIdx) : location(locIdx) {}

bool SubConditionEnter::operator()(Simpack pack, VIPRA::idx self, Target) {
  if (entered.size() < pack.pedSet.getNumPedestrians())
    entered.resize(pack.pedSet.getNumPedestrians());

  if (entered.at(self)) {
    return false;
  }

  Location& loc = pack.context.locations.at(location);
  bool      enter = loc.inside(pack.state.coords.at(self)) &&
               !loc.inside(pack.pedSet.getPedCoords(self));

  if (enter) {
    entered.at(self) = true;
  }

  return enter;
}
}  // namespace BHVR