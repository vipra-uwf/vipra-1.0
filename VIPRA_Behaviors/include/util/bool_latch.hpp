#ifndef VIPRA_BEHAVIORS_BOOL_LATCH_HPP
#define VIPRA_BEHAVIORS_BOOL_LATCH_HPP

#include <definitions/type_definitions.hpp>

namespace BHVR {
/**
   * @brief Literally a boolean with extra syntax
   * 
   */
class Latch {
 public:
  inline void latch() { set = true; }

  inline void unlatch() { set = false; }

  [[nodiscard]] inline explicit operator bool() const { return set; }

 private:
  bool set = false;

 public:
  Latch() = default;
  ~Latch() = default;
  Latch(const Latch&) = default;
  Latch& operator=(const Latch&) = default;
  Latch(Latch&&) noexcept = default;
  Latch& operator=(Latch&&) noexcept = default;
};
}  // namespace BHVR

#endif