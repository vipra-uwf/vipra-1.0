#include "data.hpp"

Data::Data()
{

}

void Data::configure(CONFIG_MAP* config){
}

PedestrianSet* Data::getPedestrianSet()
{
    return this->pedestrianSet;
}

ObstacleSet* Data::getObstacleSet()
{
    return this->obstacleSet;
}

void Data::setPedestrianSet(PedestrianSet* pedestrianSet)
{
    this->pedestrianSet = pedestrianSet;
}

void Data::setObstacleSet(ObstacleSet* obstacleSet)
{
	this->obstacleSet = obstacleSet;
}
