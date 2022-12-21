#ifndef ELAPSED_TIME_CONDITION_HPP
#define ELAPSED_TIME_CONDITION_HPP

#include "condition.hpp"

/**
 * A condition that checks to see if a certain amount of time has elapsed since
 * the previous transition. It only performs the check based on the shared data
 * in the simulation context.
 */
class ElapsedTimeCondition : public Condition {
 public:
  ElapsedTimeCondition(SimulationContext* simulationContext, VIPRA::delta_t desiredElapsedTime);
  bool evaluate(const ObstacleSet&   obsSet,
                const PedestrianSet& pedestrianSet,
                const Goals&         goals,
                VIPRA::idx           pedestrianIndex) override;

 protected:
  float desiredElapsedTime;
};

#endif