#include <cfloat>
#include "calm_pedestrian_model.hpp"

void CalmPedestrianModel::configure(CONFIG_MAP* configMap)
{

}

//Using local variables in CALM Model to increase performance
//This approach does add more overhead in initialize and precompute
void CalmPedestrianModel::initialize()
{
    this->pedestrianSet = dynamic_cast<CalmPedestrianSet*>(
        this->data->getPedestrianSet());
    this->obstacleSet = dynamic_cast<ObstacleSet*>(
        this->data->getObstacleSet());

    this->numPedestrians = this->data->getPedestrianSet()->getNumPedestrians();
    this->numObstacles = this->data->getObstacleSet()->getNumObstacles();
    this->pedestrianDistanceMatrix = new FLOATING_NUMBER[numPedestrians * numPedestrians];
    this->obstacleDistanceMatrix = new FLOATING_NUMBER[numPedestrians * numObstacles];
    this->pedestrianCoordinates = *this->pedestrianSet->getPedestrianCoordinates();
    this->obstacleCoordinates = *this->obstacleSet->getObstacleCoordinates();
    this->calculateDistanceMatrices();

    this->moveStates = *this->pedestrianSet->getMovementStates();
    this->propulsionForces = *this->pedestrianSet->getPropulsionForces();
    this->velocities = *this->pedestrianSet->getVelocities();
    this->masses = *this->pedestrianSet->getMasses();
    this->desiredSpeeds = *this->pedestrianSet->getDesiredSpeeds();
    this->goalCoordinates = *this->pedestrianSet->getGoalCoordinates();
    this->reactionTimes = *this->pedestrianSet->getReactionTimes();
    this->shoulderLengths = *this->pedestrianSet->getShoulderLengths();


    createAisles();
    calculatePriority();

    std::vector<std::pair<std::string, int>> nearestNeighbors;

    FLOATING_NUMBER pedestrianDisplacementX;
    FLOATING_NUMBER pedestrianDisplacementY;

    for (int i = 0; i < numPedestrians; ++i)
    {
        this->goals->determinePedestrianGoals();
        pedestrianDisplacementX = 
            pedestrianCoordinates[i].coordinates[0];
        pedestrianDisplacementY =
            pedestrianCoordinates[i].coordinates[1];

        nearestNeighbors.push_back(calculateNearestNeighbors(i, pedestrianDisplacementX, pedestrianDisplacementY));
    }

    this->pedestrianSet->setNearestNeighbors(nearestNeighbors);

    this->nearestNeighbors = *this->pedestrianSet->getNearestNeighbors();

    calculateBeta();
    calculatePropulsion();

    this->propulsionForces = *this->pedestrianSet->getPropulsionForces();
    this->velocities = *this->pedestrianSet->getVelocities();
    this->desiredSpeeds = *this->pedestrianSet->getDesiredSpeeds();
    
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
    //Decrease Force 0.000859424and Propulsion force in CALM code
    //result needs to be stored for each passenger
    //this->pedestrianSet->getShoulderLengths()

    std::vector<std::pair<std::string, int>> nearestNeighbors;
    bool currentPriorityActive = false;
    bool priorityActiveFlag = false;
    std::vector<MovementDefinitions> updatedMoveStates;
    this->goals->determinePedestrianGoals();

    std::vector<int> pedestriansToRemove;

        for(int i = 0; i < this->numPedestrians; ++i)
        {
            if(this->goals->checkPedestianGoalsMet(i)) //fix maybe
            {
                pedestriansToRemove.push_back(i);
            }
        }

        for(auto iter = pedestriansToRemove.begin();
                 iter != pedestriansToRemove.end();
                 iter++)
        {
                this->pedestrianSet->removePedestrian(*iter);
        }


        this->numPedestrians -= pedestriansToRemove.size();

        this->goalCoordinates = *this->pedestrianSet->getGoalCoordinates();
        this->velocities = *this->pedestrianSet->getVelocities();
        this->pedestrianCoordinates = *this->pedestrianSet->getPedestrianCoordinates();
        this->obstacleCoordinates = *this->obstacleSet->getObstacleCoordinates();



    calculateDistanceMatrices();


    FLOATING_NUMBER pedestrianDisplacementX;
    FLOATING_NUMBER pedestrianDisplacementY;

    for (int i = 0; i < this->numPedestrians; ++i)
    {

        pedestrianDisplacementX = 
            pedestrianCoordinates[i].coordinates[0];
        pedestrianDisplacementY =
            pedestrianCoordinates[i].coordinates[1];
        nearestNeighbors.push_back(calculateNearestNeighbors(i, pedestrianDisplacementX, pedestrianDisplacementY));
        currentPriorityActive = updatePriority(i);
        if(currentPriorityActive == true)
        {
            priorityActiveFlag = true;
        }
        updatedMoveStates.push_back(updateMovementState(i));
    }

    this->pedestrianSet->setNearestNeighbors(nearestNeighbors);
    this->nearestNeighbors = *this->pedestrianSet->getNearestNeighbors();

    if(priorityActiveFlag == false)
    {
        this->currentPriority--;
        std::cout << "current priority: " << currentPriority << std::endl;
    }

    this->pedestrianSet->setMovementStates(updatedMoveStates);

    this->moveStates = *this->pedestrianSet->getMovementStates();

    calculateBeta();
    this->desiredSpeeds = *this->pedestrianSet->getDesiredSpeeds();

    calculatePropulsion();
    this->propulsionForces = *this->pedestrianSet->getPropulsionForces();

}

