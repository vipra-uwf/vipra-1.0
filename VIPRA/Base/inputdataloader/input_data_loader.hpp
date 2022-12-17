#ifndef INPUT_DATALOADER_HPP
#define INPUT_DATALOADER_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "definitions/type_definitions.hpp"

class InputDataLoaderException : public std::runtime_error {
 public:
  InputDataLoaderException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw InputDataLoaderException(message); }
};

class InputDataLoader {
 public:
  static const VIPRA::EntitySet _emptyset_;
  virtual ~InputDataLoader() = default;

  virtual void                           configure(const VIPRA::ConfigMap& configMap) = 0;
  [[nodiscard]] virtual VIPRA::EntitySet getInputEntities(const std::string& filePath) = 0;
};

#endif
