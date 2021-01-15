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

    std::vector<std::pair<std::string, int>> nearestNeighbors;
    std::vector<int> nearestPedestrianNeighbor;

    for (int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        this->goals->determinePedestrianGoals();
        nearestNeighbors.push_back(calculateNearestNeighbors(i));
        nearestPedestrianNeighbor.push_back(calculateNearestPedNeighbors(i));
    }

    this->pedestrianSet->setNearestNeighbors(nearestNeighbors);
    this->pedestrianSet->setNearestPedNeighbors(nearestPedestrianNeighbor);

    calculateBeta();
    calculatePropulsion();

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
    this->goals->determinePedestrianGoals();

    for (int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        nearestNeighbors.push_back(calculateNearestNeighbors(i));
        nearestPedestrianNeighbor.push_back(calculateNearestPedNeighbors(i));
        currentPriorityActive = updatePriority(i);
        if(currentPriorityActive == true)
        {
            priorityActiveFlag = true;
        }
        updatedMoveStates.push_back(updateMovementState(i));
    }

    this->pedestrianSet->setNearestNeighbors(nearestNeighbors);

    this->pedestrianSet->setNearestPedNeighbors(nearestPedestrianNeighbor);
    if(priorityActiveFlag == false)
    {
        this->currentPriority--;
        std::cout << currentPriority << std::endl;
    }
    this->pedestrianSet->setMovementStates(updatedMoveStates);

    calculateBeta();
    calculatePropulsion();
  
}

void CalmPedestrianModel::update(FLOATING_NUMBER time)
{


    FLOATING_NUMBER coeff = 0.01; //rename, i dont understand this value -EL

    std::vector<Dimensions> newVelocities;
    std::vector<FLOATING_NUMBER> newSpeeds;
    std::vector<Dimensions> newPositions;

    for (int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        newVelocities.push_back
            (
                Dimensions 
                {
                    std::vector<FLOATING_NUMBER>
                    {
                        (*this->pedestrianSet->getPropulsionForces())[i]
                        .coordinates[0] * (time / 
                        (*this->pedestrianSet->getMasses())[i])
                         + (*this->pedestrianSet->getVelocities())
                         [i].coordinates[0],
                        (*this->pedestrianSet->getPropulsionForces())[i]
                        .coordinates[1] * (time / 
                        (*this->pedestrianSet->getMasses())[i])
                         + (*this->pedestrianSet->getVelocities())
                         [i].coordinates[1]
                    }

                }
            );

        newSpeeds.push_back((newVelocities[i].coordinates[0]
            * newVelocities[i].coordinates[0]) 
            + (newVelocities[i].coordinates[1]
            * newVelocities[i].coordinates[1]));
            
        if(newSpeeds[i] < ((*this->pedestrianSet->getDesiredSpeeds())[i] 
            * (*this->pedestrianSet->getDesiredSpeeds())[i]))
        {
            newPositions.push_back
            (
                Dimensions 
                {
                    std::vector<FLOATING_NUMBER>
                    {
                        (*this->pedestrianSet->getPedestrianCoordinates())[i]
                        .coordinates[0] + (newVelocities[i].coordinates[0] * time),
                        (*this->pedestrianSet->getPedestrianCoordinates())[i]
                        .coordinates[1] + (newVelocities[i].coordinates[1] * time)

                    }
                }   
            );
        }

        else
        {
            newPositions.push_back
            (
                Dimensions 
                {
                    std::vector<FLOATING_NUMBER>
                    {
                        (*this->pedestrianSet->getPedestrianCoordinates())
                        [i].coordinates[0] + (newVelocities[i].coordinates
                        [0] * ((*this->pedestrianSet->getDesiredSpeeds())
                        [i] / (newSpeeds[i]+coeff)) * time),
                        (*this->pedestrianSet->getPedestrianCoordinates())
                        [i].coordinates[1] + (newVelocities[i].coordinates
                        [1] * ((*this->pedestrianSet->getDesiredSpeeds())
                        [i] / (newSpeeds[i]+coeff)) * time)

                    }
                }   
            );
                
        }
            
    }

    this->pedestrianSet->setPedestrianCoordinates(newPositions);
    this->pedestrianSet->setSpeeds(newSpeeds);

}

