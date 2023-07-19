#include "calm_pedestrian_set.hpp"
#include "definitions/type_definitions.hpp"

/**
 * @brief Gets the coordinates of all pedestrians in the set.
 *
 * @return A constant reference to the vector of pedestrian coordinates.
 */
const VIPRA::f3dVec& CalmPedestrianSet::getCoordinates() const noexcept { return coords; }

/**
 * @brief Gets the coordinates of the pedestrian at the specified index.
 *
 * @param index The index of the pedestrian.
 * @return The coordinates of the pedestrian.
 */
VIPRA::f3d CalmPedestrianSet::getPedCoords(VIPRA::idx index) const {
  return coords.at(index);
}

/**
 * @brief Gets the velocity of the pedestrian at the specified index.
 *
 * @param index The index of the pedestrian.
 * @return The velocity of the pedestrian.
 */
VIPRA::f3d CalmPedestrianSet::getPedVelocity(VIPRA::idx index) const {
  return velocities.at(index);
}

/**
 * @brief Gets the number of pedestrians in the set.
 *
 * @return The number of pedestrians.
 */
VIPRA::size CalmPedestrianSet::getNumPedestrians() const noexcept {
  return coords.size();
}

/**
 * @brief Gets the velocities of all pedestrians in the set.
 *
 * @return A constant reference to the vector of pedestrian velocities.
 */
const VIPRA::f3dVec& CalmPedestrianSet::getVelocities() const noexcept {
  return velocities;
}

/**
 * @brief Updates the state of the pedestrian set with the given state object.
 *
 * @param state The state object containing updated coordinates and velocities.
 */
void CalmPedestrianSet::updateState(VIPRA::State& state) {
  std::copy(state.velocities.begin(), state.velocities.end(), velocities.begin());
  std::copy(state.coords.begin(), state.coords.end(), coords.begin());
}

// ----------------------------- INITIALIZATION -----------------------------------------------

/**
 * @brief Configures the CalmPedestrianSet with the given configuration map.
 *
 * @param configMap The configuration map.
 */
void CalmPedestrianSet::configure(const VIPRA::CONFIG::Map&) {}

/**
 * @brief Initializes the CalmPedestrianSet with the given pedestrian coordinates.
 *
 * @param pedCoords The vector of pedestrian coordinates.
 */
void CalmPedestrianSet::initialize(const std::vector<VIPRA::pcoord>& pedCoords) {
  coords = pedCoords;
  velocities = VIPRA::f3dVec{coords.size(), VIPRA::f3d{}};
}