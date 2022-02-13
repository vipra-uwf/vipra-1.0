#ifndef ACTION_HPP
#define ACTION_HPP

#include "../simulation_context.hpp"

/**
 * An action is something the pedestrian does, such as stopping movement.
 */
class Action
{
    public:
        Action(SimulationContext *simulationContext, std::string actionName);
        virtual ~Action() = default;

        virtual void performAction(int pedestrianIndex) = 0;
        const std::string &getActionName() const;
        virtual void initialize();

    protected:
        virtual bool actionApplied(int pedestrianIndex);
        SimulationContext *getSimulationContext();
        std::string actionName;


    private:
        SimulationContext *simulationContext;
};

#endif