#include "behavior/human_behavior.hpp"

#include <numeric>

const std::string&
HumanBehavior::getName() const noexcept {
  return name;
}

void
HumanBehavior::addAction(Action&& action) {
  pedActions.emplace_back(std::move(action));
}

void
HumanBehavior::initialize(const PedestrianSet& pedSet, const ObstacleSet& obsSet, const Goals& goals) {
  selector->initialize(pedSet, obsSet, goals);
}

void
HumanBehavior::timestep(const PedestrianSet&          pedSet,
                        const ObstacleSet&            obsSet,
                        const Goals&                  goals,
                        std::shared_ptr<VIPRA::State> state,
                        VIPRA::delta_t                dT) {
  // TODO evaluate transitions

  const auto& selectedPeds = selector->getSelectedPeds(pedSet, obsSet, goals, context);

  std::for_each(pedActions.begin(), pedActions.end(), [&](Action& action) {
    std::for_each(selectedPeds.begin(), selectedPeds.end(), [&](VIPRA::idx pedIdx) {
      action.performAction(pedSet, obsSet, goals, context, pedIdx, dT, state);
    });
  });
}

void
HumanBehavior::addParameter(std::string param) {
  parameters.emplace_back(param);
}

// ------------------------------------------ CONSTRUCTORS ------------------------------------------------------------------------

HumanBehavior::HumanBehavior(std::string behaviorName)
  : name(behaviorName), selector(nullptr), pedTransitions(), envTransitions(), pedActions(), context() {}

HumanBehavior::HumanBehavior(HumanBehavior&& other) noexcept
  : name(std::move(other.name)), selector(std::move(other.selector)), pedTransitions(std::move(other.pedTransitions)),
    envTransitions(std::move(other.envTransitions)), pedActions(std::move(other.pedActions)) {}

HumanBehavior&
HumanBehavior::operator=(HumanBehavior&& other) noexcept {
  name = std::move(other.name);
  selector = std::move(other.selector);
  pedTransitions = std::move(other.pedTransitions);
  envTransitions = std::move(other.envTransitions);
  pedActions = std::move(other.pedActions);
  return (*this);
}

// ------------------------------------------ END CONSTRUCTORS ------------------------------------------------------------------------