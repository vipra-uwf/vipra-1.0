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

    for (int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        this->goals->determinePedestrianGoals();
        nearestNeighbors.push_back(calculateNearestNeighbors(i));
    }

    this->pedestrianSet->setNearestNeighbors(nearestNeighbors);

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
    bool currentPriorityActive = false;
    bool priorityActiveFlag = false;
    std::vector<MovementDefinitions> updatedMoveStates;
    this->goals->determinePedestrianGoals();

    for(int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        if(this->goals->checkPedestianGoalsMet(i))
        {
            this->pedestrianSet->removePedestrian(i);
        }
    }

    for (int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        nearestNeighbors.push_back(calculateNearestNeighbors(i));
        currentPriorityActive = updatePriority(i);
        if(currentPriorityActive == true)
        {
            priorityActiveFlag = true;
        }
        updatedMoveStates.push_back(updateMovementState(i));
    }


    this->pedestrianSet->setNearestNeighbors(nearestNeighbors);

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
        if((*this->pedestrianSet->getMovementStates())[i] 
            == MovementDefinitions::STOP)
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
        else
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
        }

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
                        .coordinates[0] + (newVelocities[i].coordinates[0] 
                        * time),
                        (*this->pedestrianSet->getPedestrianCoordinates())[i]
                        .coordinates[1] + (newVelocities[i].coordinates[1] 
                        * time)

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
    this->pedestrianSet->setVelocities(newVelocities);
    this->pedestrianSet->setPedestrianCoordinates(newPositions);
    this->pedestrianSet->setSpeeds(newSpeeds);

}

void CalmPedestrianModel::calculatePropulsion()
{    

    std::vector<Dimensions> newVelocities;
    std::vector<Dimensions> newPropulsiveForces;
    FLOATING_NUMBER xAisleCoefficent = 0.5;
    FLOATING_NUMBER yAisleCoefficent = 0.9;
    FLOATING_NUMBER stagger_fix = 1.0;
    
    for(int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {

        if((*this->pedestrianSet->getMovementStates())[i]
                == MovementDefinitions::STOP)
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
                                stagger_fix * 
                                (*this->pedestrianSet->getDesiredSpeeds())[i]
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
                                0 * 
                                (*this->pedestrianSet->getDesiredSpeeds())[i],
                                -1 * 
                                (*this->pedestrianSet->getDesiredSpeeds())[i]
                            }
                        }
                    );
                }
            }

            else if((*this->pedestrianSet->
                getGoalCoordinates())[i].coordinates[0]
            == (this->getGoals()->getPedestrianExitGoal(i)).coordinates[0]
            && (*this->pedestrianSet->getGoalCoordinates())[i].coordinates[1]
                == 0)
                if(((*this->pedestrianSet->
                getGoalCoordinates())[i].coordinates[1] 
                >= ((*this->pedestrianSet->getGoalCoordinates())
                [i].coordinates[1]) + 0.4)
                || ((*this->pedestrianSet->
                getGoalCoordinates())[i].coordinates[1] 
                <= ((*this->pedestrianSet->getGoalCoordinates())
                [i].coordinates[1]) - 0.4))
                {
                    newVelocities.push_back(
                    Dimensions 
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            xAisleCoefficent * 
                            (*this->pedestrianSet->getDesiredSpeeds())[i],
                            yAisleCoefficent * 
                            (*this->pedestrianSet->getDesiredSpeeds())[i]
                        }
                    }
                );
                }
                else
                {

                    newVelocities.push_back(
                        Dimensions 
                        {
                            std::vector<FLOATING_NUMBER>
                            {
                                1 * 
                                (*this->pedestrianSet->getDesiredSpeeds())[i],
                                0 * 
                                (*this->pedestrianSet->getDesiredSpeeds())[i]
                            }
                        }
                    );
                }

            else if((*this->pedestrianSet->getGoalCoordinates())[i]
            .coordinates[0] == (this->getGoals()->getPedestrianExitGoal(i))
            .coordinates[0]
            && (*this->pedestrianSet->getGoalCoordinates())[i].coordinates[1]
            == (this->getGoals()->getPedestrianExitGoal(i)).coordinates[1])
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

    this->pedestrianSet->setPropulsionForces(newPropulsiveForces);
}

