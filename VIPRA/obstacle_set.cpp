#include "obstacle_set.hpp"

ObstacleSet::ObstacleSet(){
    this->numObstacles = 0;
}

void ObstacleSet::addObstacle(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate){
    this->xCoordinates.push_back(xCoordinate);
    this->yCoordinates.push_back(yCoordinate);
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