
#include "point_map_loader.hpp"

void
PointMapLoader::configure(const VIPRA::ConfigMap& configMap) {}

void
PointMapLoader::initialize() {}

std::unique_ptr<MapType>
PointMapLoader::LoadMap(const std::string& filePath) const {
  Json::Value             jsonDocument;
  Json::CharReaderBuilder jsonReader;
  std::ifstream           fileStream;
  std::string             errors;

  fileStream.open(filePath);
  if (!fileStream.is_open()) {
    MapLoaderException::Throw("Unable To Open Map File: " + filePath + "\n");
  }

  if (!Json::parseFromStream(jsonReader, fileStream, &jsonDocument, &errors)) {
    fileStream.close();
    MapLoaderException::Throw("Unable To Parse Map File: " + filePath + "\n");
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
    MapLoaderException::Throw("Unable To Parse Map File: " + filePath + "\n");
  }
  return inputData;
}