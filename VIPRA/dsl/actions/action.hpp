#ifndef ACTION_HPP
#define ACTION_HPP

#include "../simulation_context.hpp"

class Action
{
    public:
        Action(SimulationContext *simulationContext);
        virtual void performAction(int pedestrianIndex) = 0;
    
    protected:
        SimulationContext *getSimulationContext();


    private:
        SimulationContext *simulationContext;
};

#endif