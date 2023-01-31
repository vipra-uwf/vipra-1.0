//
// Created by joe on 8/3/21.
//

#ifndef VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
#define VIPRA_HUMAN_BEHAVIOR_MODEL_HPP

#include "definitions/behavior_definitions.hpp"
#include "definitions/config_map.hpp"
#include "definitions/state.hpp"
#include "dsl/dsl_human_behavior.hpp"
#include "dsl/human_behavior.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"


class HumanBehaviorModel {

 private:
  std::vector<std::unique_ptr<HumanBehavior>> humanBehaviors;

 protected:
  unsigned int seed;

 public:
  HumanBehaviorModel();
  ~HumanBehaviorModel();
  void configure(const VIPRA::Config::Map& configMap);
  void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&);
  void timestep(const PedestrianSet&, const ObstacleSet&, const Goals&, std::shared_ptr<VIPRA::State>, VIPRA::delta_t);
};

#endif  //VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
