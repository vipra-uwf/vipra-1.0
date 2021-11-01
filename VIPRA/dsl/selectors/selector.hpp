#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include "../../entity_sets/pedestrian_set.hpp"

/**
 * A selector is used to decide if a pedestrian should be evaluated for a 
 * behavior. It has the entire pedestrian set available to help with the 
 * selection.
 */
class Selector
{
    public:
        virtual bool select(PedestrianSet *pedestrianSet, int pedestrianIndex) = 0;
};

#endif