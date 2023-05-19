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
  explicit State(size_t numPeds) : affector(numPeds, PED_MODEL), velocities(numPeds), pedestrianCoordinates(numPeds) {}
  State(f3dVec& _velocities, f3dVec& _pedestrianCoordinates)
      : affector(_velocities.size(), PED_MODEL), velocities{_velocities}, pedestrianCoordinates{_pedestrianCoordinates} {}

  std::vector<Affector> affector;
  f3dVec                velocities;
  f3dVec                pedestrianCoordinates;
};
}  // namespace VIPRA

#endif