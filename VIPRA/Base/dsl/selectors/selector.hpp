#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include "../simulation_context.hpp"
#include "../../../Extendable/pedestrianset/pedestrian_set.hpp"
#include "../../../Extendable/obstacleset/obstacle_set.hpp"
#include "../../../Extendable/goals/goals.hpp"

/**
 * A selector is used to decide if a pedestrian should be evaluated for a 
 * behavior. It has the entire pedestrian set available to help with the 
 * selection.
 */
class Selector
{
    public:
        explicit Selector(SimulationContext *simulationContext);
        virtual bool select(int pedestrianIndex, const ObstacleSet& obstacleSet, const Goals& goals, const PedestrianSet& pedestrianSet) = 0;
        virtual void initialize();

    protected:
        SimulationContext *getSimulationContext();
    
    private:
        SimulationContext *simulationContext;
};

#endif