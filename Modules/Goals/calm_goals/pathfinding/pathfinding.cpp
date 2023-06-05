#include <spdlog/spdlog.h>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <iostream>

#include "pathfinding.hpp"

namespace CalmPath {

struct AGridPoint {
  GridPoint*  node;
  AGridPoint* parent = nullptr;
  float       g;
  float       f;

  bool operator==(const AGridPoint rightObject) const {
    return (node == rightObject.node && parent == rightObject.parent && g == rightObject.g && f == rightObject.f);
  }
};

//breadcrumb approach with a key-value pair of grid space and next grid space.
std::unordered_map<GridPoint*, GridPoint*, GridPointHash> breadCrumbMap;

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

inline void 
reverseQueue(std::queue<VIPRA::f3d>& queue) {
  std::stack<VIPRA::f3d> stack;

  while (!queue.empty()) {
    stack.push(queue.front());
    queue.pop();
  }

  while (!stack.empty()) {
    queue.push(stack.top());
    stack.pop();
  }
}

inline std::queue<VIPRA::f3d>
constructPath(VIPRA::f3d start, AGridPoint* end) {
  std::queue<VIPRA::f3d> path;
  AGridPoint*            iter = end->parent;
  AGridPoint*            prev = iter;

  VIPRA::f3d dif{0, 0, 0};

  path.push(end->node->center);
  
  while (iter != nullptr) {
    auto currDif = iter->node->center - prev->node->center;
    if (currDif != dif) {
      path.push(prev->node->center);
      dif = currDif;
    }

    if (prev != end->parent) 
      breadCrumbMap[iter->node] = prev->node;

    prev = iter;
    iter = iter->parent;

  }

  path.push(start);
  reverseQueue(path);
  return path;
}

inline float 
calculateAngle(GridPoint* point1, GridPoint* point2, GridPoint* point3) {
  float dx1 = point1->center.x - point2->center.x;
  float dy1 = point1->center.y - point2->center.y;
  float dx2 = point3->center.x - point2->center.x;
  float dy2 = point3->center.y - point2->center.y;

  float angle1 = std::atan2(dy1, dx1);
  float angle2 = std::atan2(dy2, dx2);

  float angle = angle1 - angle2;

  // Convert angle to the range [0, 2*pi]
  while (angle < 0.0f) {
    angle += 2.0f * M_PI;
  }

  // Convert angle to the range [0, 360]
  angle *= 180.0f / M_PI;

  return angle;
}

inline float
cost(GridPoint* first, GridPoint* goal) {
  const auto dif = 0.8 * std::abs(first->center.x - goal->center.x) + 2 * std::abs(first->center.y - goal->center.y);
  return dif;
}

inline AGridPoint*
makeGridPoint(GridPoint* node, AGridPoint* parent, float g, float f, std::vector<AGridPoint*>& allocator) {
  allocator.emplace_back(new AGridPoint{node, parent, g, f});
  return allocator.at(allocator.size() - 1);
}

static int count = 0;

std::queue<VIPRA::f3d>
pathFind(VIPRA::f3d start, VIPRA::f3d end, PathingGraph& graph) {
  count++;
  // find grid GridPoints the start and end reside in (flipped since the path is
  // created in reverse)
  GridPoint* first = graph.search(start);
  GridPoint* last = graph.search(end);

  // create datastructures
  std::vector<AGridPoint*> allocList;
  pQueue                   open_list;
  std::unordered_set<GridPoint*> closed_list;

  // add start first node to "open list"
  open_list.emplace(makeGridPoint(first, nullptr, 0, cost(first, last), allocList));

  AGridPoint* curr = nullptr;
  AGridPoint* prev = nullptr;

  // while there are still nodes in the open list
  while (!open_list.empty()) {
    prev = curr;
    curr = open_list.top();

    if (curr->node == last) { 
      // if the end node has been found, create the path, delete the created
      // objects, return the path
      std::queue<VIPRA::f3d> path{constructPath(start, curr)};
      std::for_each(allocList.begin(), allocList.end(), [](AGridPoint* ptr) { delete ptr; });
      return path;
    }

    // move current node to the closed list
    open_list.pop();
    closed_list.insert(curr->node);

    if (breadCrumbMap.count(curr->node) > 0 /*3 == 4*/) {
      float angle = calculateAngle(prev->node, curr->node, breadCrumbMap[curr->node]);
      if (angle < 181) {
        GridPoint*  neighbor = breadCrumbMap[curr->node];
        float       g = curr->g + neighbor->center.distanceTo(curr->node->center);
        float       f = g + cost(neighbor, last);
        AGridPoint* neighborGridPoint = makeGridPoint(neighbor, curr, g, f, allocList);

        auto found = open_list.search(neighborGridPoint);
        if (!found.has_value()) {
          open_list.push(neighborGridPoint);
        } else {
          if (neighborGridPoint->f < found.value()->f) {
            found.value()->g = neighborGridPoint->g;
            found.value()->parent = neighborGridPoint->parent;
          }
        }
        continue;
      }   
    }

    for (GridPoint* neighbor : curr->node->adj) {
      if (closed_list.find(neighbor) == closed_list.end()) { 
        // if the neighbor hasn't been visited yet, calculate it's cost
        float       g = curr->g + neighbor->center.distanceTo(curr->node->center);
        float       f = g + cost(neighbor, last);
        AGridPoint* neighborGridPoint = makeGridPoint(neighbor, curr, g, f, allocList);

        auto found = open_list.search(neighborGridPoint);
        if (!found.has_value()) {
          // if the neighbor isn't already in the open list, add it
          open_list.push(neighborGridPoint);
        } else {
          // if the neighbor is in the list check if the new path to it is
          // cheaper, if so replace its values with the cheaper path
          if (neighborGridPoint->f < found.value()->f) {
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
