
#include "json_pedestrian_loader.hpp"
#include "definitions/type_definitions.hpp"

/**
 * @brief Configures the JsonPedestrianLoader.
 *
 * @param config The configuration map.
 */
void JsonPedestrianLoader::configure(const VIPRA::CONFIG::Map&) {}

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
  Json::Value             jsonDocument;
  Json::CharReaderBuilder jsonReader;
  std::ifstream           fileStream;
  std::string             errors;

  fileStream.open(filePath);
  if (!fileStream.is_open()) {
    PedestrianLoaderException::error("Unable To Open Map File: " + filePath + "\n");
  }

  if (!Json::parseFromStream(jsonReader, fileStream, &jsonDocument, &errors)) {
    fileStream.close();
    spdlog::error("JsonPedestrianLoader: Jsoncpp unable to parse file");
    PedestrianLoaderException::error("Unable To Parse Map File: " + filePath + "\n");
  }
  fileStream.close();

  std::vector<VIPRA::pcoord> inputData;
  try {
    spdlog::debug("JsonPedestrianLoader: Parsed File, Building Pedestrians");
    for (unsigned int i = 0; i < jsonDocument.size(); i++) {
      const std::string type = jsonDocument.getMemberNames()[i];
      spdlog::debug("Type: {}", type);
      inputData = VIPRA::f3dVec{};

      for (unsigned int j = 0; j < jsonDocument[type].size(); j++) {
        VIPRA::f3d position{};
        for (unsigned int k = 0; k < jsonDocument[type][j].size(); ++k) {
          const std::string name = jsonDocument[type][j].getMemberNames()[k];
          if (name == "x") {
            position['x'] = std::stof(jsonDocument[type][j][name].asString());
          } else if (name == "y") {
            position['y'] = std::stof(jsonDocument[type][j][name].asString());
          } else if (name == "z") {
            position['z'] = std::stof(jsonDocument[type][j][name].asString());
          }
        }
        inputData.push_back(position);
      }
    }
  } catch (const std::exception& ex) {
    spdlog::debug("JsonPedestrianLoader: Error Building Pedestrians, Error: {}",
                  ex.what());
    PedestrianLoaderException::error("Unable To Parse Map File: " + filePath + "\n");
  }

  if (inputData.empty()) {
    spdlog::error("JsonPedestrianLoader: Pedestrian File Missing Properties");
    PedestrianLoaderException::error("Pedestrian File Missing Properties: " + filePath +
                                     "\n");
  }

  return inputData;
}