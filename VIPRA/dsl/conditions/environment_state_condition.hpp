//
// Created by joe on 12/1/21.
//

#ifndef VIPRA_ENVIRONMENT_STATE_CONDITION_HPP
#define VIPRA_ENVIRONMENT_STATE_CONDITION_HPP


#include "condition.hpp"

class EnvironmentStateCondition
        : public Condition
{
    public:
        explicit EnvironmentStateCondition(SimulationContext *simulationContext, int state);
        bool evaluate(int pedestrianIndex) override;

    private:
        int desiredState;
};


#endif //VIPRA_ENVIRONMENT_STATE_CONDITION_HPP
