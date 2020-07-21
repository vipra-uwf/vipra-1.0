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

std::unordered_map<std::string, FLOATING_NUMBER>* Data::getSimulationParams()
{
	return &this->simulationParams; 
}

void Data::setPedestrianSet(PedestrianSet* pedestrianSet)
{
    this->pedestrianSet = pedestrianSet;
}

void Data::setSimulationParams(
    std::unordered_map<std::string, FLOATING_NUMBER> simulationParams)
{
	this->simulationParams = simulationParams;
}