void CalmPedestrianModel::calculatePropulsion()
{    

    std::vector<Dimensions> newVelocities;
    std::vector<Dimensions> newPropulsiveForces;
    
    for(int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {

        if((*this->pedestrianSet->getMovementStates())[i]
                == MovementDefinitions::STOP 
                || (*this->pedestrianSet->getMovementStates())[i]
                == MovementDefinitions::PAUSE)
        {

            newVelocities.push_back
            (
                Dimensions 
                {
                    std::vector<FLOATING_NUMBER>
                    {
                        0,
                        0
                    }
                }
            );
        }
        
        else if ((*this->pedestrianSet->getMovementStates())[i]
                    == MovementDefinitions::PED_DYNAM)
        {
            if((*this->pedestrianSet->getGoalCoordinates())[i].coordinates[0]
                == (*this->pedestrianSet->getPedestrianCoordinates())[i]
                .coordinates[0] && (*this->pedestrianSet->getGoalCoordinates())
                [i].coordinates[1] == 0)
            {
                
                if((*this->pedestrianSet->getPedestrianCoordinates())[i]
                    .coordinates[1] < 0)
                {
                    newVelocities.push_back
                    (
                        Dimensions 
                        {
                            std::vector<FLOATING_NUMBER>
                            {
                                0 * (*this->pedestrianSet->getDesiredSpeeds())[i],
                                1 * (*this->pedestrianSet->getDesiredSpeeds())[i]
                            }
                        }
                    );
                }
                
                else if((*this->pedestrianSet->getPedestrianCoordinates())[i]
                    .coordinates[1] > 0)
                {

                    newVelocities.push_back
                    (
                        Dimensions 
                        {
                            std::vector<FLOATING_NUMBER> 
                            {
                                0 * (*this->pedestrianSet->getDesiredSpeeds())[i],
                                -1 * (*this->pedestrianSet->getDesiredSpeeds())[i]
                            }
                        }
                    );
                }
            }

            else if((*this->pedestrianSet->getGoalCoordinates())[i].coordinates[0]
                == (this->getGoals()->getPedExitGoal(i)).coordinates[0]
                && (*this->pedestrianSet->getGoalCoordinates())[i].coordinates[1] == 0)
            {

                newVelocities.push_back
                (
                    Dimensions 
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            1 * (*this->pedestrianSet->getDesiredSpeeds())[i],
                            0 * (*this->pedestrianSet->getDesiredSpeeds())[i]
                        }
                    }
                );
            }

            else if((*this->pedestrianSet->getGoalCoordinates())[i].coordinates[0]
            == (this->getGoals()->getPedExitGoal(i)).coordinates[0]
            && (*this->pedestrianSet->getGoalCoordinates())[i].coordinates[1]
            == (this->getGoals()->getPedExitGoal(i)).coordinates[1])
            {
            
                newVelocities.push_back
                (
                    Dimensions 
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            0 * (*this->pedestrianSet->getDesiredSpeeds())[i],
                            1 * (*this->pedestrianSet->getDesiredSpeeds())[i]
                        }
                    }
                );
            }
        }
            
        if(this->goals->checkPedestianGoalsMet(i)) //TODO: move somewhere more appropriate - EL
        {
            this->pedestrianSet->removePedestrian(i);
        }

        newPropulsiveForces.push_back
        (
            Dimensions
            {
                std::vector<FLOATING_NUMBER>
                {
                    (newVelocities[i].coordinates[0] - (*this->pedestrianSet->
                    getVelocities())[i].coordinates[0]) * 
                    (*this->pedestrianSet->getMasses())[i] 
                    / (*this->pedestrianSet->getReactionTimes())[i],
                    (newVelocities[i].coordinates[1] - (*this->pedestrianSet->
                    getVelocities())[i].coordinates[1]) * 
                    (*this->pedestrianSet->getMasses())[i] 
                    / (*this->pedestrianSet->getReactionTimes())[i]

                }
            }
        );

    }

    this->pedestrianSet->setVelocities(newVelocities);
    this->pedestrianSet->setPropulsionForces(newPropulsiveForces);
}

