#include <cmath>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#include <spdlog/spdlog.h>

#include "pathfinding.hpp"

namespace CALM_PATH {

/**
 * @struct AGridPoint
 * @brief A struct that represents a section on a grid.
 *
 * This struct provides implementations for an AStar algorithm as it needs a heuristic 
 * and parent nodes to generate a path. 
 */
struct AGridPoint {
  GridPoint*  node{};
  AGridPoint* parent = nullptr;
  float       distanceFromStart{};
  float       distanceWithHeuristic{};

  bool operator==(const AGridPoint rightObject) const {
    return (node == rightObject.node && parent == rightObject.parent &&
            distanceFromStart == rightObject.distanceFromStart &&
            distanceWithHeuristic == rightObject.distanceWithHeuristic);
  }
};

//breadcrumb approach with a key-value pair of grid space and next grid space.
std::unordered_map<GridPoint*, GridPoint*, GridPointHash> breadCrumbMap;

/**
 * @class GridPointCompare
 * @brief A class that compares the heuristic distance of two AGridPoint objects passed in.
 *
 */
class GridPointCompare {
 public:
  bool operator()(AGridPoint* first, AGridPoint* second) {
    return first->distanceWithHeuristic > second->distanceWithHeuristic;
  }
};

/**
 * @struct pQueue
 * @brief A struct that represents a priority queue for AGridPoint objects..
 *
 * This struct provides implementations for evaluating the shortest path from the start
 * to end using AStar as this algorithm requires a priority queue to always evaluate
 * the smallest heuristic first.
 */
struct PQueue : public std::priority_queue<AGridPoint*, std::vector<AGridPoint*>,
                                           GridPointCompare> {
  /**
  * @brief determines if an AgridPoint object is in the priority queue and returns it if it is.
  *
  * @param node AGridPoint pointer being searched for. 
  * @return std::optional<AGridPoint*>
  */
  std::optional<AGridPoint*> search(AGridPoint* node) {
    auto gridPoint = std::find_if(c.begin(), c.end(),
                                  [&](AGridPoint* n) { return node->node == n->node; });
    if (gridPoint == c.end()) {
      return std::nullopt;
    }
    return std::optional<AGridPoint*>{*gridPoint};
  }
};

/**
* @brief puts a queue in reverse order as the algorithm generates the end path backwards. 

* @param queue A queue that needs to be reversed. 
*/
inline void reverseQueue(std::queue<VIPRA::f3d>& queue) {
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

/**
* @brief generates a path using a trail of parent nodes from the end object.
*
* @param start A point that starts the path. 
* @param end An AGridPoint object at the end of the path. 
* @return std::queue<VIPRA::f3d>
*/
inline std::queue<VIPRA::f3d> constructPath(AGridPoint* end) {
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

    if (prev != end->parent) breadCrumbMap[iter->node] = prev->node;

    prev = iter;
    iter = iter->parent;
  }

  reverseQueue(path);
  return path;
}

/**
* @brief evaluates the heuristic cost of the AStar algorithm.
*
* Currently the heuristic is using he manhattan distance with a weighted amount, 
* prioritizing horizontal movement. 
* 
* @param first A GridPoint that represents current point on the path. 
* @param goal A GridPoint that represents the final point on the path. 
* @return float
*/
inline float cost(GridPoint* first, GridPoint* goal) {
  // const auto dif = 0.8 * std::abs(first->center.x - goal->center.x) +
  //                  2 * std::abs(first->center.y - goal->center.y);
  // return dif;
  return first->center.distanceTo(goal->center);
  //FIXME!! These values 0.8 and 2 help prioritize horizontal movement over vertical so that the paths remain smooth
  // allowing for the heuristic to shine. Instead these should be parameters passed in.
}

/**
* @brief creates an AGridPoint object.
*
* @param node GridPoint to keep track on the map. 
* @param parent AGridPoint to keep track of how to get to the node. 
* @param distanceFromStart total distance from the start. 
* @param distanceWithHeuristic total distance plus the heurstic to get to finish. 
* @param allocator
* @return AGridPoint*
*/
inline AGridPoint* makeGridPoint(GridPoint* node, AGridPoint* parent,
                                 float distanceFromStart, float distanceWithHeuristic,
                                 std::vector<AGridPoint*>& allocator) {
  allocator.emplace_back(
      new AGridPoint{node, parent, distanceFromStart, distanceWithHeuristic});
  return allocator.at(allocator.size() - 1);
}

/**
* @brief generates a path using an A Star algorithm
*
* @param start Initial starting point of the path. 
* @param end Desired end point of the path.
* @param graph The map that the path is built from.
* @return std::queue<VIPRA::f3d>
*/
std::queue<VIPRA::f3d> pathFind(VIPRA::f3d start, VIPRA::f3d end, PathingGraph& graph) {
  GridPoint* first = graph.search(start);
  GridPoint* last = graph.search(end);

  std::vector<AGridPoint*>       allocList;
  PQueue                         openList;
  std::unordered_set<GridPoint*> closedList;

  openList.emplace(makeGridPoint(first, nullptr, 0, cost(first, last), allocList));

  AGridPoint* curr = nullptr;

  while (!openList.empty()) {
    curr = openList.top();

    if (curr->node == last) {
      std::queue<VIPRA::f3d> path{constructPath(curr)};
      std::for_each(allocList.begin(), allocList.end(),
                    [](AGridPoint* ptr) { delete ptr; });
      return path;
    }

    openList.pop();
    closedList.insert(curr->node);

    if (breadCrumbMap.count(curr->node) > 0) {
      float distanceFromStart =
          curr->distanceFromStart +
          breadCrumbMap[curr->node]->center.distanceTo(curr->node->center);
      float distanceWithHeuristic =
          distanceFromStart + cost(breadCrumbMap[curr->node], last);
      AGridPoint* neighborGridPoint =
          makeGridPoint(breadCrumbMap[curr->node], curr, distanceFromStart,
                        distanceWithHeuristic, allocList);

      openList.push(neighborGridPoint);
    } else {
      for (GridPoint* neighbor : curr->node->adj) {
        if (closedList.find(neighbor) == closedList.end()) {
          float distanceFromStart =
              curr->distanceFromStart + neighbor->center.distanceTo(curr->node->center);
          float       distanceWithHeuristic = distanceFromStart + cost(neighbor, last);
          AGridPoint* neighborGridPoint = makeGridPoint(neighbor, curr, distanceFromStart,
                                                        distanceWithHeuristic, allocList);

          auto found = openList.search(neighborGridPoint);
          if (!found.has_value()) {
            openList.push(neighborGridPoint);
          } else {
            if (neighborGridPoint->distanceFromStart < found.value()->distanceFromStart) {
              found.value()->distanceFromStart = neighborGridPoint->distanceFromStart;
              found.value()->parent = neighborGridPoint->parent;
            }
          }
        }
      }
    }
  }

  std::for_each(allocList.begin(), allocList.end(), [](AGridPoint* ptr) { delete ptr; });
  spdlog::warn("Calm_Goals: No Path Found for Pedestrian at position: x:{}, y:{}, z:{}",
               start.x, start.y, start.z);
  return std::queue<VIPRA::f3d>{{start}};
}
}  // namespace CALM_PATH
