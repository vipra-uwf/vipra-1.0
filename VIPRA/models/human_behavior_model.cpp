//
// Created by joe on 8/3/21.
//

#include "../entity_sets/calm_pedestrian_set.hpp"
#include "human_behavior_model.hpp"
#include "dsl_human_behavior.hpp"

HumanBehaviorModel::HumanBehaviorModel()
{
    this->humanBehavior = new DslHumanBehavior();
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
    CalmPedestrianSet *calmPedestrianSet = dynamic_cast<CalmPedestrianSet *>(this->getData()->getPedestrianSet());
    for (int i = 0; i < calmPedestrianSet->getNumPedestrians(); ++i)
    {
        if (this->humanBehavior->select(calmPedestrianSet, i))
        {
            this->humanBehavior->act(calmPedestrianSet, i, timestep);

            // If this behavior has decided that it will override the default, set the movement state.
            // Note that this will look different once the HBM has its own copy of the data.
            if (this->humanBehavior->decide(calmPedestrianSet, i))
            {
                // Set the movement state to HUMAN to avoid the PDM overwriting our states
                calmPedestrianSet->getMovementStates()->at(i) = MovementDefinitions::HUMAN;
            }
            else
            {
                // Only set the movement state back to stop if it doesn't have something already.
                if (calmPedestrianSet->getMovementStates()->at(i) == MovementDefinitions::HUMAN)
                {
                    calmPedestrianSet->getMovementStates()->at(i) = MovementDefinitions::STOP;
                }
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
    this->humanBehavior->initialize(this->getData()->getPedestrianSet());
}
