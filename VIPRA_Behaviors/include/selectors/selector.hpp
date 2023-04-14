#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include <any>
#include <functional>

#include <spdlog/spdlog.h>

#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>

#include <actions/action.hpp>
#include <definitions/behavior_context.hpp>
#include <definitions/pedestrian_types.hpp>

namespace Behaviors {

using SelectorFunc = std::function<std::vector<VIPRA::idx>(seed, const PedestrianSet&, const ObstacleSet&, const Goals&)>;

class Selector {
 public:
  ~Selector() = default;

  Selector() = delete;
  Selector(const Selector&) = delete;
  Selector& operator=(const Selector&) = delete;

  Selector(typeUID, pType, SelectorFunc&&);

  Selector(Selector&&) noexcept;
  Selector& operator=(Selector&&) noexcept;

  Selector(SelectorFunc&&);

  void initialize(const std::string&, Behaviors::seed, const PedestrianSet&, const ObstacleSet&, const Goals&);

  void timestep(PedestrianSet&, ObstacleSet&, Goals&, BehaviorContext&, VIPRA::delta_t, std::shared_ptr<VIPRA::State>);

  void addAction(Action&&);

  typeUID Group() const;
  pType   Type() const;

  size_t actionCount() const;

 private:
  typeUID      group;
  pType        type;
  SelectorFunc selector;

  std::vector<Action> actions;

  std::vector<VIPRA::idx> selectedPeds;
};
}  // namespace Behaviors

#endif