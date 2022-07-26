#ifndef STATE_CONDITION_HPP
#define STATE_CONDITION_HPP

#include "condition.hpp"
#include "../simulation_context.hpp"

/**
 * A condition that evaluates whether or not the pedestrian at the current
 * index is at a particular state (as defined by the behavior file).
 */
class StateCondition: public Condition
{
    public:
        StateCondition(SimulationContext *simulationContext, int desiredState);
        bool evaluate(int pedestrianIndex) override;
    
    private:
        int desiredState;
};

#endif