#ifndef VIPRA_CONDITION_STATE
#define VIPRA_CONDITION_STATE

#include "../sub_condition.hpp"
#include "definitions/dsl_types.hpp"

class condition_state : public SubCondition {
 public:
  condition_state(VIPRA::stateUID);
  bool operator()(const ObstacleSet&, const PedestrianSet&, const Goals&, const BehaviorContext&, VIPRA::idx) const override;

 private:
  VIPRA::stateUID cond_State;
};

#endif