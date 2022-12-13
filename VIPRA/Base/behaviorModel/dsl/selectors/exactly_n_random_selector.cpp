//
// Created by joe on 12/10/21.
//

#include <iostream>
#include <algorithm>
#include "exactly_n_random_selector.hpp"

ExactlyNRandomSelector::ExactlyNRandomSelector(SimulationContext *simulationContext, int count, unsigned int seed)
    : Selector(simulationContext), count(count)
{
    srand(seed);
}


void ExactlyNRandomSelector::selectPedestrianIds(const PedestrianSet& pedestrianSet)
{
    int numPedestrians = pedestrianSet.getNumPedestrians();
    while (selectedPedestrianIds.size() < count)
    {
        int pedestrianId = rand() % numPedestrians;
        if (std::find(selectedPedestrianIds.begin(), selectedPedestrianIds.end(), pedestrianId) == selectedPedestrianIds.end()) {
            std::cout << "Selecting pedestrian id " << pedestrianId << " for behavior." << std::endl;
            selectedPedestrianIds.push_back(pedestrianId);
        }
    }
}

void ExactlyNRandomSelector::initialize()
{
    Selector::initialize();
    selectPedestrianIds();
}

bool ExactlyNRandomSelector::select(int pedestrianIndex, const ObstacleSet& obstacleSet, const Goals& goals, const PedestrianSet& pedestrianSet)
{
    int pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);
    return std::find(selectedPedestrianIds.begin(),
                     selectedPedestrianIds.end(),
                     pedestrianId) != selectedPedestrianIds.end();
}