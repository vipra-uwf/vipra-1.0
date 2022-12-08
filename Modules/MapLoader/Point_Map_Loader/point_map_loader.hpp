#ifndef POINT_MAP_LOADER_HPP
#define POINT_MAP_LOADER_HPP

#include "../../../VIPRA/Extendable/maploader/map_loader.hpp"
#include "../../../VIPRA/deps/jsoncpp/json/json.h"

struct PointMap : public MapType {
  ENTITY_SET entities;
};

class PointMapLoader : public MapLoader {
 public:
  void                     configure(const CONFIG_MAP& configMap) override;
  void                     initialize() override;
  std::unique_ptr<MapType> LoadMap(const std::string& filePath) const override;
};

#endif