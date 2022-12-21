#include "id_random_selector.hpp"
#include <algorithm>
#include <iostream>

IdRandomSelector::IdRandomSelector(SimulationContext* simContext, float selectRatio)
  : IdRandomSelector(simContext, selectRatio, time(nullptr)) {}

IdRandomSelector::IdRandomSelector(SimulationContext* simContext, float selectRatio, unsigned int seed)
  : Selector(simContext), ratio(selectRatio) {
  srand(seed);
}

void
IdRandomSelector::selectPedestrianIds(const PedestrianSet& pedestrianSet) {
  int         divisor = static_cast<int>(1.0 / ratio);
  const auto& pedestrianIDs{pedestrianSet.getIds()};
  for (auto pedestrianId : pedestrianIDs) {
    int diceRoll = rand() % divisor;
    if (diceRoll == 0) {
      LJ::Debug(simLogger, "Selecting pedestrian id: {} for behavior.", pedestrianId);
      selectedPedestrianIds.push_back(pedestrianId);
    }
  }
}

bool
IdRandomSelector::select([[maybe_unused]] const ObstacleSet& obstacleSet,
                         const PedestrianSet&                pedestrianSet,
                         [[maybe_unused]] const Goals&       goals,
                         VIPRA::idx                          pedestrianIndex) {

  VIPRA::uid pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);
  return std::find(selectedPedestrianIds.begin(), selectedPedestrianIds.end(), pedestrianId) !=
         selectedPedestrianIds.end();
}

void
IdRandomSelector::initialize(const ObstacleSet& obsSet, const PedestrianSet& pedSet, const Goals& goals) {
  Selector::initialize(obsSet, pedSet, goals);
  selectPedestrianIds(pedSet);
}
