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
  void performAction(const ObstacleSet&            obstacleSet,
                     const PedestrianSet&          pedestrianSet,
                     const Goals&                  goals,
                     VIPRA::idx                    pedestrianIndex,
                     VIPRA::delta_t                time,
                     std::shared_ptr<VIPRA::State> state) override;

  void initialize(const PedestrianSet& pedestrianSet) override;

 private:
  VIPRA::f3d        computeAlteredDimensions(VIPRA::f3d originalDimensions);
  std::vector<bool> actionAppliedStatus;
  ALTER_DIRECTION   alterDirection;
  float             factor;
};

#endif  //VIPRA_ALTER_VELOCITY_ACTION_HPP
