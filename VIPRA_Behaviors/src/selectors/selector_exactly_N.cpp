
#include <algorithm>

#include "selectors/selector_exactly_N.hpp"

Selector_Exactly_N::Selector_Exactly_N(VIPRA::size N, VIPRA::seed seed) : Selector(), count(N) {
  srand(seed);
}

void
Selector_Exactly_N::selectPedestrianIds(const PedestrianSet& pedestrianSet) {
  VIPRA::size numPedestrians = pedestrianSet.getNumPedestrians();

  while (selectedPeds.size() < count) {
    VIPRA::idx pedestrianId = static_cast<VIPRA::idx>(static_cast<VIPRA::size>(rand()) % numPedestrians);
    if (std::find(selectedPeds.begin(), selectedPeds.end(), pedestrianId) == selectedPeds.end()) {
      spdlog::debug("Selecting Pedestrian ID: {} For Behavior", pedestrianId);
      selectedPeds.push_back(pedestrianId);
    }
  }
}

void
Selector_Exactly_N::initialize(const PedestrianSet& pedSet, const ObstacleSet&, const Goals&) {
  selectPedestrianIds(pedSet);
}

const std::vector<VIPRA::idx>&
Selector_Exactly_N::getSelectedPeds(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&) {
  return selectedPeds;
}