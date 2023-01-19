#include "calm_pedestrian_set.hpp"

CalmPedestrianSet::CalmPedestrianSet() {
  numPedestrians = 0;
}

void
CalmPedestrianSet::configure(const VIPRA::ConfigMap& configMap) {}

void
CalmPedestrianSet::initialize(std::unique_ptr<VIPRA::PedData> pedData) {
  const auto peds = reinterpret_cast<CalmPedData*>(pedData.release());
  numPedestrians = peds->positions.size();

  pedestrianCoordinates = std::move(peds->positions);
  masses = std::move(peds->masses);
  reactionTimes = std::move(peds->reactionTimes);
  desiredSpeeds = std::move(peds->desiredSpeeds);
  shoulderLengths = std::move(peds->shoulderLengths);

  velocities = VIPRA::f3dVec{numPedestrians, VIPRA::f3d{0, 0, 0}};
}

VIPRA::size
CalmPedestrianSet::getNumPedestrians() const noexcept {
  return pedestrianCoordinates.size();
}

const VIPRA::f3dVec&
CalmPedestrianSet::getPedestrianCoordinates() const noexcept {
  return pedestrianCoordinates;
}

const VIPRA::f3dVec&
CalmPedestrianSet::getVelocities() const noexcept {
  return velocities;
}

const std::vector<float>&
CalmPedestrianSet::getMasses() const noexcept {
  return masses;
}

const std::vector<float>&
CalmPedestrianSet::getReactionTimes() const noexcept {
  return reactionTimes;
}

const std::vector<float>&
CalmPedestrianSet::getDesiredSpeeds() const noexcept {
  return desiredSpeeds;
}

const std::vector<float>&
CalmPedestrianSet::getShoulderLengths() const noexcept {
  return shoulderLengths;
}

void
CalmPedestrianSet::updateState(std::shared_ptr<VIPRA::State> state) {
  for (VIPRA::idx i = 0; i < numPedestrians; ++i) {
    velocities[i] = state->velocities[i];
    pedestrianCoordinates[i] = state->pedestrianCoordinates[i];
  }
}