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
  std::vector<Affector> affector;
  f3dVec                velocities;
  f3dVec                coords;

  explicit State(size_t numPeds)
      : affector(numPeds, PED_MODEL), velocities(numPeds), coords(numPeds) {}
  State(f3dVec& _velocities, f3dVec& _coords)
      : affector(_velocities.size(), PED_MODEL),
        velocities{_velocities},
        coords{_coords} {}

  State() = default;
  State(const State&) = default;
  State(State&&) noexcept = default;
  State& operator=(const State&) = default;
  State& operator=(State&&) noexcept = default;
  ~State() = default;
};
}  // namespace VIPRA

#endif