

#include "selectors/selector_percent.hpp"

Selector_Percent::Selector_Percent(float selectRatio) : Selector() {
  this->ratio = selectRatio;
}

bool
Selector_Percent::select([[maybe_unused]] const ObstacleSet&     obstacleSet,
                         [[maybe_unused]] const PedestrianSet&   pedestrianSet,
                         [[maybe_unused]] const Goals&           goals,
                         [[maybe_unused]] const BehaviorContext& context,
                         VIPRA::idx                              pedestrianIndex) {
  const uint divisor = (1.0 / this->ratio);

  return (pedestrianIndex % divisor == 0);
}