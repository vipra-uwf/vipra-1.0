#ifndef INPUT_DATALOADER_HPP
#define INPUT_DATALOADER_HPP

#include "../_pch/pch.hpp"

#include "../definitions/type_definitions.hpp"

class InputDataLoaderException : public std::exception {
 public:
  InputDataLoaderException(const std::string& message) : message(message) {}
  const std::string& what() { return message; }

  static void Error(const std::string& message) {
    std::cerr << message << std::endl;
    throw InputDataLoaderException(message);
  }

 private:
  std::string message;
};

class InputDataLoader {
 public:
  static const ENTITY_SET _emptyset_;
  virtual ~InputDataLoader() = default;

  virtual void                     configure(const CONFIG_MAP& configMap) = 0;
  [[nodiscard]] virtual ENTITY_SET getInputEntities(const std::string& filePath) = 0;
};

#endif
