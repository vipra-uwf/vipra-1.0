#ifndef POINT_MAP_LOADER_HPP
#define POINT_MAP_LOADER_HPP

#include <fstream>

#include "definitions/entitySet.hpp"
#include "jsoncpp/json/json.h"
#include "logging/logging.hpp"
#include "map_loader/map_loader.hpp"

struct PointMap : public VIPRA::MapData {
  VIPRA::EntitySet entities;
};

class PointMapLoader : public MapLoader {
 public:
  void                            configure(const VIPRA::ConfigMap& configMap) override;
  void                            initialize() override;
  std::unique_ptr<VIPRA::MapData> LoadMap(const std::string& filePath) const override;
};

#endif