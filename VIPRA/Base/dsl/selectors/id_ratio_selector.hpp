#ifndef ID_RATIO_SELECTOR_HPP
#define ID_RATIO_SELECTOR_HPP

#include "definitions/type_definitions.hpp"
#include "selector.hpp"

/**
 * Select the pedestrian based on a specified ratio. Useful for behaviors that 
 * are selected by a certain percent of the population. This uses an algorithm
 * that is deterministic, so every run of the selector is identical.
 */
class IdRatioSelector : public Selector {
 public:
  IdRatioSelector(SimulationContext* simulationContext, float ratio);
  bool select(const ObstacleSet&   obstacleSet,
              const PedestrianSet& pedestrianSet,
              const Goals&         goals,
              VIPRA::idx           pedestrianIndex) override;

 private:
  float ratio;
};

#endif