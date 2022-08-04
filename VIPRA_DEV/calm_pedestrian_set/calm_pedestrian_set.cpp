#include "calm_pedestrian_set.hpp"
#include <iostream>

CalmPedestrianSet::CalmPedestrianSet()
{
    this->numPedestrians = 0;
}


void CalmPedestrianSet::configure(CONFIG_MAP* configMap)
{
    startMass = std::stof(configMap->at("mass"));
    startReaction_time = std::stof(configMap->at("reaction_time"));
    startDesired_speed = std::stof(configMap->at("desired_speed"));
}

void CalmPedestrianSet::initialize(size_t pedestrianCount)
{
    this->numPedestrians         = pedestrianCount;
    this->goalCoordinates        = std::vector<Dimensions>(pedestrianCount, Dimensions{START_GOAL_X, START_GOAL_Y});
    this->velocities             = std::vector<Dimensions>(pedestrianCount, Dimensions{START_VELOCITY_X, START_VELOCITY_Y});
    this->speedsMetersPerSecond  = std::vector<FLOATING_NUMBER>(pedestrianCount, START_SPEED);
    this->massesKg               = std::vector<FLOATING_NUMBER>(pedestrianCount, startMass);
    this->reactionTimes          = std::vector<FLOATING_NUMBER>(pedestrianCount, startReaction_time);
    this->desiredSpeeds          = std::vector<FLOATING_NUMBER>(pedestrianCount, startDesired_speed);
    this->propulsionForces       = std::vector<Dimensions>(pedestrianCount, Dimensions{START_PROP_FORCE, START_PROP_FORCE});
    this->nearestNeighbors       = std::vector<std::pair<std::string, int>>(pedestrianCount, {"P", START_NEAREST_NEIGHBOR});
    this->movementStates         = std::vector<MovementDefinitions>(pedestrianCount, MovementDefinitions::PED_DYNAM);
    this->startingAisles         = std::vector<int>(pedestrianCount, 0);
    this->shoulderLengths        = std::vector<FLOATING_NUMBER>(pedestrianCount, START_SHOULDER_WIDTH);

    this->setIds(std::vector(pedestrianCount, 0));
    std::iota(this->ids.begin(), this->ids.end(), 0);
}

void CalmPedestrianSet::removePedestrian(size_t pedestrianIndex)
{
    std::cout << "check removed: " << this->ids.at(pedestrianIndex) << std::endl;
    this->numPedestrians--;

    this->ids.erase(ids.begin()+pedestrianIndex);
    this->pedestrianCoordinates.erase(pedestrianCoordinates.
        begin()+pedestrianIndex);
    this->goalCoordinates.erase(goalCoordinates.begin()+pedestrianIndex);
    this->velocities.erase(velocities.begin()+pedestrianIndex);
    this->speedsMetersPerSecond.erase(speedsMetersPerSecond.
        begin()+pedestrianIndex);
    this->massesKg.erase(massesKg.begin()+pedestrianIndex);
    this->reactionTimes.erase(reactionTimes.begin()+pedestrianIndex);
    this->desiredSpeeds.erase(desiredSpeeds.begin()+pedestrianIndex);
    this->propulsionForces.erase(propulsionForces.begin()+pedestrianIndex);
    this->nearestNeighbors.erase(nearestNeighbors.begin()+pedestrianIndex);
    this->movementStates.erase(movementStates.begin()+pedestrianIndex);
    this->priorities.erase(priorities.begin()+pedestrianIndex);
    this->shoulderLengths.erase(shoulderLengths.begin()+pedestrianIndex);
    this->startingAisles.erase(startingAisles.begin()+pedestrianIndex);

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

const std::vector<Dimensions>& CalmPedestrianSet::getPropulsionForces() const noexcept
{
    return this->propulsionForces;
}


const std::vector<std::pair<std::string, int>>&
    CalmPedestrianSet::getNearestNeighbors() const noexcept
{
    return this->nearestNeighbors;
}

const std::vector<FLOATING_NUMBER>& CalmPedestrianSet::getPriorities() const noexcept
{
    return this->priorities;
}

const std::vector<MovementDefinitions>& CalmPedestrianSet::getMovementStates() const noexcept
{
    return this->movementStates;
}

const std::vector<int>& CalmPedestrianSet::getStartingAisles() const noexcept
{
    return this->startingAisles;
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
    std::vector<FLOATING_NUMBER>&& massesKg)
{
    this->massesKg = massesKg;
}

void CalmPedestrianSet::setReactionTimes(
		std::vector<FLOATING_NUMBER>&& reactionTimes)
{
    this->reactionTimes = reactionTimes;
}

void CalmPedestrianSet::setDesiredSpeeds(
		std::vector<FLOATING_NUMBER>&& desiredSpeeds)
{
    this->desiredSpeeds = desiredSpeeds;
}

void CalmPedestrianSet::setPropulsionForces(
		std::vector<Dimensions>&& propulsionForces)
{
    this->propulsionForces = propulsionForces;
}

void CalmPedestrianSet::setNearestNeighbors(
    std::vector<std::pair<std::string, int>>&& nearestNeighbors)
{
   this->nearestNeighbors = nearestNeighbors;
}

void CalmPedestrianSet::setPriorities(
    std::vector<FLOATING_NUMBER>&& priorities)
{
    this->priorities = priorities;
}

void CalmPedestrianSet::setMovementStates(
    std::vector<MovementDefinitions>&& movementStates)
{
    this->movementStates = movementStates;
}

void CalmPedestrianSet::setMovementState(
    MovementDefinitions movementDefinition, size_t pedestrianIndex)
{
    this->movementStates.at(pedestrianIndex) = movementDefinition;
}

void CalmPedestrianSet::setStartingAisles(
    std::vector<int>&& startingAisles)
{
    this->startingAisles = startingAisles;
}

void CalmPedestrianSet::setShoulderLengths(
    std::vector<FLOATING_NUMBER>&& shoulderLengths)
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

void CalmPedestrianSet::setPropulsionForce(Dimensions&& propulsionForce, size_t index) {
    this->propulsionForces.at(index) = std::move(propulsionForce);
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