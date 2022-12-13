#ifndef POINT_MAP_LOADER_HPP
#define POINT_MAP_LOADER_HPP

#include <fstream>

#include "jsoncpp/json/json.h"
#include "maploader/map_loader.hpp"

struct PointMap : public MapType {
  VIPRA::EntitySet entities;
};

class PointMapLoader : public MapLoader {
 public:
  void                     configure(const VIPRA::ConfigMap& configMap) override;
  void                     initialize() override;
  std::unique_ptr<MapType> LoadMap(const std::string& filePath) const override;
};

#endif