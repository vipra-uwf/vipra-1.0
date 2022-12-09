
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
    ConfigurationReaderException::Error("Unable to Open Configuration File: " + filePath);
  }

  if (!Json::parseFromStream(jsonReader, fileStream, &jsonDocument, &errors)) {
    fileStream.close();
    ConfigurationReaderException::Error("Unable To Parse Configuration File: " + filePath);
  }
  fileStream.close();

  return jsonDocument;
}

void
ConfigurationReader::configure(const CONFIG_MAP& config) {}