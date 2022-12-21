//
// Created by joe on 12/10/21.
//

#include "exactly_n_random_selector.hpp"
#include <algorithm>
#include <iostream>

ExactlyNRandomSelector::ExactlyNRandomSelector(SimulationContext* simContext, size_t N, unsigned int seed)
  : Selector(simContext), count(N) {
  srand(seed);
}

void
ExactlyNRandomSelector::selectPedestrianIds(const PedestrianSet& pedestrianSet) {
  VIPRA::size numPedestrians = pedestrianSet.getNumPedestrians();

  while (selectedPedestrianIds.size() < count) {
    VIPRA::uid pedestrianId = static_cast<VIPRA::uid>(rand()) % numPedestrians;
    if (std::find(selectedPedestrianIds.begin(), selectedPedestrianIds.end(), pedestrianId) ==
        selectedPedestrianIds.end()) {
      LJ::Debug(simLogger, "Selecting pedestrian id: {} for behavior.", pedestrianId);
      selectedPedestrianIds.push_back(pedestrianId);
    }
  }
}

void
ExactlyNRandomSelector::initialize(const ObstacleSet&   obsSet,
                                   const PedestrianSet& pedSet,
                                   const Goals&         goals) {
  Selector::initialize(obsSet, pedSet, goals);
  selectPedestrianIds(pedSet);
}

bool
ExactlyNRandomSelector::select([[maybe_unused]] const ObstacleSet& obstacleSet,
                               const PedestrianSet&                pedestrianSet,
                               [[maybe_unused]] const Goals&       goals,
                               VIPRA::idx                          pedestrianIndex) {
  VIPRA::uid pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);
  return std::find(selectedPedestrianIds.begin(), selectedPedestrianIds.end(), pedestrianId) !=
         selectedPedestrianIds.end();
}