#ifndef PARTY_LLAMA_EVENT_SYSTEM_IMMEDIATE_HPP
#define PARTY_LLAMA_EVENT_SYSTEM_IMMEDIATE_HPP

#include <pstl/glue_algorithm_defs.h>
#include <functional>
#include <tuple>
#include <type_traits>
#include <vector>

#include "callback.hpp"
#include "concepts.hpp"

namespace pllama {
/**
 * @brief Event system for handling events synchronously as they occur
 * 
 * @tparam e_types : Types of events
 */
template <typename... e_types>
class EventSystem_Immediate {
 public:
  /**
   * @brief Calls all callbacks for a given event type
   * 
   * @tparam e_type : event data type
   * @param data : event data
   */
  template <typename e_type, typename = std::enable_if<inTypeList<e_type, e_types...>()>>
  void emit(const e_type& data) {
    auto& cbs = _callbacks.template get_callbacks<e_type>();
    for (auto& callback : cbs) {
      callback.cb(data);
    }
  }

  /**
   * @brief Adds a new callback function to an event 
   *
   * @tparam e_type : event type
   * @param callback : callback function
   * @return cb_UID : id of callback
   */
  template <typename e_type, typename = std::enable_if_t<inTypeList<e_type, e_types...>()>>
  auto on(Callback<e_type>&& callback) -> cb_UID {
    return _callbacks.template add(std::forward<Callback<e_type>>(callback));
  }

  /**
   * @brief Removes the callback with the provided id, does nothing if no callback exists
   * 
   * @tparam e_type : event type
   * @param cb_id : callback id
   */
  template <typename e_type, typename = std::enable_if_t<inTypeList<e_type, e_types...>()>>
  void remove(cb_UID cb_id) {
    _callbacks.template remove<e_type>(cb_id);
  }

 private:
  CallbackContainer<e_types...> _callbacks;

 public:
  EventSystem_Immediate() = default;
  ~EventSystem_Immediate() = default;
  EventSystem_Immediate(const EventSystem_Immediate&) = default;
  EventSystem_Immediate(EventSystem_Immediate&&) noexcept = default;
  auto operator=(const EventSystem_Immediate&) -> EventSystem_Immediate& = default;
  auto operator=(EventSystem_Immediate&&) noexcept -> EventSystem_Immediate& = default;
};
}  // namespace pllama

#endif