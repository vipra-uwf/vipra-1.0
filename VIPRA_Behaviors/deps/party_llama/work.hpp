#ifndef PARTY_LLAMA_WORK_HPP
#define PARTY_LLAMA_WORK_HPP

#include <functional>
#include <memory>
#include "callback.hpp"

namespace pllama {

struct Work {
  virtual void run() = 0;

  Work(const Work&) = default;
  Work(Work&&) = default;
  auto operator=(const Work&) -> Work& = default;
  auto operator=(Work&&) -> Work& = default;
  Work() = default;
  virtual ~Work() = default;
};

template <typename d_type>
struct Task : public Work {
  Task(std::function<void(const d_type&)>& work, std::shared_ptr<d_type>& data) : _work(work), _data(data) {}

  std::function<void(const d_type&)> _work;
  std::shared_ptr<d_type>            _data;

  void run() override { _work(*_data.get()); }
};
}  // namespace pllama

#endif