void CalmPedestrianModel::update(FLOATING_NUMBER time)
{

    FLOATING_NUMBER coeff = 0.01; //rename, i dont understand this value -EL

    Dimensions newVelocity;
    FLOATING_NUMBER newSpeed;
    Dimensions newPosition;

    for (int i = 0; i < this->numPedestrians; ++i)
    {

      MovementDefinitions currentState = this->moveStates[i];
      FLOATING_NUMBER propulsiveX = this->propulsionForces[i].coordinates[0];
      FLOATING_NUMBER propulsiveY = this->propulsionForces[i].coordinates[1];
      FLOATING_NUMBER velocityX = this->velocities[i].coordinates[0];
      FLOATING_NUMBER velocityY = this->velocities[i].coordinates[1];
      FLOATING_NUMBER mass = this->masses[i];
      FLOATING_NUMBER desiredSpeed = this->desiredSpeeds[i];
      FLOATING_NUMBER coordinateX = this->pedestrianCoordinates[i].coordinates[0];
      FLOATING_NUMBER coordinateY = this->pedestrianCoordinates[i].coordinates[1];



            if(currentState == MovementDefinitions::STOP)
            {
                newVelocity =
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
                newVelocity =
                (
                    Dimensions
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            (propulsiveX * (time / mass) + velocityX),
                            (propulsiveY * (time / mass) + velocityY)
                        }
                    }
                );
            }

            newSpeed = ((newVelocity.coordinates[0]
                * newVelocity.coordinates[0])
                + (newVelocity.coordinates[1]
                * newVelocity.coordinates[1]));

            if(newSpeed < (desiredSpeed * desiredSpeed))
            {
                newPosition =
                    Dimensions
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            (coordinateX + (newVelocity.coordinates[0] * time)),
                            (coordinateY + (newVelocity.coordinates[1] * time))
                        }
                    };
            }

            else
            {
                newPosition =
                    Dimensions
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            coordinateX + (newVelocity.coordinates
                            [0] * (desiredSpeed / (newSpeed+coeff)) * time),
                            coordinateY + (newVelocity.coordinates
                            [1] * (desiredSpeed / (newSpeed+coeff)) * time)
                        }
                    };

            }

        // Update the pedestrianSet inline. Future iterations will return a list of values for all pedestrians so the simulation can set them accordingly.
        this->pedestrianSet->getVelocities()->at(i) = newVelocity;
        this->pedestrianSet->getPedestrianCoordinates()->at(i) = newPosition;
        this->pedestrianSet->getSpeeds()->at(i) = newSpeed;
    }

}

