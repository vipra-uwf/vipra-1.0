
#include <utility>

#include <spdlog/spdlog.h>

#include <events/event.hpp>

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
void Event::evaluate(const PedestrianSet& pedSet, const ObstacleSet& obsSet, const Goals& goals, BehaviorContext& context,
                     VIPRA::delta_t dT) {

  if (!latch && startCondition.evaluate(pedSet, obsSet, goals, context, 0, dT)) {
    latch.latch();
    spdlog::info("Event \"{}\" has Started", name);
  }

  if (endCondition.evaluate(pedSet, obsSet, goals, context, 0, dT)) {
    latch.unlatch();
  }

  if (latch) {
    occurred = true;
    occurring = true;
  } else {
    spdlog::info("Event \"{}\" has Ended", name);
    occurring = false;
  }
}


bool Event::isOccurring() const {
  return occurring;
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

const std::string& Event::getName() const {
  return name;
}

// ---------------------------------- CONSTRUCTORS -----------------------------------------------------------

Event::Event(std::string evName) : name(std::move(evName)), occurred(false), occurring(false) {}

// ---------------------------------- END CONSTRUCTORS -----------------------------------------------------------

}  // namespace BHVR
