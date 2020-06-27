#include "obstacle_set.hpp"

ObstacleSet::ObstacleSet()
{
    this->numObstacles = 0;
}

int ObstacleSet::getNumObstacles()
{
    return this->numObstacles;
}

void ObstacleSet::initializeObstacles()
{
    this->obstacleCoordinates.resize(numDimensions);
}

std::vector<std::vector<FLOATING_NUMBER>>* ObstacleSet::getObstacleCoordinates()
{
    return &this->obstacleCoordinates;
}


void ObstacleSet::setNumObstacles(int numObstacles)
{
    this->numObstacles = numObstacles;
}

void ObstacleSet::setObstacleCoordinates(std::vector<FLOATING_NUMBER> coordinates)
{
    this->obstacleCoordinates.push_back(coordinates);
}

