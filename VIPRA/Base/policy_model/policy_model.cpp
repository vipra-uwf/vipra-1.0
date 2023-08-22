#include "policy_model.hpp"

namespace VIPRA {
void PolicyModel::configure(const VIPRA::Config&) {}

void PolicyModel::timestep(const VIPRA::PedestrianSet&, const VIPRA::ObstacleSet&,
                           const VIPRA::Goals&, VIPRA::State&, VIPRA::delta_t) {}
}  // namespace VIPRA