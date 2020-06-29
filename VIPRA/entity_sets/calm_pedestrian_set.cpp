#include "calm_pedestrian_set.hpp"

CalmPedestrianSet::CalmPedestrianSet()
{
    this->numPedestrians = 0;
}

void CalmPedestrianSet::initializeValues()
{
    initializeSpeeds();
    initializeGoals();
    initializeVelocities();
    initializePropulsionForces();
    initializeRepulsionForces();
    initializeNearestNeighbors();
}

void CalmPedestrianSet::initializeGoals()
{
    for(int i = 0; i < this->numPedestrians; ++i)
    {
        for(int j = 0; i < this->numDimensions; ++j)
        {
            //TODO .. this reads weird.. renaming should probably happen -- Alex
            this->goalCoordinates.at(i).coordinates.push_back(0);
        }
    }
}

void CalmPedestrianSet::initializeVelocities()
{
    for(int i = 0; i < this->numPedestrians; ++i)
    {
        for(int j = 0; i < this->numDimensions; ++j)
        {
            this->currentVelocities.at(i).coordinates.push_back(0);
        }
    }
}

void CalmPedestrianSet::initializeSpeeds()
{
    this->speedsMetersPerSecond.resize(this->numPedestrians, 0);
}

void CalmPedestrianSet::initializePropulsionForces()
{
    this->propulsionForces.resize(this->numPedestrians, 0);
}

void CalmPedestrianSet::initializeRepulsionForces()
{
    this->repulsionForces.resize(this->numPedestrians, 0);
}

void CalmPedestrianSet::initializeNearestNeighbors()
{
    this->nearestNeighbor.resize(this->numPedestrians, 0);
}

int CalmPedestrianSet::getNumPedestrians()
{
    return this->numPedestrians;
}

int CalmPedestrianSet::getNumDimensions()
{
    return this->numDimensions;
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
    return &this->currentVelocities;
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

std::vector<int>* CalmPedestrianSet::getNearestNeighbor()
{
    return &this->nearestNeighbor;
}

void CalmPedestrianSet::setNumPedestrians(int numPedestrians)
{
   this->numPedestrians = numPedestrians; 
}

void CalmPedestrianSet::setNumDimensions(int numDimensions)
{
    this->numDimensions = numDimensions;
}

void CalmPedestrianSet::setPedestrianCoordinates(std::vector<Dimensions> coordinates)
{
    this->pedestrianCoordinates = coordinates;
}

void CalmPedestrianSet::setGoalCoordinates(std::vector<Dimensions> goalCoordinates)
{
    this->goalCoordinates = goalCoordinates;
}

void CalmPedestrianSet::setSpeeds(std::vector<FLOATING_NUMBER> speedsMetersPerSecond)
{
    this->speedsMetersPerSecond = speedsMetersPerSecond;
}

void CalmPedestrianSet::setVelocities(std::vector<Dimensions> currentVelocities)
{
    this->currentVelocities = currentVelocities;
}

void CalmPedestrianSet::setMasses(std::vector<FLOATING_NUMBER> massesKg)
{
    this->massesKg = massesKg;
}

void CalmPedestrianSet::setReactionTimes(std::vector<FLOATING_NUMBER> reactionTimes)
{
    this->reactionTimes = reactionTimes;
}

void CalmPedestrianSet::setDesiredSpeeds(std::vector<FLOATING_NUMBER> desiredSpeeds)
{
    this->desiredSpeeds = desiredSpeeds;
}

void CalmPedestrianSet::setPropulsionForces(std::vector<FLOATING_NUMBER> propulsionForces)
{
    this->propulsionForces = propulsionForces;
}

void CalmPedestrianSet::setRepulsionForces(std::vector<FLOATING_NUMBER> repulsionForces)
{
    this->repulsionForces = repulsionForces;
}

void CalmPedestrianSet::setNearestNeighbor(std::vector<int> nearestNeighbor)
{
   this->nearestNeighbor = nearestNeighbor; 
}