#include "pedestrian_set.hpp"

PedestrianSet::PedestrianSet(){
    numPedestrians = 0;
}

int PedestrianSet::getNumPedestrians(){
    this->numPedestrians = xCoordinates.size(); //CHANGE .. THIS IS BAD 
    return this->numPedestrians;
}

void PedestrianSet::addPedestrian(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate){
    this->xCoordinates.push_back(xCoordinate);
    this->yCoordinates.push_back(yCoordinate);
    numPedestrians++;
}

std::vector<FLOATING_NUMBER>* PedestrianSet::getXCoordinates(){
    return &this->xCoordinates;
}

std::vector<FLOATING_NUMBER>* PedestrianSet::getYCoordinates(){
    return &this->yCoordinates;
}
