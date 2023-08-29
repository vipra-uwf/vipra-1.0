
#include <nlohmann/json.hpp>

#include "parameter_sweep.hpp"

namespace VIPRA {
VIPRA::Config ParameterSweep::randomizeParams(VIPRA::Config       config,
                                              VIPRA::pRNG_Engine& engine) {
  for (const auto& [module, params] : config.items()) {
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
    // TODO (rolland) throw error
  }

  if (!value["min"].is_number() || !value["max"].is_number()) {
    // TODO (rolland) throw error
  }

  return VIPRA::normal_distribution(value["min"].get<float>(),
                                    value["max"].get<float>())(engine);
}

nlohmann::json ParameterSweep::randomPick(const nlohmann::json& value,
                                          VIPRA::pRNG_Engine&   engine) {
  return value[VIPRA::normal_distribution<size_t>(0, value.size() - 1)(engine)];
}
}  // namespace VIPRA