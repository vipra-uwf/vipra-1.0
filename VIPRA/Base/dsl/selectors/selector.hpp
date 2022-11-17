#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include "../simulation_context.hpp"
#include "../../../pedestrian_set/pedestrian_set.hpp"
#include "../../../obstacle_set/obstacle_set.hpp"

/**
 * A selector is used to decide if a pedestrian should be evaluated for a 
 * behavior. It has the entire pedestrian set available to help with the 
 * selection.
 */
class Selector
{
    public:
        explicit Selector(SimulationContext *simulationContext);
        virtual bool select(int pedestrianIndex, const ObstacleSet& obstacleSet, const Goals& goals) = 0;
        virtual void initialize();

    protected:
        SimulationContext *getSimulationContext();
    
    private:
        SimulationContext *simulationContext;
};

#endif