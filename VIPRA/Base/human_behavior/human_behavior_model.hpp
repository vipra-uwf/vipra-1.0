//
// Created by joe on 8/3/21.
//

#ifndef VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
#define VIPRA_HUMAN_BEHAVIOR_MODEL_HPP

#include "definitions/behavior_definitions.hpp"
#include "definitions/config_map.hpp"
#include "definitions/state.hpp"
#include "dsl/behavior_builder.hpp"
#include "dsl/human_behavior.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

class BehaviorModelException : public std::runtime_error {
 public:
  BehaviorModelException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw BehaviorModelException(message); }
};

class HumanBehaviorModel {

 private:
  std::vector<std::unique_ptr<HumanBehavior>> humanBehaviors;
  VIPRA::size                                 seed;

 public:
  HumanBehaviorModel();
  ~HumanBehaviorModel();
  void configure(const VIPRA::Config::Map& configMap);
  void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&);
  void timestep(const PedestrianSet&, const ObstacleSet&, const Goals&, std::shared_ptr<VIPRA::State>, VIPRA::delta_t);

 private:
  void loadBehaviors(std::vector<std::string>);
};

#endif  //VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
