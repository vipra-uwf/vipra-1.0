#include <numeric>

#include "selectors/selector_everyone.hpp"

namespace BHVR {

SelectorResult SelectorEveryone::operator()(BHVR::seed /*seed*/, const VIPRA::idxVec& /*peds*/, const VIPRA::idxVec& group,
                                            const PedestrianSet& /*pedset*/, const ObstacleSet& /*obsset*/,
                                            const Goals& /*goals*/) {
  auto vec = VIPRA::idxVec(group.size());
  std::iota(vec.begin(), vec.end(), 0);
  return {false, vec};
}

}  // namespace BHVR
