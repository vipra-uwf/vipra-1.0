#ifndef ID_RANDOM_SELECTOR_HPP
#define ID_RANDOM_SELECTOR_HPP

#include <ctime>

#include "selector.hpp"

/**
 * Select the pedestrian based on a specified ratio. Useful for behaviors that
 * are selected by a certain percent of the population. This uses a random
 * algorithm with an optional seed parameter for determinism.
 */
class IdRandomSelector : public Selector {
 public:
  IdRandomSelector(float ratio);
  IdRandomSelector(float ratio, unsigned int seed);
  void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&) override;

 protected:
  bool select(const ObstacleSet&, const PedestrianSet&, const Goals&, const BehaviorContext&, VIPRA::idx) override;

 private:
  std::vector<VIPRA::idx> selectedPedestrianIds;
  float                   ratio;
  void                    selectPedestrianIds(const PedestrianSet& pedestrianSet);
};

#endif  //ID_RANDOM_SELECTOR_HPP
