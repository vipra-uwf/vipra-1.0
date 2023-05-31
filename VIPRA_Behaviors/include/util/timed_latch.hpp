#ifndef VIPRA_BEHAVIORS_TIME_LATCH_HPP
#define VIPRA_BEHAVIORS_TIME_LATCH_HPP

#include <definitions/dsl_types.hpp>
#include <definitions/type_definitions.hpp>

namespace BHVR {

class LatchCollection;

/**
 * @brief Timed boolean value, once latched will return true until 'duration' (simulated) time has passed
 * 
 */
class TimedLatch {
 public:
  explicit TimedLatch(VIPRA::time_s dur) : duration(dur) {}

  /**
   * @brief Starts the timer for the latch, keeps the first start time value if called repeatedly
   * 
   * @param startT : 
   */
  void latch(VIPRA::time_s startT) {
    if (!set) {
      startTime = startT;
      set = true;
    }
  }

  /**
   * @brief Checks if latched or duration time has passed, unlatches if duration has passed
   * 
   * @param currTime : 
   * @return true 
   * @return false 
   */
  [[nodiscard]] bool check(VIPRA::time_s currTime) {
    if (currTime == unlatchTime) {
      return true;
    }

    if (set) {
      const VIPRA::delta_t currDuration = currTime - startTime;
      if (currDuration >= duration) {
        unlatchTime = currTime;
        set = false;
      }
      return true;
    }

    return false;
  }

  /**
   * @brief Sets the latchs duration
   * 
   * @param dur : 
   */
  inline void setDuration(VIPRA::time_s dur) { duration = dur; }

  /**
   * @brief Gets the latchs duration
   * 
   * @return VIPRA::time_s 
   */
  [[nodiscard]] inline VIPRA::time_s getDuration() const { return duration; }

 private:
  bool  set = false;
  float startTime = 0;
  float duration = 0;
  float unlatchTime = -1;

 public:
  TimedLatch() = default;
  ~TimedLatch() = default;
  TimedLatch(const TimedLatch&) = default;
  TimedLatch& operator=(const TimedLatch&) = default;
  TimedLatch(TimedLatch&&) noexcept = default;
  TimedLatch& operator=(TimedLatch&&) noexcept = default;
  friend LatchCollection;
};


/**
 * @brief Container of TimedLatches
 * 
 */
class LatchCollection {
 public:
  explicit LatchCollection(VIPRA::time_range_s timeRange, BHVR::seed bSeed) : seed(bSeed), range(std::move(timeRange)) {}

  /**
   * @brief Latchs the latch at index
   * 
   * @param startTime : 
   * @param index : 
   */
  inline void latch(VIPRA::time_s startTime, VIPRA::idx index) { latches[index].latch(startTime); }
  /**
   * @brief Checks the latch at index
   * 
   * @param currTime : 
   * @param index : 
   * @return true 
   * @return false 
   */
  [[nodiscard]] inline bool check(VIPRA::time_s currTime, VIPRA::idx index) { return latches[index].check(currTime); }

  /**
   * @brief Adds latches to reach the provided count, if latches > count none are added
   * 
   * @param cnt : 
   */
  inline void addLatches(VIPRA::size cnt) {
    if (latches.size() <= cnt) {
      VIPRA::size start = 0;
      if (latches.empty()) {
        start = 0;
      } else {
        start = latches.size() - 1;
      }

      latches.resize(cnt);
      VIPRA::size end = latches.size();

      for (VIPRA::idx i = start; i < end; ++i) {
        latches[i].setDuration(makeDuration(i));
      }
    }
  }
  /**
   * @brief Gets the duration for latch at index
   * 
   * @param index : 
   * @return VIPRA::time_s 
   */
  [[nodiscard]] inline VIPRA::time_s getDuration(VIPRA::idx index) const { return latches[index].duration; }

  /**
   * @brief Returns the number of latches
   * 
   * @return VIPRA::size 
   */
  [[nodiscard]] inline VIPRA::size count() const { return latches.size(); }

 private:
  BHVR::seed              seed;
  std::vector<TimedLatch> latches;
  VIPRA::time_range_s     range;

  /**
   * @brief Makes a random duration between range
   * 
   * @param index : 
   * @return VIPRA::time_s 
   */
  [[nodiscard]] inline VIPRA::time_s makeDuration(VIPRA::idx index) const {
    if (range.first == range.second) {
      return range.first;
    }

    srand(seed + index);
    // TODO(rolland) : replace rand
    return range.first + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (range.second - range.first)));
  }

 public:
  LatchCollection() = delete;
  ~LatchCollection() = default;
  LatchCollection(const LatchCollection&) = default;
  LatchCollection& operator=(const LatchCollection&) = default;
  LatchCollection(LatchCollection&&) noexcept = default;
  LatchCollection& operator=(LatchCollection&&) noexcept = default;
};
}  // namespace BHVR

#endif