void CalmPedestrianModel::calculateBeta()
{
    std::vector<FLOATING_NUMBER> newDesiredSpeeds;
    for (int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        //std::cout << "check beta: " << i << std::endl;
        /*if(i == 140)
        {
            std::cout << "140 check: ";
            std::cout << (*this->pedestrianSet->getNearestNeighbors())[i]
                .second << "+" << (*this->pedestrianSet->getNearestNeighbors())[i].first << std::endl;
            std::cout << (*this->pedestrianSet->getGoalCoordinates())[i].coordinates[0] << "x+" <<
                (*this->pedestrianSet->getGoalCoordinates())[i].coordinates[1] << std::endl;
        }*/
        int nearestNeighhborIndex 
            = (*this->pedestrianSet->getNearestNeighbors())[i]
                .second;
        std::string nearestNeighborOrigin = 
            (*this->pedestrianSet->getNearestNeighbors())[i].first;

        FLOATING_NUMBER distanceMinusB = (calculateDistance(
            i, 
            FLOATING_NUMBER(nearestNeighhborIndex),
            nearestNeighborOrigin
            ) - b);
        

    newDesiredSpeeds.push_back(0.4 * (c - exp(a * distanceMinusB))); //TODO - fix the coeff to change depending on goal -EL
    }
    this->pedestrianSet->setDesiredSpeeds(newDesiredSpeeds);
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
    std::pair<std::string, int> newNearestNeighbor;

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
            << pedIndex << "dist:" << calculateDistance(pedIndex, nearest, originSet)
            << std::endl;*/

    if(nearest == -1)
    {
        newNearestNeighbor = std::make_pair((*this->pedestrianSet->getNearestNeighbors())
            [pedestrianIndex].first, (*this->pedestrianSet->
            getNearestNeighbors())[pedestrianIndex].second);
    }
    else
    {
         newNearestNeighbor = std::make_pair(std::string(originSet), nearest);
    }
    
        
    return newNearestNeighbor;

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
    
    if(nearest == -1)
    {
        nearest = (*this->pedestrianSet->getNearestPedNeighbors())[pedestrianIndex];
    }

    return nearest;

}

