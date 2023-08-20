
#include "json_pedestrian_loader.hpp"
#include "definitions/type_definitions.hpp"

/**
 * @brief Configures the JsonPedestrianLoader.
 *
 * @param config The configuration map.
 */
void JsonPedestrianLoader::configure(const VIPRA::Config&) {}

/**
 * @brief Initializes the JsonPedestrianLoader.
 */
void JsonPedestrianLoader::initialize() {}

/**
 * @brief Loads pedestrians from a file.
 *
 * @param filePath The path to the pedestrian file.
 * @return A vector of pedestrians data.
 */
std::vector<VIPRA::pcoord> JsonPedestrianLoader::loadPedestrians(
    const std::string& filePath) const {
  std::ifstream fileStream(filePath);
  auto          jsonData = nlohmann::json::parse(fileStream);

  std::vector<VIPRA::pcoord> inputData{};
  try {
    for (const auto& [key, value] : jsonData["pedestrians"].items()) {
      VIPRA::f3d temp{};
      for (const auto& dimension : value.items()) {
        temp[dimension.key()[0]] = dimension.value().get<float>();
      }
      inputData.push_back(temp);
    }
  } catch (...) {
    VIPRA::PedestrianLoaderException::error(
        "Unable To Parse Pedestrian File: " + filePath + "\n");
  }
  if (inputData.empty()) {
    VIPRA::PedestrianLoaderException::error("Empty Pedestrian File: " + filePath + "\n");
  }
  return inputData;
}