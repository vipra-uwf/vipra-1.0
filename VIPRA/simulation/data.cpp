#include "data.hpp"

Data::Data()
{
    obstacleSet = ObstacleSet();
}

PedestrianSet* Data::getPedestrianSet()
{
    return this->pedestrianSet;
}

ObstacleSet* Data::getObstacleSet()
{
    return &this->obstacleSet;
}

std::unordered_map<std::string, FLOATING_NUMBER>* Data::getHashMapData()
{
	return &this->hashMapData; 
}

void Data::setPedestrianSet(PedestrianSet* pedestrianSet)
{
    this->pedestrianSet = pedestrianSet;
}

void Data::setHashMapData(
    std::unordered_map<std::string, FLOATING_NUMBER> hashMapData)
{
	this->hashMapData = hashMapData;
}
