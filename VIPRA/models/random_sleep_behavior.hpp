#ifndef RANDOM_SLEEP_BEHAVIOR_HPP
#define RANDOM_SLEEP_BEHAVIOR_HPP

#include "human_behavior.hpp"

/**
 * Strategy ideas:
 * The goal is to have the behaviors described/defined in a DSL. We need to specify the following:
 * - The states of SLEEPING/AWAKE
 * - The effect on the person's speed for each state
 *   - An AWAKE person does not change their speed
 *   - A SLEEPING person stops moving
 * - The transition rules for each state
 *   - A person will transition from AWAKE to SLEEPING after 3600 seconds
 *   - A person will transition from SLEEPING to AWAKE after 120 seconds
 * - How to decide if a person a subject to this behavior
 *   - 2% of pedestrians are subject to this behaivor
 **/

/**
 * Hard-coded behavior to describe someone randomly falling asleep for a fixed amount of time during the simulation.
 */
class RandomSleepBehavior: public HumanBehavior
{
    private:

        // These states are defined by the this behavior. Currently they are a hard-coded enumeration but future 
        // iterations will have these defined directly in the DSL.
        std::vector<int> states;

        // The timestamps for each person that transitions. This is used in the DSL state machine to define when a
        // person first entered the previous state, in case the rule is time-dependent (e.g., 30 minute nap).
        std::vector<FLOATING_NUMBER> transitionPointSeconds;


        // A store of the elapsed time for use in computations. This is updated in the behavior's update method.
        FLOATING_NUMBER elapsedSeconds;

        // Configuration parameters for this behavior specifically. Defaults are set in this behavior's constructor.
        int timeBetweenNapsSeconds;
        int lengthOfNapSeconds;

        // Convenience method to transition the state and track the transition points.
        void transitionState(int pedestrianId, int newState);


    public:
        RandomSleepBehavior();
        virtual ~RandomSleepBehavior() = default;

        void initialize(PedestrianSet *pedestrianSet);
        void update(FLOATING_NUMBER timestep);
        bool select(PedestrianSet *pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep);
        bool decide(PedestrianSet *pedestrianSet, int pedestrianIndex);
        void act(PedestrianSet *pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep);
};

#endif