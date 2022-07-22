#include "calm_goals.hpp"

#include <climits>

CalmGoals::CalmGoals()
{
}

void CalmGoals::configure(CONFIG_MAP* configMap)
{

}

void CalmGoals::setData(Data* data)
{
    this->data = data;
    createPedestrianCoordinatesPointer();
}

void CalmGoals::addExitGoals(const ObstacleSet& obstacleSet)
{
    exitGoals = obstacleSet.getObjectsofType("exits");
    calculateNearestExit();
}

void CalmGoals::removeExitGoal(int exitIndex)
{
    this->exitGoals.erase(exitGoals.begin()+exitIndex);
}

void CalmGoals::clearGoals()
{
    this->exitGoals.clear();
}

void CalmGoals::calculateNearestExit()
{

    if(this->exitGoals.size() > 1)
    {
        for (int i = 0; i < this->data->getPedestrianSet()
            ->getNumPedestrians();
            ++i)
        {
            this->nearestExit.push_back(nearestGoal(i));
        }
    }

    else
    {
        for (int i = 0; i < this->data->getPedestrianSet()
            ->getNumPedestrians();
            ++i)
        {
            this->nearestExit.push_back(0);
        }
    }

    // for(int i = 0; i < 5/*this->data->getPedestrianSet()->getNumPedestrians()*/
    //     ; ++i)
    // {
    //     std::cout << "nearest exit for ped " << i << " :" << nearestExit[i]
    //         << std::endl;
    // }


}

void CalmGoals::determinePedestrianGoals()
{
    std::vector<Dimensions> newGoal;
    size_t index = 0;

    for(const auto& ped : *this->pedestrianCoordinatesPointer){
        bool inSeat = (ped[1] < -0.3 || ped[1] > 0.3);
        if(inSeat){
            newGoal.push_back({
                ped[0],
                0
            });
        }else{
            const auto& exit = this->exitGoals[nearestExit[index]];
            bool atExit = ped[0] == exit[0];
            if(atExit){
                newGoal.push_back(exit);
            }else{
                newGoal.push_back({
                    exit[0],
                    0
                });
            }
        }
        ++index;
    }

    data->getPedestrianSet()->setGoalCoordinates(newGoal);
}

bool CalmGoals::checkPedestianGoalsMet(int pedestrianIndex)
{

    bool goalMet = false;

    if(((*this->pedestrianCoordinatesPointer)[pedestrianIndex][0]
        >= this->exitGoals[nearestExit[pedestrianIndex]][0] - 0.5
        && (*this->pedestrianCoordinatesPointer)[pedestrianIndex][0]
        <= this->exitGoals[nearestExit[pedestrianIndex]][0] + 0.5)
        && ((*this->pedestrianCoordinatesPointer)[pedestrianIndex][1]
        >= this->exitGoals[nearestExit[pedestrianIndex]][1] - 0.5
        && (*this->pedestrianCoordinatesPointer)[pedestrianIndex][1]
        <= this->exitGoals[nearestExit[pedestrianIndex]][1] + 0.5))
    {
        goalMet = true;
    }

    return goalMet;
}

bool CalmGoals::isSimulationGoalMet()
{
    bool simGoalMet = false;
    if(this->data->getPedestrianSet()->getNumPedestrians() == 0)
    {
        simGoalMet = true;
    }
    return simGoalMet;
}

void CalmGoals::createPedestrianCoordinatesPointer()
{
    this->pedestrianCoordinatesPointer = this->data->getPedestrianSet()->
        getPedestrianCoordinates();
}

unsigned int CalmGoals::nearestGoal(int pedestrianIndex)
{
    //index of nearest starts at the first
    unsigned int nearest = 0;
    int nearDist = INT_MAX;
    //starts at position 1 because there should be at least 2 exit goals
    for (unsigned int i = 1; i < this->exitGoals.size(); ++i)
    {
        int currDist = calculateDistance(pedestrianIndex, i);
        //compares distance between exits and the pedestrian
        if (currDist < nearDist)
        {
            //sets nearest to lower if a different exit is lower.
            nearest = i;
            nearDist = currDist;
        }
    }
    return nearest;
}

//pedestrianIndex and exitGoalIndex should probably be unsigned - V
FLOATING_NUMBER CalmGoals::calculateDistance(int pedestrianIndex,
    int exitGoalIndex)
{
    FLOATING_NUMBER xDistance =
        this->exitGoals[exitGoalIndex][0] -
        (*this->pedestrianCoordinatesPointer)[pedestrianIndex][0];

    xDistance = pow(xDistance, 2);


    FLOATING_NUMBER yDistance = this->exitGoals[exitGoalIndex][1] -
        (*this->pedestrianCoordinatesPointer)[pedestrianIndex][1];

    yDistance = pow(yDistance, 2);

    return (sqrt(xDistance + yDistance));
}

Dimensions CalmGoals::getPedestrianExitGoal(int pedestrianIndex)
{
    return this->exitGoals[this->nearestExit[pedestrianIndex]];
}
