#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include <iostream>
#include <numeric>
#include <string>
#include <utility>

#include <spdlog/spdlog.h>

#include "definitions/state.hpp"
#include "definitions/type_definitions.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "pedestrian_loader/pedestrian_loader.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

/**
 * @class CalmPedestrianSet
 * @brief A class representing a set of calm pedestrians.
 *
 * This class inherits from the PedestrianSet base class and provides implementation
 * for updating the pedestrian state, configuring the set, and initializing it with
 * pedestrian coordinates.
 */
class CalmPedestrianSet : public VIPRA::PedestrianSet {
 public:
  void updateState(VIPRA::State&) override;
  void configure(const VIPRA::Config&) override;
  void initialize(const std::vector<VIPRA::pcoord>&) override;

  [[nodiscard]] VIPRA::size          getNumPedestrians() const noexcept override;
  [[nodiscard]] const VIPRA::f3dVec& getCoordinates() const noexcept override;
  [[nodiscard]] const VIPRA::f3dVec& getVelocities() const noexcept override;
  [[nodiscard]] const VIPRA::f3d&    getPedCoords(VIPRA::idx) const override;
  [[nodiscard]] const VIPRA::f3d&    getPedVelocity(VIPRA::idx) const override;
  [[nodiscard]] std::pair<VIPRA::f3d, VIPRA::idx> getNearestPedestrian(
      VIPRA::idx, const VIPRA::ObstacleSet&) const override;

 private:
  VIPRA::f3dVec coords;
  VIPRA::f3dVec velocities;
};
#endif