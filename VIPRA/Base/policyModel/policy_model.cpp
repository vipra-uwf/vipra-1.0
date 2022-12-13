#include "policy_model.hpp"

void
PolicyModel::configure(const VIPRA::ConfigMap& configMap) {}

void
PolicyModel::timestep(const PedestrianSet&,
                      const ObstacleSet&,
                      const Goals&,
                      float         timestep_size,
                      VIPRA::State& state) {}