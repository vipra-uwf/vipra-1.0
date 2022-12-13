#include "calm_pedestrian_set.hpp"

CalmPedestrianSet::CalmPedestrianSet() {
  this->numPedestrians = 0;
}

void
CalmPedestrianSet::configure(const VIPRA::ConfigMap& configMap) {
  startMass = std::stof(configMap.at("mass"));
  startReaction_time = std::stof(configMap.at("reaction_time"));
  startDesired_speed = std::stof(configMap.at("desired_speed"));
}

void
CalmPedestrianSet::initialize(VIPRA::EntitySet pedestrians) {
  const auto&  peds = pedestrians.at("pedestrians");
  const size_t pedCnt = peds.size();

  this->numPedestrians = pedCnt;
  this->velocities = VIPRA::f3dVec(pedCnt, VIPRA::f3d{STARTING_VELOCITY_X, STARTING_VELOCITY_Y});
  this->speedsMetersPerSecond = std::vector<float>(pedCnt, STARTING_SPEED);
  this->massesKg = std::vector<float>(pedCnt, startMass);
  this->reactionTimes = std::vector<float>(pedCnt, STARTING_REACTION_TIME);
  this->desiredSpeeds = std::vector<float>(pedCnt, startDesired_speed);
  this->shoulderLengths = std::vector<float>(pedCnt, STARTING_SHOULDER_WIDTH);
  this->reactionTimes = std::vector<float>(pedCnt, startReaction_time);

  setPedestrianCoordinates(peds);
  this->setIds(std::vector<int>(pedCnt, 0));
  std::iota(this->ids.begin(), this->ids.end(), 0);
}

void
CalmPedestrianSet::removePedestrian(size_t pedestrianIndex) {
  std::cout << "Removing pedestrian: " + this->ids.at(pedestrianIndex) << std::endl;

  this->numPedestrians--;
  this->velocities.erase(this->velocities.begin() + pedestrianIndex);
  this->speedsMetersPerSecond.erase(this->speedsMetersPerSecond.begin() + pedestrianIndex);
  this->massesKg.erase(this->massesKg.begin() + pedestrianIndex);
  this->reactionTimes.erase(this->reactionTimes.begin() + pedestrianIndex);
  this->desiredSpeeds.erase(this->desiredSpeeds.begin() + pedestrianIndex);
  this->shoulderLengths.erase(this->shoulderLengths.begin() + pedestrianIndex);
  this->goalCoordinates.erase(this->goalCoordinates.begin() + pedestrianIndex);
  this->ids.erase(this->ids.begin() + pedestrianIndex);
}

int
CalmPedestrianSet::getNumPedestrians() const noexcept {
  return this->pedestrianCoordinates.size();
}

const std::vector<int>&
CalmPedestrianSet::getIds() const noexcept {
  return this->ids;
}

const std::vector<VIPRA::f3d>&
CalmPedestrianSet::getPedestrianCoordinates() const noexcept {
  return this->pedestrianCoordinates;
}

const std::vector<VIPRA::f3d>&
CalmPedestrianSet::getVelocities() const noexcept {
  return this->velocities;
}

const std::vector<float>&
CalmPedestrianSet::getSpeeds() const noexcept {
  return this->speedsMetersPerSecond;
}

const std::vector<float>&
CalmPedestrianSet::getMasses() const noexcept {
  return this->massesKg;
}

const std::vector<float>&
CalmPedestrianSet::getReactionTimes() const noexcept {
  return this->reactionTimes;
}

const std::vector<float>&
CalmPedestrianSet::getDesiredSpeeds() const noexcept {
  return this->desiredSpeeds;
}

const std::vector<float>&
CalmPedestrianSet::getShoulderLengths() const noexcept {
  return this->shoulderLengths;
}

void
CalmPedestrianSet::setNumPedestrians(int numPedestrians) {
  this->numPedestrians = numPedestrians;
}

void
CalmPedestrianSet::setIds(std::vector<int> ids) {
  this->ids = ids;
}

void
CalmPedestrianSet::setPedestrianCoordinates(const std::vector<VIPRA::f3d>& coordinates) noexcept {
  this->pedestrianCoordinates = coordinates;
}

void
CalmPedestrianSet::setSpeeds(const std::vector<float>& speedsMetersPerSecond) noexcept {
  this->speedsMetersPerSecond = speedsMetersPerSecond;
}

void
CalmPedestrianSet::setVelocities(const std::vector<VIPRA::f3d>& velocities) noexcept {
  this->velocities = velocities;
}

void
CalmPedestrianSet::setMasses(std::vector<float>& massesKg) {
  this->massesKg = massesKg;
}

void
CalmPedestrianSet::setReactionTimes(std::vector<float>& reactionTimes) {
  this->reactionTimes = reactionTimes;
}

void
CalmPedestrianSet::setDesiredSpeeds(std::vector<float>& desiredSpeeds) {
  this->desiredSpeeds = desiredSpeeds;
}

void
CalmPedestrianSet::setShoulderLengths(std::vector<float>& shoulderLengths) {
  this->shoulderLengths = shoulderLengths;
}

void
CalmPedestrianSet::setPedestrianCoordinates(const VIPRA::f3d& coords, size_t index) {
  this->pedestrianCoordinates.at(index) = coords;
}

void
CalmPedestrianSet::setVelocity(const VIPRA::f3d& velocity, size_t index) {
  this->velocities.at(index) = velocity;
}

void
CalmPedestrianSet::setSpeed(float speed, size_t index) {
  this->speedsMetersPerSecond.at(index) = speed;
}

void
CalmPedestrianSet::setPedestrianCoordinates(std::vector<VIPRA::f3d>&& coordinates) noexcept {
  this->pedestrianCoordinates = std::move(coordinates);
}

void
CalmPedestrianSet::setVelocities(std::vector<VIPRA::f3d>&& velocities) noexcept {
  this->velocities = std::move(velocities);
}

void
CalmPedestrianSet::setSpeeds(std::vector<float>&& speedsMetersPerSecond) noexcept {
  this->speedsMetersPerSecond = std::move(speedsMetersPerSecond);
}

void
CalmPedestrianSet::setVelocity(VIPRA::f3d&& velocity, size_t index) {
  this->velocities.at(index) = std::move(velocity);
}

void
CalmPedestrianSet::setPedestrianCoordinates(VIPRA::f3d&& coords, size_t index) {
  this->pedestrianCoordinates.at(index) = std::move(coords);
}

void
CalmPedestrianSet::updateState(std::shared_ptr<VIPRA::State> state) {
  for (int i = 0; i < this->numPedestrians; i++) {
    this->velocities[i] = state->velocities[i];
    this->pedestrianCoordinates[i].x = state->pedestrianCoordinates[i].x;
    this->pedestrianCoordinates[i].y = state->pedestrianCoordinates[i].y;
  }
}