#include "behavior/human_behavior.hpp"

#include <numeric>
#include <utility>
#include "selectors/selector.hpp"

namespace BHVR {

/**
 * @brief Returns the name of the behavior
 * 
 * @return const std::string& 
 */
const std::string& HumanBehavior::getName() const noexcept { return name; }

/**
 * @brief Adds an action to the selectors with type
 * 
 * @param action : action to add
 */
void HumanBehavior::addAction(typeUID type, const Action& action) {
  const VIPRA::idx ndx = GroupsContainer::index(type);
  actions[ndx].emplace_back(action);
}

/**
 * @brief Adds the selector to the behavior
 * 
 * @param selector
 */
void HumanBehavior::addSubSelector(const SubSelector& subSelector) {
  selector.addSubSelector(subSelector);
}

/**
 * @brief Sets the BHVR selectors allTypes
 * 
 */
void HumanBehavior::setAllPedTypes(Ptype types) {
  selector.setAllTypes(types);
  actions.resize(types.typeCount() + 1);
}

/**
 * @brief initializes behavior selector
 * 
 * @param pedSet : pedestrian set object
 * @param obsSet : obstacle set object
 * @param goals : goals object
 */
void HumanBehavior::initialize(const PedestrianSet& pedSet, const ObstacleSet& obsSet,
                               const Goals& goals) {
  context.pedStates = std::vector<BHVR::stateUID>(pedSet.getNumPedestrians());
  context.types = std::vector<BHVR::stateUID>(pedSet.getNumPedestrians());

  spdlog::debug("Initializing {} Selectors, Seed: {}", selector.selectorCount(), seedNum);
  selector.initialize(name, rngEngine, context, pedSet, obsSet, goals);

  for (auto& actionGroup : actions) {
    for (auto& action : actionGroup) {
      action.initialize(pedSet, obsSet, goals, context);
    }
  }
}

/**
 * @brief Evaluates behavior events, and performs actions of pedestrians
 * 
 * @param pedSet : pedestrian set object
 * @param obsSet : obstacle set object
 * @param goals : goals object
 * @param state : state object to write results to
 * @param dT : simulation timestep size
 */
void HumanBehavior::timestep(PedestrianSet& pedSet, ObstacleSet& obsSet, Goals& goals,
                             VIPRA::State& state, VIPRA::delta_t dT) {
  evaluateEvents(pedSet, obsSet, goals, dT);
  applyActions(pedSet, obsSet, goals, state, dT);
  context.elapsedTime += dT;
}

/**
 * @brief adds an event to the behavior and returns a pointer to it
 * 
 * @param event : event object to add
 * @return Event* 
 */
VIPRA::idx HumanBehavior::addEvent(const Event& event) {
  context.events.emplace_back(event);
  return context.events.size() - 1;
}

/**
 * @brief adds a location to the behavior and returns a pointer to it
 * 
 * @param loc : location object to add
 * @return Location*
*/
VIPRA::idx HumanBehavior::addLocation(Location loc) {
  context.locations.emplace_back(loc);
  return context.locations.size() - 1;
}

/**
 * @brief Returns the number of events the behavior has
 * 
 * @return VIPRA::size 
 */
VIPRA::size HumanBehavior::eventCount() const { return context.events.size(); }

/**
 * @brief Returns the number of selectors the behavior has
 * 
 * @return VIPRA::size 
 */
VIPRA::size HumanBehavior::selectorCount() const { return selector.selectorCount(); }

/**
 * @brief Returns the number of actions the behavior has
 * 
 * @return VIPRA::size 
 */
VIPRA::size HumanBehavior::actionCount() const {
  VIPRA::size cnt = 0;
  for (const auto& actionGroup : actions) {
    cnt += actionGroup.size();
  }

  return cnt;
}

/**
 * @brief Sets the seed for the behavior
 * 
 * @param s : 
 */
void HumanBehavior::setSeed(BHVR::seed bSeed) {
  rngEngine.reseed(bSeed);
  seedNum = bSeed;
}

void HumanBehavior::evaluateEvents(PedestrianSet& pedSet, ObstacleSet& obsSet,
                                   Goals& goals, VIPRA::delta_t dT) {
  for (auto& event : context.events) {
    event.evaluate(pedSet, obsSet, goals, context, dT);
  }
}

void HumanBehavior::applyActions(PedestrianSet& pedSet, ObstacleSet& obsSet, Goals& goals,
                                 VIPRA::State& state, VIPRA::delta_t dT) {
  const GroupsContainer& groups = selector.getGroups();
  const VIPRA::size      groupCnt = groups.size();

  for (VIPRA::idx i = 0; i < groupCnt; ++i) {
    const auto& pedestrians = groups.at(i);
    std::for_each(pedestrians.begin(), pedestrians.end(), [&](VIPRA::idx ped) {
      for (auto& action : actions[i]) {
        action.performAction(pedSet, obsSet, goals, context, ped, dT, state);
      }
    });
  }
}

// ------------------------------------------ CONSTRUCTORS ------------------------------------------------------------------------

HumanBehavior::HumanBehavior(std::string behaviorName)
    : name(std::move(behaviorName)), context() {}

// ------------------------------------------ END CONSTRUCTORS ------------------------------------------------------------------------
}  // namespace BHVR