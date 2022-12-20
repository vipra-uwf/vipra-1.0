#include "id_ratio_selector.hpp"
#include <iostream>

IdRatioSelector::IdRatioSelector(SimulationContext* simContext, float selectRatio) : Selector(simContext) {
  this->ratio = selectRatio;
}

bool
IdRatioSelector::select(VIPRA::idx           pedestrianIndex,
                        const ObstacleSet&   obstacleSet,
                        const Goals&         goals,
                        const PedestrianSet& pedestrianSet) {
  VIPRA::uid pedestrianId = pedestrianSet.getIds().at(pedestrianIndex);

  const int divisor = (1.0 / this->ratio);

  bool condition = pedestrianId % divisor == 0;

  return condition;
}
