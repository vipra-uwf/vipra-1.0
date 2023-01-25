#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include "../simulation_context.hpp"
#include "goals/goals.hpp"
#include "logging/logging.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

/**
 * A selector is used to decide if a pedestrian should be evaluated for a 
 * behavior. It has the entire pedestrian set available to help with the 
 * selection.
 */
class Selector {
 public:
  explicit Selector(SimulationContext* simulationContext);
  virtual bool select(const ObstacleSet&   obstacleSet,
                      const PedestrianSet& pedestrianSet,
                      const Goals&         goals,
                      VIPRA::idx           pedestrianIndex) = 0;
  virtual void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&);

 protected:
  SimulationContext* getSimulationContext();

 private:
  SimulationContext* simulationContext;
};

#endif