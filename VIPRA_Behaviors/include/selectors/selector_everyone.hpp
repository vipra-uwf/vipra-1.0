#ifndef EVERYONE_SELECTOR_HPP
#define EVERYONE_SELECTOR_HPP

#include <definitions/type_definitions.hpp>
#include <selectors/selector.hpp>

namespace Behaviors {

/**
 * Select every pedestrian for this behavior
 */

struct selector_everyone {
  SelectorResult operator()(Behaviors::seed,
                            const VIPRA::idxVec&,
                            const VIPRA::idxVec&,
                            const PedestrianSet&,
                            const ObstacleSet&,
                            const Goals&);
};

}  // namespace Behaviors

#endif