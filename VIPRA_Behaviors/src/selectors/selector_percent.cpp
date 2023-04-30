
#include <algorithm>
#include <cmath>
#include <random>

#include <selectors/selector_percent.hpp>

namespace Behaviors {

/**
 * @brief Selects (numpeds * ratio) pedestrians for the simulation
 * 
 * @param pedSet : 
 */
SelectorResult
selector_percent::operator()(Behaviors::seed      seed,
                             const VIPRA::idxVec& fullGroup,
                             const VIPRA::idxVec& group,
                             const PedestrianSet&,
                             const ObstacleSet&,
                             const Goals&) {
  srand(seed);

  auto groupPeds = group;

  VIPRA::size count = static_cast<VIPRA::size>(std::floor(fullGroup.size() * percentage));

  bool starved = false;
  if (count > group.size()) {
    starved = true;
    count = group.size();
  }

  spdlog::debug("Selector Percent: Selecting {} Pedestrians", count);

  std::random_shuffle(groupPeds.begin(), groupPeds.end());
  groupPeds.resize(count);

  return {starved, groupPeds};
}
}  // namespace Behaviors