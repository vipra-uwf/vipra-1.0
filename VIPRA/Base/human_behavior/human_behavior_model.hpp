#ifndef VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
#define VIPRA_HUMAN_BEHAVIOR_MODEL_HPP

#include "behavior/human_behavior.hpp"
#include "builder/behavior_builder.hpp"
#include "configuration/config.hpp"
#include "definitions/state.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

namespace VIPRA {
class BehaviorModelException : public std::runtime_error {
 public:
  explicit BehaviorModelException(const std::string& message)
      : std::runtime_error(message) {}
  static void error(const std::string& message) { throw BehaviorModelException(message); }
};

/**
 * @brief Coordinator for Human Behaviors
 * 
 */
class HumanBehaviorModel {
 public:
  explicit HumanBehaviorModel(std::vector<BHVR::HumanBehavior> humanBehaviors)
      : humanBehaviors(std::move(humanBehaviors)) {}
  void configure(const VIPRA::Config& configMap);
  void initialize(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&, VIPRA::Goals&);
  void timestep(VIPRA::PedestrianSet&, VIPRA::ObstacleSet&, VIPRA::Goals&, VIPRA::State&,
                VIPRA::delta_t);

 private:
  std::vector<BHVR::HumanBehavior> humanBehaviors;
  VIPRA::size                      seed{};

  void loadBehaviors(const VIPRA::Config&);
  void loadMockBehavior(const std::vector<std::string>&);

 public:
  HumanBehaviorModel() = default;
  HumanBehaviorModel(const HumanBehaviorModel&) = default;
  HumanBehaviorModel(HumanBehaviorModel&&) = default;
  HumanBehaviorModel& operator=(const HumanBehaviorModel&) = default;
  HumanBehaviorModel& operator=(HumanBehaviorModel&&) = default;
  ~HumanBehaviorModel() = default;
};
}  // namespace VIPRA

#endif  //VIPRA_HUMAN_BEHAVIOR_MODEL_HPP
