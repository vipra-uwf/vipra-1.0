#ifndef SIMULATION_CONTEXT_HPP
#define SIMULATION_CONTEXT_HPP

#include "../entity_sets/pedestrian_set.hpp"

/**
 * Holder object for pedestrian set and states vector. Used for actions, conditions, and selectors in the DSL.
 */
struct SimulationContext
{
    PedestrianSet *pedestrianSet;
    std::vector<int> *states;
};

#endif