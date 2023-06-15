#ifndef VIPRA_BEHAVIORS_VALUES_HPP
#define VIPRA_BEHAVIORS_VALUES_HPP

#include <generated/BehaviorParser.h>

#include <spdlog/spdlog.h>

#include <behavior/exceptions.hpp>
#include <definitions/dsl_types.hpp>
#include <stdexcept>
#include <time/time.hpp>
#include "randomization/random.hpp"
#include "values/numeric_value.hpp"

namespace BHVR {

using RandomVal = std::pair<float, float>;
using RangeVal = std::pair<float, float>;

[[nodiscard]] inline float collapseRangeValue(BHVR::seed seed, float min, float max) {
  VIPRA::pRNG_Engine                 eng{seed};
  VIPRA::uniform_distribution<float> distr{min, max};
  return distr(eng);
}

[[nodiscard]] inline NumericValue getNumeric(BehaviorParser::Value_numberContext* ctx,
                                             BHVR::seed                           seed) {
  float val = std::stof(ctx->NUMBER()->toString());
  return NumericValue(seed, ExactValue{val});
}

[[nodiscard]] inline NumericValue getNumeric(BehaviorParser::Value_randomContext* ctx,
                                             BHVR::seed                           seed) {
  if (ctx->random_float()) {
    auto  numbers = ctx->random_float()->float_range()->FLOAT();
    float min = std::stof(numbers[0]->toString());
    float max = std::stof(numbers[1]->toString());
    return NumericValue(seed, RandomFloatValue{min, max});
  }

  auto  numbers = ctx->random_number()->number_range()->NUMBER();
  float min = std::round(std::stof(numbers[0]->toString()));
  float max = std::round(std::stof(numbers[1]->toString()));
  return NumericValue(seed, RandomNumberValue{min, max});
}

[[nodiscard]] inline NumericValue getNumeric(BehaviorParser::Value_rangeContext* ctx,
                                             BHVR::seed                          seed) {
  if (ctx->float_range()) {
    auto  numbers = ctx->float_range()->FLOAT();
    float min = std::stof(numbers[0]->toString());
    float max = std::stof(numbers[1]->toString());
    return NumericValue(seed, ExactValue{collapseRangeValue(seed, min, max)});
  }

  auto  numbers = ctx->number_range()->NUMBER();
  float min = std::round(std::stof(numbers[0]->toString()));
  float max = std::round(std::stof(numbers[1]->toString()));
  return NumericValue(seed, ExactValue{std::round(collapseRangeValue(seed, min, max))});
}

[[nodiscard]] inline NumericValue getNumeric(BehaviorParser::Value_floatContext* ctx,
                                             BHVR::seed                          seed) {
  float val = std::stof(ctx->FLOAT()->toString());
  return NumericValue(seed, ExactValue{val});
}

[[nodiscard]] inline NumericValue getNumeric(BehaviorParser::Value_numericContext* ctx,
                                             BHVR::seed                            seed) {
  if (ctx->value_float()) return getNumeric(ctx->value_float(), seed);

  if (ctx->value_number()) return getNumeric(ctx->value_number(), seed);

  if (ctx->value_random()) return getNumeric(ctx->value_random(), seed);

  if (ctx->value_range()) return getNumeric(ctx->value_range(), seed);

  spdlog::error(
      "Numeric Value Context Missing Children (you should never see this error)");
  throw std::runtime_error("");
  return {};
}
}  // namespace BHVR

#endif