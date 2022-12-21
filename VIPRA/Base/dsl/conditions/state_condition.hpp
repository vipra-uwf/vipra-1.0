#ifndef STATE_CONDITION_HPP
#define STATE_CONDITION_HPP

#include "../simulation_context.hpp"
#include "condition.hpp"

/**
 * A condition that evaluates whether or not the pedestrian at the current
 * index is at a particular state (as defined by the behavior file).
 */
class StateCondition : public Condition {
 public:
  StateCondition(SimulationContext* simulationContext, VIPRA::stateUID desiredState);
  bool evaluate(const ObstacleSet&   obsSet,
                const PedestrianSet& pedestrianSet,
                const Goals&         goals,
                VIPRA::idx           pedestrianIndex) override;

 private:
  VIPRA::stateUID desiredState;
};

#endif