#ifndef VIPRA_CONDITION_MAP_HPP
#define VIPRA_CONDITION_MAP_HPP

#include <any>
#include <conditions/sub_condition.hpp>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

namespace Behaviors {
template <typename... Params> using CondFunc = std::function<std::unique_ptr<SubCondition>(Params...)>;

extern const std::unordered_map<std::string, std::any> CondMap;
}  // namespace Behaviors

#endif