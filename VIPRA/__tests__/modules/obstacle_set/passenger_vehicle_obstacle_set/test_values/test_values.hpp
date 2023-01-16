
#ifndef PVOS_TEST_VALUES_HPP
#define PVOS_TEST_VALUES_HPP

#include "definitions/config_map.hpp"
#include "definitions/dimensions.hpp"

const VIPRA::ConfigMap configuration = {{"obstacleCollisionDistance", "0.05"}};

const VIPRA::f3dVec            goodmap_obstacles = {VIPRA::f3d{0, 3.46}, VIPRA::f3d{0, 0}, VIPRA::f3d{5, 7}};
const VIPRA::f3dVec            goodmap_seats = {VIPRA::f3d{0.89, 3.1},
                                                VIPRA::f3d{1.68, 3.1},
                                                VIPRA::f3d{2.47, 3.1},
                                                VIPRA::f3d{3.25, 3.1}};
const std::vector<std::string> goodmap_types = {"exit", "endOfAisle", "aisle", "seat", "obstacle"};

#endif