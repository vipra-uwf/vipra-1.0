#ifndef EVERYONE_SELECTOR_HPP
#define EVERYONE_SELECTOR_HPP

#include "selector.hpp"
#include "../../definitions/type_definitions.hpp"

/**
 * Select every pedestrian for this behavior
 */ 
class EveryoneSelector: public Selector
{
    public:
        explicit EveryoneSelector(SimulationContext *simulationContext);
        bool select(int pedestrianIndex) override;
};

#endif