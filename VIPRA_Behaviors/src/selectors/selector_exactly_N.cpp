
#include <algorithm>
#include <cmath>
#include <random>

#include "selectors/selector_exactly_N.hpp"

namespace BHVR {
SelectorResult SelectorExactlyN::operator()(BHVR::seed seed, const VIPRA::idxVec& /*peds*/, const VIPRA::idxVec& group,
                                            const PedestrianSet& /*pedset*/, const ObstacleSet& /*obsset*/,
                                            const Goals& /*goals*/) {
  srand(seed);
  auto groupPeds = group;

  bool starved = false;
  if (selectCount > group.size()) {
    starved = true;
    selectCount = group.size();
  }

  spdlog::debug("Selector Exaclty N: Selecting {} Pedestrians", selectCount);

  std::shuffle(groupPeds.begin(), groupPeds.end(), std::default_random_engine(seed));
  groupPeds.resize(selectCount);

  return {starved, groupPeds};
}
}  // namespace BHVR