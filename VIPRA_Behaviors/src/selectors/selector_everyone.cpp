#include <algorithm>

#include "selectors/selector_everyone.hpp"

Selector_Everyone::Selector_Everyone() : Selector() {}

bool
Selector_Everyone::select([[maybe_unused]] const ObstacleSet&     obstacleSet,
                          [[maybe_unused]] const PedestrianSet&   pedestrianSet,
                          [[maybe_unused]] const Goals&           goals,
                          [[maybe_unused]] const BehaviorContext& context,
                          [[maybe_unused]] VIPRA::idx             pedestrianIndex) {
  return true;
}
