
#include "configuration_reader.hpp"

#include <iostream>

/**
 * @throws
 * @brief Creates a Config::Map from a JSON file at filePath
 * 
 * @param filePath Absolute Path to JSON Configuration file
 * @return Config::Map containing the values of the configuration file
 */
[[nodiscard]] Json::Value
ConfigurationReader::getConfiguration(const std::string& filePath) {
  Json::Value             jsonDocument;
  Json::CharReaderBuilder jsonReader;
  std::ifstream           fileStream;
  std::string             errors;

  fileStream.open(filePath);
  if (!fileStream.is_open()) {
    VIPRA::Config::ConfigurationException::Throw("Unable to Open Configuration File: " + filePath);
  }

  if (!Json::parseFromStream(jsonReader, fileStream, &jsonDocument, &errors)) {
    fileStream.close();
    VIPRA::Config::ConfigurationException::Throw("Unable To Parse Configuration File: " + filePath);
  }
  fileStream.close();

  return jsonDocument;
}

void
ConfigurationReader::configure(const VIPRA::Config::Map&) {}