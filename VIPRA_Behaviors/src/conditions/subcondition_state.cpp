
#include <conditions/subconditions/subcondition_state.hpp>

namespace Behaviors {
SubCondition_State::SubCondition_State(Behaviors::stateUID state, bool pedEnv) : cond_State(state), pedOrEnv(pedEnv) {}

bool
SubCondition_State::operator()(const PedestrianSet&,
                               const ObstacleSet&,
                               const Goals&,
                               const BehaviorContext& context,
                               VIPRA::idx             pedIndex,
                               VIPRA::delta_t) {
  if (pedOrEnv) {
    return context.pedStates.at(pedIndex) == cond_State;
  } else {
    return context.environmentState == cond_State;
  }
}
}  // namespace Behaviors