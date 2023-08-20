#ifndef VIPRA_OUTPUT_SINK_HPP
#define VIPRA_OUTPUT_SINK_HPP

#include <nlohmann/json.hpp>

#include "configuration/config.hpp"

namespace VIPRA {
class Sink {
 public:
  virtual void configure(const VIPRA::Config&) = 0;
  virtual void write(const nlohmann::json&) = 0;

  virtual ~Sink() = default;
  Sink() = default;
  Sink(const Sink&) = default;
  Sink(Sink&&) noexcept = default;
  Sink& operator=(const Sink&) = default;
  Sink& operator=(Sink&&) noexcept = default;
};
}  // namespace VIPRA

#endif