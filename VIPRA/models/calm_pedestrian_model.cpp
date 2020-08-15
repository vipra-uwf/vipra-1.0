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
    CalmPedestrianSet* set = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());

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
    CalmPedestrianSet* set = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());

    for(int i = 0; i < set->getNumPedestrians(); ++i)
    {
        (*set->getRepulsionForces())[i] = 
            (
                (
                    (
                        (
                            calculateBeta(i) 
                            * (*set->getDesiredSpeeds())[i]
                        )
                        - 
                        (*set->getSpeeds())[i] 
                    )
                    / (*set->getReactionTimes())[i]
                )
            * (*set->getMasses())[i]
            );
    }
}

FLOATING_NUMBER CalmPedestrianModel::calculateBeta(int pedIndex)
{
	
    CalmPedestrianSet* set = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());

    int nearestNeighhborIndex = (*set->getNearestNeighbors())[pedIndex].second;
    std::string nearestNeighborOrigin = 
        (*set->getNearestNeighbors())[pedIndex].first;

    FLOATING_NUMBER distance = (calculateDistance(
        pedIndex, 
        FLOATING_NUMBER(nearestNeighhborIndex),
        nearestNeighborOrigin
    ) - b);
    return (c - exp(a * distance));
}

FLOATING_NUMBER CalmPedestrianModel::calculateDistance(
    int firstPedIndex, int secondPedIndex, std::string originSet)
{
    CalmPedestrianSet* set = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());

    std::vector<Dimensions>* firstPedcoords = set->getPedestrianCoordinates();
    std::vector<Dimensions>* secondPedcoords = set->getPedestrianCoordinates();

    if(originSet == "O")
    {
        secondPedcoords = this->data->getObstacleSet()->
            getObstacleCoordinates();
    }

    FLOATING_NUMBER xDistance = pow(
        (
            firstPedcoords->at(firstPedIndex).coordinates[0]
            - secondPedcoords->at(secondPedIndex).coordinates[0]
        ), 
        2
    );
    FLOATING_NUMBER yDistance = pow(
        (
            firstPedcoords->at(firstPedIndex).coordinates[1]
            - secondPedcoords->at(secondPedIndex).coordinates[1]
        ), 
        2
    );
    return (sqrt(xDistance + yDistance));
}

void CalmPedestrianModel::calculateNearestNeighbors()
{

    CalmPedestrianSet* pedSet = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());
    ObstacleSet* obsSet = this->data->getObstacleSet();


    for (int i = 0; i < pedSet->getNumPedestrians(); ++i)
    {
        int nearest;

        if(i == 0)
            nearest = 1;
        else
            nearest = 0;

        std::string originSet = "P";

        for (int j = 0; j < obsSet->getNumObstacles(); ++j)
        {
            if (i != j && j < pedSet->getNumPedestrians()
                && neighborDirectionTest(i, j, originSet))
            {
                if(calculateDistance(i, j, "P") < 
                    calculateDistance(i, nearest, originSet)
                    )
                {
                    nearest = j;
                    originSet = "P";
                }
            }
            if(neighborDirectionTest(i, j, "O"))
            {
                if(calculateDistance(i, j, "O") < 
                    calculateDistance(i, nearest, originSet)
                    )
                {
                    nearest = j;
                    originSet = "O";
                }
            }
        }
        std::cout << i << "dist:" << calculateDistance(i, nearest, originSet)
            << std::endl;
        
        (*pedSet->getNearestNeighbors())[i] = 
            std::make_pair(std::string(originSet), nearest);
    }
}

bool CalmPedestrianModel::neighborDirectionTest(
    int firstPedIndex, int secondPedIndex, std::string originSet)
{

    bool pass = false;

    CalmPedestrianSet* set = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());

    std::vector<Dimensions>* firstPedcoords = set->getPedestrianCoordinates();
    std::vector<Dimensions>* secondPedcoords = set->getPedestrianCoordinates();

    if(originSet == "O")
    {
        secondPedcoords = this->data->getObstacleSet()->
            getObstacleCoordinates();
    }

    FLOATING_NUMBER goalXDirection = (*set->getGoalCoordinates())[firstPedIndex]
        .coordinates[0] - (*firstPedcoords)[firstPedIndex].coordinates[0];
    FLOATING_NUMBER goalYDirection = (*set->getGoalCoordinates())[firstPedIndex]
        .coordinates[1] - (*firstPedcoords)[firstPedIndex].coordinates[1];

    if(goalXDirection > 0 && goalYDirection == 0)
    {
        if((*secondPedcoords)[secondPedIndex].coordinates[0] 
            > (*firstPedcoords)[firstPedIndex].coordinates[0])
        {
            pass = true;
        }
    }
    else if (goalXDirection < 0 && goalYDirection == 0)
    {
        if((*secondPedcoords)[secondPedIndex].coordinates[0] 
            < (*firstPedcoords)[firstPedIndex].coordinates[0])
        {
            pass = true;
        }
    }
    else if (goalXDirection == 0 && goalYDirection > 0)
    {
        if((*secondPedcoords)[secondPedIndex].coordinates[1] 
            > (*firstPedcoords)[firstPedIndex].coordinates[1])
        {
            pass = true;
        }
    }
    else if (goalXDirection == 0 && goalYDirection < 0)
    {
        if((*secondPedcoords)[secondPedIndex].coordinates[1] 
            < (*firstPedcoords)[firstPedIndex].coordinates[1])
        {
            pass = true;
        }
    }

    return pass;
}
