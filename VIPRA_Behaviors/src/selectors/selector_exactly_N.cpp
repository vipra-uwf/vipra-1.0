
#include <algorithm>
#include <cmath>
#include <definitions/type_definitions.hpp>
#include <random>

#include "selectors/selector_exactly_N.hpp"

namespace BHVR {
SelectorResult SelectorExactlyN::operator()(BHVR::seed seed,
                                            const VIPRA::idxVec& /*peds*/,
                                            const VIPRA::idxVec& group,
                                            const PedestrianSet& /*pedset*/,
                                            const ObstacleSet& /*obsset*/,
                                            const Goals& /*goals*/) const {
  srand(seed);
  auto groupPeds = group;

  auto pedCnt = static_cast<VIPRA::size>(std::round(selectCount()));

  bool starved = false;
  if (pedCnt > group.size()) {
    starved = true;
    pedCnt = group.size();
  }

  spdlog::debug("Selector Exaclty N: Selecting {} Pedestrians", pedCnt);

  std::shuffle(groupPeds.begin(), groupPeds.end(), std::default_random_engine(seed));
  groupPeds.resize(pedCnt);

  return {starved, groupPeds};
}
}  // namespace BHVR