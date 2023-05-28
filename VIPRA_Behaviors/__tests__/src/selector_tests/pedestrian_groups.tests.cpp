#include <gtest/gtest.h>
#include <filesystem>

#include <mocks/goals/goals.mock.hpp>
#include <mocks/obstacle_set/obstacle_set.mock.hpp>
#include <mocks/pedestrian_set/pedestrian_set.mock.hpp>

#include <definitions/pedestrian_types.hpp>
#include <selectors/pedestrian_groups.hpp>

#include <selectors/selector.hpp>
#include <selectors/selector_percent.hpp>
#include <selectors/subselector.hpp>


TEST(GroupContainer, initialization) {

  BHVR::Ptype           test1 = BHVR::Ptype{};
  BHVR::GroupsContainer sut1;
  sut1.initialize(test1, 100);
  EXPECT_EQ(sut1.size(), 1);

  BHVR::Ptype           test2 = BHVR::Ptype{3};
  BHVR::GroupsContainer sut2;
  sut2.initialize(test2, 100);
  EXPECT_EQ(sut2.size(), 3);

  BHVR::Ptype           test3 = BHVR::Ptype{7};
  BHVR::GroupsContainer sut3;
  sut3.initialize(test3, 100);
  EXPECT_EQ(sut3.size(), 4);

  BHVR::Ptype           test4 = BHVR::Ptype{15};
  BHVR::GroupsContainer sut4;
  sut4.initialize(test4, 100);
  EXPECT_EQ(sut4.size(), 5);

  BHVR::Ptype           test5 = BHVR::Ptype{31};
  BHVR::GroupsContainer sut5;
  sut5.initialize(test5, 100);
  EXPECT_EQ(sut5.size(), 6);
}

TEST(GroupContainer, TypeCount) {
  // TODO(rolland) this
}