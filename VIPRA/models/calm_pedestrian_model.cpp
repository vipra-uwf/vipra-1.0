#include "calm_pedestrian_model.hpp"

void CalmPedestrianModel::configure(CONFIG_MAP* configMap)
{

}

void CalmPedestrianModel::initialize()
{
    this->pedSet = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());
    this->obSet = dynamic_cast<ObstacleSet*>(
        this->data->getObstacleSet());
    createAisles();
    calculatePriority();
}

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

    std::vector<std::pair<std::string, int>> nearestNeighbors;
    std::vector<int> nearestPedNeighbor;
    bool currentPriorityActive = false;
    bool priorityActiveFlag = false;
    std::vector<MovementDefinitions> updatedMoveStates;

    for (int i = 0; i < this->pedSet->getNumPedestrians(); ++i)
    {
        this->goals->determinePedestrianGoals();
        nearestNeighbors.push_back(calculateNearestNeighbors(i));
        nearestPedNeighbor.push_back(calculateNearestPedNeighbors(i));
        currentPriorityActive = updatePriority(i);
        if(currentPriorityActive == true)
        {
            priorityActiveFlag = true;
        }
        updatedMoveStates.push_back(updateMovementState(i));
        //calculatePropulsion();
        //calculateRepulsion();
    }
    this->pedSet->setNearestNeighbors(nearestNeighbors);
    this->pedSet->setNearestPedNeighbors(nearestPedNeighbor);
    if(priorityActiveFlag == false)
    {
        this->currentPriority--;
        std::cout << currentPriority << std::endl;
    }
    this->pedSet->setMovementStates(updatedMoveStates);
}

void CalmPedestrianModel::update(FLOATING_NUMBER time)
{
    std::vector<Dimensions> movedCoordinates;

    FLOATING_NUMBER arbitraryMover = 0.01;
    
    for(int i = 0; i < this->pedSet->getNumPedestrians(); ++i)
    {

        if((*this->pedSet->getMovementStates())[i]
                == MovementDefinitions::STOP)
        {

            movedCoordinates.push_back
            (
                Dimensions 
                {
                    std::vector<FLOATING_NUMBER>
                    {
                        (*this->pedSet->getPedestrianCoordinates())[i]
                        .coordinates[0],
                        (*this->pedSet->getPedestrianCoordinates())[i]
                        .coordinates[1] //distanceMoved
                    }
                }
            );
        }
        
        else if ((*this->pedSet->getMovementStates())[i]
                    == MovementDefinitions::PED_DYNAM)
        {
            if((*this->pedSet->getGoalCoordinates())[i].coordinates[0] 
            == (*this->pedSet->getPedestrianCoordinates())[i].coordinates[0]
            && (*this->pedSet->getGoalCoordinates())[i].coordinates[1] == 0)
            {
                
                if((*this->pedSet->getPedestrianCoordinates())[i].coordinates[1] < 0)
                {
                    movedCoordinates.push_back
                    (
                        Dimensions 
                        {
                            std::vector<FLOATING_NUMBER>
                            {
                                (*this->pedSet->getPedestrianCoordinates())[i]
                                .coordinates[0],
                                (*this->pedSet->getPedestrianCoordinates())[i]
                                .coordinates[1] +  arbitraryMover //distanceMoved
                            }
                        }
                    );
                }
                
                else if((*this->pedSet->getPedestrianCoordinates())[i]
                    .coordinates[1] > 0)
                {

                    movedCoordinates.push_back
                    (
                        Dimensions 
                        {
                            std::vector<FLOATING_NUMBER> 
                            {
                                (*this->pedSet->getPedestrianCoordinates())[i]
                                .coordinates[0],
                                (*this->pedSet->getPedestrianCoordinates())[i]
                                .coordinates[1] -  arbitraryMover //distanceMoved
                            }
                        }
                    );
                }
            }

            else if((*this->pedSet->getGoalCoordinates())[i].coordinates[0]
            == (this->getGoals()->getPedExitGoal(i)).coordinates[0]
            && (*this->pedSet->getGoalCoordinates())[i].coordinates[1] == 0)
            {

                movedCoordinates.push_back
                (
                    Dimensions 
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            (*this->pedSet->getPedestrianCoordinates())[i]
                            .coordinates[0] + arbitraryMover, //distanceMoved,
                            (*this->pedSet->getPedestrianCoordinates())[i]
                            .coordinates[1]
                        }
                    }
                );
            }

            else if((*this->pedSet->getGoalCoordinates())[i].coordinates[0]
            == (this->getGoals()->getPedExitGoal(i)).coordinates[0]
            && (*this->pedSet->getGoalCoordinates())[i].coordinates[1]
            == (this->getGoals()->getPedExitGoal(i)).coordinates[1])
            {
            
                movedCoordinates.push_back
                (
                    Dimensions 
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            (*this->pedSet->getPedestrianCoordinates())[i]
                            .coordinates[0],
                            (*this->pedSet->getPedestrianCoordinates())[i]
                            .coordinates[1] + arbitraryMover //distanceMoved
                        }
                    }
                );
            }
        }
            
        if(this->goals->checkPedestianGoalsMet(i))
        {
            this->pedSet->removePedestrian(i);
        }

    }
    this->pedSet->setPedestrianCoordinates(movedCoordinates);
}

