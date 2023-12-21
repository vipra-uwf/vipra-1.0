

#include <spdlog/spdlog.h>

#include "perf_testing.hpp"

namespace BHVR::TEST {
void manual_behaviors(VIPRA::PedestrianSet& pedset, VIPRA::ObstacleSet&, VIPRA::Goals& goals,
                      VIPRA::State& state, VIPRA::delta_t) {
  BHVR::TEST::disembark_behavior(pedset, goals, state);
}

}  // namespace BHVR::TEST