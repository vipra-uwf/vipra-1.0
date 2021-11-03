#ifndef AND_CONDITION_HPP
#define AND_CONDITION_HPP

#include "condition.hpp"

class AndCondition: public Condition
{
    public:
        AndCondition(SimulationContext *simulationContext, Condition *lhs, Condition *rhs);
        bool evaluate(int pedestrianIndex);
    
    private:
        Condition *lhs;
        Condition *rhs;
};

#endif