//
// Created by joe on 8/3/21.
//

#ifndef VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
#define VIPRA_HUMAN_BEHAVIOR_MODEL_HPP


#include "../simulation/data.hpp"
#include "../definitions/behavior_definitions.hpp"
#include "pedestrian_dynamics_model.hpp"

/**
 * We define the Human Behavior Model to hold a Data object and define an update method for now. The Data object should
 * contain enough information for the human behaviors to be defined.
 */
class HumanBehaviorModel
{

    private:
        Data *data;
        Goals *goals;

        // These states are defined by the behavior model. Currently they are a hard-coded enumeration but future 
        // iterations will have these defined directly in the DSL.
        std::vector<BehaviorDefinitions> states;


        // The timestamps for each person that transitions. This is used in the DSL state machine to define when a
        // person first entered the previous state, in case the rule is time-dependent (e.g., 30 minute nap).
        std::vector<FLOATING_NUMBER> transitionPointMs;

        FLOATING_NUMBER elapsedMs;

        bool isChosen(int pedestrianIndex);

    public:
        HumanBehaviorModel();
        explicit HumanBehaviorModel(Data *data);
        virtual void configure(CONFIG_MAP* configMap);

        void setData(Data *initialData);
        Data *getData();

        void setGoals(Goals *goals);
        Goals *getGoals();

        virtual void initialize();
        void update(FLOATING_NUMBER time);

};


#endif //VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
