#include "obstacle_set.hpp"

ObstacleSet::ObstacleSet()
{
    this->numObstacles = 0;
}

void ObstacleSet::configure(CONFIG_MAP* configMap)
{

}

int ObstacleSet::getNumObstacles()
{
    return this->numObstacles;
}

std::vector<Dimensions>* ObstacleSet::getObstacleCoordinates()
{
    return &this->obstacleCoordinates;
}

void ObstacleSet::setNumObstacles(int numObstacles)
{
    this->numObstacles = numObstacles;
}

void ObstacleSet::setObstacleCoordinates(std::vector<Dimensions> coordinates)
{
    this->obstacleCoordinates = coordinates;
}