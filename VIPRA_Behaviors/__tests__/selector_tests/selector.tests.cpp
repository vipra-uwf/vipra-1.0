
#include <iostream>

#include <filesystem>
#include <gtest/gtest.h>

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

TEST(GroupContainer, initialization) {

  Behaviors::pType           test1 = Behaviors::pType{};
  Behaviors::GroupsContainer sut1;
  sut1.initialize(test1, 100);
  EXPECT_EQ(sut1.size(), 1);

  Behaviors::pType           test2 = Behaviors::pType{3};
  Behaviors::GroupsContainer sut2;
  sut2.initialize(test2, 100);
  EXPECT_EQ(sut2.size(), 3);

  Behaviors::pType           test3 = Behaviors::pType{7};
  Behaviors::GroupsContainer sut3;
  sut3.initialize(test3, 100);
  EXPECT_EQ(sut3.size(), 4);

  Behaviors::pType           test4 = Behaviors::pType{15};
  Behaviors::GroupsContainer sut4;
  sut4.initialize(test4, 100);
  EXPECT_EQ(sut4.size(), 5);

  Behaviors::pType           test5 = Behaviors::pType{31};
  Behaviors::GroupsContainer sut5;
  sut5.initialize(test5, 100);
  EXPECT_EQ(sut5.size(), 6);
}

TEST(Selector, No_Dupes) {

  ObstacleSetMock   obsSet;
  PedestrianSetMock pedSet;
  GoalsMock         goals;

  EXPECT_CALL(pedSet, getNumPedestrians()).WillRepeatedly(Return(144));

  srand(0);
  for (int x = 0; x < 5; ++x) {

    Behaviors::BehaviorContext context;
    context.pedStates = std::vector<Behaviors::stateUID>(pedSet.getNumPedestrians());
    context.types = std::vector<Behaviors::stateUID>(pedSet.getNumPedestrians());

    Behaviors::Selector test;
    test.setAllTypes(Behaviors::pType{3});
    test.addSubSelector(Behaviors::SubSelector{0, Behaviors::pType{1}, Behaviors::selector_percent{0.5f}});
    test.addSubSelector(Behaviors::SubSelector{0, Behaviors::pType{2}, Behaviors::selector_percent{0.5f}});

    Behaviors::seed s = rand();

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

  Behaviors::BehaviorContext context;
  context.pedStates = std::vector<Behaviors::stateUID>(pedSet.getNumPedestrians());
  context.types = std::vector<Behaviors::stateUID>(pedSet.getNumPedestrians());

  Behaviors::Selector test;
  test.setAllTypes(Behaviors::pType{7});

  VIPRA::size subgroupCnt = static_cast<VIPRA::size>(144 * 0.3 * 0.1);
  test.addSubSelector(Behaviors::SubSelector{0, Behaviors::pType{1}, Behaviors::selector_percent{0.3f}});
  test.addSubSelector(Behaviors::SubSelector{1, Behaviors::pType{2}, Behaviors::selector_percent{0.1f}});
  test.addSubSelector(Behaviors::SubSelector{0, Behaviors::pType{4}, Behaviors::selector_percent{0.2f}});

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