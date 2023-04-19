
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
std::vector<VIPRA::idx>
selector_percent::operator()(Behaviors::seed                seed,
                             const std::vector<VIPRA::idx>& group,
                             const PedestrianSet&,
                             const ObstacleSet&,
                             const Goals&) {
  //TODO add group
  srand(seed);

  auto groupPeds = group;

  VIPRA::size numPeds = groupPeds.size();
  VIPRA::size count = static_cast<VIPRA::size>(std::floor(numPeds * percentage));
  spdlog::debug("Selector Percent: Selecting {} Pedestrians", count);

  std::random_shuffle(groupPeds.begin(), groupPeds.end());
  groupPeds.resize(count);

  return groupPeds;
}

}  // namespace Behaviors