#include "input_json_reader.hpp"

const VIPRA::EntitySet InputDataLoader::_emptyset_{};

void
InputJSONReader::configure(const VIPRA::ConfigMap& configMap) {}

/**
 * @throws InputDataLoaderException
 * @brief Gets the VIPRA::EntitySet described by the file at filePath
 * 
 * @param filePath - Absolute path to file
 * @return VIPRA::EntitySet 
 */
VIPRA::EntitySet
InputJSONReader::getInputEntities(const std::string& filePath) {

  Json::Value             jsonDocument;
  Json::CharReaderBuilder jsonReader;
  std::ifstream           fileStream;
  std::string             errors;

  fileStream.open(filePath);
  if (!fileStream.is_open()) {
    InputDataLoaderException::Throw("Unable To Open Input File: " + filePath + "\n");
  }

  if (!Json::parseFromStream(jsonReader, fileStream, &jsonDocument, &errors)) {
    fileStream.close();
    InputDataLoaderException::Throw("Unable To Parse Input File: " + filePath + "\n");
  }
  fileStream.close();

  try {
    VIPRA::EntitySet inputData;
    VIPRA::size      docSize = jsonDocument.size();

    for (Json::ArrayIndex i = 0; i < docSize; ++i) {
      const std::string type = jsonDocument.getMemberNames()[i];
      inputData[type] = {};

      VIPRA::size typeSize = jsonDocument[type].size();
      for (Json::ArrayIndex j = 0; j < typeSize; j++) {
        VIPRA::f3d temp{};

        for (Json::ArrayIndex k = 0; k < jsonDocument[type][j].size(); ++k) {
          const std::string name = jsonDocument[type][j].getMemberNames()[k];
          temp[k] = std::stof(jsonDocument[type][j][name].asString());
        }
        inputData[type].push_back(temp);
      }
    }
    return inputData;
  } catch (...) {
    InputDataLoaderException::Throw("Unable To Parse Input File: " + filePath + "\n");
  }
  InputDataLoaderException::Throw("Unable To Parse Input File: " + filePath + "\n");
  return {};
}