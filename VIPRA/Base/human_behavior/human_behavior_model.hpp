//
// Created by joe on 8/3/21.
//

#ifndef VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
#define VIPRA_HUMAN_BEHAVIOR_MODEL_HPP

#include "behavior/behavior_builder.hpp"
#include "behavior/human_behavior.hpp"

#include "definitions/behavior_definitions.hpp"
#include "definitions/config_map.hpp"
#include "definitions/state.hpp"

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
  std::vector<HumanBehavior> humanBehaviors;
  VIPRA::size                seed;

 public:
  HumanBehaviorModel() = default;
  ~HumanBehaviorModel() = default;
  void configure(const VIPRA::Config::Map& configMap);
  void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&);
  void timestep(const PedestrianSet&, const ObstacleSet&, const Goals&, std::shared_ptr<VIPRA::State>, VIPRA::delta_t);

 private:
  void loadBehaviors(std::vector<std::string>);
  void loadMockBehaviors(const std::vector<std::string>& behaviors);
};

#endif  //VIPRA_HUMAN_BEHAVIOR_MODEL_HPP