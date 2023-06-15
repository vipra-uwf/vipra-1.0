#ifndef VIPRA_RANDOM_HPP
#define VIPRA_RANDOM_HPP

#include <sys/types.h>
#include <array>

#include <cstdint>
#include <definitions/type_definitions.hpp>
#include <limits>

namespace VIPRA {

// NOLINTNEXTLINE (rolland) Default Naming Convention looks ugly
class pRNG_Engine {
  using seed = __uint128_t;

 public:
  using result_type = uint64_t;

  explicit pRNG_Engine(uint64_t seedVal) : currVal(seedVal) { currVal <<= shiftNum; }

  /**
   * @brief Produces the next pseudo random number in the sequence, uses Lehmer's generator
   * 
   * @return uint64_t 
   */
  uint64_t operator()() {
    currVal *= multNum;
    return currVal >> shiftNum;
  }

  void reseed(uint64_t seedNum) {
    currVal = seedNum;
    currVal <<= shiftNum;
  }

  static inline constexpr uint64_t min() { return 0; }
  static inline constexpr uint64_t max() { return std::numeric_limits<uint64_t>::max(); }

 private:
  seed                      currVal;
  static constexpr uint64_t multNum = 0xda942042e4dd58b5;
  static constexpr uint64_t shiftNum = 64;

 public:
  pRNG_Engine() = default;
  ~pRNG_Engine() = default;
  pRNG_Engine(const pRNG_Engine&) = default;
  pRNG_Engine(pRNG_Engine&&) noexcept = default;
  pRNG_Engine& operator=(const pRNG_Engine&) = default;
  pRNG_Engine& operator=(pRNG_Engine&&) noexcept = default;
};

template <typename T>
// NOLINTNEXTLINE (rolland) sticking to familiar naming convention for std::uniform_real_distribution
class uniform_distribution {
 public:
  uniform_distribution(T min, T max) : range(min, max) {}
  explicit uniform_distribution(std::pair<T, T> rangeVals)
      : range(std::move(rangeVals)) {}

  T operator()(pRNG_Engine& engine) {
    auto val = engine();
    return static_cast<T>(range.first +
                          static_cast<double>(val) /
                              (static_cast<double>(std::numeric_limits<uint64_t>::max()) /
                               static_cast<double>(range.second - range.first)));
  }

 private:
  std::pair<T, T> range;
};
}  // namespace VIPRA

#endif