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

// TODO .. strangely, it calculates the repulsion force for the first pedestrian as a negative value.. i do not think this is intended behavior -- Alex
//output no longer shows this, was it fixed? - V
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
            - (
                (*set->getSpeeds())[i] 
                / (*set->getReactionTimes())[i]
            );
    }
}

FLOATING_NUMBER CalmPedestrianModel::calculateBeta(int i)
{
    // TODO .. is this equation correct? nearestNeighbors[i] - b is an integer minus a floating number.. are we trying to round by casting it as an integer? -- Alex
    // return from getNearestNeighbor() is now cast to FLOATING_NUMBER before subtraction - V
    FLOATING_NUMBER distance = calculateDistance(
        i, 
        FLOATING_NUMBER(
            (*this->data->getPedestrianSet()->getNearestNeighbor())[i]
        ) 
        - b
    );
    return (c - exp(a * (distance)));
}

FLOATING_NUMBER CalmPedestrianModel::calculateDistance(int pedestrianIndexOfFirst, int pedestrianIndexOfSecond)
{
    PedestrianSet* set = this->data->getPedestrianSet();

    FLOATING_NUMBER xDistance = pow(
        (
            set->getPedestrianCoordinates()->at(pedestrianIndexOfFirst).coordinates.at(0)
            - set->getPedestrianCoordinates()->at(pedestrianIndexOfSecond).coordinates.at(0)
        ), 
        2
    );
    FLOATING_NUMBER yDistance = pow(
        (
            set->getPedestrianCoordinates()->at(pedestrianIndexOfFirst).coordinates.at(1)
            - set->getPedestrianCoordinates()->at(pedestrianIndexOfSecond).coordinates.at(1)
        ), 
        2
    );
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