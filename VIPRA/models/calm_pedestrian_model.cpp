#include "calm_pedestrian_model.hpp"

void CalmPedestrianModel::configure(CONFIG_MAP* configMap)
{

}

void CalmPedestrianModel::initialize()
{
    this->pedestrianSet = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());
    this->obstacleSet = dynamic_cast<ObstacleSet*>(
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
    std::vector<int> nearestPedestrianNeighbor;
    bool currentPriorityActive = false;
    bool priorityActiveFlag = false;
    std::vector<MovementDefinitions> updatedMoveStates;

    for (int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        this->goals->determinePedestrianGoals();
        nearestNeighbors.push_back(calculateNearestNeighbors(i));
        nearestPedestrianNeighbor.push_back(calculateNearestPedNeighbors(i));
        currentPriorityActive = updatePriority(i);
        if(currentPriorityActive == true)
        {
            priorityActiveFlag = true;
        }
        updatedMoveStates.push_back(updateMovementState(i));
        //calculatePropulsion();
        //calculateRepulsion();
    }
    this->pedestrianSet->setNearestNeighbors(nearestNeighbors);
    this->pedestrianSet->setNearestPedNeighbors(nearestPedestrianNeighbor);
    if(priorityActiveFlag == false)
    {
        this->currentPriority--;
        std::cout << currentPriority << std::endl;
    }
    this->pedestrianSet->setMovementStates(updatedMoveStates);
}

void CalmPedestrianModel::update(FLOATING_NUMBER time)
{
    std::vector<Dimensions> movedCoordinates;

    FLOATING_NUMBER arbitraryMover = 0.01;
    
    for(int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {

        if((*this->pedestrianSet->getMovementStates())[i]
                == MovementDefinitions::STOP)
        {

            movedCoordinates.push_back
            (
                Dimensions 
                {
                    std::vector<FLOATING_NUMBER>
                    {
                        (*this->pedestrianSet->getPedestrianCoordinates())[i]
                        .coordinates[0],
                        (*this->pedestrianSet->getPedestrianCoordinates())[i]
                        .coordinates[1] //distanceMoved
                    }
                }
            );
        }
        
        else if ((*this->pedestrianSet->getMovementStates())[i]
                    == MovementDefinitions::PED_DYNAM)
        {
            if((*this->pedestrianSet->getGoalCoordinates())[i].coordinates[0]
                == (*this->pedestrianSet->getPedestrianCoordinates())[i]
                .coordinates[0]&& (*this->pedestrianSet->getGoalCoordinates())
                [i].coordinates[1] == 0)
            {
                
                if((*this->pedestrianSet->getPedestrianCoordinates())[i]
                    .coordinates[1] < 0)
                {
                    movedCoordinates.push_back
                    (
                        Dimensions 
                        {
                            std::vector<FLOATING_NUMBER>
                            {
                                (*this->pedestrianSet->
                                getPedestrianCoordinates())[i].coordinates[0],
                                (*this->pedestrianSet->
                                getPedestrianCoordinates())[i].coordinates[1]
                                +  arbitraryMover //distanceMoved
                            }
                        }
                    );
                }
                
                else if((*this->pedestrianSet->getPedestrianCoordinates())[i]
                    .coordinates[1] > 0)
                {

                    movedCoordinates.push_back
                    (
                        Dimensions 
                        {
                            std::vector<FLOATING_NUMBER> 
                            {
                                (*this->pedestrianSet->
                                getPedestrianCoordinates())[i].coordinates[0],
                                (*this->pedestrianSet->
                                getPedestrianCoordinates())[i].coordinates[1] 
                                - arbitraryMover //distanceMoved
                            }
                        }
                    );
                }
            }

            else if((*this->pedestrianSet->getGoalCoordinates())[i].coordinates[0]
            == (this->getGoals()->getPedestrianExitGoal(i)).coordinates[0]
            && (*this->pedestrianSet->getGoalCoordinates())[i].coordinates[1] == 0)
            {

                movedCoordinates.push_back
                (
                    Dimensions 
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            (*this->pedestrianSet->getPedestrianCoordinates())[i]
                            .coordinates[0] + arbitraryMover, //distanceMoved,
                            (*this->pedestrianSet->getPedestrianCoordinates())[i]
                            .coordinates[1]
                        }
                    }
                );
            }

            else if((*this->pedestrianSet->getGoalCoordinates())[i].coordinates[0]
            == (this->getGoals()->getPedestrianExitGoal(i)).coordinates[0]
            && (*this->pedestrianSet->getGoalCoordinates())[i].coordinates[1]
            == (this->getGoals()->getPedestrianExitGoal(i)).coordinates[1])
            {
            
                movedCoordinates.push_back
                (
                    Dimensions 
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            (*this->pedestrianSet->getPedestrianCoordinates())[i]
                            .coordinates[0],
                            (*this->pedestrianSet->getPedestrianCoordinates())[i]
                            .coordinates[1] + arbitraryMover //distanceMoved
                        }
                    }
                );
            }
        }
            
        if(this->goals->checkPedestianGoalsMet(i))
        {
            this->pedestrianSet->removePedestrian(i);
        }

    }
    this->pedestrianSet->setPedestrianCoordinates(movedCoordinates);
}

