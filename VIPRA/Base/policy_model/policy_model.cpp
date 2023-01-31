#include "policy_model.hpp"

void
PolicyModel::configure(const VIPRA::Config::Map& configMap) {}

void
PolicyModel::timestep(const PedestrianSet&          pedSet,
                      const ObstacleSet&            obSet,
                      const Goals&                  goals,
                      std::shared_ptr<VIPRA::State> state,
                      VIPRA::delta_t                timestep_size) {}