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
  // TODO: get index of pedestrian from id
  // size_t numPedestrians = pedestrianSet.getNumPedestrians();
  // while (selectedPedestrianIds.size() < count) {
  //   size_t pedestrianId = static_cast<size_t>(rand()) % numPedestrians;
  //   if (std::find(selectedPedestrianIds.begin(), selectedPedestrianIds.end(), pedestrianId) ==
  //       selectedPedestrianIds.end()) {
  //     std::cout << "Selecting pedestrian id " << pedestrianId << " for behavior." << std::endl;
  //     selectedPedestrianIds.push_back(pedestrianId);
  //   }
  // }
}

void
ExactlyNRandomSelector::initialize(const ObstacleSet&   obsSet,
                                   const PedestrianSet& pedSet,
                                   const Goals&         goals) {
  Selector::initialize(obsSet, pedSet, goals);
  selectPedestrianIds(pedSet);
}

bool
ExactlyNRandomSelector::select(VIPRA::idx           pedestrianIndex,
                               const ObstacleSet&   obstacleSet,
                               const Goals&         goals,
                               const PedestrianSet& pedestrianSet) {
  VIPRA::uid pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);
  return std::find(selectedPedestrianIds.begin(), selectedPedestrianIds.end(), pedestrianId) !=
         selectedPedestrianIds.end();
}