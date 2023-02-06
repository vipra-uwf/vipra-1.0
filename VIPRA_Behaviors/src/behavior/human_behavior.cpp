#include "behavior/human_behavior.hpp"

HumanBehavior::HumanBehavior(HumanBehavior&& other) noexcept
  : selector(std::move(other.selector)), pedTransitions(std::move(other.pedTransitions)),
    envTransitions(std::move(other.envTransitions)), pedActions(std::move(other.pedActions)) {}

HumanBehavior&
HumanBehavior::operator=(HumanBehavior&& other) noexcept {
  selector = std::move(other.selector);
  pedTransitions = std::move(other.pedTransitions);
  envTransitions = std::move(other.envTransitions);
  pedActions = std::move(other.pedActions);
  return (*this);
}

void
HumanBehavior::initialize(const ObstacleSet&, const PedestrianSet&, const Goals&) {}

void
HumanBehavior::timestep(const ObstacleSet&            obstacleSet,
                        const PedestrianSet&          pedestrianSet,
                        const Goals&                  goals,
                        std::shared_ptr<VIPRA::State> state,
                        VIPRA::delta_t                time) {}