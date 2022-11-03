#include "calm_pedestrian_model.hpp"

CalmPedestrianModel::CalmPedestrianModel() {

}


void CalmPedestrianModel::initialize(PedestrianSet& pedestrianSet) 
{
    pedestrianSet = static_cast<CalmPedestrianSet&>(pedestrianSet);
    this->pedestrianDistanceMatrix = new FLOATING_NUMBER[pedestrianSet.getNumPedestrians() * pedestrianSet.getNumPedestrians()];
}

DimVector CalmPedestrianModel::update(PedestrianSet& pedestrianSet, FLOATING_NUMBER time)
{
    calculateDistanceMatrices(static_cast<CalmPedestrianSet&>(pedestrianSet));
    calculateNeartestNeighbors(static_cast<CalmPedestrianSet&>(pedestrianSet));

    return {};
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
       void      CalmPedestrianModel::initialize(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet,
                     Goals& goals){};
       DimVector CalmPedestrianModel::update(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet,
                     Goals& goals, FLOATING_NUMBER time){};