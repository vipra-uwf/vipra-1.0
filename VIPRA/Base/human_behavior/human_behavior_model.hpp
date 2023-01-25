//
// Created by joe on 8/3/21.
//

#ifndef VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
#define VIPRA_HUMAN_BEHAVIOR_MODEL_HPP

#include "definitions/behavior_definitions.hpp"
#include "definitions/state.hpp"
#include "dsl/human_behavior.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

#include "definitions/config_map.hpp"

class HumanBehaviorModel {

 private:
  std::vector<HumanBehavior*> humanBehaviors;

 protected:
  unsigned int seed;

 public:
  HumanBehaviorModel();
  virtual ~HumanBehaviorModel();
  virtual void configure(const VIPRA::ConfigMap& configMap);
  virtual void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&);
  void timestep(const PedestrianSet&, const ObstacleSet&, const Goals&, std::shared_ptr<VIPRA::State>, VIPRA::delta_t);
};

#endif  //VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
