#ifndef EVERYONE_SELECTOR_HPP
#define EVERYONE_SELECTOR_HPP

#include "definitions/type_definitions.hpp"
#include "selector.hpp"

/**
 * Select every pedestrian for this behavior
 */
class Selector_Everyone : public Selector {
 public:
  explicit Selector_Everyone();
  bool select(const ObstacleSet&, const PedestrianSet&, const Goals&, const BehaviorContext&, VIPRA::idx) override;
};

#endif