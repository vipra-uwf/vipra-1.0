//
// Created by joe on 8/3/21.
//

#ifndef VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
#define VIPRA_HUMAN_BEHAVIOR_MODEL_HPP


#include "../simulation/data.hpp"
#include "../definitions/behavior_definitions.hpp"
#include "pedestrian_dynamics_model.hpp"
#include "../dsl/human_behavior.hpp"

/**
 * We define the Human Behavior Model to hold a pointer to the shared data object and wrap a single human behavior.
 * Eventually we want a list of human behaviors to model.
 */
class HumanBehaviorModel
{

    private:
        Data *data;

        std::vector <HumanBehavior *> humanBehaviors;

    protected:
        unsigned int seed;

    public:
        HumanBehaviorModel();
        virtual ~HumanBehaviorModel();
        virtual void configure(CONFIG_MAP* configMap);

        void setData(Data *initialData);
        Data *getData();

        virtual void initialize();
        void update(FLOATING_NUMBER time);

};


#endif //VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
