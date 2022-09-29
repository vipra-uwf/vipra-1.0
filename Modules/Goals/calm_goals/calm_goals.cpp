

#include "calm_goals.hpp"

void
CalmGoals::configure(const CONFIG_MAP& configMap) {
  endGoalType = configMap.at("endGoalType");
}

void
CalmGoals::initialize(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
  int pedCnt = pedSet.getNumPedestrians();
  currentGoals = DimVector(pedCnt, {-1, -1});
  endGoals = DimVector(pedCnt, {-1, -1});
  goalsMet = std::vector<bool>(pedCnt, false);
  findNearestEndGoal(obsSet, pedSet);
  updatePedestrianGoals(obsSet, pedSet);
}

void
CalmGoals::findNearestEndGoal(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
  const auto& coords = pedSet.getAllPedCoords();
  const auto& objectives = obsSet.getObjectsofType(endGoalType);
  if (objectives.size() == 1) {
    std::fill(endGoals.begin(), endGoals.end(), objectives.at(0));
  } else {
    std::transform(
        coords.begin(), coords.end(), endGoals.begin(), [&](const Dimensions& coord) {
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

void
CalmGoals::updatePedestrianGoals(const ObstacleSet& obsSet, const PedestrianSet& pedSet) {
  //TODO

  // get neartest line from rootLine

  size_t numPeds = pedSet.getNumPedestrians();

  for (size_t i = 0; i < numPeds; ++i) {
    if (currentGoals.at(i)) {}
  }
}

const Dimensions
CalmGoals::getCurrentGoal(size_t index) const {
  return currentGoals.at(index);
}

const Dimensions
CalmGoals::getEndGoal(size_t index) const {
  return endGoals.at(index);
}

const DimVector&
CalmGoals::getAllCurrentGoals() const noexcept {
  return currentGoals;
}

const DimVector&
CalmGoals::getAllEndGoals() const noexcept {
  return endGoals;
}

bool
CalmGoals::isPedestianGoalMet(size_t index) const {
  return goalsMet.at(index);
}

bool
CalmGoals::isSimulationGoalMet() const noexcept {
  return std::all_of(goalsMet.begin(), goalsMet.end(), [](bool met) { return met; });
}

void
CalmGoals::createNavLines(const ObstacleSet& obsSet) {
  const auto& objectives = obsSet.getObjectsofType(endGoalType);

  for (const auto& obj : objectives) {
    // create root line
  }
}