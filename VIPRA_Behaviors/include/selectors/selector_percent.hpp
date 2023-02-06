#ifndef ID_RATIO_SELECTOR_HPP
#define ID_RATIO_SELECTOR_HPP

#include "definitions/type_definitions.hpp"
#include "selector.hpp"

/**
 * Select the pedestrian based on a specified ratio. Useful for behaviors that 
 * are selected by a certain percent of the population. This uses an algorithm
 * that is deterministic, so every run of the selector is identical.
 */
class Selector_Percent : public Selector {
 public:
  Selector_Percent(float ratio);

  bool select(const ObstacleSet&, const PedestrianSet&, const Goals&, const BehaviorContext&, VIPRA::idx) override;

 private:
  float ratio;
};

#endif