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
  bool select(const ObstacleSet&   obstacleSet,
              const PedestrianSet& pedestrianSet,
              const Goals&         goals,
              VIPRA::idx           pedestrianIndex) override;
};

#endif