#ifndef VIPRA_PEDESTRIAN_LOADER_HPP
#define VIPRA_PEDESTRIAN_LOADER_HPP

#include <memory>

#include "definitions/type_definitions.hpp"

struct PedMapType {
  std::string type;
};

class PedestrianLoaderException : public std::runtime_error {
 public:
  PedestrianLoaderException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw PedestrianLoaderException(message); }
};

class PedestrianLoader {
 public:
  virtual ~PedestrianLoader() = default;

  virtual void                        configure(const VIPRA::ConfigMap& configMap) = 0;
  virtual void                        initialize() = 0;
  virtual std::unique_ptr<PedMapType> LoadPedestrians(const std::string& filePath) const = 0;
};

#endif