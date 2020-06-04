#include "obstacle_set.hpp"

ObstacleSet::ObstacleSet(){
    this->numObstacles = 0;
}

void ObstacleSet::addObstacle(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate){
    this->xCoordinates.push_back(xCoordinate);
    this->yCoordinates.push_back(yCoordinate);
    this->numObstacles++;
}

int ObstacleSet::getNumObstacles(){
    return this->numObstacles;
}

std::vector<FLOATING_NUMBER>* ObstacleSet::getXCoordinates(){
    return &this->xCoordinates;
}

std::vector<FLOATING_NUMBER>* ObstacleSet::getYCoordinates(){
    return &this->yCoordinates;
}




void ObstacleSet::setXCoordinates(std::vector<FLOATING_NUMBER> xCoordinates)
{
    this->xCoordinates = xCoordinates;
}

void ObstacleSet::setYCoordinates(std::vector<FLOATING_NUMBER> yCoordinates)
{
    this->yCoordinates = yCoordinates;
}

