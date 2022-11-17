#include "id_random_selector.hpp"
#include <algorithm>
#include <iostream>

IdRandomSelector::IdRandomSelector(SimulationContext *simulationContext, FLOATING_NUMBER ratio)
    : IdRandomSelector(simulationContext, ratio, time(nullptr))
{
}

IdRandomSelector::IdRandomSelector(SimulationContext *simulationContext, FLOATING_NUMBER ratio, unsigned int seed)
    : Selector(simulationContext), ratio(ratio)
{
    srand(seed);
}

void IdRandomSelector::selectPedestrianIds()
{
    int divisor = static_cast<int>(1.0 / ratio);
    for (auto pedestrianId: (this->getSimulationContext()->pedestrianSet->getIds()))
    {
        int diceRoll = rand() % divisor;
        if (diceRoll == 0)
        {
            std::cout << "Selecting pedestrian id " << pedestrianId << " for behavior." << std::endl;
            selectedPedestrianIds.push_back(pedestrianId);
        }
    }
}

bool IdRandomSelector::select(int pedestrianIndex, const ObstacleSet& obstacleSet, const Goals& goals)
{
    int pedestrianId = this->getSimulationContext()->pedestrianSet->getIds().at(pedestrianIndex);
    return std::find(selectedPedestrianIds.begin(),
                     selectedPedestrianIds.end(),
                     pedestrianId) != selectedPedestrianIds.end();
}

void IdRandomSelector::initialize()
{
    Selector::initialize();
    selectPedestrianIds();
}
