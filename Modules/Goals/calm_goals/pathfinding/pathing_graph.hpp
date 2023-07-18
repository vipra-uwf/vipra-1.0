#ifndef VIPRA_CALM_PATHING_GRAPH_HPP
#define VIPRA_CALM_PATHING_GRAPH_HPP

#include <obstacle_set/obstacle_set.hpp>

namespace CalmPath {

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

  GridPoint(VIPRA::f3d pos, bool trav, bool buff) : center(pos), adj(), traversable(trav), buffer(buff) {}
  
  /**
  * @brief determins if two vectors are equal in contents.
  *
  * @param first First vector to compare.
  * @param second Second vector to compare.
  * @return true
  * @return false
  */
  bool vectorEq(const std::vector<GridPoint*>& first, const std::vector<GridPoint*>& second) const; 

  /**
  * @brief equality overloader to test if two grid points are equivalent.
  *
  * @param rightObject GridPoint being tested. 
  * @return true
  * @return false
  */
  bool operator==(const GridPoint& rightObject) const {
    return (center == rightObject.center && vectorEq(adj, rightObject.adj) && traversable == rightObject.traversable && buffer == rightObject.buffer);
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
  
  /**
  * @brief passes in the proper value to the hash if a pointer is given.
  *
  * @param object GridPoint pointer being hashed. 
  * @return std::size_t
  */
  std::size_t operator()(const GridPoint* object) const {
    return operator()(*object);
  }
};

class PathingGraph {
 public:

  /**
  * @brief searches the graph for a desired point.
  *
  * @param pos Desired position to see if it is in the graph.
  * @return GridPoint*
  */
  GridPoint*  search(VIPRA::f3d);

  /**
  * @brief starts processes to build the points and adjacencies for the obstacle set.
  *
  * @param obsSet Obstacle set for the simulation.
  * @param gridSz Size of the grid being built.
  * @param obsBufferDist
  */
  void        build(const ObstacleSet&, float gridSize, float obsBufferDist);

 /**
  * @brief Creates and returns a string representation of the pathing graph.
  *
  * @return std::string
  */
  std::string toString() const;

 private:
  std::vector<GridPoint> points;
  VIPRA::size            xCnt;
  VIPRA::size            yCnt;
  VIPRA::f3d             dimensions;
  float                  gridSize;
  
  /**
  * @brief creates the set of GridPoints used on the map.
  *
  * @param obsSet Obstacle set for the simulation.
  * @param obsBufferDist 
  */
  void constructPoints(const ObstacleSet&, float obsBufferDist);
  /**
  * @brief builds a vector of adjacent GridPoints for each GridPoint.
  * 
  */
  void buildAdjacencies();
  /**
  * @brief adds adjacent coordinates to a string value for representation of the GridPoints.
  *
  * @param node Parent GridPoint to record adjacent grid points.
  * @param str Holds the node's adjacent coordinates.
  */
  void addAdjToString(const GridPoint& node, std::string& str) const;
};
}  // namespace CalmPath

#endif