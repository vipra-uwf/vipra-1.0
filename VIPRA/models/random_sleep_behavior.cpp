#include <cmath>
#include <iostream>
#include "random_sleep_behavior.hpp"
#include "../definitions/movement_definitions.hpp"
#include "../entity_sets/calm_pedestrian_set.hpp"

static const int AWAKE = 0;
static const int SLEEPING = 1;

RandomSleepBehavior::RandomSleepBehavior()
{
    this->elapsedSeconds = 0.0f;
    this->timeBetweenNapsSeconds = 3600;
    this->lengthOfNapSeconds = 120;

    // Simulate states being added programmatically here. These calls will be made as the DSL file is parsed.
    this->addStateDefinition("AWAKE");    // INDEX 0
    this->addStateDefinition("SLEEPING"); // INDEX 1

    // Simulate selector rules being added programmatically here. These will be done by the DSL.
    // e.g., "x% of people are subject to randomly falling asleep"
    // This selector is one of many possibilities that we can add. For example, we can add a 
    // RandomSelector implementation that will select the percentage of the population at random.
    this->setRatioSelected(2.0 / 100.0);

    /*
    Here's an example of what I'm thinking:
    this->addStateDefinition("AWAKE");
    this->addStateDefinition("SLEEPING");

    this->addSelector(new PersonIdRatioCondition(2.0 / 100.0));

    this->addTransition(new AndCondition(new StateCondition("AWAKE"), new ElapsedTimeCondition(3600)), "SLEEPING");
    this->addTransition(new AndCondition(new StateCondition("SLEEPING"), new ElapsedTimeCondition(120)), "AWAKE");

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
    this->transitionPointSeconds.resize(numPedestrians, 0);
}

void RandomSleepBehavior::update(FLOATING_NUMBER timestep)
{
    this->elapsedSeconds += timestep;
}

bool RandomSleepBehavior::select(PedestrianSet *pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep)
{
    int pedestrianId = pedestrianSet->getIds()->at(pedestrianIndex);

    // For this behavior we're given a percent selected. We multiply this by the precision we want to support,
    // and use modulos to determine if the given pedestrian is affected.
    static const int divisor = static_cast<int>((100.0 / this->getRatioSelected()) / 100.0);

    bool condition = pedestrianId % divisor == 0;

    return condition;
}

bool RandomSleepBehavior::decide(PedestrianSet *pedestrianSet, int pedestrianIndex)
{
    // We only overwrite the speed/velocity when this pedestrian is sleeping
    return this->states.at(pedestrianIndex) == SLEEPING;
}

void RandomSleepBehavior::act(PedestrianSet *pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep)
{
    static const Dimensions STOPPED = Dimensions
    {
        std::vector < FLOATING_NUMBER > {0, 0, 0}
    };

    int pedestrianId = pedestrianSet->getIds()->at(pedestrianIndex);

    // This person is subject to human behaviors for this cycle.
    FLOATING_NUMBER lastTransitionMs = this->elapsedSeconds - this->transitionPointSeconds.at(pedestrianId);

    CalmPedestrianSet *calmPedestrianSet = dynamic_cast<CalmPedestrianSet *>(pedestrianSet);

    MovementDefinitions currentMovementState = calmPedestrianSet->getMovementStates()->at(pedestrianIndex);

    // First phase: set the state transition
    if (this->states.at(pedestrianId) == AWAKE &&
        (lastTransitionMs == timestep || lastTransitionMs > timeBetweenNapsSeconds))
    {
        // Set their state
        transitionState(pedestrianId, SLEEPING);

        std::cout << "Person with id " << pedestrianId << " has transitioned to SLEEPING" << std::endl;

    }
    else if (this->states.at(pedestrianId) == SLEEPING &&
        lastTransitionMs > lengthOfNapSeconds)
    {
        // They are done with their 120 second nap, so wake them up. They will begin walking again next simulation cycle.
        transitionState(pedestrianId, AWAKE);

        std::cout << "Person with id " << pedestrianId << " has transitioned to AWAKE" << std::endl;
    }

    // Second phase: perform the actions
    if (this->states.at(pedestrianId) == SLEEPING)
    {
        // Stop their speed
        pedestrianSet->getVelocities()->at(pedestrianIndex) = STOPPED;
        pedestrianSet->getSpeeds()->at(pedestrianIndex) = 0;
    }
}

void RandomSleepBehavior::transitionState(int pedestrianId, int newState)
{
    this->states.at(pedestrianId) = newState;
    this->transitionPointSeconds.at(pedestrianId) = this->elapsedSeconds;
}
