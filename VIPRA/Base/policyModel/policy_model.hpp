#ifndef POLICY_MODEL_HPP
#define POLICY_MODEL_HPP

#include "../definitions/type_definitions.hpp"

#include "../../Extendable/goals/goals.hpp"
#include "../../Extendable/obstacleset/obstacle_set.hpp"
#include "../../Extendable/pedestrianset/pedestrian_set.hpp"

#include "../_pch/pch.hpp"

class PolicyModel {
 public:
  void timestep(const PedestrianSet&,
                const ObstacleSet&,
                const Goals&,
                State&          outState,
                FLOATING_NUMBER timestep_size);
};

#endif