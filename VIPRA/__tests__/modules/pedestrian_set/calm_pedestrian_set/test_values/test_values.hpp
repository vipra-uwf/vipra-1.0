#ifndef CALM_PEDESTRIAN_SET_TEST_VALUES
#define CALM_PEDESTRIAN_SET_TEST_VALUES

#include "PedestrianLoader/calm_pedestrian_loader/calm_pedestrian_loader.hpp"
#include "definitions/dimensions.hpp"

VIPRA::f3dVec      ped_positions = {VIPRA::f3d{0, 1}, VIPRA::f3d{1, 2}, VIPRA::f3d{3, 4}, VIPRA::f3d{4, 5}};
std::vector<float> ped_masses = {1, 2, 3, 4};
std::vector<float> ped_shoulderLengths = {.25, .3, 1, 2.75};
std::vector<float> ped_desiredSpeeds = {.26, .4, 2, 3.75};
std::vector<float> ped_reactionTimes = {.27, .5, 3, 4.75};

VIPRA::f3dVec update_ped_positions = {VIPRA::f3d{10, 11}, VIPRA::f3d{11, 12}, VIPRA::f3d{13, 14}, VIPRA::f3d{14, 15}};
VIPRA::f3dVec update_ped_velocities = {VIPRA::f3d{1.2, 5.3},
                                       VIPRA::f3d{9.1, 1.2},
                                       VIPRA::f3d{1, 500},
                                       VIPRA::f3d{3.523, 4.6}};

#endif