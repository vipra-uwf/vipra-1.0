#ifndef POLICY_MODEL_HPP
#define POLICY_MODEL_HPP

#include "definitions/config_map.hpp"
#include "definitions/state.hpp"
#include "definitions/type_definitions.hpp"
#include "goals/goals.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"

class PolicyModel {
 public:
  void configure(const VIPRA::ConfigMap& configMap);
  void timestep(const PedestrianSet&,
                const ObstacleSet&,
                const Goals&,
                std::shared_ptr<VIPRA::State>,
                VIPRA::delta_t timestep_size);
};

#endif