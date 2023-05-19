
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
                                           const PedestrianSet&, const ObstacleSet&, const Goals&) const {
  srand(seed);

  auto groupPeds = group;

  auto count = static_cast<VIPRA::size>(std::floor(fullGroup.size() * percentage));

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