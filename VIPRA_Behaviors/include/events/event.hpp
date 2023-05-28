#ifndef VIPRA_BHVR_EVENT_HPP
#define VIPRA_BHVR_EVENT_HPP

#include <functional>

#include <conditions/condition.hpp>
#include <definitions/behavior_context.hpp>
#include "util/bool_latch.hpp"

namespace BHVR {

/**
   * @brief An Event is something that occurs during a simulation, when an event starts it notifies it's subscribing functions and same when it ends
   *
   */
class Event {
 public:
  ~Event() = default;
  Event(Event&&) noexcept = default;
  Event& operator=(Event&&) noexcept = default;
  Event() = default;
  Event(const Event&) = default;
  Event& operator=(const Event&) = default;

  explicit Event(std::string);

  void evaluate(const PedestrianSet&, const ObstacleSet&, const Goals&, BehaviorContext&, VIPRA::delta_t);

  void setStartCondition(const Condition&);
  void setEndCondition(const Condition&);

  bool isOccurring() const;
  bool hasOccurred() const;

  const std::string& getName() const;

 private:
  std::string name;
  bool        occurred;
  bool        occurring;

  Latch     latch;
  Condition startCondition;
  Condition endCondition;
};
}  // namespace BHVR

#endif