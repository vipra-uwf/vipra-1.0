#ifndef STATE_CONDITION_HPP
#define STATE_CONDITION_HPP

#include "condition.hpp"
#include "../simulation_context.hpp"

class StateCondition: public Condition
{
    public:
        StateCondition(SimulationContext *simulationContext, int desiredState);
        bool evaluate(int pedestrianIndex);
    
    private:
        int desiredState;
};

#endif