void CalmPedestrianModel::calculatePropulsion()
{
    Dimensions newVelocity;
    Dimensions newPropulsiveForce;
    FLOATING_NUMBER xAisleCoefficent = 0.5;
    FLOATING_NUMBER yAisleCoefficent = 0.9;

    for(int i = 0; i < this->numPedestrians; ++i)
    {
        newVelocity = this->pedestrianSet->getVelocities()->at(i);
        newPropulsiveForce = this->pedestrianSet->getPropulsionForces()->at(i);

        MovementDefinitions currentState = this->moveStates[i];
        FLOATING_NUMBER goalX = this->goalCoordinates[i].coordinates[0];
        FLOATING_NUMBER goalY = this->goalCoordinates[i].coordinates[1];
        FLOATING_NUMBER coordinateX = this->pedestrianCoordinates[i].coordinates[0];
        FLOATING_NUMBER coordinateY = this->pedestrianCoordinates[i].coordinates[1];
        FLOATING_NUMBER mass = this->masses[i];
        FLOATING_NUMBER desiredSpeed = this->desiredSpeeds[i];
        FLOATING_NUMBER velocityX = this->velocities[i].coordinates[0];
        FLOATING_NUMBER velocityY = this->velocities[i].coordinates[1];
        FLOATING_NUMBER reactionTime = this->reactionTimes[i];

        if(currentState == MovementDefinitions::STOP)
        {

            newVelocity =
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

        else if (currentState == MovementDefinitions::PED_DYNAM)
        {
            if(goalX == coordinateX && goalY == 0)
            {

                if(coordinateY < 0)
                {
                    newVelocity =
                    (
                        Dimensions
                        {
                            std::vector<FLOATING_NUMBER>
                            {
                                0 * desiredSpeed,
                                desiredSpeed
                            }
                        }
                    );
                }

                // Possible bug: We do not check the case where the coordinate is exactly 0
                else if(coordinateY > 0)
                {

                    newVelocity =
                    (
                        Dimensions
                        {
                            std::vector<FLOATING_NUMBER>
                            {
                                0 *
                                desiredSpeed,
                                -1.1f *
                                desiredSpeed
                            }
                        }
                    );
                }
            }

            else if(goalX == (this->getGoals()->getPedestrianExitGoal(i)).coordinates[0]
                    && goalY == 0)
                {
                if((coordinateY >= (goalY) + 0.2)
                || (coordinateY <= (goalY) - 0.2))
                {
                    if(coordinateY > 0)
                    {
                        newVelocity = (
                        Dimensions
                        {
                          std::vector<FLOATING_NUMBER>
                          {
                              xAisleCoefficent *
                              desiredSpeed,
                              (-1 * yAisleCoefficent) *
                              desiredSpeed
                          }
                        }
                        );
                    }

                    else
                    {
                        newVelocity = (
                        Dimensions
                        {
                          std::vector<FLOATING_NUMBER>
                          {
                              xAisleCoefficent *
                              desiredSpeed,
                              yAisleCoefficent *
                              desiredSpeed
                          }
                        }
                      );

                    }

                }
                else
                {
                    newVelocity = (
                        Dimensions
                        {
                            std::vector<FLOATING_NUMBER>
                            {
                                1 *
                                desiredSpeed,
                                0 *
                                desiredSpeed
                            }
                        }
                    );
                }
            }

            else if(goalX == (this->getGoals()->getPedestrianExitGoal(i))
            .coordinates[0]
            && goalY == (this->getGoals()->getPedestrianExitGoal(i)).coordinates[1])
            {

                newVelocity =
                (
                    Dimensions
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            0 * desiredSpeed,
                            1 * desiredSpeed
                        }
                    }
                );
            }
        }

        newPropulsiveForce =
        (
            Dimensions
            {
                std::vector<FLOATING_NUMBER>
                {
                    (newVelocity.coordinates[0] - velocityX) * mass / reactionTime,
                    (newVelocity.coordinates[1] - velocityY) * mass / reactionTime

                }
            }
        );
        this->pedestrianSet->getPropulsionForces()->at(i) = newPropulsiveForce;       

    }
}

