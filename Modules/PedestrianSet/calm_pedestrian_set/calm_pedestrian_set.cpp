#include "calm_pedestrian_set.hpp"
#include "definitions/type_definitions.hpp"

const VIPRA::f3dVec& CalmPedestrianSet::getCoordinates() const noexcept { return coords; }

VIPRA::f3d CalmPedestrianSet::getPedCoords(VIPRA::idx index) const {
  return coords.at(index);
}

VIPRA::f3d CalmPedestrianSet::getPedVelocity(VIPRA::idx index) const {
  return velocities.at(index);
}

VIPRA::size CalmPedestrianSet::getNumPedestrians() const noexcept {
  return coords.size();
}

const VIPRA::f3dVec& CalmPedestrianSet::getVelocities() const noexcept {
  return velocities;
}

void CalmPedestrianSet::updateState(VIPRA::State& state) {
  std::copy(state.velocities.begin(), state.velocities.end(), velocities.begin());
  std::copy(state.coords.begin(), state.coords.end(), coords.begin());
}

// ----------------------------- INITIALIZATION -----------------------------------------------

void CalmPedestrianSet::configure(const VIPRA::CONFIG::Map&) {}

void CalmPedestrianSet::initialize(const std::vector<VIPRA::pcoord>& pedCoords) {
  coords = pedCoords;
  velocities = VIPRA::f3dVec{coords.size(), VIPRA::f3d{}};
}