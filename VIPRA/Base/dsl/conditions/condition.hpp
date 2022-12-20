#ifndef CONDITION_HPP
#define CONDITION_HPP

#include "../simulation_context.hpp"
#include "goals/goals.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"

/**
 * A condition gets evaluated as a part of a selector or transition. It
 * evaluates to true or false for a particular pedestrian index.
 */
class Condition {
 public:
  explicit Condition(SimulationContext* simulationContext);
  virtual bool evaluate(const ObstacleSet&,
                        const PedestrianSet&,
                        const Goals&,
                        VIPRA::idx pedestrianIndex) = 0;

 protected:
  SimulationContext* getSimulationContext();

 private:
  SimulationContext* simulationContext;
};

#endif
