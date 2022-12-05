#include "id_ratio_selector.hpp"
#include <iostream>

IdRatioSelector::IdRatioSelector(
    SimulationContext *simulationContext, 
    FLOATING_NUMBER ratio) : Selector(simulationContext)
{
    this->ratio = ratio;
}

bool IdRatioSelector::select(int pedestrianIndex, const ObstacleSet& obstacleSet, const Goals& goals, const PedestrianSet& pedestrianSet)
{
    int pedestrianId = pedestrianSet->getIds().at(pedestrianIndex);
    
    static const int divisor = static_cast<int>(1.0 / this->ratio);

    bool condition = pedestrianId % divisor == 0;

    return condition;
}