void CalmPedestrianModel::calculateBeta()
{
    std::vector<FLOATING_NUMBER> newDesiredSpeeds;

    for (int i = 0; i < this->numPedestrians; ++i)
    {

        int nearestNeighborIndex = this->nearestNeighbors[i].second;
        std::string nearestNeighborOrigin = this->nearestNeighbors[i].first;

        FLOATING_NUMBER distanceMinusB = 1;

        if(nearestNeighborIndex == -1)
        {
          distanceMinusB = ((1) - b); //the 1 value needs to be changed -EL
        }

        else
        {
          distanceMinusB = (sqrt(getDistance(
                  i,
                  FLOATING_NUMBER(nearestNeighborIndex),
                  nearestNeighborOrigin
          )) - b);
        }


    newDesiredSpeeds.push_back(0.3 * (c - exp(a * distanceMinusB))); //TODO - fix the coeff to change depending on goal -EL
    }
    this->pedestrianSet->setDesiredSpeeds(newDesiredSpeeds);
}


void CalmPedestrianModel::calculateDistanceMatrices()
{
    

    // Update the pedestrians since they could have been removed from the
    // simulation at this point. Also update the obstacles just in case they
    // can be removed in the future.
    this->numPedestrians = this->data->getPedestrianSet()->getNumPedestrians();
    this->numObstacles = this->data->getObstacleSet()->getNumObstacles();

    //Added firstPedestrianCoordinateX and Y to be used in second for loop
    //Reduces unwanted dereferences -NR
    FLOATING_NUMBER firstPedestrianCoordinateX;
    FLOATING_NUMBER firstPedestrianCoordinateY;

    //Removed sqrt() in n^2 runtime - NR
    //All distances in distance matrices are squared
    for (int i = 0; i < this->numPedestrians; ++i)
    {
        firstPedestrianCoordinateX = this->pedestrianCoordinates.at(i).coordinates[0];
        firstPedestrianCoordinateY = this->pedestrianCoordinates.at(i).coordinates[1];

        for (int j = 0; j < i; ++j)
        {
            FLOATING_NUMBER xDistance =
                    (firstPedestrianCoordinateX -
                    this->pedestrianCoordinates.at(j).coordinates[0]) *
                    (firstPedestrianCoordinateX -
                    this->pedestrianCoordinates.at(j).coordinates[0]);   
            FLOATING_NUMBER yDistance =
                    (firstPedestrianCoordinateY -
                    this->pedestrianCoordinates.at(j).coordinates[1]) * 
                    (firstPedestrianCoordinateY -
                    this->pedestrianCoordinates.at(j).coordinates[1]);
            FLOATING_NUMBER distance = xDistance + yDistance;
            this->pedestrianDistanceMatrix[i * this->numPedestrians + j] =
                    distance;
        }

        // Unlike pedestrians-to-pedestrians, we actually want to fill this
        // entire matrix with values.
        for (int j = 0; j < this->numObstacles; ++j)
        {
            FLOATING_NUMBER xDistance =
                    (firstPedestrianCoordinateX -
                    this->obstacleCoordinates.at(j).coordinates[0]) *
                    (firstPedestrianCoordinateX -
                    this->obstacleCoordinates.at(j).coordinates[0]);
            FLOATING_NUMBER yDistance = 
                    (firstPedestrianCoordinateY -
                    this->obstacleCoordinates.at(j).coordinates[1]) *
                    (firstPedestrianCoordinateY -
                    this->obstacleCoordinates.at(j).coordinates[1]);
            FLOATING_NUMBER distance = xDistance + yDistance;
            this->obstacleDistanceMatrix[i * this->numObstacles + j] =
                    distance;
        }
    }

}

FLOATING_NUMBER CalmPedestrianModel::getPedestrianDistance(int first, int second)
{
    if (first == second)
    {
        // The distance between the pedestrian and itself is always 0
        return 0;
    }

    // Exploit the fact that the distance between a to b is identical to the
    // distance between b to a
    if (first > second)
    {
        return this->pedestrianDistanceMatrix[first * this->numPedestrians +
                                              second];
    }
    else {
        return this->pedestrianDistanceMatrix[second * this->numPedestrians +
                                              first];
    }
}

FLOATING_NUMBER CalmPedestrianModel::getObstacleDistance(int pedestrianIndex, int obstacleIndex)
{
    return this->obstacleDistanceMatrix[pedestrianIndex * this->numObstacles +
                                        obstacleIndex];
}

