#include "stop_movement_action.hpp"

StopMovementAction::StopMovementAction(SimulationContext *simulationContext)
    : Action(simulationContext, "STOPPED")
{

}

void StopMovementAction::performAction(int pedestrianIndex, const PedestrianSet& pedestrianSet, const ObstacleSet& obstacleSet, const Goals& goals)
{
    static const Dimensions STOPPED = Dimensions
    {
        std::vector < FLOATING_NUMBER > {0, 0, 0}
    };

    if (!actionApplied(pedestrianIndex))
    {
        auto *pedestrianSetObj = dynamic_cast<PedestrianSet *>(pedestrianSet);
        const_cast<DimVector&>(pedestrianSetObj->getVelocities()).at(pedestrianIndex) = STOPPED;
        const_cast<Dimensions&>(pedestrianSetObj->getSpeeds()).at(pedestrianIndex) = 0;
        const_cast<DimVector&>(pedestrianSetObj->getPropulsionForces()).at(pedestrianIndex) = STOPPED;
    }
}
