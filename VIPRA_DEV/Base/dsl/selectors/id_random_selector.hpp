#ifndef ID_RANDOM_SELECTOR_HPP
#define ID_RANDOM_SELECTOR_HPP

#include <ctime>

#include "selector.hpp"
#include "../../definitions/type_definitions.hpp"

/**
 * Select the pedestrian based on a specified ratio. Useful for behaviors that
 * are selected by a certain percent of the population. This uses a random
 * algorithm with an optional seed parameter for determinism.
 */
class IdRandomSelector: public Selector
{
    public:
        IdRandomSelector(SimulationContext *simulationContext, FLOATING_NUMBER ratio);
        IdRandomSelector(SimulationContext *simulationContext, FLOATING_NUMBER ratio, unsigned int seed);
        void initialize() override;

    protected:
        bool select(int pedestrianIndex) override;

    private:
        std::vector<int> selectedPedestrianIds;
        FLOATING_NUMBER ratio;
        void selectPedestrianIds();
};


#endif //ID_RANDOM_SELECTOR_HPP
