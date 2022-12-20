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
  int divisor = static_cast<int>(1.0 / ratio);
  for (auto pedestrianId : (pedestrianSet.getIds())) {
    int diceRoll = rand() % divisor;
    if (diceRoll == 0) {
      std::cout << "Selecting pedestrian id " << pedestrianId << " for behavior." << std::endl;
      selectedPedestrianIds.push_back(pedestrianId);
    }
  }
}

bool
IdRandomSelector::select(VIPRA::idx           pedestrianIndex,
                         const ObstacleSet&   obstacleSet,
                         const Goals&         goals,
                         const PedestrianSet& pedestrianSet) {
  VIPRA::uid pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);
  return std::find(selectedPedestrianIds.begin(), selectedPedestrianIds.end(), pedestrianId) !=
         selectedPedestrianIds.end();
}

void
IdRandomSelector::initialize(const ObstacleSet& obsSet, const PedestrianSet& pedSet, const Goals& goals) {
  Selector::initialize(obsSet, pedSet, goals);
  selectPedestrianIds(pedSet);
}
