#include "policy_model.hpp"

void PolicyModel::configure(const VIPRA::CONFIG::Map&) {}

void PolicyModel::timestep(const PedestrianSet&, const ObstacleSet&, const Goals&,
                           VIPRA::State&, VIPRA::delta_t) {}