#ifndef RANDOM_SLEEP_BEHAVIOR_HPP
#define RANDOM_SLEEP_BEHAVIOR_HPP

#include "human_behavior.hpp"
#include "../dsl/actions/action.hpp"
#include "../dsl/selectors/selector.hpp"
#include "../dsl/transitions/transition.hpp"
#include "../dsl/simulation_context.hpp"

/**
 * Hard-coded behavior to describe someone randomly falling asleep for a fixed amount of time during the simulation.
 */
class RandomSleepBehavior: public HumanBehavior
{
    private:

        // Configuration parameters for this behavior specifically. Defaults are set in this behavior's constructor.
        int timeBetweenNapsSeconds;
        int lengthOfNapSeconds;


    public:
        RandomSleepBehavior();
        virtual ~RandomSleepBehavior() = default;
};

#endif