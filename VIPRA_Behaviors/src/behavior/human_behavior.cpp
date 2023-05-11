#include "behavior/human_behavior.hpp"

#include <numeric>

namespace Behaviors {

/**
 * @brief Returns the name of the behavior
 * 
 * @return const std::string& 
 */
const std::string&
HumanBehavior::getName() const noexcept {
  return name;
}

/**
 * @brief Adds an action to the selectors with type
 * 
 * @param action : action to add
 */
void
HumanBehavior::addAction(typeUID type, Action&& action) {
  const VIPRA::idx index = GroupsContainer::Index(type);
  actions[index].emplace_back(std::move(action));
}

/**
 * @brief Adds the selector to the behavior
 * 
 * @param selector
 */
void
HumanBehavior::addSubSelector(SubSelector&& subSelector) {
  selector.addSubSelector(std::move(subSelector));
}

/**
 * @brief Sets the behaviors selectors allTypes
 * 
 */
void
HumanBehavior::setAllPedTypes(pType types) {
  selector.setAllTypes(types);
  actions.resize(types.fullType);
}

/**
 * @brief initializes behavior selector
 * 
 * @param pedSet : pedestrian set object
 * @param obsSet : obstacle set object
 * @param goals : goals object
 */
void
HumanBehavior::initialize(const PedestrianSet& pedSet, const ObstacleSet& obsSet, const Goals& goals) {
  context.pedStates = std::vector<Behaviors::stateUID>(pedSet.getNumPedestrians());
  context.types = std::vector<Behaviors::stateUID>(pedSet.getNumPedestrians());

  spdlog::debug("Initializing {} Selectors, Seed: {}", selector.SelectorCount(), seedNum);
  selector.initialize(name, seedNum, context, pedSet, obsSet, goals);
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
void
HumanBehavior::timestep(PedestrianSet&                pedSet,
                        ObstacleSet&                  obsSet,
                        Goals&                        goals,
                        std::shared_ptr<VIPRA::State> state,
                        VIPRA::delta_t                dT) {
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
Event*
HumanBehavior::addEvent(Event&& event) {
  events.emplace_back(std::move(event));
  return &(events.back());
}

/**
 * @brief Returns the number of events the behavior has
 * 
 * @return VIPRA::size 
 */
VIPRA::size
HumanBehavior::eventCount() const {
  return events.size();
}

/**
 * @brief Returns the number of selectors the behavior has
 * 
 * @return VIPRA::size 
 */
VIPRA::size
HumanBehavior::selectorCount() const {
  return selector.SelectorCount();
}

/**
 * @brief Returns the number of actions the behavior has
 * 
 * @return VIPRA::size 
 */
VIPRA::size
HumanBehavior::actionCount() const {
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
void
HumanBehavior::setSeed(Behaviors::seed s) {
  seedNum = s;
}

void
HumanBehavior::evaluateEvents(PedestrianSet& pedSet, ObstacleSet& obsSet, Goals& goals, VIPRA::delta_t dT) {
  for (auto& event : events) {
    event.evaluate(pedSet, obsSet, goals, context, dT);
  }
}

void
HumanBehavior::applyActions(PedestrianSet&                pedSet,
                            ObstacleSet&                  obsSet,
                            Goals&                        goals,
                            std::shared_ptr<VIPRA::State> state,
                            VIPRA::delta_t                dT) {
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
  : seedNum(0), name(behaviorName), context(), selector(), events(), actions() {}

HumanBehavior::HumanBehavior(HumanBehavior&& other) noexcept
  : seedNum(other.seedNum), name(std::move(other.name)), context(std::move(other.context)),
    selector(std::move(other.selector)), events(std::move(other.events)), actions(std::move(other.actions)) {}

HumanBehavior&
HumanBehavior::operator=(HumanBehavior&& other) noexcept {
  seedNum = other.seedNum;
  name = (std::move(other.name));
  context = (std::move(other.context));
  selector = (std::move(other.selector));
  events = (std::move(other.events));
  actions = (std::move(other.actions));
  return (*this);
}

// ------------------------------------------ END CONSTRUCTORS ------------------------------------------------------------------------
}  // namespace Behaviors