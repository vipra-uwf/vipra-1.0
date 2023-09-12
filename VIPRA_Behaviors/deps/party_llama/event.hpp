#ifndef PARTY_LLAMA_EVENT_HPP
#define PARTY_LLAMA_EVENT_HPP

#include <cstdint>
#include <functional>

namespace pllama {
template <typename e_type>
using Handler = std::function<void(const e_type&)>;

template <typename e_type>
using Handler_Vec = std::vector<Handler<e_type>>;

using cb_UID = uint64_t;
using hn_UID = uint64_t;

}  // namespace pllama

#endif