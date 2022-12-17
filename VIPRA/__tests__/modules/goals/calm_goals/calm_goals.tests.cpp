
#include <algorithm>
#include <gtest/gtest.h>

#include "mocks/obstacle_set/obstacle_set.mock.hpp"
#include "mocks/pedestrian_set/pedestrian_set.mock.hpp"

#include "Goals/calm_goals/calm_goals.hpp"
#include "ObstacleSet/airplane_obstacle_set/airplane_obstacle_set.hpp"

class CalmGoalsTester : public CalmGoals {
 public:
  const VIPRA::f3d& testNearestObjective(const std::string& type,
                                         const VIPRA::f3d&  point,
                                         const ObstacleSet& obsSet) {
    return nearestObjective(type, point, obsSet);
  }

  void testFindNearesetEndGoal(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
    return findNearestEndGoal(obsSet, pedSet);
  }

  void setup(size_t pedCnt) {
    currentGoals = VIPRA::f3dVec(pedCnt);
    endGoals = VIPRA::f3dVec(pedCnt);
    goalsMet = std::vector<bool>(pedCnt);
  }
};

// TODO test that update pedestrian goals, properly updates to next goal
// TODO test that update pedestrian goals, properly updates if the pedestrian has met their end goal
// TODO test that is simulation goal returns the proper value

// TODO test that getters return the proper goals

// TODO test that nearest objective returns the correct value
// TODO test that nearest end goal returns the correct value

// TODO test that initialize properly sets the pedestrian paths
