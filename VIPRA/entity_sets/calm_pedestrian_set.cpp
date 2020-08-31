#include "calm_pedestrian_set.hpp"

CalmPedestrianSet::CalmPedestrianSet()
{
    this->numPedestrians = 0;
}

// CalmPedestrianSet::~CalmPedestrianSet()
// {

// }

void CalmPedestrianSet::removePedestrian(int pedestrianIndex)
{
    this->numPedestrians--;
    
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
    this->repulsionForces.erase(repulsionForces.begin()+pedestrianIndex);
    this->nearestNeighbors.erase(nearestNeighbors.begin()+pedestrianIndex);
}

int CalmPedestrianSet::getNumPedestrians()
{
    return this->numPedestrians;
}

std::vector<Dimensions>* CalmPedestrianSet::getPedestrianCoordinates()
{
    return &this->pedestrianCoordinates;
}

std::vector<Dimensions>* CalmPedestrianSet::getGoalCoordinates()
{
    return &this->goalCoordinates;
}

std::vector<Dimensions>* CalmPedestrianSet::getVelocities()
{
    return &this->velocities;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getSpeeds()
{
    return &this->speedsMetersPerSecond;    
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getMasses()
{
    return &this->massesKg;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getReactionTimes()
{
    return &this->reactionTimes;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getDesiredSpeeds()
{
    return &this->desiredSpeeds;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getPropulsionForces()
{
    return &this->propulsionForces;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getRepulsionForces()
{
    return &this->repulsionForces;
}

std::vector<std::pair<std::string, int>>* CalmPedestrianSet::getNearestNeighbors()
{
    return &this->nearestNeighbors;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getPriortiy()
{
    return &this->priorities;
}

void CalmPedestrianSet::setNumPedestrians(int numPedestrians)
{
   this->numPedestrians = numPedestrians; 
}

void CalmPedestrianSet::setPedestrianCoordinates(std::vector<Dimensions>
    coordinates)
{
    this->pedestrianCoordinates = coordinates;
}

void CalmPedestrianSet::setGoalCoordinates(
		std::vector<Dimensions> goalCoordinates)
{
    this->goalCoordinates = goalCoordinates;
}

void CalmPedestrianSet::setSpeeds(
		std::vector<FLOATING_NUMBER> speedsMetersPerSecond)
{
    this->speedsMetersPerSecond = speedsMetersPerSecond;
}

void CalmPedestrianSet::setVelocities(
		std::vector<Dimensions> velocities)
{
    this->velocities = velocities;
}

void CalmPedestrianSet::setMasses(std::vector<FLOATING_NUMBER> massesKg)
{
    this->massesKg = massesKg;
}

void CalmPedestrianSet::setReactionTimes(
		std::vector<FLOATING_NUMBER> reactionTimes)
{
    this->reactionTimes = reactionTimes;
}

void CalmPedestrianSet::setDesiredSpeeds(
		std::vector<FLOATING_NUMBER> desiredSpeeds)
{
    this->desiredSpeeds = desiredSpeeds;
}

void CalmPedestrianSet::setPropulsionForces(
		std::vector<FLOATING_NUMBER> propulsionForces)
{
    this->propulsionForces = propulsionForces;
}

void CalmPedestrianSet::setRepulsionForces(
		std::vector<FLOATING_NUMBER> repulsionForces)
{
    this->repulsionForces = repulsionForces;
}

void CalmPedestrianSet::setNearestNeighbors(
    std::vector<std::pair<std::string, int>> nearestNeighbors)
{
   this->nearestNeighbors = nearestNeighbors; 
}

void CalmPedestrianSet::setPriorities(std::vector<FLOATING_NUMBER> priorities)
{
    this->priorities = priorities;
}