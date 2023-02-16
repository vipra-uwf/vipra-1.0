
#ifndef VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
#define VIPRA_EXACTLY_N_RANDOM_SELECTOR_H

#include "selector.hpp"

namespace Behaviors {
class Selector_Exactly_N : public Selector {
 public:
  Selector_Exactly_N() = delete;
  Selector_Exactly_N(VIPRA::size count, Behaviors::seed seed);

  void initialize(const PedestrianSet&, const ObstacleSet&, const Goals&) override;

  const std::vector<VIPRA::idx>& getSelectedPeds(const PedestrianSet&,
                                                 const ObstacleSet&,
                                                 const Goals&,
                                                 const BehaviorContext&) override;

 private:
  std::vector<VIPRA::idx> selectedPeds;
  VIPRA::size             count;
  void                    selectPedestrianIds(const PedestrianSet& pedestrianSet);
};
}  // namespace Behaviors

#endif  //VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
