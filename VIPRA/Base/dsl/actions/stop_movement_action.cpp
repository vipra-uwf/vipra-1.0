#include "stop_movement_action.hpp"

StopMovementAction::StopMovementAction(SimulationContext* simContext) : Action(simContext, "STOPPED") {}

void
StopMovementAction::performAction(const ObstacleSet&   obstacleSet,
                                  const PedestrianSet& pedestrianSet,
                                  const Goals&         goals,
                                  VIPRA::idx           pedestrianIndex,
                                  std::shared_ptr<VIPRA::State>) {
  static const VIPRA::f3d STOPPED = VIPRA::f3d(0, 0, 0);

  if (!actionApplied(pedestrianIndex)) {
    const_cast<VIPRA::f3dVec&>(pedestrianSet.getVelocities()).at(pedestrianIndex) = STOPPED;
    const_cast<std::vector<float>&>(pedestrianSet.getSpeeds()).at(pedestrianIndex) = 0;
    // const_cast<VIPRA::f3dVec&>(pedestrianSet.getPropulsionForces()).at(pedestrianIndex) = STOPPED;
  }
}
