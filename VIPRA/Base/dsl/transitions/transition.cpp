//
// Created by joe on 12/5/21.
//

#include "transition.hpp"

Transition::Transition(SimulationContext* simContext, Condition* cond, VIPRA::stateUID nextState)
  : simulationContext(simContext), condition(cond), newState(nextState) {}
