#ifndef VIPRA_BEHAVIORS_TIME_HPP
#define VIPRA_BEHAVIORS_TIME_HPP

#include <string>
#include <utility>
#include "definitions/type_definitions.hpp"
namespace BHVR {
using RandomVal = std::pair<float, float>;
class Duration {
 public:
  explicit Duration(float dur) : range(dur, dur) {}
  explicit Duration(RandomVal rnd) : range(std::move(rnd)) {}
  Duration(float start, float end) : range(start, end) {}

  [[nodiscard]] std::string durationStr() const { return ""; }

 private:
  VIPRA::time_range_s range;
};
}  // namespace BHVR

#endif