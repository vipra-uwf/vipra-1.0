#ifndef CONFIGURATION_READER_HPP
#define CONFIGURATION_READER_HPP

#include <fstream>
#include <iostream>

#include "configuration/config.hpp"
#include "definitions/type_definitions.hpp"

namespace VIPRA {
class ConfigurationReaderException : public std::runtime_error {
 public:
  explicit ConfigurationReaderException(const std::string& message)
      : std::runtime_error(message) {}
  static void error(const std::string& message) {
    throw ConfigurationReaderException(message);
  }
};

/**
 * @brief Reads module params for configuration values
 * 
 */
class ConfigurationReader {
 public:
  static VIPRA::Config getConfiguration(const std::string& filePath);
  void                 configure(const VIPRA::Config& config);

 private:
};
}  // namespace VIPRA

#endif