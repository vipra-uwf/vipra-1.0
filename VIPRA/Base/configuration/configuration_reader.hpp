#ifndef CONFIGURATION_READER_HPP
#define CONFIGURATION_READER_HPP

#include <fstream>
#include <iostream>


#include "definitions/type_definitions.hpp"
#include "jsoncpp/json/json.h"

class ConfigurationReaderException : public std::exception {
 public:
  ConfigurationReaderException(const std::string& message) : message(message) {}
  const std::string& what() { return message; }

  static void Error(const std::string& message) {
    std::cerr << message << std::endl;
    throw ConfigurationReaderException(message);
  }

 private:
  std::string message;
};

class ConfigurationReader {
 public:
  Json::Value getConfiguration(const std::string& filePath);
  void        configure(const CONFIG_MAP& config);

 private:
};

#endif