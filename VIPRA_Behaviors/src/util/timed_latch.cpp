
#include <algorithm>
#include <util/timed_latch.hpp>
#include <utility>

namespace BHVR {

/**
 * @brief Latches if not already latched
 * 
 * @param startT : 
 */
void TimedLatch::latch(VIPRA::time_s startT) {
  if (!set) {
    startTime = startT;
    set = true;
  }
}

/**
 * @brief Returns true if latched, resets latch if time has passed and returns false
 * 
 */
bool TimedLatch::check(VIPRA::time_s currTime) {
  if (set) {
    const VIPRA::delta_t dt = currTime - startTime;
    if (dt >= duration) {
      set = false;
      return true;
    }
  }

  return false;
}

/**
 * @brief Sets the latchs duration
 * 
 */
void TimedLatch::setDuration(VIPRA::time_s dur) {
  duration = dur;
}

/**
 * @brief Returns the duration for the latch
 * 
 */
VIPRA::time_s TimedLatch::getDuration() const {
  return duration;
}

TimedLatch::TimedLatch(VIPRA::time_s dur) : duration(dur) {}

// -----------------------------------------------------------------------------------------


/**
 * @brief Latches the latch at index index
 * 
 */
void LatchCollection::latch(VIPRA::time_s startTime, VIPRA::idx index) {
  latches[index].latch(startTime);
}

/**
 * @brief Checks the status of latch at index
 * 
 */
bool LatchCollection::check(VIPRA::time_s currTime, VIPRA::idx index) {
  return latches[index].check(currTime);
}

/**
 * @brief Adds latches so 'latches.size()' = 'count', setting their duration randomly within 'range', if latches.size() >= count no latches are added
 * 
 */
void LatchCollection::addLatches(VIPRA::size count) {
  if (latches.size() <= count) {
    VIPRA::size start;
    if (latches.empty()) {
      start = 0;
    } else {
      start = latches.size() - 1;
    }

    latches.resize(count);
    VIPRA::size end = latches.size();

    for (VIPRA::idx i = start; i < end; ++i) {
      latches[i].setDuration(makeDuration(i));
    }
  }
}

/**
 * @brief Creates a random duration between 'range' seeded by seed+index
 * 
 */
inline VIPRA::time_s LatchCollection::makeDuration(VIPRA::idx index) const {
  if (range.first == range.second) {
    return range.first;
  }

  srand(seed + index);
  return range.first + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (range.second - range.first)));
}

/**
 * @brief Returns the duration for latch at index
 * 
 */
VIPRA::time_s LatchCollection::getDuration(VIPRA::idx index) const {
  return latches[index].duration;
}

/**
 * @brief Returns the number of latches
 * 
 */
VIPRA::size LatchCollection::count() const {
  return latches.size();
}

LatchCollection::LatchCollection(VIPRA::time_range_s timeRange, BHVR::seed sd) : seed(sd), range(std::move(timeRange)) {}
}  // namespace BHVR
