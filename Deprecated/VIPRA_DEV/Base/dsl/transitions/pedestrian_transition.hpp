#ifndef PEDESTRIAN_TRANSITION_HPP
#define PEDESTRIAN_TRANSITION_HPP

#include "../simulation_context.hpp"
#include "../conditions/condition.hpp"
#include "transition.hpp"

/**
 * A transition pairs a condition with a new state. If the condition evaluates
 * to true, the state is changed to the new value.
 */
class PedestrianTransition : public Transition
{
    public:
        PedestrianTransition(SimulationContext *simulationContext, Condition *condition, int newState);
        bool evaluateTransition(int pedestrianIndex);
};

#endif