#ifndef POLICY_MODEL_HPP
#define POLICY_MODEL_HPP

#include "definitions/state.hpp"
#include "definitions/type_definitions.hpp"

#include "goals/goals.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"

class PolicyModel {
 public:
  void configure(const CONFIG_MAP& configMap);
  void timestep(const PedestrianSet&,
                const ObstacleSet&,
                const Goals&,
                FLOATING_NUMBER timestep_size,
                State&);
};

#endif