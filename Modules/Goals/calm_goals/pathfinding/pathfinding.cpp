#include <spdlog/spdlog.h>

#include "pathfinding.hpp"

namespace CalmPath {

struct AQuad {
  Quad*  node;
  AQuad* parent = nullptr;
  float  g;
  float  f;
};

class QuadCompare {
 public:
  bool operator()(AQuad* first, AQuad* second) { return first->f > second->f; }
};

struct pQueue : public std::priority_queue<AQuad*, std::vector<AQuad*>, QuadCompare> {
  pQueue() : std::priority_queue<AQuad*, std::vector<AQuad*>, QuadCompare>() {}
  std::optional<AQuad*> search(AQuad* node);
};

std::optional<AQuad*>
pQueue::search(AQuad* node) {
  auto a = std::find_if(c.begin(), c.end(), [&](AQuad* n) { return node->node == n->node; });
  if (a == c.end()) {
    return std::nullopt;
  } else {
    return std::optional<AQuad*>{*a};
  }
}

inline std::queue<VIPRA::f3d>
constructPath(VIPRA::f3d goal, AQuad* end) {
  std::queue<VIPRA::f3d> path;
  AQuad*                 iter = end->parent;
  while (iter != nullptr) {
    path.push(iter->node->center);
    iter = iter->parent;
  }
  path.push(goal);
  return path;
}

inline float
diagonality(float d_min, float d_max) {
  if (d_max == 0) {
    return 0;
  }
  float rr = (std::abs(d_min) / std::abs(d_max)) - 0.5;
  float diag = (-5 * (rr * rr)) + 1;
  if (diag < 0) {
    diag = 0;
  }
  return diag;
}

inline float
cost(Quad* first, Quad* goal) {
  float dx = first->center.x - goal->center.x;
  float dy = first->center.y - goal->center.y;
  float d_max = (dx > dy ? dx : dy);
  float d_min = (dx < dy ? dx : dy);
  return d_max - d_min;
}

inline AQuad*
makeQuad(Quad* node, AQuad* parent, float g, float f, std::vector<AQuad*>& allocator) {
  allocator.emplace_back(new AQuad{node, parent, g, f});
  return allocator.at(allocator.size() - 1);
}

std::queue<VIPRA::f3d>
pathFind(VIPRA::f3d start, VIPRA::f3d end, const QuadTree& graph) {

  // find grid Quads the start and end reside in (flipped since the path is
  // created in reverse)
  Quad* first = graph.search(end);
  Quad* last = graph.search(start);

  // create datastructures
  std::vector<AQuad*> allocList;
  pQueue              open_list;
  std::vector<AQuad*> closed_list{};

  // add start first node to "open list"
  open_list.emplace(makeQuad(first, nullptr, 0, cost(first, last), allocList));

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
      if (!std::any_of(closed_list.begin(), closed_list.end(), [&](AQuad* n) { return n->node == neighbor; })) {
        // if the neighbor hasn't been visited yet, calculate it's cost
        float  g = curr->g + neighbor->center.distanceTo(curr->node->center);
        float  f = g + cost(neighbor, last);
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
  spdlog::warn("Calm_Goals: No Path Found for Pedestrian at position: x:{}, y:{}, z:{}", start.x, start.y, start.z);
  return std::queue<VIPRA::f3d>{};
}
}  // namespace CalmPath