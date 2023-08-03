#ifndef VIPRA_SUBCONDITION_ENTER
#define VIPRA_SUBCONDITION_ENTER

#include <conditions/sub_condition.hpp>
#include <definitions/dsl_types.hpp>
#include <definitions/type_definitions.hpp>
#include <events/event.hpp>
#include <time/time.hpp>
#include <util/timed_latch.hpp>
#include <values/numeric_value.hpp>
#include "definitions/sim_pack.hpp"

namespace BHVR {
class SubConditionEnter {
 public:
  explicit SubConditionEnter(VIPRA::idx);

  bool operator()(Simpack, VIPRA::idx, Target);

 private:
  VIPRA::idx        location;
  std::vector<bool> entered;

 public:
  ~SubConditionEnter() = default;
  SubConditionEnter(const SubConditionEnter&) = default;
  SubConditionEnter& operator=(const SubConditionEnter&) = default;
  SubConditionEnter(SubConditionEnter&&) noexcept = default;
  SubConditionEnter& operator=(SubConditionEnter&&) noexcept = default;
};
}  // namespace BHVR

#endif