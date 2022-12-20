#include "and_condition.hpp"

AndCondition::AndCondition(SimulationContext* simContext, Condition* leftCond, Condition* rightCond)
  : Condition(simContext) {
  this->lhs = leftCond;
  this->rhs = rightCond;
}

bool
AndCondition::evaluate(const ObstacleSet&   obsSet,
                       const PedestrianSet& pedestrianSet,
                       const Goals&         goals,
                       VIPRA::idx           pedestrianIndex) {
  bool evaluation = this->lhs->evaluate(obsSet, pedestrianSet, goals, pedestrianIndex) &&
                    this->rhs->evaluate(obsSet, pedestrianSet, goals, pedestrianIndex);

  return evaluation;
}
