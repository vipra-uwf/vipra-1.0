#ifndef VIPRA_SUBCONDITION_EVENT_ONE_TIME_HPP
#define VIPRA_SUBCONDITION_EVENT_ONE_TIME_HPP

#include <conditions/sub_condition.hpp>
#include <events/event.hpp>

namespace BHVR {
class SubConditionEventOneTime {
 public:
  SubConditionEventOneTime(bool, Event*);
  SubConditionEventOneTime() = delete;
  SubConditionEventOneTime(const SubConditionEventOneTime&) = default;
  SubConditionEventOneTime& operator=(const SubConditionEventOneTime&) = default;
  SubConditionEventOneTime(SubConditionEventOneTime&&) noexcept = default;
  SubConditionEventOneTime& operator=(SubConditionEventOneTime&&) noexcept = default;


  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx,
                  VIPRA::delta_t);

 private:
  bool         onStart;
  bool         hasReturned;
  const Event* event;
};
}  // namespace BHVR

#endif