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
    calculateNearestPedNeighbors();
    this->goals->determinePedestrianGoals();
    calculatePropulsion();
    calculateRepulsion();
}

void CalmPedestrianModel::update(FLOATING_NUMBER time)
{
    CalmPedestrianSet* set = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());
    
     ObstacleSet* obSet = dynamic_cast<ObstacleSet*>(
        this->data->getObstacleSet());


    FLOATING_NUMBER speed;
    FLOATING_NUMBER distanceMoved;
    std::vector<Dimensions> movedCoordinates;

    std::vector<FLOATING_NUMBER> speedMetersPerSecond;
    
    for(int i = 0; i < set->getNumPedestrians(); ++i)
    {
        if((*set->getGoalCoordinates())[i].coordinates[0] == (*set->getPedestrianCoordinates())[i].coordinates[0]
        && (*set->getGoalCoordinates())[i].coordinates[1] == 0)
        {
            if((*set->getMovementStates())[
                (*set->getNearestPedNeighbors())[i]]
                == MovementDefinitions::STOP && this->calculateDistance(i,
                (*set->getNearestPedNeighbors())[i], "P") < 0.2)
            {
                speed = 0;
                speedMetersPerSecond.push_back(speed);
                distanceMoved = speed * time;

                movedCoordinates.push_back
                    (
                        Dimensions 
                        {
                            std::vector<FLOATING_NUMBER>
                            {
                                (*set->getPedestrianCoordinates())[i].coordinates[0],
                                (*set->getPedestrianCoordinates())[i].coordinates[1] + distanceMoved
                            }
                        }
                    );
            }

            else
            {
                speed =  ((*set->getPropulsionForces())[i] + (*set->getRepulsionForces())[i]);
                speedMetersPerSecond.push_back(speed);
                distanceMoved = speed * time;
                
                if((*set->getPedestrianCoordinates())[i].coordinates[1] < 0)
                {
                        movedCoordinates.push_back
                        (
                            Dimensions 
                            {
                                std::vector<FLOATING_NUMBER>
                                {
                                    (*set->getPedestrianCoordinates())[i].coordinates[0],
                                    (*set->getPedestrianCoordinates())[i].coordinates[1] + distanceMoved
                                }
                            }
                        );
                }
                
                else if((*set->getPedestrianCoordinates())[i].coordinates[1] > 0)
                {

                    movedCoordinates.push_back
                    (
                        Dimensions 
                        {
                        std::vector<FLOATING_NUMBER> 
                            {
                                (*set->getPedestrianCoordinates())[i].coordinates[0],
                                (*set->getPedestrianCoordinates())[i].coordinates[1] - distanceMoved
                            }
                        }
                    );

                }
            }
        }

        else if((*set->getGoalCoordinates())[i].coordinates[0] == (this->getGoals()->getPedExitGoal(i)).coordinates[0]
        && (*set->getGoalCoordinates())[i].coordinates[1] == 0)
        {
            if((*set->getPriorities())[i] > currentPriority)
            {
                if((*set->getPedestrianCoordinates())[i].coordinates[0] < 
                ((*obSet->getAisles())[(*set->getStartingAisles())[i]] + 
                (*obSet->getAislesSize())[(*set->getStartingAisles())[i]]))
                {
                    if((*set->getMovementStates())[
                        (*set->getNearestPedNeighbors())[i]]
                        == MovementDefinitions::STOP && this->calculateDistance(i,
                        (*set->getNearestPedNeighbors())[i], "P") < 0.2)
                    {
                        speed = 0;
                        speedMetersPerSecond.push_back(speed);
                        distanceMoved = speed * time;

                        movedCoordinates.push_back
                        (
                            Dimensions 
                            {
                                std::vector<FLOATING_NUMBER>
                                {
                                    (*set->getPedestrianCoordinates())[i].coordinates[0] + distanceMoved,
                                    (*set->getPedestrianCoordinates())[i].coordinates[1]
                                }
                            }
                        );
                    }

                    else
                    {
                        speed =  ((*set->getPropulsionForces())[i] + (*set->getRepulsionForces())[i]);
                        speedMetersPerSecond.push_back(speed);
                        distanceMoved = speed * time;
                        movedCoordinates.push_back
                        (
                            Dimensions 
                            {
                                std::vector<FLOATING_NUMBER>
                                {
                                    (*set->getPedestrianCoordinates())[i].coordinates[0] + distanceMoved,
                                    (*set->getPedestrianCoordinates())[i].coordinates[1]
                                }
                            }
                        );
                    }
                }

                else
                {
                    speed = 0;
                    speedMetersPerSecond.push_back(speed);
                    distanceMoved = speed * time;

                    movedCoordinates.push_back
                    (
                        Dimensions 
                        {
                            std::vector<FLOATING_NUMBER>
                            {
                                (*set->getPedestrianCoordinates())[i].coordinates[0] + distanceMoved,
                                (*set->getPedestrianCoordinates())[i].coordinates[1]
                            }
                        }
                    );
                }

            }
            else
            {
                speed =  ((*set->getPropulsionForces())[i] + (*set->getRepulsionForces())[i]);
                speedMetersPerSecond.push_back(speed);
                distanceMoved = speed * time;
                movedCoordinates.push_back
                (
                    Dimensions 
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            (*set->getPedestrianCoordinates())[i].coordinates[0] + distanceMoved,
                            (*set->getPedestrianCoordinates())[i].coordinates[1]
                        }
                    }
                );
            }
            
        }
        else if((*set->getGoalCoordinates())[i].coordinates[0] == (this->getGoals()->getPedExitGoal(i)).coordinates[0]
        && (*set->getGoalCoordinates())[i].coordinates[1] == (this->getGoals()->getPedExitGoal(i)).coordinates[1])
        {

            if((*set->getMovementStates())[
                (*set->getNearestPedNeighbors())[i]]
                == MovementDefinitions::STOP && this->calculateDistance(i,
                (*set->getNearestPedNeighbors())[i], "P") < 0.2)
            {
                speed = 0;
                speedMetersPerSecond.push_back(speed);
                distanceMoved = speed * time;

                movedCoordinates.push_back
                (
                    Dimensions 
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            (*set->getPedestrianCoordinates())[i].coordinates[0],
                            (*set->getPedestrianCoordinates())[i].coordinates[1] + distanceMoved
                        }
                    }
                );
            }

            else
            {
                speed =  ((*set->getPropulsionForces())[i] + (*set->getRepulsionForces())[i]);
                speedMetersPerSecond.push_back(speed);
                distanceMoved = speed * time;
                movedCoordinates.push_back
                (
                    Dimensions 
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            (*set->getPedestrianCoordinates())[i].coordinates[0],
                            (*set->getPedestrianCoordinates())[i].coordinates[1] + distanceMoved
                        }
                    }
                );
            }
            
            if(this->goals->checkPedestianGoalsMet(i))
            {
                set->removePedestrian(i);
                std::cout << "check removed\n";
            }
        }

    }

    set->setPedestrianCoordinates(movedCoordinates);
    set->setSpeeds(speedMetersPerSecond);

}

