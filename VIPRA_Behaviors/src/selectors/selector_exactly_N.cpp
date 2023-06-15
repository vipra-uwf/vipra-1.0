
#include <algorithm>
#include <cmath>
#include <definitions/type_definitions.hpp>
#include <random>
#include <randomization/random.hpp>

#include "selectors/selector_exactly_N.hpp"

namespace BHVR {
SelectorResult SelectorExactlyN::operator()(VIPRA::pRNG_Engine& rngEngine,
                                            const VIPRA::idxVec&,
                                            const VIPRA::idxVec& group,
                                            const PedestrianSet&, const ObstacleSet&,
                                            const Goals&) const {
  auto groupPeds = group;

  auto pedCnt = static_cast<VIPRA::size>(std::round(selectCount.value(0)));

  bool starved = false;
  if (pedCnt > group.size()) {
    starved = true;
    pedCnt = group.size();
  }

  spdlog::debug("Selector Exaclty N: Selecting {} Pedestrians", pedCnt);

  std::shuffle(groupPeds.begin(), groupPeds.end(), rngEngine);
  groupPeds.resize(pedCnt);

  return {starved, groupPeds};
}
}  // namespace BHVR