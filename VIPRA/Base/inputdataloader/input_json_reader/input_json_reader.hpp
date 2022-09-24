#ifndef INPUT_JSON_READER_HPP
#define INPUT_JSON_READER_HPP

#include "../../jsoncpp/json/json.h"
#include "../input_data_loader.hpp"

class InputJSONReader : public InputDataLoader {
 private:
 public:
  ENTITY_SET getInputEntities(const std::string& filePath) override;
  void       configure(const CONFIG_MAP& configMap) override;
};

#endif