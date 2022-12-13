#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include <iostream>
#include <numeric>
#include <string>
#include <utility>

#include "definitions/state.hpp"
#include "pedestrianset/pedestrian_set.hpp"

class CalmPedestrianSet : public PedestrianSet {
 public:
  CalmPedestrianSet();

  void configure(const VIPRA::ConfigMap& configMap) override;
  void initialize(VIPRA::EntitySet pedestrianCount) override;
  void removePedestrian(size_t pedestrianIndex) override;

  [[nodiscard]] int                     getNumPedestrians() const noexcept override;
  [[nodiscard]] const std::vector<int>& getIds() const noexcept override;

  [[nodiscard]] const VIPRA::f3dVec&      getPedestrianCoordinates() const noexcept override;
  [[nodiscard]] const VIPRA::f3dVec&      getVelocities() const noexcept override;
  [[nodiscard]] const VIPRA::f3dVec&      getGoalCoordinates();
  [[nodiscard]] const std::vector<float>& getSpeeds() const noexcept override;

  void setNumPedestrians(int numPedestrians) override;
  void setIds(std::vector<int> ids) override;

  void setPedestrianCoordinates(const VIPRA::f3d& coords, size_t index) override;
  void setPedestrianCoordinates(VIPRA::f3d&& coords, size_t index) override;
  void setPedestrianCoordinates(const VIPRA::f3dVec& coordinates) noexcept override;
  void setPedestrianCoordinates(VIPRA::f3dVec&& coordinates) noexcept override;

  void setVelocity(const VIPRA::f3d& velocity, size_t index) override;
  void setVelocity(VIPRA::f3d&& velocity, size_t index) override;
  void setVelocities(const VIPRA::f3dVec& velocities) noexcept override;
  void setVelocities(VIPRA::f3dVec&& velocities) noexcept override;

  void setSpeed(float speed, size_t index) override;
  void setSpeeds(const std::vector<float>& speedsMetersPerSecond) noexcept override;
  void setSpeeds(std::vector<float>&& speedsMetersPerSecond) noexcept override;

  [[nodiscard]] const std::vector<float>& getMasses() const noexcept;
  [[nodiscard]] const std::vector<float>& getReactionTimes() const noexcept;
  [[nodiscard]] const std::vector<float>& getDesiredSpeeds() const noexcept;
  [[nodiscard]] const std::vector<float>& getShoulderLengths() const noexcept;

  [[nodiscard]] const std::vector<int>& getStartingAisles() const noexcept;

  void setMasses(std::vector<float>& massesKg);
  void setReactionTimes(std::vector<float>& reactionTimes);
  void setDesiredSpeeds(std::vector<float>& desiredSpeeds);
  void setShoulderLengths(std::vector<float>& shoulderLengths);

  void updateState(std::shared_ptr<VIPRA::State> state);

 private:
  int numPedestrians;

  VIPRA::f3dVec pedestrianCoordinates;
  VIPRA::f3dVec goalCoordinates;
  VIPRA::f3dVec velocities;

  std::vector<float> speedsMetersPerSecond;
  std::vector<float> massesKg;
  std::vector<float> reactionTimes;
  std::vector<float> desiredSpeeds;
  std::vector<float> shoulderLengths;

  std::vector<int> ids;

  float startMass = 0.0f;
  float startReaction_time = 0.0f;
  float startDesired_speed = 0.0f;

  //Constants used for initializing data
  static constexpr float STARTING_VELOCITY_X = 0.0f;
  static constexpr float STARTING_VELOCITY_Y = 0.0f;

  static constexpr float STARTING_SPEED = 0.0f;

  static constexpr float STARTING_MASS = 0.0f;

  static constexpr float STARTING_REACTION_TIME = 0.0f;
  static constexpr float STARTING_DESIRED_SPEED = 0.0f;
  static constexpr float STARTING_PROP_FORCE = 0.0f;
  static constexpr float STARTING_NEAREST_NEIGHBOR = 0.0f;
  static constexpr float STARTING_SHOULDER_WIDTH = 0.0f;
};
#endif