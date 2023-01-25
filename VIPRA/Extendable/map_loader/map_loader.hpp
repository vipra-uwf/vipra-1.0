#ifndef MAP_LOADER_HPP
#define MAP_LOADER_HPP

#include "definitions/config_map.hpp"
#include "definitions/type_definitions.hpp"
#include <memory>

namespace VIPRA {
struct MapData {
  virtual ~MapData() = default;
  std::string type;
};
}  // namespace VIPRA

class MapLoaderException : public std::runtime_error {
 public:
  MapLoaderException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw MapLoaderException(message); }
};

class MapLoader {
 public:
  virtual ~MapLoader() = default;

  virtual void                            configure(const VIPRA::ConfigMap& configMap) = 0;
  virtual void                            initialize() = 0;
  virtual std::unique_ptr<VIPRA::MapData> LoadMap(const std::string& filePath) const = 0;
};

#endif