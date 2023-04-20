#include <numeric>

#include "selectors/selector_everyone.hpp"

namespace Behaviors {

std::vector<VIPRA::idx>
selector_everyone::operator()(Behaviors::seed,
                              const std::vector<VIPRA::idx>& group,
                              const PedestrianSet&,
                              const ObstacleSet&,
                              const Goals&) {
  auto vec = std::vector<VIPRA::idx>(group.size());
  std::iota(vec.begin(), vec.end(), 0);
  return vec;
}

}  // namespace Behaviors
