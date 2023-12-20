#ifndef VIPRA_DISTRIBUTIONS_HPP
#define VIPRA_DISTRIBUTIONS_HPP

#include <algorithm>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

#include <spdlog/spdlog.h>

#include "definitions/type_definitions.hpp"
#include "randomization/random.hpp"

namespace VIPRA {

class DistributionException : public std::runtime_error {
 public:
  explicit DistributionException(const std::string& message)
      : std::runtime_error(message) {}
  static void error(const std::string& message) { throw DistributionException(message); }
};

/**
 * @brief produces a uniform random distribution
 * 
 * @tparam T : 
 */
template <typename T = float>
// NOLINTNEXTLINE (rolland) sticking to familiar naming convention for std::uniform_real_distribution
class uniform_distribution {
 public:
  uniform_distribution(T min, T max) : range(min, max) {}
  explicit uniform_distribution(std::pair<T, T> rangeVals)
      : range(std::move(rangeVals)) {}

  T operator()(pRNG_Engine& engine) {
    auto val = engine();
    if ((range.second - range.first) == 0) return range.first;
    return static_cast<T>(range.first +
                          static_cast<double>(val) /
                              (static_cast<double>(std::numeric_limits<uint64_t>::max()) /
                               static_cast<double>(range.second - range.first)));
  }

 private:
  std::pair<T, T> range;
};

/**
 * @brief Normal Distribution created using the Marsaglia method
 * @ref https://en.wikipedia.org/wiki/Marsaglia_polar_method
 */
template <typename T = float>
// NOLINTNEXTLINE (rolland) sticking to familiar naming convention for std::normal_distribution
class normal_distribution {
 public:
  normal_distribution(T mean, T stdDev) : mean_(mean), stdDev_(stdDev) {}

  T operator()(pRNG_Engine& engine) {
    double resultX = 0;
    double resultY = 0;
    double result = 1.0;

    if (hasSpare_) {
      hasSpare_ = false;
      return static_cast<T>(mean_ + stdDev_ * spare_);
    }

    while (result >= 1.0 || result == 0.0) {
      resultX =
          ((static_cast<double>(engine()) / static_cast<double>(pRNG_Engine::max())) *
           two) -
          1.0;
      resultY =
          ((static_cast<double>(engine()) / static_cast<double>(pRNG_Engine::max())) *
           two) -
          1.0;
      result = resultX * resultX + resultY * resultY;
    };

    result = std::sqrt(-two * std::log(result) / result);
    spare_ = resultY * result;
    hasSpare_ = true;
    return static_cast<T>(mean_ + stdDev_ * resultX * result);
  }

 private:
  float mean_;
  float stdDev_;

  double spare_{0.0F};
  bool   hasSpare_ = false;

  static constexpr float two = 2.0;
};

/**
 * @brief Returns a vector of float with random values following the Dist distribution
 * 
 * @tparam Dist : 
 * @param count : 
 * @param min : 
 * @param max : 
 * @param engine : 
 * @return std::vector<float> 
 */
template <typename Dist>
inline std::vector<float> makeDistribution(VIPRA::size count, float min, float max,
                                           VIPRA::pRNG_Engine& engine) {
  std::vector<float> ret(count);
  Dist               distr{min, max};
  std::transform(ret.cbegin(), ret.cend(), ret.begin(), [&](float) {
    float val = distr(engine);
    return val;
  });
  return ret;
}

}  // namespace VIPRA

#endif