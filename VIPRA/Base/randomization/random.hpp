#ifndef VIPRA_RANDOM_HPP
#define VIPRA_RANDOM_HPP

#include <cstdint>
#include <cstdlib>
#include <limits>

#include "definitions/type_definitions.hpp"

namespace VIPRA {

/**
 * @brief Psuedo Random number engine
 * 
 */
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

  /**
   * @brief Restarts the number generator with a new seed
   * 
   * @param seedNum : 
   */
  void reseed(uint64_t seedNum) {
    currVal = seedNum;
    currVal <<= shiftNum;
  }

  /**
   * @brief Returns the minimum number possible
   * 
   * @return constexpr uint64_t 
   */
  static inline constexpr uint64_t min() { return 0; }

  /**
   * @brief Returns the maximum number possible
   * 
   * @return constexpr uint64_t 
   */
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
}  // namespace VIPRA

#endif