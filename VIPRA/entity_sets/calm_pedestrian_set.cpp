#include "calm_pedestrian_set.hpp"

CalmPedestrianSet::CalmPedestrianSet()
{
    this->numPedestrians = 0;
}

void CalmPedestrianSet::initializeValues()
{
    initializeSpeeds();
    initializeGoals();
    initializeVelocitys();
    initializePropulsionForces();
    initializeRepulsionForces();
    initializeNearestNeighbors();
}

void CalmPedestrianSet::initializeSpeeds()
{
    this->speedsMetersPerSecond.resize(this->numPedestrians, 0);
}

void CalmPedestrianSet::initializeGoals()
{
    this->goalCoordinates.resize(this->numDimensions);
    for(int i = 0; i < this->numDimensions; ++i)
    {
        this->goalCoordinates.at(i).resize(this->numPedestrians,0);
    }
}

void CalmPedestrianSet::initializeVelocitys()
{
    this->currentVelocitys.resize(this->numDimensions);
    for(int i = 0; i < this->numDimensions; ++i)
    {
        this->currentVelocitys.at(i).resize(this->numPedestrians,0);
    }

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

std::vector<std::vector<FLOATING_NUMBER>>* CalmPedestrianSet::getPedestrianCoordinates()
{
    return &this->pedestrianCoordinates;
}

std::vector<std::vector<FLOATING_NUMBER>>* CalmPedestrianSet::getGoalCoordinates()
{
    return &this->goalCoordinates;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getSpeeds()
{
    return &this->speedsMetersPerSecond;    
}

std::vector<std::vector<FLOATING_NUMBER>>* CalmPedestrianSet::getVelocitys()
{
    return &this->currentVelocitys;
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

void CalmPedestrianSet::setPedestrianCoordinates(std::vector<std::vector<FLOATING_NUMBER>> coordinates)
{
    this->pedestrianCoordinates = coordinates;
}

void CalmPedestrianSet::setGoalCoordinates(std::vector<std::vector<FLOATING_NUMBER>> goalCoordinates)
{
    this->goalCoordinates = goalCoordinates;
}

void CalmPedestrianSet::setSpeeds(std::vector<FLOATING_NUMBER> speedsMetersPerSecond)
{
    this->speedsMetersPerSecond = speedsMetersPerSecond;
}

void CalmPedestrianSet::setVelocitys(std::vector<std::vector<FLOATING_NUMBER>> currentVelocitys)
{
    this->currentVelocitys = currentVelocitys;
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