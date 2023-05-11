
#include <events/event.hpp>

#include <spdlog/spdlog.h>

namespace Behaviors {

/**
 * @brief Evaluates whether an event should start or end based on its conditions
 * 
 * @param pedSet : pedestrian set object
 * @param obsSet : obstacle set object
 * @param goals : goals object
 * @param context : behavior context
 * @param dT : simulation timestep size
 */
void
Event::evaluate(const PedestrianSet&   pedSet,
                const ObstacleSet&     obsSet,
                const Goals&           goals,
                const BehaviorContext& context,
                VIPRA::delta_t         dT) {
  if (!occurring) {
    if (startCondition.evaluate(pedSet, obsSet, goals, context, 0, dT)) {
      spdlog::debug("Event \"{}\" has Started", name);
      occurring = true;
      std::for_each(startHandlers.begin(), startHandlers.end(), [&](EventHandler handler) { handler(context.elapsedTime); });
    }
  } else {
    if (endCondition.evaluate(pedSet, obsSet, goals, context, 0, dT)) {
      spdlog::debug("Event \"{}\" has Ended", name);
      occurring = false;
      std::for_each(endHandlers.begin(), endHandlers.end(), [&](EventHandler handler) { handler(context.elapsedTime); });
    }
  }
}

/**
 * @brief Adds an event handler for when the event starts
 * 
 * @param handler : handler function to add
 */
void
Event::onStart(EventHandler handler) {
  startHandlers.emplace_back(handler);
}

/**
 * @brief Adds an event handler for when the event ends
 * 
 * @param handler : handler function to add
 */
void
Event::onEnd(EventHandler handler) {
  endHandlers.emplace_back(handler);
}

void
Event::setStartCondition(Condition&& condition) {
  startCondition = std::move(condition);
}

void
Event::setEndCondition(Condition&& condition) {
  endCondition = std::move(condition);
}

const std::string&
Event::getName() const {
  return name;
}

// ---------------------------------- CONSTRUCTORS -----------------------------------------------------------

Event::Event(std::string evName)
  : name(evName), occurring(false), startCondition(), endCondition(), startHandlers(), endHandlers() {}

Event::Event(Event&& other) noexcept
  : name(std::move(other.name)), occurring(other.occurring), startCondition(std::move(other.startCondition)),
    endCondition(std::move(other.endCondition)), startHandlers(std::move(other.startHandlers)),
    endHandlers(std::move(other.endHandlers)) {}

Event&
Event::operator=(Event&& other) noexcept {
  occurring = other.occurring;
  name = std::move(other.name);
  startCondition = std::move(other.startCondition);
  endCondition = std::move(other.endCondition);
  startHandlers = std::move(other.startHandlers);
  endHandlers = std::move(other.endHandlers);
  return (*this);
}

// ---------------------------------- END CONSTRUCTORS -----------------------------------------------------------

}  // namespace Behaviors
