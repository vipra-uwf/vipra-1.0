#include "airplane_obstacle_set.hpp"

AirplaneObstacleSet::AirplaneObstacleSet()
{
    this->numObstacles = 0;
}

void AirplaneObstacleSet::configure(CONFIG_MAP* configMap)
{

}

int AirplaneObstacleSet::getNumObstacles()
{
    return this->numObstacles;
}

int AirplaneObstacleSet::getNumAisles()
{
    return this->numAisles;
}

std::vector<Dimensions>* AirplaneObstacleSet::getObstacleCoordinates()
{
    return &this->obstacleCoordinates;
}

std::vector<FLOATING_NUMBER>* AirplaneObstacleSet::getAisles()
{
    return &this->Aisles;
}

std::vector<FLOATING_NUMBER>* AirplaneObstacleSet::getAislesSize()
{
    return &this->AislesSize;
}

void AirplaneObstacleSet::setNumObstacles(int numObstacles)
{
    this->numObstacles = numObstacles;
}

void AirplaneObstacleSet::setNumAisles(int numAisles)
{
    this->numAisles = numAisles;
}

void AirplaneObstacleSet::setObstacleCoordinates(std::vector<Dimensions> coordinates)
{
    this->obstacleCoordinates = coordinates;
}

void AirplaneObstacleSet::setAisles(std::vector<FLOATING_NUMBER> Aisles)
{
    this->Aisles = Aisles;
}

void AirplaneObstacleSet::setAislesSize(std::vector<FLOATING_NUMBER> AislesSize)
{
    this->AislesSize = AislesSize;
}