#include "calm_pedestrian_set.hpp"

CalmPedestrianSet::CalmPedestrianSet() 
{
    this->numPedestrians = 0;
}

void CalmPedestrianSet::configure(const CONFIG_MAP& configMap)
{
    startMass = std::stof(configMap.at("mass"));
    startReaction_time = std::stof(configMap.at("reaction_time"));
    startDesired_speed = std::stof(configMap.at("desired_speed"));
}

void CalmPedestrianSet::initialize(ENTITY_SET pedestrians)
{
    const auto& peds = pedestrians.at("pedestrians");
    const size_t pedCnt = peds.size();

    this->numPedestrians         = pedCnt;
    this->velocities             = DimVector(pedCnt, Dimensions{STARTING_VELOCITY_X, STARTING_VELOCITY_Y});
    this->speedsMetersPerSecond  = std::vector<FLOATING_NUMBER>(pedCnt, STARTING_SPEED);
    this->massesKg               = std::vector<FLOATING_NUMBER>(pedCnt, startMass);
    this->reactionTimes          = std::vector<FLOATING_NUMBER>(pedCnt, STARTING_REACTION_TIME);
    this->desiredSpeeds          = std::vector<FLOATING_NUMBER>(pedCnt, startDesired_speed);
    this->shoulderLengths        = std::vector<FLOATING_NUMBER>(pedCnt, STARTING_SHOULDER_WIDTH);
    this->reactionTimes          = std::vector<FLOATING_NUMBER>(pedCnt, startReaction_time);

    setPedestrianCoordinates(peds);
    this->setIds(std::vector<int>(pedCnt, 0));
    std::iota(this->ids.begin(), this->ids.end(), 0);
}

void CalmPedestrianSet::removePedestrian(size_t pedestrianIndex)
{
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

int CalmPedestrianSet::getNumPedestrians() const noexcept
{
    return this->pedestrianCoordinates.size();
}

const std::vector<int>& CalmPedestrianSet::getIds() const noexcept
{
    return this->ids;
}

const std::vector<Dimensions>& CalmPedestrianSet::getPedestrianCoordinates() const noexcept
{
    return this->pedestrianCoordinates;
}

const std::vector<Dimensions>& CalmPedestrianSet::getVelocities() const noexcept
{
    return this->velocities;
}

const std::vector<FLOATING_NUMBER>& CalmPedestrianSet::getSpeeds() const noexcept
{
    return this->speedsMetersPerSecond;
}

const std::vector<FLOATING_NUMBER>& CalmPedestrianSet::getMasses() const noexcept
{
    return this->massesKg;
}

const std::vector<FLOATING_NUMBER>& CalmPedestrianSet::getReactionTimes() const noexcept
{
    return this->reactionTimes;
}

const std::vector<FLOATING_NUMBER>& CalmPedestrianSet::getDesiredSpeeds() const noexcept
{
    return this->desiredSpeeds;
}

const std::vector<FLOATING_NUMBER>& CalmPedestrianSet::getShoulderLengths() const noexcept
{
  return this->shoulderLengths;
}

void CalmPedestrianSet::setNumPedestrians(int numPedestrians)
{
   this->numPedestrians = numPedestrians;
}

void CalmPedestrianSet::setIds(std::vector<int> ids)
{
    this->ids = ids;
}

void CalmPedestrianSet::setPedestrianCoordinates(const std::vector<Dimensions>&
    coordinates) noexcept
{
    this->pedestrianCoordinates = coordinates;
}

void CalmPedestrianSet::setSpeeds(
		const std::vector<FLOATING_NUMBER>& speedsMetersPerSecond) noexcept
{
    this->speedsMetersPerSecond = speedsMetersPerSecond;
}

void CalmPedestrianSet::setVelocities(
		const std::vector<Dimensions>& velocities) noexcept
{
    this->velocities = velocities;
}

void CalmPedestrianSet::setMasses(
    std::vector<FLOATING_NUMBER>& massesKg)
{
    this->massesKg = massesKg;
}

void CalmPedestrianSet::setReactionTimes(
		std::vector<FLOATING_NUMBER>& reactionTimes)
{
    this->reactionTimes = reactionTimes;
}

void CalmPedestrianSet::setDesiredSpeeds(
		std::vector<FLOATING_NUMBER>& desiredSpeeds)
{
    this->desiredSpeeds = desiredSpeeds;
}

void CalmPedestrianSet::setShoulderLengths(
    std::vector<FLOATING_NUMBER>& shoulderLengths)
{
  this->shoulderLengths = shoulderLengths;
}

void CalmPedestrianSet::setPedestrianCoordinates(const Dimensions& coords, size_t index){
    this->pedestrianCoordinates.at(index) = coords;
}

void CalmPedestrianSet::setVelocity(const Dimensions& velocity, size_t index) {
    this->velocities.at(index) = velocity;
}

void CalmPedestrianSet::setSpeed(FLOATING_NUMBER speed, size_t index) {
    this->speedsMetersPerSecond.at(index) = speed;
}

void CalmPedestrianSet::setPedestrianCoordinates(std::vector<Dimensions>&& coordinates) noexcept {
    this->pedestrianCoordinates = std::move(coordinates);
}

void CalmPedestrianSet::setVelocities(std::vector<Dimensions>&& velocities) noexcept {
    this->velocities = std::move(velocities);
}

void CalmPedestrianSet::setSpeeds(std::vector<FLOATING_NUMBER>&& speedsMetersPerSecond) noexcept {
    this->speedsMetersPerSecond = std::move(speedsMetersPerSecond);
}

void CalmPedestrianSet::setVelocity(Dimensions&& velocity, size_t index) {
    this->velocities.at(index) = std::move(velocity);
}

void CalmPedestrianSet::setPedestrianCoordinates(Dimensions&& coords, size_t index) {
    this->pedestrianCoordinates.at(index) = std::move(coords);
}