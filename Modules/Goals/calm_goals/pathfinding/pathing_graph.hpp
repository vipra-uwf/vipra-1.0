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
  
  bool vectorEq(const std::vector<GridPoint*>& first, const std::vector<GridPoint*>& second) const; 
  bool operator==(const GridPoint& rightObject) const {
    return (center == rightObject.center && vectorEq(adj, rightObject.adj) && traversable == rightObject.traversable && buffer == rightObject.buffer);
  }
};

struct GridPointHash {
  std::size_t operator() (const GridPoint& object) const {
    std::size_t seed = 0;

    seed += VIPRA::F3dHash{}(object.center);
    for (const GridPoint* adjPoint : object.adj) {
      seed += reinterpret_cast<std::size_t>(adjPoint);
    }
    seed += std::hash<bool>{}(object.traversable);
    seed += std::hash<bool>{}(object.buffer);

    return seed;
  }
  
  std::size_t operator()(const GridPoint* object) const {
    return operator()(*object);
  }
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