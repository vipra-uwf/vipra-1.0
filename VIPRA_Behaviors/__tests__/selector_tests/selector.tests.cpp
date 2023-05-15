
#include <iostream>

#include <gtest/gtest.h>
#include <filesystem>

#include <definitions/../../__tests__/mocks/goals/goals.mock.hpp>
#include <definitions/../../__tests__/mocks/obstacle_set/obstacle_set.mock.hpp>
#include <definitions/../../__tests__/mocks/pedestrian_set/pedestrian_set.mock.hpp>

#include <definitions/pedestrian_types.hpp>
#include <selectors/pedestrian_groups.hpp>

#include <selectors/selector.hpp>
#include <selectors/selector_percent.hpp>
#include <selectors/subselector.hpp>

using ::testing::Return;
using ::testing::ReturnRef;

TEST(Selector, No_Dupes) {

  ObstacleSetMock   obsSet;
  PedestrianSetMock pedSet;
  GoalsMock         goals;

  EXPECT_CALL(pedSet, getNumPedestrians()).WillRepeatedly(Return(144));

  srand(0);
  for (int x = 0; x < 5; ++x) {

    BHVR::BehaviorContext context;
    context.pedStates = std::vector<BHVR::stateUID>(pedSet.getNumPedestrians());
    context.types = std::vector<BHVR::stateUID>(pedSet.getNumPedestrians());

    BHVR::Selector test;
    test.setAllTypes(BHVR::pType{3});
    test.addSubSelector(BHVR::SubSelector{0, BHVR::pType{1}, false, BHVR::selector_percent{0.5f}});
    test.addSubSelector(BHVR::SubSelector{0, BHVR::pType{2}, false, BHVR::selector_percent{0.5f}});

    BHVR::seed s = rand();

    test.initialize("test", s, context, pedSet, obsSet, goals);

    const auto& groups = test.getGroups();

    for (VIPRA::idx i = 0; i < groups.at(1).size(); ++i) {
      for (VIPRA::idx j = 0; j < groups.at(2).size(); ++j) {
        EXPECT_NE(groups.at(1)[i], groups.at(2)[j]);
      }
    }
  }
}

TEST(Selector, SubGroups) {
  ObstacleSetMock   obsSet;
  PedestrianSetMock pedSet;
  GoalsMock         goals;

  EXPECT_CALL(pedSet, getNumPedestrians()).WillRepeatedly(Return(144));

  BHVR::BehaviorContext context;
  context.pedStates = std::vector<BHVR::stateUID>(pedSet.getNumPedestrians());
  context.types = std::vector<BHVR::stateUID>(pedSet.getNumPedestrians());

  BHVR::Selector test;
  test.setAllTypes(BHVR::pType{7});

  VIPRA::size subgroupCnt = static_cast<VIPRA::size>(144 * 0.3 * 0.1);
  test.addSubSelector(BHVR::SubSelector{0, BHVR::pType{1}, false, BHVR::selector_percent{0.3f}});
  test.addSubSelector(BHVR::SubSelector{1, BHVR::pType{2}, false, BHVR::selector_percent{0.1f}});
  test.addSubSelector(BHVR::SubSelector{0, BHVR::pType{4}, false, BHVR::selector_percent{0.2f}});

  test.initialize("test", 123, context, pedSet, obsSet, goals);

  const auto& groups = test.getGroups();

  EXPECT_EQ(groups.at(2).size(), subgroupCnt);

  VIPRA::size counter = 0;
  for (VIPRA::idx i = 0; i < groups.at(2).size(); ++i) {
    for (VIPRA::idx j = 0; j < groups.at(1).size(); ++j) {
      if (groups.at(2)[i] == groups.at(1)[j]) {
        ++counter;
      }
    }
  }

  EXPECT_EQ(counter, subgroupCnt);
}