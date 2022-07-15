#ifndef CONDITION_HPP
#define CONDITION_HPP

#include "../simulation_context.hpp"

/**
 * A condition gets evaluated as a part of a selector or transition. It
 * evaluates to true or false for a particular pedestrian index.
 */
class Condition
{
    public:
        explicit Condition(SimulationContext *simulationContext);
        virtual bool evaluate(int pedestrianIndex) = 0;

    protected:
        SimulationContext *getSimulationContext();
    
    private:
        SimulationContext *simulationContext;

};

#endif
