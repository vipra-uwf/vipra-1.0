

#include "calm_goals.hpp"
#include "pathfinding.hpp"

void
CalmGoals::configure(const VIPRA::ConfigMap& configMap) {
  goalRange = std::stof(configMap.at("goalRange"));
  endGoalType = configMap.at("endGoalType");
  pathingType = configMap.at("pathFinding");
  diagonalCost = (std::stof(configMap.at("diagonalCost")));
}

/**
 * @brief Initializes the member variables and path finding
 * 
 * @param obsSet
 * @param pedSet
 */
void
CalmGoals::initialize(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
  size_t pedCnt = pedSet.getNumPedestrians();
  currentGoals = VIPRA::f3dVec(pedCnt);
  endGoals = VIPRA::f3dVec(pedCnt, VIPRA::f3d{-1, -1});
  goalsMet = std::vector<bool>(pedCnt, false);
  paths = std::vector<std::queue<VIPRA::f3d>>(pedCnt);
  LJ::Debug(simLogger, "CalmGoals: Finding Nearest End Goal");
  findNearestEndGoal(obsSet, pedSet);

  if (pathingType == "Astar") {
    LJ::Debug(simLogger, "CalmGoals: Building Pathing Graph");
    graph.buildGraph(obsSet);
  }
  LJ::Debug(simLogger, "CalmGoals: Initializing Paths");
  initializePaths(pedSet, obsSet);
  LJ::Debug(simLogger, "CalmGoals: Finished Initializing");
}

/**
 * @brief Gets the path for each pedestrian placing it into the queue at paths[pedIndex]
 * 
 * @param pedSet 
 */
void
CalmGoals::initializePaths(const PedestrianSet& pedSet, const ObstacleSet& obsSet) {
  const size_t         pedCnt = pedSet.getNumPedestrians();
  const VIPRA::f3dVec& coords = pedSet.getPedestrianCoordinates();

  for (size_t i = 0; i < pedCnt; ++i) {
    if (pathingType == "Astar") {
      LJ::Debug(simLogger, "CalmGoals: Finding AStar Path for Ped: {}", i);
      paths[i] = CalmPath::pathFind(coords.at(i), endGoals.at(i), graph, diagonalCost);
    } else if (pathingType == "Disembark") {
      LJ::Debug(simLogger, "CalmGoals: Finding Disembark Path for Ped: {}", i);
      paths[i] = disembarkPath(coords.at(i), obsSet);
    }
    currentGoals[i] = paths[i].front();
  }
  LJ::Debug(simLogger, "CalmGoals: Finished Initializing Paths");
}

std::queue<VIPRA::f3d>
CalmGoals::disembarkPath(const VIPRA::f3d& start, const ObstacleSet& obsSet) {
  std::queue<VIPRA::f3d> path;
  VIPRA::f3d             aisle = nearestObjective("aisle", start, obsSet);
  path.push(aisle);
  VIPRA::f3d aisleEnd = nearestObjective("endAisle", aisle, obsSet);
  path.push(aisleEnd);
  path.push(nearestObjective("exit", aisleEnd, obsSet));
  return path;
}

const VIPRA::f3d&
CalmGoals::nearestObjective(const std::string& type, const VIPRA::f3d& point, const ObstacleSet& obsSet) {
  const auto&  objectives = obsSet.getObjectsofType(type);
  const size_t objCnt = objectives.size();
  if (objectives.empty()) {
    GoalsException::Throw("No Objectives of Type: " + type + " In Provided Map");
  }
  size_t closest = 0;
  float  minDist = std::numeric_limits<float>::max();
  for (size_t i = 0; i < objCnt; ++i) {
    float dist = objectives.at(i).distanceTo(point);
    if (dist < minDist) {
      minDist = dist;
      closest = i;
    }
  }
  return objectives.at(closest);
}

/**
 * @brief Fills endGoals with the nearest endgoal of endgoaltype
 * 
 * @param obsSet 
 * @param pedSet 
 */
void
CalmGoals::findNearestEndGoal(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
  const auto& coords = pedSet.getPedestrianCoordinates();
  const auto& objectives = obsSet.getObjectsofType(endGoalType);

  if (objectives.empty()) {
    GoalsException::Throw("No Objectives of Type: " + endGoalType + " In Provided Map");
  }

  if (objectives.size() == 1) {
    LJ::Debug(simLogger, "CalmGoals: Only One Objective of Type: {}, Filling Goals", endGoalType);
    // if only one objective, set every end goal as that
    std::fill(endGoals.begin(), endGoals.end(), std::ref(objectives.at(0)));
    LJ::Debug(simLogger, "Filled Goals");
  } else {
    // otherwise, for each ped coord set the end goal as the nearest objective
    std::transform(coords.begin(), coords.end(), endGoals.begin(), [&](const VIPRA::f3d& coord) {
      VIPRA::f3d goal;
      float      shortest = std::numeric_limits<float>::max();
      for (const auto& obj : objectives) {
        float dist = coord.distanceTo(obj);
        if (dist < shortest) {
          goal = obj;
        }
      }
      return goal;
    });
  }
  LJ::Debug(simLogger, "CalmGoals: Finished Finding Nearest Goals");
}

/**
 * @brief Checks if pedestrians have met their current goal, removing it from the queue if the have
 * also checks if they have met their end goal, updating goalsMet if they have
 * 
 * @param obsSet 
 * @param pedSet 
 */
void
CalmGoals::updatePedestrianGoals([[maybe_unused]] const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
  const size_t         numPeds = pedSet.getNumPedestrians();
  const VIPRA::f3dVec& pedCoords = pedSet.getPedestrianCoordinates();

  for (size_t i = 0; i < numPeds; ++i) {
    if (!paths[i].empty()) {
      const VIPRA::f3d& currGoal = paths[i].front();
      if (inside(pedCoords.at(i), currGoal, goalRange)) {
        LJ::Debug(simLogger, "Pedestrian {}, Reached a Goal", i);
        paths[i].pop();
        if (paths[i].empty()) {
          LJ::Debug(simLogger, "Pedestrian {}, Reached Their End Goal", i);
          goalsMet[i] = true;
        } else {
          currentGoals[i] = paths[i].front();
        }
      }
    }
  }
}

/**
 * @brief returns the current goal for the pedestrian at index, returns uninitialized VIPRA::f3d if no current goal
 * 
 * @param index 
 * @return const VIPRA::f3d 
 */
const VIPRA::f3d&
CalmGoals::getCurrentGoal(VIPRA::idx index) const {
  if (paths[index].empty()) {
    return VIPRA::__emptyf3d__;
  }
  return paths[index].front();
}

/**
 * @brief returns the end goal for the pedestrian at index
 * 
 * @param index 
 * @return const VIPRA::f3d 
 */
const VIPRA::f3d&
CalmGoals::getEndGoal(VIPRA::idx index) const {
  return endGoals.at(index);
}

/**
 * @brief returns a vector with all pedestrians current goals
 * 
 * @return const VIPRA::f3dVec& 
 */
const VIPRA::f3dVec&
CalmGoals::getAllCurrentGoals() const noexcept {
  return currentGoals;
}

/**
 * @brief returns the endgoals vector
 * 
 * @return const VIPRA::f3dVec& 
 */
const VIPRA::f3dVec&
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
CalmGoals::isPedestianGoalMet(VIPRA::idx index) const {
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
  bool passed = std::all_of(goalsMet.begin(), goalsMet.end(), [](bool met) { return met; });
  return passed;
}