#ifndef VIPRA_BEHAVIORS_ACTOR_HPP
#define VIPRA_BEHAVIORS_ACTOR_HPP

#include <definitions/type_definitions.hpp>

#include "memory.hpp"

namespace BHVR {
class Actor {
 public:
 private:
  VIPRA::idx _pedidx;
  Memory     _memory;
};
}  // namespace BHVR

#endif