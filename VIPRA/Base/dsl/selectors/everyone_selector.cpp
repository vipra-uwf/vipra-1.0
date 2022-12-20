#include "everyone_selector.hpp"
#include <algorithm>
#include <iostream>

EveryoneSelector::EveryoneSelector(SimulationContext* simContext) : Selector(simContext) {}

bool
EveryoneSelector::select(VIPRA::idx           pedestrianIndex,
                         const ObstacleSet&   obstacleSet,
                         const Goals&         goals,
                         const PedestrianSet& pedestrianSet) {
  return true;
}
