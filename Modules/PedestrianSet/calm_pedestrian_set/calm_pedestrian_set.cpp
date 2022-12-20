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
  const auto&       peds = pedestrians.at("pedestrians");
  const VIPRA::size pedCnt = peds.size();

  this->numPedestrians = pedCnt;
  this->velocities = VIPRA::f3dVec(pedCnt, VIPRA::f3d{STARTING_VELOCITY_X, STARTING_VELOCITY_Y});
  this->speedsMetersPerSecond = std::vector<float>(pedCnt, STARTING_SPEED);
  this->massesKg = std::vector<float>(pedCnt, startMass);
  this->reactionTimes = std::vector<float>(pedCnt, STARTING_REACTION_TIME);
  this->desiredSpeeds = std::vector<float>(pedCnt, startDesired_speed);
  this->shoulderLengths = std::vector<float>(pedCnt, STARTING_SHOULDER_WIDTH);
  this->reactionTimes = std::vector<float>(pedCnt, startReaction_time);

  setPedestrianCoordinates(peds);
  this->setIds(std::vector<VIPRA::uid>(pedCnt, 0));
  std::iota(this->ids.begin(), this->ids.end(), 0);
}

void
CalmPedestrianSet::removePedestrian(VIPRA::idx pedestrianIndex) {
  LJ::Debug(simLogger, "Removing Pedestrian: {}", this->ids.at(pedestrianIndex));
  this->numPedestrians--;
  this->velocities.erase(this->velocities.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  this->speedsMetersPerSecond.erase(this->speedsMetersPerSecond.begin() +
                                    static_cast<std::ptrdiff_t>(pedestrianIndex));
  this->massesKg.erase(this->massesKg.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  this->reactionTimes.erase(this->reactionTimes.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  this->desiredSpeeds.erase(this->desiredSpeeds.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  this->shoulderLengths.erase(this->shoulderLengths.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  this->goalCoordinates.erase(this->goalCoordinates.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
  this->ids.erase(this->ids.begin() + static_cast<std::ptrdiff_t>(pedestrianIndex));
}

VIPRA::size
CalmPedestrianSet::getNumPedestrians() const noexcept {
  return this->pedestrianCoordinates.size();
}

const std::vector<VIPRA::uid>&
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
CalmPedestrianSet::setNumPedestrians(VIPRA::size numPeds) {
  this->numPedestrians = numPeds;
}

void
CalmPedestrianSet::setIds(std::vector<VIPRA::uid> IDs) {
  this->ids = IDs;
}

void
CalmPedestrianSet::setPedestrianCoordinates(const std::vector<VIPRA::f3d>& coords) noexcept {
  this->pedestrianCoordinates = coords;
}

void
CalmPedestrianSet::setSpeeds(const std::vector<float>& speedsMetersPerSec) noexcept {
  this->speedsMetersPerSecond = speedsMetersPerSec;
}

void
CalmPedestrianSet::setVelocities(const std::vector<VIPRA::f3d>& vels) noexcept {
  this->velocities = vels;
}

void
CalmPedestrianSet::setMasses(std::vector<float>& masses) {
  this->massesKg = masses;
}

void
CalmPedestrianSet::setReactionTimes(std::vector<float>& times) {
  this->reactionTimes = times;
}

void
CalmPedestrianSet::setDesiredSpeeds(std::vector<float>& speeds) {
  this->desiredSpeeds = speeds;
}

void
CalmPedestrianSet::setShoulderLengths(std::vector<float>& shldrLengths) {
  this->shoulderLengths = shldrLengths;
}

void
CalmPedestrianSet::setPedestrianCoordinates(const VIPRA::f3d& coords, VIPRA::idx index) {
  this->pedestrianCoordinates.at(index) = coords;
}

void
CalmPedestrianSet::setVelocity(const VIPRA::f3d& velocity, VIPRA::idx index) {
  this->velocities.at(index) = velocity;
}

void
CalmPedestrianSet::setSpeed(float speed, VIPRA::idx index) {
  this->speedsMetersPerSecond.at(index) = speed;
}

void
CalmPedestrianSet::setPedestrianCoordinates(std::vector<VIPRA::f3d>&& coords) noexcept {
  this->pedestrianCoordinates = std::move(coords);
}

void
CalmPedestrianSet::setVelocities(std::vector<VIPRA::f3d>&& Velocities) noexcept {
  this->velocities = std::move(Velocities);
}

void
CalmPedestrianSet::setSpeeds(std::vector<float>&& speedsMetersPerSec) noexcept {
  this->speedsMetersPerSecond = std::move(speedsMetersPerSec);
}

void
CalmPedestrianSet::setVelocity(VIPRA::f3d&& velocity, VIPRA::idx index) {
  this->velocities.at(index) = std::move(velocity);
}

void
CalmPedestrianSet::setPedestrianCoordinates(VIPRA::f3d&& coords, VIPRA::idx index) {
  this->pedestrianCoordinates.at(index) = std::move(coords);
}

void
CalmPedestrianSet::updateState(std::shared_ptr<VIPRA::State> state) {
  for (VIPRA::idx i = 0; i < this->numPedestrians; ++i) {
    this->velocities[i] = state->velocities[i];
    this->pedestrianCoordinates[i].x = state->pedestrianCoordinates[i].x;
    this->pedestrianCoordinates[i].y = state->pedestrianCoordinates[i].y;
  }
}