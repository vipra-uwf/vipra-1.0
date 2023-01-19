#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include <iostream>
#include <numeric>
#include <string>
#include <utility>

#include "PedestrianLoader/calm_pedestrian_loader/calm_pedestrian_loader.hpp"
#include "definitions/state.hpp"
#include "logging/logging.hpp"
#include "pedestrianloader/pedestrian_loader.hpp"
#include "pedestrianset/pedestrian_set.hpp"

class CalmPedestrianSet : public PedestrianSet {
 public:
  CalmPedestrianSet();

  void updateState(std::shared_ptr<VIPRA::State>) override;

  void configure(const VIPRA::ConfigMap&) override;
  void initialize(std::unique_ptr<VIPRA::PedData>) override;

  [[nodiscard]] VIPRA::size getNumPedestrians() const noexcept override;

  [[nodiscard]] const VIPRA::f3dVec& getPedestrianCoordinates() const noexcept override;
  [[nodiscard]] const VIPRA::f3dVec& getVelocities() const noexcept override;

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