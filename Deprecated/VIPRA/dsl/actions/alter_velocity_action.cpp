//
// Created by joe on 12/7/21.
//

#include "alter_velocity_action.hpp"
#include "../../entity_sets/calm_pedestrian_set.hpp"

AlterVelocityAction::AlterVelocityAction(SimulationContext *simulationContext,
                                         ALTER_DIRECTION alterDirection,
                                         FLOATING_NUMBER factor)
        : Action(simulationContext, "ALTER_VELOCITY"),
          alterDirection(alterDirection), factor(factor)
{
}

void AlterVelocityAction::performAction(int pedestrianIndex)
{
    auto *calmPedestrianSet = dynamic_cast<CalmPedestrianSet *>(this->getSimulationContext()->pedestrianSet);
    if (!actionApplied(pedestrianIndex))
    {
        // Slow down the new velocity
        Dimensions &originalVelocity = this->getSimulationContext()->pedestrianSet->getVelocities()->at(
                pedestrianIndex);
        const Dimensions &newVelocity = computeAlteredDimensions(originalVelocity);

        // Override the velocity for this pedestrian
        this->getSimulationContext()->pedestrianSet->getVelocities()->at(pedestrianIndex) = newVelocity;


        // Taken from the CALM pedestrian model
        FLOATING_NUMBER newSpeed = ((newVelocity.coordinates[0]
                     * newVelocity.coordinates[0])
                    + (newVelocity.coordinates[1]
                       * newVelocity.coordinates[1]));

        calmPedestrianSet->getSpeeds()->at(pedestrianIndex) = newSpeed;

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
    Dimensions &originalPropulsionForce = calmPedestrianSet->getPropulsionForces()->at(pedestrianIndex);
    const Dimensions &newPropulsion = computeAlteredDimensions(originalPropulsionForce);
    calmPedestrianSet->getPropulsionForces()->at(pedestrianIndex) = newPropulsion;

}

Dimensions AlterVelocityAction::computeAlteredDimensions(Dimensions originalDimensions)
{
    std::vector<FLOATING_NUMBER> coordinates(originalDimensions.coordinates.size());

    FLOATING_NUMBER multiplier;
    if (alterDirection == FASTER)
    {
        // Faster
        multiplier = 1.0F + factor;
    }
    else
    {
        // Slower
        multiplier = 1.0F - factor;
    }

    for (int i = 0; i < originalDimensions.coordinates.size(); ++i)
    {
        coordinates.at(i) = originalDimensions.coordinates.at(i) * multiplier;
    }

    return Dimensions { coordinates };
}

void AlterVelocityAction::initialize()
{
    actionAppliedStatus.resize(this->getSimulationContext()->pedestrianSet->getNumPedestrians(), false);
    Action::initialize();
}


