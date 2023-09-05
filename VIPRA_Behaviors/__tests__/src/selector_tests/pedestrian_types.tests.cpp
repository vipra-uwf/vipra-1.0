#include <gtest/gtest.h>
#include <filesystem>

#include <mocks/goals/goals.mock.hpp>
#include <mocks/obstacle_set/obstacle_set.mock.hpp>
#include <mocks/pedestrian_set/pedestrian_set.mock.hpp>

#include <definitions/pedestrian_types.hpp>


TEST(PedstrianTypes, ForEach) {
  BHVR::Ptype sut1{15};

  BHVR::typeUID totalTypes = 0;
  BHVR::typeUID nextType = 1;

  sut1.forEachType([&](BHVR::typeUID type) {
    EXPECT_EQ(type, nextType);
    nextType = nextType << 1;
    totalTypes += 1;
  });

  EXPECT_EQ(totalTypes, 4);

  BHVR::Ptype sut2{31};

  totalTypes = 0;
  nextType = 1;

  sut2.forEachType([&](BHVR::typeUID type) {
    EXPECT_EQ(type, nextType);
    nextType = nextType << 1;
    totalTypes += 1;
  });

  EXPECT_EQ(totalTypes, 5);

  BHVR::Ptype sut3{63};

  totalTypes = 0;
  nextType = 1;

  sut3.forEachType([&](BHVR::typeUID type) {
    EXPECT_EQ(type, nextType);
    nextType = nextType << 1;
    totalTypes += 1;
  });

  EXPECT_EQ(totalTypes, 6);
}