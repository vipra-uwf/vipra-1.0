
#include <nlohmann/json.hpp>

#include "parameter_sweep.hpp"

namespace VIPRA {
VIPRA::Config ParameterSweep::randomizeParams(VIPRA::Config       config,
                                              VIPRA::pRNG_Engine& engine) {
  for (const auto& [module, params] : config.items()) {
    if (module == "human_behavior_model") continue;
    for (const auto& [param, value] : params.items()) {
      if (value.is_array()) {
        // TODO (rolland) choose random value in array
        params[param] = randomPick(value, engine);
      } else if (value.is_object()) {
        // TODO (rolland) choose random value between min / max
        params[param] = randomizeValue(value, engine);
      }
    }
  }
  return config;
}

float ParameterSweep::randomizeValue(const nlohmann::json& value,
                                     VIPRA::pRNG_Engine&   engine) {
  if (!value.contains("min") || !value.contains("max")) {
    ParameterSweepException::error("Value Does Not Contain A Min and/or Max");
  }

  if (!value["min"].is_number() || !value["max"].is_number()) {
    ParameterSweepException::error("Min or Max Not A Number");
  }

  return VIPRA::uniform_distribution(value["min"].get<float>(),
                                     value["max"].get<float>())(engine);
}

nlohmann::json ParameterSweep::randomPick(const nlohmann::json& value,
                                          VIPRA::pRNG_Engine&   engine) {
  auto cnt = value.size();
  if (cnt < 1) {
    ParameterSweepException::error("Empty Array Value");
  }
  auto idx = VIPRA::uniform_distribution<size_t>(0, cnt - 1)(engine);
  return value[idx];
}
}  // namespace VIPRA