#ifndef VIPRA_SUBCONDITION_EVENT_HPP
#define VIPRA_SUBCONDITION_EVENT_HPP

#include <conditions/sub_condition.hpp>
#include <events/event.hpp>

namespace BHVR {
class SubConditionEventOccurred {
 public:
  explicit SubConditionEventOccurred(VIPRA::idx);
  SubConditionEventOccurred() = delete;
  SubConditionEventOccurred(const SubConditionEventOccurred&) = default;
  SubConditionEventOccurred& operator=(const SubConditionEventOccurred&) = default;
  SubConditionEventOccurred(SubConditionEventOccurred&&) noexcept = default;
  SubConditionEventOccurred& operator=(SubConditionEventOccurred&&) noexcept = default;



  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx,
                  VIPRA::delta_t) const;

 private:
  VIPRA::idx event;
};
}  // namespace BHVR

#endif