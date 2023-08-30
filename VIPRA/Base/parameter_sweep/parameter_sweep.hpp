#ifndef VIPRA_PARAMETER_SWEEP_ENGINE_HPP
#define VIPRA_PARAMETER_SWEEP_ENGINE_HPP

#include <stdexcept>

#include "configuration/config.hpp"
#include "distributions/distributions.hpp"
#include "randomization/random.hpp"

namespace VIPRA {

class ParameterSweepException : public std::runtime_error {
 public:
  explicit ParameterSweepException(const std::string& message)
      : std::runtime_error(message) {}

  /**
   * @brief Throws a ParameterSweepException with the given error message.
   *
   * @param message The error message for the exception.
   */
  static void error(const std::string& message) {
    throw ParameterSweepException(message);
  }
};

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