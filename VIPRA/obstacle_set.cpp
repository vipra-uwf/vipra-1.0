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

FLOATING_NUMBER ObstacleSet::getXCoordinate(int i){
    return this->xCoordinates.at(i);
}

FLOATING_NUMBER ObstacleSet::getYCoordinate(int i){
    return this->yCoordinates.at(i);
}