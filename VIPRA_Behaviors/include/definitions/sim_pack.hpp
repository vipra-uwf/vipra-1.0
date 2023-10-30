#ifndef VIPRA_BEHAVIORS_SIM_PACK_HPP
#define VIPRA_BEHAVIORS_SIM_PACK_HPP

#include <functional>

#include "definitions/behavior_context.hpp"
#include "definitions/state.hpp"
#include "definitions/type_definitions.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"
#include "selectors/pedestrian_groups.hpp"

namespace BHVR {
/**
  * @brief Holds references to commonly used parameters for simpler passing
  * 
  */
struct Simpack {
  std::reference_wrapper<const VIPRA::PedestrianSet> pedSet;
  std::reference_wrapper<const VIPRA::ObstacleSet>   obsSet;
  std::reference_wrapper<VIPRA::Goals>               goals;
  std::reference_wrapper<VIPRA::State>               state;
  std::reference_wrapper<BehaviorContext>            context;
  std::reference_wrapper<const GroupsContainer>      groups;
  VIPRA::delta_t                                     dT;

  [[nodiscard]] inline auto get_pedset() const noexcept -> const VIPRA::PedestrianSet& {
    return pedSet.get();
  }
  [[nodiscard]] inline auto get_obsset() const noexcept -> const VIPRA::ObstacleSet& { return obsSet.get(); }
  [[nodiscard]] inline auto get_goals() const noexcept -> VIPRA::Goals& { return goals.get(); }
  [[nodiscard]] inline auto get_state() const noexcept -> VIPRA::State& { return state.get(); }
  [[nodiscard]] inline auto get_context() const noexcept -> BehaviorContext& { return context.get(); }
  [[nodiscard]] inline auto get_groups() const noexcept -> const GroupsContainer& { return groups.get(); }
};
}  // namespace BHVR

#endif