
#include <numeric>

#include <selectors/selector.hpp>

namespace BHVR {

/**
 * @brief Initializes the pedestrian groups, and runs the sub selectors over them
 * 
 * @param behaviorName : 
 * @param seed : 
 * @param pedSet : 
 * @param obsSet : 
 * @param goals : 
 */
void Selector::initialize(const std::string& behaviorName, BHVR::seed seed, BehaviorContext& context,
                          const PedestrianSet& pedSet, const ObstacleSet& obsSet, const Goals& goals) {
  pedGroups.initialize(allTypes, pedSet.getNumPedestrians());

  auto selectorIdxs = orderSelectors();
  runSelectors(selectorIdxs, behaviorName, seed, context, pedSet, obsSet, goals);
  sortGroups();
  pedGroups.cleanUsed();
}

/**
 * @brief Goes through each sub selector in the provided order, updating the pedestrian groups
 * 
 * @param selectorIdxs : 
 * @param behaviorName : 
 * @param seed : 
 * @param context : 
 * @param pedSet : 
 * @param obsSet : 
 * @param goals : 
 */
void Selector::runSelectors(const VIPRA::idxVec& selectorIdxs, const std::string& behaviorName, BHVR::seed seed,
                            BehaviorContext& context, const PedestrianSet& pedSet, const ObstacleSet& obsSet,
                            const Goals& goals) {

  std::for_each(selectorIdxs.begin(), selectorIdxs.end(), [&](VIPRA::idx index) {
    auto& selector = subSelectors[index];
    auto  selectedPeds = selectPedsFromGroup(selector, seed, pedSet, obsSet, goals, behaviorName);
    updatePedGroups(selectedPeds, selector, context, behaviorName);
  });

  pedGroups[0].resize(pedSet.getNumPedestrians());
  std::iota(pedGroups[0].begin(), pedGroups[0].end(), 0);
}

/**
 * @brief Selects pedestrians using a sub selector
 * 
 * @param selector : 
 * @param seed : 
 * @param pedSet : 
 * @param obsSet : 
 * @param goals : 
 * @param behaviorName : 
 * @return VIPRA::idxVec 
 */
VIPRA::idxVec Selector::selectPedsFromGroup(SubSelector& selector, BHVR::seed seed, const PedestrianSet& pedSet,
                                            const ObstacleSet& obsSet, const Goals& goals, const std::string& behaviorName) {
  const auto& fullGroup = pedGroups.getGroup(selector.group);
  auto        usablegroup = filterUsedPeds(fullGroup, pedGroups.getUsed(selector.group));
  auto        result = selector.selectPeds(seed, fullGroup, usablegroup, pedSet, obsSet, goals);

  if (!result.starved) {
    return result.group;
  }

  if (selector.required) {
    spdlog::error("Behavior: {}, Required Selector Starved For Type: {} From Group: {}",
                  behaviorName,
                  selector.type.fullType,
                  selector.group);
    exit(1);
  }

  spdlog::warn(
      "Behavior: {}, Starved Selector For Type: {} From Group: {}", behaviorName, selector.type.fullType, selector.group);
  return result.group;
}

/**
 * @brief Adds each selected pedestrian to their respective type groups, sets the pedestrian as used in the original group
 * 
 * @param selectedPeds : 
 * @param selector : 
 * @param context : 
 * @param behaviorName : 
 */
void Selector::updatePedGroups(const VIPRA::idxVec& selectedPeds, SubSelector& selector, BehaviorContext& context,
                               const std::string& behaviorName) {
  std::for_each(selectedPeds.begin(), selectedPeds.end(), [&](auto& pedIdx) {
    selector.type.forEachType([&](typeUID type) {
      spdlog::debug("Behavior: {}, Selecting Ped {} for Type: {}", behaviorName, pedIdx, type);
      context.types[pedIdx] += type;
      pedGroups.addPed(pedIdx, type);
    });

    pedGroups.setUsed(pedIdx, selector.group);
  });
}

/**
 * @brief Returns a vector with all of the pedestrians from a group that are not already used
 * 
 * @param peds : 
 * @param used : 
 * @return VIPRA::idxVec 
 */
VIPRA::idxVec Selector::filterUsedPeds(const VIPRA::idxVec& peds, const std::vector<bool>& used) {
  VIPRA::idxVec ret;

  for (VIPRA::idx i = 0; i < peds.size(); ++i) {
    if (!used[i]) {
      ret.push_back(peds[i]);
    }
  }

  return ret;
}

/**
 * @brief Sorts all of the groups in the selector's group container
 * 
 */
void Selector::sortGroups() {
  const VIPRA::size groupCnt = pedGroups.size();
  for (VIPRA::idx i = 1; i < groupCnt; ++i) {
    std::sort(pedGroups[i].begin(), pedGroups[i].end());
  }
}

/**
 * @brief Checks that there are no duplicate selectors in the order
 * @note if there is, something is very wrong
 * 
 * @param order : 
 */
void checkforDuplicates(const VIPRA::idxVec& order) {
  for (VIPRA::idx i = 0; i < order.size(); ++i) {
    for (VIPRA::idx j = i + 1; j < order.size(); ++j) {
      if (order[i] == order[j]) {
        spdlog::error("Duplicate Selector in Selectors");
        exit(1);
      }
    }
  }
}

/**
 * @brief Stable sorts the selectors based on their group dependencies
 * 
 * @return VIPRA::idxVec 
 */
VIPRA::idxVec Selector::orderSelectors() {
  VIPRA::idxVec order;

  for (VIPRA::idx selIdx = 0; selIdx < subSelectors.size(); ++selIdx) {
    if (subSelectors[selIdx].group == 0) {
      order.push_back(selIdx);
    }
  }

  allTypes.forEachType([&](typeUID type) {
    for (VIPRA::idx selIdx = 0; selIdx < subSelectors.size(); ++selIdx) {
      if (subSelectors[selIdx].group == type) {
        order.push_back(selIdx);
      }
    }
  });

  for (VIPRA::idx selIdx = 0; selIdx < subSelectors.size(); ++selIdx) {
    bool notInGraph =
        std::find_if(order.begin(), order.end(), [&](VIPRA::idx index) { return index == selIdx; }) == order.end();
    if (notInGraph) {
      order.push_back(selIdx);
    }
  }

  checkforDuplicates(order);
  return order;
}

// ----------------- GETTERS/SETTERS --------------------------------------------------------------------

void Selector::setAllTypes(Ptype pedTypes) {
  allTypes = pedTypes;
}

void Selector::addSubSelector(const SubSelector& subSelector) {
  subSelectors.emplace_back(subSelector);
}

VIPRA::size Selector::selectorCount() const {
  return subSelectors.size();
}

const GroupsContainer& Selector::getGroups() const {
  return pedGroups;
}

// ----------------- END GETTERS/SETTERS --------------------------------------------------------------------

}  // namespace BHVR
