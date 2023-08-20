#ifndef POINT_MAP_LOADER_HPP
#define POINT_MAP_LOADER_HPP

#include <fstream>
#include <memory>

#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>

#include "definitions/entitySet.hpp"
#include "map_loader/map_loader.hpp"

/**
 * @struct PointMap
 * @brief A struct representing the PointMap data.
 *
 * This struct inherits from VIPRA::MapData and contains a set of entities.
 */
struct PointMap : public VIPRA::MapData {
  VIPRA::EntitySet entities;
};

/**
 * @class PointMapLoader
 * @brief A class responsible for loading PointMap data.
 *
 * This class inherits from MapLoader and provides methods for configuration,
 * initialization, and loading PointMap data from a file.
 */
class PointMapLoader : public VIPRA::MapLoader {
 public:
  /**
   * @brief Configures the PointMapLoader.
   *
   * @param config The configuration map.
   */
  void configure(const VIPRA::Config&) override;

  /**
   * @brief Initializes the PointMapLoader.
   */
  void initialize() override;
  /**
   * @brief Loads PointMap data from a file.
   *
   * @param filePath The path to the PointMap file.
   * @return A unique pointer to the loaded PointMap data.
   */
  [[nodiscard]] std::unique_ptr<VIPRA::MapData> loadMap(
      const std::string&) const override;
};

#endif