void CalmPedestrianModel::calculatePropulsion(int pedestrianIndex)
{    
    (*this->pedestrianSet->getPropulsionForces())[pedestrianIndex] = 
        (
            (
                (*this->pedestrianSet->getDesiredSpeeds())[pedestrianIndex]
                - (*this->pedestrianSet->getSpeeds())[pedestrianIndex]
            ) 
            / (*this->pedestrianSet->getReactionTimes())[pedestrianIndex]
        )
        * (*this->pedestrianSet->getMasses())[pedestrianIndex];
}

void CalmPedestrianModel::calculateRepulsion(int pedestrianIndex)
{
    (*this->pedestrianSet->getRepulsionForces())[pedestrianIndex] = 
        (
            (
                (
                    (
                        calculateBeta(pedestrianIndex) -1
                    )
                    * (*this->pedestrianSet->
                        getDesiredSpeeds())[pedestrianIndex]
                )
                / (*this->pedestrianSet->getReactionTimes())[pedestrianIndex]
            )
        * (*this->pedestrianSet->getMasses())[pedestrianIndex]
        );
}

FLOATING_NUMBER CalmPedestrianModel::calculateBeta(int pedestrianIndex)
{
    
    int nearestNeighhborIndex 
        = (*this->pedestrianSet->getNearestNeighbors())[pedestrianIndex]
            .second;
    std::string nearestNeighborOrigin = 
        (*this->pedestrianSet->getNearestNeighbors())[pedestrianIndex].first;

    FLOATING_NUMBER distance = (calculateDistance(
        pedestrianIndex, 
        FLOATING_NUMBER(nearestNeighhborIndex),
        nearestNeighborOrigin
    ) - b);

    return (c - exp(a * distance));
}

FLOATING_NUMBER CalmPedestrianModel::calculateDistance(
    int firstPedestrianIndex, int secondPedestrianIndex, std::string originSet)
{

    std::vector<Dimensions>* firstPedestriancoords 
        = this->pedestrianSet->getPedestrianCoordinates();
    std::vector<Dimensions>* secondPedestriancoords 
        = this->pedestrianSet->getPedestrianCoordinates();

    if(originSet == "O")
    {
        secondPedestriancoords = this->data->getObstacleSet()->
            getObstacleCoordinates();
    }

    FLOATING_NUMBER xDistance = pow(
        (
            firstPedestriancoords->at(firstPedestrianIndex).coordinates[0]
            - secondPedestriancoords->at(secondPedestrianIndex).coordinates[0]
        ), 
        2
    );
    FLOATING_NUMBER yDistance = pow(
        (
            firstPedestriancoords->at(firstPedestrianIndex).coordinates[1]
            - secondPedestriancoords->at(secondPedestrianIndex).coordinates[1]
        ), 
        2
    );
    return (sqrt(xDistance + yDistance));
}

std::pair<std::string, int> 
    CalmPedestrianModel::calculateNearestNeighbors(int pedestrianIndex)
{

    int nearest = -1;

    std::string originSet = "P";

    for (int j = 0; j < this->obstacleSet->getNumObstacles(); ++j)
    {
        if (pedestrianIndex != j && j < this->pedestrianSet->
            getNumPedestrians() && neighborDirectionTest
            (pedestrianIndex, j, originSet))
        {
            if(nearest == -1 
                || calculateDistance(pedestrianIndex, j, "P") 
                < calculateDistance(pedestrianIndex, nearest, originSet)
                )
            {
                nearest = j;
                originSet = "P";
            }
        }

        if(neighborDirectionTest(pedestrianIndex, j, "O"))
        {
            if(nearest == -1 
                || calculateDistance(pedestrianIndex, j, "O") 
                < calculateDistance(pedestrianIndex, nearest, originSet))
            {
                nearest = j;
                originSet = "O";
            }
        }
    }

        /*std::cout 
            << pedestrianIndex << "dist:" << calculateDistance(pedestrianIndex, nearest, originSet)
            << std::endl;*/
        
    return std::make_pair(std::string(originSet), nearest);

}

