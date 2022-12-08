#ifndef STATE_HPP
#define STATE_HPP

#include "type_definitions.hpp"

enum Affector {
  PED_MODEL,
  POLICY_MODEL,
  BEHAVIOR_MODEL,
};

struct State {
  State(size_t numPeds) : affector(numPeds, PED_MODEL), velocities(numPeds), pedestrianCoordinates(numPeds) {}
  State(DimVector& velocities, DimVector& pedestrianCoordinates)
    : affector(velocities.size(), PED_MODEL), velocities{velocities}, pedestrianCoordinates{
                                                                          pedestrianCoordinates} {}

  std::vector<Affector> affector;
  DimVector             velocities;
  DimVector             pedestrianCoordinates;
};

#endif