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






void Data::printPedestrianCoordinates()
{
    for(int i = 0; i < this->pedestrianSet.getNumPedestrians(); ++i)
    {
        std::cout << "Pedestrian " << i + 1 << " [" 
        << this->pedestrianSet.getXCoordinates()->at(i) << ", "
        << this->pedestrianSet.getYCoordinates()->at(i) << "]" << std::endl;
    }
}

void Data::printObstacleCoordinates()
{
    for(int i = 0; i < this->obstacleSet.getNumObstacles(); ++i)
    {
        std::cout << "Obstacle " << i + 1 << " [" 
        << this->obstacleSet.getXCoordinates()->at(i) << ", "
        << this->obstacleSet.getYCoordinates()->at(i) << "]" << std::endl;
    }
}



