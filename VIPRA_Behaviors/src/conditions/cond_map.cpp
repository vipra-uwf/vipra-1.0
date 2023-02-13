
#include <conditions/condition_map.hpp>

#include <conditions/subconditions/subcondition_state.hpp>
#include <conditions/subconditions/subcondition_elapsed_time.hpp>

const std::unordered_map<std::string, std::any> CondMap = {
    {"state", CondFunc<VIPRA::stateUID, bool>([](VIPRA::stateUID state, bool pedOrEnv) -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_State>(state, pedOrEnv);})},
    {"elapsed_time", CondFunc<VIPRA::delta_t>([](VIPRA::delta_t time) -> std::unique_ptr<SubCondition> {return std::make_unique<SubCondition_Elapsed_Time>(time);})}
};