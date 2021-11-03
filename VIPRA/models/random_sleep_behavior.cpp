#include <cmath>
#include <iostream>
#include "random_sleep_behavior.hpp"
#include "../definitions/movement_definitions.hpp"
#include "../entity_sets/calm_pedestrian_set.hpp"
#include "../dsl/selectors/id_ratio_selector.hpp"
#include "../dsl/transitions/transition.hpp"
#include "../dsl/conditions/and_condition.hpp"
#include "../dsl/conditions/elapsed_time_condition.hpp"
#include "../dsl/conditions/state_condition.hpp"

static const int AWAKE = 0;
static const int SLEEPING = 1;

RandomSleepBehavior::RandomSleepBehavior()
{
    this->simulationContext.elapsedSeconds = 0.0f;
    this->timeBetweenNapsSeconds = 120;
    this->lengthOfNapSeconds = 120;

    this->simulationContext.states = &(this->states);

    // Simulate states being added programmatically here. These calls will be made as the DSL file is parsed.
    this->addStateDefinition("AWAKE");    // INDEX 0
    this->addStateDefinition("SLEEPING"); // INDEX 1

    // Simulate selector rules being added programmatically here. These will be done by the DSL.
    // e.g., "x% of people are subject to randomly falling asleep"
    // This selector is one of many possibilities that we can add. For example, we can add a 
    // RandomSelector implementation that will select the percentage of the population at random.

    // TODO Add sim context on the HBM and track lifecycle
    this->addSelector(new IdRatioSelector(&(this->simulationContext), 2.0 / 100.0));

    this->addTransition
    (
        new Transition
        (   
            &(this->simulationContext),
            new AndCondition
            (
                &(this->simulationContext),
                new StateCondition(&(this->simulationContext), AWAKE),
                new ElapsedTimeCondition(&(this->simulationContext), 120.0)
            ),
            SLEEPING
        )
    );

    this->addTransition
    (
        new Transition
        (
            &(this->simulationContext),
            new AndCondition
            (
                &(this->simulationContext),
                new StateCondition(&(this->simulationContext), SLEEPING),
                new ElapsedTimeCondition(&(this->simulationContext), 120.0)
            ),
            AWAKE
        )
    );

    /*

    this->addStateAction("SLEEPING", new StopMovementAction());

    // Signify that this HBM should override the fields for a specific pedestrian if they are in a sleeping state.
    this->addDecider(new StateCondition("SLEEPING"));

    // So a selector tells the Behavioral model to evaluate this person. A decider indicates that this person is 
    // deciding to be subject to this specific behavior.
    */
}

void RandomSleepBehavior::initialize(PedestrianSet *pedestrianSet)
{
    int numPedestrians = pedestrianSet->getNumPedestrians();
    this->states.resize(numPedestrians, 0);
    this->simulationContext.transitionPointSeconds.resize(numPedestrians, 0);

    this->simulationContext.pedestrianSet = pedestrianSet;
}

void RandomSleepBehavior::update(FLOATING_NUMBER timestep)
{
    this->simulationContext.elapsedSeconds += timestep;
}

bool RandomSleepBehavior::select(PedestrianSet *pedestrianSet, int pedestrianIndex)
{

    bool selected = false;
    for (auto selector = this->selectors.begin();
         !selected && selector != this->selectors.end();
         selector++)
    {
        selected = (*selector)->select(pedestrianIndex);
    }

    return selected;
}

bool RandomSleepBehavior::decide(PedestrianSet *pedestrianSet, int pedestrianIndex)
{
    int pedestrianId = pedestrianSet->getIds()->at(pedestrianIndex);

    // We only overwrite the speed/velocity when this pedestrian is sleeping
    return this->states.at(pedestrianId) == SLEEPING;
}

void RandomSleepBehavior::act(PedestrianSet *pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep)
{
    static const Dimensions STOPPED = Dimensions
    {
        std::vector < FLOATING_NUMBER > {0, 0, 0}
    };

    int pedestrianId = pedestrianSet->getIds()->at(pedestrianIndex);

    // This person is subject to human behaviors for this cycle.
    FLOATING_NUMBER lastTransitionMs = this->simulationContext.elapsedSeconds - this->simulationContext.transitionPointSeconds.at(pedestrianId);

    CalmPedestrianSet *calmPedestrianSet = dynamic_cast<CalmPedestrianSet *>(pedestrianSet);

    // First phase: set the state transition
    bool transitioned = false;
    for (auto transition = this->transitions.begin();
         !transitioned && transition != this->transitions.end();
         ++transition)
    {
        if ((*transition)->evaluateTransition(pedestrianIndex))
        {
            std::cout 
                << "Person with id " << pedestrianId 
                << " has transitioned to " << this->states.at(pedestrianId) 
                << std::endl;
            transitioned = true;
        }
    }

    // if (this->states.at(pedestrianId) == AWAKE &&
    //     lastTransitionMs > timeBetweenNapsSeconds)
    // {
    //     // Set their state
    //     transitionState(pedestrianId, SLEEPING);

    //     std::cout << "Person with id " << pedestrianId << " has transitioned to SLEEPING" << std::endl;

    // }
    // else if (this->states.at(pedestrianId) == SLEEPING &&
    //     lastTransitionMs > lengthOfNapSeconds)
    // {
    //     // They are done with their 120 second nap, so wake them up. They will begin walking again next simulation cycle.
    //     transitionState(pedestrianId, AWAKE);

    //     std::cout << "Person with id " << pedestrianId << " has transitioned to AWAKE" << std::endl;
    // }

    // Second phase: perform the actions
    if (this->states.at(pedestrianId) == SLEEPING)
    {
        // Stop their speed
        pedestrianSet->getVelocities()->at(pedestrianIndex) = STOPPED;
        pedestrianSet->getSpeeds()->at(pedestrianIndex) = 0;
    }
}

// void RandomSleepBehavior::transitionState(int pedestrianId, int newState)
// {
//     this->states.at(pedestrianId) = newState;
//     this->simulationContext.transitionPointSeconds.at(pedestrianId) = this->simulationContext.elapsedSeconds;
// }

void RandomSleepBehavior::addSelector(Selector *selector)
{
    this->selectors.push_back(selector);
}

void RandomSleepBehavior::addTransition(Transition *transition)
{
    this->transitions.push_back(transition);
}
