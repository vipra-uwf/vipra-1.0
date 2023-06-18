#ifndef VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
#define VIPRA_HUMAN_BEHAVIOR_MODEL_HPP

#include <behavior/behavior_builder.hpp>
#include <behavior/human_behavior.hpp>
#include <definitions/config_map.hpp>
#include <definitions/state.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

class BehaviorModelException : public std::runtime_error {
 public:
  explicit BehaviorModelException(const std::string& message)
      : std::runtime_error(message) {}
  static void error(const std::string& message) { throw BehaviorModelException(message); }
};

class HumanBehaviorModel {
 public:
  explicit HumanBehaviorModel(std::vector<BHVR::HumanBehavior> humanBehaviors)
      : humanBehaviors(std::move(humanBehaviors)) {}
  void configure(const VIPRA::CONFIG::Map& configMap);
  void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&);
  void timestep(PedestrianSet&, ObstacleSet&, Goals&, VIPRA::State&, VIPRA::delta_t);

 private:
  std::vector<BHVR::HumanBehavior> humanBehaviors;
  VIPRA::size                      seed{};

  void loadBehavior(const std::vector<std::string>&);
  void loadMockBehavior(const std::vector<std::string>&);

 public:
  HumanBehaviorModel() = default;
  HumanBehaviorModel(const HumanBehaviorModel&) = default;
  HumanBehaviorModel(HumanBehaviorModel&&) = default;
  HumanBehaviorModel& operator=(const HumanBehaviorModel&) = default;
  HumanBehaviorModel& operator=(HumanBehaviorModel&&) = default;
  ~HumanBehaviorModel() = default;
};

#endif  //VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
