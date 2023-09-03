
#include <gtest/gtest.h>
#include <filesystem>

#include "test_values/test_values.hpp"

#include "MapLoader/Point_Map_Loader/point_map_loader.hpp"

namespace fs = std::filesystem;

const auto testValues =
    fs::current_path().string() + "/modules/maploader/point_map_loader/test_values/";

// test that LoadPedestrians returns the proper data
TEST(Point_Map_Loader, Load_Map) {
  PointMapLoader test;

  std::unique_ptr<VIPRA::MapData> result = test.loadMap(testValues + "good_map.omap");
  auto                            resultptr = reinterpret_cast<PointMap*>(result.get());

  for (VIPRA::idx i = 0; i < goodmap_obstacles.size(); ++i) {
    EXPECT_EQ(resultptr->entities.at("obstacle").at(i), goodmap_obstacles.at(i));
  }

  for (VIPRA::idx i = 0; i < goodmap_seats.size(); ++i) {
    EXPECT_EQ(resultptr->entities.at("seat").at(i), goodmap_seats.at(i));
  }

  for (VIPRA::idx i = 0; i < goodmap_exits.size(); ++i) {
    EXPECT_EQ(resultptr->entities.at("exit").at(i), goodmap_exits.at(i));
  }

  for (VIPRA::idx i = 0; i < goodmap_endOfAisles.size(); ++i) {
    EXPECT_EQ(resultptr->entities.at("endOfAisle").at(i), goodmap_endOfAisles.at(i));
  }

  for (VIPRA::idx i = 0; i < goodmap_aisles.size(); ++i) {
    EXPECT_EQ(resultptr->entities.at("aisle").at(i), goodmap_aisles.at(i));
  }
}

// test that LoadPedestrians handles improper data correctly
TEST(Calm_Pedestrian_Loader, Load_Map_Improper_Map) {
  PointMapLoader test;

  EXPECT_THROW(test.loadMap(testValues + "bad_map.omap"), VIPRA::MapLoaderException);
}