#ifndef VIPRA_BHVR_EVENT_HPP
#define VIPRA_BHVR_EVENT_HPP

#include <functional>

#include <conditions/condition.hpp>
#include <definitions/behavior_context.hpp>
#include <events/event_status.hpp>
#include "definitions/sim_pack.hpp"
#include "util/bool_latch.hpp"

namespace BHVR {

/**
   * @brief An Event is something that occurs during a simulation, when an event starts it notifies it's subscribing functions and same when it ends
   *
   */
class Event {
 public:
  explicit Event(std::string);

  void evaluate(Simpack);

  void setStartCondition(const Condition&);
  void setEndCondition(const Condition&);

  [[nodiscard]] bool isOccurring() const;
  [[nodiscard]] bool hasOccurred() const;
  [[nodiscard]] bool isStarting() const;
  [[nodiscard]] bool isEnding() const;

  void                             setStatus(EventStatus);
  [[nodiscard]] const EventStatus& getStatus() const;

  [[nodiscard]] const std::string& getName() const;

 private:
  std::string name;
  EventStatus status{EventStatus::NOT_OCCURRING};
  bool        occurred = false;

  Latch     latch;
  Condition startCondition;
  Condition endCondition;

 public:
  ~Event() = default;
  Event(Event&&) noexcept = default;
  Event& operator=(Event&&) noexcept = default;
  Event() = default;
  Event(const Event&) = default;
  Event& operator=(const Event&) = default;
};
}  // namespace BHVR

#endif