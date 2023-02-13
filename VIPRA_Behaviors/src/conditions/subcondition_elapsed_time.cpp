
#include <conditions/subconditions/subcondition_elapsed_time.hpp>

SubCondition_Elapsed_Time::SubCondition_Elapsed_Time(VIPRA::delta_t time) : requiredTime(time) {}

bool
SubCondition_Elapsed_Time::operator()(const PedestrianSet&,
                                      const ObstacleSet&,
                                      const Goals&,
                                      const BehaviorContext&,
                                      VIPRA::idx,
                                      VIPRA::delta_t) const {
  return true;
}