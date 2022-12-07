#include "calm_pedestrian_model.hpp"

CalmPedestrianModel::CalmPedestrianModel() {

}


void CalmPedestrianModel::initialize(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet, Goals& goals) 
{
    pedestrianSet = static_cast<CalmPedestrianSet&>(pedestrianSet);
    this->pedestrianDistanceMatrix = new FLOATING_NUMBER[pedestrianSet.getNumPedestrians() * pedestrianSet.getNumPedestrians()];
    this->propulsionForces = DimVector(pedestrianSet.getNumPedestrians(), Dimensions{0.0f, 0.0f});
    this->modelState = std::make_shared<State>(pedestrianSet.getNumPedestrians());
}

std::shared_ptr<State> CalmPedestrianModel::timestep(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet,
    Goals& goals, FLOATING_NUMBER time){

    CalmPedestrianSet calmPedestrianSet = static_cast<CalmPedestrianSet&>(pedestrianSet);
    AirplaneObstacleSet airObstacleSet = static_cast<AirplaneObstacleSet&>(obstacleSet);
    CalmGoals calmGoals = static_cast<CalmGoals&>(goals);


    calculateDistanceMatrices(calmPedestrianSet);
    calculateNeartestNeighbors(calmPedestrianSet);
    calculateDesiredSpeeds(calmPedestrianSet, calmGoals);
    calculatePropulsion(calmPedestrianSet, calmGoals);
    updateModelState(calmPedestrianSet, time);
    
    return this->modelState;
}

void CalmPedestrianModel::updateModelState(CalmPedestrianSet& pedestrianSet, FLOATING_NUMBER time) {

    //Need some clarification on why we need this coeff... - NR
    FLOATING_NUMBER coeff = 0.01; 

    DimVector newVelocities = DimVector(pedestrianSet.getNumPedestrians(), Dimensions{0.0f, 0.0f});
    DimVector newPositions = DimVector(pedestrianSet.getNumPedestrians(), Dimensions{0.0f, 0.0f});

    Dimensions newVelocity;
    FLOATING_NUMBER newSpeed;
    Dimensions newPosition;

    int numPedestrians = pedestrianSet.getNumPedestrians();
    for (int i = 0; i < numPedestrians; ++i)
    {

        FLOATING_NUMBER propulsiveX = this->propulsionForces.at(i).axis[0];
        FLOATING_NUMBER propulsiveY = this->propulsionForces[i].axis[1];
        FLOATING_NUMBER velocityX = pedestrianSet.getVelocities()[i].axis[0];
        FLOATING_NUMBER velocityY = pedestrianSet.getVelocities()[i].axis[1];
        FLOATING_NUMBER mass = pedestrianSet.getMasses()[i];
        FLOATING_NUMBER desiredSpeed = pedestrianSet.getDesiredSpeeds()[i];
        FLOATING_NUMBER coordinateX = pedestrianSet.getPedestrianCoordinates()[i].axis[0];
        FLOATING_NUMBER coordinateY = pedestrianSet.getPedestrianCoordinates()[i].axis[1];
            
        newVelocity =
        (
            Dimensions
            {
                (propulsiveX * (time / mass) + velocityX),
                (propulsiveY * (time / mass) + velocityY)
            }
        );
        
        newSpeed = ((newVelocity.axis[0]
            * newVelocity.axis[0])
            + (newVelocity.axis[1]
            * newVelocity.axis[1]));

        if(newSpeed < (desiredSpeed * desiredSpeed))
        {
            newPosition =
                Dimensions
                {
                    (coordinateX + (newVelocity.axis[0] * time)),
                    (coordinateY + (newVelocity.axis[1] * time))   
                };
        } else
        {
            newPosition =
                Dimensions
                {
                    coordinateX + (newVelocity.axis[0] * (desiredSpeed / (newSpeed+coeff)) * time),
                    coordinateY + (newVelocity.axis[1] * (desiredSpeed / (newSpeed+coeff)) * time)
                };
        }

        this->modelState->velocities[i] = newVelocity;
        this->modelState->pedestrianCoordinates[i] = newVelocity;
        this->modelState->affector[i] = Affector::PED_MODEL;
    }

}

//TODO: Add Goals and ObstacleSet to Algorithm
void CalmPedestrianModel::calculateDistanceMatrices(CalmPedestrianSet& pedestrianSet)
{
    // Update the pedestrians since they could have been removed from the
    // simulation at this point. Also update the obstacles just in case they
    // can be removed in the future.
    int numPedestrians = pedestrianSet.getNumPedestrians();

    //Added firstPedestrianCoordinateX and Y to be used in second for loop
    FLOATING_NUMBER firstPedestrianCoordinateX;
    FLOATING_NUMBER firstPedestrianCoordinateY;

    //Updates pedestrian-to-pedestrian distance matrix and pedestrian-to-object distance matrix
    for (int i = 0; i < numPedestrians; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            FLOATING_NUMBER distance = pedestrianSet.getPedestrianCoordinates().at(i)
            .distanceTo(pedestrianSet.getPedestrianCoordinates().at(j));
            
            this->pedestrianDistanceMatrix[(i * numPedestrians) + j] =
                    distance;
        }   
    }

    
}

