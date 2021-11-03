#ifndef ELAPSED_TIME_CONDITION_HPP
#define ELAPSED_TIME_CONDITION_HPP

#include "condition.hpp"

class ElapsedTimeCondition: protected Condition
{
    public:
        ElapsedTimeCondition(SimulationContext *simulationContext, FLOATING_NUMBER desiredElapsedTime);
        bool evaluate(int pedestrianIndex);
    
    private:
        FLOATING_NUMBER desiredElapsedTime;
};

#endif