#ifndef ID_RATIO_SELECTOR_HPP
#define ID_RATIO_SELECTOR_HPP

#include "selector.hpp"
#include "../../definitions/type_definitions.hpp"

/**
 * Select the pedestrian based on a specified ratio. Useful for behaviors that 
 * are selected by a certain percent of the population.
 */ 
class IdRatioSelector: public Selector
{
    public:
        IdRatioSelector(FLOATING_NUMBER ratio);
        bool select(PedestrianSet *pedestrianSet, int pedestrianIndex);

    private:
        FLOATING_NUMBER ratio;
};

#endif