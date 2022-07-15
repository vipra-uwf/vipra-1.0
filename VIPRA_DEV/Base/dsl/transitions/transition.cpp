//
// Created by joe on 12/5/21.
//

#include "transition.hpp"

Transition::Transition(SimulationContext *simulationContext, Condition *condition, int newState)
    : simulationContext(simulationContext), condition(condition), newState(newState)
{
}
