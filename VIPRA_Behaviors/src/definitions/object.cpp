
#include <spdlog/spdlog.h>

#include <behavior/exceptions.hpp>
#include <definitions/object.hpp>

namespace BHVR {
Object objectFromContext(BehaviorParser::ObjectContext* ctx) {
  if (ctx == nullptr) {
    spdlog::error("ObjectFromContext: Context is null");
    exit(1);
  }

  std::string name = ctx->OBJECT()->toString();
  if (name[0] == '+') {
    name = name.substr(1);
  }

  if (name == "Pedestrian") {
    return {ObjType::PED, ""};
  }

  if (name == "Obstacle") {
    return {ObjType::OBSTACLE, ""};
  }

  return {ObjType::OBJECT, name};
}
}  // namespace BHVR