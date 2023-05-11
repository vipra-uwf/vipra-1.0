#include "everyone_selector.hpp"
#include <algorithm>
#include <iostream>

EveryoneSelector::EveryoneSelector(SimulationContext *simulationContext)
    : Selector(simulationContext)
{
}

bool EveryoneSelector::select(int pedestrianIndex)
{
    return true;
}
