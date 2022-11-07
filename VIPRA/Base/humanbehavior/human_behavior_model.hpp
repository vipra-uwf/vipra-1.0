//
// Created by joe on 8/3/21.
//

#ifndef VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
#define VIPRA_HUMAN_BEHAVIOR_MODEL_HPP

#include "../../Extendable/goals/goals.hpp"
#include "../../Extendable/obstacleset/obstacle_set.hpp"
#include "../../Extendable/pedestrianset/pedestrian_set.hpp"
#include "../definitions/behavior_definitions.hpp"
#include "../dsl/human_behavior.hpp"

class HumanBehaviorModel {

 private:
  std::vector<HumanBehavior*> humanBehaviors;

 protected:
  unsigned int seed;

 public:
  HumanBehaviorModel();
  virtual ~HumanBehaviorModel();
  virtual void configure(const CONFIG_MAP& configMap);

  virtual void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&);
  void         update(const PedestrianSet&, const ObstacleSet&, const Goals&, FLOATING_NUMBER timestep);
};

#endif  //VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
