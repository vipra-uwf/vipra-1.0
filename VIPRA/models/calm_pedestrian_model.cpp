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
    PedestrianSet* set = this->data->getPedestrianSet();

    for(int i = 0; i < set->getNumPedestrians(); ++i)
    {
        (*set->getPropulsionForces())[i] = 
            (
                (
                    (*set->getDesiredSpeeds())[i]
                    - (*set->getSpeeds())[i]
                ) 
                / (*set->getReactionTimes())[i]
            )
            * (*set->getMasses())[i];
    }
}

void CalmPedestrianModel::calculateRepulsion()
{
    PedestrianSet* set = this->data->getPedestrianSet();

    for(int i = 0; i < set->getNumPedestrians(); ++i)
    {
        (*set->getRepulsionForces())[i] = 
            (
                calculateBeta(i) 
                * (*set->getDesiredSpeeds())[i]
            ) 
            - 
            (
                (*set->getSpeeds())[i] 
                / (*set->getReactionTimes())[i]
            );
    }
}

FLOATING_NUMBER CalmPedestrianModel::calculateBeta(int i)
{
    int nearestNeighhborIndex = (*this->data->getPedestrianSet()->getNearestNeighbor())[i];

    FLOATING_NUMBER distance = calculateDistance(
        i, 
        FLOATING_NUMBER(nearestNeighhborIndex) - b
    );
    return (c - exp(a * distance));
}

FLOATING_NUMBER CalmPedestrianModel::calculateDistance(int pedestrianIndexOfFirst, int pedestrianIndexOfSecond)
{
<<<<<<< HEAD
    FLOATING_NUMBER xDistance = pow((data->getPedestrianSet()->getPedestrianCoordinates()->at(0).coordinates.at(pedestrianIndexOfFirst) - data->getPedestrianSet()->getPedestrianCoordinates()->at(0).coordinates.at(pedestrianIndexOfSecond)), 2);
    FLOATING_NUMBER yDistance = pow((data->getPedestrianSet()->getPedestrianCoordinates()->at(1).coordinates.at(pedestrianIndexOfFirst) - data->getPedestrianSet()->getPedestrianCoordinates()->at(1).coordinates.at(pedestrianIndexOfSecond)), 2);
=======
    PedestrianSet* set = this->data->getPedestrianSet();
    std::vector<Dimensions>* coords = set->getPedestrianCoordinates();

    FLOATING_NUMBER xDistance = pow(
        (
            coords->at(pedestrianIndexOfFirst).coordinates.at(0)
            - coords->at(pedestrianIndexOfSecond).coordinates.at(0)
        ), 
        2
    );
    FLOATING_NUMBER yDistance = pow(
        (
            coords->at(pedestrianIndexOfFirst).coordinates.at(1)
            - coords->at(pedestrianIndexOfSecond).coordinates.at(1)
        ), 
        2
    );
>>>>>>> master
    return (sqrt(xDistance + yDistance));
}

void CalmPedestrianModel::calculateNearestNeighbors()
{
    PedestrianSet* set = this->data->getPedestrianSet();

    for (int i = 0; i < set->getNumPedestrians(); ++i)
    {
        int nearest = -1;

        for (int j = 0; j < set->getNumPedestrians(); ++j)
        {
            if(i != j)
            {
                if (nearest == -1 || calculateDistance(i, j) < calculateDistance(i, nearest))
                {
                    nearest = j;
                }
            }
        }
        
        (*set->getNearestNeighbor())[i] = nearest;
    }
}