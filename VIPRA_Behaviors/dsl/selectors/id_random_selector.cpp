#include "id_random_selector.hpp"
#include <algorithm>
#include <iostream>

IdRandomSelector::IdRandomSelector(float selectRatio) : IdRandomSelector(selectRatio, time(nullptr)) {}

IdRandomSelector::IdRandomSelector(float selectRatio, unsigned int seed) : Selector(), ratio(selectRatio) {
  srand(seed);
}

void
IdRandomSelector::selectPedestrianIds(const PedestrianSet& pedestrianSet) {
  const VIPRA::size pedCnt = pedestrianSet.getNumPedestrians();
  int               divisor = static_cast<int>(1.0 / ratio);
  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    int diceRoll = rand() % divisor;
    if (diceRoll == 0) {
      spdlog::debug("Selecting pedestrian id: {} for behavior.", i);
      selectedPedestrianIds.push_back(i);
    }
  }
}

bool
IdRandomSelector::select([[maybe_unused]] const ObstacleSet&     obstacleSet,
                         [[maybe_unused]] const PedestrianSet&   pedestrianSet,
                         [[maybe_unused]] const Goals&           goals,
                         [[maybe_unused]] const BehaviorContext& context,
                         VIPRA::idx                              pedestrianIndex) {

  return std::find(selectedPedestrianIds.begin(), selectedPedestrianIds.end(), pedestrianIndex) !=
         selectedPedestrianIds.end();
}

void
IdRandomSelector::initialize([[maybe_unused]] const ObstacleSet& obsSet,
                             const PedestrianSet&                pedSet,
                             [[maybe_unused]] const Goals&       goals) {
  selectPedestrianIds(pedSet);
}
