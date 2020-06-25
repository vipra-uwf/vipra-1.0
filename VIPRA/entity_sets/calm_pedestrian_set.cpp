#include "calm_pedestrian_set.hpp"

CalmPedestrianSet::CalmPedestrianSet()
{
    this->numPedestrians = 0;
}

int CalmPedestrianSet::getNumPedestrians()
{
    return this->numPedestrians;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getCoordinatesX()
{
    return &this->coordinatesX;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getCoordinatesY()
{
    return &this->coordinatesY;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getGoalCoordinatesX()
{
    return &this->goalCoordinatesX;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getGoalCoordinatesY()
{
    return &this->goalCoordinatesY;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getSpeeds()
{
    return &this->speedsMetersPerSecond;    
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getVelocityX()
{
    return &this->currentVelocityX;
}

std::vector<FLOATING_NUMBER>* CalmPedestrianSet::getVelocityY()
{
    return &this->currentVelocityY;
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

void CalmPedestrianSet::setNumPedestrians(int numPedestrians)
{
   this->numPedestrians = numPedestrians; 
}

void CalmPedestrianSet::setCoordinatesX(std::vector<FLOATING_NUMBER> coordinatesX)
{
    this->coordinatesX = coordinatesX; 
}

void CalmPedestrianSet::setCoordinatesY(std::vector<FLOATING_NUMBER> coordinatesY)
{
    this->coordinatesY = coordinatesY;
}

void CalmPedestrianSet::setGoalCoordinatesX(std::vector<FLOATING_NUMBER> goalCoordinatesX)
{
    this->goalCoordinatesX = goalCoordinatesX;
}

void CalmPedestrianSet::setGoalCoordinatesY(std::vector<FLOATING_NUMBER> goalCoordinatesY)
{
    this->goalCoordinatesY = goalCoordinatesY;
}

void CalmPedestrianSet::setSpeeds(std::vector<FLOATING_NUMBER> speedsMetersPerSecond)
{
    this->speedsMetersPerSecond = speedsMetersPerSecond;
}

void CalmPedestrianSet::setVelocityX(std::vector<FLOATING_NUMBER> currentVelocityX)
{
    this->currentVelocityX = currentVelocityX;
}

void CalmPedestrianSet::setVelocityY(std::vector<FLOATING_NUMBER> currentVelocityY)
{
    this->currentVelocityY = currentVelocityY;
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

// void PedestrianSet::initializeSpeeds()
// {
//     this->speedsMetersPerSecond.resize(this->numPedestrians, 0);
// }
