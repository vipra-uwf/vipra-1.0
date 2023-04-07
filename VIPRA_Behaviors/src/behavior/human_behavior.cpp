#include "behavior/human_behavior.hpp"

#include <numeric>

namespace Behaviors {

const std::string&
HumanBehavior::getName() const noexcept {
  return name;
}

/**
 * @brief Adds an action to pedActions
 * 
 * @param action : action to add
 */
void
HumanBehavior::addAction(typeUID type, Action&& action) {
  for (auto& selector : selectors) {
    if (selector.Type() == type) {
      selector.addAction(std::forward<Action>(action));
      return;
    }
  }
}

void
HumanBehavior::addSelector(Selector&& selector) {
  selectors.emplace_back(std::move(selector));
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
  context.pedStates = std::vector<Behaviors::stateUID>(pedSet.getNumPedestrians(), 0);
  spdlog::debug("Initializing {} Selectors, Seed: {}", selectors.size(), seedNum);
  for (auto& selector : selectors) {
    spdlog::debug("Initializing Selector For Type Id: {}", selector.Type());
    selector.initialize(name, seedNum, pedSet, obsSet, goals);
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
void
HumanBehavior::timestep(PedestrianSet&                pedSet,
                        ObstacleSet&                  obsSet,
                        Goals&                        goals,
                        std::shared_ptr<VIPRA::State> state,
                        VIPRA::delta_t                dT) {

  for (auto& event : events) {
    event.evaluate(pedSet, obsSet, goals, context, dT);
  }

  for (auto& selector : selectors) {
    selector.timestep(pedSet, obsSet, goals, context, dT, state);
  }

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

size_t
HumanBehavior::eventCount() const {
  return events.size();
}

size_t
HumanBehavior::selectorCount() const {
  return selectors.size();
}

size_t
HumanBehavior::actionCount() const {
  size_t sum = 0;
  for (const auto& selector : selectors) {
    sum += selector.actionCount();
  }

  return sum;
}

void
HumanBehavior::setSeed(Behaviors::seed s) {
  seedNum = s;
}

// ------------------------------------------ CONSTRUCTORS ------------------------------------------------------------------------

HumanBehavior::HumanBehavior(std::string behaviorName) : seedNum(0), name(behaviorName), context(), selectors(), events() {}

HumanBehavior::HumanBehavior(HumanBehavior&& other) noexcept
  : seedNum(other.seedNum), name(std::move(other.name)), context(std::move(other.context)),
    selectors(std::move(other.selectors)), events(std::move(other.events)) {}

HumanBehavior&
HumanBehavior::operator=(HumanBehavior&& other) noexcept {
  seedNum = other.seedNum;
  name = (std::move(other.name));
  context = (std::move(other.context));
  selectors = (std::move(other.selectors));
  events = (std::move(other.events));
  return (*this);
}

// ------------------------------------------ END CONSTRUCTORS ------------------------------------------------------------------------
}  // namespace Behaviors