
#include "point_map_loader.hpp"
#include "definitions/dimensions.hpp"

/**
 * @brief Configures the PointMapLoader.
 *
 * @param config The configuration map.
 */
void PointMapLoader::configure(const VIPRA::Config&) {}

/**
 * @brief Initializes the PointMapLoader.
 */
void PointMapLoader::initialize() {}

/**
 * @brief Loads PointMap data from a file.
 *
 * @param filePath The path to the PointMap file.
 * @return A unique pointer to the loaded PointMap data.
 */
std::unique_ptr<VIPRA::MapData> PointMapLoader::loadMap(
    const std::string& filePath) const {
  std::ifstream fileStream(filePath);
  auto          jsonData = nlohmann::json::parse(fileStream);

  auto inputData = std::make_unique<PointMap>();
  try {
    inputData->type = "PointMap";

    for (const auto& [key, value] : jsonData.items()) {
      inputData->entities[key] = VIPRA::f3dVec{};
      for (const auto& position : value.items()) {
        VIPRA::f3d temp{};
        for (const auto& dimension : position.value().items()) {
          temp[dimension.key()[0]] = dimension.value().get<float>();
        }
        inputData->entities[key].push_back(temp);
      }
    }
  } catch (...) {
    VIPRA::MapLoaderException::error("Unable To Parse Map File: " + filePath + "\n");
  }
  if (inputData->entities.empty()) {
    VIPRA::MapLoaderException::error("Empty Map File: " + filePath + "\n");
  }
  return inputData;
}