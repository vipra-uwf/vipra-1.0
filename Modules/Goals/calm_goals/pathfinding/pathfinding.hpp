#ifndef CALM_GOALS_PATHFINDING_HPP
#define CALM_GOALS_PATHFINDING_HPP

#include <optional>
#include <queue>

#include "quad.hpp"
#include "quadTree.hpp"

namespace CalmPath {

std::queue<VIPRA::f3d> pathFind(VIPRA::f3d start, VIPRA::f3d end, const QuadTree&, float diagCost);

}  // namespace CalmPath

#endif