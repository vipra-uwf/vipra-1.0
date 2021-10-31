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

bool RandomSleepBehavior::decide(PedestrianSet *pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep)
{
    int pedestrianId = pedestrianSet->getIds()->at(pedestrianIndex);

    // This is an example of the condition that would be provided by the HBM DSL. Hard-coded here for now.
    bool condition = pedestrianId % 50 == 0;

    return condition;
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

    // Define the transition rules here. The intention is for this to be defined externally in a HBM.
    if ((currentMovementState == MovementDefinitions::PED_DYNAM || currentMovementState == MovementDefinitions::STOP) &&
        this->states.at(pedestrianId) == AWAKE &&
        (lastTransitionMs == timestep || lastTransitionMs > timeBetweenNapsSeconds))
    {
        // Stop their speed
        pedestrianSet->getVelocities()->at(pedestrianIndex) = STOPPED;
        pedestrianSet->getSpeeds()->at(pedestrianIndex) = 0;

        // Set their state
        this->states.at(pedestrianId) = SLEEPING;
        this->transitionPointSeconds.at(pedestrianId) = this->elapsedSeconds;

        std::cout << "Person with id " << pedestrianId << " is now being controlled by the Human Behavior Model" << std::endl;

        // Signify that they are being governed by the HBM now
        calmPedestrianSet->getMovementStates()->at(pedestrianIndex) = MovementDefinitions::HUMAN;

    }
    else if (currentMovementState == MovementDefinitions::HUMAN && 
        this->states.at(pedestrianId) == SLEEPING &&
        lastTransitionMs > lengthOfNapSeconds)
    {
        // They are done with their 120 second nap, so wake them up. They will begin walking again next simulation cycle.
        this->states.at(pedestrianId) = AWAKE;
        this->transitionPointSeconds.at(pedestrianId) = this->elapsedSeconds;

        std::cout << "Person with id " << pedestrianId << " is now being controlled by the Pedestrian Dynamics Model" << std::endl;
        calmPedestrianSet->getMovementStates()->at(pedestrianIndex) = MovementDefinitions::STOP;
    }

    if (this->states.at(pedestrianIndex) == SLEEPING)
    {
        // Stop their speed
        pedestrianSet->getVelocities()->at(pedestrianIndex) = STOPPED;
        pedestrianSet->getSpeeds()->at(pedestrianIndex) = 0;
    }
}
