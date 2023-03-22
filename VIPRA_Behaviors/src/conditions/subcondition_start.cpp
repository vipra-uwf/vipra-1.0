
#include <conditions/subconditions/subcondition_start.hpp>

namespace Behaviors {
/**
   * @brief Always returns true
   * 
   * @return true 
   * @return false 
   */
bool
SubCondition_Start::operator()(const PedestrianSet&,
                               const ObstacleSet&,
                               const Goals&,
                               const BehaviorContext&,
                               VIPRA::idx,
                               VIPRA::delta_t) {
  return true;
}
}  // namespace Behaviors