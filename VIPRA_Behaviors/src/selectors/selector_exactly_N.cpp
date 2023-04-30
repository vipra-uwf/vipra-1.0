
#include <algorithm>
#include <cmath>
#include <random>

#include "selectors/selector_exactly_N.hpp"

namespace Behaviors {
SelectorResult
selector_exactly_N::operator()(Behaviors::seed seed,
                               const VIPRA::idxVec&,
                               const VIPRA::idxVec& group,
                               const PedestrianSet&,
                               const ObstacleSet&,
                               const Goals&) {
  srand(seed);
  auto groupPeds = group;

  bool starved = false;
  if (N > group.size()) {
    starved = true;
    N = group.size();
  }

  spdlog::debug("Selector Exaclty N: Selecting {} Pedestrians", N);

  std::random_shuffle(groupPeds.begin(), groupPeds.end());
  groupPeds.resize(N);

  return {starved, groupPeds};
}
}  // namespace Behaviors