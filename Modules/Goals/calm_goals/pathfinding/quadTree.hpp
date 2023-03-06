#ifndef CALM_GOALS_QUAD_TREE_HPP
#define CALM_GOALS_QUAD_TREE_HPP

#include <obstacle_set/obstacle_set.hpp>

#include "quad.hpp"

namespace CalmPath {
class QuadTree {
 public:
  QuadTree() = default;
  ~QuadTree();

  Quad* search(VIPRA::f3d) const;
  void  build(const ObstacleSet&, float quadSize, float closestObs);

  std::string toString() const;

 private:
  Quad* root = nullptr;

  Quad* constructQuad(const ObstacleSet& obsSet, VIPRA::f3d center, float size, float minSize, float closestObs);
  void  buildAdjacencies(Quad*);
  void  getAdjacencies(Quad*, Quad*);

  void clean(Quad*);
  bool inside(VIPRA::f3d point, VIPRA::f3d center, float size) const;

  void addQuadToString(Quad*, std::string&) const;
  void addAdjToString(Quad*, std::string&) const;
};
}  // namespace CalmPath

#endif