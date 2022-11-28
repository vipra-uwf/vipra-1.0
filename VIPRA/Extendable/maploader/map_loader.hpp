#ifndef MAP_LOADER_HPP
#define MAP_LOADER_HPP

#include <memory>

#include "../../Base/definitions/type_definitions.hpp"

struct MapType {
  std::string type;
};

class MapLoaderException : public std::runtime_error {
 public:
  MapLoaderException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw MapLoaderException(message); }
};

class MapLoader {
 public:
  virtual ~MapLoader() = default;

  virtual void                     configure(const CONFIG_MAP& configMap) = 0;
  virtual void                     initialize() = 0;
  virtual std::unique_ptr<MapType> LoadMap(const std::string& filePath) const = 0;
};

#endif