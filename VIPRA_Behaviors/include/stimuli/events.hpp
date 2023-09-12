#ifndef VIPRA_BEHAVIORS_STIMULUS_EVENT_HPP
#define VIPRA_BEHAVIORS_STIMULUS_EVENT_HPP

#include <definitions/dimensions.hpp>

#include "definitions/dsl_types.hpp"

namespace BHVR {
struct AuditoryEvent {
  uid        id;
  VIPRA::f3d location;
};

struct VisualEvent {
  uid        id;
  VIPRA::f3d location;
};
}  // namespace BHVR

#endif