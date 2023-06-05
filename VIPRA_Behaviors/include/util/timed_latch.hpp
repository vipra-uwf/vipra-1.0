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


  void latch(VIPRA::time_s startT) {
    if (!set) {
      startTime = startT;
      set = true;
    }
  }

  [[nodiscard]] bool check(VIPRA::time_s currTime) {
    if (set) {
      const VIPRA::delta_t currDuration = currTime - startTime;
      if (currDuration >= duration) {
        set = false;
        return true;
      }
    }

    return false;
  }

  inline void setDuration(VIPRA::time_s dur) { duration = dur; }

  [[nodiscard]] inline VIPRA::time_s getDuration() const { return duration; }

 private:
  bool  set = false;
  float startTime = 0;
  float duration = 0;

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

  inline void               latch(VIPRA::time_s startTime, VIPRA::idx index) { latches[index].latch(startTime); }
  [[nodiscard]] inline bool check(VIPRA::time_s currTime, VIPRA::idx index) { return latches[index].check(currTime); }

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
  [[nodiscard]] inline VIPRA::time_s getDuration(VIPRA::idx index) const { return latches[index].duration; }

  [[nodiscard]] inline VIPRA::size count() const { return latches.size(); }

 private:
  BHVR::seed              seed;
  std::vector<TimedLatch> latches;
  VIPRA::time_range_s     range;

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