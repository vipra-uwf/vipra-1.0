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
HumanBehavior::addAction(Action&& action) {
  pedActions.emplace_back(std::move(action));
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
  selector->initialize(pedSet, obsSet, goals);
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
  std::for_each(events.begin(), events.end(), [&](Event& event) { event.evaluate(pedSet, obsSet, goals, context, dT); });

  const auto& selectedPeds = selector->getSelectedPeds(pedSet, obsSet, goals, context);

  std::for_each(selectedPeds.begin(), selectedPeds.end(), [&](VIPRA::idx pedIdx) {
    std::for_each(pedActions.begin(), pedActions.end(), [&](Action& action) {
      action.performAction(pedSet, obsSet, goals, context, pedIdx, dT, state);
    });
  });

  context.elapsedTime += dT;
}

void
HumanBehavior::addParameter(std::string param) {
  parameters.emplace_back(param);
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
HumanBehavior::actionCount() const {
  return pedActions.size();
}

size_t
HumanBehavior::eventCount() const {
  return events.size();
}

// ------------------------------------------ CONSTRUCTORS ------------------------------------------------------------------------

HumanBehavior::HumanBehavior(std::string behaviorName)
  : name(behaviorName), context(), parameters(), selector(nullptr), events(), pedActions() {}

HumanBehavior::HumanBehavior(HumanBehavior&& other) noexcept
  : name(std::move(other.name)), context(std::move(other.context)), parameters(std::move(other.parameters)),
    selector(std::move(other.selector)), events(std::move(other.events)), pedActions(std::move(other.pedActions)) {}

HumanBehavior&
HumanBehavior::operator=(HumanBehavior&& other) noexcept {
  name = (std::move(other.name));
  context = (std::move(other.context));
  parameters = (std::move(other.parameters));
  selector = (std::move(other.selector));
  events = (std::move(other.events));
  pedActions = (std::move(other.pedActions));
  return (*this);
}

// ------------------------------------------ END CONSTRUCTORS ------------------------------------------------------------------------
}  // namespace Behaviors