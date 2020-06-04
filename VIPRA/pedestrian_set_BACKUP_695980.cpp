#include "pedestrian_set.hpp"

PedestrianSet::PedestrianSet()
{
    numPedestrians = 0;
<<<<<<< HEAD
=======
    desiredSpeed = 1;
    reactionTime = .25;
    massKg = 70;
>>>>>>> master
}

void PedestrianSet::addPedestrian(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate)
{
    this->xCoordinates.push_back(xCoordinate);
    this->yCoordinates.push_back(yCoordinate);

    goalXCoordinates.push_back(0);
    goalYCoordinates.push_back(0);

<<<<<<< HEAD
    propulsionForces.push_back(0);
    repulsionForces.push_back(0);
=======
    speeds.push_back(0);
    propulsionForces.push_back(0);
    repulsionForces.push_back(0);

    numPedestrians++;
}
>>>>>>> master

    numPedestrians++;
}


void PedestrianSet::setPropulsionForces(int pedestrianIndex, FLOATING_NUMBER propulsionForce)
{
    propulsionForces.at(pedestrianIndex) = propulsionForce;
}

void PedestrianSet::setRepulsionForces(int pedestrianIndex, FLOATING_NUMBER repulsionForce)
{
    repulsionForces.at(pedestrianIndex) = repulsionForce;
}

FLOATING_NUMBER PedestrianSet::calculateDistance(int pedestrianIndexOfFirst, int pedestrianIndexOfSecond)
{
    FLOATING_NUMBER xDistance = pow((xCoordinates.at(pedestrianIndexOfFirst) - xCoordinates.at(pedestrianIndexOfSecond)), 2);
    FLOATING_NUMBER yDistance = pow((yCoordinates.at(pedestrianIndexOfFirst) - yCoordinates.at(pedestrianIndexOfSecond)), 2);
    return (sqrt(xDistance + yDistance));
}

int PedestrianSet::getNumPedestrians()
{
    return this->numPedestrians;
}

FLOATING_NUMBER PedestrianSet::getDesiredSpeed(int pedestrianIndex)
{
    return this->speedsMetersPerSecond.at(pedestrianIndex);
}

<<<<<<< HEAD
FLOATING_NUMBER PedestrianSet::getMassKg(int pedestrianIndex)
=======
int PedestrianSet::getNumPedestrians()
{
    return this->numPedestrians;
}

FLOATING_NUMBER PedestrianSet::getDesiredSpeed()
>>>>>>> master
{
    return this->massesKg.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getReactionTimeSeconds(int pedestrianIndex)
{
    return this->reactionTimesSeconds.at(pedestrianIndex);
}


int PedestrianSet::getNearestNeighbor(int pedestrianIndex)
{
    return this->nearestNeighbors.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getXCoordinate(int pedestrianIndex)
{
    return this->xCoordinates.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getYCoordinate(int pedestrianIndex)
{
<<<<<<< HEAD
    return this->yCoordinates.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getSpeed(int pedestrianIndex)
{
    return this->speedsMetersPerSecond.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getPropulsionForce(int pedestrianIndex)
=======
    return &this->nearestNeighbor;
}

std::vector<FLOATING_NUMBER>* PedestrianSet::getXCoordinates()
{
    return &this->xCoordinates;
}

std::vector<FLOATING_NUMBER>* PedestrianSet::getYCoordinates()
{
    return &this->yCoordinates;
}

std::vector<FLOATING_NUMBER>* PedestrianSet::getSpeeds()
{
   return &this->speeds;
}

std::vector<FLOATING_NUMBER>* PedestrianSet::getPropulsionForces()
>>>>>>> master
{
    return this->propulsionForces.at(pedestrianIndex);
}

FLOATING_NUMBER PedestrianSet::getRepulsionForce(int pedestrianIndex)
{
    return this->repulsionForces.at(pedestrianIndex);
}
