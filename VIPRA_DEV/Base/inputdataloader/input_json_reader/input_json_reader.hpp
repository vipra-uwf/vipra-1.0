#ifndef INPUT_JSON_READER_HPP
#define INPUT_JSON_READER_HPP

#include "../../jsoncpp/json/json.h"
#include "../input_data_loader.hpp"

class InputJSONReader : public InputDataLoader {
 private:
  Json::Value             jsonDocument;
  Json::CharReaderBuilder jsonReader;
  std::ifstream           fileStream;
  std::string             errors;

  void openFile(std::string fileName);
  void parseFile();

 public:
  ENTITY_SET getInputEntities() override;

  void configure(const CONFIG_MAP& configMap) override;

  void extractFileData(std::string       fileName,
                       const CONFIG_MAP& configMap) override;
};

#endif