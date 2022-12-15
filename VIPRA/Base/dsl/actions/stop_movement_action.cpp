#include "stop_movement_action.hpp"

StopMovementAction::StopMovementAction(SimulationContext* simulationContext)
  : Action(simulationContext, "STOPPED") {}

void
StopMovementAction::performAction(int                  pedestrianIndex,
                                  const PedestrianSet& pedestrianSet,
                                  const ObstacleSet&   obstacleSet,
                                  const Goals&         goals) {
  static const VIPRA::f3d STOPPED = VIPRA::f3d(0, 0, 0);

  if (!actionApplied(pedestrianIndex)) {
    const_cast<VIPRA::f3dVec&>(pedestrianSet.getVelocities()).at(pedestrianIndex) = STOPPED;
    const_cast<std::vector<float>&>(pedestrianSet.getSpeeds()).at(pedestrianIndex) = 0;
    // const_cast<VIPRA::f3dVec&>(pedestrianSet.getPropulsionForces()).at(pedestrianIndex) = STOPPED;
  }
}
