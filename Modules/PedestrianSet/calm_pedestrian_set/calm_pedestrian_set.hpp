#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include <iostream>
#include <numeric>
#include <string>
#include <utility>

#include "PedestrianLoader/calm_pedestrian_loader/calm_pedestrian_loader.hpp"
#include "definitions/state.hpp"
#include "pedestrian_loader/pedestrian_loader.hpp"
#include "pedestrian_set/pedestrian_set.hpp"
#include <spdlog/spdlog.h>


class CalmPedestrianSet : public PedestrianSet {
 public:
  CalmPedestrianSet();

  void updateState(std::shared_ptr<VIPRA::State>) override;

  void configure(const VIPRA::Config::Map&) override;
  void initialize(std::unique_ptr<VIPRA::PedData>) override;

  [[nodiscard]] VIPRA::size getNumPedestrians() const noexcept override;

  [[nodiscard]] const VIPRA::f3dVec& getPedestrianCoordinates() const noexcept override;
  [[nodiscard]] const VIPRA::f3dVec& getVelocities() const noexcept override;
  [[nodiscard]] VIPRA::f3d           getPedCoords(VIPRA::idx) const override;
  [[nodiscard]] VIPRA::f3d           getPedVelocity(VIPRA::idx) const override;

  [[nodiscard]] const std::vector<float>& getMasses() const noexcept;
  [[nodiscard]] const std::vector<float>& getReactionTimes() const noexcept;
  [[nodiscard]] const std::vector<float>& getDesiredSpeeds() const noexcept;
  [[nodiscard]] const std::vector<float>& getShoulderLengths() const noexcept;

 private:
  VIPRA::size numPedestrians;

  VIPRA::f3dVec pedestrianCoordinates;
  VIPRA::f3dVec velocities;

  std::vector<float> masses;
  std::vector<float> reactionTimes;
  std::vector<float> desiredSpeeds;
  std::vector<float> shoulderLengths;
};
#endif