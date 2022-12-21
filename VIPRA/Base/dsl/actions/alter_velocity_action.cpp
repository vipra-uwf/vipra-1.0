//
// Created by joe on 12/7/21.
//

#include "alter_velocity_action.hpp"

AlterVelocityAction::AlterVelocityAction(SimulationContext* simContext,
                                         ALTER_DIRECTION    alterDir,
                                         float              vel_factor)
  : Action(simContext, "ALTER_VELOCITY"), alterDirection(alterDir), factor(vel_factor) {}

void
AlterVelocityAction::performAction([[maybe_unused]] const ObstacleSet&   obstacleSet,
                                   [[maybe_unused]] const PedestrianSet& pedestrianSet,
                                   [[maybe_unused]] const Goals&         goals,
                                   VIPRA::idx                            pedIndex,
                                   [[maybe_unused]] VIPRA::delta_t       time,
                                   std::shared_ptr<VIPRA::State>         state) {

  VIPRA::f3d originalPos = state->pedestrianCoordinates[pedIndex] - state->velocities[pedIndex];
  state->velocities[pedIndex] = computeAlteredDimensions(state->velocities[pedIndex]);
  state->pedestrianCoordinates[pedIndex] = originalPos + state->velocities[pedIndex];
}

VIPRA::f3d
AlterVelocityAction::computeAlteredDimensions(VIPRA::f3d originalDimensions) {
  float multiplier;
  if (alterDirection == FASTER) {
    // Faster
    multiplier = 1.0F + factor;
  } else {
    // Slower
    multiplier = 1.0F - factor;
  }
  originalDimensions *= multiplier;
  return originalDimensions;
}

void
AlterVelocityAction::initialize(const PedestrianSet& pedestrianSet) {
  actionAppliedStatus.resize(pedestrianSet.getNumPedestrians(), false);
  Action::initialize(pedestrianSet);
}
