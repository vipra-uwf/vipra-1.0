#include "action.hpp"

Action::Action(SimulationContext *simulationContext)
{
    this->simulationContext = simulationContext;
}

SimulationContext *Action::getSimulationContext()
{
    return this->simulationContext;
}