#include <numeric>

#include "selectors/selector_everyone.hpp"

namespace Behaviors {

SelectorResult
selector_everyone::operator()(Behaviors::seed,
                              const VIPRA::idxVec&,
                              const VIPRA::idxVec& group,
                              const PedestrianSet&,
                              const ObstacleSet&,
                              const Goals&) {
  auto vec = VIPRA::idxVec(group.size());
  std::iota(vec.begin(), vec.end(), 0);
  return {false, vec};
}

}  // namespace Behaviors
