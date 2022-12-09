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
  IdRatioSelector(SimulationContext* simulationContext, FLOATING_NUMBER ratio);
  bool select(int                  pedestrianIndex,
              const ObstacleSet&   obstacleSet,
              const Goals&         goals,
              const PedestrianSet& pedestrianSet) override;

 private:
  FLOATING_NUMBER ratio;
};

#endif