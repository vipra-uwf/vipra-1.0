#include "pedestrian_set.hpp"

PedestrianSet::PedestrianSet()
{
    numPedestrians = 0;
}

void PedestrianSet::addPedestrian(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate)
{
    this->xCoordinates.push_back(xCoordinate);
    this->yCoordinates.push_back(yCoordinate);

    goalXCoordinates.push_back(0);
    goalYCoordinates.push_back(0);

    numPedestrians++;
}

void PedestrianSet::setGoalXCoordinates(int pedestrianIndex, FLOATING_NUMBER goalXCoordinate)
{
    this->goalXCoordinates.at(pedestrianIndex) = goalXCoordinate;
}

void PedestrianSet::setGoalYCoordinates(int pedestrianIndex, FLOATING_NUMBER goalYCoordinate)
{
    this->goalYCoordinates.at(pedestrianIndex) = goalYCoordinate;
}

void PedestrianSet::setSpeed(int pedestrianIndex, FLOATING_NUMBER speedMetersPerSecond)
{
    this->speedsMetersPerSecond.at(pedestrianIndex) = speedMetersPerSecond;
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

void PedestrianSet::setXCoordinate(int pedestrianIndex, FLOATING_NUMBER xCoordinate)
{
    this->xCoordinates.at(pedestrianIndex) = xCoordinate;
}

void PedestrianSet::setYCoordinate(int pedestrianIndex, FLOATING_NUMBER yCoordinate)
{
    this->yCoordinates.at(pedestrianIndex) = yCoordinate;
}

int PedestrianSet::getNumPedestrians()
{
    return this->numPedestrians;
}

FLOATING_NUMBER PedestrianSet::getDesiredSpeed(int pedestrianIndex)
{
    return this->speedsMetersPerSecond.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getMassKg(int pedestrianIndex)
{
    return this->massesKg.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getReactionTimeSeconds(int pedestrianIndex)
{
    return this->reactionTimesSeconds.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getGoalXCoordinates(int pedestrianIndex)
{
    return this->goalXCoordinates.at(pedestrianIndex);
}
FLOATING_NUMBER PedestrianSet::getGoalYCoordinates(int pedestrianIndex)
{
    return this->goalYCoordinates.at(pedestrianIndex);
}

std::vector<FLOATING_NUMBER> PedestrianSet::getXCoordinates()
{
    return xCoordinates;
}

std::vector<FLOATING_NUMBER> PedestrianSet::getYCoordinates()
{
    return yCoordinates;
}

std::vector<std::string>* PedestrianSet::getTypes()
{
    return &types;
}

FLOATING_NUMBER PedestrianSet::getXCoordinate(int pedestrianIndex)
{
    return this->xCoordinates.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getYCoordinate(int pedestrianIndex)
{
    return this->yCoordinates.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getSpeed(int pedestrianIndex)
{
    return this->speedsMetersPerSecond.at(pedestrianIndex);
}
