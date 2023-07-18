
#include "configuration_reader.hpp"

#include <iostream>

/**
 * @throws
 * @brief Creates a CONFIG::Map from a JSON file at filePath
 * 
 * @param filePath Absolute Path to JSON Configuration file
 * @return CONFIG::Map containing the values of the configuration file
 */
VIPRA::CONFIG::Map ConfigurationReader::getConfiguration(const std::string& filePath) {
  Json::Value             jsonDocument;
  Json::CharReaderBuilder jsonReader;
  std::ifstream           fileStream;
  std::string             errors;

  fileStream.open(filePath);
  if (!fileStream.is_open()) {
    VIPRA::CONFIG::ConfigurationException::error("Unable to Open Configuration File: " +
                                                 filePath);
  }

  if (!Json::parseFromStream(jsonReader, fileStream, &jsonDocument, &errors)) {
    fileStream.close();
    VIPRA::CONFIG::ConfigurationException::error("Unable To Parse Configuration File: " +
                                                 filePath);
  }
  fileStream.close();

  return VIPRA::CONFIG::Map(jsonDocument);
}

/**
 * @brief Does nothing, each module has this function
 * 
 */
void ConfigurationReader::configure(const VIPRA::CONFIG::Map&) {}