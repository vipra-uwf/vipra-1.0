//TODO: Fill in with actual details
#include "calm_pedestrian_model.hpp"

void CalmPedestrianModel::setData(Data* initialData)
{
    this->data = initialData;
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

    calculatePropulsion();
    calculateRepulsion();

}

void CalmPedestrianModel::update()
{
    //use clock, calculated force prop and calculated force rep to update positions ~Elizabeth
}

void CalmPedestrianModel::calculatePropulsion()
{

     FLOATING_NUMBER forceOfPropulsion;
     for(int pedestrianIndex = 0; pedestrianIndex < data->getPedestrianSet()->getNumPedestrians(); ++pedestrianIndex)
     {
         data->getPedestrianSet()->setPropulsionForces(pedestrianIndex, ((data->getPedestrianSet()->getDesiredSpeed(pedestrianIndex) - data->getPedestrianSet()->getSpeed(pedestrianIndex)) / data->getPedestrianSet()->getReactionTimeSeconds(pedestrianIndex)) * data->getPedestrianSet()->getMassKg(pedestrianIndex));
     }

}

void CalmPedestrianModel::calculateRepulsion()
{

     for(int pedestrianIndex = 0; pedestrianIndex < data->getPedestrianSet()->getNumPedestrians(); ++pedestrianIndex)
     {
         data->getPedestrianSet()->setRepulsionForces(pedestrianIndex, (((calculateBeta(pedestrianIndex)*data->getPedestrianSet()->getDesiredSpeed(pedestrianIndex)) - data->getPedestrianSet()->getSpeed(pedestrianIndex)) / data->getPedestrianSet()->getReactionTimeSeconds(pedestrianIndex)));
     }

}

FLOATING_NUMBER CalmPedestrianModel::calculateBeta(int pedestrianIndex)
{
    FLOATING_NUMBER a = -2.111;
    FLOATING_NUMBER b = 0.366;
    FLOATING_NUMBER c = 0.966;

    return (c - exp(a * (data->getPedestrianSet()->calculateDistance(pedestrianIndex,calculateNearestNeighbor(pedestrianIndex) - b))));
}

int CalmPedestrianModel::calculateNearestNeighbor(int pedestrianIndex)
{
    return 1;
}

void CalmPedestrianModel::printPedestrianCoordinates()
{
    this->data->printPedestrianCoordinates();
}

void CalmPedestrianModel::printObstacleCoordinates()
{
    this->data->printObstacleCoordinates();
}
