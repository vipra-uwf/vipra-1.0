#ifndef TRANSITION_HPP
#define TRANSITION_HPP

#include "../simulation_context.hpp"
#include "../conditions/condition.hpp"

class Transition
{
    public:
        Transition(SimulationContext *simulationContext, Condition *condition, int newState);
        bool evaluateTransition(int pedestrianIndex);
    
    private:
        SimulationContext *simulationContext;
        Condition *condition;
        int newState;
};

#endif