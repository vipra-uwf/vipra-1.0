#include "data.hpp"

Data::Data()
{
    pedestrianSet = PedestrianSet();
    obstacleSet = ObstacleSet();
}

PedestrianSet* Data::getPedestrianSet(){
    return &this->pedestrianSet;
}

void Data::pushCoordinates(std::string parseElement, FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate)
{
    //this is not how we do this, will refactor
    if(parseElement.compare("pedestrian") == 0)
    {
        pedestrianSet.addPedestrian(xCoordinate, yCoordinate);
    }
    else if(parseElement.compare("obstacle") == 0)
    {
        obstacleSet.addObstacle(xCoordinate, yCoordinate);
    }
}

void Data::printPedestrianCoordinates()
{
    for(int pedestrianIndex = 0; pedestrianIndex < this->pedestrianSet.getNumPedestrians(); ++pedestrianIndex)
    {
        std::cout << "Pedestrian " << pedestrianIndex + 1 << " ["
        << this->pedestrianSet.getXCoordinate(pedestrianIndex) << ", "
        << this->pedestrianSet.getYCoordinate(pedestrianIndex) << "]" << std::endl;
    }
}

void Data::printObstacleCoordinates()
{
    for(int pedestrianIndex = 0; pedestrianIndex < this->obstacleSet.getNumObstacles(); ++pedestrianIndex)
    {
        std::cout << "Obstacle " << pedestrianIndex + 1 << " ["
        << this->obstacleSet.getXCoordinate(pedestrianIndex) << ", "
        << this->obstacleSet.getYCoordinate(pedestrianIndex) << "]" << std::endl;
    }
}



