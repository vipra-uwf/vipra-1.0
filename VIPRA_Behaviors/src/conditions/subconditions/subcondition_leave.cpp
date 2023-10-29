
#include <limits>
#include <output/output.hpp>

#include "conditions/subconditions/subcondition_leave.hpp"
#include "locations/location.hpp"

namespace BHVR {
SubConditionLeave::SubConditionLeave(VIPRA::idx locIdx) : _location(locIdx) {}

auto SubConditionLeave::operator()(Simpack pack, VIPRA::idx self, Target /*unused*/) -> bool {
  if (_left.size() < pack.get_pedset().getNumPedestrians())
    _left.resize(pack.get_pedset().getNumPedestrians());

  if (_left[self]) {
    return false;
  }

  Location& loc = pack.get_context().locations[_location];
  bool      leave =
      !loc.is_inside(pack.get_state().coords[self]) && loc.is_inside(pack.get_pedset().getPedCoords(self));

  if (leave) {
    _left[self] = true;
  }

  return leave;
}
}  // namespace BHVR