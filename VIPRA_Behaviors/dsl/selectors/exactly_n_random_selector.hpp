//
// Created by joe on 12/10/21.
//

#ifndef VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
#define VIPRA_EXACTLY_N_RANDOM_SELECTOR_H

#include "selector.hpp"

class ExactlyNRandomSelector : public Selector {
 public:
  ExactlyNRandomSelector(VIPRA::size count, unsigned int seed);
  void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&) override;

 protected:
  bool select(const ObstacleSet&, const PedestrianSet&, const Goals&, const BehaviorContext&, VIPRA::idx) override;

 private:
  std::vector<VIPRA::idx> selectedPedestrianIds;
  VIPRA::size             count;
  void                    selectPedestrianIds(const PedestrianSet& pedestrianSet);
};

#endif  //VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
