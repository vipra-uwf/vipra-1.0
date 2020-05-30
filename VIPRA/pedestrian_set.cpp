#include "pedestrian_set.hpp"

PedestrianSet::PedestrianSet()
{
    numPedestrians = 0;
    desiredSpeed = 1;
    reactionTime = .25;
    massKg = 70;
}

void PedestrianSet::addPedestrian(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate)
{
    this->xCoordinates.push_back(xCoordinate);
    this->yCoordinates.push_back(yCoordinate);
    numPedestrians++;
}

void PedestrianSet::setSpeed(int id, FLOATING_NUMBER speed)
{
    speeds.at(id) = speed;
}

void PedestrianSet::setPropulsionForces(int id, FLOATING_NUMBER propulsionForce)
{
    propulsionForces.at(id) = propulsionForce;
}

void PedestrianSet::setRepulsionForces(int id, FLOATING_NUMBER repulsionForce)
{
    repulsionForces.at(id) = repulsionForce;
}

void PedestrianSet::calculateAim(int id)
{
    if(yCoordinates.at(id) > 0)
    {
        aims.at(id) = "DOWN_TO_ISLE";
    }

    else if(yCoordinates.at(id) < 0)
    {
        aims.at(id) = "UP_TO_ISLE";
    }
    else
    {
        aims.at(id) = "IN_ISLE";
    }
}

int PedestrianSet::getNumPedestrians()
{
    return this->numPedestrians;
}

FLOATING_NUMBER PedestrianSet::getDesiredSpeed()
{
    return desiredSpeed;
}

FLOATING_NUMBER PedestrianSet::getMassKg()
{
    return massKg;
}

FLOATING_NUMBER PedestrianSet::getReactionTime()
{
    return reactionTime;
}

std::vector<std::string>* PedestrianSet::getAims()
{
    return &this->aims;
}

std::vector<FLOATING_NUMBER>* PedestrianSet::getNearestNeighborX()
{
    return &this->nearestNeighborX;
}

std::vector<FLOATING_NUMBER>* PedestrianSet::getNearestNeighborY()
{
     return &this->nearestNeighborY;
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
{
    return &this->propulsionForces;
}

std::vector<FLOATING_NUMBER>* PedestrianSet::getRepulsionForces()
{
    return &this->propulsionForces;
}
