#include "stop_movement_action.hpp"

StopMovementAction::StopMovementAction(SimulationContext *simulationContext)
    : Action(simulationContext)
{

}

void StopMovementAction::performAction(int pedestrianIndex)
{
    static const Dimensions STOPPED = Dimensions
    {
        std::vector < FLOATING_NUMBER > {0, 0, 0}
    };

    this->getSimulationContext()->pedestrianSet->getVelocities()->at(pedestrianIndex) = STOPPED;
    this->getSimulationContext()->pedestrianSet->getSpeeds()->at(pedestrianIndex) = 0;
}
