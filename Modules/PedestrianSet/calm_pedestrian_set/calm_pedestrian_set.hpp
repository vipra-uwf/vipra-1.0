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

class CalmPedestrianSet : public PedestrianSet {
 public:
  void updateState(VIPRA::State&) override;
  void configure(const VIPRA::CONFIG::Map&) override;
  void initialize(const std::vector<VIPRA::pcoord>&) override;

  [[nodiscard]] VIPRA::size getNumPedestrians() const noexcept override;

  [[nodiscard]] const VIPRA::f3dVec& getCoordinates() const noexcept override;
  [[nodiscard]] const VIPRA::f3dVec& getVelocities() const noexcept override;
  [[nodiscard]] VIPRA::f3d           getPedCoords(VIPRA::idx) const override;
  [[nodiscard]] VIPRA::f3d           getPedVelocity(VIPRA::idx) const override;

 private:
  VIPRA::f3dVec coords;
  VIPRA::f3dVec velocities;
};
#endif