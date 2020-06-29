#include "obstacle_set.hpp"

ObstacleSet::ObstacleSet()
{
    this->numObstacles = 0;
}

int ObstacleSet::getNumObstacles()
{
    return this->numObstacles;
}

int ObstacleSet::getNumDimensions()
{
    return this->numDimensions;
}

std::vector<Dimensions>* ObstacleSet::getObstacleCoordinates()
{
    return &this->obstacleCoordinates;
}

void ObstacleSet::setNumObstacles(int numObstacles)
{
    this->numObstacles = numObstacles;
}
void ObstacleSet::setNumDimensions(int numDimensions)
{
    this->numDimensions = numDimensions;
}

void ObstacleSet::setObstacleCoordinates(std::vector<Dimensions> coordinates)
{
    this->obstacleCoordinates = coordinates;
}

