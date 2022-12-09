#ifndef EVERYONE_SELECTOR_HPP
#define EVERYONE_SELECTOR_HPP

#include "definitions/type_definitions.hpp"
#include "selector.hpp"


/**
 * Select every pedestrian for this behavior
 */
class EveryoneSelector : public Selector {
 public:
  explicit EveryoneSelector(SimulationContext* simulationContext);
  bool select(int                  pedestrianIndex,
              const ObstacleSet&   obstacleSet,
              const Goals&         goals,
              const PedestrianSet& pedestrianSet) override;
};

#endif