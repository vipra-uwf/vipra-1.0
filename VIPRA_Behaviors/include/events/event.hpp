#ifndef VIPRA_BEHAVIORS_EVENT_HPP
#define VIPRA_BEHAVIORS_EVENT_HPP

#include <functional>

#include <conditions/condition.hpp>
#include <definitions/behavior_context.hpp>

namespace Behaviors {
class Event {
 public:
  ~Event() = default;

  Event() = delete;
  Event(const Event&) = delete;
  Event& operator=(const Event&) = delete;

  Event(std::string);
  Event(Event&&) noexcept;
  Event& operator=(Event&&) noexcept;

  void evaluate(const PedestrianSet&, const ObstacleSet&, const Goals&, const BehaviorContext&, VIPRA::delta_t);

  void setStartCondition(Condition&&);
  void setEndCondition(Condition&&);

  void onStart(std::function<void()>);
  void onEnd(std::function<void()>);

  const std::string& getName() const;

 private:
  std::string name;
  bool        occurring;

  Condition startCondition;
  Condition endCondition;

  std::vector<std::function<void()>> startHandlers;
  std::vector<std::function<void()>> endHandlers;
};
}  // namespace Behaviors

#endif