void CalmPedestrianModel::calculatePropulsion(int pedIndex)
{    
    (*this->pedSet->getPropulsionForces())[pedIndex] = 
        (
            (
                (*this->pedSet->getDesiredSpeeds())[pedIndex]
                - (*this->pedSet->getSpeeds())[pedIndex]
            ) 
            / (*this->pedSet->getReactionTimes())[pedIndex]
        )
        * (*this->pedSet->getMasses())[pedIndex];
}

void CalmPedestrianModel::calculateRepulsion(int pedIndex)
{
    (*this->pedSet->getRepulsionForces())[pedIndex] = 
        (
            (
                (
                    (
                        calculateBeta(pedIndex) -1
                    )
                    * (*this->pedSet->getDesiredSpeeds())[pedIndex]
                )
                / (*this->pedSet->getReactionTimes())[pedIndex]
            )
        * (*this->pedSet->getMasses())[pedIndex]
        );
}

FLOATING_NUMBER CalmPedestrianModel::calculateBeta(int pedIndex)
{
    
    int nearestNeighhborIndex = (*this->pedSet->getNearestNeighbors())[pedIndex].second;
    std::string nearestNeighborOrigin = 
        (*this->pedSet->getNearestNeighbors())[pedIndex].first;

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

    std::vector<Dimensions>* firstPedcoords = this->pedSet->getPedestrianCoordinates();
    std::vector<Dimensions>* secondPedcoords = this->pedSet->getPedestrianCoordinates();

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

std::pair<std::string, int> CalmPedestrianModel::calculateNearestNeighbors(int pedIndex)
{

    int nearest = -1;

    std::string originSet = "P";

    for (int j = 0; j < this->obSet->getNumObstacles(); ++j)
    {
        if (pedIndex != j && j < this->pedSet->getNumPedestrians()
                && neighborDirectionTest(pedIndex, j, originSet))
        {
            if(nearest == -1 
                || calculateDistance(pedIndex, j, "P") 
                < calculateDistance(pedIndex, nearest, originSet)
                )
            {
                nearest = j;
                originSet = "P";
            }
        }

        if(neighborDirectionTest(pedIndex, j, "O"))
        {
            if(nearest == -1 
                || calculateDistance(pedIndex, j, "O") 
                < calculateDistance(pedIndex, nearest, originSet))
            {
                nearest = j;
                originSet = "O";
            }
        }
    }

        /*std::cout 
            << pedIndex << "dist:" << calculateDistance(pedIndex, nearest, originSet) 
            << std::endl;*/
        
    return std::make_pair(std::string(originSet), nearest);

}

int CalmPedestrianModel::calculateNearestPedNeighbors(int pedIndex)
{
    
    std::vector<int> nearestPedNeighbor;

    int nearest = -1;

    std::string originSet = "P";

    for (int j = 0; j < this->pedSet->getNumPedestrians(); ++j)
    {
        if (pedIndex != j && neighborDirectionTest(pedIndex, j, originSet))
        {
            if(nearest == -1 || calculateDistance(pedIndex, j, originSet) < 
                calculateDistance(pedIndex, nearest, originSet)
                )
            {
                nearest = j;
            }
        }
    }
        /*std::cout << i << "dist:" << calculateDistance(i, nearest, originSet)
            << std::endl;*/
      
    return nearest;

}

bool CalmPedestrianModel::neighborDirectionTest(
    int firstPedIndex, int secondPedIndex, std::string originSet)
{

    bool pass = false;

    std::vector<Dimensions>* firstPedcoords = this->pedSet->getPedestrianCoordinates();
    std::vector<Dimensions>* secondPedcoords = this->pedSet->getPedestrianCoordinates();

    if(originSet == "O")
    {
        secondPedcoords = this->data->getObstacleSet()->
            getObstacleCoordinates();
    }

    FLOATING_NUMBER goalXDirection = 
        (*this->pedSet->getGoalCoordinates())[firstPedIndex].coordinates[0]
        - (*firstPedcoords)[firstPedIndex].coordinates[0];
    FLOATING_NUMBER goalYDirection = 
        (*this->pedSet->getGoalCoordinates())[firstPedIndex].coordinates[1]
        - (*firstPedcoords)[firstPedIndex].coordinates[1];

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

void CalmPedestrianModel::calculatePriority()
{
    
    std::vector<Dimensions>* pedCoords = this->pedSet->getPedestrianCoordinates();
    std::vector<FLOATING_NUMBER>* Aisles = this->obSet->getAisles();
    std::vector<FLOATING_NUMBER>* AislesSize = this->obSet->getAislesSize();
    int numAisles = this->obSet->getNumAisles();

    //std::cout << numAisles; //testing statement -El

    std::vector<FLOATING_NUMBER> priorities;
    std::vector<int> startingAisles; //maybe move somewhere else? 
                                    //might not fit into this method - EL
     for(int i = 0; i < this->pedSet->getNumPedestrians(); ++i)
     {
        bool prioritySet = false;
        for(int j = 0; prioritySet == false && j < numAisles; ++j)
        {
            if((*pedCoords)[i].coordinates[0] < ((*Aisles)[j] 
            + ((*AislesSize)[j]/2)) && (*pedCoords)[i].coordinates[0]
            > ((*Aisles)[j] - ((*AislesSize)[j]/2)))
            {
                priorities.push_back(j);
                startingAisles.push_back(j);
                break;
            }
        }
     }

     this->pedSet->setPriorities(priorities);
     this->pedSet->setStartingAisles(startingAisles);
    

    /*for(int i = 0; i < pedSet->getNumPedestrians(); ++i) //testing loop -EL
     {
         std::cout << "Ped " << i << " priority: " << priorities[i] << std::endl;
     }*/

     this->currentPriority = 24; //hardcoded! fix this -EL
}

void CalmPedestrianModel::createAisles() //TODO move this somewhere more approrpriate -EL
{
    
    std::vector<Dimensions>* pedCoords = this->pedSet->getPedestrianCoordinates();
    std::vector<Dimensions>* obCoords = this->obSet->getObstacleCoordinates();

    std::vector<FLOATING_NUMBER> Aisles;
    std::vector<FLOATING_NUMBER> AisleSize;
    int numAisles = 0;

    for(int i = 0; i < this->pedSet->getNumPedestrians(); ++i)
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

    /*for (int i = 0; i < numAisles; ++i) //testing loop -EL
    {
        std::cout << "Aisle " << i << ": " << Aisles[i] << std::endl;
    }*/

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
                   .coordinates[1] > -1.73)
                {
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

        /*std::cout << "Aisle " << i << " back" << backOfAisle //testing statement -EL
            << ": front " << frontOfAisle << std::endl;*/ 
        AisleSize.push_back(frontOfAisle-backOfAisle);
    }

    /*for (int i = 0; i < numAisles; ++i) //testing loop -EL
    {
        std::cout << "Aisle size" << i << ": " << AisleSize[i] << std::endl;
    }*/

    this->obSet->setAisles(Aisles);
    this->obSet->setAislesSize(AisleSize);
    this->obSet->setNumAisles(numAisles);
}

MovementDefinitions CalmPedestrianModel::updateMovementState(int pedIndex)
{
    MovementDefinitions newDefinition;
    if(/*(this->calculateDistance( i , (*set->getNearestPedNeighbors())[i]
        , "P") < 0.1) ||*/ (*this->pedSet->getPriorities())[pedIndex] < this->currentPriority 
        && ((*this->pedSet->getPedestrianCoordinates())[pedIndex].coordinates[0] >= 
        ((*this->obSet->getAisles())[(*this->pedSet->getStartingAisles())[pedIndex]] 
        + ((*this->obSet->getAislesSize())[(*this->pedSet->getStartingAisles())[pedIndex]] / 2)
        - 0.1)))
        {
            newDefinition = MovementDefinitions::STOP;
        }

    else
    {
        newDefinition = MovementDefinitions::PED_DYNAM;
    }

    return newDefinition;
}

bool CalmPedestrianModel::updatePriority(int pedIndex)
{

    bool currentPriorityActive = false;

    if((*this->pedSet->getPriorities())[pedIndex] == this->currentPriority)
    {
        currentPriorityActive = true;
    }

    return currentPriorityActive;

}