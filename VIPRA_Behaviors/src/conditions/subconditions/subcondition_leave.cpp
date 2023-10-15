
#include <limits>
#include <output/output.hpp>

#include "conditions/subconditions/subcondition_leave.hpp"
#include "locations/location.hpp"

namespace BHVR {
SubConditionLeave::SubConditionLeave(VIPRA::idx locIdx) : location(locIdx) {}

bool SubConditionLeave::operator()(Simpack pack, VIPRA::idx self, Target) {
  if (left.size() < pack.pedSet.getNumPedestrians())
    left.resize(pack.pedSet.getNumPedestrians());

  if (left.at(self)) {
    return false;
  }

  Location& loc = pack.context.locations.at(location);
  bool      leave = !loc.inside(pack.state.coords.at(self)) &&
               loc.inside(pack.pedSet.getPedCoords(self));

  if (leave) {
    left.at(self) = true;
  }

  return leave;
}
}  // namespace BHVR