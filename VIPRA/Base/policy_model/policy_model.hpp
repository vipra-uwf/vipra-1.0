#ifndef POLICY_MODEL_HPP
#define POLICY_MODEL_HPP

#include <definitions/state.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>
#include "configuration/config.hpp"
#include "definitions/type_definitions.hpp"

namespace VIPRA {
class PolicyModel {
 public:
  void configure(const VIPRA::Config&);
  void timestep(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&,
                const VIPRA::Goals&, VIPRA::State&, VIPRA::delta_t);
};

}  // namespace VIPRA

#endif