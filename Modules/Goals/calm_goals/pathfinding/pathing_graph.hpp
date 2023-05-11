#ifndef VIPRA_CALM_PATHING_GRAPH_HPP
#define VIPRA_CALM_PATHING_GRAPH_HPP

#include <obstacle_set/obstacle_set.hpp>

namespace CalmPath {

struct GridPoint {
  VIPRA::f3d              center;
  std::vector<GridPoint*> adj;
  bool                    traversable;
  bool                    buffer;
  GridPoint(VIPRA::f3d pos, bool trav, bool buff) : center(pos), adj(), traversable(trav), buffer(buff) {}
};

class PathingGraph {
 public:
  GridPoint*  search(VIPRA::f3d);
  void        build(const ObstacleSet&, float gridSize, float obsBufferDist);
  std::string toString() const;

 private:
  std::vector<GridPoint> points;
  VIPRA::size            xCnt;
  VIPRA::size            yCnt;
  VIPRA::f3d             dimensions;
  float                  gridSize;

  void constructPoints(const ObstacleSet&, float obsBufferDist);

  void buildAdjacencies();
  void addAdjToString(const GridPoint& node, std::string& str) const;
};
}  // namespace CalmPath

#endif