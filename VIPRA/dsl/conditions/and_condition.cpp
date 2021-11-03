#include "and_condition.hpp"

AndCondition::AndCondition(SimulationContext *simulationContext, Condition *lhs, Condition *rhs)
    : Condition(simulationContext)
{
    this->lhs = lhs;
    this->rhs = rhs;
}

bool AndCondition::evaluate(int pedestrianIndex)
{
    bool evaluation = this->lhs->evaluate(pedestrianIndex) && 
        this->rhs->evaluate(pedestrianIndex);

    return evaluation;
}
