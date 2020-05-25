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

void Data::pushCoordinateData(double value, std::string entity, std::string axis)
{
   if(entity.compare("pedestrian") == 0)
   {
       if(axis.compare("x") == 0)
       {
           pushXPedestrianCoordinate(value);
       }
       else if(axis.compare("y") == 0)
       {
           pushYPedestrianCoordinate(value);
       }
   }
   else if(entity.compare("obstacle") == 0)
   {
       if(axis.compare("x") == 0)
       {
           pushXObstacleCoordinate(value);
       }
       else if(axis.compare("y") == 0)
       {
           pushYObstacleCoordinate(value);
       }
   }
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

void Data::createPedestrians()
{
    //gets number of pedestrians
    int numberOfPedestrians = xPedestrianCoordinates.size();

    //fills vector of pedestrian objects
    for(int i = 0; i < numberOfPedestrians; ++i)
    {
        Pedestrian temp;
        pedestrians.push_back(temp);
    }

}



