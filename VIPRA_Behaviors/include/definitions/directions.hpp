#ifndef VIPRA_BHVR_DIRECTIONS_HPP
#define VIPRA_BHVR_DIRECTIONS_HPP

#include <grammar/generated/BehaviorParser.h>

namespace BHVR {
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
}  // namespace BHVR

#endif