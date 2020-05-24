#include "pedestrian.hpp"

pedestrian::pedestrian()
{
    desiredVelocity = 1.0;
    velocityXDirection = 0;
    velocityYDirection = 0;
    mass = 70;
}

//MUTATORS
void pedestrian::setNearestNeighbor(double nearestNeighborX, double nearestNeighborY)
{
    nearestNeighbor.push_back(nearestNeighborX);
    nearestNeighbor.push_back(nearestNeighborY);
}

void pedestrian::setPedestrianGoal(int goal)
{
    this->goal = goal;
}

void pedestrian::setDesiredVelocity(double desiredVelocity)
{
    this->desiredVelocity = desiredVelocity;
}

void pedestrian::setVelocityXDirection(double velocityXDirection)
{
    this->velocityXDirection = velocityXDirection;
}

void pedestrian::setVelocityYDirection(double velocityYDirection)
{
    this->velocityYDirection = velocityYDirection;
}

void pedestrian::setPedestrianMass(double mass)
{
    this->mass = mass;
}

void pedestrian::setForceOfPropulsion(double forceOfPropulsion)
{
    this->forceOfPropulsion = forceOfPropulsion;
}

//ACESSORS
std::vector<double> pedestrian::getNearestNeighbor()
{
    return nearestNeighbor;
}

int pedestrian::getPedestrianGoal()
{
    return goal;
}

double pedestrian::getDesiredVelocity()
{
    return desiredVelocity;
}

double pedestrian::getVelocityXDirection()
{
    return velocityXDirection;
}

double pedestrian::getVelocityYDirection()
{
    return velocityYDirection;
}

double pedestrian::getPedestrianMass()
{
    return mass;
}

double pedestrian::getForceOfPropulsion()
{
    return forceOfPropulsion;
}

