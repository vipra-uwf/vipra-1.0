#ifndef CALM_GOALS_TEST_VALUES_HPP
#define CALM_GOALS_TEST_VALUES_HPP

#include "definitions/dimensions.hpp"
#include "definitions/entitySet.hpp"

VIPRA::f3dVec goodmap_obstacles = {VIPRA::f3d{0, 3.46}, VIPRA::f3d{0, 0}, VIPRA::f3d{5, 7}};
VIPRA::f3dVec goodmap_seats = {VIPRA::f3d{0.89, 3.1}, VIPRA::f3d{1.68, 3.1}, VIPRA::f3d{2.47, 3.1}, VIPRA::f3d{3.25, 3.1}};

VIPRA::f3dVec goodmap_exits = {VIPRA::f3d{24.2, 3.5}};

VIPRA::f3dVec goodmap_endOfAisle = {VIPRA::f3d{24.1, 1.7}};

VIPRA::f3dVec goodmap_aisle = {VIPRA::f3d{0.89, 1.7}, VIPRA::f3d{1.68, 1.7}, VIPRA::f3d{2.47, 1.7}, VIPRA::f3d{3.25, 1.7}};

std::vector<std::string> goodmap_types = {"exit", "endOfAisle", "aisle", "seat", "obstacle"};

VIPRA::EntitySet map_value = {{"obstacle", goodmap_obstacles},
                              {"seat", goodmap_seats},
                              {"exit", goodmap_exits},
                              {"endOfAilse", goodmap_endOfAisle},
                              {"aisle", goodmap_aisle}};

VIPRA::f3dVec goodmap_pedestrians = {VIPRA::f3d{0.89, 3.1},
                                     VIPRA::f3d{1.68, 3.1},
                                     VIPRA::f3d{2.47, 3.1},
                                     VIPRA::f3d{3.25, 3.1}};

#endif