FLOATING_NUMBER CalmPedestrianModel::getDistance(
    int firstPedestrianIndex, int secondPedestrianIndex, std::string originSet)
{
    if (originSet == "P")
    {
        return getPedestrianDistance(firstPedestrianIndex, secondPedestrianIndex);
    }
    else
    {
        return getObstacleDistance(firstPedestrianIndex, secondPedestrianIndex);
    }
}

//Added displacement function parameters to be used in neighborDirectionTest and neighborSpacialTest
//This reduces number of dereferences and unwanted function calls -NR
std::pair<std::string, int>
        CalmPedestrianModel::calculateNearestNeighbors(
            int pedestrianIndex, FLOATING_NUMBER pedestrianDisplacementX, FLOATING_NUMBER pedestrianDisplacementY)
{
    const int NOT_FOUND = -1;

    int nearest = NOT_FOUND;
    std::string originSet = "P";
    FLOATING_NUMBER nearestDistance = FLT_MAX;

    if ((this->moveStates)[pedestrianIndex]
          == MovementDefinitions::STOP)
    {
        //return NOT_FOUND pedestrian if pedestrian is stopped 
        return std::make_pair(std::string(originSet), nearest);
    }

    std::pair<std::string, int> newNearestNeighbor;


    int localNearest = NOT_FOUND;
    std::string localOriginSet = "P";
    FLOATING_NUMBER localNearestDistance = FLT_MAX;

    FLOATING_NUMBER pedestrianShoulderLength = this->shoulderLengths.at(pedestrianIndex);


    for (int j = 0; j < numObstacles; ++j)
    {
        if (pedestrianIndex != j && j < numPedestrians &&
            neighborDirectionTest(pedestrianIndex, j, pedestrianDisplacementX, pedestrianDisplacementY,
                (this->pedestrianCoordinates)[j].coordinates[0], (this->pedestrianCoordinates)[j].coordinates[1]) &&
            neighborSpacialTest(pedestrianIndex, j, pedestrianDisplacementX, pedestrianDisplacementY,
                (this->pedestrianCoordinates)[j].coordinates[0], (this->pedestrianCoordinates)[j].coordinates[1],
                "P", pedestrianShoulderLength))
        {
            FLOATING_NUMBER distance = getDistance(pedestrianIndex, j, "P");
            if (localNearest == NOT_FOUND
                || distance < localNearestDistance)
            {
                localNearest = j;
                localOriginSet = "P";
                localNearestDistance = distance;
            }
        }

        if (neighborDirectionTest(pedestrianIndex, j, pedestrianDisplacementX, pedestrianDisplacementY, 
                (this->obstacleCoordinates)[j].coordinates[0], (this->obstacleCoordinates)[j].coordinates[1])
            && neighborSpacialTest(pedestrianIndex, j, pedestrianDisplacementX, pedestrianDisplacementY,
                (this->obstacleCoordinates)[j].coordinates[0], (this->obstacleCoordinates)[j].coordinates[1],
                "O", 0))
        {
            FLOATING_NUMBER distance = getDistance(pedestrianIndex, j, "O");
            if (localNearest == NOT_FOUND
                || distance < localNearestDistance)
            {
                localNearest = j;
                localOriginSet = "O";
                localNearestDistance = distance;
            }
        }
    }

    if (localNearestDistance < nearestDistance)
    {
        nearest = localNearest;
        originSet = localOriginSet;
        nearestDistance = localNearestDistance;
    }

    newNearestNeighbor = std::make_pair(std::string(originSet), nearest);

    return newNearestNeighbor;
}

inline bool CalmPedestrianModel::neighborDirectionTest(
    int firstPedestrianIndex, int secondPedestrianIndex, FLOATING_NUMBER pedestrianDisplacementX, FLOATING_NUMBER pedestrianDisplacementY,
        FLOATING_NUMBER secondDisplacementX, FLOATING_NUMBER secondDisplacementY)
{
    
    FLOATING_NUMBER displacementX;
    FLOATING_NUMBER displacementY;
    FLOATING_NUMBER directionX;
    FLOATING_NUMBER directionY;

    FLOATING_NUMBER dotProduct;

    
    displacementX = (pedestrianDisplacementX - secondDisplacementX);
    displacementY = (pedestrianDisplacementY - secondDisplacementY);

    directionX = (this->velocities)[firstPedestrianIndex]
    .coordinates[0];

    directionY = (this->velocities)[firstPedestrianIndex]
    .coordinates[1];

    dotProduct = (displacementX * directionX) + (displacementY * directionY);

    return dotProduct < 0;
}

