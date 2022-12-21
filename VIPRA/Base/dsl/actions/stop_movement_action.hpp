#ifndef STOP_MOVEMENT_ACTION_HPP
#define STOP_MOVEMENT_ACTION_HPP

#include "action.hpp"

/**
 * Stop the movement of the pedestrian at the current index.
 */
class StopMovementAction : public Action {
 public:
  explicit StopMovementAction(SimulationContext* simulationContext);
  ~StopMovementAction() override = default;
  void performAction(const ObstacleSet&   obstacleSet,
                     const PedestrianSet& pedestrianSet,
                     const Goals&         goals,
                     VIPRA::idx           pedestrianIndex,
                     std::shared_ptr<VIPRA::State>) override;
};

#endif