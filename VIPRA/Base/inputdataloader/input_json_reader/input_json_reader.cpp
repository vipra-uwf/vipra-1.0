#include "input_json_reader.hpp"

const ENTITY_SET InputDataLoader::_emptyset_{};

void InputJSONReader::configure(const CONFIG_MAP& configMap) {}

ENTITY_SET InputJSONReader::getInputEntities(const std::string& filePath) {

  Json::Value             jsonDocument;
  Json::CharReaderBuilder jsonReader;
  std::ifstream           fileStream;
  std::string             errors;

  fileStream.open(filePath);
  if (!fileStream.is_open()) {
    std::cout << "Unable to open Input File: " << filePath << std::endl;
    return _emptyset_;
  }

  if (!Json::parseFromStream(jsonReader, fileStream, &jsonDocument, &errors)) {
    fileStream.close();
    std::cout << "Error parsing JSON: " << errors << std::endl;
    return _emptyset_;
  }
  fileStream.close();

  ENTITY_SET inputData;

  for (unsigned int i = 0; i < jsonDocument.size(); i++) {
    const std::string type = jsonDocument.getMemberNames()[i];
    inputData[type] = {};

    for (unsigned int j = 0; j < jsonDocument[type].size(); j++) {
      Dimensions temp{};
      for (unsigned int k = 0; k < jsonDocument[type][j].size(); ++k) {
        const std::string name = jsonDocument[type][j].getMemberNames()[k];
        temp.axis[k] = std::stof(jsonDocument[type][j][name].asString());
      }
      inputData[type].push_back(temp);
    }
  }
  return inputData;
}