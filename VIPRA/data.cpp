#include "data.hpp"

Data::Data()
{

}

std::vector<double> Data::getXPedestrianCoordinates()
{
    return this->xPedestrianCoordinates;
}

std::vector<double> Data::getYPedestrianCoordinates()
{
    return this->yPedestrianCoordinates;
}

std::vector<double> Data::getXObstacleCoordinates()
{
    return this->xObstacleCoordinates;
}

std::vector<double> Data::getYObstacleCoordinates()
{
    return this->yObstacleCoordinates;
} 

void Data::setXPedestrianCoordinates(std::vector<double> xPedestrianCoordinates)
{
    this->xPedestrianCoordinates = xPedestrianCoordinates;
}

void Data::setYPedestrianCoordinates(std::vector<double> yPedestrianCoordinates)
{
    this->yPedestrianCoordinates = yPedestrianCoordinates;
}

void Data::setXObstacleCoordinates(std::vector<double> xObstacleCoordinates)
{
    this->xObstacleCoordinates = xObstacleCoordinates;
}

void Data::setYObstacleCoordinates(std::vector<double> yObstacleCoordinates)
{
    this->yObstacleCoordinates = yObstacleCoordinates;
}

void Data::pushXPedestrianCoordinate(double xCoordinate)
{
    this->xPedestrianCoordinates.push_back(xCoordinate);
}

void Data::pushYPedestrianCoordinate(double yCoordinate)
{
    this->yPedestrianCoordinates.push_back(yCoordinate);
}

void Data::pushXObstacleCoordinate(double xCoordinate)
{
    this->xObstacleCoordinates.push_back(xCoordinate);
}

void Data::pushYObstacleCoordinate(double yCoordinate)
{
    this->yObstacleCoordinates.push_back(yCoordinate);
}

void Data::printPedestrianCoordinates()
{
    for(int i = 0; i < this->xPedestrianCoordinates.size(); ++i)
    {
        std::cout << "Pedestrian " << i + 1 << " [" << this->xPedestrianCoordinates[i]<< ", " 
        << this->yPedestrianCoordinates[i] << "]" << std::endl;
    }
}

void Data::printObstacleCoordinates()
{
    for(int i = 0; i < this->xObstacleCoordinates.size(); ++i)
    {
        std::cout << "Obstacle " << i + 1 << " [" << this->xObstacleCoordinates[i] << ", "
        << this->yObstacleCoordinates[i] << "]" << std::endl;
    }
}



