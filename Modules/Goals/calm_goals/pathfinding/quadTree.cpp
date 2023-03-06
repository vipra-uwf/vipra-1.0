
#include <spdlog/spdlog.h>

#include "quadTree.hpp"

namespace CalmPath {
QuadTree::~QuadTree() {
  clean(root);
}

void
QuadTree::clean(Quad* node) {
  if (node != nullptr) {
    clean(node->botleft);
    clean(node->topleft);
    clean(node->botright);
    clean(node->topright);
    delete node;
  }
}

Quad*
QuadTree::search(VIPRA::f3d coord) const {
  Quad* curr = nullptr;
  Quad* next = root;
  while (next != nullptr) {
    curr = next;
    if (coord.x < curr->center.x) {
      if (coord.y < curr->center.y) {
        next = curr->botleft;
      } else {
        next = curr->topleft;
      }
    } else {
      if (coord.y < curr->center.y) {
        next = curr->botright;
      } else {
        next = curr->topright;
      }
    }
  }
  return curr;
}

void
QuadTree::build(const ObstacleSet& obsSet, float quadSize, float closestObs) {
  const VIPRA::f3d mapRes = obsSet.getMapDimensions();
  float            mapSize = std::max(mapRes.x, mapRes.y);
  root = constructQuad(obsSet, VIPRA::f3d{mapSize / 2, mapSize / 2}, mapSize, quadSize, closestObs);
  buildAdjacencies(root);
}

Quad*
QuadTree::constructQuad(const ObstacleSet& obsSet, VIPRA::f3d center, float size, float minSize, float closestObs) {
  Quad* tl = nullptr;
  Quad* tr = nullptr;
  Quad* bl = nullptr;
  Quad* br = nullptr;

  float      x = center.x;
  float      y = center.y;
  bool       trav = true;
  bool       buffer = false;
  const auto nearest = obsSet.nearestObstacle(center);

  bool ins = inside(nearest, center, size);
  bool buf = nearest.distanceTo(center) <= closestObs;

  if (buf && !ins) {
    buffer = true;
  }

  if (ins || buf) {
    float newsize = size / 2;
    if (newsize < minSize) {
      trav = false;
    } else {
      tl = constructQuad(obsSet, VIPRA::f3d{x - newsize / 2, y + newsize / 2}, newsize, minSize, closestObs);
      tr = constructQuad(obsSet, VIPRA::f3d{x + newsize / 2, y + newsize / 2}, newsize, minSize, closestObs);
      bl = constructQuad(obsSet, VIPRA::f3d{x - newsize / 2, y - newsize / 2}, newsize, minSize, closestObs);
      br = constructQuad(obsSet, VIPRA::f3d{x + newsize / 2, y - newsize / 2}, newsize, minSize, closestObs);
    }
  }
  return new Quad(center, size, trav, buffer, tl, tr, bl, br);
}

void
QuadTree::buildAdjacencies(Quad* curr) {
  if (curr == nullptr)
    return;

  buildAdjacencies(curr->topleft);
  buildAdjacencies(curr->topright);
  buildAdjacencies(curr->botleft);
  buildAdjacencies(curr->botright);

  getAdjacencies(curr, root);
}

void
QuadTree::getAdjacencies(Quad* from, Quad* to) {
  if (to == nullptr || !from->traversable)
    return;

  getAdjacencies(from, to->topleft);
  getAdjacencies(from, to->topright);
  getAdjacencies(from, to->botleft);
  getAdjacencies(from, to->botright);

  // travel along line between nodes
  // check if grid at point is traversable
  if (to->traversable && from != to) {
    VIPRA::f3d checkPoint = from->center;
    float      d = (from->center.distanceTo(to->center) / 0.01);
    float      dx = (to->center.x - from->center.x) / d;
    float      dy = (to->center.y - from->center.y) / d;
    VIPRA::f3d move{dx, dy};
    Quad*      curr = from;
    while (curr != nullptr && curr != to) {
      checkPoint += move;
      curr = search(checkPoint);
      if (!curr->traversable) {
        return;
      }
      if (curr == to || inside(checkPoint, to->center, 0.01)) {
        from->adj.push_back(to);
        return;
      }
    }
  }
}

bool
QuadTree::inside(VIPRA::f3d point, VIPRA::f3d center, float size) const {
  VIPRA::f3d tl{center.x - size / 2, center.y + size / 2};
  VIPRA::f3d br{center.x + size / 2, center.y - size / 2};
  return (point.x >= tl.x && point.x <= br.x && point.y <= tl.y && point.y >= br.y);
}

void
QuadTree::addQuadToString(Quad* node, std::string& str) const {
  if (node != nullptr) {
    str += fmt::format("{{\"x\":{} , \"y\":{}, \"size\":{}, \"trav\":{}, \"buffer\":{}, \"adj\":[",
                       node->center.x,
                       node->center.y,
                       node->size,
                       (node->traversable ? "true" : "false"),
                       (node->buffer ? "true" : "false"));

    addAdjToString(node, str);
    str += "]},";
    addQuadToString(node->topleft, str);
    addQuadToString(node->topright, str);
    addQuadToString(node->botleft, str);
    addQuadToString(node->botright, str);
  }
}

void
QuadTree::addAdjToString(Quad* node, std::string& str) const {
  if (node != nullptr) {
    for (const auto adj : node->adj) {
      str += fmt::format("{{\"x\": {}, \"y\": {}}},", adj->center.x, adj->center.y);
    }
    if (node->adj.size() > 0) {
      str.pop_back();
    }
  }
}

std::string
QuadTree::toString() const {
  std::string treeStr = "{ \"Quads\":[";
  addQuadToString(root, treeStr);
  treeStr.pop_back();
  treeStr += "]}";
  return treeStr;
}

}  // namespace CalmPath