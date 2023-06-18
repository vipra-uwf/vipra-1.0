#ifndef POINT_MAP_LOADER_HPP
#define POINT_MAP_LOADER_HPP

#include <fstream>
#include <memory>

#include <json/json.h>
#include <spdlog/spdlog.h>

#include <definitions/entitySet.hpp>
#include <map_loader/map_loader.hpp>

struct PointMap : public VIPRA::MapData {
  VIPRA::EntitySet entities;
};

class PointMapLoader : public MapLoader {
 public:
  void configure(const VIPRA::CONFIG::Map&) override;
  void initialize() override;
  [[nodiscard]] std::unique_ptr<VIPRA::MapData> loadMap(
      const std::string&) const override;
};

#endif