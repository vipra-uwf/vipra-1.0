#ifndef EVERYONE_SELECTOR_HPP
#define EVERYONE_SELECTOR_HPP

#include "definitions/type_definitions.hpp"
#include "selector.hpp"

/**
 * Select every pedestrian for this behavior
 */
class Selector_Everyone : public Selector {
 public:
  Selector_Everyone() = default;
  void                           initialize(const PedestrianSet&, const ObstacleSet&, const Goals&) override;
  const std::vector<VIPRA::idx>& getSelectedPeds(const PedestrianSet&,
                                                 const ObstacleSet&,
                                                 const Goals&,
                                                 const BehaviorContext&) override;

 private:
  std::vector<VIPRA::idx> selectedPeds;
};

#endif