bool CalmPedestrianModel::neighborDirectionTest(
    int firstPedestrianIndex, int secondPedestrianIndex, std::string originSet)
{

    bool pass = false;

    std::vector<Dimensions>* firstPedestriancoords 
        = this->pedestrianSet->getPedestrianCoordinates();
    std::vector<Dimensions>* secondPedestriancoords //TODO:fix name -EL
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

    if(goalXDirection > 0 && (goalYDirection <= 0.011 && goalYDirection >= -0.011))
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
    else if (goalXDirection < 0 && (goalYDirection <= 0.011 && goalYDirection >= -0.011))
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
    else if ((goalXDirection <= 0.011 && goalXDirection >= -0.011) && goalYDirection > 0)
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
    else if ((goalXDirection <= 0.011 && goalXDirection >= -0.011) && goalYDirection < 0)
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
    
    std::vector<Dimensions>* pedestrianCoords 
        = this->pedestrianSet->getPedestrianCoordinates();
    std::vector<FLOATING_NUMBER>* Aisles = this->obstacleSet->getAisles();
    std::vector<FLOATING_NUMBER>* AislesSize 
        = this->obstacleSet->getAislesSize();
    int numAisles = this->obstacleSet->getNumAisles();

    //std::cout << numAisles; //testing statement -El

    std::vector<FLOATING_NUMBER> priorities;
    std::vector<int> startingAisles; //maybe move somewhere else? 
                                    //might not fit into this method - EL
     for(int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
     {
        bool prioritySet = false;
        for(int j = 0; prioritySet == false && j < numAisles; ++j)
        {
            if((*pedestrianCoords)[i].coordinates[0] < ((*Aisles)[j] 
            + ((*AislesSize)[j]/2)) && (*pedestrianCoords)[i].coordinates[0]
            > ((*Aisles)[j] - ((*AislesSize)[j]/2)))
            {
                priorities.push_back(j);
                startingAisles.push_back(j);
                break;
            }
        }
     }

     this->pedestrianSet->setPriorities(priorities);
     this->pedestrianSet->setStartingAisles(startingAisles);
    

    /*for(int i = 0; i < pedSet->getNumPedestrians(); ++i) //testing loop -EL
     {
         std::cout << "Ped " << i << " priority: " << priorities[i] << std::endl;
     }*/

     this->currentPriority = 24; //hardcoded! fix this -EL
}

void CalmPedestrianModel::createAisles() //TODO move this somewhere more approrpriate -EL
{
    
    std::vector<Dimensions>* pedestrianCoords 
        = this->pedestrianSet->getPedestrianCoordinates();
    std::vector<Dimensions>* obstacleCoords 
        = this->obstacleSet->getObstacleCoordinates();

    std::vector<FLOATING_NUMBER> Aisles;
    std::vector<FLOATING_NUMBER> AisleSize;
    int numAisles = 0;

    for(int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        bool duplicateCheck = true;

        if(i == 0)
        {
            Aisles.push_back((*pedestrianCoords)[i].coordinates[0]);
            ++numAisles;
        }

        else
        {
            for(int j = 0; j < numAisles; ++j)
            {
                if((*pedestrianCoords)[i].coordinates[0] == Aisles[j])
                {
                    duplicateCheck = false;
                }
            }

            if(duplicateCheck == true)
            {
                Aisles.push_back((*pedestrianCoords)[i].coordinates[0]);
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
            if((*obstacleCoords)[j].coordinates[0] > Aisles[i])
            {
                //TODO fix this so it's not hard coded! - Elizabeth
                if((*obstacleCoords)[j].coordinates[1] < 1.73 
                && (*obstacleCoords)[j].coordinates[1] > -1.73)
                {
                    if(frontOfAisle == -1)
                    {
                        frontOfAisle = (*obstacleCoords)[j].coordinates[0];
                    }
                    else if(((*obstacleCoords)[j].coordinates[0] - Aisles[i])
                        < (frontOfAisle - Aisles[i]))
                    {
                        frontOfAisle = (*obstacleCoords)[j].coordinates[0];
                    }
                }
            }
            else if((*obstacleCoords)[j].coordinates[0] < Aisles[i])
            {
                if((*obstacleCoords)[j].coordinates[1] < 1.73 
                    && (*obstacleCoords)[j].coordinates[1] > -1.73)
                {
                    if(backOfAisle == -1)
                    {
                        backOfAisle = (*obstacleCoords)[j].coordinates[0];
                    }

                    else if((Aisles[i] - (*obstacleCoords)[j].coordinates[0])
                        < (Aisles[i] - backOfAisle))
                    {
                        backOfAisle = (*obstacleCoords)[j].coordinates[0];
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

    this->obstacleSet->setAisles(Aisles);
    this->obstacleSet->setAislesSize(AisleSize);
    this->obstacleSet->setNumAisles(numAisles);
}

MovementDefinitions CalmPedestrianModel::updateMovementState
    (int pedestrianIndex)
{
    
    MovementDefinitions newDefinition;
    if((*this->pedestrianSet->getPriorities())[pedestrianIndex]
        < this->currentPriority 
        && ((*this->pedestrianSet->getPedestrianCoordinates())
        [pedestrianIndex].coordinates[0]
        >= ((*this->obstacleSet->getAisles())
        [(*this->pedestrianSet->getStartingAisles())[pedestrianIndex]]
        + ((*this->obstacleSet->getAislesSize())
        [(*this->pedestrianSet->getStartingAisles())[pedestrianIndex]] / 2)
        - 0.1)))
    {
        newDefinition = MovementDefinitions::STOP;
    }

    else
    {
        if(calculateDistance(pedestrianIndex, 
        (*this->pedestrianSet->getNearestPedNeighbors())[pedestrianIndex],
        "P") < 0.2)
        {
            if(((*this->pedestrianSet->getMovementStates())
                [(*this->pedestrianSet->getNearestPedNeighbors())[pedestrianIndex]]
                == MovementDefinitions::STOP))
            {
                newDefinition = MovementDefinitions::STOP;
            }
            else if(((*this->pedestrianSet->getMovementStates())
                [(*this->pedestrianSet->getNearestPedNeighbors())[pedestrianIndex]]
                == MovementDefinitions::PAUSE))
            {
                newDefinition = MovementDefinitions::PED_DYNAM;
            }
            else
            {
                newDefinition = MovementDefinitions::PAUSE;
            }
        }
        else
        {
            newDefinition = MovementDefinitions::PED_DYNAM;
        }
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