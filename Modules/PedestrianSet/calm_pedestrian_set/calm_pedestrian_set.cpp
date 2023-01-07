#include "calm_pedestrian_set.hpp"

CalmPedestrianSet::CalmPedestrianSet() {
  numPedestrians = 0;
}

void
CalmPedestrianSet::configure(const VIPRA::ConfigMap& configMap) {
  startMass = std::stof(configMap.at("mass"));
  startReaction_time = std::stof(configMap.at("reaction_time"));
  startDesired_speed = std::stof(configMap.at("desired_speed"));
}

void
CalmPedestrianSet::initialize(VIPRA::EntitySet pedestrians) {
  const auto&       peds = pedestrians.at("pedestrians");
  const VIPRA::size pedCnt = peds.size();

  numPedestrians = pedCnt;
  velocities = VIPRA::f3dVec(pedCnt, VIPRA::f3d{STARTING_VELOCITY_X, STARTING_VELOCITY_Y});
  speedsMetersPerSecond = std::vector<float>(pedCnt, STARTING_SPEED);
  massesKg = std::vector<float>(pedCnt, startMass);
  reactionTimes = std::vector<float>(pedCnt, startReaction_time);
  desiredSpeeds = std::vector<float>(pedCnt, startDesired_speed);
  shoulderLengths = std::vector<float>(pedCnt, STARTING_SHOULDER_WIDTH);
  reactionTimes = std::vector<float>(pedCnt, startReaction_time);

  setPedestrianCoordinates(peds);
  setIds(std::vector<VIPRA::uid>(pedCnt, 0));
  std::iota(ids.begin(), ids.end(), 0);
}

void
CalmPedestrianSet::removePedestrian(VIPRA::idx pedestrianIndex) {
  LJ::Debug(simLogger, "Removing Pedestrian: {}", ids.at(pedestrianIndex));
  numPedestrians--;
  velocities.erase(velocities.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  speedsMetersPerSecond.erase(speedsMetersPerSecond.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  massesKg.erase(massesKg.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  reactionTimes.erase(reactionTimes.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  desiredSpeeds.erase(desiredSpeeds.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  shoulderLengths.erase(shoulderLengths.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  goalCoordinates.erase(goalCoordinates.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  ids.erase(ids.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
}

VIPRA::size
CalmPedestrianSet::getNumPedestrians() const noexcept {
  return pedestrianCoordinates.size();
}

const std::vector<VIPRA::uid>&
CalmPedestrianSet::getIds() const noexcept {
  return ids;
}

const std::vector<VIPRA::f3d>&
CalmPedestrianSet::getPedestrianCoordinates() const noexcept {
  return pedestrianCoordinates;
}

const std::vector<VIPRA::f3d>&
CalmPedestrianSet::getVelocities() const noexcept {
  return velocities;
}

const std::vector<float>&
CalmPedestrianSet::getSpeeds() const noexcept {
  return speedsMetersPerSecond;
}

const std::vector<float>&
CalmPedestrianSet::getMasses() const noexcept {
  return massesKg;
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
CalmPedestrianSet::setNumPedestrians(VIPRA::size numPeds) {
  numPedestrians = numPeds;
}

void
CalmPedestrianSet::setIds(std::vector<VIPRA::uid> IDs) {
  ids = IDs;
}

void
CalmPedestrianSet::setPedestrianCoordinates(const std::vector<VIPRA::f3d>& coords) noexcept {
  pedestrianCoordinates = coords;
}

void
CalmPedestrianSet::setSpeeds(const std::vector<float>& speedsMetersPerSec) noexcept {
  speedsMetersPerSecond = speedsMetersPerSec;
}

void
CalmPedestrianSet::setVelocities(const std::vector<VIPRA::f3d>& vels) noexcept {
  velocities = vels;
}

void
CalmPedestrianSet::setMasses(std::vector<float>& masses) {
  massesKg = masses;
}

void
CalmPedestrianSet::setReactionTimes(std::vector<float>& times) {
  reactionTimes = times;
}

void
CalmPedestrianSet::setDesiredSpeeds(std::vector<float>& speeds) {
  desiredSpeeds = speeds;
}

void
CalmPedestrianSet::setShoulderLengths(std::vector<float>& shldrLengths) {
  shoulderLengths = shldrLengths;
}

void
CalmPedestrianSet::setPedestrianCoordinates(const VIPRA::f3d& coords, VIPRA::idx index) {
  pedestrianCoordinates.at(index) = coords;
}

void
CalmPedestrianSet::setVelocity(const VIPRA::f3d& velocity, VIPRA::idx index) {
  velocities.at(index) = velocity;
}

void
CalmPedestrianSet::setSpeed(float speed, VIPRA::idx index) {
  speedsMetersPerSecond.at(index) = speed;
}

void
CalmPedestrianSet::setPedestrianCoordinates(std::vector<VIPRA::f3d>&& coords) noexcept {
  pedestrianCoordinates = std::move(coords);
}

void
CalmPedestrianSet::setVelocities(std::vector<VIPRA::f3d>&& Velocities) noexcept {
  velocities = std::move(Velocities);
}

void
CalmPedestrianSet::setSpeeds(std::vector<float>&& speedsMetersPerSec) noexcept {
  speedsMetersPerSecond = std::move(speedsMetersPerSec);
}

void
CalmPedestrianSet::setVelocity(VIPRA::f3d&& velocity, VIPRA::idx index) {
  velocities.at(index) = std::move(velocity);
}

void
CalmPedestrianSet::setPedestrianCoordinates(VIPRA::f3d&& coords, VIPRA::idx index) {
  pedestrianCoordinates.at(index) = std::move(coords);
}

void
CalmPedestrianSet::updateState(std::shared_ptr<VIPRA::State> state) {
  for (VIPRA::idx i = 0; i < numPedestrians; ++i) {
    velocities[i] = state->velocities[i];
    pedestrianCoordinates[i].x = state->pedestrianCoordinates[i].x;
    pedestrianCoordinates[i].y = state->pedestrianCoordinates[i].y;
    desiredSpeeds[i] = reinterpret_cast<CalmState*>(state.get())->desiredSpeeds[i];
  }
}