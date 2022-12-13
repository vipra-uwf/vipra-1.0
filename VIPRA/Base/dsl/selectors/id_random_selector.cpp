#include "id_random_selector.hpp"
#include <algorithm>
#include <iostream>

IdRandomSelector::IdRandomSelector(SimulationContext* simulationContext, float ratio)
  : IdRandomSelector(simulationContext, ratio, time(nullptr)) {}

IdRandomSelector::IdRandomSelector(SimulationContext* simulationContext, float ratio, unsigned int seed)
  : Selector(simulationContext), ratio(ratio) {
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
IdRandomSelector::select(int                  pedestrianIndex,
                         const ObstacleSet&   obstacleSet,
                         const Goals&         goals,
                         const PedestrianSet& pedestrianSet) {
  int pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);
  return std::find(selectedPedestrianIds.begin(), selectedPedestrianIds.end(), pedestrianId) !=
         selectedPedestrianIds.end();
}

void
IdRandomSelector::initialize() {
  Selector::initialize();
  selectPedestrianIds();
}
