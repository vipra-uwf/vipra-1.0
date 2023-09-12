#ifndef PARTY_LLAMA_CONCEPTS_HPP
#define PARTY_LLAMA_CONCEPTS_HPP

#include <type_traits>
#include <typeinfo>

template <typename e, typename... e_list>
constexpr auto inTypeList() -> bool {
  constexpr bool INLIST = (std::is_same_v<e, e_list> || ...);
  static_assert(INLIST, "Event Type: Not A Part of Valid Components");
  return INLIST;
}

#endif