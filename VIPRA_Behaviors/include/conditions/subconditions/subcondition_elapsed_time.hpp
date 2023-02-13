#ifndef VIPRA_SUBCONDITION_ELAPSED_TIME
#define VIPRA_SUBCONDITION_ELAPSED_TIME

#include <conditions/sub_condition.hpp>
#include <definitions/dsl_types.hpp>

class SubCondition_Elapsed_Time : public SubCondition {
 public:
  SubCondition_Elapsed_Time(VIPRA::delta_t);
  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx, VIPRA::delta_t)
      const override;

 private:
  VIPRA::delta_t requiredTime;
};

#endif