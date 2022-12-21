//
// Created by joe on 12/5/21.
//

#ifndef VIPRA_ENVIRONMENT_ELAPSED_TIME_CONDITION_HPP
#define VIPRA_ENVIRONMENT_ELAPSED_TIME_CONDITION_HPP

#include "elapsed_time_condition.hpp"

class EnvironmentElapsedTimeCondition : public ElapsedTimeCondition {
 public:
  EnvironmentElapsedTimeCondition(SimulationContext* simulationContext, VIPRA::delta_t desiredElapsedTime);
  bool evaluate(const ObstacleSet&   obsSet,
                const PedestrianSet& pedestrianSet,
                const Goals&         goals,
                VIPRA::idx           pedestrianIndex) override;
};

#endif  //VIPRA_ENVIRONMENT_ELAPSED_TIME_CONDITION_HPP
