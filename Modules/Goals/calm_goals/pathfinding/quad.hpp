#ifndef CALM_GOALS_QUAD_HPP
#define CALM_GOALS_QUAD_HPP

#include <memory>
#include <vector>

#include <definitions/dimensions.hpp>

namespace CalmPath {
struct Quad {
  VIPRA::f3d         center;
  float              size;
  bool               traversable;
  Quad*              topleft;
  Quad*              topright;
  Quad*              botleft;
  Quad*              botright;
  std::vector<Quad*> adj;
  Quad(VIPRA::f3d middle, float sz, bool travable, Quad* tl, Quad* tr, Quad* bl, Quad* br)
    : center(middle), size(sz), traversable(travable), topleft(tl), topright(tr), botleft(bl), botright(br) {}
};
}  // namespace CalmPath

#endif