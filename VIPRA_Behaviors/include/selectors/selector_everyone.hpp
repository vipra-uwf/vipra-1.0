#ifndef EVERYONE_SELECTOR_HPP
#define EVERYONE_SELECTOR_HPP

#include <definitions/type_definitions.hpp>
#include <selectors/selector.hpp>

namespace Behaviors {

/**
 * Select every pedestrian for this behavior
 */

struct selector_everyone {
  std::vector<VIPRA::idx> operator()(Behaviors::seed, const PedestrianSet& pedSet, const ObstacleSet&, const Goals&);
};

}  // namespace Behaviors

#endif