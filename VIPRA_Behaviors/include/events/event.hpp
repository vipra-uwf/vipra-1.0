#ifndef VIPRA_BEHAVIORS_EVENT_HPP
#define VIPRA_BEHAVIORS_EVENT_HPP

#include <functional>

#include <conditions/condition.hpp>
#include <definitions/behavior_context.hpp>

namespace Behaviors {

typedef std::function<void(float)> EventHandler;

/**
   * @brief An Event is something that occurs during a simulation, when an event starts it notifies it's subscribing functions and same when it ends
   * 
   */
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

  void onStart(EventHandler);
  void onEnd(EventHandler);

  const std::string& getName() const;

 private:
  std::string name;
  bool        occurring;

  Condition startCondition;
  Condition endCondition;

  std::vector<EventHandler> startHandlers;
  std::vector<EventHandler> endHandlers;
};
}  // namespace Behaviors

#endif