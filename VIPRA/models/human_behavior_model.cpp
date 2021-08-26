//
// Created by joe on 8/3/21.
//

#include "human_behavior_model.hpp"
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>

HumanBehaviorModel::HumanBehaviorModel()
{
    this->STOPPED = Dimensions
    {
        std::vector < FLOATING_NUMBER > {0, 0, 0}
    };

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

const std::string currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void HumanBehaviorModel::update(FLOATING_NUMBER timestep)
{

    // Hack to initialize local states. For some reason this isn't working in the configure step. TODO
    bool initialize = (this->states.size() == 0);

    // TODO: it's not clear how this is milliseconds when the timestamp size is 0.005. Get clarification on this.
    // TODO: timestep is a float, but elapsed msec is an unsigned long. Doesn't seem to be right.
    // Basically we need to know how the human behavior model interacts with the simulation clock in order to solve the
    // problem of extending our base listener to build this out via the DSL.
    // Observations:
    // - Assumption that 0.005 seconds == 1 second of simulation is false. A full hour passes between each boarding zone, which is incorrect.
    // - Assumption that 0.005 seconds == 0.005 seconds of simulation is under investigation. 
    this->elapsedMs += timestep;

    static int print_index = 0;
    print_index++;
    if (print_index % 1000 == 0)
    {
        std::cout << "DEBUG: Elapsed time sec = " << this->elapsedMs << std::endl;
    }

    // These should be defined in the DSL. Define them here for now.
    int const AWAKE = 0;
    int const SLEEPING = 1;

    // Iterate through the pedestrian list. If there's someone that is in a "sleep" state make sure their velocity remains 0.
    for (int i = 0; i < this->data->getPedestrianSet()->getNumPedestrians(); ++i)
    {

        if (initialize)
        {
            this->states.push_back(AWAKE);
            this->transitionPointMs.push_back(this->elapsedMs);
            this->preTransitionVelocities.push_back(this->data->getPedestrianSet()->getVelocities()->at(i));
        }

        if (i % 50 == 0) // 2% of people
        {
            FLOATING_NUMBER lastTransitionMs = this->elapsedMs - this->transitionPointMs.at(i);

            if (this->states.at(i) == AWAKE && (initialize || lastTransitionMs > 3600))
            {
                std::cout << "Person at index " << i << " is now sleeping for 2 minutes" << std::endl;

                // This is setting their state to 1, which is sleep. We need to find a way to set this back to 0 when they wake up.
                // This requires storing arbitrary data per-user (so we can track how long they've been asleep).
                this->preTransitionVelocities.at(i) = this->data->getPedestrianSet()->getVelocities()->at(i);
                this->states.at(i) = SLEEPING;
                this->transitionPointMs.at(i) = this->elapsedMs;
            }
            else if (this->states.at(i) == SLEEPING && lastTransitionMs > 120)
            {
                std::cout << "Person at index " << i << " has woken up and will stay awake for another hour" << std::endl;
                // They are done with their 120 second nap, so wake them up. They will begin walking again next simulation cycle.
                this->states.at(i) = AWAKE;
                this->transitionPointMs.at(i) = this->elapsedMs;

                // // Set them back to their previous speed
                // Dimensions newVelocity = this->preTransitionVelocities.at(i);
                // FLOATING_NUMBER newSpeed = (newVelocity.coordinates[0] * newVelocity.coordinates[0]) +
                //                            (newVelocity.coordinates[1] * newVelocity.coordinates[1]);

                // std::cout << "DEBUG: Setting new speed to " << newSpeed << std::endl; 

                // this->data->getPedestrianSet()->getVelocities()->at(i) = newVelocity;
                // this->data->getPedestrianSet()->getSpeeds()->at(i) = newSpeed;
            }

            if (this->states.at(i) == SLEEPING)
            {
                // Stop their speed
                // this->data->getPedestrianSet()->getVelocities()->at(i) = this->STOPPED;
                // this->data->getPedestrianSet()->getSpeeds()->at(i) = 0;

                // TODO Here's the problem with this approach:
                // CALM model will compute the desired velocity/speed on every update state, and then _immediately_ compute the new position.
                // We don't have a hook in place to override this value for the purposes of affecting the speed of a person. We either need
                // access to the movement state by putting it in the parent class, or we need another way to stop a person.
                //
                // Also TODO: Ask about the "HUMAN" movement state. It would certainly make sense that it would work in this case.
                // New goal for this: specify the sleep time and states inside the DSL. That's all.
            }
        }
    }
}

void HumanBehaviorModel::configure(CONFIG_MAP *configMap)
{
    // for (int i = 0; i < this->data->getPedestrianSet()->getNumPedestrians(); ++i)
    // {
    //     // Set the initial state of the user to 0 (no state)
    //     this->states.push_back(0);
    // }
    // Nothing to configure, but needs to be defined anyway
}