#include "stop_movement_action.hpp"
#include "../../../calm_pedestrian_set/calm_pedestrian_set.hpp"

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
        const_cast<DimsVector&>(calmPedestrianSet->getVelocities()).at(pedestrianIndex) = STOPPED;
        const_cast<Dimensions&>(calmPedestrianSet->getSpeeds()).at(pedestrianIndex) = 0;
        const_cast<DimsVector&>(calmPedestrianSet->getPropulsionForces()).at(pedestrianIndex) = STOPPED;
    }
}
