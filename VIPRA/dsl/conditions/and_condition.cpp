#include "and_condition.hpp"

AndCondition::AndCondition(SimulationContext *simulationContext, Condition *lhs, Condition *rhs)
    : Condition(simulationContext)
{
    this->lhs = lhs;
    this->rhs = rhs;
}

bool AndCondition::evaluate(int pedestrianIndex)
{
    return 
        this->lhs->evaluate(pedestrianIndex) && 
        this->rhs->evaluate(pedestrianIndex);
}
