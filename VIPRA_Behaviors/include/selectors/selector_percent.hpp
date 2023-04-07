#ifndef ID_RATIO_SELECTOR_HPP
#define ID_RATIO_SELECTOR_HPP

#include <definitions/type_definitions.hpp>
#include <selectors/selector.hpp>

namespace Behaviors {

struct selector_percent {
  float                   percentage;
  std::vector<VIPRA::idx> operator()(Behaviors::seed, const PedestrianSet& pedSet, const ObstacleSet&, const Goals&);
};

}  // namespace Behaviors

#endif