void CalmPedestrianModel::calculatePropulsion()
{
    CalmPedestrianSet* set = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());

    for(int i = 0; i < set->getNumPedestrians(); ++i)
    {
        /*std::cout << "ped: " << i << "  Desired speed: " << 
        (*set->getDesiredSpeeds())[i] << "  current speed: " << 
        (*set->getSpeeds())[i] << "  reaction time: " << 
        (*set->getReactionTimes())[i] <<
        "  mass: " << (*set->getMasses())[i] << std::endl;

        std::cout << "V0i - Vi = " << (*set->getDesiredSpeeds())[i]
                    - (*set->getSpeeds())[i] << std::endl;

        std::cout << "(V0i - Vi)/reaction time = " << ((*set->getDesiredSpeeds())[i]
                    - (*set->getSpeeds())[i]) / (*set->getReactionTimes())[i] << std::endl;*/ //testing for Ashok -EL

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
                            calculateBeta(i) -1
                        )
                        * (*set->getDesiredSpeeds())[i]
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

    /*std::cout << "ped :" << pedIndex << "  nearest neighbor: " 
    << nearestNeighhborIndex << "  neighbor type: " 
    << nearestNeighborOrigin << "  a: " << this->a
    << "  b:" << this->b << "  c: " << this->c << "  distance between neighbors: " 
    << distance <<std::endl;

    std::cout << "Beta = " << c - exp(a * distance) << std::endl;*/ //tesing for Dr. s -EL

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

    std::vector<std::pair<std::string, int>> nearestNeighbors;


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
        /*std::cout 
            << i << "dist:" << calculateDistance(i, nearest, originSet) 
            << std::endl;*/
        
        (nearestNeighbors.push_back(std::make_pair(
            std::string(originSet), nearest)));
    }

    pedSet->setNearestNeighbors(nearestNeighbors);
}

