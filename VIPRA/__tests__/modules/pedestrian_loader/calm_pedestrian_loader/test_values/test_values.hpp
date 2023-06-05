#ifndef CALM_PEDESTRIAN_LOADER_TEST_VALUES
#define CALM_PEDESTRIAN_LOADER_TEST_VALUES

#include "definitions/dimensions.hpp"

std::vector<float> good_masses = {
    1.00,
    1.00,
    1.00,
    1.00,
    1.00,
};

std::vector<float> good_reactions = {
    0.4,
    0.4,
    0.4,
    0.4,
    0.4,
};

std::vector<float> good_speeds = {
    1.00,
    1.00,
    1.00,
    1.00,
    1.00,
};

std::vector<float> good_shoulders = {
    0.25,
    0.25,
    0.25,
    0.25,
    0.25,
};

VIPRA::f3dVec good_coords = {VIPRA::f3d{0.89, 3.1, 0},
                             VIPRA::f3d{1.68, 3.1, 0},
                             VIPRA::f3d{2.47, 3.1, 0},
                             VIPRA::f3d{3.25, 3.1, 0},
                             VIPRA::f3d{4.04, 3.1, 0}};

#endif