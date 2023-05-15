
#include <conditions/subconditions/subcondition_start.hpp>

namespace BHVR {
/**
   * @brief Always returns true
   * 
   * @return true 
   * @return false 
   */
bool SubConditionStart::operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&,
                                   VIPRA::idx, VIPRA::delta_t) const {
  return true;
}
}  // namespace BHVR