#ifndef CONFIGURATION_READER_HPP
#define CONFIGURATION_READER_HPP

#include <fstream>
#include <iostream>

#include "definitions/config_map.hpp"
#include "definitions/type_definitions.hpp"
#include "jsoncpp/json/json.h"

class ConfigurationReaderException : public std::runtime_error {
 public:
  ConfigurationReaderException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw ConfigurationReaderException(message); }
};

class ConfigurationReader {
 public:
  VIPRA::Config::Map getConfiguration(const std::string& filePath);
  void               configure(const VIPRA::Config::Map& config);

 private:
};

#endif