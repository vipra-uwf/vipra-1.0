#ifndef VIPRA_PARAMETER_SWEEP_ENGINE_HPP
#define VIPRA_PARAMETER_SWEEP_ENGINE_HPP

#include "configuration/config.hpp"
#include "distributions/distributions.hpp"
#include "randomization/random.hpp"

namespace VIPRA {
class ParameterSweep {
 public:
  [[nodiscard]] static VIPRA::Config randomizeParams(VIPRA::Config,
                                                     VIPRA::pRNG_Engine& engine);

 private:
  [[nodiscard]] static float randomizeValue(const nlohmann::json&,
                                            VIPRA::pRNG_Engine& engine);

  [[nodiscard]] static nlohmann::json randomPick(const nlohmann::json& value,
                                                 VIPRA::pRNG_Engine&   engine);
};
}  // namespace VIPRA

#endif