#ifndef TRANSITION_HPP
#define TRANSITION_HPP

#include "../simulation_context.hpp"
#include "../conditions/condition.hpp"

/**
 * A transition pairs a condition with a new state. If the condition evaluates
 * to true, the state is changed to the new value.
 */
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