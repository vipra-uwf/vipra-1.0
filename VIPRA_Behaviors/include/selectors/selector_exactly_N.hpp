
#ifndef VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
#define VIPRA_EXACTLY_N_RANDOM_SELECTOR_H

#include <selectors/selector.hpp>

namespace Behaviors {

struct selector_exactly_N {
  size_t         N;
  SelectorResult operator()(Behaviors::seed,
                            const VIPRA::idxVec&,
                            const VIPRA::idxVec&,
                            const PedestrianSet&,
                            const ObstacleSet&,
                            const Goals&);
};

extern const SelectorFunc exactly_N_selector;

}  // namespace Behaviors

#endif  //VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
