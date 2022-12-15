//
// Created by joe on 8/3/21.
//

#ifndef VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
#define VIPRA_HUMAN_BEHAVIOR_MODEL_HPP

#include "definitions/behavior_definitions.hpp"
#include "definitions/state.hpp"
#include "dsl/human_behavior.hpp"
#include "goals/goals.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "pedestrianset/pedestrian_set.hpp"

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
  void timestep(const PedestrianSet&, const ObstacleSet&, const Goals&, float timestep, VIPRA::State&);
};

#endif  //VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
