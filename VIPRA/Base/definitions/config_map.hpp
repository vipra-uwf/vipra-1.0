#ifndef VIPRA_CONFIGURATION_HPP
#define VIPRA_CONFIGURATION_HPP

#include <fstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "jsoncpp/json/json.h"

namespace VIPRA {
namespace Config {

class ConfigurationException : public std::runtime_error {
 public:
  ConfigurationException(const std::string& message) : std::runtime_error{message} {}
  static void Throw(const std::string& message) { throw ConfigurationException(message); }
};

typedef Json::Value Map;

}  // namespace Config
}  // namespace VIPRA

#endif