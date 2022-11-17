#include "stop_movement_action.hpp"
#include "../../../pedestrian_set/pedestrian_set.hpp"

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
        auto *pedestrianSetObj = dynamic_cast<PedestrianSet *>(this->getSimulationContext()->pedestrianSet);
        const_cast<DimsVector&>(pedestrianSetObj->getVelocities()).at(pedestrianIndex) = STOPPED;
        const_cast<Dimensions&>(pedestrianSetObj->getSpeeds()).at(pedestrianIndex) = 0;
        const_cast<DimsVector&>(pedestrianSetObj->getPropulsionForces()).at(pedestrianIndex) = STOPPED;
    }
}
