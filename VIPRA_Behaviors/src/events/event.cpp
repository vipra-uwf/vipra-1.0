
#include <utility>

#include <spdlog/spdlog.h>

#include <events/event.hpp>
#include "definitions/sim_pack.hpp"
#include "events/event_status.hpp"
#include "targets/target.hpp"

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
void Event::evaluate(Simpack pack) {
  if (status == EventStatus::ENDING) {
    status = EventStatus::NOT_OCCURRING;
  }
  if (status == EventStatus::STARTING) {
    status = EventStatus::OCCURRING;
  }

  // TODO (rolland) : These might need target selectors?
  if (status == EventStatus::OCCURRING) {
    if (endCondition.evaluate(pack, 0, {})) {
      spdlog::info("Event {} is Ending", name);
      status = EventStatus::ENDING;
    }

    return;
  }

  if (startCondition.evaluate(pack, 0, {})) {
    spdlog::info("Event {} is Starting", name);
    occurred = true;
    status = EventStatus::STARTING;
  }
}

/**
 * @brief Sets the events current status
 * 
 * @param stat : 
 */
void Event::setStatus(EventStatus stat) { status = stat; }

/**
 * @brief Checks if the event is occurring
 * 
 * @return true 
 * @return false 
 */
bool Event::isOccurring() const {
  return status == EventStatus::OCCURRING || status == EventStatus::STARTING;
}

/**
 * @brief Checks if the event has occurred at all during the simulation
 * 
 * @return true 
 * @return false 
 */
bool Event::hasOccurred() const { return occurred; }

/**
 * @brief Checks if the event is starting
 * 
 * @return true 
 * @return false 
 */
bool Event::isStarting() const { return status == EventStatus::STARTING; }

/**
 * @brief Checks if the event is ending
 * 
 * @return true 
 * @return false 
 */
bool Event::isEnding() const { return status == EventStatus::ENDING; }

/**
 * @brief Sets the condition for the event to start
 * 
 * @param condition : condition for event to start
 */
void Event::setStartCondition(const Condition& condition) { startCondition = condition; }

/**
 * @brief Sets the condition for the event to end
 * 
 * @param condition : condition for event to end
 */
void Event::setEndCondition(const Condition& condition) { endCondition = condition; }

/**
 * @brief Returns the events name
 * 
 * @return const std::string& 
 */
const std::string& Event::getName() const { return name; }

// ---------------------------------- CONSTRUCTORS -----------------------------------------------------------

Event::Event(std::string evName) : name(std::move(evName)) {}

// ---------------------------------- END CONSTRUCTORS -----------------------------------------------------------

}  // namespace BHVR
