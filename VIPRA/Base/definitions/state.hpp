#ifndef STATE_HPP
#define STATE_HPP

#include "definitions/dimensions.hpp"

namespace VIPRA {
enum Affector {
  PED_MODEL,
  POLICY_MODEL,
  BEHAVIOR_MODEL,
};
struct State {
  State(size_t numPeds) : affector(numPeds, PED_MODEL), velocities(numPeds), pedestrianCoordinates(numPeds) {}
  State(f3dVec& velocities, f3dVec& pedestrianCoordinates)
    : affector(velocities.size(), PED_MODEL), velocities{velocities}, pedestrianCoordinates{
                                                                          pedestrianCoordinates} {}

  std::vector<Affector> affector;
  f3dVec                velocities;
  f3dVec                pedestrianCoordinates;
};
}  // namespace VIPRA

#endif