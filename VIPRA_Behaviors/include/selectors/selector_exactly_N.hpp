
#ifndef VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
#define VIPRA_EXACTLY_N_RANDOM_SELECTOR_H

#include <selectors/selector.hpp>

namespace Behaviors {

struct selector_exactly_N {
  size_t                  N;
  std::vector<VIPRA::idx> operator()(Behaviors::seed, const PedestrianSet& pedSet, const ObstacleSet&, const Goals&);
};

extern const SelectorFunc exactly_N_selector;

}  // namespace Behaviors

#endif  //VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
