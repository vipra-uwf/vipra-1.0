

#include <conditions/subconditions/subcondition_event_one_time.hpp>

namespace Behaviors {
/**
   * @brief Constructor, adds start and end listeners to the provided event
   * 
   * @param event : 
   */
SubCondition_Event_One_Time::SubCondition_Event_One_Time(bool onstart, Event* event) : run(false) {
  if (onstart) {
    event->onStart([this](float time) {
      this->startTime = time;
      this->run = true;
    });
  } else {
    event->onEnd([this](float time) {
      this->startTime = time;
      this->run = true;
    });
  }
}

/**
 * @brief Returns true once when the event has either started or ended
 * 
 * @return true 
 * @return false 
 */
bool
SubCondition_Event_One_Time::operator()(const PedestrianSet&,
                                        const ObstacleSet&,
                                        const Goals&,
                                        const BehaviorContext& context,
                                        VIPRA::idx,
                                        VIPRA::delta_t) {
  if (run) {
    if ((context.elapsedTime - startTime) < 0.0001) {
      return true;
    } else {
      run = false;
    }
  }

  return false;
}
}  // namespace Behaviors