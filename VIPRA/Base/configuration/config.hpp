#ifndef VIPRA_CONFIGURATION_HPP
#define VIPRA_CONFIGURATION_HPP

#include <fstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include <nlohmann/json.hpp>

#include "definitions/type_definitions.hpp"

namespace VIPRA {
class ConfigurationException : public std::runtime_error {
 public:
  explicit ConfigurationException(const std::string& message)
      : std::runtime_error{message} {}
  static void error(const std::string& message) { throw ConfigurationException(message); }
};

using Config = nlohmann::json;
using Params = nlohmann::json;

}  // namespace VIPRA

#endif