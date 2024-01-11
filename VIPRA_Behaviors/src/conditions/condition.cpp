
#include <algorithm>

#include "conditions/condition.hpp"
#include "util/timed_latch.hpp"

namespace BHVR {

void Condition::initialize(const Simpack& pack) {
  if (_conditions.size() > 1) {
    _temp.resize(pack.get_pedset().getNumPedestrians());
    std::fill(_temp.begin(), _temp.end(), false);
  }
}

/**
 * @brief Tests whether a condition is met, by running through each sub condition sequentially
 * 
 * @param pedSet : pedestrian set object
 * @param obsSet : obstacle set object
 * @param goals : goals object
 * @param context : behavior context
 * @param pedIndex : index of current pedestrian
 * @param dT : simulation timestep size
 * @return true 
 * @return false
 */
void Condition::evaluate(Simpack pack, const VIPRA::idxVec& peds, std::vector<bool>& met,
                         const std::vector<Target>& targets, std::optional<TimedLatchCollection>& latches) {}
}  // namespace BHVR