void CalmPedestrianModel::calculateBeta()
{
    std::vector<FLOATING_NUMBER> newDesiredSpeeds;

    for (int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {

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
        

    newDesiredSpeeds.push_back(0.3 * (c - exp(a * distanceMinusB))); //TODO - fix the coeff to change depending on goal -EL
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

    if(nearest == -1)
    {
        newNearestNeighbor = std::make_pair(
            (*this->pedestrianSet->getNearestNeighbors())
            [pedestrianIndex].first, (*this->pedestrianSet->
            getNearestNeighbors())[pedestrianIndex].second);
    }
    else
    {
         newNearestNeighbor = std::make_pair(std::string(originSet), nearest);
    }
    
        
    return newNearestNeighbor;

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

    if(goalXDirection == 0 && goalYDirection > 0)
    {
        if((*secondPedestriancoords)[secondPedestrianIndex].coordinates[1]
            > (*firstPedestriancoords)[firstPedestrianIndex].coordinates[1]
            && ((*secondPedestriancoords)[secondPedestrianIndex].coordinates[0]
            < (*firstPedestriancoords)[firstPedestrianIndex].coordinates[0] 
            + 0.1
            && (*secondPedestriancoords)[secondPedestrianIndex].coordinates[0]
            > (*firstPedestriancoords)[firstPedestrianIndex].coordinates[0] 
            - 0.1))
        {
            pass = true;
        }
    }
    else if(goalXDirection == 0 && goalYDirection < 0)
    {
        if((*secondPedestriancoords)[secondPedestrianIndex].coordinates[1]
            < (*firstPedestriancoords)[firstPedestrianIndex].coordinates[1]
            && ((*secondPedestriancoords)[secondPedestrianIndex].coordinates[0]
            < (*firstPedestriancoords)[firstPedestrianIndex].coordinates[0] 
            + 0.1
            && (*secondPedestriancoords)[secondPedestrianIndex].coordinates[0]
            > (*firstPedestriancoords)[firstPedestrianIndex].coordinates[0] 
            - 0.1))
        {
            pass = true;
        }
    }
    else if(goalXDirection > 0)
    {
        if((*secondPedestriancoords)[secondPedestrianIndex].coordinates[0]
            > (*firstPedestriancoords)[firstPedestrianIndex].coordinates[0]
            && ((*secondPedestriancoords)[secondPedestrianIndex].coordinates[1]
            < (*firstPedestriancoords)[firstPedestrianIndex].coordinates[1] 
            + 0.1
            && (*secondPedestriancoords)[secondPedestrianIndex].coordinates[1]
            > (*firstPedestriancoords)[firstPedestrianIndex].coordinates[1] 
            - 0.1))
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
    std::vector<FLOATING_NUMBER>* aisles
        = dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)->getAisles();
    std::vector<FLOATING_NUMBER>* aislesSize 
        = dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)->getAislesSize();
    int numAisles 
        = dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)->getNumAisles();

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
            + ((*aislesSize)[j]/2)) && (*pedestrianCoordinates)[i]
            .coordinates[0]> ((*aisles)[j] 
            - ((*aislesSize)[j]/2)))
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

    dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)
        ->setAisles(aisles);
    dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)
        ->setAislesSize(aisleSize);
    dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)
        ->setNumAisles(numAisles);
}

MovementDefinitions CalmPedestrianModel::updateMovementState
    (int pedestrianIndex)
{
    
    MovementDefinitions newDefinition;
    if((*this->pedestrianSet->getPriorities())[pedestrianIndex]
        < this->currentPriority 
        && ((*this->pedestrianSet->getPedestrianCoordinates())
        [pedestrianIndex].coordinates[0]
        >= ((*dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)
            ->getAisles())
        [(*this->pedestrianSet->getStartingAisles())[pedestrianIndex]]
        + ((*dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)
            ->getAislesSize())
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