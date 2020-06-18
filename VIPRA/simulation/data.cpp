#include "data.hpp"

Data::Data()
{
    pedestrianSet = PedestrianSet();
    obstacleSet = ObstacleSet();
}

PedestrianSet* Data::getPedestrianSet()
{
    return &this->pedestrianSet;
}

ObstacleSet* Data::getObstacleSet()
{
    return &this->obstacleSet;
}