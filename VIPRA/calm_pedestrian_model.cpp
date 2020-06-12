//TODO: Fill in with actual details
#include "calm_pedestrian_model.hpp"

void CalmPedestrianModel::setData(Data* initialData)
{
    this->data = initialData;

    for(int i = 0; i < data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        propulsionForces.push_back(0);
        repulsionForces.push_back(0);
    }
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
    for(int pedestrianIndex = 0; pedestrianIndex < data->getPedestrianSet()->getNumPedestrians(); ++pedestrianIndex)
    {
        propulsionForces.at(pedestrianIndex) = ((desiredSpeed - data->getPedestrianSet()->getSpeed(pedestrianIndex)) / reactionTime) * data->getPedestrianSet()->getMassKg(pedestrianIndex);
    }
}

void CalmPedestrianModel::calculateRepulsion()
{
    for(int pedestrianIndex = 0; pedestrianIndex < data->getPedestrianSet()->getNumPedestrians(); ++pedestrianIndex)
    {
        repulsionForces.at(pedestrianIndex) = (calculateBeta(pedestrianIndex)*desiredSpeed) - (data->getPedestrianSet()->getSpeed(pedestrianIndex) / reactionTime);
    }
}

FLOATING_NUMBER CalmPedestrianModel::calculateBeta(int pedestrianIndex)
{
    return (c - exp(a * (calculateDistance(pedestrianIndex, nearestNeighbors.at(pedestrianIndex) - b))));
}

FLOATING_NUMBER CalmPedestrianModel::calculateDistance(int pedestrianIndexOfFirst, int pedestrianIndexOfSecond)
{
    FLOATING_NUMBER xDistance = pow((data->getPedestrianSet()->getXCoordinate(pedestrianIndexOfFirst) - data->getPedestrianSet()->getXCoordinate(pedestrianIndexOfSecond)), 2);
    FLOATING_NUMBER yDistance = pow((data->getPedestrianSet()->getYCoordinate(pedestrianIndexOfFirst) - data->getPedestrianSet()->getXCoordinate(pedestrianIndexOfSecond)), 2);
    return (sqrt(xDistance + yDistance));
}
