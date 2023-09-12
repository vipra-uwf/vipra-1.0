#ifndef PARTY_LLAMA_CALLBACK_HPP
#define PARTY_LLAMA_CALLBACK_HPP

#include <cstdint>
#include <functional>

#include "concepts.hpp"

namespace pllama {
template <typename e_type>
using Callback = std::function<void(const e_type&)>;

using cb_UID = uint64_t;
using hn_UID = uint64_t;

template <typename e_type>
struct CB {
  uint64_t                           id;
  std::function<void(const e_type&)> cb;
};

template <typename e_type>
using Callback_Vec = std::vector<CB<e_type>>;

template <typename... e_types>
class CallbackContainer {
 public:
  /**
   * @brief Adds a new callback function to an event 
   *
   * @tparam e_type : event type
   * @param callback : callback function
   * @return cb_UID : id of callback
   */
  template <typename e_type, typename = std::enable_if<inTypeList<e_type, e_types...>()>>
  auto add(Callback<e_type>&& callback) -> cb_UID {
    auto& callbacks = get_callbacks<e_type>();
    auto  cbid = _current;

    callbacks.push_back({cbid, std::forward<Callback<e_type>>(callback)});
    ++_current;
    return callbacks.size() - 1;
  }

  /**
   * @brief Removes the callback with the provided id, does nothing if no callback exists
   * 
   * @tparam e_type : event type
   * @param cb_id : callback id
   */
  template <typename e_type, typename = std::enable_if<inTypeList<e_type, e_types...>()>>
  void remove(cb_UID cb_id) {
    auto& callbacks = get_callbacks<e_type>();
    callbacks.erase(std::remove_if(callbacks.begin(), callbacks.end(),
                                   [cb_id](CB<e_type>& val) { return val.id == cb_id; }),
                    callbacks.end());
  }

  /**
   * @brief Gets the vector of callbacks for an event type
   * 
   * @tparam e_type : event type
   * @return Callback_Vec<e_type>& : callbacks vector
   */
  template <typename e_type>
  [[nodiscard]] auto get_callbacks() -> Callback_Vec<e_type>& {
    return std::get<Callback_Vec<e_type>>(_callbacks);
  }

 private:
  std::tuple<Callback_Vec<e_types>...> _callbacks;
  cb_UID                               _current = 0;
};

}  // namespace pllama

#endif