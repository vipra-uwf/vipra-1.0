
#include "configuration_reader.hpp"

/**
 * @brief Reads a Sim.Config and returns the Json::Value it describes
 * 
 * @param filePath - Absolute path to config file
 * @return Json::Value 
 */
Json::Value
ConfigurationReader::getConfiguration(const std::string& filePath) {
  Json::Value             jsonDocument;
  Json::CharReaderBuilder jsonReader;
  std::ifstream           fileStream;
  std::string             errors;

  fileStream.open(filePath);
  if (!fileStream.is_open()) {
    ConfigurationReaderException::Throw("Unable to Open Configuration File: " + filePath);
  }

  if (!Json::parseFromStream(jsonReader, fileStream, &jsonDocument, &errors)) {
    fileStream.close();
    ConfigurationReaderException::Throw("Unable To Parse Configuration File: " + filePath);
  }
  fileStream.close();

  return jsonDocument;
}

void
ConfigurationReader::configure(const VIPRA::ConfigMap& config) {}