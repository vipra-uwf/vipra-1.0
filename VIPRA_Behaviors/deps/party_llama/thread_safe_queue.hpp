#ifndef PARTY_LLAMA_THREAD_SAFE_QUEUE_HPP
#define PARTY_LLAMA_THREAD_SAFE_QUEUE_HPP

#include <condition_variable>
#include <list>
#include <mutex>

namespace pllama {
template <typename d_type>
class Queue {
 public:
  /**
   * @brief Adds a new item to the queue, and notifies waiting
   * 
   * @param item : 
   */
  void push(d_type&& item) {
    {
      std::lock_guard lock{_mutex};
      if (_block) return;
      _queue.push_back(std::forward<d_type>(item));
    }

    _cond_var.notify_one();
  }

  /**
   * @brief Gives all waiting threads empty work
   * 
   */
  void shutdown() {
    std::unique_lock lock{_mutex};
    _shutdown = true;
    _block = true;
    _queue.clear();
    _cond_var.notify_all();
  }

  void block_new() {
    std::unique_lock lock{_mutex};
    _block = true;
  }

  void unblock_new() {
    std::unique_lock lock{_mutex};
    _block = false;
  }

  [[nodiscard]] auto is_empty() -> bool {
    std::unique_lock lock{_mutex};
    return _queue.empty();
  }

  /**
   * @brief Waits for an element to be on the queue, removes it
   * 
   * @return std::list<d_type> : list containing the work to be done
   */
  auto pop() -> std::list<d_type> {
    std::unique_lock lock{_mutex};
    _cond_var.wait(lock, [&] { return !_queue.empty() || _shutdown; });
    if (_shutdown) return {};

    std::list<d_type> temp;
    temp.splice(temp.begin(), _queue, _queue.begin());
    return temp;
  }

 private:
  std::list<d_type>       _queue;
  std::mutex              _mutex;
  std::condition_variable _cond_var;
  bool                    _shutdown = false;
  bool                    _block = false;
};
}  // namespace pllama

#endif