inline bool CalmPedestrianModel::neighborSpacialTest(int firstPedestrianIndex,
  int secondPedestrianIndex, FLOATING_NUMBER pedestrianDisplacementX, FLOATING_NUMBER pedestrianDisplacementY,
    FLOATING_NUMBER secondDisplacementX, FLOATING_NUMBER secondDisplacementY,
        std::string originSet, FLOATING_NUMBER firstShoulderLength)
{

  FLOATING_NUMBER firstPedestrianDirectionX;
  FLOATING_NUMBER firstPedestrianDirectionY;

  FLOATING_NUMBER secondPedestrianDirectionX;
  FLOATING_NUMBER secondPedestrianDirectionY;

  FLOATING_NUMBER secondShoulderLength = 0;
  FLOATING_NUMBER L;
  FLOATING_NUMBER R;

  int coordinateIndex;



  firstPedestrianDirectionX = std::fabs(
      (this->velocities)[firstPedestrianIndex]
      .coordinates[0]);
  firstPedestrianDirectionY = std::fabs(
      (this->velocities)[firstPedestrianIndex]
      .coordinates[1]);


  if(originSet == "P")
  {
    secondPedestrianDirectionX = std::fabs(
      (this->velocities)[secondPedestrianIndex]
      .coordinates[0]);
    secondPedestrianDirectionY = std::fabs(
      (this->velocities)[secondPedestrianIndex]
      .coordinates[1]);

    if(firstPedestrianDirectionX > firstPedestrianDirectionY
        && secondPedestrianDirectionX > secondPedestrianDirectionY
        || firstPedestrianDirectionY > firstPedestrianDirectionX
        && secondPedestrianDirectionY > secondPedestrianDirectionX)
    {
      secondShoulderLength = this->shoulderLengths.
      at(secondPedestrianIndex);
    }

  }


    FLOATING_NUMBER pedestrianDisplacement;
    FLOATING_NUMBER secondDisplacement;

    //Set pedestrianDisplacement to either the X or Y coordinate if
    //directionX is greater than directionY
    if(firstPedestrianDirectionX > firstPedestrianDirectionY)
    {
        pedestrianDisplacement = pedestrianDisplacementY;
        secondDisplacement = secondDisplacementY;

    }
    else
    {
        pedestrianDisplacement = pedestrianDisplacementX;
        secondDisplacement = secondDisplacementX;
    }

    L = std::max((pedestrianDisplacement - firstShoulderLength),  (secondDisplacement - secondShoulderLength));

    R = std::min((pedestrianDisplacement + firstShoulderLength),  (secondDisplacement + secondShoulderLength));

  return L <= R;
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

        aisleSize.push_back(frontOfAisle-backOfAisle);
    }


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

    MovementDefinitions newDefinition = this->pedestrianSet->getMovementStates()->at(pedestrianIndex);
    if (newDefinition != MovementDefinitions::HUMAN)
    {
        if((*this->pedestrianSet->getPriorities())[pedestrianIndex]
            < this->currentPriority
            && ((*this->pedestrianSet->getPedestrianCoordinates())
            [pedestrianIndex].coordinates[0]
            >= ((*dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)
                ->getAisles())
            [(*this->pedestrianSet->getStartingAisles())[pedestrianIndex]]
            + ((*dynamic_cast<AirplaneObstacleSet*>(this->obstacleSet)
                ->getAislesSize())
            [(*this->pedestrianSet->getStartingAisles())[pedestrianIndex]] * 0.5)
            - 0.1)))
        {
            newDefinition = MovementDefinitions::STOP;
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

CalmPedestrianModel::~CalmPedestrianModel() {
    delete [] obstacleDistanceMatrix;
    delete [] pedestrianDistanceMatrix;
}