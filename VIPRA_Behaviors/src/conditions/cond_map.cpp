
#include <conditions/condition_map.hpp>
#include <events/event.hpp>

#include <conditions/subconditions/subcondition_state.hpp>
#include <conditions/subconditions/subcondition_elapsed_time.hpp>
#include <conditions/subconditions/subcondition_event.hpp>
#include <conditions/subconditions/subcondition_event_occurring.hpp>
#include <conditions/subconditions/subcondition_start.hpp>

namespace Behaviors {
const std::unordered_map<std::string, std::any> CondMap = {
    {"start", CondFunc<>([]() -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_Start>();})},
    {"state", CondFunc<stateUID, bool>([](stateUID state, bool pedOrEnv) -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_State>(state, pedOrEnv);})},
    {"elapsed_time_from_event", CondFunc<VIPRA::delta_t, Event*>([](VIPRA::delta_t time, Event* event) -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_Elapsed_Time_From_Event>(time, event);})},
    {"event_occurred", CondFunc<Event*>([](Event* event) -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_Event_Occurred>(event);})},
    {"event_occurring", CondFunc<Event*>([](Event* event) -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_Event_Occurring>(event);})}
};
}