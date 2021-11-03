#ifndef CONDITION_HPP
#define CONDITION_HPP

#include "../entity_sets/pedestrian_set.hpp"

// Idea: we pass in a context object that has everything we need. I'm thinking we call this something that won't
// be confused with the generated DSL context.
class Condition
{
    public:
        bool evaluate(PedestrianSet *pedestrianSet, std::vector<std::string> *states, int pedestrianIndex);

};

#endif
