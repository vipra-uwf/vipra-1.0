
#include <events/event.hpp>
#include <utility>
#include "definitions/behavior_context.hpp"

#include <spdlog/spdlog.h>

namespace BHVR {

/**
 * @brief Evaluates whether an event should start or end based on its conditions
 * 
 * @param pedSet : pedestrian set object
 * @param obsSet : obstacle set object
 * @param goals : goals object
 * @param context : behavior context
 * @param dT : simulation timestep size
 */
void Event::evaluate(const PedestrianSet& pedSet, const ObstacleSet& obsSet, const Goals& goals,
                     const BehaviorContext& context, VIPRA::delta_t dT) {
  if (!isOccurring()) {
    if (startCondition.evaluate(pedSet, obsSet, goals, context, 0, dT)) {
      spdlog::info("Event \"{}\" has Started", name);
      started = true;
      occurred = true;
      startTime = context.elapsedTime;
    } else {
      if (endCondition.evaluate(pedSet, obsSet, goals, context, 0, dT)) {
        spdlog::info("Event \"{}\" has Ended", name);
        started = false;
        ended = true;
        endTime = context.elapsedTime;
      }
    }
  }
}

bool Event::hasStarted() const {
  return started;
}

bool Event::hasEnded() const {
  return ended;
}

bool Event::isOccurring() const {
  return started && !ended;
}

bool Event::hasOccurred() const {
  return occurred;
}

void Event::setStartCondition(const Condition& condition) {
  startCondition = condition;
}

void Event::setEndCondition(const Condition& condition) {
  endCondition = condition;
}

float Event::timeSinceLastStart(const BehaviorContext& context) const {
  return context.elapsedTime - startTime;
}

const std::string& Event::getName() const {
  return name;
}

// ---------------------------------- CONSTRUCTORS -----------------------------------------------------------

Event::Event(std::string evName) : name(std::move(evName)), occurred(false), started(false), ended(false) {}

// ---------------------------------- END CONSTRUCTORS -----------------------------------------------------------

}  // namespace BHVR
