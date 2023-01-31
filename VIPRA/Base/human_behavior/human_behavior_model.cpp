//
// Created by joe on 8/3/21.
//

#include "human_behavior_model.hpp"

HumanBehaviorModel::HumanBehaviorModel() {}

HumanBehaviorModel::~HumanBehaviorModel() {}

void
HumanBehaviorModel::configure(const VIPRA::Config::Map& configMap) {
  seed = configMap["seed"].asUInt();
}

void
HumanBehaviorModel::initialize(const ObstacleSet&, const PedestrianSet&, const Goals&) {}

void
HumanBehaviorModel::timestep(const PedestrianSet&,
                             const ObstacleSet&,
                             const Goals&,
                             std::shared_ptr<VIPRA::State>,
                             VIPRA::delta_t) {}
