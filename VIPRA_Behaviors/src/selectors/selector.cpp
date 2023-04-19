
#include <numeric>

#include <selectors/selector.hpp>

namespace Behaviors {

/**
 * @brief Initializes the pedestrian groups, and runs the sub selectors over them
 * 
 * @param behaviorName : 
 * @param seed : 
 * @param pedSet : 
 * @param obsSet : 
 * @param goals : 
 */
void
Selector::initialize(const std::string&   behaviorName,
                     Behaviors::seed      seed,
                     BehaviorContext&     context,
                     const PedestrianSet& pedSet,
                     const ObstacleSet&   obsSet,
                     const Goals&         goals) {
  pedGroups.initialize(allTypes, pedSet.getNumPedestrians());

  std::for_each(subSelectors.begin(), subSelectors.end(), [&](SubSelector& selector) {
    auto selectedPeds = selectPedsFromGroup(selector, seed, pedSet, obsSet, goals, behaviorName);
    updatePedGroups(selectedPeds, selector, context, behaviorName);
  });

  pedGroups[0].resize(pedSet.getNumPedestrians());
  std::iota(pedGroups[0].begin(), pedGroups[0].end(), 0);

  sortGroups();
}

void
Selector::setAllTypes(pType pedTypes) {
  allTypes = pedTypes;
}

void
Selector::addSubSelector(SubSelector&& subSelector) {
  subSelectors.emplace_back(subSelector);
}

VIPRA::size
Selector::SelectorCount() const {
  return subSelectors.size();
}

const GroupsContainer&
Selector::getGroups() const {
  return pedGroups;
}

std::vector<VIPRA::idx>
Selector::selectPedsFromGroup(SubSelector&         selector,
                              Behaviors::seed      seed,
                              const PedestrianSet& pedSet,
                              const ObstacleSet&   obsSet,
                              const Goals&         goals,
                              const std::string&   behaviorName) {
  const auto& group = pedGroups.getGroup(selector.group);
  auto        selectedPeds = selector.select(seed, group, pedSet, obsSet, goals);

  if (selectedPeds.size() == 0) {
    spdlog::warn("Behavior: {}, Starved Selector For Type: {} From Group: {}",
                 behaviorName,
                 selector.type.fullType,
                 selector.group);
  }

  return selectedPeds;
}

void
Selector::updatePedGroups(const std::vector<VIPRA::idx>& selectedPeds,
                          SubSelector&                   selector,
                          BehaviorContext&               context,
                          const std::string&             behaviorName) {
  std::for_each(selectedPeds.begin(), selectedPeds.end(), [&](auto& pedIdx) {
    selector.type.forEachType([&](typeUID type) {
      spdlog::debug("Behavior: {}, Selecting Ped {} for Type: {}", behaviorName, pedIdx, type);
      context.types[pedIdx] += type;
      pedGroups.addPed(pedIdx, type);
    });

    if (selector.group == 0) {
      pedGroups.removePed(pedIdx, selector.group);
    }
  });
}

void
Selector::sortGroups() {
  const VIPRA::size groupCnt = pedGroups.size();
  for (VIPRA::idx i = 1; i < groupCnt; ++i) {
    std::sort(pedGroups[i].begin(), pedGroups[i].end());
  }
}

// --------------- CONSTRUCTORS ---------------------------------------------------------------

Selector::Selector() : allTypes(0), subSelectors(), pedGroups() {}

Selector::Selector(Selector&& other) noexcept
  : allTypes(std::move(other.allTypes)), subSelectors(std::move(other.subSelectors)),
    pedGroups(std::move(other.pedGroups)) {}

Selector&
Selector::operator=(Selector&& other) noexcept {
  subSelectors = std::move(other.subSelectors);
  pedGroups = std::move(other.pedGroups);
  allTypes = other.allTypes;
  return *this;
}

// --------------- END CONSTRUCTORS ---------------------------------------------------------------
}  // namespace Behaviors
