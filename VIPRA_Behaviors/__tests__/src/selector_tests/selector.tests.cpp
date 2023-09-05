
#include <filesystem>
#include <iostream>

#include <gtest/gtest.h>

#include <mocks/goals/goals.mock.hpp>
#include <mocks/obstacle_set/obstacle_set.mock.hpp>
#include <mocks/pedestrian_set/pedestrian_set.mock.hpp>

#include <definitions/dsl_types.hpp>
#include <definitions/pedestrian_types.hpp>
#include <selectors/pedestrian_groups.hpp>

#include <selectors/selector.hpp>
#include <selectors/selector_percent.hpp>
#include <selectors/subselector.hpp>

// using ::testing::Return;

// TEST(Selector, NoDupes) {

//   ObstacleSetMock   obsSet;
//   PedestrianSetMock pedSet;
//   GoalsMock         goals;

//   EXPECT_CALL(pedSet, getNumPedestrians()).WillRepeatedly(Return(144));

//   srand(0);
//   for (int x = 0; x < 5; ++x) {

//     BHVR::BehaviorContext context;
//     context.pedStates = std::vector<BHVR::stateUID>(pedSet.getNumPedestrians());
//     context.types = std::vector<BHVR::stateUID>(pedSet.getNumPedestrians());

//     BHVR::Selector test;
//     test.setAllTypes(BHVR::Ptype{3});
//     test.addSubSelector(BHVR::SubSelector{0, BHVR::Ptype{1}, false, BHVR::SelectorPercent{0.5F}});
//     test.addSubSelector(BHVR::SubSelector{0, BHVR::Ptype{2}, false, BHVR::SelectorPercent{0.5F}});

//     BHVR::seed s = rand();

//     test.initialize("test", s, context, pedSet, obsSet, goals);

//     const auto& groups = test.getGroups();

//     for (VIPRA::idx i = 0; i < groups.at(1).size(); ++i) {
//       for (VIPRA::idx j = 0; j < groups.at(2).size(); ++j) {
//         EXPECT_NE(groups.at(1)[i], groups.at(2)[j]);
//       }
//     }
//   }
// }

// TEST(Selector, SubGroups) {
//   ObstacleSetMock   obsSet;
//   PedestrianSetMock pedSet;
//   GoalsMock         goals;

//   EXPECT_CALL(pedSet, getNumPedestrians()).WillRepeatedly(Return(144));

//   BHVR::BehaviorContext context;
//   context.pedStates = std::vector<BHVR::stateUID>(pedSet.getNumPedestrians());
//   context.types = std::vector<BHVR::stateUID>(pedSet.getNumPedestrians());

//   BHVR::Selector test;
//   test.setAllTypes(BHVR::Ptype{7});

//   auto subgroupCnt = static_cast<VIPRA::size>(144 * 0.3 * 0.1);
//   test.addSubSelector(BHVR::SubSelector{0, BHVR::Ptype{1}, false, BHVR::SelectorPercent{0.3F}});
//   test.addSubSelector(BHVR::SubSelector{1, BHVR::Ptype{2}, false, BHVR::SelectorPercent{0.1F}});
//   test.addSubSelector(BHVR::SubSelector{0, BHVR::Ptype{4}, false, BHVR::SelectorPercent{0.2F}});

//   test.initialize("test", 123, context, pedSet, obsSet, goals);

//   const auto& groups = test.getGroups();

//   EXPECT_EQ(groups.at(2).size(), subgroupCnt);

//   VIPRA::size counter = 0;
//   for (VIPRA::idx i = 0; i < groups.at(2).size(); ++i) {
//     for (VIPRA::idx j = 0; j < groups.at(1).size(); ++j) {
//       if (groups.at(2)[i] == groups.at(1)[j]) {
//         ++counter;
//       }
//     }
//   }

//   EXPECT_EQ(counter, subgroupCnt);
// }