

#include <definitions/directions.hpp>

namespace BHVR {
Direction directionFromContext(BehaviorParser::DirectionContext* ctx) {

  Direction direction{};

  if (ctx->dir()->direction_of()) {
    direction.type = DirType::TOWARDS;
  }
  if (ctx->dir()->infront()) {
    direction.type = DirType::IN_FRONT;
  }
  if (ctx->dir()->behind()) {
    direction.type = DirType::BEHIND;
  }
  if (ctx->dir()->around()) {
    direction.type = DirType::AROUND;
  }

  direction.dist = std::stof(ctx->NUMBER()->toString());

  return direction;
}
}  // namespace BHVR