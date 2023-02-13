#ifndef VIPRA_CONDITION_STATE
#define VIPRA_CONDITION_STATE

#include <conditions/sub_condition.hpp>
#include <definitions/dsl_types.hpp>

class SubCondition_State : public SubCondition {
 public:
  SubCondition_State(VIPRA::stateUID, bool);
  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx, VIPRA::delta_t)
      const override;

 private:
  VIPRA::stateUID cond_State;
  bool            pedOrEnv;
};

#endif