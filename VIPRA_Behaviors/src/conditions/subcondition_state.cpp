
#include <conditions/subconditions/subcondition_state.hpp>

SubCondition_State::SubCondition_State(VIPRA::stateUID state, bool pedEnv) : cond_State(state), pedOrEnv(pedEnv) {}

bool
SubCondition_State::operator()(const PedestrianSet&,
                               const ObstacleSet&,
                               const Goals&,
                               const BehaviorContext& context,
                               VIPRA::idx             pedIndex,
                               VIPRA::delta_t) const {
  if (pedOrEnv) {
    return context.pedStates.at(pedIndex) == cond_State;
  } else {
    return context.environmentState == cond_State;
  }
}