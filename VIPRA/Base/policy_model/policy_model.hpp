#ifndef POLICY_MODEL_HPP
#define POLICY_MODEL_HPP

#include <definitions/config_map.hpp>
#include <definitions/state.hpp>
#include <definitions/type_definitions.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

class PolicyModel {
 public:
  void configure(const VIPRA::CONFIG::Map&);
  void timestep(const PedestrianSet&, const ObstacleSet&, const Goals&, VIPRA::State&,
                VIPRA::delta_t);
};

#endif