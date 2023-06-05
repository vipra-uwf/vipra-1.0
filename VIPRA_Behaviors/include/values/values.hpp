#ifndef VIPRA_BEHAVIORS_VALUES_HPP
#define VIPRA_BEHAVIORS_VALUES_HPP

#include <generated/BehaviorParser.h>

#include <time/time.hpp>
#include "behavior/exceptions.hpp"


namespace BHVR {
using RandomVal = std::pair<float, float>;
using RangeVal = std::pair<float, float>;
[[nodiscard]] inline float collapseRandomValue(BHVR::RandomVal) {}

[[nodiscard]] inline BHVR::RangeVal getRange(BehaviorParser::Value_rangeContext* ctx) {}


[[nodiscard]] inline BHVR::RandomVal getRandom(BehaviorParser::Value_randomContext* ctx) {}


[[nodiscard]] inline BHVR::Duration getDuration(BehaviorParser::DurationContext* ctx) {
  // TODO(rolland)
}


/**
 * @brief Gets a single value from a value context, collapsing randoms and ranges
 * 
 * @param value : 
 * @return float 
 */
[[nodiscard]] inline float getValue(BehaviorParser::ValueContext* value) {

  if (value->value_number()) {
    auto* val = value->value_number();
    if (val->FLOAT()) {
      return std::stof(val->FLOAT()->toString());
    }

    if (val->NUMBER()) {
      return std::stof(val->NUMBER()->toString());
    }
  }

  if (value->value_random()) {
    auto* ctx = value->value_random();
    return collapseRandomValue(getRandom(ctx));
  }

  if (value->value_range()) {
    auto* ctx = value->value_range();
    return collapseRandomValue(getRange(ctx));
  }

  return -1;
}
}  // namespace BHVR


#endif