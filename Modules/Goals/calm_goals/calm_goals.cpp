

#include "calm_goals.hpp"
#include "pathfinding.hpp"

const Dimensions Goals::__empty__ = Dimensions{};

void
CalmGoals::configure(const CONFIG_MAP& configMap) {
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
  int pedCnt = pedSet.getNumPedestrians();
  currentGoals = DimVector(pedCnt);
  endGoals = DimVector(pedCnt, {-1, -1});
  goalsMet = std::vector<bool>(pedCnt, false);
  paths = std::vector<std::queue<Dimensions>>(pedCnt);
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
  const size_t     pedCnt = pedSet.getNumPedestrians();
  const DimVector& coords = pedSet.getPedestrianCoordinates();

  for (size_t i = 0; i < pedCnt; ++i) {
    if (pathingType == "Astar") {
      LJ::Debug(simLogger, "CalmGoals: Finding AStar Path for Ped: {}", i);
      paths[i] = CalmPath::pathFind(coords.at(i), endGoals.at(i), graph, diagonalCost);
    } else if (pathingType == "Disembark") {
      LJ::Debug(simLogger, "CalmGoals: Finding Disembark Path for Ped: {}", i);
      paths[i] = disembarkPath(coords.at(i), endGoals.at(i), obsSet);
    }
    currentGoals[i] = paths[i].front();
  }
  LJ::Debug(simLogger, "CalmGoals: Finished Initializing Paths");
}

std::queue<Dimensions>
CalmGoals::disembarkPath(const Dimensions& start, const Dimensions& endGoal, const ObstacleSet& obsSet) {
  std::queue<Dimensions> path;
  Dimensions             aisle = nearestObjective("aisle", start, obsSet);
  path.push(aisle);
  Dimensions aisleEnd = nearestObjective("endAisle", aisle, obsSet);
  path.push(aisleEnd);
  path.push(nearestObjective("exits", aisleEnd, obsSet));
  return path;
}

const Dimensions&
CalmGoals::nearestObjective(const std::string& type, const Dimensions& point, const ObstacleSet& obsSet) {
  const auto&  objectives = obsSet.getObjectsofType(type);
  const size_t objCnt = objectives.size();
  if (objectives.empty()) {
    GoalsException::Throw("No Objectives of Type: " + type + " In Provided Map");
  }
  size_t          closest = 0;
  FLOATING_NUMBER minDist = std::numeric_limits<float>::max();
  for (size_t i = 0; i < objCnt; ++i) {
    FLOATING_NUMBER dist = objectives.at(i).distanceTo(point);
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
CalmGoals::updatePedestrianGoals(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
  const size_t     numPeds = pedSet.getNumPedestrians();
  const DimVector& pedCoords = pedSet.getPedestrianCoordinates();

  for (size_t i = 0; i < numPeds; ++i) {
    if (!paths[i].empty()) {
      const Dimensions& currGoal = paths[i].front();
      if (pedCoords.at(i).inside(currGoal, goalRange)) {
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
 * @brief returns the current goal for the pedestrian at index, returns uninitialized Dimensions if no current goal
 * 
 * @param index 
 * @return const Dimensions 
 */
const Dimensions&
CalmGoals::getCurrentGoal(size_t index) const {
  if (paths[index].empty()) {
    return __empty__;
  }
  return paths[index].front();
}

/**
 * @brief returns the end goal for the pedestrian at index
 * 
 * @param index 
 * @return const Dimensions 
 */
const Dimensions&
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
  int  cnt = 0;
  bool passed = std::all_of(goalsMet.begin(), goalsMet.end(), [&cnt](bool met) {
    ++cnt;
    return met;
  });
  if (passed) {
    LJ::Debug(simLogger, "{} Pedestrians Have Met Their Goal", cnt);
  }
  return passed;
}

int n = 0;

void
printTree(CalmPath::Quad* root) {
  if (root != nullptr) {
    fprintf(stderr,
            "{\"x\":%f , \"y\":%f, \"size\":%f, \"trav\":%s, \"adjacencies\":[\n",
            root->center.axis[0],
            root->center.axis[1],
            root->size,
            (root->traversable ? "true" : "false"));
    if (n % 1000 == 0) {
      for (int i = 0; i < root->adj.size(); ++i) {
        fprintf(
            stderr, "\t{\"x\": %f, \"y\": %f}\n", root->adj[i]->center.axis[0], root->adj[i]->center.axis[1]);
        if (i < root->adj.size() - 1) {
          fprintf(stderr, ",");
        }
      }
    }
    ++n;
    fprintf(stderr, "]},\n");
    printTree(root->tl);
    printTree(root->tr);
    printTree(root->bl);
    printTree(root->br);
  }
}

void
CalmGoals::printGraph() {
  fprintf(stderr, "\"quads\":[");
  printTree(graph.getRoot());
  fprintf(stderr, "]");
}

void
CalmGoals::printPaths() {
  fprintf(stderr, "\"paths\": [");
  for (auto& path : paths) {
    if (!path.empty()) {
      int i = 0;
      fprintf(stderr, "[");
      while (!path.empty()) {
        auto d = path.front();
        path.pop();
        fprintf(stderr, "{\"x\":%f, \"y\":%f},\n", d.axis[0], d.axis[1]);
        ++i;
      }
      fprintf(stderr, "],");
    }
  }
  fprintf(stderr, "]");
}