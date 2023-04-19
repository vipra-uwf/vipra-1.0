
#include <algorithm>
#include <cmath>
#include <random>

#include "selectors/selector_exactly_N.hpp"

namespace Behaviors {
std::vector<VIPRA::idx>
selector_exactly_N::operator()(Behaviors::seed                seed,
                               const std::vector<VIPRA::idx>& group,
                               const PedestrianSet&,
                               const ObstacleSet&,
                               const Goals&) {
  //TODO add group
  srand(seed);
  auto groupPeds = group;

  spdlog::debug("Selector Exaclty N: Selecting {} Pedestrians", N);

  std::random_shuffle(groupPeds.begin(), groupPeds.end());
  groupPeds.resize(N);

  return groupPeds;
}
}  // namespace Behaviors