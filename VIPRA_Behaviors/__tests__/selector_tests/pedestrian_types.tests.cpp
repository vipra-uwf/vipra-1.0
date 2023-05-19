#include <gtest/gtest.h>
#include <filesystem>

#include <definitions/../../__tests__/mocks/goals/goals.mock.hpp>
#include <definitions/../../__tests__/mocks/obstacle_set/obstacle_set.mock.hpp>
#include <definitions/../../__tests__/mocks/pedestrian_set/pedestrian_set.mock.hpp>

#include <definitions/pedestrian_types.hpp>

using ::testing::Return;
using ::testing::ReturnRef;

TEST(PedstrianTypes, ForEach) {
  BHVR::pType sut1{15};

  BHVR::typeUID totalTypes = 0;
  BHVR::typeUID nextType = 1;

  sut1.forEachType([&](BHVR::typeUID type) {
    EXPECT_EQ(type, nextType);
    nextType = nextType << 1;
    totalTypes += 1;
  });

  EXPECT_EQ(totalTypes, 4);

  BHVR::pType sut2{31};

  totalTypes = 0;
  nextType = 1;

  sut2.forEachType([&](BHVR::typeUID type) {
    EXPECT_EQ(type, nextType);
    nextType = nextType << 1;
    totalTypes += 1;
  });

  EXPECT_EQ(totalTypes, 5);

  BHVR::pType sut3{63};

  totalTypes = 0;
  nextType = 1;

  sut3.forEachType([&](BHVR::typeUID type) {
    EXPECT_EQ(type, nextType);
    nextType = nextType << 1;
    totalTypes += 1;
  });

  EXPECT_EQ(totalTypes, 6);
}