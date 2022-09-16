#ifndef INPUT_DATALOADER_HPP
#define INPUT_DATALOADER_HPP

#include "../_pch/pch.hpp"

#include "../definitions/type_definitions.hpp"

class InputDataLoader {
 public:
  virtual ~InputDataLoader() = default;

  virtual void extractFileData(std::string       fileName,
                               const CONFIG_MAP& configMap) = 0;

  virtual void configure(const CONFIG_MAP& configMap) = 0;

  virtual ENTITY_SET getInputEntities() = 0;
};

#endif
