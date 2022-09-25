#include "input_json_reader.hpp"

const ENTITY_SET InputDataLoader::_emptyset_{};

void
throwIRError(const std::string& message) {
  std::cerr << message;
  throw InputReaderException(message);
}

void
InputJSONReader::configure(const CONFIG_MAP& configMap) {}

ENTITY_SET
InputJSONReader::getInputEntities(const std::string& filePath) {

  Json::Value             jsonDocument;
  Json::CharReaderBuilder jsonReader;
  std::ifstream           fileStream;
  std::string             errors;

  fileStream.open(filePath);
  if (!fileStream.is_open()) {}

  if (!Json::parseFromStream(jsonReader, fileStream, &jsonDocument, &errors)) {
    fileStream.close();
    throwIRError("Unable To Parse Input File: " + filePath + "\n");
  }
  fileStream.close();

  try {
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
  } catch (std::exception ex) {
    throwIRError("Unable To Parse Input File: " + filePath + "\n");
  }
}