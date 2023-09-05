#ifndef PEDESTRIAN_POSITION_LOADER_HPP
#define PEDESTRIAN_POSITION_LOADER_HPP

#include <fstream>
#include <vector>

#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>

#include <pedestrian_loader/pedestrian_loader.hpp>

#include <definitions/dimensions.hpp>
#include "definitions/type_definitions.hpp"

/**
 * @class JsonPedestrianLoader
 * @brief A class for loading pedestrian positions from a JSON file.
 *
 * This class inherits from PedestrianLoader and provides functionality for
 * configuring, initializing, and loading pedestrian positions from a JSON file.
 */
class JsonPedestrianLoader : public VIPRA::PedestrianLoader {
 public:
  /**
   * @brief Configures the JsonPedestrianLoader with the given configuration map.
   *
   * @param configMap The configuration map.
   */
  void configure(const VIPRA::Config& configMap) override;
  /**
   * @brief Initializes the JsonPedestrianLoader.
   */
  void initialize() override;

  /**
   * @brief Loads pedestrians from the specified JSON file.
   *
   * @param filePath The path to the JSON file.
   * @return A vector containing the pedestrians data.
   */
  [[nodiscard]] std::vector<VIPRA::pcoord> loadPedestrians(
      const std::string& filePath) const override;
  /**
   * @brief Default constructor for the JsonPedestrianLoader class.
   */
  JsonPedestrianLoader() = default;
};

#endif