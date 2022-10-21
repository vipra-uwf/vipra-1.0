

#include "calm_goals.hpp"

void
CalmGoals::configure(const CONFIG_MAP& configMap) {
  endGoalType = configMap.at("endGoalType");
}

/**
 * @brief Initializes the member variables and path finding
 * 
 * @param obsSet 
 * @param pedSet 
 */
void
CalmGoals::initialize(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
  int pedCnt = pedSet.getNumPedestrians();
  currentGoals = DimVector(pedCnt);
  endGoals = DimVector(pedCnt, {-1, -1});
  goalsMet = std::vector<bool>(pedCnt, false);
  paths = std::vector<std::queue<Dimensions>>(pedCnt);

  graph.buildGraph(obsSet);
  findNearestEndGoal(obsSet, pedSet);
  initializePaths(pedSet);
}

/**
 * @brief Gets the path for each pedestrian placing it into the queue at paths[pedIndex]
 * 
 * @param pedSet 
 */
void
CalmGoals::initializePaths(const PedestrianSet& pedSet) {
  const size_t     pedCnt = pedSet.getNumPedestrians();
  const DimVector& coords = pedSet.getAllPedCoords();

  for (size_t i = 0; i < pedCnt; ++i) {
    paths[i] = pathFind(coords.at(i), endGoals.at(i), graph);
  }
}

/**
 * @brief Fills endGoals with the nearest endgoal of endgoaltype
 * 
 * @param obsSet 
 * @param pedSet 
 */
void
CalmGoals::findNearestEndGoal(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
  const auto& coords = pedSet.getAllPedCoords();
  const auto& objectives = obsSet.getObjectsofType(endGoalType);

  if (objectives.size() == 1) {
    // if only one objective, set every end goal as that
    std::fill(endGoals.begin(), endGoals.end(), objectives.at(0));
  } else {
    // otherwise, for each ped coord set the end goal as the nearest objective
    std::transform(coords.begin(), coords.end(), endGoals.begin(), [&](const Dimensions& coord) {
      Dimensions      goal;
      FLOATING_NUMBER shortest = std::numeric_limits<float>::max();
      for (const auto& obj : objectives) {
        FLOATING_NUMBER dist = coord.distanceTo(obj);
        if (dist < shortest) {
          goal = obj;
        }
      }
      return goal;
    });
  }
}

/**
 * @brief Checks if pedestrians have met their current goal, removing it from the queue if the have
 * also checks if they have met their end goal, updating goalsMet if they have
 * 
 * @param obsSet 
 * @param pedSet 
 */
void
CalmGoals::updatePedestrianGoals(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
  const size_t     numPeds = pedSet.getNumPedestrians();
  const DimVector& pedCoords = pedSet.getAllPedCoords();

  for (size_t i = 0; i < numPeds; ++i) {
    if (!paths[i].empty()) {
      const Dimensions& currGoal = paths[i].front();
      if (pedCoords.at(i).inside(currGoal, GOAL_RANGE)) {
        paths[i].pop();
        goalsMet[i] = paths[i].empty();
      }
    }
  }
}

/**
 * @brief returns the current goal for the pedestrian at index
 * 
 * @param index 
 * @return const Dimensions 
 */
const Dimensions
CalmGoals::getCurrentGoal(size_t index) const {
  return paths[index].front();
}

/**
 * @brief returns the end goal for the pedestrian at index
 * 
 * @param index 
 * @return const Dimensions 
 */
const Dimensions
CalmGoals::getEndGoal(size_t index) const {
  return endGoals.at(index);
}

/**
 * @brief returns a vector with all pedestrians current goals
 * 
 * @return const DimVector& 
 */
const DimVector&
CalmGoals::getAllCurrentGoals() const noexcept {
  // since current goals are the first element of a queue, we need to convert that to a vector
  std::transform(paths.begin(), paths.end(), currentGoals.begin(), [](const std::queue<Dimensions>& path) {
    if (path.empty()) {
      return Dimensions{-1, -1};
    }
    return path.front();
  });
  return currentGoals;
}

/**
 * @brief returns the endgoals vector
 * 
 * @return const DimVector& 
 */
const DimVector&
CalmGoals::getAllEndGoals() const noexcept {
  return endGoals;
}

/**
 * @brief returns if a pedestrian has met their end goal
 * 
 * @param index 
 * @return true 
 * @return false 
 */
bool
CalmGoals::isPedestianGoalMet(size_t index) const {
  return goalsMet.at(index);
}

/**
 * @brief returns if all pedestrians are set as having met their end goal
 * 
 * @return true 
 * @return false 
 */
bool
CalmGoals::isSimulationGoalMet() const noexcept {
  return std::all_of(goalsMet.begin(), goalsMet.end(), [](bool met) { return met; });
}