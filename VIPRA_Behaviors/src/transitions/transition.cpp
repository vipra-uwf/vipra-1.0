

#include <transitions/transition.hpp>

Transition::Transition(VIPRA::stateUID state) : newState(state) {}

void
Transition::addCondition(Condition&& cond) {
  condition = std::move(cond);
}

void
Transition::evaluate(const PedestrianSet& pedset,
                     const ObstacleSet&   obsset,
                     const Goals&         goals,
                     BehaviorContext&     context,
                     VIPRA::idx           idx,
                     VIPRA::delta_t       dT) {
  if (condition.evaluate(pedset, obsset, goals, context, idx, dT)) {
    if (idx == std::numeric_limits<VIPRA::idx>::max()) {
      spdlog::debug("Environment Transitioning");
      context.environmentState = newState;
    } else {
      spdlog::debug("Pedestrian {} Transitioning", idx);
      context.pedStates[idx] = newState;
    }
  }
}