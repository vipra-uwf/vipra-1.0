#include <numeric>

#include "selectors/selector_everyone.hpp"

namespace Behaviors {
void
Selector_Everyone::initialize(const PedestrianSet& pedSet, const ObstacleSet&, const Goals&) {
  selectedPeds = std::vector<VIPRA::idx>(pedSet.getNumPedestrians());
  std::iota(selectedPeds.begin(), selectedPeds.end(), 0);
}

const std::vector<VIPRA::idx>&
Selector_Everyone::getSelectedPeds(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&) {
  return selectedPeds;
}
}  // namespace Behaviors
