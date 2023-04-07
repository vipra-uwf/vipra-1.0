#include <numeric>

#include "selectors/selector_everyone.hpp"

namespace Behaviors {

std::vector<VIPRA::idx>
selector_everyone::operator()(Behaviors::seed, const PedestrianSet& pedSet, const ObstacleSet&, const Goals&) {
  auto vec = std::vector<VIPRA::idx>(pedSet.getNumPedestrians());
  std::iota(vec.begin(), vec.end(), 0);
  return vec;
}

}  // namespace Behaviors
