//
// Created by joe on 12/1/21.
//

#ifndef VIPRA_ENVIRONMENT_STATE_CONDITION_HPP
#define VIPRA_ENVIRONMENT_STATE_CONDITION_HPP

#include "condition.hpp"

class EnvironmentStateCondition : public Condition {
 public:
  explicit EnvironmentStateCondition(SimulationContext* simulationContext, VIPRA::stateUID state);
  bool evaluate(const ObstacleSet&   obsSet,
                const PedestrianSet& pedestrianSet,
                const Goals&         goals,
                VIPRA::idx           pedestrianIndex) override;

 private:
  VIPRA::stateUID desiredState;
};

#endif  //VIPRA_ENVIRONMENT_STATE_CONDITION_HPP
