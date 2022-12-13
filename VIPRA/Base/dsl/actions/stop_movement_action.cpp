#include "stop_movement_action.hpp"

StopMovementAction::StopMovementAction(SimulationContext* simulationContext)
  : Action(simulationContext, "STOPPED") {}

void
StopMovementAction::performAction(int                  pedestrianIndex,
                                  const PedestrianSet& pedestrianSet,
                                  const ObstacleSet&   obstacleSet,
                                  const Goals&         goals) {
  static const VIPRA::f3d STOPPED = VIPRA::f3d{std::vector<float>{0, 0, 0}};

  if (!actionApplied(pedestrianIndex)) {
    auto pedestrianSetObj = dynamic_cast<PedestrianSet*>(pedestrianSet);
    const_cast<VIPRA::f3dVec&>(pedestrianSetObj->getVelocities()).at(pedestrianIndex) = STOPPED;
    const_cast<VIPRA::f3d&>(pedestrianSetObj->getSpeeds()).at(pedestrianIndex) = 0;
    const_cast<VIPRA::f3dVec&>(pedestrianSetObj->getPropulsionForces()).at(pedestrianIndex) = STOPPED;
  }
}
