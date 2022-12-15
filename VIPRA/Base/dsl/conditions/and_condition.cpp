#include "and_condition.hpp"

AndCondition::AndCondition(SimulationContext* simulationContext, Condition* lhs, Condition* rhs)
  : Condition(simulationContext) {
  this->lhs = lhs;
  this->rhs = rhs;
}

bool
AndCondition::evaluate(const ObstacleSet&   obsSet,
                       const PedestrianSet& pedestrianSet,
                       const Goals&         goals,
                       int                  pedestrianIndex) {
  bool evaluation = this->lhs->evaluate(obsSet, pedestrianSet, goals, pedestrianIndex) &&
                    this->rhs->evaluate(obsSet, pedestrianSet, goals, pedestrianIndex);

  return evaluation;
}
