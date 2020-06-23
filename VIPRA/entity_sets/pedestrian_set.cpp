#include "pedestrian_set.hpp"

PedestrianSet::PedestrianSet()
{
    numPedestrians = 0;
}

void PedestrianSet::initializeSpeeds()
{
    this->speedsMetersPerSecond.resize(this->numPedestrians);
    // std::fill (speedsMetersPerSecond.begin(),speedsMetersPerSecond.begin()+numPedestrians,0);
}

int PedestrianSet::getNumPedestrians()
{   
    return this->numPedestrians;
}

FLOATING_NUMBER PedestrianSet::getSpeed(int pedestrianIndex)
{
    return this->speedsMetersPerSecond.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getMassKg(int pedestrianIndex)
{
    return this->massesKg.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getGoalXCoordinate(int pedestrianIndex)
{
    return this->goalXCoordinates.at(pedestrianIndex);
}
FLOATING_NUMBER PedestrianSet::getGoalYCoordinate(int pedestrianIndex)
{
    return this->goalYCoordinates.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getXCoordinate(int pedestrianIndex)
{
    return this->xCoordinates.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getYCoordinate(int pedestrianIndex)
{
    return this->yCoordinates.at(pedestrianIndex);
}

std::vector<FLOATING_NUMBER>* PedestrianSet::getXCoordinates()
{
    return &xCoordinates;
}

std::vector<FLOATING_NUMBER>* PedestrianSet::getYCoordinates()
{
    return &yCoordinates;
}

std::vector<std::string>* PedestrianSet::getTypes()
{
    return &types;
}

void PedestrianSet::setNumPedestrians(int numPedestrians)
{
    this->numPedestrians = numPedestrians;
}

void PedestrianSet::setSpeed(int pedestrianIndex, FLOATING_NUMBER speedMetersPerSecond)
{
    this->speedsMetersPerSecond.at(pedestrianIndex) = speedMetersPerSecond;
}

void PedestrianSet::setGoalXCoordinate(int pedestrianIndex, FLOATING_NUMBER goalXCoordinate)
{
    this->goalXCoordinates.at(pedestrianIndex) = goalXCoordinate;
}

void PedestrianSet::setGoalYCoordinate(int pedestrianIndex, FLOATING_NUMBER goalYCoordinate)
{
    this->goalYCoordinates.at(pedestrianIndex) = goalYCoordinate;
}

void PedestrianSet::setXCoordinate(int pedestrianIndex, FLOATING_NUMBER xCoordinate)
{
    this->xCoordinates.at(pedestrianIndex) = xCoordinate;
}

void PedestrianSet::setYCoordinate(int pedestrianIndex, FLOATING_NUMBER yCoordinate)
{
    this->yCoordinates.at(pedestrianIndex) = yCoordinate;
}

void PedestrianSet::setXCoordinates(std::vector<FLOATING_NUMBER> xCoordinates)
{
    this->xCoordinates = xCoordinates;
}

void PedestrianSet::setYCoordinates(std::vector<FLOATING_NUMBER> yCoordinates)
{
    this->yCoordinates = yCoordinates;
}

void PedestrianSet::setTypes(std::vector<std::string> types)
{
    this->types = types;
}
void PedestrianSet::setMassesKg(std::vector<FLOATING_NUMBER> massesKG)
{
    this->massesKg = massesKG;
}


