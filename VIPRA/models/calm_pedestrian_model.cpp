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
    calculatePriortiy();
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
        int nearest = -1;

        std::string originSet = "P";

        for (int j = 0; j < obsSet->getNumObstacles(); ++j)
        {
            if (i != j && j < pedSet->getNumPedestrians()
                && neighborDirectionTest(i, j, originSet))
            {
                if(nearest == -1 
                    || calculateDistance(i, j, "P") 
                    < calculateDistance(i, nearest, originSet)
                    )
                {
                    nearest = j;
                    originSet = "P";
                }
            }

            if(neighborDirectionTest(i, j, "O"))
            {
                if(nearest == -1 
                    || calculateDistance(i, j, "O") 
                    < calculateDistance(i, nearest, originSet))
                {
                    nearest = j;
                    originSet = "O";
                }
            }
        }
        std::cout 
            << i << "dist:" << calculateDistance(i, nearest, originSet) 
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
            > (*firstPedcoords)[firstPedIndex].coordinates[0]
            && ((*secondPedcoords)[secondPedIndex].coordinates[1]
            <= (*firstPedcoords)[firstPedIndex].coordinates[1] + 0.20
            && (*secondPedcoords)[secondPedIndex].coordinates[1]
            >= (*firstPedcoords)[firstPedIndex].coordinates[1] - 0.20))
        {
            pass = true;
        }
    }
    else if (goalXDirection < 0 && goalYDirection == 0)
    {
        if((*secondPedcoords)[secondPedIndex].coordinates[0] 
            < (*firstPedcoords)[firstPedIndex].coordinates[0]
            && ((*secondPedcoords)[secondPedIndex].coordinates[1]
            <= (*firstPedcoords)[firstPedIndex].coordinates[1] + 0.20
            && (*secondPedcoords)[secondPedIndex].coordinates[1]
            >= (*firstPedcoords)[firstPedIndex].coordinates[1] - 0.20))
        {
            pass = true;
        }
    }
    else if (goalXDirection == 0 && goalYDirection > 0)
    {
        if((*secondPedcoords)[secondPedIndex].coordinates[1] 
            > (*firstPedcoords)[firstPedIndex].coordinates[1]
            && ((*secondPedcoords)[secondPedIndex].coordinates[0]
            <= (*firstPedcoords)[firstPedIndex].coordinates[0] + 0.20
            && (*secondPedcoords)[secondPedIndex].coordinates[0]
            >= (*firstPedcoords)[firstPedIndex].coordinates[0] - 0.20))
        {
            pass = true;
        }
    }
    else if (goalXDirection == 0 && goalYDirection < 0)
    {
        if((*secondPedcoords)[secondPedIndex].coordinates[1] 
            < (*firstPedcoords)[firstPedIndex].coordinates[1]
            && ((*secondPedcoords)[secondPedIndex].coordinates[0]
            <= (*firstPedcoords)[firstPedIndex].coordinates[0] + 0.20
            && (*secondPedcoords)[secondPedIndex].coordinates[0]
            >= (*firstPedcoords)[firstPedIndex].coordinates[0] - 0.20))
        {
            pass = true;
        }
    }

    return pass;
}

void CalmPedestrianModel::calculatePriortiy()
{
    CalmPedestrianSet* pedSet = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());
    
    ObstacleSet* obSet = dynamic_cast<ObstacleSet*>(
        this->data->getObstacleSet());
    
    std::vector<Dimensions>* pedCoords = pedSet->getPedestrianCoordinates();
    std::vector<Dimensions>* obCoords = obSet->getObstacleCoordinates();

    std::vector<FLOATING_NUMBER> Aisles;
    std::vector<FLOATING_NUMBER> AisleSize;
    int numAisles = 0;

    for(int i = 0; i < pedSet->getNumPedestrians(); ++i)
    {
        bool duplicateCheck = true;

        if(i == 0)
        {
            Aisles.push_back((*pedCoords)[i].coordinates[0]);
            ++numAisles;
        }

        else
        {
            for(int j = 0; j < numAisles; ++j)
            {
                if((*pedCoords)[i].coordinates[0] == Aisles[j])
                {
                    duplicateCheck = false;
                }
            }

            if(duplicateCheck == true)
            {
                Aisles.push_back((*pedCoords)[i].coordinates[0]);
                ++numAisles;
            }
        }
    }

    for (int i = 0; i < numAisles; ++i)
    {
        std::cout << "Aisle " << i << ": " << Aisles[i] << std::endl;
    }

    for(int i = 0; i < numAisles; ++i)
    {
        FLOATING_NUMBER backOfAisle = -1;
        FLOATING_NUMBER frontOfAisle = -1;
        for(int j = 0; j < obSet->getNumObstacles(); ++j)
        {
            if((*obCoords)[j].coordinates[0] > Aisles[i])
            {
                //TODO fix this so it's not hard coded! - Elizabeth
                if((*obCoords)[j].coordinates[1] < 1.73 && (*obCoords)[j]
                    .coordinates[1] > -1.73)                                                {
                    if(frontOfAisle == -1)
                    {
                        frontOfAisle = (*obCoords)[j].coordinates[0];
                    }
                    else if(((*obCoords)[j].coordinates[0] - Aisles[i])
                        < (frontOfAisle - Aisles[i]))
                    {
                        frontOfAisle = (*obCoords)[j].coordinates[0];
                    }
                }
            }
            else if((*obCoords)[j].coordinates[0] < Aisles[i])
            {
                if((*obCoords)[j].coordinates[1] < 1.73 
                    && (*obCoords)[j].coordinates[1] > -1.73)
                {
                    if(backOfAisle == -1)
                    {
                        backOfAisle = (*obCoords)[j].coordinates[0];
                    }

                    else if((Aisles[i] - (*obCoords)[j].coordinates[0]) 
                        < (Aisles[i] - backOfAisle))
                    {
                        backOfAisle = (*obCoords)[j].coordinates[0];
                    }
                }
            }
        }
        std::cout << "Aisle " << i << " back" << backOfAisle
            << ": front " << frontOfAisle << std::endl;
            
        AisleSize.push_back(frontOfAisle-backOfAisle);
    }

    for (int i = 0; i < numAisles; ++i)
    {
        std::cout << "Aisle size" << i << ": " << AisleSize[i] << std::endl;
    }

    std::vector<FLOATING_NUMBER> priorities;

    for(int i = 0; i < pedSet->getNumPedestrians(); ++i)
    {
        bool prioritiesSet = false;
        
        for(int j = 0; prioritiesSet == false && j < numAisles; ++j)
        {
            if((*pedCoords)[i].coordinates[0] < (Aisles[j] + (AisleSize[j]/2))
            &&(*pedCoords)[i].coordinates[0] > (Aisles[j] - (AisleSize[j]/2)))
            {
                priorities.push_back(j);
                break;
            }
        }
    }

    pedSet->setPriorities(priorities);

    for(int i = 0; i < pedSet->getNumPedestrians(); ++i)
    {
        std::cout << "Ped " << i << " priorities: " << priorities[i] << std::endl;
    }
}