#ifndef VIPRA_CALM_PATHING_GRAPH_HPP
#define VIPRA_CALM_PATHING_GRAPH_HPP

#include <cstdint>
#include <obstacle_set/obstacle_set.hpp>

namespace CALM_PATH {

/**
 * @struct GridPoint
 * @brief A struct that represents points on a grid.
 *
 * This struct provides implementations for holding a point on a grid that serves 
 * as a base point for paths to be generated from.
 */
struct GridPoint {
  VIPRA::f3d              center;
  std::vector<GridPoint*> adj;
  bool                    traversable;
  bool                    buffer;

  GridPoint(VIPRA::f3d pos, bool trav, bool buff)
      : center(pos), traversable(trav), buffer(buff) {}

  /**
  * @brief determins if two vectors are equal in contents.
  *
  * @param first First vector to compare.
  * @param second Second vector to compare.
  * @return true
  * @return false
  */
  [[nodiscard]] static bool vectorEq(const std::vector<GridPoint*>& first,
                                     const std::vector<GridPoint*>& second);

  /**
  * @brief equality overloader to test if two grid points are equivalent.
  *
  * @param rightObject GridPoint being tested. 
  * @return true
  * @return false
  */
  bool operator==(const GridPoint& rightObject) const {
    return (center == rightObject.center && vectorEq(adj, rightObject.adj) &&
            traversable == rightObject.traversable && buffer == rightObject.buffer);
  }
};

/**
 * @struct GridPointHash
 * @brief A struct that evaluates a hash function for GridPoint objects
 *
 * This struct provides implementations for hashing a GridPoint in a hash map.
 */
struct GridPointHash {
  /**
  * @brief calculates hash of a GridPoint object.
  *
  * @param object GridPoint being hashed. 
  * @return std::size_t
  */
  std::size_t operator()(const GridPoint& object) const {
    std::size_t seed = 0;

    seed += VIPRA::F3dHash{}(object.center);
    for (const GridPoint* adjPoint : object.adj) {
      // NOLINTNEXTLINE
      seed += reinterpret_cast<uintptr_t>(adjPoint);
    }
    seed += std::hash<bool>{}(object.traversable);
    seed += std::hash<bool>{}(object.buffer);

    return seed;
  }

  std::size_t operator()(const GridPoint* object) const { return operator()(*object); }
};

/**
 * @class PathingGraph
 * @brief A class that builds a graph of points for the paths to be built upon.
 *
 * This class provides implementations for creating, searching, and representing the
 * graph that the pedestrians paths are created from, which is used in the simulation.
 */
class PathingGraph {
 public:
  GridPoint* search(VIPRA::f3d);
  void       build(const VIPRA::ObstacleSet& obsSet, float gridSz, float obsBufferDist);
  [[nodiscard]] std::string toString() const;

 private:
  std::vector<GridPoint>            points;
  VIPRA::size                       xCnt;
  VIPRA::size                       yCnt;
  std::pair<VIPRA::f3d, VIPRA::f3d> dimensions;
  float                             gridSize;

  void setGridCounts();

  [[nodiscard]] static VIPRA::idx getIndex(VIPRA::size, VIPRA::size, VIPRA::size);

  void        constructPoints(const VIPRA::ObstacleSet&, float obsBufferDist);
  void        buildAdjacencies();
  static void addAdjToString(const GridPoint& node, std::string& str);
};
}  // namespace CALM_PATH

#endif