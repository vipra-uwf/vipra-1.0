
#include <algorithm>
#include <cmath>
#include <random>

#include <selectors/selector_percent.hpp>

namespace BHVR {
/**
 * @brief Selects (numpeds * ratio) pedestrians for the simulation
 * 
 * @param pedSet : 
 */
SelectorResult SelectorPercent::operator()(BHVR::seed seed, const VIPRA::idxVec& fullGroup, const VIPRA::idxVec& group,
                                           const PedestrianSet& /*pedset*/, const ObstacleSet& /*obsSet*/,
                                           const Goals& /*goals*/) const {
  srand(seed);

  auto groupPeds = group;

  auto count = static_cast<VIPRA::size>(std::floor(percentage * static_cast<float>(fullGroup.size())));

  bool starved = false;
  if (count > group.size()) {
    starved = true;
    count = group.size();
  }

  spdlog::debug("Selector Percent: Selecting {} Pedestrians", count);

  std::shuffle(groupPeds.begin(), groupPeds.end(), std::default_random_engine(seed));
  groupPeds.resize(count);

  return {starved, groupPeds};
}
}  // namespace BHVR