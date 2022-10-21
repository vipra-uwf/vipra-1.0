#ifndef ADJACENCYGRAPH_HPP
#define ADJACENCYGRAPH_HPP

#include "../../../VIPRA/Base/definitions/type_definitions.hpp"
#include "../../../VIPRA/Extendable/obstacleset/obstacle_set.hpp"

namespace CalmPath {

struct Node {
  Dimensions         center;
  float              size;
  Node*              tl;
  Node*              tr;
  Node*              bl;
  Node*              br;
  std::vector<Node*> adj;
  Node(Dimensions center, float size, Node* tl, Node* tr, Node* bl, Node* br)
    : center(center), size(size), tl(tl), tr(tr), bl(bl), br(br) {}
  Node(Dimensions center, float size)
    : center(center), size(size), tl(nullptr), tr(nullptr), bl(nullptr), br(nullptr) {}
};

class Graph {
 public:
  ~Graph() { cleanNode(root); }

  void buildGraph(const ObstacleSet& obSet) {
    obs = &obSet;
    const Dimensions mapRes = obSet.getDimensions();
    root = construct({mapRes.axis[0] / 2, mapRes.axis[1] / 2}, mapRes.axis[0], obSet);

    buildAdjacencies(root);

    printf("[");
    printTree(root);
    printf("]");
  }

  [[nodiscard]] Node* search(Dimensions coords) const {
    Node* curr = nullptr;
    Node* next = root;
    while (next != nullptr) {
      curr = next;
      if (coords.axis[0] < curr->center.axis[0]) {
        if (coords.axis[1] < curr->center.axis[1]) {
          next = curr->bl;
        } else {
          next = curr->tl;
        }
      } else {
        if (coords.axis[1] < curr->center.axis[1]) {
          next = curr->br;
        } else {
          next = curr->tr;
        }
      }
    }
    return curr;
  }

 private:
  static constexpr float gridUnit = .1;
  const ObstacleSet*     obs;
  Node*                  root;

  void cleanNode(Node* node) {
    if (node != nullptr) {
      cleanNode(node->bl);
      cleanNode(node->tl);
      cleanNode(node->br);
      cleanNode(node->tr);
      delete node;
    }
  }

  void printTree(Node* root) {
    if (root != nullptr) {
      printf("{\"x\":%f , \"y\":%f, \"size\":%f, \"adjacencies\":[\n",
             root->center.axis[0],
             root->center.axis[1],
             root->size);
      for (auto node : root->adj) {
        printf("\t{\"x\": %f, \"y\": %f},\n", node->center.axis[0], node->center.axis[1]);
      }
      printf("]},\n");
      printTree(root->tl);
      printTree(root->tr);
      printTree(root->bl);
      printTree(root->br);
    }
  }

  void buildAdjacencies(Node* curr) {
    if (curr == nullptr)
      return;

    buildAdjacencies(curr->tl);
    buildAdjacencies(curr->tr);
    buildAdjacencies(curr->bl);
    buildAdjacencies(curr->br);

    getAdjacencies(curr, root);
  }

  void getAdjacencies(Node* first, Node* curr) {
    if (curr == nullptr)
      return;
    getAdjacencies(first, curr->tl);
    getAdjacencies(first, curr->tr);
    getAdjacencies(first, curr->bl);
    getAdjacencies(first, curr->br);

    if (obs->rayHit(first->center, curr->center) == -1) {
      first->adj.push_back(curr);
    }
  }

  Node* construct(Dimensions center, float size, const ObstacleSet& obSet) {
    if (size <= gridUnit) {
      return nullptr;
    }

    float x = center.axis[0];
    float y = center.axis[1];
    if (inside(obSet.nearestObstacle(center), center, size)) {
      Node* tl = construct({x - size / 4, y + size / 4}, size / 2, obSet);
      Node* tr = construct({x + size / 4, y + size / 4}, size / 2, obSet);
      Node* bl = construct({x - size / 4, y - size / 4}, size / 2, obSet);
      Node* br = construct({x + size / 4, y - size / 4}, size / 2, obSet);
      return new Node(center, size, tl, tr, bl, br);
    } else {
      return nullptr;
    }
  }

  bool inside(Dimensions point, Dimensions center, float size) {
    Dimensions tl = {center.axis[0] - size / 2, center.axis[1] + size / 2};
    Dimensions br = {center.axis[0] + size / 2, center.axis[1] - size / 2};
    bool i = (point.axis[0] >= tl.axis[0] && point.axis[0] <= br.axis[0] && point.axis[1] <= tl.axis[1] &&
              point.axis[1] >= br.axis[1]);
    return i;
  }
};
}  // namespace CalmPath
#endif