//TODO: Add Goals and ObstacleSet
void CalmPedestrianModel::calculateNeartestNeighbors(CalmPedestrianSet& pedestrianSet)
{
    int nearestIndex, 
        localNearestIndex;

    std::string originSet, 
                localOriginSet;
 
    FLOATING_NUMBER nearestDistance, 
                    localNearestDistance;

    FLOATING_NUMBER pedestrianShoulderLength;

    FLOATING_NUMBER firstPedestrianX, firstPedestrianY,
                    secondPedestrianX, secondPedestrianY; 


    int numPedestrians = pedestrianSet.getNumPedestrians();
    const int NOT_FOUND = -1;

    for(int pedestrianIndex = 0; pedestrianIndex < numPedestrians; ++pedestrianIndex)
    {
        nearestIndex = NOT_FOUND;
        localNearestIndex = NOT_FOUND;

        originSet = "P";
        localOriginSet = "P";

        nearestDistance = __FLT_MAX__;
        localNearestDistance = __FLT_MAX__;

        pedestrianShoulderLength = pedestrianSet.getShoulderLengths().at(pedestrianIndex);;

        firstPedestrianX = pedestrianSet.getPedestrianCoordinates().at(pedestrianIndex).axis[0];
        firstPedestrianY = pedestrianSet.getPedestrianCoordinates().at(pedestrianIndex).axis[1];

        std::pair<std::string, int> newNearestNeighbor;

        for (int j = 0; j < numPedestrians; ++j)
        {

            secondPedestrianX = pedestrianSet.getPedestrianCoordinates().at(j).axis[0];
            secondPedestrianY = pedestrianSet.getPedestrianCoordinates().at(j).axis[1];


            if(pedestrianIndex != j && j < numPedestrians &&
                neighborDirectionTest(pedestrianSet, pedestrianIndex, j, firstPedestrianX, firstPedestrianY,
                    secondPedestrianX, secondPedestrianY) &&
                neighborSpacialTest(pedestrianSet, pedestrianIndex, j, firstPedestrianX, firstPedestrianY,
                    secondPedestrianX, secondPedestrianY,
                    "P", pedestrianShoulderLength))
            {

                FLOATING_NUMBER distance = getPedestrianDistance(pedestrianSet, pedestrianIndex, j);
                if(localNearestIndex == NOT_FOUND || distance < localNearestDistance)
                {
                    localNearestIndex = j;
                    localOriginSet = "P";
                    localNearestDistance = distance;
                }
            }
        }



        if (localNearestDistance < nearestDistance)
        {
            nearestIndex = localNearestIndex;
            originSet = localOriginSet;
            nearestDistance = localNearestDistance;
        }

        this->nearestNeighbors.push_back(std::make_pair(std::string(originSet), nearestIndex));
    }
   
}

inline bool CalmPedestrianModel::neighborDirectionTest(CalmPedestrianSet& pedestrianSet,
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

    directionX = (pedestrianSet.getVelocities())[firstPedestrianIndex].axis[0];

    directionY = (pedestrianSet.getVelocities())[firstPedestrianIndex].axis[1];

    dotProduct = (displacementX * directionX) + (displacementY * directionY);

    return dotProduct <= 0;
}

