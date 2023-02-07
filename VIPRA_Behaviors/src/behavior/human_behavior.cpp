#include "behavior/human_behavior.hpp"

const std::string&
HumanBehavior::getName() const noexcept {
  return name;
}

void
HumanBehavior::addAction(Action&& action) {
  pedActions.emplace_back(std::move(action));
}

void
HumanBehavior::initialize(const ObstacleSet&, const PedestrianSet&, const Goals&) {}

void
HumanBehavior::timestep(const ObstacleSet&            obstacleSet,
                        const PedestrianSet&          pedestrianSet,
                        const Goals&                  goals,
                        std::shared_ptr<VIPRA::State> state,
                        VIPRA::delta_t                time) {}

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