#ifndef VIPRA_BEHAVIORS_OBJECT_HPP
#define VIPRA_BEHAVIORS_OBJECT_HPP

#include <grammar/generated/BehaviorParser.h>

namespace Behaviors {
enum class ObjType {
  PED,
  OBSTACLE,
  OBJECT,
};

struct Object {
  ObjType     type;
  std::string name;
};

Object objectFromContext(BehaviorParser::ObjectContext*);

}  // namespace Behaviors

#endif