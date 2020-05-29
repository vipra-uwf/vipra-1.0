#include "pedestrian_set.hpp"

PedestrianSet::PedestrianSet(){
    numPedestrians = 0;
}

int PedestrianSet::getNumPedestrians(){
    return this->numPedestrians;
}

void PedestrianSet::addPedestrian(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate){
    this->xCoordinates.push_back(xCoordinate);
    this->yCoordinates.push_back(yCoordinate);
    numPedestrians++;
}

std::vector<double>* PedestrianSet::getXCoordinates(){
    return &this->xCoordinates;
}

std::vector<double>* PedestrianSet::getYCoordinates(){
    return &this->yCoordinates;
}
