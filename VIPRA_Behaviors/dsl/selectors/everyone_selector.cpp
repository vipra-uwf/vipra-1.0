#include "everyone_selector.hpp"
#include <algorithm>
#include <iostream>

EveryoneSelector::EveryoneSelector() : Selector() {}

bool
EveryoneSelector::select([[maybe_unused]] const ObstacleSet&     obstacleSet,
                         [[maybe_unused]] const PedestrianSet&   pedestrianSet,
                         [[maybe_unused]] const Goals&           goals,
                         [[maybe_unused]] const BehaviorContext& context,
                         [[maybe_unused]] VIPRA::idx             pedestrianIndex) {
  return true;
}