void CalmPedestrianModel::calculateNearestPedNeighbors()
{

    CalmPedestrianSet* pedSet = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());

    std::vector<int> nearestPedNeighbor;

    for (int i = 0; i < pedSet->getNumPedestrians(); ++i)
    {
        int nearest = -1;

        std::string originSet = "P";

        for (int j = 0; j < pedSet->getNumPedestrians(); ++j)
        {
            if (i != j && neighborDirectionTest(i, j, originSet))
            {
                if(nearest == -1 || calculateDistance(i, j, originSet) < 
                    calculateDistance(i, nearest, originSet)
                    )
                {
                    nearest = j;
                }
            }
        }
        /*std::cout << i << "dist:" << calculateDistance(i, nearest, originSet)
            << std::endl;*/
        
        nearestPedNeighbor.push_back(nearest);
    }
    pedSet->setNearestPedNeighbors(nearestPedNeighbor);
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
    std::vector<FLOATING_NUMBER>* Aisles = obSet->getAisles();
    std::vector<FLOATING_NUMBER>* AislesSize = obSet->getAislesSize();
    int numAisles = obSet->getNumAisles();

    //std::cout << numAisles; //testing statement -El

    std::vector<FLOATING_NUMBER> priorities;
    std::vector<int> startingAisles; //maybe move somewhere else? might not fit into this method - Elizabeth
     for(int i = 0; i < pedSet->getNumPedestrians(); ++i)
     {
        bool prioritySet = false;
        for(int j = 0; prioritySet == false && j < numAisles; ++j)
        {
            if((*pedCoords)[i].coordinates[0] < ((*Aisles)[j] + ((*AislesSize)[j]/2))
            &&(*pedCoords)[i].coordinates[0] > ((*Aisles)[j] - ((*AislesSize)[j]/2)))
            {
                priorities.push_back(j);
                startingAisles.push_back(j);
                break;
            }
        }
     }

     pedSet->setPriorities(priorities);
     pedSet->setStartingAisles(startingAisles);
    

    /*for(int i = 0; i < pedSet->getNumPedestrians(); ++i) //testing loop -EL
     {
         std::cout << "Ped " << i << " priority: " << priorities[i] << std::endl;
     }*/

     this->currentPriority = 0;
}

void CalmPedestrianModel::createAisles() //TODO move this somewhere more approrpriate -EL
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
        /*std::cout << "Aisle " << i << " back" << backOfAisle //testing statement -EL
            << ": front " << frontOfAisle << std::endl;*/
            
        AisleSize.push_back(frontOfAisle-backOfAisle);
    }

    /*for (int i = 0; i < numAisles; ++i) //testing loop -EL
    {
        std::cout << "Aisle size" << i << ": " << AisleSize[i] << std::endl;
    }*/

    obSet->setAisles(Aisles);
    obSet->setAislesSize(AisleSize);
    obSet->setNumAisles(numAisles);
}