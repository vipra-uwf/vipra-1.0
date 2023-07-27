#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include <iostream>
#include <numeric>
#include <string>
#include <utility>

#include <spdlog/spdlog.h>

#include <definitions/state.hpp>
#include <definitions/type_definitions.hpp>
#include <pedestrian_loader/pedestrian_loader.hpp>
#include <pedestrian_set/pedestrian_set.hpp>
#include "obstacle_set/obstacle_set.hpp"

/**
 * @class CalmPedestrianSet
 * @brief A class representing a set of calm pedestrians.
 *
 * This class inherits from the PedestrianSet base class and provides implementation
 * for updating the pedestrian state, configuring the set, and initializing it with
 * pedestrian coordinates.
 */
class CalmPedestrianSet : public PedestrianSet {
 public:
  /**
   * @brief Updates the state of the pedestrian set with the given state object.
   *
   * @param state The state object containing updated coordinates and velocities.
   */
  void updateState(VIPRA::State&) override;
  /**
   * @brief Configures the CalmPedestrianSet with the given configuration map.
   *
   * @param configMap The configuration map.
   */
  void configure(const VIPRA::CONFIG::Map&) override;
  /**
   * @brief Initializes the CalmPedestrianSet with the given pedestrian coordinates.
   *
   * @param pedCoords The vector of pedestrian coordinates.
   */
  void initialize(const std::vector<VIPRA::pcoord>&) override;

  /**
   * @brief Gets the number of pedestrians in the set.
   *
   * @return The number of pedestrians.
   */
  [[nodiscard]] VIPRA::size getNumPedestrians() const noexcept override;

  /**
   * @brief Gets the coordinates of all pedestrians in the set.
   *
   * @return A constant reference to the vector of pedestrian coordinates.
   */
  [[nodiscard]] const VIPRA::f3dVec& getCoordinates() const noexcept override;
  /**
   * @brief Gets the velocities of all pedestrians in the set.
   *
   * @return A constant reference to the vector of pedestrian velocities.
   */
  [[nodiscard]] const VIPRA::f3dVec& getVelocities() const noexcept override;
  /**
   * @brief Gets the coordinates of the pedestrian at the specified index.
   *
   * @param index The index of the pedestrian.
   * @return The coordinates of the pedestrian.
   */
  [[nodiscard]] const VIPRA::f3d& getPedCoords(VIPRA::idx) const override;
  /**
   * @brief Gets the velocity of the pedestrian at the specified index.
   *
   * @param index The index of the pedestrian.
   * @return The velocity of the pedestrian.
   */
  [[nodiscard]] const VIPRA::f3d& getPedVelocity(VIPRA::idx) const override;

  /**
   * @brief Get the nearest pedestrian to the specified pedestrian.
   *
   * @param pedIdx The index of the pedestrian for which to find the nearest pedestrian.
   * @return A pair containing the coordinates and index of the nearest pedestrian.
   */
  [[nodiscard]] std::pair<VIPRA::f3d, VIPRA::idx> getNearestPedestrian(
      VIPRA::idx, const ObstacleSet&) const override;

 private:
  VIPRA::f3dVec coords;
  VIPRA::f3dVec velocities;
};
#endif