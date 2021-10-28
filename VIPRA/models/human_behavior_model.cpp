//
// Created by joe on 8/3/21.
//

#include "human_behavior_model.hpp"
#include "human_behavior.hpp"
#include "random_sleep_behavior.hpp"

HumanBehaviorModel::HumanBehaviorModel()
{
    this->humanBehavior = new RandomSleepBehavior();
}

HumanBehaviorModel::~HumanBehaviorModel()
{
    delete this->humanBehavior;
}

void HumanBehaviorModel::setData(Data *initialData)
{
    this->data = initialData;
}

Data *HumanBehaviorModel::getData()
{
    return this->data;
}

void HumanBehaviorModel::update(FLOATING_NUMBER timestep)
{
    this->humanBehavior->update(timestep);

    // Iterate through the pedestrian list and apply our behavior to it.
    PedestrianSet *pedestrianSet = this->getData()->getPedestrianSet();
    for (int i = 0; i < pedestrianSet->getNumPedestrians(); ++i)
    {
        if (this->humanBehavior->decide(pedestrianSet, i, timestep))
        {
            this->humanBehavior->act(pedestrianSet, i, timestep);
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
    this->humanBehavior->initialize(this->getData()->getPedestrianSet());
}
