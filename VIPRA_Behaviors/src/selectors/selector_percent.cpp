
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
selector_percent::operator()(Behaviors::seed seed, const PedestrianSet& pedSet, const ObstacleSet&, const Goals&) {
  srand(seed);
  VIPRA::size numPeds = pedSet.getNumPedestrians();
  VIPRA::size count = static_cast<VIPRA::size>(std::floor(numPeds * percentage));
  spdlog::debug("Selector Percent: Selecting {} Pedestrians", count);

  auto selectedPeds = std::vector<VIPRA::idx>(numPeds);
  std::iota(selectedPeds.begin(), selectedPeds.end(), 0);
  std::random_shuffle(selectedPeds.begin(), selectedPeds.end());
  selectedPeds.resize(count);

  return selectedPeds;
}

}  // namespace Behaviors