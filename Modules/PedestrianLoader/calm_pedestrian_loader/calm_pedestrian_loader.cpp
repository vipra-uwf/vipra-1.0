
#include "calm_pedestrian_loader.hpp"

void
CalmPedestrianLoader::configure(const VIPRA::Config::Map& configMap) {}

void
CalmPedestrianLoader::initialize() {}

std::unique_ptr<VIPRA::PedData>
CalmPedestrianLoader::LoadPedestrians(const std::string& filePath) const {
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
    spdlog::error("CalmPedestrianLoader: Jsoncpp unable to parse file");
    PedestrianLoaderException::Throw("Unable To Parse Map File: " + filePath + "\n");
  }
  fileStream.close();

  std::unique_ptr<CalmPedData> inputData = std::make_unique<CalmPedData>();
  try {
    spdlog::debug("CalmPedestrianLoader: Parsed File, Building Pedestrians");
    for (unsigned int i = 0; i < jsonDocument.size(); i++) {
      const std::string type = jsonDocument.getMemberNames()[i];
      spdlog::debug("Type: {}", type);
      inputData->positions = VIPRA::f3dVec{};
      inputData->masses = std::vector<float>{};
      inputData->desiredSpeeds = std::vector<float>{};
      inputData->reactionTimes = std::vector<float>{};

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
          } else if (name == "mass") {
            inputData->masses.push_back(std::stof(jsonDocument[type][j][name].asString()));
          } else if (name == "reaction") {
            inputData->reactionTimes.push_back(std::stof(jsonDocument[type][j][name].asString()));
          } else if (name == "desiredSpeed") {
            inputData->desiredSpeeds.push_back(std::stof(jsonDocument[type][j][name].asString()));
          } else if (name == "shoulderLength") {
            inputData->shoulderLengths.push_back(std::stof(jsonDocument[type][j][name].asString()));
          }
        }
        inputData->positions.push_back(position);
      }
    }
  } catch (const std::exception& ex) {
    spdlog::debug("CalmPedestrianLoader: Error Building Pedestrians, Error: {}", ex.what());
    PedestrianLoaderException::Throw("Unable To Parse Map File: " + filePath + "\n");
  }

  if (inputData->positions.size() < 1 || inputData->masses.size() < 1 || inputData->desiredSpeeds.size() < 1 ||
      inputData->reactionTimes.size() < 1) {
    spdlog::error("CalmPedestrianLoader: Pedestrian File Missing Properties");
    PedestrianLoaderException::Throw("Pedestrian File Missing Properties: " + filePath + "\n");
  }

  return inputData;
}