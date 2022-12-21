//
// Created by joe on 12/10/21.
//

#ifndef VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
#define VIPRA_EXACTLY_N_RANDOM_SELECTOR_H

#include "selector.hpp"

class ExactlyNRandomSelector : public Selector {
 public:
  ExactlyNRandomSelector(SimulationContext* simulationContext, VIPRA::size count, unsigned int seed);
  void initialize(const ObstacleSet&, const PedestrianSet&, const Goals&) override;

 protected:
  bool select(const ObstacleSet&   obstacleSet,
              const PedestrianSet& pedestrianSet,
              const Goals&         goals,
              VIPRA::idx           pedestrianIndex) override;

 private:
  std::vector<VIPRA::uid> selectedPedestrianIds;
  VIPRA::size             count;
  void                    selectPedestrianIds(const PedestrianSet& pedestrianSet);
};

#endif  //VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
