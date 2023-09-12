#ifndef VIPRA_BEHAVIOR_CONCEPTS_HPP
#define VIPRA_BEHAVIOR_CONCEPTS_HPP

#include <tuple>
#include <type_traits>

namespace BHVR {
template <typename t, typename... t_list>
constexpr auto inTypeList() -> bool {
  constexpr bool INLIST = (std::is_same_v<t, t_list> || ...);
  static_assert(INLIST, "Type Not In List");
  return INLIST;
}

template <std::size_t I = 0, typename FuncT, typename... Tp>
inline auto forEach(std::tuple<Tp...>& /*tuple*/, FuncT /*func*/) ->
    typename std::enable_if<I == sizeof...(Tp), void>::type {}

template <std::size_t I = 0, typename FuncT, typename... Tp>
    inline auto forEach(std::tuple<Tp...>& tup, FuncT func) ->
    typename std::enable_if < I<sizeof...(Tp), void>::type {
  func(std::get<I>(tup));
  forEach<I + 1, FuncT, Tp...>(tup, func);
}
}  // namespace BHVR

#endif