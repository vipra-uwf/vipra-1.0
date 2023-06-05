
#include <gtest/gtest.h>
#include <filesystem>

#include "test_values/test_values.hpp"

#include "PedestrianLoader/calm_pedestrian_loader/calm_pedestrian_loader.hpp"

namespace fs = std::filesystem;

const auto testValues = fs::current_path().string() + "/modules/pedestrian_loader/calm_pedestrian_loader/test_values/";

// test that loadPedestrians returns the proper data
TEST(Calm_Pedestrian_Loader, Load_Pedestrians) {
  CalmPedestrianLoader test;

  std::unique_ptr<VIPRA::PedData> result = test.loadPedestrians(testValues + "good_map.pmap");
  auto                            resultptr = reinterpret_cast<CalmPedData*>(result.get());

  for (VIPRA::idx i = 0; i < resultptr->positions.size(); ++i) {
    EXPECT_EQ(resultptr->desiredSpeeds[i], good_speeds.at(i));
    EXPECT_EQ(resultptr->reactionTimes[i], good_reactions.at(i));
    EXPECT_EQ(resultptr->shoulderLengths[i], good_shoulders.at(i));
    EXPECT_EQ(resultptr->positions[i], good_coords.at(i));
    EXPECT_EQ(resultptr->masses[i], good_masses.at(i));
  }
}

// test that loadPedestrians handles improper data correctly
TEST(Calm_Pedestrian_Loader, Load_Pedestrians_Improper_Map) {
  CalmPedestrianLoader test;

  EXPECT_THROW(test.loadPedestrians(testValues + "bad_map.pmap"), PedestrianLoaderException);
}