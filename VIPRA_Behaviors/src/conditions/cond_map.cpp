
#include <conditions/condition_map.hpp>
#include <events/event.hpp>

#include <definitions/attributes.hpp>
#include <definitions/directions.hpp>
#include <definitions/object.hpp>
#include <conditions/subconditions/subcondition_elapsed_time.hpp>
#include <conditions/subconditions/subcondition_event.hpp>
#include <conditions/subconditions/subcondition_event_occurring.hpp>
#include <conditions/subconditions/subcondition_start.hpp>
#include <conditions/subconditions/subcondition_event_one_time.hpp>

namespace Behaviors {
    /**
    * @brief Map that holds the constructor functions for sub conditions
    */
const std::unordered_map<std::string, std::any> CondMap = {
    {"start", CondFunc<>([]() -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_Start>();})},
    {"elapsed_time_from_event", CondFunc<VIPRA::delta_t, Event*>([](VIPRA::delta_t time, Event* event) -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_Elapsed_Time_From_Event>(time, event);})},
    {"event_occurred", CondFunc<Event*>([](Event* event) -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_Event_Occurred>(event);})},
    {"event_occurring", CondFunc<Event*>([](Event* event) -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_Event_Occurring>(event);})},
    {"event_one_time", CondFunc<bool, Event*>([](bool onstart, Event* event) -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_Event_One_Time>(onstart, event);})},
};
}