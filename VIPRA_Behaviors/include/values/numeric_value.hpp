#ifndef VIPRA_BEHAVIORS_NUMERIC_VALUE
#define VIPRA_BEHAVIORS_NUMERIC_VALUE

#include <cmath>
#include <functional>

#include <definitions/dsl_types.hpp>
#include <definitions/type_definitions.hpp>
#include <random/random.hpp>
#include <utility>

namespace BHVR {
/**
 * @brief Function for getting the value of a numeric
 * 
 */
using ValueFunc = std::function<float(BHVR::seed, VIPRA::idx)>;

/**
 * @brief Numeric Values hold runtime float values taken from Behaviors
 * 
 */
class NumericValue {
 public:
  explicit NumericValue(BHVR::seed seedNum, ValueFunc func)
      : seed(seedNum), val(std::move(func)) {}

  [[nodiscard]] inline float value(VIPRA::idx pedIdx) const { return val(seed, pedIdx); }

 private:
  BHVR::seed seed{};
  ValueFunc  val;

 public:
  NumericValue() = default;
};

/**
 * @brief Holds an exact float value
 * 
 */
struct ExactValue {
  float        value;
  inline float operator()(BHVR::seed, VIPRA::idx) const { return value; }
};

/**
 * @brief Holds a random float value for each pedestrian
 * 
 */
struct RandomFloatValue {
  float min{};
  float max{};

  inline float operator()(BHVR::seed seed, VIPRA::idx pedIdx) const {
    return BHVR::DRNG::pedRandomFloat(seed, pedIdx, min, max);
  }
};

/**
 * @brief Holds a random whole number value for each pedestrian
 * 
 */
struct RandomNumberValue {
  float min{};
  float max{};

  inline float operator()(BHVR::seed seed, VIPRA::idx pedIdx) const {
    return std::round(BHVR::DRNG::pedRandomFloat(seed, pedIdx, min, max));
  }
};

}  // namespace BHVR

#endif