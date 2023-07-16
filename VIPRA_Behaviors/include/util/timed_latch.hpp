#ifndef VIPRA_BEHAVIORS_TIME_LATCH_HPP
#define VIPRA_BEHAVIORS_TIME_LATCH_HPP

#include <definitions/dsl_types.hpp>
#include <definitions/type_definitions.hpp>
#include <utility>
#include "spdlog/spdlog.h"
#include "values/numeric_value.hpp"

namespace BHVR {

/**
 * @brief Collection of timed latches, one for each pedestrian
 * @note Need to resize the collection to the correct number of pedestrians before use
 */
class TimedLatchCollection {
 public:
  explicit TimedLatchCollection(BHVR::NumericValue value) : duration(std::move(value)) {}

  /**
   * @brief Sets the amount of latches
   * 
   * @param latchCnt : number of pedestrians
   */
  void resize(VIPRA::size latchCnt) { startTimes.resize(latchCnt, -1); }

  /**
   * @brief Sets the pedestrians latch, it stays latched until the pedestrians duration time has passed. Subsequent calls do not reset the time for unlatching.
   * 
   * @param startTime : current simulation time
   * @param pedIdx : pedestrian latch to latch
   */
  void latch(VIPRA::time_s startTime, VIPRA::idx pedIdx) {
    if (startTimes.at(pedIdx) == -1) {
      startTimes.at(pedIdx) = startTime;
    }
  }

  /**
   * @brief Checks if the duration time has elapsed since the latch was toggled
   * 
   * @param currTime : current simulation time
   * @param pedIdx : pedestrian index to check
   * @return true, duration has not passed
   * @return false, latch not set or duration has passed
   */
  bool check(VIPRA::time_s currTime, VIPRA::idx pedIdx) {
    if (startTimes.at(pedIdx) == -1) return false;

    float val = duration.value(pedIdx);
    if (currTime - startTimes.at(pedIdx) >= val) {
      startTimes.at(pedIdx) = -1;
      return false;
    }

    return true;
  }

  /**
   * @brief Returns the duration value for the given ped
   * 
   * @param pedIdx : pedestrian index
   * @return float, duration time
   */
  float getDuration(VIPRA::idx pedIdx) { return duration.value(pedIdx); }

 private:
  BHVR::NumericValue         duration;
  std::vector<VIPRA::time_s> startTimes;

  /**
   * @brief Checks if the current time is within the duration
   * 
   * @param currTime : current simulation time
   * @param checkTime : time duration ends
   * @param dT : timestep size
   * @return true - in same timestep as duration end
   * @return false - not in same timestep as duration end
   */
  static inline constexpr bool inTimeStep(VIPRA::time_s currTime, VIPRA::time_s checkTime,
                                          VIPRA::delta_t dT) {
    const VIPRA::delta_t left = checkTime - dT;
    const VIPRA::delta_t right = checkTime + dT;
    return (currTime > left && currTime < right);
  }
};
}  // namespace BHVR

#endif