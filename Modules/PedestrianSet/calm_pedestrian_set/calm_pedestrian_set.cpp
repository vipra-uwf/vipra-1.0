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
VIPRA::f3d CalmPedestrianSet::getPedCoords(VIPRA::idx index) const { return coords.at(index); }

/**
 * @brief Gets the velocity of the pedestrian at the specified index.
 *
 * @param index The index of the pedestrian.
 * @return The velocity of the pedestrian.
 */
VIPRA::f3d CalmPedestrianSet::getPedVelocity(VIPRA::idx index) const { return velocities.at(index); }

/**
 * @brief Gets the number of pedestrians in the set.
 *
 * @return The number of pedestrians.
 */
VIPRA::size CalmPedestrianSet::getNumPedestrians() const noexcept { return coords.size(); }

/**
 * @brief Gets the velocities of all pedestrians in the set.
 *
 * @return A constant reference to the vector of pedestrian velocities.
 */
const VIPRA::f3dVec& CalmPedestrianSet::getVelocities() const noexcept { return velocities; }

/**
 * @brief Updates the state of the pedestrian set with the given state object.
 *
 * @param state The state object containing updated coordinates and velocities.
 */
void CalmPedestrianSet::updateState(VIPRA::State& state) {
  std::copy(state.velocities.begin(), state.velocities.end(), velocities.begin());
  std::copy(state.coords.begin(), state.coords.end(), coords.begin());
}

/**
 * @brief Get the nearest pedestrian to the specified pedestrian.
 *
 * @param pedIdx The index of the pedestrian for which to find the nearest pedestrian.
 * @return A pair containing the coordinates and index of the nearest pedestrian.
 */
std::pair<VIPRA::f3d, VIPRA::idx> CalmPedestrianSet::getNearestPedestrian(VIPRA::idx pedIdx) const {
  const VIPRA::f3d currCoords = coords.at(pedIdx);

  VIPRA::dist shortest = std::numeric_limits<VIPRA::dist>::max();
  VIPRA::idx  nearest = VIPRA::idx_INVALID;
  for (VIPRA::idx i = 0; i < coords.size(); ++i) {
    if (pedIdx == i) continue;

    VIPRA::dist curr = currCoords.distanceTo(coords.at(i));
    if (curr < shortest) {
      shortest = curr;
      nearest = pedIdx;
    }
  }

  return {coords.at(nearest), nearest};
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