#include <spdlog/spdlog.h>

#include "pathfinding.hpp"

namespace CalmPath {

struct AGridPoint {
  GridPoint*  node;
  AGridPoint* parent = nullptr;
  float       g;
  float       f;
};

class GridPointCompare {
 public:
  bool operator()(AGridPoint* first, AGridPoint* second) { return first->f > second->f; }
};

struct pQueue : public std::priority_queue<AGridPoint*, std::vector<AGridPoint*>, GridPointCompare> {
  pQueue() : std::priority_queue<AGridPoint*, std::vector<AGridPoint*>, GridPointCompare>() {}
  std::optional<AGridPoint*> search(AGridPoint* node);
};

std::optional<AGridPoint*>
pQueue::search(AGridPoint* node) {
  auto a = std::find_if(c.begin(), c.end(), [&](AGridPoint* n) { return node->node == n->node; });
  if (a == c.end()) {
    return std::nullopt;
  } else {
    return std::optional<AGridPoint*>{*a};
  }
}

inline std::queue<VIPRA::f3d>
constructPath(VIPRA::f3d goal, AGridPoint* end) {
  std::queue<VIPRA::f3d> path;
  AGridPoint*            iter = end->parent;
  AGridPoint*            prev = iter;

  VIPRA::f3d dif{0, 0, 0};

  while (iter != nullptr) {
    auto currDif = iter->node->center - prev->node->center;
    if (currDif != dif) {
      path.push(prev->node->center);
      dif = currDif;
    }
    prev = iter;
    iter = iter->parent;
  }

  path.push(goal);
  return path;
}

inline float
cost(GridPoint* first, GridPoint* goal) {
  const auto dif = goal->center - first->center;
  return dif.magnitudeSquared();
}

inline AGridPoint*
makeGridPoint(GridPoint* node, AGridPoint* parent, float g, float f, std::vector<AGridPoint*>& allocator) {
  allocator.emplace_back(new AGridPoint{node, parent, g, f});
  return allocator.at(allocator.size() - 1);
}

std::queue<VIPRA::f3d>
pathFind(VIPRA::f3d start, VIPRA::f3d end, PathingGraph& graph) {

  // find grid GridPoints the start and end reside in (flipped since the path is
  // created in reverse)
  GridPoint* first = graph.search(end);
  GridPoint* last = graph.search(start);

  // create datastructures
  std::vector<AGridPoint*> allocList;
  pQueue                   open_list;
  std::vector<AGridPoint*> closed_list{};

  // add start first node to "open list"
  open_list.emplace(makeGridPoint(first, nullptr, 0, cost(first, last), allocList));

  AGridPoint* curr = nullptr;

  // while there are still nodes in the open list
  while (!open_list.empty()) {
    curr = open_list.top();

    if (curr->node == last) {
      // if the end node has been found, create the path, delete the created
      // objects, return the path
      std::queue<VIPRA::f3d> path{constructPath(end, curr)};
      std::for_each(allocList.begin(), allocList.end(), [](AGridPoint* ptr) { delete ptr; });
      return path;
    }

    // move current node to the closed list
    open_list.pop();
    closed_list.push_back(curr);

    for (GridPoint* neighbor : curr->node->adj) {
      if (!std::any_of(closed_list.begin(), closed_list.end(), [&](AGridPoint* n) { return n->node == neighbor; })) {
        // if the neighbor hasn't been visited yet, calculate it's cost
        float       g = curr->g + neighbor->center.distanceTo(curr->node->center);
        float       f = g + cost(neighbor, first);
        AGridPoint* neighborGridPoint = makeGridPoint(neighbor, curr, g, f, allocList);

        auto found = open_list.search(neighborGridPoint);
        if (!found.has_value()) {
          // if the neighbor isn't already in the open list, add it
          open_list.push(neighborGridPoint);
        } else {
          // if the neighbor is in the list check if the new path to it is
          // cheaper, if so replace its values with the cheaper path
          if (neighborGridPoint->g < found.value()->g) {
            found.value()->g = neighborGridPoint->g;
            found.value()->parent = neighborGridPoint->parent;
          }
        }
      }
    }
  }

  // no path was found, clear the data, return empty queue
  std::for_each(allocList.begin(), allocList.end(), [](AGridPoint* ptr) { delete ptr; });
  spdlog::warn("Calm_Goals: No Path Found for Pedestrian at position: x:{}, y:{}, z:{}", start.x, start.y, start.z);
  return std::queue<VIPRA::f3d>{};
}
}  // namespace CalmPath