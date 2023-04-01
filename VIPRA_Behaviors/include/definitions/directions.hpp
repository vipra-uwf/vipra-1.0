#ifndef VIPRA_BEHAVIORS_DIRECTIONS_HPP
#define VIPRA_BEHAVIORS_DIRECTIONS_HPP

#include <grammar/generated/BehaviorParser.h>

namespace Behaviors {
enum class DirType {
  IN_FRONT,
  TOWARDS,
  BEHIND,
  AROUND,
};

struct Direction {
  DirType type;
  float   dist;
};

Direction directionFromContext(BehaviorParser::DirectionContext*);
}  // namespace Behaviors

#endif