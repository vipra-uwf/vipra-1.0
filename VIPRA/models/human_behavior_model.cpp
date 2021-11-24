//
// Created by joe on 8/3/21.
//

#include "../entity_sets/calm_pedestrian_set.hpp"
#include "human_behavior_model.hpp"
#include "../dsl/dsl_human_behavior.hpp"

HumanBehaviorModel::HumanBehaviorModel():
    data(nullptr),
    seed(time(nullptr))
{
}

HumanBehaviorModel::~HumanBehaviorModel()
{
    for (auto hb: this->humanBehaviors)
    {
        delete hb;
    }
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
    for (auto humanBehavior: this->humanBehaviors)
    {
        humanBehavior->update(timestep);
    }

    // Iterate through the pedestrian list and apply our behavior to it.
    auto *calmPedestrianSet = dynamic_cast<CalmPedestrianSet *>(this->getData()->getPedestrianSet());
    for (int i = 0; i < calmPedestrianSet->getNumPedestrians(); ++i)
    {
        bool behaviorDecided = false;
        for (auto humanBehavior: this->humanBehaviors)
        {
            if (humanBehavior->select(calmPedestrianSet, i))
            {
                humanBehavior->act(calmPedestrianSet, i, timestep);

                // If this behavior has decided that it will override the default, set the movement state.
                // Note that this will look different once the HBM has its own copy of the data.
                if (humanBehavior->decide(calmPedestrianSet, i))
                {
                    behaviorDecided = true;
                }
            }
        }

        if (behaviorDecided)
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

void HumanBehaviorModel::configure(CONFIG_MAP *configMap)
{
    for (const auto& config: (*configMap))
    {
        if (config.first.find("behavior#") != std::string::npos)
        {
            // This is a behavior, so add it to the human behaviors. The value is the filename.
            this->humanBehaviors.push_back(new DslHumanBehavior(config.second, this->seed));
        }

        if (config.first == "random_seed")
        {
            // Override the seed value for deterministic runs.
            this->seed = atoi(config.second.c_str());
        }
    }
}

/**
 * Initialize this model after the pedestrian set has been read in.
 */
void HumanBehaviorModel::initialize()
{
    for (auto humanBehavior: this->humanBehaviors)
    {
        humanBehavior->initialize(this->getData()->getPedestrianSet());
    }
}
