#ifndef VIPRA_BHVR_OBJECT_HPP
#define VIPRA_BHVR_OBJECT_HPP

#include <grammar/generated/BehaviorParser.h>

namespace BHVR {
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

}  // namespace BHVR

#endif