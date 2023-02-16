
#include <cmath>

#include "selectors/selector_percent.hpp"

namespace Behaviors {
Selector_Percent::Selector_Percent(float selectRatio) : Selector(), ratio(selectRatio) {}

void
Selector_Percent::selectPedestrianIds(const PedestrianSet& pedestrianSet) {
  VIPRA::size numPedestrians = pedestrianSet.getNumPedestrians();
  VIPRA::size count = static_cast<VIPRA::size>(std::floor(numPedestrians * ratio));

  while (selectedPeds.size() < count) {
    VIPRA::idx pedestrianId = static_cast<VIPRA::idx>(static_cast<VIPRA::size>(rand()) % numPedestrians);
    if (std::find(selectedPeds.begin(), selectedPeds.end(), pedestrianId) == selectedPeds.end()) {
      spdlog::debug("Selecting pedestrian id: {} for behavior.", pedestrianId);
      selectedPeds.push_back(pedestrianId);
    }
  }
}

void
Selector_Percent::initialize(const PedestrianSet& pedSet, const ObstacleSet&, const Goals&) {
  selectPedestrianIds(pedSet);
}

const std::vector<VIPRA::idx>&
Selector_Percent::getSelectedPeds(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&) {
  return selectedPeds;
}
}  // namespace Behaviors