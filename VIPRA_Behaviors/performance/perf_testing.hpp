#ifndef VIPRA_BEHAVIORS_PERF_TESTING_HPP
#define VIPRA_BEHAVIORS_PERF_TESTING_HPP

#include "manual_behaviors/disembark_behavior.hpp"

namespace BHVR::TEST {
void manual_behaviors(VIPRA::PedestrianSet&, VIPRA::ObstacleSet&, VIPRA::Goals&, VIPRA::State&,
                      VIPRA::delta_t);
}

#endif