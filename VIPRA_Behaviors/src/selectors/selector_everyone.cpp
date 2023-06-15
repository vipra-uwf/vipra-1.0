#include <numeric>
#include <randomization/random.hpp>

#include "selectors/selector_everyone.hpp"

namespace BHVR {

SelectorResult SelectorEveryone::operator()(VIPRA::pRNG_Engine&, const VIPRA::idxVec&,
                                            const VIPRA::idxVec& group,
                                            const PedestrianSet&, const ObstacleSet&,
                                            const Goals&) {
  auto vec = VIPRA::idxVec(group.size());
  std::iota(vec.begin(), vec.end(), 0);
  return {false, vec};
}

}  // namespace BHVR
