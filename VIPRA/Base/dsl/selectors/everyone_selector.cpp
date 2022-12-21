#include "everyone_selector.hpp"
#include <algorithm>
#include <iostream>

EveryoneSelector::EveryoneSelector(SimulationContext* simContext) : Selector(simContext) {}

bool
EveryoneSelector::select([[maybe_unused]] const ObstacleSet&   obstacleSet,
                         [[maybe_unused]] const PedestrianSet& pedestrianSet,
                         [[maybe_unused]] const Goals&         goals,
                         [[maybe_unused]] VIPRA::idx           pedestrianIndex) {
  return true;
}
