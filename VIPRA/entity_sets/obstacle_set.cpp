#include "obstacle_set.hpp"

ObstacleSet::ObstacleSet()
{
    this->numObstacles = 0;
}

int ObstacleSet::getNumObstacles()
{
    return this->numObstacles;
}

std::vector<FLOATING_NUMBER>* ObstacleSet::getXCoordinates()
{
    return &this->xCoordinates;
}

std::vector<FLOATING_NUMBER>* ObstacleSet::getYCoordinates()
{
    return &this->yCoordinates;
}

void ObstacleSet::setNumObstacles(int numObstacles)
{
    this->numObstacles = numObstacles;
}

void ObstacleSet::setXCoordinates(std::vector<FLOATING_NUMBER> xCoordinates)
{
    this->xCoordinates = xCoordinates;
}

void ObstacleSet::setYCoordinates(std::vector<FLOATING_NUMBER> yCoordinates)
{
    this->yCoordinates = yCoordinates;
}

