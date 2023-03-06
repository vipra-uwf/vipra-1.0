#ifndef CALM_GOALS_PATHFINDING_HPP
#define CALM_GOALS_PATHFINDING_HPP

#include <optional>
#include <queue>

#include "pathing_graph.hpp"

namespace CalmPath {

std::queue<VIPRA::f3d> pathFind(VIPRA::f3d start, VIPRA::f3d end, PathingGraph&);

}  // namespace CalmPath

#endif