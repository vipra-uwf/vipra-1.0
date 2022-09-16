#include "stop_movement_action.hpp"
#include "../../entity_sets/calm_pedestrian_set.hpp"

StopMovementAction::StopMovementAction(SimulationContext *simulationContext)
    : Action(simulationContext, "STOPPED")
{

}

void StopMovementAction::performAction(int pedestrianIndex)
{
    static const Dimensions STOPPED = Dimensions
    {
        std::vector < FLOATING_NUMBER > {0, 0, 0}
    };

    if (!actionApplied(pedestrianIndex))
    {
        auto *calmPedestrianSet = dynamic_cast<CalmPedestrianSet *>(this->getSimulationContext()->pedestrianSet);
        calmPedestrianSet->getVelocities()->at(pedestrianIndex) = STOPPED;
        calmPedestrianSet->getSpeeds()->at(pedestrianIndex) = 0;
        calmPedestrianSet->getPropulsionForces()->at(pedestrianIndex) = STOPPED;
    }
}
