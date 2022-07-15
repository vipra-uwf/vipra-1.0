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
    this->goalCoordinates        = std::vector<Dimensions>(pedestrianCount, Dimensions{{START_GOAL_X, START_GOAL_Y}});
    this->velocities             = std::vector<Dimensions>(pedestrianCount, Dimensions{{START_VELOCITY_X, START_VELOCITY_Y}});
    this->speedsMetersPerSecond  = std::vector<FLOATING_NUMBER>(pedestrianCount, START_SPEED);
    this->massesKg               = std::vector<FLOATING_NUMBER>(pedestrianCount, startMass);
    this->reactionTimes          = std::vector<FLOATING_NUMBER>(pedestrianCount, startReaction_time);
    this->desiredSpeeds          = std::vector<FLOATING_NUMBER>(pedestrianCount, startDesired_speed);
    this->propulsionForces       = std::vector<Dimensions>(pedestrianCount, Dimensions{{START_PROP_FORCE, 0}});
    this->nearestNeighbors       = std::vector<std::pair<std::string, int>>(pedestrianCount, {"P", START_NEAREST_NEIGHBOR});
    this->movementStates         = std::vector<MovementDefinitions>(pedestrianCount, MovementDefinitions::PED_DYNAM);
    this->startingAisles         = std::vector<int>(pedestrianCount, 0);
    this->shoulderLengths        = std::vector<FLOATING_NUMBER>(pedestrianCount, START_SHOULDER_WIDTH);

    this->setIds(std::vector(pedestrianCount, 0));
    std::iota(this->getIds()->begin(), this->getIds()->end(), 0);
}

void CalmPedestrianSet::removePedestrian(int pedestrianIndex)
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

int CalmPedestrianSet::getNumPedestrians()
{
    return this->numPedestrians;
}

std::vector<int>* CalmPedestrianSet::getIds()
{
    return &this->ids;
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

std::vector<Dimensions>* CalmPedestrianSet::getPropulsionForces()
{
    return &this->propulsionForces;
}


std::vector<std::pair<std::string, int>>*
    CalmPedestrianSet::getNearestNeighbors()
{
    return &this->nearestNeighbors;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getPriorities()
{
    return &this->priorities;
}

std::vector<MovementDefinitions>* CalmPedestrianSet::getMovementStates()
{
    return &this->movementStates;
}

std::vector<int>* CalmPedestrianSet::getStartingAisles()
{
    return &this->startingAisles;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getShoulderLengths()
{
  return &this->shoulderLengths;
}

void CalmPedestrianSet::setNumPedestrians(int numPedestrians)
{
   this->numPedestrians = numPedestrians;
}

void CalmPedestrianSet::setIds(std::vector<int> ids)
{
    this->ids = ids;
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
		std::vector<Dimensions> propulsionForces)
{
    this->propulsionForces = propulsionForces;
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

void CalmPedestrianSet::setMovementStates(
    std::vector<MovementDefinitions> movementStates)
{
    this->movementStates = movementStates;
}

void CalmPedestrianSet::setStartingAisles(std::vector<int> startingAisles)
{
    this->startingAisles = startingAisles;
}

void CalmPedestrianSet::setShoulderLengths(std::vector<FLOATING_NUMBER> shoulderLengths)
{
  this->shoulderLengths = shoulderLengths;
}
