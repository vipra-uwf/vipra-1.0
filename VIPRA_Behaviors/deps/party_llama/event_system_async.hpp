#ifndef PARTY_LLAMA_EVENT_ASYNC_HPP
#define PARTY_LLAMA_EVENT_ASYNC_HPP

#include <atomic>
#include <thread>

#include "callback.hpp"
#include "concepts.hpp"
#include "thread_safe_queue.hpp"
#include "work.hpp"

namespace pllama {
/**
 * @brief Event system for asynchronous event handling
 * 
 * @tparam e_types : Types of events
 */
template <typename... e_types>
class EventSystem_Async {
 public:
  explicit EventSystem_Async(size_t thread_cnt) : _callbacks(), _workQueue(), _threads(thread_cnt) {
    for (size_t i = 0; i < thread_cnt; ++i) {
      _threads.at(i) = std::thread(&EventSystem_Async::work, this);
    }
  }

  void set_threads(size_t thread_cnt) {
    _workQueue.block_new();
    while (!_workQueue.is_empty()) {
    }

    _threads.resize(thread_cnt);
    for (size_t i = 0; i < thread_cnt; ++i) {
      _threads.at(i) = std::thread(&EventSystem_Async::work, this);
    }
  }

  /**
   * @brief Adds an event handler for a given event type
   * 
   * @tparam e_type : event type
   * @param handler : event hanlder
   * @return cb_UID : id of the event handler
   */
  template <typename e_type, typename = std::enable_if_t<inTypeList<e_type, e_types...>()>>
  auto on(Callback<e_type>&& handler) -> cb_UID {
    return _callbacks.add(std::forward<Callback<e_type>>(handler));
  }

  /**
   * @brief Stops threads from getting new work and waits for running threads to finish
   * 
   */
  void shutdown() {
    _run = false;
    _workQueue.shutdown();
    for (auto& thread : _threads) {
      thread.join();
    }
  }

  void wait_shutdown() {
    _workQueue.block_new();
    while (!_workQueue.is_empty()) {
    }
    shutdown();
  }

  /**
   * @brief Removes a handler for an event type
   * 
   * @tparam e_type : event type
   * @param cb_id : event handler id
   */
  template <typename e_type, typename = std::enable_if_t<inTypeList<e_type, e_types...>()>>
  void remove(cb_UID cb_id) {
    _callbacks.template remove<e_type>(cb_id);
  }

  /**
   * @brief Emits a new event for the appropriate handlers to take care of
   * 
   * @tparam e_type : event type
   * @param data : event data
   */
  template <typename e_type, typename = std::enable_if_t<inTypeList<e_type, e_types...>()>>
  void emit(e_type&& data) {
    auto stored = std::make_shared<e_type>(std::forward<e_type>(data));
    for (auto& callback : _callbacks.template get_callbacks<e_type>()) {
      _workQueue.push(std::make_unique<Task<e_type>>(callback.cb, stored));
    }
  }

 private:
  CallbackContainer<e_types...> _callbacks;
  Queue<std::unique_ptr<Work>>  _workQueue;
  std::vector<std::thread>      _threads;

  std::atomic_bool _run = true;

  /**
   * @brief Function for worker threads to run
   * 
   */
  void work() {
    while (_run) {
      auto wrk = _workQueue.pop();
      if (wrk.empty()) {
        return;
      }

      wrk.front()->run();
    }
  }

 public:
  EventSystem_Async() = default;
  EventSystem_Async(const EventSystem_Async&) = default;
  EventSystem_Async(EventSystem_Async&&) noexcept = default;
  auto operator=(const EventSystem_Async&) -> EventSystem_Async& = default;
  auto operator=(EventSystem_Async&&) noexcept -> EventSystem_Async& = default;
  ~EventSystem_Async() = default;
};
}  // namespace pllama

#endif