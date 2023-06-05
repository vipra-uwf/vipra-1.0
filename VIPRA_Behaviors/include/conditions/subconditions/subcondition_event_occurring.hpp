#ifndef VIPRA_SUBCONDITION_EVENT_OCCURRING_HPP
#define VIPRA_SUBCONDITION_EVENT_OCCURRING_HPP

#include <conditions/sub_condition.hpp>
#include <events/event.hpp>

namespace BHVR {
class SubConditionEventOccurring {
 public:
  explicit SubConditionEventOccurring(VIPRA::idx);

  bool operator()(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::idx,
                  VIPRA::delta_t) const;

 private:
  VIPRA::idx event;

 public:
  ~SubConditionEventOccurring() = default;
  SubConditionEventOccurring() = delete;
  SubConditionEventOccurring(const SubConditionEventOccurring&) = default;
  SubConditionEventOccurring& operator=(const SubConditionEventOccurring&) = default;
  SubConditionEventOccurring(SubConditionEventOccurring&&) noexcept = default;
  SubConditionEventOccurring& operator=(SubConditionEventOccurring&&) noexcept = default;
};
}  // namespace BHVR

#endif