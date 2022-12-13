//
// Created by joe on 12/7/21.
//

#include "alter_velocity_action.hpp"

AlterVelocityAction::AlterVelocityAction(SimulationContext* simulationContext,
                                         ALTER_DIRECTION    alterDirection,
                                         float              factor)
  : Action(simulationContext, "ALTER_VELOCITY"), alterDirection(alterDirection), factor(factor) {}

void
AlterVelocityAction::performAction(int                  pedestrianIndex,
                                   const PedestrianSet& pedestrianSet,
                                   const ObstacleSet&   obstacleSet,
                                   const Goals&         goals) {
  if (!actionApplied(pedestrianIndex)) {
    // Slow down the new velocity
    VIPRA::f3d& originalVelocity = const_cast<VIPRA::f3d&>(pedestrianSet.getVelocities().at(pedestrianIndex));
    const VIPRA::f3d& newVelocity = computeAlteredDimensions(originalVelocity);

    // Override the velocity for this pedestrian
    const_cast<VIPRA::f3d&>(pedestrianSet.getVelocities().at(pedestrianIndex)) = newVelocity;

    // Taken from the CALM pedestrian model
    float newSpeed = ((newVelocity[0] * newVelocity[0]) + (newVelocity[1] * newVelocity[1]));

    const_cast<VIPRA::f3d&>(pedestrianSet.getSpeeds()).at(pedestrianIndex) = newSpeed;

    this->actionAppliedStatus.at(pedestrianIndex) = true;
  }

  // Apply the multiplier to both the propulsion force too.
  // The CALM pedestrian model controls the application of these values to compute the next position. See the
  // update method of calm_pedestrian_model.cpp for the details of this math. Basically if we want a multiplier
  // applied to the _final_ velocity, we need to apply it to the old velocity, and the propulsion force.
  // We update this every time regardless of whether or not the action has been applied because the propulsion is
  // calculated in the precompute() section of the calm_pedestrian_model, and does not look at any previous value
  // of the propulsion force. So to persist our velocity change, we need to modify the original velocity once, but
  // modify the propulsion force every time while this action is active.
  VIPRA::f3d& originalPropulsionForce =
      const_cast<VIPRA::f3dVec&>(pedestrianSet.getPropulsionForces()).at(pedestrianIndex);
  const VIPRA::f3d& newPropulsion = computeAlteredDimensions(originalPropulsionForce);
  const_cast<VIPRA::f3dVec&>(pedestrianSet.getPropulsionForces()).at(pedestrianIndex) = newPropulsion;
}

VIPRA::f3d
AlterVelocityAction::computeAlteredDimensions(VIPRA::f3d originalDimensions) {
  std::vector<float> coordinates(originalDimensions.size());

  float multiplier;
  if (alterDirection == FASTER) {
    // Faster
    multiplier = 1.0F + factor;
  } else {
    // Slower
    multiplier = 1.0F - factor;
  }

  for (int i = 0; i < originalDimensions.size(); ++i) {
    coordinates.at(i) = originalDimensions.at(i) * multiplier;
  }

  return VIPRA::f3d{coordinates};
}

void
AlterVelocityAction::initialize(const PedestrianSet& pedestrianSet) {
  actionAppliedStatus.resize(pedestrianSet.getNumPedestrians(), false);
  Action::initialize();
}
