#include "pedestrian.hpp"

// no longer in use!!!

Pedestrian::Pedestrian()
{
    desiredVelocity = 1.0;
    velocityXDirection = 0;
    velocityYDirection = 0;
    mass = 70;//kg
}

//MUTATORS
void Pedestrian::setNearestNeighbor(double nearestNeighborX, double nearestNeighborY)
{
    nearestNeighbor.push_back(nearestNeighborX);
    nearestNeighbor.push_back(nearestNeighborY);
}

void Pedestrian::setPedestrianGoal(int goal)
{
    this->goal = goal;
}

void Pedestrian::setDesiredVelocity(double desiredVelocity)
{
    this->desiredVelocity = desiredVelocity;
}

void Pedestrian::setVelocityXDirection(double velocityXDirection)
{
    this->velocityXDirection = velocityXDirection;
}

void Pedestrian::setVelocityYDirection(double velocityYDirection)
{
    this->velocityYDirection = velocityYDirection;
}

void Pedestrian::setPedestrianMass(double mass)
{
    this->mass = mass;
}

void Pedestrian::setForceOfPropulsion(double forceOfPropulsion)
{
    this->forceOfPropulsion = forceOfPropulsion;
}

//ACESSORS
std::vector<double> Pedestrian::getNearestNeighbor()
{
    return nearestNeighbor;
}

int Pedestrian::getPedestrianGoal()
{
    return goal;
}

double Pedestrian::getDesiredVelocity()
{
    return desiredVelocity;
}

double Pedestrian::getVelocityXDirection()
{
    return velocityXDirection;
}

double Pedestrian::getVelocityYDirection()
{
    return velocityYDirection;
}

double Pedestrian::getPedestrianMass()
{
    return mass;
}

double Pedestrian::getForceOfPropulsion()
{
    return forceOfPropulsion;
}

