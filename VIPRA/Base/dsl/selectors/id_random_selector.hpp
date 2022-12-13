#ifndef ID_RANDOM_SELECTOR_HPP
#define ID_RANDOM_SELECTOR_HPP

#include <ctime>

#include "definitions/type_definitions.hpp"
#include "selector.hpp"

/**
 * Select the pedestrian based on a specified ratio. Useful for behaviors that
 * are selected by a certain percent of the population. This uses a random
 * algorithm with an optional seed parameter for determinism.
 */
class IdRandomSelector : public Selector {
 public:
  IdRandomSelector(SimulationContext* simulationContext, float ratio);
  IdRandomSelector(SimulationContext* simulationContext, float ratio, unsigned int seed);
  void initialize() override;

 protected:
  bool select(int                  pedestrianIndex,
              const ObstacleSet&   obstacleSet,
              const Goals&         goals,
              const PedestrianSet& pedestrianSet) override;

 private:
  std::vector<int> selectedPedestrianIds;
  float            ratio;
  void             selectPedestrianIds(const PedestrianSet& pedestrianSet);
};

#endif  //ID_RANDOM_SELECTOR_HPP
