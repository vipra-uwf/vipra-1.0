#ifndef CALM_GOALS_PATHFINDING_HPP
#define CALM_GOALS_PATHFINDING_HPP

#include "adjacencyGraph.hpp"
#include <algorithm>
#include <iostream>
#include <optional>
#include <queue>
#include <vector>

namespace CalmPath {
struct AQuad {
  Quad*  node;
  AQuad* parent = nullptr;
  float  g;
  float  f;
};

inline auto compare = [](AQuad* first, AQuad* second) {
  return first->f > second->f;
};

/**
 * @brief priority queue with custom search function
 */
struct pQueue : public std::priority_queue<AQuad*, std::vector<AQuad*>, decltype(compare)> {

  pQueue() : std::priority_queue<AQuad*, std::vector<AQuad*>, decltype(compare)>(compare) {}

  std::optional<AQuad*> search(AQuad* node) {
    auto a = std::find_if(c.begin(), c.end(), [&](AQuad* n) { return node->node == n->node; });
    if (a == c.end()) {
      return std::nullopt;
    } else {
      return std::optional<AQuad*>{*a};
    }
  }
};

inline AQuad*
makeQuad(Quad* node, AQuad* parent, float g, float f, std::vector<AQuad*>& allocator) {
  allocator.emplace_back(new AQuad{node, parent, g, f});
  return allocator.at(allocator.size() - 1);
}

/**
 * @brief
 *
 * @param first
 * @param second
 * @return float
 */
inline float
cost(Quad* first, Quad* goal, float diagonalCost) {
  float dx = first->center.x - goal->center.x;
  float dy = first->center.y - goal->center.y;
  float d_max = (dx > dy ? dx : dy);
  float d_min = (dx < dy ? dx : dy);
  return (diagonalCost * d_min) + (d_max - d_min);
}

inline std::queue<VIPRA::f3d>
constructPath(VIPRA::f3d goal, AQuad* end) {
  // create queue by traversing the path, add the start and end, return
  std::queue<VIPRA::f3d> path;
  AQuad*                 iter = end;
  while (iter != nullptr) {
    path.push(iter->node->center);
    iter = iter->parent;
  }
  path.push(goal);
  return path;
}

/**
 * @brief Finds the path for a given start and end node, using A*
 *
 * @param start
 * @param end
 * @param graph
 * @return std::queue<VIPRA::f3d>
 */
inline std::queue<VIPRA::f3d>
pathFind(VIPRA::f3d start, VIPRA::f3d end, const Graph& g, float diagonalCost) {

  // find grid Quads the start and end reside in (flipped since the path is
  // created in reverse)
  Quad* first = g.search(end);
  Quad* last = g.search(start);

  // create datastructures
  std::vector<AQuad*> allocList;
  pQueue              open_list;
  std::vector<AQuad*> closed_list{};

  // add start first node to "open list"
  open_list.emplace(makeQuad(first, nullptr, 0, cost(first, last, diagonalCost), allocList));

  AQuad* curr = nullptr;

  // while there are still nodes in the open list
  while (!open_list.empty()) {
    curr = open_list.top();

    if (curr->node == last) {
      // if the end node has been found, create the path, delete the created
      // objects, return the path
      std::queue<VIPRA::f3d> path{constructPath(end, curr)};
      std::for_each(allocList.begin(), allocList.end(), [](AQuad* ptr) { delete ptr; });
      return path;
    }

    // move current node to the closed list
    open_list.pop();
    closed_list.push_back(curr);

    for (Quad* neighbor : curr->node->adj) {
      if (!std::any_of(
              closed_list.begin(), closed_list.end(), [&](AQuad* n) { return n->node == neighbor; })) {
        // if the neighbor hasn't been visited yet, calculate it's cost
        float  g = curr->g + neighbor->center.distanceTo(curr->node->center);
        float  f = g + cost(neighbor, last, diagonalCost);
        AQuad* neighborQuad = makeQuad(neighbor, curr, g, f, allocList);

        auto found = open_list.search(neighborQuad);
        if (!found.has_value()) {
          // if the neighbor isn't already in the open list, add it
          open_list.push(neighborQuad);
        } else {
          // if the neighbor is in the list check if the new path to it is
          // cheaper, if so replace its values with the cheaper path
          if (neighborQuad->g < found.value()->g) {
            found.value()->g = neighborQuad->g;
            found.value()->parent = neighborQuad->parent;
          }
        }
      }
    }
  }

  // no path was found, clear the data, return empty queue
  std::for_each(allocList.begin(), allocList.end(), [](AQuad* ptr) { delete ptr; });
  LJ::Warn(simLogger,
           "Calm_Goals: No Path Found for Pedestrian at position: x:{}, y:{}, z:{}",
           start.x,
           start.y,
           start.z);
  return std::queue<VIPRA::f3d>{};
}

}  // namespace CalmPath
#endif