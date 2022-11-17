#include "everyone_selector.hpp"
#include <algorithm>
#include <iostream>

EveryoneSelector::EveryoneSelector(SimulationContext *simulationContext)
    : Selector(simulationContext)
{
}

bool EveryoneSelector::select(int pedestrianIndex, const ObstacleSet& obstacleSet, const Goals& goals)
{
    return true;
}
