#ifndef MAP_LOADER_MOCK_HPP
#define MAP_LOADER_MOCK_HPP

#include <gmock/gmock.h>

#include "maploader/map_loader.hpp"

// virtual void                            configure(const VIPRA::ConfigMap& configMap) = 0;
// virtual void                            initialize() = 0;
// virtual std::unique_ptr<VIPRA::MapData> LoadMap(const std::string& filePath) const = 0;

class MapLoaderMock : public MapLoader {
 public:
  MOCK_METHOD(void, configure, (const VIPRA::ConfigMap& configMap), (override));
  MOCK_METHOD(void, initialize, (), (override));
  MOCK_METHOD(std::unique_ptr<VIPRA::MapData>, LoadMap, (const std::string& filePath), (const override));
};

#endif