inline bool CalmPedestrianModel::neighborSpacialTest(CalmPedestrianSet& pedestrianSet, int firstPedestrianIndex,
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



  firstPedestrianDirectionX = std::fabs((pedestrianSet.getVelocities())[firstPedestrianIndex].axis[0]);
  firstPedestrianDirectionY = std::fabs((pedestrianSet.getVelocities())[firstPedestrianIndex].axis[1]);


  if(originSet == "P")
  {
    secondPedestrianDirectionX = std::fabs((pedestrianSet.getVelocities())[secondPedestrianIndex].axis[0]);
    secondPedestrianDirectionY = std::fabs((pedestrianSet.getVelocities())[secondPedestrianIndex].axis[1]);

    if(firstPedestrianDirectionX > firstPedestrianDirectionY
        && secondPedestrianDirectionX > secondPedestrianDirectionY
        || firstPedestrianDirectionY > firstPedestrianDirectionX
        && secondPedestrianDirectionY > secondPedestrianDirectionX)
    {
      secondShoulderLength = pedestrianSet.getShoulderLengths().at(secondPedestrianIndex);
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

//determine pedestrian direction
void CalmPedestrianModel::calculatePropulsion(CalmPedestrianSet& pedestrianSet, CalmGoals& goals) 
{
    const DimVector& currentGoals = goals.getAllCurrentGoals();
    const DimVector& endGoals = goals.getAllEndGoals();
    FLOATING_NUMBER xAisleCoefficent = 0.5;
    FLOATING_NUMBER yAisleCoefficent = 0.9;

    for(int i = 0; i < pedestrianSet.getNumPedestrians(); ++i)
    {
        
        if(!goals.isPedestianGoalMet(i))
        {
            Dimensions newVelocity = pedestrianSet.getVelocities().at(i);
            Dimensions newPropulsiveForce = this->propulsionForces.at(i);

            FLOATING_NUMBER goalX = currentGoals[i].axis[0];
            FLOATING_NUMBER goalY = currentGoals[i].axis[1];
            FLOATING_NUMBER coordinateX = pedestrianSet.getPedestrianCoordinates()[i].axis[0];
            FLOATING_NUMBER coordinateY = pedestrianSet.getPedestrianCoordinates()[i].axis[1];
            FLOATING_NUMBER mass = pedestrianSet.getMasses()[i];
            FLOATING_NUMBER desiredSpeed = pedestrianSet.getDesiredSpeeds()[i];
            FLOATING_NUMBER velocityX = pedestrianSet.getVelocities()[i].axis[0];
            FLOATING_NUMBER velocityY = pedestrianSet.getVelocities()[i].axis[1];
            FLOATING_NUMBER reactionTime = pedestrianSet.getReactionTimes()[i];

            FLOATING_NUMBER directionX = goalX - coordinateX;
            FLOATING_NUMBER directionY = goalY - coordinateY;



            if(directionX <= 0 && directionY <= 0) {
                newVelocity = 
                (
                    Dimensions
                    {
                        -1.0f * desiredSpeed * xAisleCoefficent,
                        -1.0f * desiredSpeed * yAisleCoefficent
                    }
                );
            } else if(directionX <= 0 && directionY >= 0) {
                newVelocity = 
                (
                    Dimensions
                    {
                        -1.0f * desiredSpeed * xAisleCoefficent,
                        desiredSpeed * yAisleCoefficent
                    }
                );
            } else if(directionX >= 0 && directionY >= 0) {
                newVelocity = 
                (
                    Dimensions
                    {
                        desiredSpeed * xAisleCoefficent,
                        desiredSpeed * yAisleCoefficent
                    }
                );
            } else if(directionX >= 0 && directionY <= 0) {
                newVelocity = 
                (
                    Dimensions
                    {
                        desiredSpeed * xAisleCoefficent,
                        -1.0f * desiredSpeed * yAisleCoefficent
                    }
                );
            } else {
                newVelocity = 
                (
                    Dimensions
                    {
                        0.0,
                        0.0
                    }
                );
            }


            newPropulsiveForce =
            (
                Dimensions
                {
                    (newVelocity.axis[0] - velocityX) * mass / reactionTime,
                    (newVelocity.axis[1] - velocityY) * mass / reactionTime
                }
            );

            this->propulsionForces.at(i) = std::move(newPropulsiveForce);
        }
    }
}

//Change to calculatePropulsion
void CalmPedestrianModel::calculateDesiredSpeeds(CalmPedestrianSet& pedestrianSet, CalmGoals& goals)
{
    std::vector<FLOATING_NUMBER> newDesiredSpeeds;
    int numPedestrians = pedestrianSet.getNumPedestrians();
    FLOATING_NUMBER a = -2.4532;
    FLOATING_NUMBER b = 0.138412;
    FLOATING_NUMBER c = 0.87436;

    for (int i = 0; i < numPedestrians; ++i)
    {
        if(!goals.isPedestianGoalMet(i)){
            int nearestNeighborIndex = this->nearestNeighbors[i].second;
            std::string nearestNeighborOrigin = this->nearestNeighbors[i].first;


            FLOATING_NUMBER distanceMinusB = 1;

            if(nearestNeighborIndex == -1)
            {
                distanceMinusB = ((1) - b);  //1 value might need to change
            }
            else
            {
                distanceMinusB = (getPedestrianDistance(pedestrianSet,
                        i,
                        nearestNeighborIndex
                )) - b;
            }

            newDesiredSpeeds.push_back(0.3 * (c - exp(a * distanceMinusB))); // Might need to change this depending on goal.
        }else{
            newDesiredSpeeds.push_back(0);
        }
    }
    pedestrianSet.setDesiredSpeeds(newDesiredSpeeds);
}

FLOATING_NUMBER CalmPedestrianModel::getPedestrianDistance(CalmPedestrianSet& pedestrianSet, int firstPedestrian, int secondPedestrian) {

    if(firstPedestrian == secondPedestrian) {
        return 0;
    }

    if(firstPedestrian > secondPedestrian) {
        return this->pedestrianDistanceMatrix[(pedestrianSet.getNumPedestrians() * firstPedestrian) + secondPedestrian];
    } else {
        return this->pedestrianDistanceMatrix[(pedestrianSet.getNumPedestrians() * secondPedestrian) + firstPedestrian];
    }


}

DimVector CalmPedestrianModel::getPropulsionForces() {
    return this->propulsionForces;
}

std::vector<std::pair<std::string, int>> CalmPedestrianModel::getNearestNeighbors()
{
    return this->nearestNeighbors;
}


CalmPedestrianModel::~CalmPedestrianModel()
{
    //delete[] this->obstacleDistanceMatrix;
    delete[] this->pedestrianDistanceMatrix;
}




void      CalmPedestrianModel::configure(const CONFIG_MAP& configMap) {}