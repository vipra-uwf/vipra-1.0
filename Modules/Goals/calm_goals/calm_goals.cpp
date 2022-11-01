

#include "calm_goals.hpp"

#include "pathfinding.hpp"

void
CalmGoals::configure(const CONFIG_MAP& configMap) {
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
  std::cout << "Finding Nearest End Goal\n";
  findNearestEndGoal(obsSet, pedSet);

  if (pathingType == "Astar") {
    std::cout << "Building Graph\n";
    graph.buildGraph(obsSet);
  } else {
  }
  std::cout << "Creating Paths\n";
  initializePaths(pedSet, obsSet);
  std::cout << "Done\n";
}

/**
 * @brief Gets the path for each pedestrian placing it into the queue at paths[pedIndex]
 * 
 * @param pedSet 
 */
void
CalmGoals::initializePaths(const PedestrianSet& pedSet, const ObstacleSet& obsSet) {
  const size_t     pedCnt = pedSet.getNumPedestrians();
  const DimVector& coords = pedSet.getAllPedCoords();

  for (size_t i = 0; i < pedCnt; ++i) {
    if (pathingType == "Astar") {
      paths[i] = CalmPath::pathFind(coords.at(i), endGoals.at(i), graph, diagonalCost);
    } else if (pathingType == "Deplane") {
      paths[i] = deplanePath(coords.at(i), endGoals.at(i), obsSet);
    }
  }
}

std::queue<Dimensions>
CalmGoals::deplanePath(const Dimensions& start, const Dimensions& endGoal, const ObstacleSet& obsSet) {
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
  const auto&     objectives = obsSet.getObjectsofType(type);
  const size_t    objCnt = objectives.size();
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
        currentGoals[i] = paths[i].front();
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