#ifndef CONFIGURATION_READER_HPP
#define CONFIGURATION_READER_HPP

#include <fstream>
#include <iostream>

#include <json/json.h>
#include <definitions/config_map.hpp>
#include <definitions/type_definitions.hpp>

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
  static VIPRA::CONFIG::Map getConfiguration(const std::string& filePath);
  void                      configure(const VIPRA::CONFIG::Map& config);

 private:
};

#endif