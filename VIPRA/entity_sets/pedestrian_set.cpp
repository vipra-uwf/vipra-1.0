#include "pedestrian_set.hpp"

PedestrianSet::PedestrianSet()
{
    numPedestrians = 0;
}

void PedestrianSet::initializeSpeeds()
{
    this->speedsMetersPerSecond.resize(this->numPedestrians, 0);
    // std::fill (speedsMetersPerSecond.begin(),speedsMetersPerSecond.begin()+numPedestrians,0);
}

int PedestrianSet::getNumPedestrians()
{   
    return this->numPedestrians;
}

int PedestrianSet::getNumDimensions()
{
    return this->numDimensions;
}

FLOATING_NUMBER PedestrianSet::getSpeed(int pedestrianIndex)
{
    return this->speedsMetersPerSecond.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getMassKg(int pedestrianIndex)
{
    return this->massesKg.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getGoalCoordinate(int dimension, int pedestrianIndex)
{
    return this->goalCoordinates.at(dimension).at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getPedestrianCoordinate(int dimension, int pedestrianIndex)
{
    return this->pedestrianCoordinates.at(dimension).at(pedestrianIndex);
}


std::vector<std::vector<FLOATING_NUMBER>>* PedestrianSet::getPedestrianCoordinates()
{
    return &pedestrianCoordinates;
}


void PedestrianSet::setNumPedestrians(int numPedestrians)
{
    this->numPedestrians = numPedestrians;
}

void PedestrianSet::setNumDimensions(int numDimensions)
{
    this->numDimensions = numDimensions;
}

void PedestrianSet::setSpeed(int pedestrianIndex, FLOATING_NUMBER speedMetersPerSecond)
{
    this->speedsMetersPerSecond.at(pedestrianIndex) = speedMetersPerSecond;
}

void PedestrianSet::setGoalCoordinate(int dimension, int pedestrianIndex, FLOATING_NUMBER goalCoordinate)
{
    this->goalCoordinates.at(dimension).at(pedestrianIndex) = goalCoordinate;
}

void PedestrianSet::setPedestrianCoordinate(int dimension, int pedestrianIndex, FLOATING_NUMBER coordinate)
{
    this->pedestrianCoordinates.at(dimension).at(pedestrianIndex) = coordinate;
}

void PedestrianSet::setPedestrianCoordinates(std::vector<FLOATING_NUMBER> Coordinates)
{
    this->pedestrianCoordinates.push_back(Coordinates);
}

void PedestrianSet::setMassesKg(std::vector<FLOATING_NUMBER> massesKG)
{
    this->massesKg = massesKG;
}


