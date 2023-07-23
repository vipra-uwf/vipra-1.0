// TODO (rolland) : fix this
// #include <gtest/gtest.h>

// #include "PedestrianLoader/calm_pedestrian_loader/calm_pedestrian_loader.hpp"
// #include "PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp"
// #include "definitions/type_definitions.hpp"

// #include "test_values/test_values.hpp"

// TEST(Calm_Pedestrian_Set, Initialize) {
//   std::unique_ptr<CalmPedData> data = std::make_unique<CalmPedData>();
//   data->positions = ped_positions;
//   data->masses = ped_masses;
//   data->shoulderLengths = ped_shoulderLengths;
//   data->desiredSpeeds = ped_desiredSpeeds;
//   data->reactionTimes = ped_reactionTimes;

//   CalmPedestrianSet test;
//   test.initialize(std::move(data));

//   const auto coords = test.getPedestrianCoordinates();
//   const auto vels = test.getVelocities();
//   const auto masses = test.getMasses();
//   const auto rtimes = test.getReactionTimes();
//   const auto dspeeds = test.getDesiredSpeeds();
//   const auto slens = test.getShoulderLengths();

//   for (VIPRA::idx i = 0; i < coords.size(); ++i) {
//     EXPECT_EQ(VIPRA::f3d(0, 0, 0), vels.at(i));
//     EXPECT_EQ(ped_positions.at(i), coords.at(i));
//     EXPECT_EQ(ped_masses.at(i), masses.at(i));
//     EXPECT_EQ(ped_reactionTimes.at(i), rtimes.at(i));
//     EXPECT_EQ(ped_desiredSpeeds.at(i), dspeeds.at(i));
//     EXPECT_EQ(ped_shoulderLengths.at(i), slens.at(i));
//   }
// }

// TEST(Calm_Pedestrian_Set, Update_State) {
//   std::unique_ptr<CalmPedData> data = std::make_unique<CalmPedData>();
//   data->positions = ped_positions;
//   data->masses = ped_masses;
//   data->shoulderLengths = ped_shoulderLengths;
//   data->desiredSpeeds = ped_desiredSpeeds;
//   data->reactionTimes = ped_reactionTimes;

//   std::shared_ptr<VIPRA::State> update_data = std::make_shared<VIPRA::State>(data->positions.size());
//   update_data->pedestrianCoordinates = update_ped_positions;
//   update_data->velocities = update_ped_velocities;

//   CalmPedestrianSet test;
//   test.initialize(std::move(data));

//   test.updateState(update_data);

//   const auto coords = test.getPedestrianCoordinates();
//   const auto vels = test.getVelocities();
//   const auto masses = test.getMasses();
//   const auto rtimes = test.getReactionTimes();
//   const auto dspeeds = test.getDesiredSpeeds();
//   const auto slens = test.getShoulderLengths();

//   for (VIPRA::idx i = 0; i < coords.size(); ++i) {
//     EXPECT_EQ(update_ped_velocities.at(i), vels.at(i));
//     EXPECT_EQ(update_ped_positions.at(i), coords.at(i));
//     EXPECT_EQ(ped_masses.at(i), masses.at(i));
//     EXPECT_EQ(ped_reactionTimes.at(i), rtimes.at(i));
//     EXPECT_EQ(ped_desiredSpeeds.at(i), dspeeds.at(i));
//     EXPECT_EQ(ped_shoulderLengths.at(i), slens.at(i));
//   }
// }