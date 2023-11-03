
#include "conditions/subconditions/subcondition_in_location.hpp"

namespace BHVR {
SubConditionInLocation::SubConditionInLocation(VIPRA::idx location) : _location(location) {}

/**
 * @brief Returns true if the target is in the location
 * 
 */
auto SubConditionInLocation::operator()(Simpack pack, VIPRA::idx /*unused*/, Target target) const -> bool {
  return pack.get_context().locations[_location].contains(pack.get_pedset().getPedCoords(target.targetIdx));
}

}  // namespace BHVR