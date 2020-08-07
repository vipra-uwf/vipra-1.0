#include "calm_pedestrian_model.hpp"

void CalmPedestrianModel::setData(Data* initialData)
{
    this->data = initialData;
}

void CalmPedestrianModel::setGoals(Goals* goals)
{
    this->goals = goals;
}

Data* CalmPedestrianModel::getData()
{
    return this->data;
}

Goals* CalmPedestrianModel::getGoals()
{
    return this->goals;
}

void CalmPedestrianModel::precompute()
{
    //TODO: Perform precomputation for all passengers
    //Equations 6 and 7 of CALM paper
    //Decrease Force and Propulsion force in CALM code
    //result needs to be stored for each passenger

    calculateNearestNeighbors();
    this->goals->determinePedestrianGoals();
    calculatePropulsion();
    calculateRepulsion();

}

void CalmPedestrianModel::update()
{
    //use clock, calculated force prop and 
    //calculated force rep to update positions ~Elizabeth
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

FLOATING_NUMBER CalmPedestrianModel::calculateBeta(int pedIndex)
{
    int nearestNeighhborIndex = (*this->data->getPedestrianSet()->
                                getNearestNeighbors())[pedIndex];

    FLOATING_NUMBER distance = calculateDistance(
        pedIndex, 
        FLOATING_NUMBER(nearestNeighhborIndex) - b
    );
    return (c - exp(a * distance));
}

FLOATING_NUMBER CalmPedestrianModel::calculateDistance(
    int firstPedIndex, int secondPedIndex)
{
    PedestrianSet* set = this->data->getPedestrianSet();
    std::vector<Dimensions>* coords = set->getPedestrianCoordinates();

    FLOATING_NUMBER xDistance = pow(
        (
            coords->at(firstPedIndex).coordinates[0]
            - coords->at(secondPedIndex).coordinates[0]
        ), 
        2
    );
    FLOATING_NUMBER yDistance = pow(
        (
            coords->at(firstPedIndex).coordinates[1]
            - coords->at(secondPedIndex).coordinates[1]
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
                if (nearest == -1 || 
                calculateDistance(i, j) < calculateDistance(i, nearest))
                {
                    nearest = j;
                }
            }
        }
        
        (*set->getNearestNeighbors())[i] = nearest;
    }
}