
#include "conditions/condition_state.hpp"

condition_state::condition_state(VIPRA::stateUID) {}

bool
condition_state::operator()(const ObstacleSet&,
                            const PedestrianSet&,
                            const Goals&,
                            const BehaviorContext& context,
                            VIPRA::idx             pedIndex) const {
  return context.pedStates.at(pedIndex) == cond_State;
}