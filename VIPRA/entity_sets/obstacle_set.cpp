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

int ObstacleSet::getNumAisles()
{
    return this->numAisles;
}

std::vector<Dimensions>* ObstacleSet::getObstacleCoordinates()
{
    return &this->obstacleCoordinates;
}

std::vector<FLOATING_NUMBER>* ObstacleSet::getAisles()
{
    return &this->Aisles;
}

std::vector<FLOATING_NUMBER>* ObstacleSet::getAislesSize()
{
    return &this->AislesSize;
}

void ObstacleSet::setNumObstacles(int numObstacles)
{
    this->numObstacles = numObstacles;
}

void ObstacleSet::setNumAisles(int numAisles)
{
    this->numAisles = numAisles;
}

void ObstacleSet::setObstacleCoordinates(std::vector<Dimensions> coordinates)
{
    this->obstacleCoordinates = coordinates;
}

void ObstacleSet::setAisles(std::vector<FLOATING_NUMBER> Aisles)
{
    this->Aisles = Aisles;
}

void ObstacleSet::setAislesSize(std::vector<FLOATING_NUMBER> AislesSize)
{
    this->AislesSize = AislesSize;
}