
#include <algorithm>

#include "selectors/selector_exactly_N.hpp"

Selector_Exactly_N::Selector_Exactly_N(VIPRA::size N, VIPRA::seed seed) : Selector(), count(N) {
  srand(seed);
}

void
Selector_Exactly_N::selectPedestrianIds(const PedestrianSet& pedestrianSet) {
  VIPRA::size numPedestrians = pedestrianSet.getNumPedestrians();

  while (selectedPedestrianIds.size() < count) {
    VIPRA::idx pedestrianId = static_cast<VIPRA::idx>(static_cast<VIPRA::size>(rand()) % numPedestrians);
    if (std::find(selectedPedestrianIds.begin(), selectedPedestrianIds.end(), pedestrianId) == selectedPedestrianIds.end()) {
      spdlog::debug("Selecting pedestrian id: {} for behavior.", pedestrianId);
      selectedPedestrianIds.push_back(pedestrianId);
    }
  }
}

void
Selector_Exactly_N::initialize([[maybe_unused]] const ObstacleSet& obsSet,
                               const PedestrianSet&                pedSet,
                               [[maybe_unused]] const Goals&       goals) {
  selectPedestrianIds(pedSet);
}

bool
Selector_Exactly_N::select([[maybe_unused]] const ObstacleSet&     obstacleSet,
                           [[maybe_unused]] const PedestrianSet&   pedestrianSet,
                           [[maybe_unused]] const Goals&           goals,
                           [[maybe_unused]] const BehaviorContext& context,
                           VIPRA::idx                              pedestrianIndex) {
  return std::find(selectedPedestrianIds.begin(), selectedPedestrianIds.end(), pedestrianIndex) !=
         selectedPedestrianIds.end();
}