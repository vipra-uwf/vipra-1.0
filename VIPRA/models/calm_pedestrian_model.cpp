#include "calm_pedestrian_model.hpp"

CalmPedestrianModel::CalmPedestrianModel()
{
    // this->desiredSpeed = 0;
    // this->reactionTime = 0;
}

void CalmPedestrianModel::initializeForces()
{
    this->propulsionForces.resize(this->data->getPedestrianSet()->getNumPedestrians(), 0);
    this->repulsionForces.resize(this->data->getPedestrianSet()->getNumPedestrians(), 0);
    this->nearestNeighbors.resize(this->data->getPedestrianSet()->getNumPedestrians(), 0);
}

void CalmPedestrianModel::setData(Data* initialData)
{
    this->data = initialData;

    //find a better home for this function call - Alex
    initializeForces();
}

Data* CalmPedestrianModel::getData()
{
    return this->data;
}

void CalmPedestrianModel::precompute()
{
    //TODO: Perform precomputation for all passengers
    //Equations 6 and 7 of CALM paper
    //Decrease Force and Propulsion force in CALM code
    //result needs to be stored for each passenger

    calculateNearestNeighbors();
    calculatePropulsion();
    calculateRepulsion();

    // will be removed once we figure out why the rapidxml "segfault" is happening - Alex
    // printDataDELETETHIS();
}

void CalmPedestrianModel::update()
{
    //use clock, calculated force prop and calculated force rep to update positions ~Elizabeth
}

void CalmPedestrianModel::calculatePropulsion()
{
    for(int pedestrianIndex = 0; pedestrianIndex < data->getPedestrianSet()->getNumPedestrians(); ++pedestrianIndex)
    {
        this->propulsionForces.at(pedestrianIndex) = ((this->desiredSpeed - this->data->getPedestrianSet()->getSpeed(pedestrianIndex)) / this->reactionTime) * this->data->getPedestrianSet()->getMassKg(pedestrianIndex);
    }
}

void CalmPedestrianModel::calculateRepulsion()
{
    for(int pedestrianIndex = 0; pedestrianIndex < data->getPedestrianSet()->getNumPedestrians(); ++pedestrianIndex)
    {
        this->repulsionForces.at(pedestrianIndex) = (this->calculateBeta(pedestrianIndex)*desiredSpeed) - (this->data->getPedestrianSet()->getSpeed(pedestrianIndex) / reactionTime);
    }
}

FLOATING_NUMBER CalmPedestrianModel::calculateBeta(int pedestrianIndex)
{
    return (c - exp(a * (calculateDistance(pedestrianIndex, nearestNeighbors.at(pedestrianIndex) - b))));
}

FLOATING_NUMBER CalmPedestrianModel::calculateDistance(int pedestrianIndexOfFirst, int pedestrianIndexOfSecond)
{
    int x = 0;
    int y = 1;

    FLOATING_NUMBER xDistance = pow((data->getPedestrianSet()->getPedestrianCoordinate(x, pedestrianIndexOfFirst) - data->getPedestrianSet()->getPedestrianCoordinate(x, pedestrianIndexOfSecond)), 2);
    FLOATING_NUMBER yDistance = pow((data->getPedestrianSet()->getPedestrianCoordinate(y, pedestrianIndexOfFirst) - data->getPedestrianSet()->getPedestrianCoordinate(y, pedestrianIndexOfSecond)), 2);
    return (sqrt(xDistance + yDistance));
}
void CalmPedestrianModel::calculateNearestNeighbors()
{
    for (int pedestrianIndex =0; pedestrianIndex < this->data->getPedestrianSet()->getNumPedestrians(); ++pedestrianIndex)
    {
        int nearest = 0;
        for (int i = 0; i < this->data->getPedestrianSet()->getNumPedestrians(); ++i)
        {
            if(i != pedestrianIndex)
            {
                if(calculateDistance(pedestrianIndex, i) < calculateDistance(pedestrianIndex, nearest))
                {
                    nearest = i;
                }
            }
        }
        this->nearestNeighbors.at(pedestrianIndex) = nearest;
    }
}


void CalmPedestrianModel::printDataDELETETHIS()
{
    for(int i = 0; i < this->data->getPedestrianSet()->getNumPedestrians(); i++)
    {
        std::cout << "Pedestrian " << i << " | Propulsion Force = " << this->propulsionForces[i];
        std::cout << " | Repulsion Force = " << this->repulsionForces[i];
        std::cout << " | Nearest Neighbor = " << this->nearestNeighbors[i] << std::endl;
    }
}