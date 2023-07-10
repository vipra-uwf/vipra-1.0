#ifndef VIPRA_BEHAVIORS_TIME_LATCH_HPP
#define VIPRA_BEHAVIORS_TIME_LATCH_HPP

#include <definitions/dsl_types.hpp>
#include <definitions/type_definitions.hpp>
#include <utility>
#include "spdlog/spdlog.h"
#include "values/numeric_value.hpp"

namespace BHVR {

class TimedLatchCollection;
class TimedLatchCollection {
 public:
  explicit TimedLatchCollection(BHVR::NumericValue value) : duration(std::move(value)) {}

  void resize(VIPRA::size latchCnt) { startTimes.resize(latchCnt, -1); }

  void latch(VIPRA::time_s startTime, VIPRA::idx pedIdx) {
    if (startTimes.at(pedIdx) == -1) {
      startTimes.at(pedIdx) = startTime;
    }
  }

  bool check(VIPRA::time_s currTime, VIPRA::idx pedIdx) {
    if (startTimes.at(pedIdx) == -1) return false;

    float val = duration.value(pedIdx);
    if (currTime - startTimes.at(pedIdx) >= val) {
      startTimes.at(pedIdx) = -1;
      return false;
    }

    return true;
  }

  float getDuration(VIPRA::idx pedIdx) { return duration.value(pedIdx); }

 private:
  BHVR::NumericValue         duration;
  std::vector<VIPRA::time_s> startTimes;

  static inline constexpr bool inTimeStep(VIPRA::time_s currTime, VIPRA::time_s checkTime,
                                          VIPRA::delta_t dT) {
    const VIPRA::delta_t left = checkTime - dT;
    const VIPRA::delta_t right = checkTime + dT;
    return (currTime > left && currTime < right);
  }
};
}  // namespace BHVR

#endif