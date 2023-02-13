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
  context.pedStates = std::vector<VIPRA::stateUID>(pedSet.getNumPedestrians(), 0);
  selector->initialize(pedSet, obsSet, goals);
}

void
HumanBehavior::timestep(const PedestrianSet&          pedSet,
                        const ObstacleSet&            obsSet,
                        const Goals&                  goals,
                        std::shared_ptr<VIPRA::State> state,
                        VIPRA::delta_t                dT) {

  std::for_each(envTransitions.begin(), envTransitions.end(), [&](Transition& trans) {
    trans.evaluate(pedSet, obsSet, goals, context, std::numeric_limits<VIPRA::idx>::max(), dT);
  });

  const auto& selectedPeds = selector->getSelectedPeds(pedSet, obsSet, goals, context);

  std::for_each(selectedPeds.begin(), selectedPeds.end(), [&](VIPRA::idx pedIdx) {
    std::for_each(pedTransitions.begin(), pedTransitions.end(), [&](Transition& trans) {
      trans.evaluate(pedSet, obsSet, goals, context, pedIdx, dT);
    });
  });

  std::for_each(selectedPeds.begin(), selectedPeds.end(), [&](VIPRA::idx pedIdx) {
    std::for_each(pedActions.begin(), pedActions.end(), [&](Action& action) {
      action.performAction(pedSet, obsSet, goals, context, pedIdx, dT, state);
    });
  });
}

void
HumanBehavior::addParameter(std::string param) {
  parameters.emplace_back(param);
}

void
HumanBehavior::addPedTransition(Transition&& transition) {
  pedTransitions.emplace_back(std::move(transition));
}

void
HumanBehavior::addEnvTransition(Transition&& transition) {
  envTransitions.emplace_back(std::move(transition));
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