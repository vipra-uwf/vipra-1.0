
#include <algorithm>
#include <cmath>
#include <random>

#include "selectors/selector_exactly_N.hpp"

namespace Behaviors {
std::vector<VIPRA::idx>
selector_exactly_N::operator()(Behaviors::seed seed, const PedestrianSet& pedSet, const ObstacleSet&, const Goals&) {
  srand(seed);
  VIPRA::size numPeds = pedSet.getNumPedestrians();

  auto selectedPeds = std::vector<VIPRA::idx>(numPeds);
  std::iota(selectedPeds.begin(), selectedPeds.end(), 0);
  std::random_shuffle(selectedPeds.begin(), selectedPeds.end());
  selectedPeds.resize(N);

  return selectedPeds;
}
}  // namespace Behaviors