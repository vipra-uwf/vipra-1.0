#ifndef CALM_GOALS
#define CALM_GOALS

#include <algorithm>
#include <limits>
#include <queue>

#include <spdlog/spdlog.h>

#include "goals/goals.hpp"
#include "pathfinding/pathfinding.hpp"

/**
 * @class CalmGoals
 * @brief A class that represents calm goals.
 *
 * This class extends the Goals class and provides implementations for configuring, initializing,
 * and updating pedestrian goals.
 */
class CalmGoals : public Goals {
 public:
  /**
  * @brief Configures the map for calm goals
  * 
  * @param configMap
  */
  void configure(const VIPRA::CONFIG::Map& configMap) override;

  /**
  * @brief Initializes the member variables and path finding
  * 
  * @param obsSet
  * @param pedSet
  */
  void initialize(const ObstacleSet&, const PedestrianSet&) override;

  /**
  * @brief Checks if pedestrians have met their current goal, removing it from the queue if the have
  * also checks if they have met their end goal, updating goalsMet if they have
  * 
  * @param obsSet 
  * @param pedSet 
  */
  void updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&,
                             VIPRA::delta_t) override;
  
  /**
  * @brief returns the current goal for the pedestrian at index, returns VIPRA::_emptyf3d_ if no current goal
  * 
  * @param index 
  * @return const VIPRA::f3d 
  */
  [[nodiscard]] VIPRA::f3d getCurrentGoal(VIPRA::idx) const override;
  /**
  * @brief returns the end goal for the pedestrian at index
  * 
  * @param index 
  * @return const VIPRA::f3d 
  */
  [[nodiscard]] VIPRA::f3d getEndGoal(VIPRA::idx) const override;

  /**
  * @brief returns a vector with all pedestrians current goals
  * 
  * @return const VIPRA::f3dVec& 
  */
  [[nodiscard]] const VIPRA::f3dVec& getAllCurrentGoals() const noexcept override;
  /**
  * @brief returns the endgoals vector
  * 
  * @return const VIPRA::f3dVec& 
  */
  [[nodiscard]] const VIPRA::f3dVec& getAllEndGoals() const noexcept override;

  /**
  * @brief returns if a pedestrian has met their end goal
  * 
  * @param index 
  * @return true 
  * @return false 
  */
  [[nodiscard]] bool isPedestianGoalMet(VIPRA::idx) const override;
  /**
  * @brief returns if all pedestrians are set as having met their end goal
  * 
  * @return true 
  * @return false 
  */
  [[nodiscard]] bool isSimulationGoalMet() const noexcept override;

  /**
  * @brief returns the time since the last goal was met
  * 
  * @param index
  * @return VIPRA::delta_t
  */
  [[nodiscard]] VIPRA::delta_t timeSinceLastGoal(VIPRA::idx) const override;

 private:
  float goalRange;
  float quadSize;
  float closestObs;

  std::string endGoalType;
  std::string pathingType;

  VIPRA::f3dVec currentGoals;
  VIPRA::f3dVec endGoals;

  std::vector<VIPRA::delta_t>         lastGoalTimes;
  std::vector<bool>                   goalsMet;
  CalmPath::PathingGraph              graph;
  std::vector<std::queue<VIPRA::f3d>> paths;
  
 /**
  * @brief Gets the path for each pedestrian placing it into the queue at paths[pedIndex]
  * 
  * @param pedSet 
  */
  void initializePaths(const PedestrianSet&, const ObstacleSet&);
  /**
  * @brief Fills endGoals with the nearest endgoal of endgoaltype
  * 
  * @param obsSet 
  * @param pedSet 
  */
  void findNearestEndGoal(const ObstacleSet&, const PedestrianSet&);

  /**
  * @brief Uses disembark to generate a path of points from a start to the exit.
  * 
  * @param start 
  * @param obsSet
  * @return std::queue<VIPRA::f3d>
  */
  [[nodiscard]] static std::queue<VIPRA::f3d> disembarkPath(const VIPRA::f3d&,
                                                            const ObstacleSet&);

  /**
  * @brief Returns the nearest objective of a specific type compared to a point
  * 
  * @param type 
  * @param point
  * @param obsSet
  * @return const VIPRA::f3d&
  */
  [[nodiscard]] static const VIPRA::f3d&      nearestObjective(const std::string&,
                                                               const VIPRA::f3d&,
                                                               const ObstacleSet&);
};

#endif