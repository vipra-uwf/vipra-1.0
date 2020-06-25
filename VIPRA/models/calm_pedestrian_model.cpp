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

    calculateNearestNeighbors();
    calculatePropulsion();
    calculateRepulsion();
}

void CalmPedestrianModel::update()
{
    //use clock, calculated force prop and calculated force rep to update positions ~Elizabeth
}

void CalmPedestrianModel::calculatePropulsion()
{
    for(int i = 0; i < data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        // this->propulsionForces.at(pedestrianIndex) = ((this->desiredSpeed - (*this->data->getPedestrianSet()->getSpeeds())[pedestrianIndex]) / this->reactionTime) * (*this->data->getPedestrianSet()->getMasses())[pedestrianIndex];
        (*this->data->getPedestrianSet()->getPropulsionForces())[i] = (((*this->data->getPedestrianSet()->getDesiredSpeeds())[i] - (*this->data->getPedestrianSet()->getSpeeds())[i]) / (*this->data->getPedestrianSet()->getReactionTimes())[i]) * (*this->data->getPedestrianSet()->getMasses())[i];
    }
}

// TODO .. strangely, it calculates the repulsion force for the first pedestrian as a negative value.. i do not think this is intended behavior -- Alex
void CalmPedestrianModel::calculateRepulsion()
{
    for(int i = 0; i < data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        // this->repulsionForces.at(pedestrianIndex) = (this->calculateBeta(pedestrianIndex)*desiredSpeed) - ((*this->data->getPedestrianSet()->getSpeeds())[pedestrianIndex] / reactionTime);
        (*this->data->getPedestrianSet()->getRepulsionForces())[i] = (calculateBeta(i) * (*this->data->getPedestrianSet()->getDesiredSpeeds())[i]) - ((*this->data->getPedestrianSet()->getSpeeds())[i] / (*this->data->getPedestrianSet()->getReactionTimes())[i]);
    }
}

FLOATING_NUMBER CalmPedestrianModel::calculateBeta(int i)
{
    // TODO .. is this equation correct? nearestNeighbors[i] - b is an integer minus a floating number.. are we trying to round by casting it as an integer? -- Alex
    // return (c - exp(a * (calculateDistance(i, nearestNeighbors.at(i) - b))));
    return (c - exp(a * (calculateDistance(i, (*this->data->getPedestrianSet()->getNearestNeighbor())[i] - b))));
}

FLOATING_NUMBER CalmPedestrianModel::calculateDistance(int pedestrianIndexOfFirst, int pedestrianIndexOfSecond)
{
    FLOATING_NUMBER xDistance = pow(((*data->getPedestrianSet()->getCoordinatesX())[pedestrianIndexOfFirst] - (*data->getPedestrianSet()->getCoordinatesX())[pedestrianIndexOfSecond]), 2);
    FLOATING_NUMBER yDistance = pow(((*data->getPedestrianSet()->getCoordinatesY())[pedestrianIndexOfFirst] - (*data->getPedestrianSet()->getCoordinatesY())[pedestrianIndexOfSecond]), 2);
    return (sqrt(xDistance + yDistance));
}

// TODO .. i am pretty sure that this has some unintended behavior. the first pedestrian's nearest neighbor is itself. i do not think this is intentional -- Alex
void CalmPedestrianModel::calculateNearestNeighbors()
{
    for (int i = 0; i < this->data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        int nearest = 0;

        for (int j = 0; j < this->data->getPedestrianSet()->getNumPedestrians(); ++j)
        {
            if(j != i)
            {
                if(calculateDistance(i, j) < calculateDistance(i, nearest))
                {
                    nearest = j;
                }
            }
        }

        // this->nearestNeighbors.at(pedestrianIndex) = nearest;
        (*this->data->getPedestrianSet()->getNearestNeighbor())[i] = nearest;
    }
}
