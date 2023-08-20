

#include "configuration_reader.hpp"

namespace VIPRA {
/**
 * @throws
 * @brief Creates a CONFIG::Map from a JSON file at filePath
 * 
 * @param filePath Absolute Path to JSON Configuration file
 * @return CONFIG::Map containing the values of the configuration file
 */
VIPRA::Config ConfigurationReader::getConfiguration(const std::string& filePath) {
  std::ifstream fileStream(filePath);
  return nlohmann::json::parse(fileStream);
}

/**
 * @brief Does nothing, each module has this function
 * 
 */
void ConfigurationReader::configure(const VIPRA::Config&) {}
}  // namespace VIPRA