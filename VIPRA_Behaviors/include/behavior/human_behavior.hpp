#ifndef VIPRA_HUMAN_BEHAVIOR_HPP
#define VIPRA_HUMAN_BEHAVIOR_HPP

#include <spdlog/spdlog.h>

#include <definitions/behavior_context.hpp>
#include <definitions/dsl_types.hpp>
#include <definitions/type_definitions.hpp>

#include <actions/action.hpp>
#include <events/event.hpp>
#include <locations/location.hpp>
#include <goals/goals.hpp>
#include <obstacle_set/obstacle_set.hpp>
#include <pedestrian_set/pedestrian_set.hpp>
#include <selectors/selector.hpp>


namespace BHVR {
/**
 * Describes a specific human behavior. Implementations can either define the behavior directly in C++ or use a DSL.
 */
class HumanBehavior {
 public:
  explicit HumanBehavior(std::string);

  [[nodiscard]] const std::string& getName() const noexcept;

  void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&);
  void timestep(PedestrianSet&, ObstacleSet&, Goals&, VIPRA::State&, VIPRA::delta_t);

  void       setAllPedTypes(Ptype);
  void       addSubSelector(const SubSelector&);
  void       addAction(typeUID, const Action&);
  VIPRA::idx addEvent(const Event&);
  VIPRA::idx addLocation(Location&&);

  [[nodiscard]] VIPRA::size eventCount() const;
  [[nodiscard]] VIPRA::size selectorCount() const;
  [[nodiscard]] VIPRA::size actionCount() const;

  void setSeed(BHVR::seed);

 private:
  BHVR::seed seedNum = 0;

  std::string     name;
  BehaviorContext context;

  Selector                         selector;
  std::vector<Event>               events;
  std::vector<Location*>            locations;
  std::vector<std::vector<Action>> actions;

  void evaluateEvents(PedestrianSet&, ObstacleSet&, Goals&, VIPRA::delta_t);
  void applyActions(PedestrianSet&, ObstacleSet&, Goals&, VIPRA::State&, VIPRA::delta_t);

 public:
  HumanBehavior() = default;
  ~HumanBehavior() = default;
  HumanBehavior& operator=(const HumanBehavior&) = default;
  HumanBehavior(const HumanBehavior&) = default;
  HumanBehavior(HumanBehavior&&) noexcept = default;
  HumanBehavior& operator=(HumanBehavior&&) noexcept = default;
};
}  // namespace BHVR

#endif
