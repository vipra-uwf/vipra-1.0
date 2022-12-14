#include "and_condition.hpp"

AndCondition::AndCondition(SimulationContext *simulationContext, Condition *lhs, Condition *rhs)
    : Condition(simulationContext)
{
    this->lhs = lhs;
    this->rhs = rhs;
}

bool AndCondition::evaluate(int pedestrianIndex, const PedestrianSet& pedestrianSet)
{
    bool evaluation = this->lhs->evaluate(pedestrianIndex, pedestrianSet) && 
        this->rhs->evaluate(pedestrianIndex, pedestrianSet);

    return evaluation;
}
