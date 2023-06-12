#ifndef VIPRA_BEHAVIORS_NUMERIC_VALUE
#define VIPRA_BEHAVIORS_NUMERIC_VALUE

#include <cmath>
#include <functional>
#include <random>

#include <definitions/dsl_types.hpp>
#include <definitions/type_definitions.hpp>
#include <utility>

namespace BHVR {

using ValueFunc = std::function<float(std::default_random_engine&)>;

class NumericValue {
 public:
  explicit NumericValue(ValueFunc func) : value(std::move(func)) {}

  [[nodiscard]] inline float operator()() const {
    float val = value(getRandomEngine());
    return val;
  }

  [[nodiscard]] static std::default_random_engine& getRandomEngine() {
    // NOLINTNEXTLINE (rolland) probably not ideal, builder seeds the engine with each new behavior : ignores(cert-msc32-c)
    static std::default_random_engine gen{};
    return gen;
  }

 private:
  std::function<float(std::default_random_engine&)> value;

 public:
  NumericValue() = default;
};

struct ExactValue {
  float        value;
  inline float operator()(std::default_random_engine&) const { return value; }
};

struct RandomFloatValue {
  float                                 min{};
  float                                 max{};
  std::uniform_real_distribution<float> distr{min, max};

  inline float operator()(std::default_random_engine& gen) { return distr(gen); }
};

struct RandomNumberValue {
  float                                 min{};
  float                                 max{};
  std::uniform_real_distribution<float> distr{min, max};

  inline float operator()(std::default_random_engine& gen) {
    return std::round(distr(gen));
  }
};

}  // namespace BHVR

#endif