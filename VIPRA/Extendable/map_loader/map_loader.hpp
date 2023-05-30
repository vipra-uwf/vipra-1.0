#ifndef MAP_LOADER_HPP
#define MAP_LOADER_HPP

#include <memory>

#include <definitions/config_map.hpp>
#include <definitions/type_definitions.hpp>

namespace VIPRA {
struct MapData {
  std::string type;
  explicit MapData(std::string type) : type(std::move(type)) {}

  MapData(const MapData&) = default;
  MapData(MapData&&) = delete;
  MapData& operator=(const MapData&) = default;
  MapData& operator=(MapData&&) = delete;
  MapData() = default;
  virtual ~MapData() = default;
};
}  // namespace VIPRA

class MapLoaderException : public std::runtime_error {
 public:
  explicit MapLoaderException(const std::string& message) : std::runtime_error(message) {}
  static void error(const std::string& message) { throw MapLoaderException(message); }
};

class MapLoader {
 public:
  virtual void                                          configure(const VIPRA::CONFIG::Map& configMap) = 0;
  virtual void                                          initialize() = 0;
  [[nodiscard]] virtual std::unique_ptr<VIPRA::MapData> loadMap(const std::string& filePath) const = 0;

  MapLoader(const MapLoader&) = default;
  MapLoader(MapLoader&&) = delete;
  MapLoader& operator=(const MapLoader&) = default;
  MapLoader& operator=(MapLoader&&) = delete;
  MapLoader() = default;
  virtual ~MapLoader() = default;
};

#endif