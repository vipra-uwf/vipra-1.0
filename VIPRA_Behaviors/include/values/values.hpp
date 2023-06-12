#ifndef VIPRA_BEHAVIORS_VALUES_HPP
#define VIPRA_BEHAVIORS_VALUES_HPP

#include <random>

#include <generated/BehaviorParser.h>

#include <spdlog/spdlog.h>

#include <behavior/exceptions.hpp>
#include <definitions/dsl_types.hpp>
#include <stdexcept>
#include <time/time.hpp>
#include "values/numeric_value.hpp"

namespace BHVR {

using RandomVal = std::pair<float, float>;
using RangeVal = std::pair<float, float>;

[[nodiscard]] inline float collapseRangeValue(float min, float max) {
  auto&                                 gen = NumericValue::getRandomEngine();
  std::uniform_real_distribution<float> distr{min, max};
  return distr(gen);
}

[[nodiscard]] inline NumericValue getNumeric(BehaviorParser::Value_numberContext* ctx) {
  float val = std::stof(ctx->NUMBER()->toString());
  return NumericValue(ExactValue{val});
}

[[nodiscard]] inline NumericValue getNumeric(BehaviorParser::Value_randomContext* ctx) {
  if (ctx->random_float()) {
    auto  numbers = ctx->random_float()->float_range()->FLOAT();
    float min = std::stof(numbers[0]->toString());
    float max = std::stof(numbers[1]->toString());
    return NumericValue(RandomFloatValue{min, max});
  }

  auto  numbers = ctx->random_number()->number_range()->NUMBER();
  float min = std::round(std::stof(numbers[0]->toString()));
  float max = std::round(std::stof(numbers[1]->toString()));
  return NumericValue(RandomNumberValue{min, max});
}

[[nodiscard]] inline NumericValue getNumeric(BehaviorParser::Value_rangeContext* ctx) {
  if (ctx->float_range()) {
    auto  numbers = ctx->float_range()->FLOAT();
    float min = std::stof(numbers[0]->toString());
    float max = std::stof(numbers[1]->toString());
    return NumericValue(ExactValue{collapseRangeValue(min, max)});
  }

  auto  numbers = ctx->number_range()->NUMBER();
  float min = std::round(std::stof(numbers[0]->toString()));
  float max = std::round(std::stof(numbers[1]->toString()));
  return NumericValue(ExactValue{std::round(collapseRangeValue(min, max))});
}

[[nodiscard]] inline NumericValue getNumeric(BehaviorParser::Value_floatContext* ctx) {
  float val = std::stof(ctx->FLOAT()->toString());
  return NumericValue(ExactValue{val});
}

[[nodiscard]] inline NumericValue getNumeric(BehaviorParser::Value_numericContext* ctx) {
  if (ctx->value_float()) return getNumeric(ctx->value_float());

  if (ctx->value_number()) return getNumeric(ctx->value_number());

  if (ctx->value_random()) return getNumeric(ctx->value_random());

  if (ctx->value_range()) return getNumeric(ctx->value_range());

  spdlog::error(
      "Numeric Value Context Missing Children (you should never see this error)");
  throw std::runtime_error("");
  return {};
}
}  // namespace BHVR

#endif