//
// Created by joe on 12/7/21.
//

#ifndef VIPRA_ALTER_VELOCITY_ACTION_HPP
#define VIPRA_ALTER_VELOCITY_ACTION_HPP

#include "action.hpp"

typedef enum { FASTER, SLOWER } ALTER_DIRECTION;

class AlterVelocityAction : public Action {
 public:
  AlterVelocityAction(SimulationContext* simulationContext, ALTER_DIRECTION alterDirection, float factor);
  void performAction(VIPRA::idx           pedestrianIndex,
                     const PedestrianSet& pedestrianSet,
                     const ObstacleSet&   obstacleSet,
                     const Goals&         goals) override;
  void initialize(const PedestrianSet& pedestrianSet) override;

 private:
  VIPRA::f3d        computeAlteredDimensions(VIPRA::f3d originalDimensions);
  std::vector<bool> actionAppliedStatus;
  ALTER_DIRECTION   alterDirection;
  float             factor;
};

#endif  //VIPRA_ALTER_VELOCITY_ACTION_HPP
