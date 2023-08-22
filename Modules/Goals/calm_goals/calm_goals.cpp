
#include "calm_goals.hpp"

void CalmGoals::configure(const VIPRA::Config& configMap) {
  spdlog::info("CalmGoals: Configuring Calm Goals");
  goalRange = configMap["goalRange"].get<float>();
  endGoalType = configMap["endGoalType"].get<std::string>();
  gridSize = configMap["gridSize"].get<float>();
  closestObs = configMap["closestObstacle"].get<float>();
  spdlog::info("CalmGoals: Done Configuring Calm Goals");
}

/**
 * @brief Initializes the member variables and path finding
 * 
 * @param obsSet
 * @param pedSet
 */
void CalmGoals::initialize(const VIPRA::ObstacleSet&   obsSet,
                           const VIPRA::PedestrianSet& pedSet) {
  VIPRA::size pedCnt = pedSet.getNumPedestrians();

  currentGoals = VIPRA::f3dVec(pedCnt);
  endGoals = VIPRA::f3dVec(pedCnt, VIPRA::f3d{-1, -1});
  goalsMet = std::vector<bool>(pedCnt, false);
  paths = std::vector<std::queue<VIPRA::f3d>>(pedCnt);
  lastGoalTimes =
      std::vector<VIPRA::delta_t>(pedCnt, -std::numeric_limits<VIPRA::delta_t>::max());

  spdlog::debug("CalmGoals: Finding Nearest End Goal");
  findNearestEndGoal(obsSet, pedSet);

  spdlog::debug("CalmGoals: Building Pathing Graph");
  graph.build(obsSet, gridSize, closestObs);

  spdlog::debug("CalmGoals: Initializing Paths");
  initializePaths(pedSet, obsSet);

  spdlog::debug("CalmGoals: Finished Initializing");
}

/**
 * @brief Gets the path for each pedestrian placing it into the queue at paths[pedIndex]
 * 
 * @param pedSet 
 */
void CalmGoals::initializePaths(const VIPRA::PedestrianSet& pedSet,
                                const VIPRA::ObstacleSet&) {
  const VIPRA::size    pedCnt = pedSet.getNumPedestrians();
  const VIPRA::f3dVec& coords = pedSet.getCoordinates();

  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    spdlog::debug("CalmGoals: Finding AStar Path for Ped: {}", i);
    paths[i] = CALM_PATH::pathFind(coords.at(i), endGoals.at(i), graph);
    currentGoals[i] = paths[i].front();
  }
  spdlog::debug("CalmGoals: Finished Initializing Paths");
}

/**
 * @brief Finds the nearest objective to a point
 * 
 * @param type : objective type
 * @param point : position to search from
 * @param obsSet : obstacle set
 * @return const VIPRA::f3d& 
 */
const VIPRA::f3d& CalmGoals::nearestObjective(const std::string&        type,
                                              const VIPRA::f3d&         point,
                                              const VIPRA::ObstacleSet& obsSet) {
  const auto&       objectives = obsSet.getObjectsofType(type);
  const VIPRA::size objCnt = objectives.size();
  if (objectives.empty()) {
    VIPRA::GoalsException::error("No Objectives of Type: " + type + " In Provided Map");
  }
  VIPRA::idx closest = 0;
  float      minDist = std::numeric_limits<float>::max();
  for (VIPRA::idx i = 0; i < objCnt; ++i) {
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
void CalmGoals::findNearestEndGoal(const VIPRA::ObstacleSet&   obsSet,
                                   const VIPRA::PedestrianSet& pedSet) {
  const auto& coords = pedSet.getCoordinates();
  const auto& objectives = obsSet.getObjectsofType(endGoalType);

  if (objectives.empty()) {
    VIPRA::GoalsException::error("No Objectives of Type: " + endGoalType +
                                 " In Provided Map");
  }

  if (objectives.size() == 1) {
    spdlog::debug("CalmGoals: Only One Objective of Type: {}, Filling Goals",
                  endGoalType);
    std::fill(endGoals.begin(), endGoals.end(), std::ref(objectives.at(0)));
    spdlog::debug("CalmGoals: Filled Goals");
  } else {
    std::transform(coords.begin(), coords.end(), endGoals.begin(),
                   [&](const VIPRA::f3d& coord) {
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
  spdlog::debug("CalmGoals: Finished Finding Nearest Goals");
}

/**
 * @brief Checks if pedestrians have met their current goal, removing it from the queue if the have
 * also checks if they have met their end goal, updating goalsMet if they have
 * 
 * @param obsSet 
 * @param pedSet 
 */
void CalmGoals::updatePedestrianGoals(const VIPRA::ObstacleSet&,
                                      const VIPRA::PedestrianSet& pedSet,
                                      VIPRA::delta_t              d_time) {
  const VIPRA::size    numPeds = pedSet.getNumPedestrians();
  const VIPRA::f3dVec& pedCoords = pedSet.getCoordinates();

  for (VIPRA::idx i = 0; i < numPeds; ++i) {
    lastGoalTimes[i] += d_time;
    if (!paths[i].empty()) {
      const VIPRA::f3d& currGoal = paths[i].front();
      if (pedCoords.at(i).distanceTo(currGoal) < goalRange) {
        spdlog::debug("Pedestrian {}, Reached a Goal", i);
        paths[i].pop();
        if (paths[i].empty()) {
          spdlog::debug("Pedestrian {}, Reached Their End Goal", i);
          currentGoals[i] = VIPRA::_emptyf3d_;
          goalsMet[i] = true;
        } else {
          currentGoals[i] = paths[i].front();
        }
        lastGoalTimes[i] = 0.0F;
      }
    }
  }
}

/**
 * @brief returns the current goal for the pedestrian at index, returns VIPRA::_emptyf3d_ if no current goal
 * 
 * @param index 
 * @return const VIPRA::f3d 
 */
const VIPRA::f3d& CalmGoals::getCurrentGoal(VIPRA::idx index) const {
  if (paths[index].empty()) {
    return VIPRA::_emptyf3d_;
  }
  return paths[index].front();
}

/**
 * @brief returns the end goal for the pedestrian at index
 * 
 * @param index 
 * @return const VIPRA::f3d 
 */
const VIPRA::f3d& CalmGoals::getEndGoal(VIPRA::idx index) const {
  return endGoals.at(index);
}

/**
 * @brief returns a vector with all pedestrians current goals
 * 
 * @return const VIPRA::f3dVec& 
 */
const VIPRA::f3dVec& CalmGoals::getAllCurrentGoals() const noexcept {
  return currentGoals;
}

/**
 * @brief returns the endgoals vector
 * 
 * @return const VIPRA::f3dVec& 
 */
const VIPRA::f3dVec& CalmGoals::getAllEndGoals() const noexcept { return endGoals; }

/**
 * @brief returns if a pedestrian has met their end goal
 * 
 * @param index 
 * @return true 
 * @return false 
 */
bool CalmGoals::isPedestianGoalMet(VIPRA::idx index) const { return goalsMet.at(index); }

/**
 * @brief returns if all pedestrians are set as having met their end goal
 * 
 * @return true 
 * @return false 
 */
bool CalmGoals::isSimulationGoalMet() const noexcept {
  return std::all_of(goalsMet.begin(), goalsMet.end(), [](bool met) { return met; });
}

VIPRA::delta_t CalmGoals::timeSinceLastGoal(VIPRA::idx index) const {
  return lastGoalTimes.at(index);
}