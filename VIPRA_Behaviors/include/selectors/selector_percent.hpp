#ifndef ID_RATIO_SELECTOR_HPP
#define ID_RATIO_SELECTOR_HPP

#include "definitions/type_definitions.hpp"
#include "selector.hpp"

namespace Behaviors {
/**
 * Select the pedestrian based on a specified ratio. Useful for behaviors that 
 * are selected by a certain percent of the population. This uses an algorithm
 * that is deterministic, so every run of the selector is identical.
 */
class Selector_Percent : public Selector {
 public:
  Selector_Percent() = delete;
  Selector_Percent(float);

  void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&) override;

  const std::vector<VIPRA::idx>& getSelectedPeds(const PedestrianSet&,
                                                 const ObstacleSet&,
                                                 const Goals&,
                                                 const BehaviorContext&) override;

 private:
  float                   ratio;
  std::vector<VIPRA::idx> selectedPeds;
  void                    selectPedestrianIds(const PedestrianSet& pedestrianSet);
};
}  // namespace Behaviors

#endif