#ifndef VIPRA_MAP_LOADER_HPP
#define VIPRA_MAP_LOADER_HPP

#include <memory>

#include "configuration/config.hpp"
#include "definitions/type_definitions.hpp"

namespace VIPRA {

/**
 * @struct MapData
 * @brief Represents data for a map.
 *
 * This struct holds information about the type of the map.
 */
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

/**
 * @class MapLoaderException
 * @brief Custom exception class for handling errors related to MapLoader.
 *
 * This class is a custom exception class derived from std::runtime_error.
 * It is used to handle errors that may occur during the loading of a map.
 */
class MapLoaderException : public std::runtime_error {
 public:
  explicit MapLoaderException(const std::string& message) : std::runtime_error(message) {}

  /**
   * @brief Static function to throw a MapLoaderException with the given error message.
   *
   * This static function can be used to throw a MapLoaderException with the specified error message.
   * It is a convenient way to create and throw exceptions.
   *
   * @param message The error message for the exception.
   */
  static void error(const std::string& message) { throw MapLoaderException(message); }
};

/**
 * @class MapLoader
 * @brief Interface for loading map data.
 *
 * This class is an interface for loading map data from different sources.
 */
class MapLoader {
 public:
  virtual void configure(const VIPRA::Config& configMap) = 0;
  virtual void initialize() = 0;
  [[nodiscard]] virtual std::unique_ptr<VIPRA::MapData> loadMap(
      const std::string& filePath) const = 0;

  MapLoader(const MapLoader&) = default;
  MapLoader(MapLoader&&) = delete;
  MapLoader& operator=(const MapLoader&) = default;
  MapLoader& operator=(MapLoader&&) = delete;
  MapLoader() = default;
  virtual ~MapLoader() = default;
};
}  // namespace VIPRA

#endif