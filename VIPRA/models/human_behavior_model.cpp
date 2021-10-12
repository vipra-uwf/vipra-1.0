//
// Created by joe on 8/3/21.
//

#include "../entity_sets/calm_pedestrian_set.hpp" // TODO not very cleanly separated
#include "human_behavior_model.hpp"
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>

HumanBehaviorModel::HumanBehaviorModel()
{
    this->elapsedMs = 0.0f;
}

void HumanBehaviorModel::setData(Data *initialData)
{
    this->data = initialData;
}

Data *HumanBehaviorModel::getData()
{
    return this->data;
}

void HumanBehaviorModel::setGoals(Goals *goals)
{
    this->goals = goals;
}

Goals *HumanBehaviorModel::getGoals()
{
    return this->goals;
}

/**
 * Decide if this pedestrian is chosen in this iteration to be evaluated by the HBM.
 */
bool HumanBehaviorModel::isChosen(int pedestrianIndex)
{
    int pedestrianId = this->data->getPedestrianSet()->getIds()->at(pedestrianIndex);

    // This is an example of the condition that would be provided by the HBM DSL. Hard-coded here for now.
    bool condition = pedestrianId % 50 == 0;

    return condition;
}

void HumanBehaviorModel::update(FLOATING_NUMBER timestep)
{
    static const Dimensions STOPPED = Dimensions
    {
        std::vector < FLOATING_NUMBER > {0, 0, 0}
    };

    this->elapsedMs += timestep;

    // Dynamic cast to a CALM pedestrian set since we need access to the current movement states. 
    // This will be moved to the parent class in the future.
    CalmPedestrianSet * calmPedestrianSet = dynamic_cast<CalmPedestrianSet*>(this->getData()->getPedestrianSet());
    // PedestrianSet *calmPedestrianSet = this->getData()->getPedestrianSet();

    // Iterate through the pedestrian list. If there's someone that is in a "sleep" state make sure their velocity remains 0.
    for (int i = 0; i < calmPedestrianSet->getNumPedestrians(); ++i)
    {
        int pedestrianId = calmPedestrianSet->getIds()->at(i);

        if (isChosen(i))
        {
            // This person is subject to human behaviors for this cycle.
            FLOATING_NUMBER lastTransitionMs = this->elapsedMs - this->transitionPointMs.at(pedestrianId);

            MovementDefinitions currentMovementState = calmPedestrianSet->getMovementStates()->at(i);

            // Define the transition rules here. The intention is for this to be defined externally in a HBM.
            if ((currentMovementState == MovementDefinitions::PED_DYNAM || currentMovementState == MovementDefinitions::STOP) &&
                this->states.at(pedestrianId) == BehaviorDefinitions::AWAKE &&
                (lastTransitionMs == timestep || lastTransitionMs > 3600))
            {
                // Stop their speed
                this->data->getPedestrianSet()->getVelocities()->at(i) = STOPPED;
                this->data->getPedestrianSet()->getSpeeds()->at(i) = 0;

                // Set their state
                this->states.at(pedestrianId) = BehaviorDefinitions::SLEEPING;
                this->transitionPointMs.at(pedestrianId) = this->elapsedMs;

                std::cout << "Person with id " << pedestrianId << " is now being controlled by the Human Behavior Model" << std::endl;

                // Signify that they are being governed by the HBM now
                calmPedestrianSet->getMovementStates()->at(i) = MovementDefinitions::HUMAN;

            }
            else if (currentMovementState == MovementDefinitions::HUMAN && 
                this->states.at(pedestrianId) == BehaviorDefinitions::SLEEPING &&
                lastTransitionMs > 120)
            {
                // They are done with their 120 second nap, so wake them up. They will begin walking again next simulation cycle.
                this->states.at(pedestrianId) = BehaviorDefinitions::AWAKE;
                this->transitionPointMs.at(pedestrianId) = this->elapsedMs;

                std::cout << "Person with id " << pedestrianId << " is now being controlled by the Pedestrian Dynamics Model" << std::endl;
                calmPedestrianSet->getMovementStates()->at(i) = MovementDefinitions::STOP;
            }

            if (this->states.at(i) == BehaviorDefinitions::SLEEPING)
            {
                // Stop their speed
                this->data->getPedestrianSet()->getVelocities()->at(i) = STOPPED;
                this->data->getPedestrianSet()->getSpeeds()->at(i) = 0;
            }
        }
    }
}

void HumanBehaviorModel::configure(CONFIG_MAP *configMap)
{
    // Nothing to configure, but needs to be defined anyway
}

/**
 * Initialize this model after the pedestrian set has been read in.
 */
void HumanBehaviorModel::initialize()
{
    int numPedestrians = this->data->getPedestrianSet()->getNumPedestrians();
    for (int i = 0; i < numPedestrians; ++i)
    {
        this->states.push_back(BehaviorDefinitions::AWAKE);
        this->transitionPointMs.push_back(0);
    }
}
