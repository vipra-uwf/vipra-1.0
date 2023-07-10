#ifndef PEDESTRIAN_POSITION_LOADER_HPP
#define PEDESTRIAN_POSITION_LOADER_HPP

#include <fstream>
#include <vector>

#include <json/json.h>
#include <spdlog/spdlog.h>

#include <pedestrian_loader/pedestrian_loader.hpp>

#include <definitions/dimensions.hpp>
#include "definitions/type_definitions.hpp"

class JsonPedestrianLoader : public PedestrianLoader {
 public:
  void configure(const VIPRA::CONFIG::Map& configMap) override;
  void initialize() override;
  [[nodiscard]] std::vector<VIPRA::pcoord> loadPedestrians(
      const std::string& filePath) const override;

  JsonPedestrianLoader() = default;
};

#endif