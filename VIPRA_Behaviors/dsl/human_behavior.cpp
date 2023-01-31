#include "human_behavior.hpp"

void
HumanBehavior::initialize(const ObstacleSet&, const PedestrianSet&, const Goals&) {}

void
HumanBehavior::timestep(const ObstacleSet&   obstacleSet,
                        const PedestrianSet& pedestrianSet,
                        const Goals&         goals,
                        std::shared_ptr<VIPRA::State>,
                        VIPRA::delta_t) {}