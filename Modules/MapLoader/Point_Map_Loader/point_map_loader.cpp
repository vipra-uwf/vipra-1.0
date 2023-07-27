
#include "point_map_loader.hpp"

/**
 * @brief Configures the PointMapLoader.
 *
 * @param config The configuration map.
 */
void PointMapLoader::configure(const VIPRA::CONFIG::Map&) {}

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
  Json::Value             jsonDocument;
  Json::CharReaderBuilder jsonReader;
  std::ifstream           fileStream;
  std::string             errors;

  fileStream.open(filePath);
  if (!fileStream.is_open()) {
    MapLoaderException::error("Unable To Open Map File: " + filePath + "\n");
  }

  if (!Json::parseFromStream(jsonReader, fileStream, &jsonDocument, &errors)) {
    fileStream.close();
    MapLoaderException::error("Unable To Parse Map File: " + filePath + "\n");
  }
  fileStream.close();
  auto inputData = std::make_unique<PointMap>();
  try {
    inputData->type = "PointMap";
    for (unsigned int i = 0; i < jsonDocument.size(); i++) {
      const std::string type = jsonDocument.getMemberNames()[i];
      inputData->entities[type] = VIPRA::f3dVec{};

      for (unsigned int j = 0; j < jsonDocument[type].size(); j++) {
        VIPRA::f3d temp{};
        for (unsigned int k = 0; k < jsonDocument[type][j].size(); ++k) {
          const std::string name = jsonDocument[type][j].getMemberNames()[k];
          temp[k] = std::stof(jsonDocument[type][j][name].asString());
        }
        inputData->entities[type].push_back(temp);
      }
    }
  } catch (...) {
    MapLoaderException::error("Unable To Parse Map File: " + filePath + "\n");
  }
  if (inputData->entities.empty()) {
    MapLoaderException::error("Empty Map File: " + filePath + "\n");
  }
  return inputData;
}