int CalmPedestrianModel::calculateNearestPedNeighbors(int pedestrianIndex)
{
    
    std::vector<int> nearestPedestrianNeighbor;

    int nearest = -1;

    std::string originSet = "P";

    for (int j = 0; j < this->pedestrianSet->getNumPedestrians(); ++j)
    {
        if (pedestrianIndex != j && neighborDirectionTest
            (pedestrianIndex, j, originSet))
        {
            if(nearest == -1 || calculateDistance
                (pedestrianIndex, j, originSet) 
                < calculateDistance(pedestrianIndex, nearest, originSet)
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
    int firstPedestrianIndex, int secondPedestrianIndex, std::string originSet)
{

    bool pass = false;

    std::vector<Dimensions>* firstPedestriancoords 
        = this->pedestrianSet->getPedestrianCoordinates();
    std::vector<Dimensions>* secondPedestriancoords 
        = this->pedestrianSet->getPedestrianCoordinates();

    if(originSet == "O")
    {
        secondPedestriancoords = this->data->getObstacleSet()->
            getObstacleCoordinates();
    }

    FLOATING_NUMBER goalXDirection = 
        (*this->pedestrianSet->getGoalCoordinates())[firstPedestrianIndex]
        .coordinates[0] - (*firstPedestriancoords)[firstPedestrianIndex]
        .coordinates[0];
    FLOATING_NUMBER goalYDirection = 
        (*this->pedestrianSet->getGoalCoordinates())[firstPedestrianIndex]
        .coordinates[1] - (*firstPedestriancoords)[firstPedestrianIndex]
        .coordinates[1];

    if(goalXDirection > 0 && goalYDirection == 0)
    {
        if((*secondPedestriancoords)[secondPedestrianIndex].coordinates[0]
            > (*firstPedestriancoords)[firstPedestrianIndex].coordinates[0]
            && ((*secondPedestriancoords)[secondPedestrianIndex].coordinates[1]
            <= (*firstPedestriancoords)[firstPedestrianIndex].coordinates[1] 
            + 0.20
            && (*secondPedestriancoords)[secondPedestrianIndex].coordinates[1]
            >= (*firstPedestriancoords)[firstPedestrianIndex].coordinates[1] 
            - 0.20))
        {
            pass = true;
        }
    }
    else if (goalXDirection < 0 && goalYDirection == 0)
    {
        if((*secondPedestriancoords)[secondPedestrianIndex].coordinates[0] 
            < (*firstPedestriancoords)[firstPedestrianIndex].coordinates[0]
            && ((*secondPedestriancoords)[secondPedestrianIndex].coordinates[1]
            <= (*firstPedestriancoords)[firstPedestrianIndex].coordinates[1]
            + 0.20
            && (*secondPedestriancoords)[secondPedestrianIndex].coordinates[1]
            >= (*firstPedestriancoords)[firstPedestrianIndex].coordinates[1]
            - 0.20))
        {
            pass = true;
        }
    }
    else if (goalXDirection == 0 && goalYDirection > 0)
    {
        if((*secondPedestriancoords)[secondPedestrianIndex].coordinates[1] 
            > (*firstPedestriancoords)[firstPedestrianIndex].coordinates[1]
            && ((*secondPedestriancoords)[secondPedestrianIndex].coordinates[0]
            <= (*firstPedestriancoords)[firstPedestrianIndex].coordinates[0] 
            + 0.20
            && (*secondPedestriancoords)[secondPedestrianIndex].coordinates[0]
            >= (*firstPedestriancoords)[firstPedestrianIndex].coordinates[0] 
            - 0.20))
        {
            pass = true;
        }
    }
    else if (goalXDirection == 0 && goalYDirection < 0)
    {
        if((*secondPedestriancoords)[secondPedestrianIndex].coordinates[1] 
            < (*firstPedestriancoords)[firstPedestrianIndex].coordinates[1]
            && ((*secondPedestriancoords)[secondPedestrianIndex].coordinates[0]
            <= (*firstPedestriancoords)[firstPedestrianIndex].coordinates[0] 
            + 0.20
            && (*secondPedestriancoords)[secondPedestrianIndex].coordinates[0]
            >= (*firstPedestriancoords)[firstPedestrianIndex].coordinates[0] 
            - 0.20))
        {
            pass = true;
        }
    }

    return pass;
}

void CalmPedestrianModel::calculatePriority()
{
    
    std::vector<Dimensions>* pedestrianCoordinates 
        = this->pedestrianSet->getPedestrianCoordinates();
    std::vector<FLOATING_NUMBER>* aisles = dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)->getAisles();
    std::vector<FLOATING_NUMBER>* aislesSize 
        = dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)->getAislesSize();
    int numAisles = dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)->getNumAisles();

    //std::cout << numAisles; //testing statement -El

    std::vector<FLOATING_NUMBER> priorities;
    std::vector<int> startingAisles; //maybe move somewhere else? 
                                    //might not fit into this method - EL
     for(int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
     {
        bool prioritySet = false;
        for(int j = 0; prioritySet == false && j < numAisles; ++j)
        {
            if((*pedestrianCoordinates)[i].coordinates[0] < ((*aisles)[j] 
            + ((*aislesSize)[j]/2)) && (*pedestrianCoordinates)[i].coordinates[0]
            > ((*aisles)[j] - ((*aislesSize)[j]/2)))
            {
                priorities.push_back(j);
                startingAisles.push_back(j);
                break;
            }
        }
     }

     this->pedestrianSet->setPriorities(priorities);
     this->pedestrianSet->setStartingAisles(startingAisles);
    

    /*for(int i = 0; i < pedestrianSet->getNumPedestrians(); ++i) //testing loop -EL
     {
         std::cout << "Ped " << i << " priority: " << priorities[i] << std::endl;
     }*/

     this->currentPriority = 24; //hardcoded! fix this -EL
}

void CalmPedestrianModel::createAisles() //TODO move this somewhere more approrpriate -EL
{
    
    std::vector<Dimensions>* pedestrianCoordinates 
        = this->pedestrianSet->getPedestrianCoordinates();
    std::vector<Dimensions>* obstacleCoords 
        = this->obstacleSet->getObstacleCoordinates();

    std::vector<FLOATING_NUMBER> aisles;
    std::vector<FLOATING_NUMBER> aisleSize;
    int numAisles = 0;

    for(int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        bool duplicateCheck = true;

        if(i == 0)
        {
            aisles.push_back((*pedestrianCoordinates)[i].coordinates[0]);
            ++numAisles;
        }

        else
        {
            for(int j = 0; j < numAisles; ++j)
            {
                if((*pedestrianCoordinates)[i].coordinates[0] == aisles[j])
                {
                    duplicateCheck = false;
                }
            }

            if(duplicateCheck == true)
            {
                aisles.push_back((*pedestrianCoordinates)[i].coordinates[0]);
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
        for(int j = 0; j < obstacleSet->getNumObstacles(); ++j)
        {
            if((*obstacleCoords)[j].coordinates[0] > aisles[i])
            {
                //TODO fix this so it's not hard coded! - Elizabeth
                if((*obstacleCoords)[j].coordinates[1] < 1.73 
                && (*obstacleCoords)[j].coordinates[1] > -1.73)
                {
                    if(frontOfAisle == -1)
                    {
                        frontOfAisle = (*obstacleCoords)[j].coordinates[0];
                    }
                    else if(((*obstacleCoords)[j].coordinates[0] - aisles[i])
                        < (frontOfAisle - aisles[i]))
                    {
                        frontOfAisle = (*obstacleCoords)[j].coordinates[0];
                    }
                }
            }
            else if((*obstacleCoords)[j].coordinates[0] < aisles[i])
            {
                if((*obstacleCoords)[j].coordinates[1] < 1.73 
                    && (*obstacleCoords)[j].coordinates[1] > -1.73)
                {
                    if(backOfAisle == -1)
                    {
                        backOfAisle = (*obstacleCoords)[j].coordinates[0];
                    }

                    else if((aisles[i] - (*obstacleCoords)[j].coordinates[0])
                        < (aisles[i] - backOfAisle))
                    {
                        backOfAisle = (*obstacleCoords)[j].coordinates[0];
                    }
                }
            }
        }

        /*std::cout << "Aisle " << i << " back" << backOfAisle //testing statement -EL
            << ": front " << frontOfAisle << std::endl;*/ 
        aisleSize.push_back(frontOfAisle-backOfAisle);
    }

    /*for (int i = 0; i < numAisles; ++i) //testing loop -EL
    {
        std::cout << "Aisle size" << i << ": " << AisleSize[i] << std::endl;
    }*/

    dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)->setAisles(aisles);
    dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)->setAislesSize(aisleSize);
    dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)->setNumAisles(numAisles);
}

MovementDefinitions CalmPedestrianModel::updateMovementState
    (int pedestrianIndex)
{
    MovementDefinitions newDefinition;
    if((*this->pedestrianSet->getPriorities())[pedestrianIndex]
        < this->currentPriority 
        && ((*this->pedestrianSet->getPedestrianCoordinates())
        [pedestrianIndex].coordinates[0]
        >= ((*dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)->getAisles())
        [(*this->pedestrianSet->getStartingAisles())[pedestrianIndex]]
        + ((*dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)->getAislesSize())
        [(*this->pedestrianSet->getStartingAisles())[pedestrianIndex]] / 2)
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

bool CalmPedestrianModel::updatePriority(int pedestrianIndex)
{

    bool currentPriorityActive = false;

    if((*this->pedestrianSet->getPriorities())[pedestrianIndex]
        == this->currentPriority)
    {
        currentPriorityActive = true;
    }

    return currentPriorityActive;

}