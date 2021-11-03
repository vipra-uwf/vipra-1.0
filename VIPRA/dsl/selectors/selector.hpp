#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include "../simulation_context.hpp"

/**
 * A selector is used to decide if a pedestrian should be evaluated for a 
 * behavior. It has the entire pedestrian set available to help with the 
 * selection.
 */
class Selector
{
    public:
        Selector(SimulationContext *simulationContext);
        virtual bool select(int pedestrianIndex) = 0;

    protected:
        SimulationContext *getSimulationContext();
    
    private:
        SimulationContext *simulationContext;
};

#endif