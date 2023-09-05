#ifndef MAP_LOADER_MOCK_HPP
#define MAP_LOADER_MOCK_HPP

#include <gmock/gmock.h>

#include "map_loader/map_loader.hpp"

class MapLoaderMock : public VIPRA::MapLoader {
 public:
  MOCK_METHOD(void, configure, (const VIPRA::Config& configMap), (override));
  MOCK_METHOD(void, initialize, (), (override));
  MOCK_METHOD(std::unique_ptr<VIPRA::MapData>, LoadMap, (const std::string& filePath),
              (const override));
};

#endif