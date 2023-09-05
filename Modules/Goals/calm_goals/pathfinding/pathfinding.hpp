#ifndef CALM_GOALS_PATHFINDING_HPP
#define CALM_GOALS_PATHFINDING_HPP

#include <optional>
#include <queue>

#include "pathing_graph.hpp"

namespace CALM_PATH {

/**
* @brief generates a path using an A Star algorithm
*
* @param start Initial starting point of the path. 
* @param end Desired end point of the path.
* @param graph The map that the path is built from.
* @return std::queue<VIPRA::f3d>
*/
std::queue<VIPRA::f3d> pathFind(VIPRA::f3d start, VIPRA::f3d end, PathingGraph&);

}  // namespace CALM_PATH

#endif