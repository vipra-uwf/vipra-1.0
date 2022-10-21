#ifndef CALM_GOALS_PATHFINDING_HPP
#define CALM_GOALS_PATHFINDING_HPP

#include "adjacencyGraph.hpp"
#include <algorithm>
#include <optional>
#include <queue>
#include <vector>

namespace CalmPath {

struct ANode {
  Node*  node;
  ANode* parent = nullptr;
  float  g;
  float  f;
};

float                  distance(Node*, Node*);
std::queue<Dimensions> constructPath(Dimensions, Dimensions, ANode*);

auto compare = [](ANode* first, ANode* second) {
  return first->f < second->f;
};

/**
 * @brief priority queue with custom search function
 */
struct pQueue : public std::priority_queue<ANode*, std::vector<ANode*>, decltype(compare)> {

  pQueue() : std::priority_queue<ANode*, std::vector<ANode*>, decltype(compare)>(compare) {}

  std::optional<ANode*> search(ANode* node) {
    auto a = std::find_if(c.begin(), c.end(), [&](ANode* n) { return node->node == n->node; });
    if (a == c.end()) {
      return std::nullopt;
    } else {
      return std::optional<ANode*>{*a};
    }
  }
};

ANode*
makeNode(Node* node, ANode* parent, float g, float f, std::vector<ANode*>& allocator) {
  allocator.emplace_back(new ANode{node, parent, g, f});
  return allocator.at(allocator.size() - 1);
}

/**
 * @brief Finds the path for a given start and end node, using A*
 *
 * @param start
 * @param end
 * @param graph
 * @return std::queue<Dimensions>
 */
std::queue<Dimensions>
pathFind(Dimensions start, Dimensions end, const Graph& g) {

  // find grid Nodes the start and end reside in (flipped since the path is created in reverse)
  Node* first = g.search(end);
  Node* last = g.search(start);

  // create datastructures
  std::vector<ANode*> allocList;
  CalmPath::pQueue    open_list;
  std::vector<ANode*> closed_list{};

  // add start first node to "open list"
  open_list.emplace(makeNode(first, nullptr, 0, distance(first, last), allocList));

  ANode* curr = nullptr;

  // while there are still nodes in the open list
  while (!open_list.empty()) {
    curr = open_list.top();

    if (curr->node == last) {
      // if the end node has been found, create the path, delete the created objects, return the path
      std::queue<Dimensions> path{constructPath(start, end, curr)};
      std::for_each(allocList.begin(), allocList.end(), [](ANode* ptr) { delete ptr; });
      return path;
    }

    // move current node to the closed list
    open_list.pop();
    closed_list.push_back(curr);

    for (Node* neighbor : curr->node->adj) {
      if (!std::any_of(
              closed_list.begin(), closed_list.end(), [&](ANode* n) { return n->node == neighbor; })) {
        // if the neighbor hasn't been visited yet, calculate it's cost
        float  g = curr->g + distance(neighbor, curr->node);
        float  f = g + distance(neighbor, last);
        ANode* neighborNode = makeNode(neighbor, curr, g, f, allocList);

        auto found = open_list.search(neighborNode);
        if (!found.has_value()) {
          // if the neighbor isn't already in the open list, add it
          open_list.push(neighborNode);
        } else {
          // if the neighbor is in the list check if the new path to it is cheaper, if so replace its values with the cheaper path
          if (neighborNode->g < found.value()->g) {
            found.value()->g = neighborNode->g;
            found.value()->parent = neighborNode->parent;
          }
        }
      }
    }
  }

  // no path was found, clear the data, return empty queue
  std::for_each(allocList.begin(), allocList.end(), [](ANode* ptr) { delete ptr; });
  return std::queue<Dimensions>{};
}

/**
 * @brief 
 * 
 * @param first 
 * @param second 
 * @return float 
 */
inline float
distance(Node* first, Node* second) {
  return first->center.distanceTo(second->center);
}

std::queue<Dimensions>
constructPath(Dimensions start, Dimensions goal, ANode* end) {
  // create queue by traversing the path, add the start and end, return
  std::queue<Dimensions> path;
  path.push(start);
  ANode* iter = end;
  while (iter != nullptr) {
    path.push(iter->node->center);
    iter = iter->parent;
  }
  path.push(goal);
  return path;
}
}  // namespace CalmPath
#endif