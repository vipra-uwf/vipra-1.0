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
  void               latch(VIPRA::time_s);
  [[nodiscard]] bool check(VIPRA::time_s);

  void          setDuration(VIPRA::time_s);
  VIPRA::time_s getDuration() const;

 private:
  bool  set = false;
  float startTime = 0;
  float duration = 0;

 public:
  explicit TimedLatch(VIPRA::time_s);
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
  void               latch(VIPRA::time_s, VIPRA::idx);
  [[nodiscard]] bool check(VIPRA::time_s, VIPRA::idx);

  void          addLatches(VIPRA::size);
  VIPRA::time_s getDuration(VIPRA::idx) const;

  VIPRA::size count() const;

 private:
  BHVR::seed              seed;
  std::vector<TimedLatch> latches;
  VIPRA::time_range_s     range;

  inline VIPRA::time_s makeDuration(VIPRA::idx) const;

 public:
  explicit LatchCollection(VIPRA::time_range_s, BHVR::seed);
  LatchCollection() = delete;
  ~LatchCollection() = default;
  LatchCollection(const LatchCollection&) = default;
  LatchCollection& operator=(const LatchCollection&) = default;
  LatchCollection(LatchCollection&&) noexcept = default;
  LatchCollection& operator=(LatchCollection&&) noexcept = default;
};
}  // namespace BHVR

#endif