#ifndef STOP_MOVEMENT_ACTION_HPP
#define STOP_MOVEMENT_ACTION_HPP

#include "action.hpp"

class StopMovementAction : public Action
{
    public:
        StopMovementAction(SimulationContext *simulationContext);
        void performAction(int pedestrianIndex);
};

#endif