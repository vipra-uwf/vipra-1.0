
#include "pedestrian_position_loader.hpp"

void
PedestrianPositionLoader::configure(const VIPRA::ConfigMap& configMap) {}

void
PedestrianPositionLoader::initialize() {}

std::unique_ptr<PedMapType>
PedestrianPositionLoader::LoadPedestrians(const std::string& filePath) const {
  Json::Value             jsonDocument;
  Json::CharReaderBuilder jsonReader;
  std::ifstream           fileStream;
  std::string             errors;

  fileStream.open(filePath);
  if (!fileStream.is_open()) {
    PedestrianLoaderException::Throw("Unable To Open Map File: " + filePath + "\n");
  }

  if (!Json::parseFromStream(jsonReader, fileStream, &jsonDocument, &errors)) {
    fileStream.close();
    PedestrianLoaderException::Throw("Unable To Parse Map File: " + filePath + "\n");
  }
  fileStream.close();
  try {
    std::unique_ptr<PedestrianPositions> inputData = std::make_unique<PedestrianPositions>();
    for (unsigned int i = 0; i < jsonDocument.size(); i++) {
      const std::string type = jsonDocument.getMemberNames()[i];
      inputData->positions = VIPRA::f3dVec{};

      for (unsigned int j = 0; j < jsonDocument[type].size(); j++) {
        VIPRA::f3d temp{};
        for (unsigned int k = 0; k < jsonDocument[type][j].size(); ++k) {
          const std::string name = jsonDocument[type][j].getMemberNames()[k];
          temp[k] = std::stof(jsonDocument[type][j][name].asString());
        }
        inputData->positions.push_back(temp);
      }
    }
    return inputData;
  } catch (...) {
    PedestrianLoaderException::Throw("Unable To Parse Map File: " + filePath + "\n");
  }
}