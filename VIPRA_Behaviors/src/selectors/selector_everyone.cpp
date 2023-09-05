#include <numeric>
#include <randomization/random.hpp>

#include "selectors/selector_everyone.hpp"

namespace BHVR {
/**
 * @brief Selects all pedestrians from a group
 * 
 * @param group : group to pull from
 * @return SelectorResult 
 */
SelectorResult SelectorEveryone::operator()(VIPRA::pRNG_Engine&, const VIPRA::idxVec&,
                                            const VIPRA::idxVec& group,
                                            const VIPRA::PedestrianSet&,
                                            const VIPRA::ObstacleSet&,
                                            const VIPRA::Goals&) {
  auto vec = VIPRA::idxVec(group.size());
  std::iota(vec.begin(), vec.end(), 0);
  return {false, vec};
}

}  // namespace BHVR
