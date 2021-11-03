#ifndef CONDITION_HPP
#define CONDITION_HPP

#include "../simulation_context.hpp"

class Condition
{
    public:
        Condition(SimulationContext *simulationContext);
        virtual bool evaluate(int pedestrianIndex) = 0;

    protected:
        SimulationContext *getSimulationContext();
    
    private:
        SimulationContext *simulationContext;

};

#endif
